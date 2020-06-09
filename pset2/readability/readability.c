#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

int count_letters(string t);// function declaration
int count_words(string t);
int count_sentences(string t);
void get_grade(int L, int S);

int main(void)  //main
{
    string t = get_string("Text: "); // prompt the user

    int letters = count_letters(t); // number of letters
    int words = count_words(t); // number of words
    int sentences = count_sentences(t); // number of sentences

    // printf("%i\n", letters);
    // printf("%i\n", words);
    // printf("%i\n", sentences);

    float L = ((float)letters /  words) * 100 ; // average number of letters by 100 words
    float S = (sentences / (float) words) * 100; // average number of sentences by 100 words

    // L = round(L)/100;
    // S = round(S)/100;
    //  printf("%f\n", L);
    //  printf("%f\n", S);
    get_grade(L, S);    // to print grade
}

int count_letters(string t) // to count the number of letters
{
    int l = 0;
    for (int i = 0; i < strlen(t); i++)
    {
        if ((t[i] >= 'a' && t[i] <= 'z') || (t[i] >= 'A' && t[i] <= 'Z'))
        {
            l++;
        }
    }
    return l;
}

int count_words(string t)   // to count the number of words
{
    int w = 0;
    for (int i = 0; i < strlen(t); i++)
    {
        if (t[i] == ' ')
        {
            w++;
        }
    }
    w++;
    return w;
}

int count_sentences(string t)   // to count the nubmer of sentences
{
    int s = 0;
    for (int i = 0; i < strlen(t); i++)
    {
        if (t[i] == '.' || t[i] == '?' || t[i] == '!')
        {
            s++;
        }
    }

    return s;
}

void get_grade(int L, int S)        // to print the grade with Coleman-Liau index
{
    float in = 0.0588 * L - 0.296 * S - 15.8;


    if (in >= 7.5 && in <= 7.6)
    {
        int ind = in;
        printf("Grade %i\n", ind);
    }
    else
    {
        int index = round(in);
        if (index >= 16)
        {
            printf("Grade 16+\n");

        }
        else if (index < 1)
        {
            printf("Before Grade 1\n");

        }
        else
        {
            printf("Grade %i\n", index);
        }

    }


}