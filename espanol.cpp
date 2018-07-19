#include "espanol.h"
#include <stdio.h>
#include <string.h>
static int isVowel(char c)
{
    switch(c)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return 1;
    default:
        return 0;
    }
}
void palabra::prox_cons(void) // cons = proximo consonante
{
    while(isVowel(*cons))
        ++cons;
}
int palabra::check(const char* set) // check if the following set matches the current cons.
{
    if(!(*cons))
        return 0; // error - end of word
    while(*set)
    {
        if(*set == *cons)
        {
            if(DOUBLE)
            {
                if(cons[1] == cons[0])
                {
                    cons += 2;
                    prox_cons();
                    return 1;
                }
            }
            ++cons;
            prox_cons();
            return 1;

        }
        ++set;
    }
    return 0;
}
int palabra::match(int count, char **sets)
{

    for(int i = 0; i < count; ++i)
    {
        int ret = check(sets[i]);
        if(!ret)
            return 0;
    }
    //check that it is the end of the word
    if(*cons)
        return 0;
    return 1;
}
#if 0
const char* next_cons(const char* str)
{
    while(*str) {
        switch(*str)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            ++str;
            continue;
        default:
            return str;
        }
    }
    return str;
}
const char * next(const char* rest /* the remaining characters of the word */, char cur /* the current chararcter */)
{
    /* skip the vowels */
    rest = next_cons(rest);
    if(cur == *rest)
    {
        if(rest[1] == cur && DOUBLE) // see if it is a double, DOUBLE defined by the user. If 0 - ignore
            return rest + 2; // continue scanning
        return rest + 1;
    }
    return (const char* )1;
}
#endif

