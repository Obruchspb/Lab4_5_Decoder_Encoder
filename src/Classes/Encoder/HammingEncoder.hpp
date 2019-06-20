#include <iostream>
#include <vector>

// интерфейс кодировщика
class Encoder {

public:
	virtual std::string Encode(const std::vector<uint8_t> &data) = 0; // виртуальная функция кодирования
};

// кодировщик кода Хэмминга 7-4
class Hamming74Encoder : public Encoder {
	std::vector<std::vector<bool>> G; // порождающая матрица

	std::string PrintBits(uint8_t n, int bits = 8) const; // вывод числа с заданным числом бит

public:
	Hamming74Encoder(); // конструктор кодировщика

	std::string Encode(const std::vector<uint8_t> &data); // кодирование
};
