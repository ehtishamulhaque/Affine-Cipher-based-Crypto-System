//Project 2c
//Affine Cipher Brute Force Attack

#include<iostream>
#include<stdlib.h>
using namespace std;

int c;
int d;

string encryptMessage(string msg)
{
    string cipher = "";
    for (int i = 0; i < msg.length(); i++)
    {
        if (msg[i] != ' ')
            cipher = cipher +
            (char)(((msg[i] - 'A') * c + d) % 26 + 'A');

        //else if (msg[i] != ' ')
           // cipher = cipher +
            //(char)(((msg[i] - 'A') * c + d) % 26 + 'a');
        else
            //else simply append space character
            cipher += msg[i];
    }
    return cipher;
}

string decryptCipher(string cipher)
{
    string msg = "";
    int a_inv = 0;
    int flag = 0;


    for (int i = 0; i < 26; i++)
    {
        flag = (c * i) % 26;


        if (flag == 1)
        {
            a_inv = i;
        }
    }
    for (int i = 0; i < cipher.length(); i++)
    {
        if (cipher[i] != ' ')
            msg = msg +
            (char)(((a_inv * ((cipher[i] + 'A' - d)) % 26)) + 'A');

        //else if (cipher[i] != ' ')
          //  msg = msg +
            //(char)(((a_inv * ((cipher[i] + 'a' - d)) % 26)) + 'a');
        else
            msg += cipher[i];
    }

    return msg;
}



int main(void)
{
    //string msg = "WELCOME";

    string msg;
    std::cout << "Enter one letter to encrypt and decrypt in Capital letter" << std::endl;
    std::cin >> msg;

    int c, d;
    std::cout << "Enter a in integer value reletive prime to 26:" << std::endl;
    std::cin >> c;
    std::cout << "Enter b in integer value from 0-26:" << std::endl;
    std::cin >> d;
   
    int gcd;
    for (int i = 1; (i <= c) && (i <= d); i++)
    {
        if ((c % i == 0) && (d % i == 0)) {
            gcd = i;
            
        }

    }
   
    /*
    std::cout << "Enter a in integer value reletive prime to 26:" << std::endl;
    std::cin >> c;
    std::cout << "Enter b in integer value from 0-26:" << std::endl;
    std::cin >> d;
    */

    //Encryption function
    string cipherText = encryptMessage(msg);
    std::cout << "Encrypted Message is : " << cipherText << endl;

    //Decryption function
    std::cout << "Decrypted Message is: " << decryptCipher(cipherText);

    std::cin.ignore();
    return 0;
}