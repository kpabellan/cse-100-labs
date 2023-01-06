#include <iostream>
#include <vector>
using namespace std;

void printMatrix(vector<vector<int>> matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < 10; j++) {
      cout << matrix[i][j] << ";";
    }
    cout << endl;
  }
}

void radixSort(vector<vector<int>> matrix, int iteration) {
  vector<int> *output;
  output = new vector<int>[matrix.size()];
  
  int count[10] = {0};

  for (int i = 0; i < matrix.size(); i++) {
    count[(matrix[i][iteration]) % 10]++;
  }

  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (int i = matrix.size() - 1; i >= 0; i--) {
    output[count[(matrix[i][iteration]) % 10] - 1] = matrix[i];
    count[(matrix[i][iteration]) % 10]--;
  }

  for (int i = 0; i < matrix.size(); i++) {
    matrix[i] = output[i];
  }

  if (iteration >= 0) {
    radixSort(matrix, iteration - 1);
  } else {
    printMatrix(matrix);
  }
}

int main() {
  int vectorCount = 0;
  cin >> vectorCount;
  vector<vector<int>> matrix;

  for (int i = 0; i < vectorCount; i++) {
    vector<int> row;
    for (int j = 0; j < 10; j++) {
      int value;
      cin >> value;
      row.push_back(value);
    }
    matrix.push_back(row);
  }

  radixSort(matrix, 10);

  return 0;
}