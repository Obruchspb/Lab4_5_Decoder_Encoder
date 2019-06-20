#include <iostream>
#include <vector>

// интерфейс кодировщика
class Encoder 
{

public:
	virtual std::string Encode(const std::vector<uint8_t> &data) = 0; // на входе вектр uint8_t, который хранит кодируемые числа
};

// кодировщик кода Хэмминга 7-4
class Hamming74Encoder : public Encoder 
{
	std::vector<std::vector<bool>> G; // порождающая матрица

	std::string Get_bits(uint8_t n, int bits = 8) const; // первод 10-го числа в 2-е формата string На входе: число и количество бит, которые мы переводим
	void Mult_g(uint8_t high, uint8_t low, uint8_t &highOut, uint8_t &lowOut, std::vector<std::vector<bool>> G);
	//На вход поступает верхний полубат числа uint8_t, нижний полубайт числа uint8_t. А так же ссылки на результаты кодирования и пораждающая матрица

public:
	Hamming74Encoder(); 

	std::string Encode(const std::vector<uint8_t> &data); 
};
