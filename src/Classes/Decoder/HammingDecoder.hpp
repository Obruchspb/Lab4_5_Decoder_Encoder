#pragma once
#include <iostream>
#include <vector>

using std::string;
using std::vector;


// ��������� �������������
class Decoder {

public:
	virtual string Decode(const vector<uint8_t> &data) = 0; // ����������� ������� �������������
};

// ������������ ���� �������� 7-4
class Hamming74Decoder : public Decoder {
	vector<vector<bool>> H; // ����������� �������

	string PrintBits(uint8_t n, int bits = 8) const; // ����� ����� � �������� ������ ���

public:
	Hamming74Decoder(); // ����������� �����������

	string Decode(const vector<uint8_t> &data); // �����������
};
