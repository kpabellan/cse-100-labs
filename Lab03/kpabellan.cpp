#include <iostream>
using namespace std;

int findMaxCrossArr(int *arr, int low, int mid, int high) {
  int leftSum = -2147483647;
  int rightSum = -2147483647;
  int maxLeft = 0;
  int maxRight = 0;
  int sum = 0;

  for (int i = mid; i >= low; i--) {
    sum += arr[i];
    if (sum > leftSum) {
      leftSum = sum;
      maxLeft = i;
    }
  }

  sum = 0;

  for (int j = mid + 1; j <= high; j++) {
    sum += arr[j];
    if (sum > rightSum) {
      rightSum = sum;
      maxRight = j;
    }
  }

  return (leftSum + rightSum);
}

int findMaxSubArr(int *arr, int low, int high) {
  if (high == low) {
    return (arr[low]);
  } else {
    int mid = (low + high) / 2;

    int maxSumLeft = findMaxSubArr(arr, low, mid);
    int maxSumRight = findMaxSubArr(arr, mid + 1, high);
    int maxSumCross = findMaxCrossArr(arr, low, mid, high);

    if (maxSumLeft >= maxSumRight && maxSumLeft >= maxSumCross) {
      return (maxSumLeft);
    } else if (maxSumRight >= maxSumLeft && maxSumRight >= maxSumCross) {
      return (maxSumRight);
    } else {
      return (maxSumCross);
    }
  }
}

int main() {
  int numberCount = 0;
  cin >> numberCount;
  int *numberArray = new int[numberCount];

  for (int i = 0; i < numberCount; i++) {
    cin >> numberArray[i];
  }

  cout << findMaxSubArr(numberArray, 0, numberCount - 1);

  delete[] numberArray;

  return 0;
}