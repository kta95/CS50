#include<cs50.h>
#include<stdio.h>

void print_pyramids(int n);
int get_number(void);
void print_star(int n);

int main(void)      // green flag
{
    int i = get_number();   //get the height
    print_pyramids(i);   //to print pyramids from mario
}

int get_number(void)    //to prompt user
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}
void print_star(int n) //to print desired hashes
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}

void print_space(int n) //to print desired spaces
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void print_pyramids(int n)  //to print pyramids
{
    int j = 1;
    int k = 1;

    while (j <= n)
    {
        print_space(n - k);
        print_star(k);
        print_space(2);
        print_star(k);
        j++;
        k++;
        printf("\n");
    }


}