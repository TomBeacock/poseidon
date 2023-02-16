#include "utf8_iterator.h"

namespace poseidon
{
	Utf8Iterator::Utf8Iterator(std::u8string::const_iterator it) :
		it_(it) {}

	Utf8Iterator::Utf8Iterator(const Utf8Iterator& source) :
		it_(source.it_) {}

	Utf8Iterator::~Utf8Iterator() {}

	Utf8Iterator& Utf8Iterator::operator=(const Utf8Iterator& rhs)
	{
		it_ = rhs.it_;
		return *this;
	}

	Utf8Iterator& Utf8Iterator::operator++()
	{
		char8_t c = *it_;
		if ((c & 0b10000000) == 0) it_ += 1;
		else if ((c & 0b11100000) == 0b11000000) it_ += 2;
		else if ((c & 0b11110000) == 0b11100000) it_ += 3;
		else if ((c & 0b11111000) == 0b11110000) it_ += 4;
		return *this;
	}

	Utf8Iterator Utf8Iterator::operator++(int)
	{
		Utf8Iterator temp = *this;
		++(*this);
		return temp;
	}

	Utf8Iterator& Utf8Iterator::operator--()
	{
		--it_;
		while ((*it_ & 0b11000000) == 0b10000000)
			--it_;
		return *this;
	}

	Utf8Iterator Utf8Iterator::operator--(int)
	{
		Utf8Iterator temp = *this;
		--(*this);
		return temp;
	}

	char32_t Utf8Iterator::operator*() const
	{
		char32_t codePoint = 0;

		if ((*it_ & 0b10000000) == 0)
		{
			codePoint = *it_;
		}
		else if ((*it_ & 0b11100000) == 0b11000000)
		{
			codePoint = (*it_ & 0b00011111) << 6;
			codePoint |= (*(it_ + 1) & 0b00111111);
		}
		else if ((*it_ & 0b11110000) == 0b11100000)
		{
			codePoint = (*it_ & 0b00001111) << 12;
			codePoint |= (*(it_ + 1) & 0b00111111) << 6;
			codePoint |= (*(it_ + 2) & 0b00111111);
		}
		else if ((*it_ & 0b11111000) == 0b11110000)
		{
			codePoint = (*it_ & 0b00000111) << 18;
			codePoint |= (*(it_ + 1) & 0b00111111) << 12;
			codePoint |= (*(it_ + 2) & 0b00111111) << 6;
			codePoint |= (*(it_ + 3) & 0b00111111);
		}

		return codePoint;
	}

	bool Utf8Iterator::operator==(const Utf8Iterator& rhs) const
	{
		return it_ == rhs.it_;
	}

	bool Utf8Iterator::operator!=(const Utf8Iterator& rhs) const
	{
		return it_ != rhs.it_;
	}

	bool Utf8Iterator::operator==(std::u8string::iterator rhs) const
	{
		return it_ == rhs;
	}

	bool Utf8Iterator::operator==(std::u8string::const_iterator rhs) const
	{
		return it_ == rhs;
	}

	bool Utf8Iterator::operator!=(std::u8string::iterator rhs) const
	{
		return it_ != rhs;
	}

	bool Utf8Iterator::operator!=(std::u8string::const_iterator rhs) const
	{
		return it_ != rhs;
	}
}