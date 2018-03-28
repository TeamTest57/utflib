#include <iostream>
#include "utflib.hpp"

using namespace utflib;

int main()
{
	//UTF-8
	const std::string u8str = u8"こんにちはabcdef";
	const char* u8charP = u8"こんにちはabcdef";
	const char u8char = u8'K';

	//UTF-16
	const std::u16string u16str = u"こんにちはabcdef";
	const char16_t* u16charP = u"こんにちはabcdef";
	const char16_t u16char = u'こ';

	//UTF-32
	const std::u32string u32str = U"こんにちはabcdef";
	const char32_t* u32charP = U"こんにちはabcdef";
	const char32_t u32char = U'こ';

	//to_UTF-8--------------------------------------------------

	std::cout << "\n[to_UTF-8]\n" << std::endl;

	//UTF-8
	std::cout << utf8(u8str) << std::endl;
	std::cout << utf8(u8charP) << std::endl;
	std::cout << utf8(u8char) << std::endl;

	//UTF-16
	std::cout << utf8(u16str) << std::endl;
	std::cout << utf8(u16charP) << std::endl;
	std::cout << utf8(u16char) << std::endl;

	//UTF-32
	std::cout << utf8(u32str) << std::endl;
	std::cout << utf8(u32charP) << std::endl;
	std::cout << utf8(u32char) << std::endl;

	//--------------------------------------------------

	//to_UTF-16--------------------------------------------------

	std::cout << "\n[to_UTF-16]\n" << std::endl;

	//UTF-8
	std::cout << utf8(utf16(u8str)) << std::endl;
	std::cout << utf8(utf16(u8charP)) << std::endl;
	std::cout << utf8(utf16(u8char)) << std::endl;

	//UTF-16
	std::cout << utf8(utf16(u16str)) << std::endl;
	std::cout << utf8(utf16(u16charP)) << std::endl;
	std::cout << utf8(utf16(u16char)) << std::endl;

	//UTF-32
	std::cout << utf8(utf16(u32str)) << std::endl;
	std::cout << utf8(utf16(u32charP)) << std::endl;
	std::cout << utf8(utf16(u32char)) << std::endl;

	//--------------------------------------------------

	//to_UTF-32--------------------------------------------------

	std::cout << "\n[to_UTF-32]\n" << std::endl;

	//UTF-8
	std::cout << utf8(utf32(u8str)) << std::endl;
	std::cout << utf8(utf32(u8charP)) << std::endl;
	std::cout << utf8(utf32(u8char)) << std::endl;

	//UTF-16
	std::cout << utf8(utf32(u16str)) << std::endl;
	std::cout << utf8(utf32(u16charP)) << std::endl;
	std::cout << utf8(utf32(u16char)) << std::endl;

	//UTF-32
	std::cout << utf8(utf32(u32str)) << std::endl;
	std::cout << utf8(utf32(u32charP)) << std::endl;
	std::cout << utf8(utf32(u32char)) << std::endl;

	//--------------------------------------------------

	//Visual Studio
	//SJIS (環境によっては異なる)
	const std::string sstr = "こんにちはabcdef";
	const char* scharP = "こんにちはabcdef";
	const char schar = 'K';

	//to_UTF-8--------------------------------------------------

	std::cout << "\n[to_SJIS]\n" << std::endl;

	//UTF-8
	std::cout << utf8_s(sstr) << std::endl;
	std::cout << utf8_s(scharP) << std::endl;
	//std::cout << utf8_s(schar) << std::endl;

	//UTF-16
	std::cout << utf8(utf16_s(sstr)) << std::endl;
	std::cout << utf8(utf16_s(scharP)) << std::endl;
	//std::cout << utf8(utf16_s(schar)) << std::endl;

	//UTF-32
	std::cout << utf8(utf32_s(sstr)) << std::endl;
	std::cout << utf8(utf32_s(scharP)) << std::endl;
	//std::cout << utf8(utf32_s(schar)) << std::endl;

	//--------------------------------------------------

	return 0;
}