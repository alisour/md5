#include "cipher.hpp"

cipher::cipher(/* args */)
{
}
//set the size of plain text
void cipher::setPlainSize(string dir)
{
    ifstream::pos_type size;
    ifstream in(dir, ios::binary | ios::in);
    //set the size of file
    in.seekg(0, ios::end);
    size = in.tellg();
    in.seekg(0, ios::beg);
    in.close();

    this->mPlainSize = size;
}
//get the size of plain text
ifstream::pos_type cipher::getPlainSize()
{
    return this->mPlainSize;
}
//read plain file
string cipher::readFile(string dir)
{
    ifstream in(dir, ios::binary | ios::in);
    in.seekg(0, std::ios::end);
    string buffer(getPlainSize(), ' ');
    in.seekg(0);
    in.read(&buffer[0], getPlainSize());
    in.close();

    return buffer;
}
//edit string value to reverse it
string cipher::Reverse32Bits(string str)
{
    string b1, b2, b3, b4;

    for (int i = 0; i < 32; i++)
    {
        if ((i >= 0) & (i < 8))
            b1 += str[i];
        if ((i >= 8) & (i < 16))
            b2 += str[i];
        if ((i >= 16) & (i < 24))
            b3 += str[i];
        if ((i >= 24) & (i < 32))
            b4 += str[i];
    }

    return b4 + b3 + b2 + b1;
}
//from string to binary
string cipher::stringToBinary(string plain)
{
    string binary;

    for (size_t i = 0; i < plain.size(); ++i)
        binary += bitset<8>(plain.c_str()[i]).to_string();

    return binary;
}
//from unsigned int to binary
string cipher::intToBinary(unsigned number, int size)
{
    string binary;
    while (number != 0)
    {
        binary = (number % 2 == 0 ? "0" : "1") + binary;
        number /= 2;
    }

    if (size > -1)
    {
        if (size > binary.length())
        {
            string temp;
            for (int i = (int)binary.length(); i < size; i++)
            {
                temp += '0';
            }
            binary = temp + binary;
        }
    }

    return binary;
}
//from binary string into dec
unsigned cipher::binaryStringToDecimal(string a)
{
    unsigned num = 0;
    bool neg = false;

    if (a.at(0) == '1')
    {
        neg = true;
        for (int x = (int)a.length() - 1; x >= 0; x--)
        {
            if (a.at(x) == '1')
                a.at(x) = '0';
            else
                a.at(x) = '1';
        }

        a.at(a.length() - 1) += 1;
        for (int x = (int)a.length() - 1; x >= 0; x--)
        {
            if (a.at(x) == '2')
            {
                if (x - 1 >= 0)
                {
                    if (a.at(x - 1) == '1')
                        a.at(x - 1) = '2';
                    if (a.at(x - 1) == '0')
                        a.at(x - 1) = '1';
                    a.at(x) = '0';
                }
            }
            else if (a.at(x) == '3')
            {
                if (x - 1 >= 0)
                    a.at(x - 1) += '2';
                a.at(x) = '1';
            }
        }

        if (a.at(0) == '2')
            a.at(0) = '0';
        else if (a.at(0) == '3')
            a.at(0) = '1';
    }

    for (int x = (int)a.length() - 1; x >= 0; x--)
    {
        if (a.at(x) == '1')
            num += pow(2.0, a.length() - x - 1);
    }

    if (neg)
        num = num * -1;

    return num;
}
//appending plain text into 512 bit. (plain(448bit) + plain_length(64bit) )
string cipher::appendTo512Bits(string plain)
{
    string result = plain;
    int string_size = (int)plain.length();

    //adding a single 1 bit
    result += '1';

    int fullSize;

    //"0" bits are appended, so that the length in bits of the padded message
    //becomes congruent to 448, modulo 512
    if ((string_size % 512) < 448)
        fullSize = 512 * (string_size / 512) + 448 - string_size - 1;
    else
        fullSize = 512 * (string_size / 512) + 511 - string_size + 448;

    //padding with zeros to 448 bits, modulo 512
    for (int i = 0; i < fullSize; i++)
        result += '0';

    //append string length to 64 bits
    string string_size_binary = intToBinary(string_size, -1);

    string result_lenght = string_size_binary;

    for (int i = 0; i < (64 - string_size_binary.size()); i++)
        result_lenght += '0';

    return result + result_lenght;
}
//initiliaze seed values
void cipher::init()
{
    A = 0x67452301;
    B = 0xefcdab89;
    C = 0x98badcfe;
    D = 0x10325476;
    // Use binary integer part of the sines of integers (Radians) as constants:
    for (int i = 0; i < 64; i++)
    {
        k[i] = floor(pow(2, 32) * abs(sin(i + 1)));
    }
}
//encryption of plain text in md5
void cipher::encrypt(string text)
{
    int index = (int)text.length() / 32;

    for (int i = 0; i <= (index / 16) - 1; i++)
    {
        //take 16 bits of chunks from text to compute
        string m[16];
        for (int j = 0; j < 16; j++)
        {
            m[j] = Reverse32Bits(text.substr(j * 32, 32));
        }
        // Initialize hash value for this chunk:
        unsigned a = A;
        unsigned b = B;
        unsigned c = C;
        unsigned d = D;
        //main loop for diffusion
        unsigned f = 0;
        int g = 0;
        for (int j = 0; j < 64; j++)
        {
            if (j >= 0 && j < 16)
            {
                f = F(b, c, d);
                g = j;
            }
            else if (j >= 16 && j < 32)
            {
                f = G(b, c, d);
                g = (5 * j + 1) % 16;
            }
            else if (j >= 32 && j < 48)
            {
                f = H(b, c, d);
                g = (3 * j + 5) % 16;
            }
            else if (j >= 48 && j < 64)
            {
                f = I(b, c, d);
                g = (7 * j) % 16;
            }

            f = f + a + k[j] + binaryStringToDecimal(m[g]);
            a = d;
            d = c;
            c = b;
            b = b + leftRotate(f, s[j]);
        }
        //adding message digest for every round
        A += a;
        B += b;
        C += c;
        D += d;
    }
    //adding the values all together.
    string hArray[4] = {
        Reverse32Bits(intToBinary(A, 32)),
        Reverse32Bits(intToBinary(B, 32)),
        Reverse32Bits(intToBinary(C, 32)),
        Reverse32Bits(intToBinary(D, 32))};
    //print hArray from Binary to hex:
    cout << "md5 value of plainfile is: ";
    for (int h = 0; h < 4; h++)
    {
        string bin(hArray[h]);
        int result = 0;

        for (size_t count = 0; count < bin.length(); ++count)
        {
            result *= 2;
            result += bin[count] == '1' ? 1 : 0;
        }

        cout << hex << setw(8) << setfill('0') << result;
    }

    cout << endl;
}

cipher::~cipher()
{
}