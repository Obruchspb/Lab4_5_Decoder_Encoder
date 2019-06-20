#include "../Classes/Decoder/HammingDecoder.hpp"
#include "../Classes/Encoder/HammingEncoder.hpp"
#include <gtest/gtest.h>

Encoder *encoder = new Hamming74Encoder();
Decoder *decoder = new Hamming74Decoder();


TEST(Encoder_Decoder, _10_)
{

	vector<uint8_t> data;
	data.push_back(10); // ����� ���������� ����� 10 (1010)
	string code = encoder->Encode(data); // ��������
	// ����� ����������� �� ������ �������� 1010001
	ASSERT_EQ(code,"00000001010001");// ��������� ������ �� 16 ���
	// � 10-� ����� ����� 1010001 = 81, ���������� ������������� 
	code.clear();
	data.clear();
	data.push_back(81);
	code = decoder->Decode(data); // � ������ ������ �������� 1010
	ASSERT_EQ(code, "1010");

}

TEST(Encoder_Decoder, _120_)
{
	// ����� ���������� ����� 120 (0111 1000) �������� ��� �� 7 (0111) � 8 (1000)
	vector<uint8_t> data;
	
	data.push_back(7);
	string code_e = encoder->Encode(data);

	ASSERT_EQ(code_e, "00000000111001"); // 57 

	data.clear();

	data.push_back(57);
	string code_d = decoder->Decode(data);

	data.clear();
	code_e.clear();

	data.push_back(8);

	code_e.clear();
	code_e = encoder->Encode(data);

	//std::cout << code_e;
	ASSERT_EQ(code_e, "00000001000110"); // 70 

	data.clear();

	data.push_back(70);
	code_d += decoder->Decode(data);

	ASSERT_EQ(code_d, "01111000");
}

TEST(Encoder_Decoder, _0_)
{
	vector<uint8_t> data;
	data.push_back(0); // ����� ���������� ����� 0 (0)
	string code = encoder->Encode(data); // ��������
	//std::cout << code << std::endl;
	// ����� ����������� �� ������ �������� 0000000000000000 �.�. ��� ���� 0
	ASSERT_EQ(code, "00000000000000");// ��������� ������ �� 16 ���
	code.clear();
	data.clear();
	data.push_back(0);
	code = decoder->Decode(data); // ��������� ������������� 2 ���� �.�. ��������� ����� �7 ������ ��� ����, � ��� � ������ ���� ��������� 8-������ �����
	code += decoder->Decode(data);
	ASSERT_EQ(code, "00000000");
}

TEST(Encoder_Decoder, _255_)
{
	vector<uint8_t> data;
	data.push_back(255); 
	string code = encoder->Encode(data); // ��������
	//std::cout << code << std::endl;
	// ����� ����������� �� ������ �������� 11111111111111
	ASSERT_EQ(code, "11111111111111");
		code.clear();
	data.clear();
	data.push_back(127);
	code = decoder->Decode(data); // ��������� �� ��� ����� 127 �.�. ������������ ������ ������ 7 ��� (� 4) �� �����. � ����� ������ �������� �� 8 ���
	code += decoder->Decode(data);
	ASSERT_EQ(code, "11111111");
}


int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();

	delete encoder;
	delete decoder;

}