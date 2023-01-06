#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ";";
  }
  cout << endl;
}

void insertionSort(int arr[], int n) {
  if (n <= 1) {
    printArray(arr, n);
  }

  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
    printArray(arr, i + 1);
  }
}

int main() {
  int numberCount = 0;
  cin >> numberCount;
  int *numberArray = new int[numberCount];

  for (int i = 0; i < numberCount; i++) {
    cin >> numberArray[i];
  }

  insertionSort(numberArray, numberCount);

  delete[] numberArray;
  return 0;
}