#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
using namespace std;
string exec(string cmd) {
    array<char, 128> buffer;
    string result;
    shared_ptr<FILE> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get()))
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    return result;
}
void test(int taskNumber, int numberOfTestCases) {
  exec("g++ -pedantic-errors -std=c++11 "+to_string(taskNumber)+".cpp -o"+to_string(taskNumber));
  for (int i=1;i<=numberOfTestCases;i++) {
    string filename = to_string(taskNumber)+"_"+to_string(i)+".txt";
    cout << taskNumber << "_" << i << ": ";
    exec("more input/"+filename+" | ./"+to_string(taskNumber)+" > yourOutput/"+filename);
    string result = exec("diff yourOutput/"+filename +" expectedOutput/"+filename);
    string result1;
    if (taskNumber==4) {
        filename = "text_" + to_string(i) + "_formatted.txt";
        result1 = exec("diff yourOutput/"+filename +" expectedOutput/"+filename);
    }
    if (result.size()==0 && result1.size()==0) cout << "PASSED" << endl;
    else cout << "FAILED" << endl;
    cout << result;
    cout << result1;
  }
  cout << endl;
}
int main() {
  exec("rm -f 1 2 3 4");
  int t;
  cout << "Task number (1 to 4, or 0 to run all): ";
  cin >> t;
  if (t==1||t==0) test(1, 5);
  if (t==2||t==0) test(2, 7);
  if (t==3||t==0) test(3, 7);
  if (t==4||t==0) test(4, 7);
}
