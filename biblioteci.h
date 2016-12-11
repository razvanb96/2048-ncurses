/************************************************
File for including the library and saving 
the  headers of the functions
************************************************/
#ifndef __STDIO__
#define __STDIO__

#include <stdio.h>

#endif

#ifndef __STDLIB__
#define __STDLIB__

#include <stdlib.h>

#endif

#ifndef __TIME__
#define __TIME__

#include <time.h>

#endif

#ifndef __MATH__
#define __MATH__

#include <math.h>

#endif

#ifndef __CURSES__
#define __CURSES__

#include <curses.h>

#endif

#ifndef __SELECT__
#define __SELECT__

#include <sys/select.h>

#endif

int main_menu();
int new_game();
int load(int mat[4][4],int scor);
void save(int mat[4][4],int scor);
void aleatoriu(int mat[4][4]);
int moveup(int mat[4][4]);
int movedown(int mat[4][4]);
int moveleft(int mat[4][4]);
int moveright(int mat[4][4]);
int schimb(int old,int new,int rm,int cm);
int highscore();
int selectie(int poz);
int resume_game();
char auto_move(int mat[4][4]);
void undo(int mat[4][4],int matant[4][4]);
int you_win(int scor);
int you_lose(int scor);
int verificare(int mat[4][4]);
void citirehighscore(int v[10]);
void highscoref(int scor);
int compara(const void *a, const void *b);
void citirehighscoref(int v[11]);