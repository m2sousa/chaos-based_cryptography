#ifndef LOGISTICMAP_H
#define LOGISTICMAP_H

#include "ChaoticMap.h"

#include <cstdint>
#include <cmath>

class LogisticMap : public ChaoticMap
{
	public:
		LogisticMap(const std::vector<double> &parameters,const std::vector<double> &initialConditions, int sizeKey);

	private:
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
