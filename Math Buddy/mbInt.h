#pragma once

#include "MathBuddy.h"

namespace mb {
	class mbInt {
	private:
		std::vector<int> digits;
		bool isNegative;

	public:
		mbInt(const std::string number);
		mbInt(long long number);

		// operations:
		// addition
		mbInt add(const mbInt j, const mbInt k);			// mbInt + mbInt
		mbInt add(const mbInt j, const int k);				// mbInt + int
		mbInt add(const int j, const mbInt k);				// int   + mbInt
		mbInt add(const int j, const int k);				// int   + int
		mbInt add(const mbInt j, const long k);				// mbInt + long
		mbInt add(const long j, const mbInt k);				// long  + mbInt
		mbInt add(const long j, const long k);				// long  + long
		mbInt add(const mbInt j, const long long k);		// mbInt + long long
		mbInt add(const long long j, const mbInt k);		// long long + mbInt
		mbInt add(const long long j, const long long k);	// long long + long long

		std::string getString() const;

		// operators declaration:
		//friend mbInt operator+(const mbInt& obj1, const mbInt& obj2);
		friend std::ostream& operator<<(std::ostream& os, const mbInt& obj);
	};
}