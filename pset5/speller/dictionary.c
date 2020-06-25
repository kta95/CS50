// Implements a dictionary's functionality
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <strings.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

int total = 0;
// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    node *n = table[hash(word)];

    if (strcasecmp(n -> word, word) == 0)
    {
        return true;
    }

    while (n -> next != NULL)
    {
        n = n -> next;
        if (strcasecmp(n -> word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int temp = (int) tolower(word[0]) - 97;
    return temp;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    char *d_word = malloc(LENGTH);
    if (d_word == NULL)
    {
        return false;
    }
    while (fscanf(file, "%s", d_word) != EOF)
    {
        node *temp = malloc(sizeof(node));
        if (temp == NULL)
        {
            return false;
        }
        strcpy(temp -> word, d_word);
        total += 1;
        temp -> next = table[hash(d_word)];
        table[hash(d_word)] = temp;
    }

    fclose(file);
    free(d_word);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return total;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    node *temp;
    node *n;
    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL)
        {
            continue;
        }
        n = table[i];
        temp = n;

        while (n -> next != NULL)
        {
            n = n -> next;
            free(temp);
            temp = n;
        }
        free(n);
    }
    return true;
}
