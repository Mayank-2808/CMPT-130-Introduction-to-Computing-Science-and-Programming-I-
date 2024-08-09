//
//  main.cpp
//  Assignment 1
//
//  Created by Mayank  on 2022-06-24.
//

#include <iostream>
#include <ctime>
using namespace std;

int roll()
{
    //Rolling a die is equivalent to generating a random number in the range [1, 6].
    //You are provided this function for rolling a die.
    //The function returns the point scored which is a random number in the range [1, 6].
    return rand() % 6 + 1;
}
int playComputer(const int computerScore)
{
    //You are required to define this function so that your program works exactly as described and prints exactly the same output.
    
    int turnScore = 0;
    
    while( turnScore < 20 )
    {
        int rollDie = roll();
        
        cout << "--->Rolled and got " << rollDie << " points." << endl;
        
        if (rollDie == 1)
        {
            turnScore = 0;
            cout << "Computer turn stopped with a score of 0 points." << endl;
            break;
        }
        
        turnScore += rollDie;
        
        cout << "        Turn score so far = " << turnScore << " and computer total score if turn stopped here = " << computerScore + turnScore << endl;
        
        if ( (computerScore + turnScore) >= 100 )
        {
            cout << "Computer stopping the turn because winning score is already reached." << endl;
            cout << "Computer turn stopped with a score of " << turnScore << " points." << endl;
            break;
        }
    }
    
    if ( turnScore >= 20 && (computerScore + turnScore) < 100 )
        cout << "Computer turn stopped with a score of " << turnScore << " points." << endl;
    
    return turnScore;
}

int playHuman(const int humanScore)
{
    //You are required to define this function so that your program works exactly as described and prints exactly the same output.
    
    int turnScore = 0;
    
    while ( humanScore < 100)
    {
        int rollDie = roll();
        
        cout << "--->Rolled and got " << rollDie << " points." << endl;
        
        if (rollDie == 1)
        {
            turnScore = 0;
            cout << "Human turn stopped with a score of 0 points." << endl;
            break;
        }
        
        turnScore += rollDie;
        
        cout << "        Turn score so far = " << turnScore << " and human total score if turn stopped here = " << humanScore + turnScore << endl;
        
        if ( (humanScore + turnScore) >= 100 )
        {
            cout << "Human stopping the turn because winning score is already reached." << endl;
            cout << "Human turn stopped with a score of " << turnScore << " points." << endl;
            break;
        }
        
        char input;
        
        cout << "Do you want to roll again or stop the turn? Enter R to roll again or S to stop the turn. ";
        cin >> input;
        
        if ( input == 'r' )
            continue;
        
        if ( input == 's' )
            break;
    }
    
    return turnScore;
}
int main()
{
    cout << "This program demonstrates a game popularly known as the Game of Pigs." << endl;
    cout << "There are two players in the game: a human and a computer." << endl;
    cout << "The game is played in turns where each player plays after the other player stops." << endl;
    cout << "At each turn a player rolls a die several times and sums the points scored to compute a turn score." << endl;
    cout << "The game is won by the player who first reaches a total score of 100 points or more." << endl;
    cout << "Any of the two players can start the game. In this program the computer will start the game." << endl;
    cout << endl;
    cout << "The computer plays with the following rule:" << endl;
    cout << "\tIt rolls a die repeatedly where at each roll a point between 1 and 6 is scored." << endl;
    cout << "\tIf the point scored is 1, then the computer turn ends with a score of zero points for the turn." << endl;
    cout << "\tIf the point scored is not 1, then it is added to the computer turn score and the computer rolls again." << endl;
    cout << "\tThe computer will stop its turn when its turn score reaches 20 points or more." << endl;
    cout << "Once the computer turn ends, then the human starts playing." << endl;
    cout << endl;
    cout << "The human plays with the following rule:" << endl;
    cout << "\tThe human rolls a die repeatedly where at each roll a point between 1 and 6 is scored." << endl;
    cout << "\tIf the point scored is 1, then the human turn ends with zero points for the turn." << endl;
    cout << "\tIf the point scored is not 1, then it is added to the human turn score." << endl;
    cout << "\tThe human is then asked to choose to either roll again or to stop the turn." << endl;
    cout << "\tIf the human chooses to roll again then the human rolls again otherwise the human turn ends." << endl;
    cout << "Once the human turn ends, then the computer starts playing." << endl;
    cout << endl;
    cout << "Any of the players will also stop its turn when the players wins the game." << endl;
    system("Pause");

    //Seed the random number generator with a fixed value so that every student working on
    //Microsoft Visual C++ 2010 Express gets the same random numbers and the same output.
    //You may change the seed value to any other non-negative integer or to time(0) in order to test your program rigorously.
    const unsigned int seedValue = 1;
    srand(seedValue);

    int humanTotalScore = 0, computerTotalScore = 0;
    while (true)
    {
        //Play Computer
        cout << endl << "Computer Playing... [Computer Total Score so far = " << computerTotalScore << "]" << endl;
        int computerTurnScore = playComputer(computerTotalScore);
        computerTotalScore += computerTurnScore;
        cout << "Computer total score so far = " << computerTotalScore << endl;
        if (computerTotalScore >= 100)
        {
            cout << "Computer Won the Game!" << endl;
            break;
        }
        system("Pause");

        //Play Human
        cout << endl << "Human Playing... [Human Total Score so far = " << humanTotalScore << "]" << endl;
        int humanTurnScore = playHuman(humanTotalScore);
        humanTotalScore += humanTurnScore;
        cout << "Human total score so far = " << humanTotalScore << endl;
        if (humanTotalScore >= 100)
        {
            cout << "Human Won the Game!" << endl;
            break;
        }
        system("Pause");
    }
    system("Pause");
    return 0;
}
