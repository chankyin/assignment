#include <iostream>

using namespace std;

int queryInteger(string);

int main() {
    int a = queryInteger("a");
    int b = queryInteger("b");
    int d1 = queryInteger("Divisor 1");
    int d2 = queryInteger("Divisor 2");
    cout << "M " << d1 << " " << d2 << endl;
    for(int i = a; i < b; ++i){
        cout << i << " " << (i % d1 == 0) << " " << (i % d2 == 0) << endl;
    }

}

int queryInteger(const string query) {
    cout << query << ": ";
    int i;
    cin >> i;
    return i;
}
