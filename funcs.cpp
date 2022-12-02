#include "funcs.h"
#include <iostream>

#define SIZE 256

using namespace std;

// bad
void double_free()
{
  char *buf1;
  buf1 = (char *) malloc(SIZE);
  free(buf1);
  free(buf1);
}

// good
void no_double_free()
{
  char *ptr;
  ptr = (char *) malloc(SIZE);
  free(ptr);
  ptr = (char *) malloc(SIZE);
  free(ptr);
  cout << "Good!\n";
}

// bad (buf2)
void df_by_pointer()
{
  char *buf1;
  char *buf2;
  char *buf3;

  buf1 = (char *) malloc(SIZE);
  buf2 = (char *) malloc(SIZE);
  free(buf1);
  free(buf2);

  buf3 = (char *) malloc(SIZE);
  free(buf2);
  free(buf3);
}

void wrapper(char *ptr)
{
  free(ptr);
  cout << "Wrapper!\n";
}

// bad
void df_with_wrappers()
{
  char *buf1;
  buf1 = (char *) malloc(SIZE);
  wrapper(buf1);
  wrapper(buf1);
}

// bad
void conditional_dfree()
{
  int condition = 1;
  char *ptr;
  ptr = (char *) malloc(SIZE);
  if (condition){
    free(ptr);
  }
  free(ptr);
  free(ptr);
}

// good
void free_null()
{
  char *ptr;
  ptr = (char *) malloc(SIZE);
  free(ptr);
  ptr = NULL;
  free(ptr);
  cout << "Null ptr isn't a crime yet!\n";
}

//bad
void double_delete()
{
  int *x = new int[101];
  delete [] x;
  delete [] x;
}

void reassignment(char *ptr)
{
  ptr = (char *) malloc(SIZE);
  cout << "Reassignment!\n";
}

// good
void intrnl_reassignment()
{
  char *ptr;
  ptr = (char *) malloc(SIZE);
  free(ptr);
  reassignment(ptr);
  free(ptr);
}

//bad
void bad_goto()
{
  char *ptr;
  ptr = (char *) malloc(SIZE);
  free(ptr);
  goto free_me;

free_me:
  free(ptr);
  return;
}

//good
void good_goto()
{
  char *ptr;	
  bool cond = true;
  ptr = (char *) malloc(SIZE);  	
  if (cond){
    goto no_free;
  }    
  free(ptr);
  return;

no_free:
  free(ptr);
  ptr = NULL;
  return;
}
