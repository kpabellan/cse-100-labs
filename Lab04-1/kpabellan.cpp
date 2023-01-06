#include <iostream>
using namespace std;

void maxHeapify(int *arr, int numberCount, int i) {
  int largestValue = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < numberCount && arr[left] > arr[largestValue]) {
    largestValue = left;
  }

  if (right < numberCount && arr[right] > arr[largestValue]) {
    largestValue = right;
  }

  if (largestValue != i) {
    swap(arr[i], arr[largestValue]);
    maxHeapify(arr, numberCount, largestValue);
  }
}

void buildMaxHeap(int *arr, int numberCount) {
  for (int i = numberCount / 2 - 1; i >= 0; i--) {
    maxHeapify(arr, numberCount, i);
  }
}

void heapSort(int *arr, int numberCount) {
  buildMaxHeap(arr, numberCount);

  for (int i = numberCount - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    maxHeapify(arr, i, 0);
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ";";
  }
}

int main() {
  int numberCount = 0;
  cin >> numberCount;
  int *numberArray = new int[numberCount];

  for (int i = 0; i < numberCount; i++) {
    cin >> numberArray[i];
  }

  heapSort(numberArray, numberCount);

  printArray(numberArray, numberCount);

  delete[] numberArray;
  return 0;
}