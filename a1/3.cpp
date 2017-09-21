#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        int input;
        cin >> input;
        int product = 1;
        for (int j = 2; j <= input; ++j) {
            product *= j;
        }
        sum += product;
    }
    cout << sum << endl;
}
