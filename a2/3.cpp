#include <iostream>

//----------------------DO NOT CHANGE ANYTHING ABOVE THIS LINE------------------

//   Write your function definitions here

//----------------------DO NOT CHANGE ANYTHING BELOW THIS LINE------------------

int main()
{
  const int SIZE = 8;
  int arr1[SIZE]{};
  int arr2[SIZE]{};
  int arr3[SIZE]{};

  read_lists(arr1, arr2, arr3, SIZE);
  display_common_integers(arr1, arr2, arr3, SIZE);

  return 0;
}
