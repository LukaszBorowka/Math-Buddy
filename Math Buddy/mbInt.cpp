#include "mbInt.h"

namespace mb {
	
	// constructors
	mbInt::mbInt(std::string number) {
		this->isNegative = false;
		bool numStarted = false;
		bool minusAlrUsed = false;
		for (const char ch : number) {
			if (isdigit(ch)) {
				if (!numStarted && ch == '0') continue;
				numStarted = true;
				this->digits.push_back(ch - '0');
			}
			else if (ch == '-' && !numStarted && !minusAlrUsed) {
				minusAlrUsed = true;
				this->isNegative = true;
			}
			else if (ch == ' ') continue;
			else break;
		}
		if (this->digits.size() == 0) this->digits.push_back(0);
		std::reverse(this->digits.begin(), this->digits.end());
	}

	mbInt::mbInt(long long number) {
		this->isNegative = false;
		if (number == 0) {
			this->digits.push_back(0);
		}
		else {
			if (number < 0) {
				this->isNegative = true;
				number = -number;
			}
			while (number > 0) {
				this->digits.push_back(number % 10);
				number /= 10;
			}
		}
	}

	mbInt::mbInt(std::vector<int> digits, bool isNegative) {
		//std::reverse(digits.begin(), digits.end());
		this->digits = digits;
		this->isNegative = isNegative;
	}

	// adding two mbInts
	mbInt add(const mbInt& x1, const mbInt& x2) {
		bool isNegative;
		std::vector<int> digits;

		// both are positive or both are negative
		if (x1.isNegative == x2.isNegative) {
			// just need to add the absolutes of x1 and x2 and add the sign
			isNegative = x1.isNegative; // sign of sum will be the same as the sign of x1 and x2

			// need to have two vectors: shorter and longer
			std::vector<int> shorter;
			std::vector<int> longer;
			if (x1.digits.size() >= x2.digits.size()) {
				longer = x1.digits;
				shorter = x2.digits;
			}
			else {
				longer = x2.digits;
				shorter = x1.digits;
			}

			// sum digit by digit
			int carry = 0;
			for (int i = 0; i < shorter.size(); i++) {
				digits.push_back(shorter[i] + longer[i] + carry);
				carry = 0;
				if (digits[i] >= 10) {
					digits[i] -= 10;
					carry = 1;
				}
			}
			for (int i = shorter.size(); i < longer.size(); i++) {
				digits.push_back(longer[i] + carry);
				carry = 0;
				if (digits[i] >= 10) {
					digits[i] -= 10;
					carry = 1;
				}
			}
			if (carry) digits.push_back(carry);

			return mbInt(digits, isNegative);
		}


		return mbInt(0);
	}

	std::string mbInt::getString() const {
		std::string buff = (this->isNegative) ? "-" : "";
		for (int i = this->digits.size() - 1; i >= 0; i--) buff += std::to_string(this->digits[i]);
		return buff;
	}

	mbInt operator+(const mbInt& obj1, const mbInt& obj2) {
		return add(obj1, obj2);
	}

	std::ostream& operator<<(std::ostream& os, const mbInt& obj) {
		os << obj.getString();
		return os;
	}

}