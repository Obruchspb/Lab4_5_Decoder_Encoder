#include <iostream>
#include <vector>
#include "HammingEncoder.hpp"

// конструктор кодировщика
Hamming74Encoder::Hamming74Encoder() 
{
	// порождающая матрица
	G = {
		{ 1, 0, 0, 0, 1, 1, 0 },
		{ 0, 1, 0, 0, 0, 1, 1 },
		{ 0, 0, 1, 0, 1, 1, 1 },
		{ 0, 0, 0, 1, 1, 0, 1 }
	};
}

// вывод числа с заданным числом бит
std::string Hamming74Encoder::Get_bits(uint8_t n, int bits) const 
{
	std::string s = "";

	for (int i = 0; i < bits; i++)
		s += '0' + ((n >> (bits - 1 - i) & 1));

	return s;
}

void Hamming74Encoder::Mult_g(uint8_t high, uint8_t low, uint8_t &highOut, uint8_t &lowOut, std::vector<std::vector<bool>> G)

{
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 4; j++) {
			int highBit = (high >> (3 - j)) & 1;
			int lowBit = (low >> (3 - j)) & 1;

			highOut ^= (G[j][i] * highBit) << (6 - i);
			lowOut ^= (G[j][i] * lowBit << (6 - i));
		}
	}
}

std::string Hamming74Encoder::Encode(const std::vector<uint8_t> &data)
{
	std::string code = "";

	for (size_t index = 0; index < data.size(); index++) 
	{
		// разделяем байт на 2 полубайта
		uint8_t high = data[index] >> 4;
		uint8_t low = data[index] & 0b1111;

		uint8_t highOut = 0;
		uint8_t lowOut = 0;

		// умножаем на порождающую мтарицу каждый из полубайтов
		Mult_g(high, low, highOut, lowOut,G);

		code += Get_bits(highOut, 7); // получаем старшие 7 бит кода
		code += Get_bits(lowOut, 7); // получаем младшие 7 бит кода
	}

	return code;
}
