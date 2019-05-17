#include <iostream>
#include "runSortingMethods.h"
#include <fstream>
#include <string>
#include <ctime>
#include <stdio.h>


using namespace std;

runAll::runAll(){

  bubbleSortArray=0;
  quickSortArray=0;
  insertSortArray=0;
  selectSortArray=0;
  arraySize=0;
  fileName= "SortingNeeded.txt";
}

runAll::~runAll(){
//delete dynamically allocated memory
delete[] bubbleSortArray;
delete[] quickSortArray;
delete[] insertSortArray;
delete[] selectSortArray;
}
//sorting algorithims

void runAll::insertSort(double insertArr[], int maxSize)
{
  int i= 0;
  int j= 0;

  for(i = 1; i < maxSize; ++i){

    double temp = insertArr[i];
    j= i-1;

    while(j >=0 && insertArr[j] > temp)
    {
      insertArr[j+1] = insertArr[j];
      --j;
    }
    insertArr[j+1] = temp;
  }


}


void runAll::bubbleSort(double bubbleArr[], int maxSize)
{

for (int i = 0; i < maxSize; ++i)
{
  double temp = 0;

  for(int j = 0; j < maxSize - 1; ++j)
  {
      if(bubbleArr[j] > bubbleArr[j+1])
      {
        temp = bubbleArr[j+1];
        bubbleArr[j+1] = bubbleArr[j];
        bubbleArr[j] = temp;
      }
    }
  }
}


double runAll::separatePosition(double arraySort[], int firstPosition, int finalPosition)
{
  int  pivot = firstPosition; //set the pivot start
  int pivotPos = arraySort[firstPosition]; //set the pivot value

    for(int j = firstPosition+1 ; j <= finalPosition ; j++)
    {

        if(arraySort[j] <=pivotPos)
        {
            pivot++;
            swap(&arraySort[j], &arraySort[pivot]); //using the pivot to sort timeSections of the array
        }
    }

    swap(&arraySort[pivot], &arraySort[firstPosition]); //swapping values to sort them in the right order

    return pivot;
}


void runAll::quickSort(double arraySort[], int firstPosition, int finalPosition)
{
  int pivotPos=0;
  int NewEndPart= 0;
  int newStartPart =0;

   if(firstPosition > finalPosition) //tales in first index and finalPosition of array to start the sort
   {
   }
   else{
     pivotPos = separatePosition(arraySort, firstPosition, finalPosition); //creates the pivot point to be used in sorting the array before and after the pivot
     NewEndPart= pivotPos-1;
     newStartPart= pivotPos+1;
     quickSort(arraySort, firstPosition, NewEndPart);
     quickSort(arraySort, newStartPart, finalPosition);
   }

}

//used for quicksort and select sort
void runAll::swap(double* a, double* b)
{
    double  temp = *a;
    *a = *b;
    *a = temp;
}
void runAll::runQuickSort()
{
//fileName= fileInput;
  //readFile(fileName);

cout << "Quick Sort" << endl;
  int left= arraySize-1;
    clock_t start = clock();
    quickSort(quickSortArray, 0, left);
    clock_t end = clock();
    double timeSec = double(end - start) / CLOCKS_PER_SEC;
    for (int i=0; i < arraySize ; i++)
    {
      cout << " "<< quickSortArray[i] << " " ;
    }
    cout << endl;
  cout <<"Time " <<timeSec *100  << " "<< endl;
  cout << endl;
}
void runAll::runBubbleSort()
{
  cout << "Bubble Sort" << endl;
  clock_t begin = clock();
  bubbleSort(bubbleSortArray, arraySize);
  clock_t end = clock();
  for (int i=0; i < arraySize ; i++)
  {
      cout << " "<< bubbleSortArray[i] << " " ;

  }
  cout << endl;

    double timeSec = double(end - begin) / CLOCKS_PER_SEC;

    cout <<"Time " <<timeSec *100 << " "<< endl;
    cout << endl;

}
void runAll::runInsertSort()
{
  cout << "Insertion Sort" << endl;
  clock_t begin = clock();

  insertSort(insertSortArray, arraySize);
  clock_t end = clock();

  for (int i=0; i < arraySize ; i++)
  {
    cout << " "<< insertSortArray[i] << " " ;
  }
    cout << endl;
    double timeSec = double(end - begin) / CLOCKS_PER_SEC;
    cout <<"Time " <<timeSec *100 << " "<< endl;
      cout << endl;

}
void runAll::runMergeSort(){ //code referenced from class + Geeks from geeks (needed to modify it a bit)

cout << "Selection Sort" << endl;
clock_t begin = clock();
mergeSort(selectSortArray, arraySize);
clock_t end = clock();
double timeSec = double(end - begin) / CLOCKS_PER_SEC;
for (int i=0; i < arraySize ; i++)
{
  cout << " "<< selectSortArray[i] << " " ;
}
  cout << endl;
  cout <<"Time it took: " <<timeSec << " milliseconds"<< endl;
  cout << endl;
}
void runAll::mergeSort(double array1[], int size){ //code referenced from class + Geeks from geeks (needed to modify it a bit)
  int i= 0;
  int j= 0;
  int minIndex= 0;

  for (i= 0; i<size-1; ++i){
    minIndex=i;
    for(j=i+1; j< size; ++j){
      if(array1[j] < array1[minIndex]){
            minIndex=j;
      }
    }
    swap(&array1[minIndex],&array1[i]);

  }
}
void runAll::readFile(string fileInput)
{
  ifstream file;
  string line = " ";
  int lineCounter=0;
  file.open(fileName);
 //read fileName in and grab the first line in order to set the array size
    while(getline(file, line))
    {
      if(lineCounter==0)
      {
        //converts string to integer
        arraySize= atof(line.c_str());

      }
      lineCounter++;
    }

//close file to reset pointer to top of file
    file.close();
    file.open(fileName);
    lineCounter=0;
    int numCount=0;
    //set the size of the arrays
    bubbleSortArray = new double[arraySize];
    quickSortArray = new double[arraySize];
    insertSortArray = new double[arraySize];
    selectSortArray= new double [arraySize];
    for (int i=0; i < arraySize ; ++i)
    {
      bubbleSortArray[i] = 0;
      quickSortArray[i]=0;
      insertSortArray[i]=0;
      selectSortArray[i]=0;
    }

//set the values in array to 0
    while(getline(file, line))
    {
      if(lineCounter==0)
      {

      }
      else{

          bubbleSortArray[numCount] = atof(line.c_str());
          quickSortArray[numCount]= atof(line.c_str());
          insertSortArray[numCount]= atof(line.c_str());
          selectSortArray[numCount]= atof(line.c_str());
          numCount++; //increase the index counter for the arrays essentially for looping through the array

      }
      lineCounter++; //increase line counter

    }


}
