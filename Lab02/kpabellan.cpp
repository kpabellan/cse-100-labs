#include <iostream>
using namespace std;

void merge(int *arr, int left, int mid, int right) {
  int i = 0;
  int j = 0;
  int k = left;

  int leftArraySize = mid - left + 1;
  int rightArraySize = right - mid;

  int *leftArray = new int[leftArraySize];
  int *rightArray = new int[rightArraySize];

  for (int i = 0; i < leftArraySize; i++) {
    leftArray[i] = arr[left + i];
  }

  for (int j = 0; j < rightArraySize; j++) {
    rightArray[j] = arr[mid + 1 + j];
  }

  while (i < leftArraySize && j < rightArraySize) {
    if (leftArray[i] <= rightArray[j]) {
      arr[k] = leftArray[i];
      i++;
    } else {
      arr[k] = rightArray[j];
      j++;
    }
    k++;
  }

  while (i < leftArraySize) {
    arr[k] = leftArray[i];
    i++;
    k++;
  }

  while (j < rightArraySize) {
    arr[k] = rightArray[j];
    j++;
    k++;
  }

  delete[] leftArray;
  delete[] rightArray;
}

void mergeSort(int *arr, int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
}

int main() {
  int numberCount = 0;
  cin >> numberCount;
  int *numberArray = new int[numberCount];

  for (int i = 0; i < numberCount; i++) {
    cin >> numberArray[i];
  }

  mergeSort(numberArray, 0, numberCount - 1);

  for (int i = 0; i < numberCount; i++) {
    cout << numberArray[i] << ";";
  }

  delete[] numberArray;

  return 0;
}