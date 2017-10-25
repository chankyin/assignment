#include <iostream>

//----------------------DO NOT CHANGE ANYTHING ABOVE THIS LINE------------------

//   Write your function definitions here

void read_lists(int *arr1, int *arr2, int *arr3, const int &size){
  for(int i = 0; i < size; ++i){
    std::cin >> arr1[i];
  }
  for(int i = 0; i < size; ++i){
    std::cin >> arr2[i];
  }
  for(int i = 0; i < size; ++i){
    std::cin >> arr3[i];
  }
}

void display_common_integers(const int *arr1, const int *arr2, const int *arr3, const int &size){
  bool displayed = false;
  int accumulator = 0;
  for(int i = 0; i < size; ++i){
    if(i + 1 < size && arr1[i] == arr1[i + 1]){
      ++accumulator;
    } else{ // continue not allowed :(
      int occ2 = 0, occ3 = 0;
      for(int j = 0; j < size; ++j){
        if(arr2[j] == arr1[i]){
          ++occ2;
        }
        if(arr3[j] == arr1[i]){
          ++occ3;
        }
      }
        for(int j = 0; j < accumulator + 1 && j < occ2 && j < occ3; ++j){ // TODO: may change this to ||
          std::cout << arr1[i] << std::endl;
          displayed = true;
        }
      accumulator = 0; // reset counter if arr1[i + 1] != arr1[i]
    }
  }
  if(!displayed){
    std::cout << "None" << std::endl;
  }
}

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
