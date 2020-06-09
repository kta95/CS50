#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string convert_key(string key); // function to convert key to uppercase
void encrypt_t0_cipher(string key, string text);    //function declaration to encrypt to cipher text

int main(int argc, string argv[])   // main function with command line arguments
{
    if (argc == 2)  // check the argument numbers
    {
        string key = argv[1];
        if (strlen(key) == 26)  // check the number of arguments
        {
            for (int i = 0, n = strlen(key); i < n; i++)
            {
                if ((key[i] >= 'a' && key[i] <= 'z') || (key[i] >= 'A' && key[i] <= 'Z'))   // check if the argument characters are alphabet or not
                {
                    for (int j = 0; j < i; j++)
                    {
                        if (key[i] == key[j])
                        {
                            printf("a character must contain only once \n");    // error message
                            return 1;
                        }
                    }

                }
                else
                {
                    printf("key must contain only alphabetic characters\n");    // error message
                    return 1;
                }
            }
            string text = get_string("plaintext:  ");   // prompt the user for plaintext to encrypt
            encrypt_t0_cipher(key, text);   // encrypt function call
            return 0;
        }
        else
        {
            printf("Key must contain 26 characters.\n");    // error message
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");  // error message
        return 1;
    }
}

string convert_key(string key)  //function for converting the key to uppercase
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (key[i] >= 97 && key[i] <= 122)
        {
            key[i] -= 32;
        }
    }
    return key;
}

void encrypt_t0_cipher(string key, string text) // function for encrypting the plaintext to cipher text
{
    key = convert_key(key);
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            text[i] = key[(text[i] - 65)];
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            text[i] = (key[(text[i] - 97)]) + 32;
        }
    }
    printf("ciphertext: %s\n", text);
}