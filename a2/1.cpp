#include <iostream>

const int SIZE = 8;
//----------------------DO NOT CHANGE ANYTHING ABOVE THIS LINE------------------

//   Write your function definitions here

void read_array(int *array){
  for(int i = 0; i < SIZE; ++i){
    std::cin >> array[i];
  }
}

int read_number_of_shifts(){
  int result;
  std::cin >> result;
  return result;
}

void shift_array(int *array, int shifts){
  shifts %= SIZE;
  if(shifts < 0){
    shifts += SIZE;
  }
  int clone[SIZE]{};
  for(int i = 0; i < SIZE; ++i){
    int offset = i - shifts;
    if(offset < 0){
      offset += SIZE;
    }
    clone[i] = array[offset];
  }
  for(int i = 0; i < SIZE; ++i){
    array[i] = clone[i];
  }
}

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
