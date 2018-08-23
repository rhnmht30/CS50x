// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

//creating the word container node
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

//Creating HASH_TABLE and HASH_FUNCTION DECLARATIONS
#define HASHTABLE_SIZE 65536
node *hash_table[HASHTABLE_SIZE] = {NULL};

/**
 * Hash function via reddit user delipity:
 * https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn
 */
int hash_it(char *needs_hashing)
{
    unsigned int hash = 0;
    for (int i = 0, n = strlen(needs_hashing); i < n; i++)
    {
        hash = (hash << 2) ^ needs_hashing[i];
    }
    return hash % HASHTABLE_SIZE;
}

//global variable to count words in the dict.
unsigned int w_count = 0;

//declare check variable to find out if dict. is loaded or not
bool loaded = false;

//to store word from the file
char WORD[LENGTH + 1];
// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    //creating a variable to convert the given word to lower case and check its spelling

    char w_check[LENGTH + 1];

    //store each letter of the word in lowercase
    for (int i = 0; i < strlen(word); i++)
    {
        w_check[i] = tolower(word[i]);
    }
    //since /0 character is not copied, we have to copy it explicitly
    w_check[strlen(word)] = '\0';

    //getting the hash value of this word
    int h_value = hash_it(w_check);

    if (hash_table[h_value] == NULL)
    {
        return false; //word not found in the hash table
    }

    node *cursor = hash_table[h_value];

    while (cursor != NULL)
    {
        if (strcmp(cursor->word, w_check) == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor->next;
        }
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    //open the dictionary file to read the words and store them
    FILE *inp = fopen(dictionary, "r");
    if (inp == NULL)
    {
        printf("Could not open dictionary");
        return false;
    }

    while (fscanf(inp, "%s\n", WORD) != EOF)
    {
        //count the words from the file
        w_count++;

        // allocate space for a new node named 'container' to store a word from dict.
        node *w_container = malloc(sizeof(node));
        //check for successfull allocation
        if (w_container == NULL)
        {
            printf("Could not allocate memory for new word \n");
            return false;
        }

        strcpy(w_container->word, WORD);
        w_container->next = NULL;

        //getting the hash value for that word
        int h_value = hash_it(WORD);

        //inserting the word in the particular hash value
        //if hash_table for that value is empty
        if (hash_table[h_value] == NULL)
        {
            hash_table[h_value] = w_container;
        }
        //if its not empty then insert in the front of the list
        else
        {
            w_container->next = hash_table[h_value];
            hash_table[h_value] = w_container;
        }
    }
    loaded = true;//updating the global value to check loading of a dictionary
    fclose(inp);
    return loaded;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (loaded)
    {
        return w_count; // a global variable that counts the word in dict. when its loaded
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        node *cursor = hash_table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    loaded = false;//updating the global value of loading of dictionary
    return true;
}
