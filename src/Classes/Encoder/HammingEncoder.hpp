#include <iostream>
#include <vector>

// ��������� �����������
class Encoder 
{

public:
	virtual std::string Encode(const std::vector<uint8_t> &data) = 0; // �� ����� ����� uint8_t, ������� ������ ���������� �����
};

// ���������� ���� �������� 7-4
class Hamming74Encoder : public Encoder 
{
	std::vector<std::vector<bool>> G; // ����������� �������

	std::string Get_bits(uint8_t n, int bits = 8) const; // ������ 10-�� ����� � 2-� ������� string �� �����: ����� � ���������� ���, ������� �� ���������
	void Mult_g(uint8_t high, uint8_t low, uint8_t &highOut, uint8_t &lowOut, std::vector<std::vector<bool>> G);
	//�� ���� ��������� ������� ������� ����� uint8_t, ������ �������� ����� uint8_t. � ��� �� ������ �� ���������� ����������� � ����������� �������

public:
	Hamming74Encoder(); 

	std::string Encode(const std::vector<uint8_t> &data); 
};
