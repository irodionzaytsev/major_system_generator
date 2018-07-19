#include "espanol.h"
#include <stdio.h>
#include <string.h>
int DOUBLE;
static const char *help_msg = "Usage: <filename> <ignore double> <first_letter> <second_letter> ...\n\
The file must contain a list of words.\n\
Ignore double is optional, this argument must be 1\n\
(double letters considered as one) or nonexistent.\n";
int main(int argc, char **argv)
{
    if(argc == 1)
    {
        printf(help_msg);
        return 0;
    }
    FILE * list = fopen(argv[1], "r");
    if(!list)
    {
        printf("Couldn't open the file");
        return 1;
    }
    int i = 2;
    if(argv[2][0] == '1')
    {
        DOUBLE = 1;
        i = 3;
    }
    else
        DOUBLE = 0;
    char word[MAX_WORD_LENGTH];
    int start = i;
    int count = argc - start;
    char **sets = &argv[i];
    while(fscanf(list, "%30s", word) != EOF) // see if the word is suited
    {
        palabra w(word);
        if(w.match(count, sets))
            printf("%s\n",word);
    }
    return 0;
}
