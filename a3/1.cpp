#include <iostream>
#include <string>
using namespace std;

//----------------------DO NOT CHANGE ANYTHING ABOVE THIS LINE------------------

void alignNumbers(string &input1, string &input2) {
    while (input1.length() < input2.length()) {
        input1 = input1.insert(0, "0");
    }
    while (input1.length() > input2.length()) {
        input2 = input2.insert(0, "0");
    }
}

string computeAddition(char high, char low, bool &carry){
    int sum = 0;
    if(high == '1') ++sum;
    if(low == '1') ++sum;
    if(carry) ++sum;

    carry = sum >= 2;
    if(sum == 1 || sum == 3){
        return "1";
    }else{
        return "0";
    }
}

int main()
{
    string input1, input2;
    cin >> input1 >> input2;

    alignNumbers(input1, input2);

    int length = input1.length();
    string output = "";

    bool carry = false;
    for (int i = length - 1; i >= 0; --i) {
        output = output.insert(0, computeAddition(input1[i], input2[i], carry));
    }
    if(carry) output = output.insert(0, "1");
    cout << output << endl;
}
