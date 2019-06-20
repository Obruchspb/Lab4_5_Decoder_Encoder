#pragma once
#include <iostream>
#include <vector>

using std::string;
using std::vector;


// интерфейс декодировщика
class Decoder {

public:
	virtual string Decode(const vector<uint8_t> &data) = 0; // виртуальная функция декодирования
};

// декодировщик кода Хэмминга 7-4
class Hamming74Decoder : public Decoder {
	vector<vector<bool>> H; // порождающая матрица

	string PrintBits(uint8_t n, int bits = 8) const; // вывод числа с заданным числом бит

public:
	Hamming74Decoder(); // конструктор кодировщика

	string Decode(const vector<uint8_t> &data); // кодирование
};
