#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

//----------------------DO NOT CHANGE ANYTHING ABOVE THIS LINE------------------

struct ResizableStringArray {
    string *array = new string[0];
    int size = 0;

    string get(int i) {
        return array[i];
    }

    void push(const string str) {
        string *newArray = new string[size + 1];
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
        newArray[size++] = str;
        if(size > 0) delete[] array;
        array = newArray;
    }

    string shift() {
        string first = array[0];
        string *newArray = new string[size - 1];
        for (int i = 1; i < size; ++i) {
            newArray[i - 1] = array[i];
        }
        if(size > 0) delete[] array;
        array = newArray;
        --size;
        return first;
    }

    string justify(int M) {
        if (size == 0) {
            return "";
        }
        if (size == 1) {
            return array[0];
        }
        for (int i = 0; i < size; ++i) {
            M -= array[i].length();
        }
        int basicSeparation = M / (size - 1);
        int remainder = M % (size - 1);
        string output = "";
        for (int i = 0; i + 1 < size; ++i) {
            output += array[i];
            for (int j = 0; j < basicSeparation; ++j) {
                output += ' ';
            }
            if ((remainder--) > 0) {
                output += ' ';
            }
        }
        return output + array[size - 1];
    }

    void free() {
        if(size > 0) delete[] array;
    }
};

void initRuler(ofstream &os, int M);

int printJustified(ofstream &os, ResizableStringArray &words, const int M);

int main()
{
    string inputFile;
    cin >> inputFile;
    string outputFile = inputFile.substr(inputFile.rfind('/') + 1);
    outputFile = "yourOutput/" + outputFile.insert(outputFile.rfind('.'), "_formatted");

    int M;
    cin >> M;

    ofstream os(outputFile);
    ResizableStringArray words;

    ifstream is(inputFile);
    string word;
    while (is >> word) {
        words.push(word);
    }
    is.close();

    initRuler(os, M);

    int linesWritten = printJustified(os, words, M);

    words.free();
    os.close();

    cout << linesWritten << " formatted lines written to " << outputFile << endl;
}

void initRuler(ofstream &os, int M) {
    for (int i = 0; i < M; ++i) {
        os << (i % 10);
    }
    os << endl;
}

int printJustified(ofstream &os, ResizableStringArray &words, const int M) {
    int linesWritten = 0;
    while (words.size > 0) {
        ResizableStringArray thisLine;
        thisLine.push(words.shift());
        int totalLength = thisLine.get(0).length();
        string word;
        while (words.size > 0 && totalLength + words.get(0).length() < M) { // < not <= because of an extra space
            word = words.shift();
            thisLine.push(word);
            totalLength += word.length() + 1;
        }
        if (words.size == 0) {
            for (int i = 0; i < thisLine.size; ++i) {
                if (i != 0) {
                    os << ' ';
                }
                os << thisLine.get(i);
            }
            os << endl;
        } else {
            os << thisLine.justify(M) << endl;
        }
        ++linesWritten;
        thisLine.free();
    }
    return linesWritten;
}
