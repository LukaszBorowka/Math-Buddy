#include "mbInt.h"

namespace mb {
	
	mbInt::mbInt(const std::string number) {
		this->isNegative = false;
		bool numStarted = false;
		bool minusAlrUsed = false;
		for (const char ch : number) {
			if (isdigit(ch)) {
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

	std::string mbInt::getString() const {
		std::string buff = (this->isNegative) ? "-" : "";
		for (int i = this->digits.size() - 1; i >= 0; i--) buff += std::to_string(this->digits[i]);
		return buff;
	}

	std::ostream& operator<<(std::ostream& os, const mbInt& obj) {
		os << obj.getString();
		return os;
	}

}