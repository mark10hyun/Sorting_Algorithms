#include <iostream>
#include <stdlib.h>
#include <array>
#include "runSortingMethods.h"

using namespace std;

int main(int argc, char const *argv[]){

  string fileName= " ";
  cout << "Please type in a file name to run sorting algorithm " << endl;
  cin >> fileName;
  runAll sortingMethods;
  sortingMethods.runQuickSort();
  sortingMethods.runBubbleSort();
  sortingMethods.runInsertSort();
  sortingMethods.runMergeSort();
  return 0;
  }
