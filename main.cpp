#include "funcs.h"
#include <iostream>

using namespace std;

int main()
{
  int choice;
  void (*func) (void);

  while (1) {
    cout << "Enter your choice: ";
    cin >> choice;
    
    switch (choice) {
      case 1:
        double_free();
        break;
      case 2:
        no_double_free();
        break;
      case 3:
        func = df_by_pointer;
        func();
        break;
      case 4:
        df_with_wrappers();
        break;
      case 5:
        conditional_dfree();
        break;
      case 6:
        free_null();
        break;
      case 7:
        double_delete();
        break;
      case 8:
        intrnl_reassignment();
        break;
      case 9:
        bad_goto();
        break;
      case 10:
        good_goto();
        break;
      default:
        cout << "Be more self-confident!\n";
        break;
    }
  }
  return 0;
}
