#include "ChaoticMap.h"

ChaoticMap::ChaoticMap(const std::vector<double> &parameters, const std::vector<double> &initialConditions){
	this->parameters = parameters;
	this->initialConditions = initialConditions;
}

ChaoticMap::ChaoticMap(const ChaoticMap &cmap1, const ChaoticMap &cmap2){
	if(cmap1.key.size() == cmap2.key.size()){
		unsigned int sizeKey {static_cast<unsigned int>(cmap1.key.size())};
		for(unsigned int i {0}; i<sizeKey; ++i){
			uint8_t xorKey = cmap1.key[i] ^ cmap2.key[i];
			this->key.push_back(xorKey);
		}
	} else {
		std::cerr << "Please generate two keys of the same length.";
		exit(1);
	}
}

