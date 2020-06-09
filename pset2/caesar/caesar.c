#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string encrypt(string t, int key);// function for encryption
int main(int argc, string argv[])    // main function
{

    if (argc == 2)
    {
        char *e;
        long lkey;
        int errno = 0;

        lkey = strtol(argv[1], &e, 10);
        if ((errno != 0) || (*argv[1] == 0) || (*e != 0) || (lkey < 0) || (((int) lkey) != lkey) || argc >= 3)
            // this statement check to see the characters on argv[1] are all digits
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            string a = argv[1];
            int key = atoi(a);  // convert the command line to integer
            if (key > 0)
            {
                string text = get_string("plaintext:  ");
                string result = encrypt(text, key);
                printf("ciphertext: %s\n", result);
                return 0;
            }
            else
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

string encrypt(string text, int key)    // to encrypt the text using caesar cipher
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i])) // to encrypt uppercase
            {
                text[i] = ((text[i] - 'A' + key) % 26) + 'A';
            }
            else
            {
                text[i] = ((text[i] - 'a' + key) % 26) + 'a';// to encrypt lower
            }
        }
        // otherwise, just ignore it without encryption
    }
    return text;
}