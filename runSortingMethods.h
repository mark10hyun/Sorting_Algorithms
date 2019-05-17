#include <iostream>

using namespace std;
//run sorts
class runAll{
public:
//constructor
  runAll();
//destructor
  ~runAll();
//Reads file
  void readFile(string fileName);
//runs the sorts
  void runQuickSort();
  void runBubbleSort();
  void runInsertSort();
  void runMergeSort(); //selection sort referenced using code given in class + online resources

//resized dynamic array
  int arraySize;

  string fileName;
//dymanic array pointers for the sorts
  double *bubbleSortArray;
  double *quickSortArray;
  double *insertSortArray;
  double *selectSortArray;

  //sorting algorithms
    void bubbleSort(double bubbleArr[], int maxSize); //code given in class
    void quickSort(double arraySort[], int firstPosition, int finalPosition); // textbook and online resources
    void insertSort(double insertArr[], int maxSize); //code given in class
    void mergeSort(double selectArry[], int size); //code given in class 
    double separatePosition(double arraySort[], int firstPosition, int finalPosition); //used for quick sort to set the pivot or splitting point
    void swap(double* part1, double* part2); //swap used for quicksort and selection sort
};
