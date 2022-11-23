// Implements a dictionary's functionality

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
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
    //We obtain hash value type int from the hash function
    int hashi = hash(word);

    //Going to place in the hash table
    node *n = table[hashi];
    //Going through array of linked list from hash table position
    //While position in the hash table
    while (n != NULL)
    {
        if (strcasecmp(word, n-> word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //With the use of the ASCII chart, reference: 2022, https://elcodigoascii.com.ar/codigos-ascii/espacio-codigo-ascii-32.html
    //For the type of hash table implementation, reference: 2022, https://pages.cs.wisc.edu/~siff/CS367/Notes/hash.html
    int sword = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sword += toupper(word[i]);
    }
    return (sword) % N;
}

//For function size
int dsize = 0;
// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
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
    while(fscanf(file, "%s", dword) != EOF)
    {
        //Create new node for each word scanned
        node *n = malloc(sizeof(node));
        if (!n)
        {
            return false;
        }
        //Copy word scanned into word char of node struct
        strcpy (n->word, dword);
        //Get int from hash function to locate word scanned into hash table
        int hashi = hash(dword);
        //Input int to next address in node struct to connect hash table according to hash function
        n->next = table[hashi];
        //Insert node in hash table
        table[hashi] = n;

        //Count of words in loop for function size
        dsize++;

    }

    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    //Print value of dsize from function load
    if (dsize > 0)
    {
        return dsize;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *n = table[i];
        if (n == NULL)
        {
            return true;
        }
        else if (n != NULL)
        {
            node *tmp = n;
            n = n->next;
            free(tmp);
        }
    }
    return false;
}
