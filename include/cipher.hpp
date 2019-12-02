#ifndef cipher_hpp
#define cipher_hpp

#include <iostream>
#include <fstream>
#include <bitset>
#include <iomanip>
#include <string>
#include <cmath>

// 4 main function for diffusion:
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

// LeftRotate function definition:
#define leftRotate(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

using namespace std;

class cipher
{
private:
    ifstream::pos_type mPlainSize;

    uint32_t A, B, C, D;

    // "s" specifies the per-round shift amounts:
    unsigned s[64] = {
        7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

    unsigned k[64];

public:
    cipher();

    void setPlainSize(string dir);

    ifstream::pos_type getPlainSize();

    string readFile(string dir);

    string Reverse32Bits(string str);

    string stringToBinary(string plain);

    string intToBinary(unsigned number, int size);

    unsigned binaryStringToDecimal(string a);

    string appendTo512Bits(string plain);

    void init();

    void encrypt(string text);

    ~cipher();
};

#endif