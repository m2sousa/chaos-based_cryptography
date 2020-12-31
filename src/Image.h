/**
 * @file 	Image.h
 * @brief	BMP image class
 * @author 	De Sousa Maxime / NuxDD
 * @date 	December 2020
 */

#ifndef IMAGE_H
#define IMAGE_H

#include <cstdint>
#include <vector>
#include <iostream>
#include <fstream>

#include "ChaoticMap.h"

/**
 * @brief	The Image class provides various methods in order to read BMP files, encrypt data, and save to the disk.
 * @details The Image class provides methods to read the file header, the dib header and the data from a BMP file. It also provides a method to encrypt the data with the key generated of a ChaoticMap. Finally, it provides a method to save the instance to the disk as a BMP file.
 */
class Image
{
	public:

		/**
		 * @brief	The Image constructor will read various dara array from the BMP file and save it as members of the class.
		 * @details The Image constructor will first read the file header and check if the BMP file is correct. Then dib header and data will be read and save to the instance members.
		 *
		 * @param filename	Relative path to where the file to be read is.
		 */
		Image(std::string filename);

	public:

		/**
		 * @brief	Display informations about the BMP Image that has been read.
		 * @details Display the width, length and the number of bits per pixel by reading the dib header fetched by the constructor.
		 */
		void displayInfo();

		/**
		 * @brief 	Encrypt the image with the key generated in the ChaoticMap constructor.
		 * @details Encrypt the data vector member of the Image class by a XOR operation with the key of the ChaoticMap instance.
		 *
		 * @param &cmap	Reference to the ChaoticMap instance to provide the encryption key.
		 */
		void encrypt(ChaoticMap &cmap); 

		/**
		 * @brief	Save the instance of the class to disk as a BMP file.
		 * @details Save the instance by writing the file header followed by the dib header and the data to respect the BMP file format.
		 *
		 * @param filename	Relative path to where the file is going to be written on the disk.
		 */
		void save(std::string filename);

		/**
		 * @brief	Return the width of the BMP Image that has been read.
		 * @details Read the width of the file encoded on 4 bytes at the offset 0x12 (0x04 in the dib header) and return it.
		 *
		 * @return	Width of the file as an unsigned integer encoded on 4 bytes.
		 */
		uint32_t getWidth();

		/**
		 * @brief	Return the height of the BMP Image that has been read.
		 * @details Read the height of the file encoded on 4 bytes at the offset 0x16 (0x08 in the dib header) and return it.
		 *
		 * @return	Height of the file as an unsigned integer encoded on 4 bytes.
		 */
		uint32_t getHeight();

		/**
		 * @brief	Return the number of bits on which each pixel is encoded.
		 * @details Read the number of bits on which each pixel is encoded on 2 bytes at the offset 0x1C (0x0E in the dib header) and return it.
		 *
		 * @return Number of bits as an unsigned integer encoded on 2 bytes.
		 */
		uint16_t getBitPerPixel();

		/**
		 * @brief	Extract a single color of the data.
		 * @details Extract a single color of the data by setting each bytes which are not related to the provided color or the alpha to zero.
		 *
		 * @param color	Code of the color (see enum definition) to extract.
		 */
		enum colorCode {blue=0, green=1, red=2};
		void extractColor(colorCode color);


	private:

		/**
		 * @brief	Get the file header of the BMP file.
		 * @details Read the 14 first bytes of the file (which are the file header) and save it to the fileHeader array member.
		 */
		void getFileHeader(std::ifstream* file);

		/**
		 * @brief	Get the dib header of the BMP file.
		 * @details Read the first two bytes at the offset 0x14 to determine the size of the dib header, then read the entire dib header and save it to the dibHeader vector member.
		 */
		void getDibHeader(std::ifstream* file);

		/**
		 * @brief	Get the data of the BMP file.
		 * @details Read the offset of the data array at offset 0x0A, then read the size of the data array at the offset 0x14 of the dib header. Finally, read the data array and save it to the data vector member.
		 */
		void getData(std::ifstream* file);

		/**
		 * @brief	Check if the BMP file provided to construct the instance of Image is correct.
		 * @details Check if the first two bytes of the file are the BMP signature, then if the four bytes reserved at the offset 0x06 are 0.
		 */
		bool checkFileHeader();

	private:
		static constexpr int fileHeaderLength = 14;
		
		uint8_t fileHeader[fileHeaderLength]{};
		std::vector<uint8_t> dibHeader{};
		std::vector<uint8_t> pixelArray{};
		std::vector<uint8_t> data{};

};

#endif

