//--------------------------------------------------
//
//           utflib   -   UTFライブラリ
//      by Gaccho (wanotaitei@gmail.com)
//
//--------------------------------------------------
#pragma once
#include <string>
#include <cstdint>

namespace utflib
{
	// UTF-8(string) から UTF-8(char*)へ
	const char* utf8(const std::string& src) { return src.c_str(); }

	// UTF-8(char*) から UTF-8(char*)へ
	const char* utf8(const char* src) { return src; }

	// UTF-8(char) から UTF-8(char*)へ
	const char* utf8(const char src) {
		static char u8char[2];
		u8char[0] = src;
		u8char[1] = 0;
		return u8char;
	}

	// UTF-32(char32_t) から UTF-8(char*)へ
	const char* utf8(const char32_t src) {

		static char u8char[5];
		u8char[0] = 0;
		u8char[1] = 0;
		u8char[2] = 0;
		u8char[3] = 0;
		u8char[4] = 0;

		if (src < 0 || src > 0x10ffff) return u8char;

		if (src < 0x80) u8char[0] = char(src);
		else if (src < 0x800) {
			u8char[0] = 0xc0 | char(src >> 6);
			u8char[1] = 0x80 | (char(src) & 0x3f);
		}
		else if (src < 0x10000) {
			u8char[0] = 0xe0 | char(src >> 12);
			u8char[1] = 0x80 | (char(src >> 6) & 0x3f);
			u8char[2] = 0x80 | (char(src) & 0x3f);
		}
		else {
			u8char[0] = 0xf0 | char(src >> 18);
			u8char[1] = 0x80 | (char(src >> 12) & 0x3f);
			u8char[2] = 0x80 | (char(src >> 6) & 0x3f);
			u8char[3] = 0x80 | (char(src) & 0x3f);
		}

		return u8char;
	}

	// UTF-32(char32_t*) から UTF-8(char*)へ
	const char* utf8(const char32_t* src)
	{
		static std::string u8str;
		u8str = "";

		for (size_t j = 0;; ++j) {

			if (src[j] == 0) break;
			u8str += utf8(src[j]);
		}
		return u8str.c_str();
	}

	// UTF-32(u32string) から UTF-8(char*)へ
	const char* utf8(const std::u32string& src)
	{
		static std::string u8str;
		u8str = "";

		const size_t src_len = src.length();
		for (size_t j = 0; j < src_len; ++j) {

			if (src[j] == 0) break;
			u8str += utf8(src[j]);
		}
		return u8str.c_str();
	}

	// UTF-16(char16_t) から UTF-32(char32_t)へ
	const char32_t utf32(const char16_t src0, const char16_t src1 = 0) {
		char32_t u32char{};

		if (0xd800 <= src0 && src0 < 0xdc00) {
			if (0xdc00 <= src1 && src1 < 0xe000) u32char = 0x10000 + (char32_t(src0) - 0xd800) * 0x400 + (char32_t(src1) - 0xdc00);
			else if (src1 == 0) u32char = src0;
			else return u32char;
		}
		else if (0xdc00 <= src0 && src0 < 0xe000) {
			if (src1 == 0) u32char = src0;
			else return u32char;
		}
		else u32char = src0;

		return u32char;
	}

	// UTF-16(char16_t*) から UTF-32(char32_t*)へ
	const char32_t* utf32(const char16_t* src)
	{
		static std::u32string u32str;
		u32str = U"";

		for (size_t j = 0;; ++j) {
			if (src[j] == 0) break;
			u32str += utf32(src[j], src[j + 1]);
		}
		return u32str.c_str();
	}

	// UTF-16(u16string) から UTF-32(char32_t*)へ
	const char32_t* utf32(const std::u16string& src)
	{
		static std::u32string u32str;
		u32str = U"";

		const size_t src_len = src.length();
		for (size_t j = 0; j < src_len; ++j) {
			if (src[j] == 0) break;
			u32str += utf32(src[j], src[j + 1]);
		}
		return u32str.c_str();
	}

	// UTF-16(char16_t*) から UTF-8(char*)へ
	const char* utf8(const char16_t* src) { return utf8(utf32(src)); }

