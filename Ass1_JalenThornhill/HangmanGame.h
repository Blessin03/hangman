#ifndef HANGMANGAME_H_INCLUDED
#define HANGMANGAME_H_INCLUDED

#include <vector>
#include <string>

using namespace std;

class Letter
{
public:
    char value;
    bool visible;
    Letter(char val);
};

class WordApp
{
private:
    vector<Letter> theword;

public:
    WordApp(string word);
    void reveal(char character);
    void display();
    bool isWordGuessed();
};

int amtGuesses(string str);

#endif // HANGMANGAME_H_INCLUDED
