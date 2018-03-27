#pragma once
//#include <string>
#include <cstdint>

//char* sjisToUtf8(const char* sjis)
//{
//	constexpr size_t str_len = 256;
//	constexpr size_t for_len = str_len - 3;
//
//	uint8_t utf8[str_len] = {};
//	char utf8_c[str_len] = {};
//
//	uint8_t sjis_0;
//	uint8_t sjis_1;
//
//	for (size_t i = 0; i < for_len; ++i) {
//		if (sjis[i] == 0) break;
//		sjis_0 = sjis[i];
//
//		if (sjis_0 <= 0x7f) utf8[i] = sjis_0;
//		else if (sjis_0 <= 0xa0) {
//			if (sjis[i + 1] == 0) break;
//			sjis_1 = sjis[i + 1];
//
//			switch (sjis_0)
//			{
//			case 0x82:
//				if (sjis_1 <= 0x9e) {
//
//				}
//				else if (sjis_1 <= 0xf1) {
//
//					utf8[i] = 0xe3;
//					
//					if (sjis_1 <= 0xdd) {
//						utf8[i + 1] = 0x81;
//						utf8[i + 2] = 0x81 + 0xdd - sjis_1;
//					}
//					else {
//						utf8[i + 1] = 0x82;
//						utf8[i + 2] = 0xde + 0xf1 - sjis_1;
//					}
//					i += 2;
//				}
//				break;
//			}
//
//		}
//	}
//
//	for (size_t i = 0; i < str_len; ++i) {
//
//	}
//	return utf8_c;
//}