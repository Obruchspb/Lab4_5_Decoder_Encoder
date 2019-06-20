#pragma once
#include <iostream>
#include <vector>

using std::string;
using std::vector;



class Decoder {

public:
	virtual string Decode(const vector<uint8_t> &data) = 0; // виртуальная функция декодирования
	// Функция принемает вектор uint8_t чисел, которые будем декодировать
};

// декодировщик кода Хэмминга 7-4
class Hamming74Decoder : public Decoder {
	vector<vector<bool>> H; // порождающая матрица

	string Get_bits(uint8_t n, int bits = 8) const; // первод 10-го числа в 2-е формата string На входе: число и количество бит, которые мы переводим
	void Mult_H(uint8_t input, vector<vector<bool>> H, uint8_t &s); // Функция принемает входное число, проверочную матрицу и указатель на переменную, в котору будет записан результат
	void Get_error(uint8_t input, uint8_t &s); //Функция исправления ошибок. На вход число с ошибками и ссылка на переменную с синдромом
	
public:
	Hamming74Decoder(); 

	string Decode(const vector<uint8_t> &data); 
};
