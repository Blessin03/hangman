#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include "HangmanGame.h"

using namespace std;

int main()
{

    bool playAgain = true;

    ifstream wordFile("words.txt");
    if (!wordFile.is_open())
    {
        cout << "Cannot open file, there is an error" << endl;
        return -1;  // Check if the file "words.txt" can be opened, and return -1 if it cannot
    }


    // Create a vector to store words from the file
    string word;
    vector<string> words;
    while (getline(wordFile, word))
    {
        words.push_back(word);  // Read words from the file and add them to the vector
    }

    // Close the file after reading
    wordFile.close();


    // Seed the random number generator with the current time
    srand(time(NULL));

    while (playAgain)
    {
        int randomIndex = rand() % words.size();  // Generate a random index
        string password = words[randomIndex];  // Select a random word from the vector
        WordApp wordApp(password);  // Create a WordApp object with the selected word

        int k = amtGuesses(password);  // Determine the number of guesses allowed

        while (!wordApp.isWordGuessed() && k > 0)
        {
            cout << "Guess the word: ";
            wordApp.display();  // Display the current state of the word
            cout << "\nYou have " << k << " guesses left." << endl;

            char guess;
            cin >> guess;  // Read a character guess from the user

            wordApp.reveal(guess);  // Mark the character as visible in the word
            k--;  // Decrease the number of guesses remaining
        }

        if (wordApp.isWordGuessed())
        {
            cout << "Congratulations! You guessed the password correctly: " << password << endl << endl;
        }
        else
        {
            cout << "Sorry, you're out of guesses. The password was: " << password << endl << endl;
        }

        char choice;
        do
        {
            cout << "Press '#' to play again, \nPress '*' to end the game: ";
            cin >> choice;

            if (choice == '#')
            {
                playAgain = true;  // Play again
                break;
            }
            else if (choice == '*')
            {
                playAgain = false;  // End the game
                break;
            }
            else
            {
                cout << "Invalid ."<<endl;  // Handle invalid input
            }
        }
        while (true);
    }
return 0;

}
