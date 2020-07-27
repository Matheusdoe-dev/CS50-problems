// reference asci table: http://www.asciitable.com
// includes
#include<stdio.h>
#include<cs50.h>
#include<math.h>

string getUserInput(void);
int countLetters(string userInput);
int countWords(string userInput);
int countSentences(string userInput);
void ColemanLiauIndex(float letters, float words, float sentences);

int main(void)
{
    // get user input and print grade level
    string userInput = getUserInput();
    int letters = countLetters(userInput);
    int words = countWords(userInput);
    int sentences = countSentences(userInput);
    ColemanLiauIndex(letters, words, sentences);
}

// get user input
string getUserInput(void)
{
    string userInput = get_string("Text: \n");
    return userInput;
}

//  letters count function
int countLetters(string userInput)
{
    // text letters count
    int lettersCount = 0;
    for (int i = 0; userInput[i] ; i++)
    {
        // filter letters than symbols
        if (
            userInput[i] == 32 ||
            userInput[i] == 33 ||
            userInput[i] == 34 ||
            userInput[i] == 35 ||
            userInput[i] == 36 ||
            userInput[i] == 37 ||
            userInput[i] == 38 ||
            userInput[i] == 39 ||
            userInput[i] == 40 ||
            userInput[i] == 41 ||
            userInput[i] == 42 ||
            userInput[i] == 43 ||
            userInput[i] == 44 ||
            userInput[i] == 45 ||
            userInput[i] == 46 ||
            userInput[i] == 47 ||
            userInput[i] == 48 ||
            userInput[i] == 49 ||
            userInput[i] == 50 ||
            userInput[i] == 51 ||
            userInput[i] == 52 ||
            userInput[i] == 53 ||
            userInput[i] == 54 ||
            userInput[i] == 55 ||
            userInput[i] == 56 ||
            userInput[i] == 57 ||
            userInput[i] == 58 ||
            userInput[i] == 59 ||
            userInput[i] == 60 ||
            userInput[i] == 61 ||
            userInput[i] == 62 ||
            userInput[i] == 63 ||
            userInput[i] == 64 ||
            userInput[i] == 91 ||
            userInput[i] == 92 ||
            userInput[i] == 93 ||
            userInput[i] == 94 ||
            userInput[i] == 95 ||
            userInput[i] == 96 ||
            userInput[i] == 123 ||
            userInput[i] == 124 ||
            userInput[i] == 125 ||
            userInput[i] == 126)
        {
            lettersCount += 0;
        }
        else
        {
            lettersCount++;
        }
    }
    return lettersCount;
}

//  words count function
int countWords(string userInput)
{
    int wordsCount;
    if (userInput[0] == 32)
    {
        wordsCount = 0;
    }
    else
    {
        wordsCount = 1;
    }
    for (int i = 0; userInput[i] ; i++)
    {
        if (userInput[i] == 32)
        {
            // if the next index is space (double spaces) will increment i to jump the next space.
            if (userInput[i + 1] == 32)
            {
                wordsCount++;
                i++;
            }
            else
            {
                wordsCount++;
            }
        }
    }
    return wordsCount;
}

// senteces count function
int countSentences(string userInput)
{
    int sentencesCount = 0;
    for (int i = 0; userInput[i]; i++)
    {
        // if the userInput index is a . , ? and !, sentences count will be incremented
        if (
            userInput[i] == 33 ||
            userInput[i] == 46 ||
            userInput[i] == 63)
        {
            sentencesCount++;
        }
    }
    return sentencesCount;
}

// Coleman-Liau index function
void ColemanLiauIndex(float letters, float words, float sentences)
{
    // letters per 100 words
    float L = letters * 100 / words;
    // sentences per 100 words
    float S = sentences * 100 / words;
    // Coleman-Liau algorithm
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    // Grade print
    // if index is bigger or equal to 16 the output will be "Grade 16+"
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    // if index less than 16 and bigger than one the output will be "Grade 'index'"
    else if (index < 16 && index > 1)
    {
        printf("Grade %i\n", index);
    }
    // if index is less or equal to 1 the output will be "Before Grade 1"
    else if (index <= 1)
    {
        printf("Before Grade 1\n");
    }
}

