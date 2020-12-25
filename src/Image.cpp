#include "Image.h"

Image::Image(std::string filename){

	std::ifstream inputFile{filename, std::ios::binary};

	if(! inputFile){
		std::cerr << "Can't open the image file.";
		exit(1);
	}

	this->getFileHeader(&inputFile);

	this->getDibHeader(&inputFile);

	this->getData(&inputFile);

	this->displayInfo();
	
	inputFile.close();	
}

void Image::displayInfo(){
	std::cout.setf(std::ios::dec, std::ios::basefield);
	std::cout << "Width : " << getWidth() << '\n';
	std::cout << "Height : " << getHeight() << '\n';
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
