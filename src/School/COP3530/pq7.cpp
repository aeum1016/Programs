#include <iostream>
#include <climits>

using namespace std;

int maxChildId(int arr[], int size, int currentNode)
{
  int leftChild = currentNode * 2 + 1;
  int rightChild = currentNode * 2 + 2;
  if(leftChild >= size) return -1;

  int leftVal = arr[leftChild], rightVal = INT_MIN;
  if(rightChild < size)
  {
    rightVal = arr[rightChild];
  }
  if(leftVal > rightVal) return leftChild;
  else return rightChild;
}

int* extractMax(int arr[], int size)
{
  arr[0] = arr[size-1];

  int i = 0;

  while(arr[i] < arr[maxChildId(arr, size-1, i)] && maxChildId(arr, size-1, i) != -1)
  {
    int maxID = maxChildId(arr,size-1, i);
    int temp = arr[i];
    arr[i] = arr[maxID];
    arr[maxID] = temp;
    i = maxID;
  }

	return arr; 
}