	// UTF-16(string) から UTF-8(char*)へ
	const char* utf8(const std::u16string src) { return utf8(utf32(src)); }

	// UTF-16(char16_t) から UTF-8(char*)へ
	const char* utf8(const char16_t src0, const char16_t src1 = 0) { return utf8(utf32(src0, src1)); }

	// UTF-32(u32string) から UTF-32(char32_t*)へ
	const char32_t* utf32(const std::u32string& src) { return src.c_str(); }

	// UTF-32(char32_t*) から UTF-32(char32_t*)へ
	const char32_t* utf32(const char32_t* src) { return src; }

	// UTF-32(char32_t) から UTF-32(char32_t*)へ
	const char32_t* utf32(const char32_t src) {
		static char32_t u32char[2];
		u32char[0] = src;
		u32char[1] = 0;
		return u32char;
	}

	// UTF-16(u16string) から UTF-16(char16_t*)へ
	const char16_t* utf16(const std::u16string& src) { return src.c_str(); }

	// UTF-16(char16_t*) から UTF-16(char16_t*)へ
	const char16_t* utf16(const char16_t* src) { return src; }

	// UTF-16(char16_t) から UTF-16(char16_t*)へ
	const char16_t* utf16(const char16_t src) {
		static char16_t u16char[2];
		u16char[0] = src;
		u16char[1] = 0;
		return u16char;
	}

	// UTF-32(char32_t) から UTF-16(char16_t*)へ
	const char16_t* utf16(const char32_t src) {
		static char16_t u16char[3];
		u16char[0] = 0;
		u16char[1] = 0;
		u16char[2] = 0;

		if (src < 0 || src > 0x10ffff) return u16char;

		if (src < 0x10000) u16char[0] = char16_t(src);
		else {
			u16char[0] = char16_t((src - 0x10000) / 0x400 + 0xd800);
			u16char[1] = char16_t((src - 0x10000) % 0x400 + 0xdc00);
		}

		return u16char;
	}

	// UTF-32(char32_t*) から UTF-16(char16_t*)へ
	const char16_t* utf16(const char32_t* src)
	{
		static std::u16string u16str;
		u16str = u"";

		for (size_t j = 0;; ++j) {

			if (src[j] == 0) break;
			u16str += utf16(src[j]);
		}
		return u16str.c_str();
	}

	// UTF-32(u32string) から UTF-16(char16_t*)へ
	const char16_t* utf16(const std::u32string& src)
	{
		static std::u16string u16str;
		u16str = u"";

		const size_t src_len = src.length();
		for (size_t j = 0; j < src_len; ++j) {

			if (src[j] == 0) break;
			u16str += utf16(src[j]);
		}
		return u16str.c_str();
	}

	int32_t utf8Byte(char src) {
		if (0 <= uint8_t(src) && uint8_t(src) < 0x80) return 1;
		if (0xc2 <= uint8_t(src) && uint8_t(src) < 0xe0) return 2;
		if (0xe0 <= uint8_t(src) && uint8_t(src) < 0xf0) return 3;
		if (0xf0 <= uint8_t(src) && uint8_t(src) < 0xf8) return 4;
		return 0;
	}

	bool utf8_0x80To0xc0(char src) { return 0x80 <= uint8_t(src) && uint8_t(src) < 0xc0; }

