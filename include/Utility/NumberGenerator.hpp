#pragma once
#include "BaseValues.hpp"
#include <random>

namespace CC
{
	namespace Utility
	{

		inline static int32 GenRandomInt32(int32 min, int32 max)
		{
			std::random_device seed;
			std::mt19937 gen(seed());

			std::uniform_int_distribution dist(min, max);

			return dist(gen);
		}



		inline static int64 GenRandomInt64(int64 min, int64 max)
		{
			std::random_device seed;
			std::mt19937_64 gen(seed());

			std::uniform_int_distribution dist(min, max);

			return dist(gen);
		}
	}
}
