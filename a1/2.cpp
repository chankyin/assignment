#include <iostream>

using namespace std;

int main() {
    int input;
    cin >> input;
    if (input < 18) {
        cout << "junior" << endl;
    } else if (input < 65) {
        cout << "adult" << endl;
    } else {
        cout << "senior" << endl;
    }
}
