// C++ Code Challenges, LinkedIn Learning

// Challenge #13: Conway's Game of Life
// Write an application that runs Conway's Game of Life, the best-known cellular automaton.
// Do this for a 10x10 grid.
// The grid wraps around in all directions, like the Pac-Man world.

// Rules:
// Any live cell with fewer than two live neighbors dies, as if by underpopulation.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by overpopulation.
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

#define N 10
#define M 10

const int coordShift[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

int wrappingChecker(int coord){
    if (coord < 0)
    {
        return 9;
    }
    if (coord > 9)
    {
        return 0;
    }
}

// Update the grid per epoch
void update(char (&game)[N][M]){
    // Store current state of the game
    char oldGame[N][M];
    memcpy(oldGame, game, M*N*sizeof(char));

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            int liveNeighbours = 0;
            for (size_t k = 0; k < 8; k++)
            {
                // Check for wrapping
                int newR = wrappingChecker(i + coordShift[k][0]);
                int newC = wrappingChecker(j + coordShift[k][1]);
                
                liveNeighbours += oldGame[newR][newC] == 'X';
            }

            // Determine whether the cell lives to the next generation or dies
            if (oldGame[i][j] == 'X')
            {
                if (liveNeighbours < 2)
                {
                    // Cell dies due to underpopulation
                    game[i][j] = '-';
                    continue;
                }

                if (liveNeighbours == 2 || liveNeighbours == 3)
                {
                    // Cell lives until the next generation
                    continue;
                }
                
                if (liveNeighbours > 3)
                {
                    // Cell dies due to overpopulation
                    game[i][j] = '-';
                    continue;
                }
            } else {
                if (liveNeighbours == 3)
                {
                    // Cell becomes alive due to reproduction
                    game[i][j] = 'X';
                    continue;
                }
            }
        }
    }
    
}

// Conway's Game of Life, main()
// Summary: This application is a simulation of Conway's game of life.
int main(){    
    // The game, initialized with a glider and a blinker.
    char game[N][M];  
    std::memset(game,'-',N*M); // Initialize game with dashes.

    // A glider     // - - - - - - - - - -
    game[1][1]='X'; // - X - - - - - - - -
    game[2][2]='X'; // - - X - - - - - - -
    game[3][0]='X'; // X X X - - - - - - -
    game[3][1]='X';
    game[3][2]='X';

    // A blinker    // - - - - - - - - - -
    game[3][6]='X'; // - - - - - - - - - -
    game[3][7]='X'; // - - - - - - - - - -
    game[3][8]='X'; // - - - - - - X X X -
    
    int generation = 0;
    std::string go_on;
    do{
        std::cout << "Generation #" << generation++ << "\n";
        for (auto &str : game){
            for (auto &ch : str)
                std::cout << " " << ch;
            std::cout << "\n";
        }
        std::cout << "\n";

        update(game);
        
        std::cout << "Press Enter for the next generation, or type \"Exit\": " << std::flush;
        std::getline(std::cin,go_on);
        std::transform(go_on.begin(), go_on.end(), go_on.begin(), toupper);
        std::cout << "\n" << std::flush;
    }while(go_on.compare("EXIT")!=0);
    
    return 0;
}
