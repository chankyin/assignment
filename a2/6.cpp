#include <iostream>

//----------------------DO NOT CHANGE ANYTHING ABOVE THIS LINE------------------

//   Write your function definitions here

void read_board(char *board, const int &squares){
  for(int i = 0; i < squares; ++i){
    std::cin >> board[i];
  }
}

char evaluate_board(char *board, const int &squares){
  const int lines[8][3] = {
          {0, 1, 2},
          {3, 4, 5},
          {6, 7, 8},
          {0, 3, 6},
          {1, 4, 7},
          {2, 5, 8},
          {0, 4, 8},
          {2, 4, 6}
  };
  for(int i = 0; i < 8; ++i){
    if(board[lines[i][0]] == board[lines[i][1]] && board[lines[i][0]] == board[lines[i][2]]){
      // assuming the empty squares have their correct value, e.g. '2' != '5'
      return board[lines[i][0]];
    }
  }
  for(int i = 0; i < 9; ++i){
    if(board[i] != 'x' && board[i] != 'o'){
      return 'u';
    }
  }
  return 'd';
}

//----------------------DO NOT CHANGE ANYTHING BELOW THIS LINE------------------

int main()
{
  const int SQUARES = 9;

  char board[SQUARES];

  read_board(board, SQUARES);
  char result = evaluate_board(board, SQUARES);

  switch (result)
  {
    case 'x':
    case 'o':
      std::cout << "Player " << result << " wins!!" << std::endl;
      break;
    case 'd':
      std::cout << "No winner. It's a draw!!" << std::endl;
      break;
    case 'u':
      std::cout << "No winner, but game is not over yet. Please continue." << std::endl;
      break;
    default:
      std::cout << "Sorry, I am broken." << std::endl;
  }
  
  return 0;
}
