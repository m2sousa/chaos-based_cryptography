/**
 * @file	LogisticMap.h
 * @brief	LogisticMap class definition & implementation
 * @author	De Sousa Maxime / NuxDD
 * @date	December 2020
 */

#ifndef LOGISTICMAP_H
#define LOGISTICMAP_H

#include "ChaoticMap.h"

#include <cstdint>
#include <cmath>

/**
 * @brief	The LogisticMap class provides a single method to generate a key for encryption.
 * @details The LogisticMap inherits from the ChaoticMap class. It generates a key with the results on the step by step logistic maps with the parameters provided to the constructor.
 */
class LogisticMap : public ChaoticMap
{
	public:

		/**
		 * @brief	The LogisticMap constructor will generate a key with the step by step definition of the logistic map.
		 * @details The LogisticMap constructor firstly saves the parameters and initial conditions provided to the vector members, then, it generates an encryption key that will be saved to the key vector member.
		 *
		 * @param &parameters			Reference to an array of parameters, at least a parameter is needed.
		 * @param &initialConditions	Reference to an array of initial conditions, at least an initial conditions is needed.
		 * @param sizeKey				Length of the key that need to be generated.
		 */
		LogisticMap(const std::vector<double> &parameters,const std::vector<double> &initialConditions, int sizeKey);

	private:

		/**
		 * @brief	Generate a key with the length provided by the parameter.
		 * @details Generate a key using the step by step logistic map and save it to the key vector member.
		 *
		 * @param sizekey	Length of the key that need to be generated.
		 */
		void computeKey(int sizeKey);
};

inline LogisticMap::LogisticMap(const std::vector<double> &parameters, const std::vector<double> &initialConditions, int sizeKey) : ChaoticMap(parameters, initialConditions){
	this->computeKey(sizeKey);
}

inline void LogisticMap::computeKey(int sizeKey){
	double res = this->initialConditions[0];
	for(int i {0}; i<sizeKey; ++i){
		res = this->parameters[0]*res*(1-res);
		this->key.push_back(static_cast<uint8_t>(floor(res * 255)));
	}
}

#endif
