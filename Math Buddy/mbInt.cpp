#include "mbInt.h"

namespace mthbd {
	
	// constructors
	Int::Int(long long num) {
		this->isNegative = (num < 0) ? true : false;
		do {
			this->bits.push_back(num % 2);
			num /= 2;
		} while (num > 0);
	}

	Int::Int(std::string num) {
		// TODO later
	}

	Int::Int(std::vector<bool> bits, bool isNegative) {
		this->bits = bits;
		this->isNegative = isNegative;
	}


	// printing
	std::string Int::getBitsString() {
		std::string buff = "";
		// bits are stored in a reversed order
		for (int i = this->bits.size() - 1; i >= 0; i--) {
			buff += (this->bits[i]) ? "1" : "0";
		}
		return buff;
	}


	Int sum(const Int& term1, const Int& term2) {
		if (term1.isNegative == term2.isNegative) {
			std::vector<bool> buff;
			bool isNegative = term1.isNegative;
			bool carry = false;
			for (size_t i = 0; i < std::max(term1.bits.size(), term2.bits.size()); ++i) {
				bool bitA = (i < term1.bits.size()) ? term1.bits[i] : false;
				bool bitB = (i < term2.bits.size()) ? term2.bits[i] : false;
				buff.push_back(bitA ^ bitB ^ carry);
				carry = (bitA && bitB) || (bitA && carry) || (bitB && carry);
			}
			if (carry) buff.push_back(true);
			return Int(buff, isNegative);
		}

		else if (!term1.isNegative && term2.isNegative) return difference(term1, term2);
		else if (term1.isNegative && !term2.isNegative) return difference(term2, term1);

		return Int(0);
	}

	Int difference(const Int& term1, const Int& term2) {
		return Int(0); // TODO later
	}

}