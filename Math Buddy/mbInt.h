#pragma once

#include "MathBuddy.h"

namespace mb {
	class mbInt {
	private:
		std::vector<int> digits;
		bool isNegative;

		void removeFrontZeros();

	public:
		mbInt(std::string number);
		mbInt(long long number);
		mbInt(std::vector<int> digits, bool isNegative);

		//mbInt add(const mbInt& x1, const mbInt& x2);

		std::string getString() const;




		friend mbInt add(const mbInt& x1, const mbInt& x2);
		friend mbInt operator+(const mbInt& obj1, const mbInt& obj2);
		friend std::ostream& operator<<(std::ostream& os, const mbInt& obj);
	};
}