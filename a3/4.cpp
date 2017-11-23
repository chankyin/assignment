#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

//----------------------DO NOT CHANGE ANYTHING ABOVE THIS LINE------------------

void initRuler(ofstream os, int M) {
    for (int i = 0; i < M; ++i) {
        os << (i % 10);
    }
    os << endl;
}



int main()
{
    string inputFile;
    cin >> inputFile;
    string outputFile = inputFile.substr(inputFile.rfind('/') + 1);
    outputFile = outputFile.insert(outputFile.rfind('.'), "_formatted");

    int M;
    cin >> M;

    ofstream os(outputFile);
    initRuler(os, M);

    

    os.close();

    cout << inputFile << ", " << outputFile;
}
