#include <iostream>

using namespace std;

bool isPrime(int);

int main() {
    int i;
    cin >> i;
    ++i; // workaround requirement "larger than the value", not "larger than or equal to"
    for (int found = 0; found < 10; ++i) {
        if (isPrime(i)) {
            cout << i << endl;
            ++found;
        }
    }
}

bool isPrime(int i) {
    for (int f = 2; f * f <= i; ++f) {
        if (i % f == 0) {
            return false;
        }
    }
    return true;
}