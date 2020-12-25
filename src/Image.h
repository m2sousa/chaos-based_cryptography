#ifndef IMAGE_H
#define IMAGE_H

#include <cstdint>
#include <vector>
#include <iostream>
#include <fstream>

class Image
{
	public:
		Image(std::string filename);

	public:
		void displayInfo();
		void encrypt(); //TODO: add key as parameter
		void save();
		void toBW();
		uint32_t getWidth();
		uint32_t getHeight();


	private:
		void getFileHeader(std::ifstream* file);
		void getDibHeader(std::ifstream* file);
		void getData(std::ifstream* file);
		bool checkFileHeader();

	private:
		static constexpr int fileHeaderLength = 14;
		
		uint8_t fileHeader[fileHeaderLength]{};
		std::vector<uint8_t> dibHeader{};
		std::vector<uint8_t> pixelArray{};
		std::vector<uint8_t> data{};

};

#endif

