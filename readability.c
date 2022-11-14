#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Task: Building a program that calculates the approximate school grade level needed to comprehend some text

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void) 
{
    string text = get_string("Text: ");

    int letters_in_text = count_letters(text); // counts the length of text without spaces and special chars
    int words_in_text = count_words(text);
    int sentences_in_text = count_sentences(text);

    /*
    printf("%i letters\n", letters_in_text);
    printf("%i words\n", words_in_text);
    printf("%i sentences\n", sentences_in_text);
    */

    // applying Coleman-Liau index:
    float L = (float) letters_in_text / words_in_text * 100;
    float S = (float) sentences_in_text / words_in_text * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade = (int) round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
    printf("Grade: %i\n", grade);
    }
}



int count_letters(string text) 
{
    int letter_count = 0;

    for (int i = 0, n = strlen(text); i < n; i++) // counts the length of text incl. spaces and special chars
    {
        char letter = text[i];

        if (isalpha(letter)) 
        {
            letter_count++;
        }
    }

    return letter_count;
}



int count_words(string text)
{
    int word_count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char letter = text[i];

        if (isspace(letter)) // check for whitespace
        {
            word_count++;
        }
         if (letter == ',' || letter == '.' || letter == '!' || letter == '?') // check for special char
        {
            word_count++;
            i++; // skip next char bc of whitespace
        }

    }

    return word_count;
}



int count_sentences(string text)
{
    int sentence_count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char letter = text[i];

        if (letter == '.' || letter == '!' || letter == '?') // check for sentence's end
        {
            sentence_count++;
        }
    }

    return sentence_count;
} 