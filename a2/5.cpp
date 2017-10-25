#include <iostream>

const int MAXDIM = 10;

//----------------------DO NOT CHANGE ANYTHING ABOVE THIS LINE------------------

//   Write your function definitions here

void read_matrix(char matrix[MAXDIM][MAXDIM], int &dim){
  std::cin >> dim;
  for(int y = 0; y < dim; ++y){
    for(int x = 0; x < dim; ++x){
      std::cin >> matrix[x][y];
    }
  }
}

void display_with_fill(char matrix[MAXDIM][MAXDIM], const int &dim){
  bool crossColumns[MAXDIM] = {}, crossRows[MAXDIM] = {};
  for(int x = 0; x < dim; ++x){
    for(int y = 0; y < dim; ++y){
      if(matrix[x][y] == 'x'){
        crossColumns[x] = true;
        crossRows[y] = true;
      }
    }
  }
  for(int y = 0; y < dim; ++y){
    for(int x = 0; x < dim; ++x){
      std::cout << (crossColumns[x] || crossRows[y] ? 'x' : matrix[x][y]) << ' ';
    }
    std::cout << std::endl;
  }
}

//----------------------DO NOT CHANGE ANYTHING BELOW THIS LINE------------------

int main()
{
  char matrix[MAXDIM][MAXDIM]{};
  int dim = 0;

  read_matrix(matrix, dim);
  display_with_fill(matrix, dim);

  return 0;
}
