#include <iostream>
#include <vector>
#include "fns.hpp"


int main() {
  char p1;
  char p2;
  std::vector<char> grid = {'1','2','3','4','5','6','7','8','9'};
  bool game = true;
  great();

//brain of the game
gridPrint(grid);

while(game) {
  
  std::cout << "\nX : ";
  std::cin >> p1;
  for(int i = 0; i < grid.size(); i++) {
    if(grid[i]==p1) {
      grid[i] = 'X';
      
      gridPrint(grid);
      game = endGame(grid, game);
        
    } 
  }
  if(!game) break;
  std::cout << "\nO: ";
  std::cin >> p2;
  for(int i = 0; i < grid.size(); i++) {
    if(grid[i]==p2) {
      grid[i] = 'O';
      gridPrint(grid);
      game = endGame(grid, game);

    } 
  }

}


std::cout<<"\n";

} //end of the main

