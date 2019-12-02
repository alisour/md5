Introduction:

This is a C++ project that implements the Message Digest Algorithm (MD5).

The end goal of this project is using the file named "plainfile" as an input for the cipher.

You can change the directory with a variable named "plainDir" in main.cpp.

Code comes with "exe" file but if you want you can build again with cmake "make" command in ./build directory.

Class usage:

Defined functions outside class:

	F(x,y,z): [x (and) y] (or) [(not)x (and)z]
	
	G(x,y,z): [x (and) z] (or) [y (and) (not)z] 
	
	H(x,y,z): x (xor) y (xor) z
	
	I(x,y,z): x (xor) y (or) (not)z
	
	leftrotate(x,n): Takes x and does left circular shifting n times.
	
In class:

	private variables:
		mPlainSize: used for determing size of plainfile.
		
		A,B,C,D: seed values for diffusion.
		
		s[64]: values used for left shifting.
		
		k[64]: constants for diffusion.
	
	public:
		setPlainSize(string dir): for setting mPlainSize.
		
		getPlainSize: for getting mPlainSize.
		
		readFile(string dir): for reading "plainfile".
		
		Reverse32Bits(string dir): dividing 32 bit string into 8 bits (1 byte) and reversing their order.
		
		stringToBinary(string plain): convertion from string to binary.

		intToBinary(unsigned number, int size): convertion from integer to binary.

		binaryStringToDecimal(string a): conversion from binary string to decimal one.

		appendTo512Bits(string plain): padding the input value into 512 bit module.	

		init(): initilazing A,B,C,D and k constants.

		encrypt(string text): Encryption happens here. Takes already padded value as input.
	
	
Main:
	Simply creates an object from cipher class calls its functions and prints a menu that can be expanded later
	
	At the end and begining of while loop i used two cin.get() function so be careful to not break the code while giving an input at command prompt. If it got stuck at "invalid choice" press enter twice to fix.
	