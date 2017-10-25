#include <iostream>

//----------------------DO NOT CHANGE ANYTHING ABOVE THIS LINE------------------

//   Write your function definitions here

void read_word(char *word, int &arrayLength){
  std::cin >> arrayLength;
  for(int i = 0; i < arrayLength; ++i){
    std::cin >> word[i];
  }
}

char read_target(){
  char c;
  std::cin >> c;
  return c;
}

void delete_target(char *word, int &wordLength, const char &target){
  int matchCount = 0;
  bool matches[10] = {};
  for(int i = 0; i < wordLength; ++i){
    if(word[i] == target){
      matches[i] = true;
      ++matchCount;
    }
  }
  wordLength -= matchCount;
  int shiftSize = 0;
  for(int i = 0; i < wordLength; ++i){
    if(matches[i]){
      ++shiftSize;
    }
    word[i] = word[i + shiftSize];
    // assertion: i + shiftSize < o_wordLength (where o_wordLength is the original value of wordLength, i.e. wordLength + matchCount
    // proof: i and shiftSize both attain maximum in the last loop
    // i.e. i = wordLength - 1 and shiftSize = matchCount,
    // assuming matchCount = number of true values in matches.slice(0, o_wordLength)
  }
}

//----------------------DO NOT CHANGE ANYTHING BELOW THIS LINE------------------

int main()
{
  const int MAXLENGTH = 10;

  char word[MAXLENGTH]{};
  int word_length = 0;
  read_word(word, word_length);

  char target = read_target();

  delete_target(word, word_length, target);

  for (int i = 0; i < word_length; ++i)
  {
    std::cout << word[i];
  }
  std::cout << std::endl;

  return 0;
}
