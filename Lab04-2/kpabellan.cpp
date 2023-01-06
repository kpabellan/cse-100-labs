#include <iostream>
using namespace std;

int partition(int *arr, int low, int high) {
  int x = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] <= x) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
  return i + 1;
}

int randomizedPartition(int arr[], int low, int high) {
  int i = low + rand() % (high - low + 1);
  swap(arr[i], arr[high]);
  return partition(arr, low, high);
}

void randomizedQuickSort(int *arr, int low, int high) {
  if (low < high) {
    int q = randomizedPartition(arr, low, high);
    randomizedQuickSort(arr, low, q - 1);
    randomizedQuickSort(arr, q + 1, high);
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

  randomizedQuickSort(numberArray, 0, numberCount - 1);

  printArray(numberArray, numberCount);

  delete[] numberArray;
  return 0;
}