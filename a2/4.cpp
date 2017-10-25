#include <iostream>

const int MAXDIM = 10;

//----------------------DO NOT CHANGE ANYTHING ABOVE THIS LINE------------------

//   Write your function definitions here

void read_matrix(int matrix[MAXDIM][MAXDIM], int &dim){
  std::cin >> dim;
  for(int y = 0; y < dim; ++y){
    for(int x = 0; x < dim; ++x){
      std::cin >> matrix[x][y];
    }
  }
}

void display_inner_cw_rotated(int matrix[MAXDIM][MAXDIM], const int &dim){
  for(int y = 1; y < dim - 1; ++y){
    for(int x = 1; x < dim - 1; ++x){
      std::cout << matrix[y][dim - 1 - x] << " ";
    }
    std::cout << std::endl;
  }
}

//----------------------DO NOT CHANGE ANYTHING BELOW THIS LINE------------------

int main()
{
  int matrix[MAXDIM][MAXDIM]{};
  int dim = 0;

  read_matrix(matrix, dim);
  display_inner_cw_rotated(matrix, dim);

  return 0;
}
