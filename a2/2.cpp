#include <iostream>

//----------------------DO NOT CHANGE ANYTHING ABOVE THIS LINE------------------

//   Write your function definitions here

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
