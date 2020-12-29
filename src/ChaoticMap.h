#ifndef CHAOTICMAP_H
#define CHAOTICMAP_H

#include <cstdint>
#include <vector>
#include <iostream>

class ChaoticMap
{
	public:
		ChaoticMap(const std::vector<double> &parameters, const std::vector<double> &initialConditions);
		ChaoticMap(const ChaoticMap &cmap1, const ChaoticMap &cmap2);

	public:
		std::vector<uint8_t> key{};

	protected:
		std::vector<double> parameters{};
		std::vector<double> initialConditions{};
};

#endif
