#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int max;
    if (m > n) {
        max = m;
    } else {
        max = n;
    }
    for (int i = 0; i < max; ++i) {
        if (i < m) {
            cout << 'y';
        }
        if (i < n) {
            cout << 'z';
        }
    }
    cout << endl;
}
