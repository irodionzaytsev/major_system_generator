#ifndef ESPANOL_H
#define ESPANOL_H
#include <stdio.h>
#include <string.h>
const char* next(const char*, char);
const char* next_cons(const char*);
extern int DOUBLE;
#define MAX_WORD_LENGTH 30
class palabra
{
    char p[MAX_WORD_LENGTH+1];
    char* cons; //el consonante para la foncion
public:
    void prox_cons(void); // set to the next consonant
    palabra(const char* pal)
    {
        strcpy(p, pal);
        cons = p;
        prox_cons();
    }
    ~palabra() {}
    int check(const char* set);
    int match(int count, char** sets);
};
#endif // ESPANOL_H
