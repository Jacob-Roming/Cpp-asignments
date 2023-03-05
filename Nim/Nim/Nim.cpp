// Nim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <string>

void SimpleAI(int* toDraw, int* matches);
void SmartAI(int* toDraw, int* matches);

int main()
{
    std::cout << "Welcome to Nim!\n";

    int matches = 24;
    bool gameIsOngoing = true;
    bool playersTurn = true;
    bool advancedAI = false;
    int toDraw;
    std::string hello;
    //Random random = new Random();

    std::cout << "Do you want to enable the smart AI? (Y/N) (only input one character or everything will break)\n";
    char input = getchar();
    if (input == 'Y')
    {
        advancedAI = true;
    }

    while (gameIsOngoing) {
        std::string matchesGraphics = "";

        for (int i = 0; i < matches; i++) {
            matchesGraphics = matchesGraphics + '|';
        }

        

        matchesGraphics = matchesGraphics + " (" + std::to_string(matches) + ")";
        std::cout << matchesGraphics;
        if (playersTurn) {
            std::cout << "Choose a number of matches to draw: ";
            
            std::cin >> toDraw;
            
            if (toDraw > 3) { //in case the player tries to be a sneaky git
                std::cout << "You cant draw more than 3 matches per turn!\n";
                std::cout << "You draw 3 matches\n";
                toDraw = 3;
            }

            if (toDraw <= 0) {
                std::cout << "You cant draw less than 1 match!\n";
                std::cout << "You draw 1 match\n";
                toDraw = 1;
            }
        }
        else
        {
            if (advancedAI)
            {
                SmartAI(&toDraw, &matches);
            }
            else
            {
                SimpleAI(&toDraw, &matches);
            }
            char toDrawChar = (char)toDraw;
            std::string aiDraws = "The AI draws ";
            //aiDraws = aiDraws + toDrawChar;
            
            aiDraws += std::to_string(toDraw);
            aiDraws = aiDraws + " match";
            if (toDraw > 1)
            {
                aiDraws = aiDraws + "es\n";
            }
            else {
                aiDraws = aiDraws + "\n";
            }
            std::cout << aiDraws;
        }

        matches = matches - toDraw;

        if (matches <= 0) {
            gameIsOngoing = false;
        }
        else {
            playersTurn = !playersTurn;
        }
    }

    if (!playersTurn) {//The last turn was the AIs turn, they must have drawn the last match
        std::cout << "The AI draws the final match!\n";
        std::cout << "You won!\n";
    }
    else
    {
        std::cout << "You drew the final match!\n";
        std::cout << "The AI won\n";
    }


    

    
}

    void SimpleAI(int* toDraw, int* matches)
{
    *toDraw = rand() % (3 - 1 + 1) + 0;

    if (*matches > 4)
        return;


    if (*matches <= 4 && *matches != 1)//The AI tries to be smart and win in easy situations
    {
        toDraw = matches - 1;
        return;
    }

    *toDraw = 1;


}

    void SmartAI(int* toDraw, int* matches)
    {
        switch (*matches % 4)//The AI always wants the number of matches to be divisible by 4 on the players turn
        {
        case 1:
            *toDraw = 1;
            break;
        case 2:
            *toDraw = 2;
            break;
        case 3:
            *toDraw = 3;
            break;
        default:
            *toDraw = 1;
            //break;
        }

        if (*matches <= 4 && *matches != 1)//The AI tries to be smart and win in easy situations
        {
            *toDraw = *matches - 1;
        }
        else if (*matches == 1) //the AI as no choice but to do a loosing move
        {
            *toDraw = 1;
        }

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
