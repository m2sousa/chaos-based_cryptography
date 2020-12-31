#include "Image.h"
#include "LogisticMap.h"

void printUsage(){
	std::cout << "Usage: chaos-based_cryptography inputFilename outputFilename";
}

int main(int argc, char** argv){
	if(argc != 3){
		printUsage();
		exit(1);
	} 
	
	// Get the path to the input and output files with the arguments
	std::string pathToInput {"../input/" + static_cast<std::string>(argv[1]) + ".bmp"};
	std::string pathToOutput {"../output/" + static_cast<std::string>(argv[2]) + ".bmp"};

	// Open and read the input file and get the key length
	Image img {pathToInput};

	int width = static_cast<int>(img.getWidth());
	int height = static_cast<int>(img.getHeight());
	int bytesPerPixel = static_cast<int>(img.getBitPerPixel())/8;

	int keyLength {width*height*bytesPerPixel};

	// Generating the first part of encryption key
	std::vector<double> parameters1 {3.89};
	std::vector<double> initCond1 {0.6104};
	
	LogisticMap logisticm1 {parameters1, initCond1, keyLength};

	// Generating the second part of encryption key
	std::vector<double> parameters2 {3.79};
	std::vector<double> initCond2 {0.902};

	LogisticMap logisticm2 {parameters2, initCond2, keyLength};

	// Generating the encryption key
	ChaoticMap xored {logisticm1, logisticm2};

	// Encrypting the input file
	img.encrypt(xored);

	// Save the file to the disk
	img.save(pathToOutput);
}
