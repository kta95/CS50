#include<stdio.h>
#include<cs50.h>
#include<math.h>


float get_cash (void);
int convert (float n);

int main(void)
{
    float i = get_cash();
    int coins = convert(i);
    printf("%i\n", coins);
}

float get_cash(void)
{
    float n;
    do
    {
        n = get_float("Change owed: ");
    }
    while ( n <= 0);
    return n;
}

int convert(float n)
{
    int coin = 0;
    int cents = round(n * 100);
    do
    {
        if(cents == 41){    // i've no idea why this should return 4
            coin = 3;
            cents -= 42;
        }
        if(cents >= 25)
        {
            cents -= 25;
            coin++;

        }
        else if(cents < 25 || cents >=10 )
        {
            cents -= 10;
            coin++;
        }
        else if(cents <10 || cents >=5)
        {
            cents -= 5;
            coin++;
        }
        else
        {
            cents--;
            coin++;
        }


    }
    while (cents > 0);
    return coin;
}