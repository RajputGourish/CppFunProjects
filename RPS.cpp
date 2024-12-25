#include <iostream>
#include <cstdlib>
using namespace std;
int generateRandom(int n)
{
    srand(time(NULL));
    return rand() % n;
}
int Greater(char char1, char char2)
{

    if (char1 == char2)
        return -1;
    else if ((char1 == 'r') && (char2 == 'p'))
        return 1;
    else if ((char1 == 'p') && (char2 == 'r'))
        return 0;
    else if ((char1 == 's') && (char2 == 'r'))
        return 1;
    else if ((char1 == 'r') && (char2 == 's'))
        return 0;
    else if ((char1 == 'p') && (char2 == 's'))
        return 1;
    else if ((char1 == 's') && (char2 == 'p'))
        return 0;
    return 5;
}
int main()
{
    int temp, playerScore = 0, compScore = 0;
    char playerChar, compChar;

    char dict[] = {'r', 'p', 's'};

    for (int i = 0; i < 3; i++)
    {

        cout << "Choose 1 for Rock, 2 for Paper and 3 for Scissor" << endl;
        cin >> temp;
        playerChar = dict[temp - 1];
        cout << "Player Choice = " << playerChar << endl;
        cout << "\nComputer_Turns!!" << endl;
        temp = generateRandom(3) + 1;
        compChar = dict[temp - 1];
        cout << "Computer_Choice = " << compChar << endl;

        if (Greater(playerChar, compChar) == -1)
        {
            playerScore += 1;
            compScore += 1;
            cout << "\nIts a Draw!!\nPlayer Score = " << playerScore << "\nComputer Score = " << compScore << endl;
        }
        else if (Greater(playerChar, compChar) == 0)
        {
            playerScore += 1;
            cout << "\nPlayer got it!!..\nPlayer Score = " << playerScore << "\nComputer Score = " << compScore << endl;
        }
        else
        {
            compScore += 1;
            cout << "\nComputer got it!!..\nPlayer Score = " << playerScore << "\nComputer Score = " << compScore << endl;
        }
        cout << endl;
    }
    if (playerScore > compScore)
    {
        cout << "\n....Result....\nPlayer win the game.....\nPlayer Score = " << playerScore << endl;
    }
    else if (compScore > playerScore)
    {
        cout << "\n....Result....\nComputer win the game.....\nComputer Score = " << compScore << endl;
    }
    else
    {
        cout << "\n....Result....\nDraw.......\nPlayer Score = " << playerScore << "\nComputer Score = " << compScore << endl;
    }

    return 0;
}