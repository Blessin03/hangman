#include "HangmanGame.h"
#include <iostream>

// Implementation of the Letter class
Letter::Letter(char val) : value(val), visible(false) {}

// Implementation of the WordApp class constructor
WordApp::WordApp(std::string word)
{
    int numRevealed = 0;

    // Iterate through each character in the input word
    for (char c : word)
    {
        Letter letter(c);  // Create a Letter object for each character

        // Check if fewer than 2 characters have been revealed
        if (numRevealed < 2)
        {
            letter.visible = true; // Set the character as visible
            numRevealed++; // Increment the count of revealed characters
        }

        theword.push_back(letter);  // Add the Letter to the word vector
    }
}

// Implementation of the reveal method in WordApp
void WordApp::reveal(char character)
{
    for (Letter &l : theword)
    {
        if (l.value == character)
        {
            l.visible = true;  // Set the character as visible if it matches the input
        }
    }
}

// Implementation of the display method in WordApp
void WordApp::display()
{
    for (Letter l : theword)
    {
        char v = (l.visible) ? l.value : '-';  // Display the character or a dash if not visible
        std::cout << v << " ";
    }
}

// Implementation of the isWordGuessed method in WordApp
bool WordApp::isWordGuessed()
{
    for (Letter l : theword)
    {
        if (!l.visible)
            return false;  // If any letter is not visible, the word is not guessed
    }
    return true;  // All letters are visible, so the word is guessed
}

// Implementation of the amtGuesses function
int amtGuesses(std::string str)
{
    int amtLetters = 0;
    for (char c : str)
    {
        if (isalpha(c))
        {
            amtLetters++;
        }
    }
    return amtLetters + 4;
}
