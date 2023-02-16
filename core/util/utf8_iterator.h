#pragma once

#include <string>

namespace poseidon
{
	class Utf8Iterator
	{
	public:
		Utf8Iterator(std::u8string::const_iterator it);
		Utf8Iterator(const Utf8Iterator& source);
		~Utf8Iterator();

		Utf8Iterator& operator=(const Utf8Iterator& rhs);
		Utf8Iterator& operator++();
		Utf8Iterator operator++(int);
		Utf8Iterator& operator--();
		Utf8Iterator operator--(int);

		char32_t operator*() const;

		bool operator==(const Utf8Iterator& rhs) const;
		bool operator!=(const Utf8Iterator& rhs) const;
		bool operator==(std::u8string::iterator rhs) const;
		bool operator==(std::u8string::const_iterator rhs) const;
		bool operator!=(std::u8string::iterator rhs) const;
		bool operator!=(std::u8string::const_iterator rhs) const;

	private:

		std::u8string::const_iterator it_;
	};
}