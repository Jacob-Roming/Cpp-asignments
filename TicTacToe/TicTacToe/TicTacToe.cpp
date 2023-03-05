// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int ContainsNumberOfElement(char input[], char comparator);

int GetInput(std::string message);

void DrawPlaySpace(char playSpace[][3]);

bool CheckGameWon(char playSpace[][3]);

bool CheckSoftLock(char playSpace[][3]);

int main()
{
    bool playerOnesTurn = true;
    bool gameWon;
    bool advancedAI = false;
    int fieldSize = 3;
    int inARow = fieldSize; //how many markers in a row is the goal of the game?, if its not the same as fieldSize a bunch of weird edge cases pop up

    char playSpace[3][3]; //= new char[fieldSize][];

    for (int i = 0; i < fieldSize; i++)
    {
        //playSpace[i] = new char[fieldSize];
        //might not be needed but it calms the nerves to initialize variables before using them 
        for (int j = 0; j < fieldSize; j++)
        {
            playSpace[i][j] = ' ';
        }
    }

    std::cout << "Welcome to tic-tac-toe\n";
    std::cout << "Ported from C# so the code is kinda janky\nNo AI player though...\n";
    DrawPlaySpace(playSpace);
    std::cout << "Player 1 starts and plays as X\n";

    do {
        if (playerOnesTurn)
        {
            bool inputIsValid = false;
            int y = 0;
            int x = 0;
            std::cout << "Player one (X) make your move!\n";
            while (!inputIsValid)
            {
                y = GetInput("Input the horizontal row you want to select (1-3)");

                x = GetInput("Input the vertical column you want to select (1-3)");

                if (playSpace[y][x] == ' ')
                {
                    inputIsValid = true;
                }
                else
                {
                    std::cout << "That spot is already taken, please choose another spot!\n";
                }
            }

            playSpace[y][x] = 'X';
            DrawPlaySpace(playSpace);
            playerOnesTurn = false;
        }
        else
        {
            bool inputIsValid = false;
            int y = 0;
            int x = 0;
            std::cout << "Player two (O) make your move!\n";
            while (!inputIsValid)
            {
                y = GetInput("Input the horizontal row you want to select (1-3)");

                x = GetInput("Input the vertical column you want to select (1-3)");

                if (playSpace[y][x] == ' ')
                {
                    inputIsValid = true;
                }
                else
                {
                    std::cout << "That spot is already taken, please choose another spot!\n";
                }
            }

            playSpace[y][x] = 'O';
            DrawPlaySpace(playSpace);
            playerOnesTurn = false;
            playerOnesTurn = true;
        }

        gameWon = CheckGameWon(playSpace);
    } while (!gameWon && !CheckSoftLock(playSpace));

    if (CheckSoftLock(playSpace) && !gameWon) {
        std::cout << "All spots are taken, nobody won\n";
    }
    else if (playerOnesTurn == false) {
        std::cout << "Player one won\n";
    }
    else {
        std::cout << "Player two won\n";
    }

    

    



    

    

    

    

    

    
}

void DrawPlaySpace(char playSpace[][3])
{
    for (int i = 0; i < 3; i++) {
        //This .ToString is required once to prevent a syntax error, why?
        //Microsoft pls fix
        std::string row = "";
        for (int j = 0; j < 3; j++)
        {
            row += playSpace[i][j];
            if (j != 3 - 1)
            {
                row += "|";
            }
        }

        std::cout << row;
        std::cout << "\n";

        if (i != 3 - 1) {
            //Writing to the console a lot like this makes us a second class citizen at the hardware scheduler
            //There is probably a better way to do this that avoids that
            std::cout << "-";
            for (int j = 0; j < 3 - 1; j++)
            {
                std::cout << "--";
            }
            std::cout << "\n";
        }
    }

}

int GetInput(std::string message)
{
    bool validInput = false;
    int output = 0;
    char input;
          
    std::cout << message;

    std::cin >> output;
        
 
    output--;
    if (output > 2)
    {
        output = 2;
    }
    else if (output < 0)
    {
        output = 0;
    }

    return output;
}

bool CheckGameWon(char playSpace[][3]) {
    //Checks if any player has gotten as many markers in a row as InARow states
    char toCheck[3];
    //check vertical columns
    for (int i = 0; i < 3; i++) {
        if (ContainsNumberOfElement(playSpace[i], 'O') == 3 || ContainsNumberOfElement(playSpace[i], 'X') == 3) {
            return true;
        }
    }
    //check horizontal rows
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            toCheck[j] = playSpace[i][j];
        }
        if (ContainsNumberOfElement(toCheck,'O') == 3 || ContainsNumberOfElement(toCheck,'X') == 3) {
            return true;
        }
    }

    //Check diagonal 
    for (int i = 0; i < 3; i++)
    {
        toCheck[i] = playSpace[i][i];
    }
    if (ContainsNumberOfElement(toCheck, 'O') == 3 || ContainsNumberOfElement(toCheck, 'X') == 3) {
        //Checking that they're all actually in a row will be a massive pain

        return true;
    }
    for (int i = 0; i < 3; i++)
    {
        toCheck[i] = playSpace[i][(3 - 1) - 2];
    }
    if (ContainsNumberOfElement(toCheck, 'O') == 3 || ContainsNumberOfElement(toCheck, 'X') == 3) {
        return true;
    }
    
    return false;
}

int ContainsNumberOfElement(char input[], char comparator) {
    int amountFound = 0;
    for (int i = 0; i < sizeof(input); i++) {
        if (input[i] == comparator) {
            amountFound++;
        }
    }
    return amountFound;
}

bool CheckSoftLock(char playSpace[][3])
{
    //This function checks if there are any empty positions left on the board
    //If there isn't the game is soft-locked, and the function returns true
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (playSpace[i][j] == ' ')
            {
                return false;
            }
        }
    }

    return false;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
