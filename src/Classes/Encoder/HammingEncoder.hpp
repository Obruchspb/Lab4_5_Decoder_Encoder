#include <iostream>
#include <vector>

// ��������� �����������
class Encoder {

public:
	virtual std::string Encode(const std::vector<uint8_t> &data) = 0; // ����������� ������� �����������
};

// ���������� ���� �������� 7-4
class Hamming74Encoder : public Encoder {
	std::vector<std::vector<bool>> G; // ����������� �������

	std::string PrintBits(uint8_t n, int bits = 8) const; // ����� ����� � �������� ������ ���

public:
	Hamming74Encoder(); // ����������� �����������

	std::string Encode(const std::vector<uint8_t> &data); // �����������
};
