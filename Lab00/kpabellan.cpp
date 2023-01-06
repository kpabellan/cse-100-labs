#include <iostream>
using namespace std;

int numAmount = 0;
int num = 0;
int minimumNum = 0;
int maximumNum = 0;

int main () {
    cin >> numAmount;

    for (int i = 0; i < numAmount; i++) {
        cin >> num;

        if (i == 0) {
            minimumNum = num;
            maximumNum = num;
        }

        if (num < minimumNum) {
            minimumNum = num;
        }

        if (num > maximumNum) {
            maximumNum = num;
        }
    }

    cout << maximumNum << ";" << minimumNum;

    return 0;
}