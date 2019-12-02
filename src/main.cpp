#include "cipher.hpp"

int main(int argc, char **argv)
{
   cipher *cp = new cipher();
   string plain;
   string plainDir = "./../plaintext";
   //interface
   char choice;
   while (true)
   {
      cout << endl;
      cout << "0.exit" << endl;
      cout << "1.encrypt plaintext" << endl;
      cout << "your choice: ";
      choice = cin.get();
      if (choice == '0')
      {

         break;
      }
      else if (choice == '1')
      { //encryption
         //find the plain text lenght
         cp->setPlainSize(plainDir);
         //read the plain text
         plain = cp->readFile(plainDir);
         //print the message
         cout << "your message is: " << plain << endl;
         //convert plain to binary
         plain = cp->stringToBinary(plain);
         //adding a single 1 bit & padding with zeros to fill the message.
         plain = cp->appendTo512Bits(plain);
         //begin the encryption
         cp->init();
         cp->encrypt(plain); //bit of padded plain goes in
      }
      else
      {
         cout << "invalid choice!";
      }
      cout << endl
           << "-----------------------------------------------------------";
      cin.get();
   }
   free(cp);
   return 0;
}