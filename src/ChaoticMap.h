/**
 * @file	ChaoticMap.h
 * @brief	ChaoticMap class definition
 * @author	De Sousa Maxime / NuxDD
 * @date	December 2020
 */

#ifndef CHAOTICMAP_H
#define CHAOTICMAP_H

#include <cstdint>
#include <vector>
#include <iostream>

/**
 * @brief	Base class for every map used to generate an encryption key.
 * @details This class is the base from which map will inherit. It provides only some members needed to save the parameters, the initial conditions and the key.
 */
class ChaoticMap
{
	public:

		/**
		 * @brief	The default constructor of the class, should not be used if it is not by an inherited class.
		 * @details The default constructor simply saves the parameters and initial conditions to the class members.
		 *
		 * @param &parameters			Reference to a vector with the parameters of the map.
		 * @param &initialConditions	Reference to a vector with the initial conditions of the map.
		 */
		ChaoticMap(const std::vector<double> &parameters, const std::vector<double> &initialConditions);

		/**
		 * @brief	Generate a key from two chaotic maps by xoring the keys.
		 *
		 * @param &cmap1	Reference to ChaoticMap instance to provide a key.
		 * @param &cmap2	Reference to ChaoticMap instance to provide a key.
		 */
		ChaoticMap(const ChaoticMap &cmap1, const ChaoticMap &cmap2);

	public:
		std::vector<uint8_t> key{};

	protected:
		std::vector<double> parameters{};
		std::vector<double> initialConditions{};
};

#endif
