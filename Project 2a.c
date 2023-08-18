//Project 2(a)
//Affine Cipher C implementation

#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

/*const int c = 7;
const int d=8; */

int c;
int d;

string encryptMessage(string msg)
{
    string cipher = "";
    for (int i = 0; i < msg.length(); i++)
    {
        if (msg[i] != ' ')
            /*applying encryption formula(a x + b) mod m
            {here x is msg[i] and m is 64} and added 'A' to
            bring it in range of ascii alphabet[ 65-90 | A-Z ]*/
            cipher = cipher +
            (char)((((c * (msg[i] - 'A')) + d) % 64) + 'A');

        /*else if (msg[i] != ' ')
            applying encryption formula(a x + b) mod m
            {here x is msg[i] and m is 64} and added 'A' to
            bring it in range of ascii alphabet[ 97-122 | a-z ]
            cipher = cipher +
            (char)((((c * (msg[i] - 'a')) + d) % 64) + 'a');
            */
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

    //Find a^-1 (the multiplicative inverse of a
        //in the group of integers modulo m.)
    for (int i = 0; i < 64; i++)
    {
        flag = (c * i) % 64;

        //Check if (a*i)%26 == 1,
                //then i will be the multiplicative inverse of a
        if (flag == 1)
        {
            a_inv = i;
        }
    }
    for (int i = 0; i < cipher.length(); i++)
    {
        if (cipher[i] != ' ')
            /*Applying decryption formula a^-1 ( x - b ) mod m
            {here x is cipher[i] and m is 64} and added 'A'
            to bring it in range of ASCII alphabet[ 65-90 | A-Z ] */
            msg = msg +
            (char)(((a_inv * ((cipher[i] + 'A' - d)) % 64)) + 'A');

        /* else if (cipher[i] != ' ')
             Applying decryption formula a^-1 ( x - b ) mod m
            {here x is cipher[i] and m is 64} and added 'A'
            to bring it in range of ASCII alphabet[ 97-122 | a-z ]
             msg = msg +
             (char)(((a_inv * ((cipher[i] + 'a' - d)) % 64)) + 'a');
             */
        else
            //else simply append space character
            msg += cipher[i];
    }

    return msg;
}



int main(void)
{
    //string msg = "WELCOME";

    string msg;
    std::cout << "Enter the message to encrypt and decrypt in Capital letter" << std::endl;
    std::cin >> msg;

    std::cout << "Enter key 1 in integer value reletive prime to 64:" << std::endl;
    std::cin >> c;
    std::cout << "Enter key 2 in integer value from 0-63:" << std::endl;
    std::cin >> d;


    //Encryption function
    string cipherText = encryptMessage(msg);
    std::cout << "Encrypted Message is : " << cipherText << endl;

    //Decryption function
    std::cout << "Decrypted Message is: " << decryptCipher(cipherText);

    std::cin.ignore();
    return 0;
}