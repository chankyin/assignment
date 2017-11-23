#include <iostream>
#include <string>
using namespace std;

//----------------------DO NOT CHANGE ANYTHING ABOVE THIS LINE------------------

int areAnagram(string a, string b) {
    const int POSSIBLE_CHARS = 256;
    int charsetA[POSSIBLE_CHARS] = {};
    int charsetB[POSSIBLE_CHARS] = {};

    int length = b.length();
    int offset = 0;
    for (int read = 0; read < length; ++offset) {
        if (a[offset] != ' ') {
            ++charsetA[a[offset]];
            ++read;
        }
    }
    for (int i = 0; i < b.length(); ++i) {
        ++charsetB[b[i]];
    }

    for (int i = 0; i < POSSIBLE_CHARS; ++i) {
        if (charsetA[i] != charsetB[i]) {
            return -1;
        }
    }
    return offset - 1;
}

void findAnagram(const string haystack, const string needle) {
    for (int i = 0; i <= haystack.length() - needle.length(); ++i) {
        if(haystack[i] != ' '){
            int result = areAnagram(haystack.substr(i), needle);
            if (result != -1) {
                cout << i << ' ' << (i + result) << endl;
            }
        }
    }
}

int main()
{
    string s, t;
    getline(cin, s);
    getline(cin, t);

    if(s.length() > t.length()){
        findAnagram(s, t);
    }
}
