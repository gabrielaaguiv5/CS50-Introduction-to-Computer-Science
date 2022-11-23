// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dictionary.h"

// Represents a node in a hash table
//Hash table is a collection of linked lists
typedef struct node
{
    //Every node has a word which is a character array plus /0
    char word[LENGTH + 1];
    //Address of next node
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
//26 letters of the alphabet
const unsigned int N = 26;

// Hash table
//Array of node pointers, each points to a node, for each letter of the alphabet
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //Create n type node
    node *n = NULL;
    //True if load false if no memory
    //Use of "r" because the file is for reading, for txt
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        return false;
    }
    //To put memory in the node, for each word of the file
    char dword[LENGTH + 1];
    //Allocate memory for each new node to go to the hash table
    //Address of memory size of node into n
    while(fscanf(file, "%s", dword != EOF)
    {
        node *n = malloc(sizeof(node));
        if (!n)
        {
            return false;
        }
        strcpy (n->word, dword);

        int hashi = hash(dword);

        n->next = table[hashi];

        table[hashi] = n;

    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
