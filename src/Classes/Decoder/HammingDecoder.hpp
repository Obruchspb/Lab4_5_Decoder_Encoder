#pragma once
#include <iostream>
#include <vector>

using std::string;
using std::vector;



class Decoder {

public:
	virtual string Decode(const vector<uint8_t> &data) = 0; // ����������� ������� �������������
	// ������� ��������� ������ uint8_t �����, ������� ����� ������������
};

// ������������ ���� �������� 7-4
class Hamming74Decoder : public Decoder {
	vector<vector<bool>> H; // ����������� �������

	string Get_bits(uint8_t n, int bits = 8) const; // ������ 10-�� ����� � 2-� ������� string �� �����: ����� � ���������� ���, ������� �� ���������
	void Mult_H(uint8_t input, vector<vector<bool>> H, uint8_t &s); // ������� ��������� ������� �����, ����������� ������� � ��������� �� ����������, � ������ ����� ������� ���������
	void Get_error(uint8_t input, uint8_t &s); //������� ����������� ������. �� ���� ����� � �������� � ������ �� ���������� � ���������
	
public:
	Hamming74Decoder(); 

	string Decode(const vector<uint8_t> &data); 
};
