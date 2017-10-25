#include <iostream>

const int SIZE = 8;
//----------------------DO NOT CHANGE ANYTHING ABOVE THIS LINE------------------

//   Write your function definitions here

//----------------------DO NOT CHANGE ANYTHING BELOW THIS LINE------------------
int main()
{
  int arr[SIZE]{};

  read_array(arr);
  int shifts = read_number_of_shifts();
  shift_array(arr, shifts);

  for (int i = 0; i < SIZE; ++i)
  {
    std::cout << arr[i] << ' ';
  }
  std::cout << std::endl;

  return 0;
}
