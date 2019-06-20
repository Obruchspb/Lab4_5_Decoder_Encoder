#include <iostream>
#include <vector>
#include "HammingDecoder.hpp"

Hamming74Decoder::Hamming74Decoder() {
	// порождающая матрица
	H = {
		{ 1, 1, 0 },
		{ 0, 1, 1 },
		{ 1, 1, 1 },
		{ 1, 0, 1 },
		{ 1, 0, 0 },
		{ 0, 1, 0 },
		{ 0, 0, 1 },
	};
}

// вывод числа с заданным числом бит
string Hamming74Decoder::Get_bits(uint8_t n, int bits) const {
	string s = "";

	for (int i = 0; i < bits; i++)
		s += '0' + (n >> (bits - 1 - i) & 1);
	return s;
}

void Hamming74Decoder::Mult_H(uint8_t input, vector<vector<bool>> H, uint8_t &s)
{
	for (int i = 0; i < 3; i++) {
		int bit = 0;

		for (int j = 0; j < 7; j++) {
			bit ^= H[j][i] * ((input >> (6 - j)) & 1);
		}

		s |= bit << (2 - i);
	}
}

void Hamming74Decoder::Get_error(uint8_t input, uint8_t &s)
{
	if (s == 6)
		input ^= (1 << 6);
	else if (s == 3)
		input ^= (1 << 5);
	else if (s == 7)
		input ^= (1 << 4);
	else if (s == 5)
		input ^= (1 << 3);
	else if (s == 4)
		input ^= (1 << 2);
	else if (s == 2)
		input ^= (1 << 1);
	else if (s == 1)
		input ^= (1 << 0);
}

string Hamming74Decoder::Decode(const vector<uint8_t> &data)
{
	string code = "";

	for (size_t index = 0; index < data.size(); index++)
	{
		uint8_t input = data[index] & 0b1111111;
					
		uint8_t s = 0;
		uint8_t &s_ref = s;
		Mult_H(input, H, s_ref);			

		if (s != 0) 
		{
			Get_error(input, s_ref);
		}
		code += Get_bits(input >> 3, 4);
	}
	return code;
}
