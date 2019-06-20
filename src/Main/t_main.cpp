#include "../Classes/Decoder/HammingDecoder.hpp"
#include "../Classes/Encoder/HammingEncoder.hpp"
#include <gtest/gtest.h>

Encoder *encoder = new Hamming74Encoder();
Decoder *decoder = new Hamming74Decoder();


TEST(Encoder_Decoder, _10_)
{

	vector<uint8_t> data;
	data.push_back(10); // Будем кодирвоать число 10 (1010)
	string code = encoder->Encode(data); // Кодируем
	// полсе кодирования мы должны получить 1010001
	ASSERT_EQ(code,"00000001010001");// Дополняем нулями до 16 бит
	// В 10-й форем число 1010001 = 81, попытаемся деклодировать 
	code.clear();
	data.clear();
	data.push_back(81);
	code = decoder->Decode(data); // В ответе должны получить 1010
	ASSERT_EQ(code, "1010");

}

TEST(Encoder_Decoder, _120_)
{
	// Будем кодирвоать число 120 (0111 1000) разобьем его на 7 (0111) и 8 (1000)
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
	data.push_back(0); // Будем кодирвоать число 0 (0)
	string code = encoder->Encode(data); // Кодируем
	//std::cout << code << std::endl;
	// полсе кодирования мы должны получить 0000000000000000 т.к. все биты 0
	ASSERT_EQ(code, "00000000000000");// Дополняем нулями до 16 бит
	code.clear();
	data.clear();
	data.push_back(0);
	code = decoder->Decode(data); // повторяем декодирваоние 2 рааз т.к. кодиуются тольк о7 первых бит чила, а нам в ответе нужн ополучить 8-битное число
	code += decoder->Decode(data);
	ASSERT_EQ(code, "00000000");
}

TEST(Encoder_Decoder, _255_)
{
	vector<uint8_t> data;
	data.push_back(255); 
	string code = encoder->Encode(data); // Кодируем
	//std::cout << code << std::endl;
	// полсе кодирования мы должны получить 11111111111111
	ASSERT_EQ(code, "11111111111111");
		code.clear();
	data.clear();
	data.push_back(127);
	code = decoder->Decode(data); // разбиваем на два числа 127 т.к. декодируются только первые 7 бит (в 4) из числа. а ответ должен состоять из 8 бит
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