	const char32_t char_utf32(const char src[5], int32_t& number_of_byte) {
		char32_t u32char{};

		number_of_byte = utf8Byte(src[0]);
		if (number_of_byte == 0) return u32char;

		switch (number_of_byte) {

		case 1:u32char = char32_t(uint8_t(src[0])); break;

		case 2:
			if (!utf8_0x80To0xc0(src[1])) return u32char;
			if ((uint8_t(src[0]) & 0x1e) == 0) return u32char;

			u32char = char32_t(src[0] & 0x1f) << 6;
			u32char |= char32_t(src[1] & 0x3f);
			break;

		case 3:
			if (!utf8_0x80To0xc0(src[1]) || !utf8_0x80To0xc0(src[2])) return u32char;
			if ((uint8_t(src[0]) & 0x0f) == 0 && (uint8_t(src[1]) & 0x20) == 0) return u32char;

			u32char = char32_t(src[0] & 0x0f) << 12;
			u32char |= char32_t(src[1] & 0x3f) << 6;
			u32char |= char32_t(src[2] & 0x3f);
			break;

		case 4:
			if (!utf8_0x80To0xc0(src[1]) || !utf8_0x80To0xc0(src[2]) || !utf8_0x80To0xc0(src[3])) return u32char;
			if ((uint8_t(src[0]) & 0x07) == 0 && (uint8_t(src[1]) & 0x30) == 0) return u32char;

			u32char = char32_t(src[0] & 0x07) << 18;
			u32char |= char32_t(src[1] & 0x3f) << 12;
			u32char |= char32_t(src[2] & 0x3f) << 6;
			u32char |= char32_t(src[3] & 0x3f);
			break;

		default:return u32char; break;

		}

		return u32char;
	}

	// UTF-8(char) から UTF-32(char32_t*)へ
	const char32_t* utf32(const char src) {
		static char32_t u32char[2];
		char u8char[5]{};
		int32_t number_of_byte;
		u8char[0] = src;

		u32char[0] = char_utf32(u8char, number_of_byte);
		u32char[1] = 0;
		return u32char;
	}

	const char32_t char_utf32(const std::string& src, char u8char[5], const size_t j, int32_t& number_of_byte)
	{
		u8char[0] = 0;
		u8char[1] = 0;
		u8char[2] = 0;
		u8char[3] = 0;

		if (src[j] == 0) return char_utf32(u8char, number_of_byte);
		u8char[0] = src[j];
		if (src[j + 1] == 0) return char_utf32(u8char, number_of_byte);
		u8char[1] = src[j + 1];
		if (src[j + 2] == 0) return char_utf32(u8char, number_of_byte);
		u8char[2] = src[j + 2];
		if (src[j + 3] == 0) return char_utf32(u8char, number_of_byte);
		u8char[3] = src[j + 3];

		return char_utf32(u8char, number_of_byte);
	}

	// UTF-8(string) から UTF-32(char32_t*)へ
	const char32_t* utf32(const std::string& src)
	{
		static std::u32string u32str;
		u32str = U"";

		char u8char[5]{};
		int32_t number_of_byte;

		const size_t src_len = src.length();
		for (size_t j = 0; j < src_len;) {
			if (src[j] == 0) break;
			u32str += char_utf32(src, u8char, j, number_of_byte);
			j += number_of_byte;
		}
		return u32str.c_str();
	}

	const char32_t char_utf32(const char* src, char u8char[5], const size_t j, int32_t& number_of_byte)
	{
		u8char[0] = 0;
		u8char[1] = 0;
		u8char[2] = 0;
		u8char[3] = 0;

		if (src[j] == 0) return char_utf32(u8char, number_of_byte);
		u8char[0] = src[j];
		if (src[j + 1] == 0) return char_utf32(u8char, number_of_byte);
		u8char[1] = src[j + 1];
		if (src[j + 2] == 0) return char_utf32(u8char, number_of_byte);
		u8char[2] = src[j + 2];
		if (src[j + 3] == 0) return char_utf32(u8char, number_of_byte);
		u8char[3] = src[j + 3];

		return char_utf32(u8char, number_of_byte);
	}

	// UTF-8(char*) から UTF-32(char32_t*)へ
	const char32_t* utf32(const char* src)
	{
		static std::u32string u32str;
		u32str = U"";

		char u8char[5]{};
		int32_t number_of_byte;

		for (size_t j = 0;; j += number_of_byte) {
			if (src[j] == 0) break;
			u32str += char_utf32(src, u8char, j, number_of_byte);
		}
		return u32str.c_str();
	}

	// UTF-8(char*) から UTF-16(char16_t*)へ
	const char16_t* utf16(const char* src) { return utf16(utf32(src)); }

	// UTF-8(string) から UTF-16(char16_t*)へ
	const char16_t* utf16(const std::string src) { return utf16(utf32(src)); }

	// UTF-8(char) から UTF-16(char16_t*)へ
	const char16_t* utf16(const char src) { return utf16(utf32(src)); }

}