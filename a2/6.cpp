#include <iostream>

//----------------------DO NOT CHANGE ANYTHING ABOVE THIS LINE------------------

//   Write your function definitions here

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
