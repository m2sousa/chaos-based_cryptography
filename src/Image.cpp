#include "Image.h"

Image::Image(std::string filename){

	std::ifstream inputFile{filename, std::ios::binary};

	if(! inputFile){
		std::cerr << "Can't open the image file.";
		exit(1);
	}

	// No skip on white spaces to avoid byte missing while reading
	inputFile >> std::noskipws;

	this->getFileHeader(&inputFile);

	this->getDibHeader(&inputFile);

	this->getData(&inputFile);

	inputFile.close();	
}

void Image::displayInfo(){
	std::cout.setf(std::ios::dec, std::ios::basefield);
	std::cout << "Width : " << getWidth() << '\n';
	std::cout << "Height : " << getHeight() << '\n';
	std::cout << "Number of bits per pixel : " << getBitPerPixel() << '\n';
}

void Image::encrypt(ChaoticMap &cmap){
	// Checking if a pixel is encoded on 32 bits, otherwise, padding should be considered
	if(this->getBitPerPixel() == 0x0020){
		if(cmap.key.size() == this->data.size()){
			const unsigned int sizeData {static_cast<unsigned int>(this->data.size())};
			for(unsigned int i {0}; i<sizeData; ++i){
				uint8_t encodedByte = this->data[i] ^ cmap.key[i];
				this ->data[i] = encodedByte;
			}
		} else {
			std::cerr << "Please generate a key with the length of the image data.";
			exit(1);
		}
	}
}

void Image::save(std::string filename){
	std::ofstream outputFile {filename, std::ios::out | std::ios::binary};
	outputFile.write(reinterpret_cast<const char*>(&fileHeader[0]), fileHeaderLength);
	outputFile.write(reinterpret_cast<const char*>(&dibHeader[0]), sizeof(uint8_t)*dibHeader.size());
	outputFile.write(reinterpret_cast<const char*>(&data[0]), sizeof(uint8_t)*data.size());
	outputFile.close();
}

uint32_t Image::getWidth(){
	int offset {0x04};
	uint32_t width = 	dibHeader[offset] 			|
						dibHeader[offset + 1] << 8 	|
						dibHeader[offset + 2] << 16 |
						dibHeader[offset + 3] << 24;
	return width;
}

uint32_t Image::getHeight(){
	int offset {0x08};
	uint32_t height = 	dibHeader[offset] 			|
						dibHeader[offset + 1] << 8 	|
						dibHeader[offset + 2] << 16 |
						dibHeader[offset + 3] << 24;
	return height;
}

uint16_t Image::getBitPerPixel(){
	int offset {0x0E};
	uint16_t bpp = 	dibHeader[offset]			|
					dibHeader[offset + 1] << 8;
	return bpp;
}

void Image::getFileHeader(std::ifstream* file){
	uint8_t readedByte{};
	for(int i {0}; i<fileHeaderLength; ++i){
		*file >> readedByte;
		this->fileHeader[i] = readedByte;
	}
	if(this->checkFileHeader()){
		std::cerr << "Incorrect BMP file.";
		exit(1);
	}
}

void Image::getDibHeader(std::ifstream* file){
	uint8_t readedByte{};
	uint32_t lengthDibHeader{};
	for(int i {0}; i<4; ++i){
		*file >> readedByte;
		this->dibHeader.push_back(readedByte);
		lengthDibHeader = (readedByte << i*8) | lengthDibHeader;
	}
	for(unsigned int i {0}; i<(lengthDibHeader-4); ++i){
		*file >> readedByte;
		this->dibHeader.push_back(readedByte);
	}
}

void Image::getData(std::ifstream* file){
	uint8_t offset {0x0A};
	uint32_t dataOffset = 	fileHeader[offset]			|
							fileHeader[offset + 1] << 8 |
							fileHeader[offset + 2] << 16|
							fileHeader[offset + 3] << 24;
	uint8_t sizeOffset {0x14};
	uint32_t sizeData =		dibHeader[sizeOffset]			|
							dibHeader[sizeOffset + 1] << 8	|
							dibHeader[sizeOffset + 2] << 16	|
							dibHeader[sizeOffset + 3] << 24;
	uint8_t readedByte{};
	file->seekg(dataOffset, std::ios::beg);
	for(unsigned int i {0}; i<sizeData; ++i){
		*file >> readedByte;
		data.push_back(readedByte);
	}
}

bool Image::checkFileHeader(){
	bool checkFlag {false};
	if(	((fileHeader[0x01] << 8 | fileHeader[0x00]) != 0x4D42) || 
	   	((fileHeader[0x07] << 8 | fileHeader[0x06]) != 0x0000) ||
		((fileHeader[0x09] << 8 | fileHeader[0x08]) != 0x0000)){
		checkFlag = true;
	} 
	return checkFlag;
}
