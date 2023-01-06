#include <iostream>

using namespace std;

void extendedBottomUpCutRod(int prices[], int n) {
  int *r = new int[n + 1];
  int *s = new int[n + 1];

  r[0] = 0;

  for (int i = 1; i < n; i++) {
    int max = -1;
    for (int j = 1; j <= i; j++) {
      if (max < prices[j] + r[i - j]) {
        max = prices[j] + r[i - j];
        s[i] = j;
      }
    }
    r[i] = max;
  }

  n--;

  cout << r[n] << endl;

  while (n > 0) {
    cout << s[n] << " ";
    n = n - s[n];
  }

  cout << "-1" << endl;

  delete[] r;
  delete[] s;
}

int main() {
  int n = 0;

  cin >> n;

  n++;

  int *prices = new int[n];

  for (int i = 1; i < n; i++) {
    cin >> prices[i];
  }

  extendedBottomUpCutRod(prices, n);

  delete[] prices;

  return 0;
}