#pragma once

#include "MathBuddy.h"

namespace mthbd {
	class Int {
	private:
		std::vector<bool> bits; // stored in reverse order for simpler calculations
		bool isNegative;

	public:
		// constructors
		Int(long long num);
		Int(std::string num);
		Int(std::vector<bool> bits, bool isNegative);


		// printing
		std::string getBitsString();


		// external operations
		friend Int sum(const Int& term1, const Int& term2);
		friend Int difference(const Int& term1, const Int& term2);
	};

	Int sum(const Int& term1, const Int& term2);
	Int difference(const Int& term1, const Int& term2);
}