#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString
{

private:
    string _Value;

public:
    enum enCaseToCount { Small, Capital, All };

    clsString()
    {

        _Value = "";
    }

    clsString(string Value)
    {

        _Value = Value;
    }


    void SetValue(string Value) {
        _Value = Value;
    }

    string GetValue() {
        return _Value;
    }

    __declspec(property(get = GetValue, put = SetValue)) string Value;

    /// <summary>
    /// inverts case of character
    /// </summary>
    /// <param name="C"></param>
    /// <returns></returns>
    static char InvertCharacter(char C)
    {
        return isupper(C) ? tolower(C) : toupper(C);
    }

    /// <summary>
    /// check if character is vowel
    /// </summary>
    /// <param name="C"></param>
    /// <returns></returns>
    static bool IsVowel(char C)
    {
        char C1 = tolower(C);
        return (C1 == 'a' || C1 == 'e' || C1 == 'i' || C1 == 'o' || C1 == 'u');
    }


    /// <summary>
    /// prints the first letter of each word in the string
    /// </summary>
    /// <param name="input"></param>
    static void PrintFirstLetterOfEachWord(string input)
    {
        bool isFirstLetter = true;

        cout << "First letters of this string:\n";

        for (short i = 0; i < input.length(); i++)
        {
            if (input[i] != ' ' && isFirstLetter)
                cout << input[i] << endl;

            isFirstLetter = input[i] == ' ' ? true : false;
        }
    }

    void PrintFirstLetterOfEachWord()
    {
        PrintFirstLetterOfEachWord(_Value);
    }


    /// <summary>
    /// upper cases first letters of each word in string
    /// </summary>
    /// <param name="input"></param>
    /// <returns> a new string with all first letters upper cased </returns>
    static string UpperFirstLetterOfEachWord(string input)
    {
        bool isFirstLetter = true;

        for (short i = 0; i < input.length(); i++)
        {
            if (input[i] != ' ' && isFirstLetter)
            {
                input[i] = toupper(input[i]);
            }

            isFirstLetter = input[i] == ' ' ? true : false;
        }
        return input;
    }

    void UpperFirstLetterOfEachWord()
    {
        _Value = UpperFirstLetterOfEachWord(_Value);
    }


    /// <summary>
    /// lower cases first letters of each word in string
    /// </summary>
    /// <param name="input"></param>
    /// <returns> a new string with all first letters lower cased </returns>
    static string LowerFirstLetterOfEachWord(string input)
    {
        bool isFirstLetter = true;

        for (short i = 0; i < input.length(); i++)
        {
            if (input[i] != ' ' && isFirstLetter)
            {
                input[i] = tolower(input[i]);
            }

            isFirstLetter = input[i] == ' ' ? true : false;
        }
        return input;
    }

    void LowerFirstLetterOfEachWord()
    {
        _Value = LowerFirstLetterOfEachWord(_Value);
    }


    /// <summary>
    /// Upper all the string chars
    /// </summary>
    /// <param name="input"></param>
    /// <returns> new string with all letters upper cased </returns>
    static string UpperAllString(string input)
    {
        for (short i = 0; i < input.length(); i++)
        {
            input[i] = toupper(input[i]);
        }
        return input;
    }

    void UpperAllString()
    {
        _Value = UpperAllString(_Value);
    }


    /// <summary>
    /// Lower all the string chars
    /// </summary>
    /// <param name="input"></param>
    /// <returns> new string with all letters uplowerper cased </returns>
    static string LowerAllString(string input)
    {
        for (short i = 0; i < input.length(); i++)
        {
            input[i] = tolower(input[i]);
        }
        return input;
    }

    void LowerAllString()
    {
        _Value = LowerAllString(_Value);
    }


    /// <summary>
    /// Invert the string's characters case
    /// </summary>
    /// <param name="input"></param>
    /// <returns> new string with all its characters cases inverted </returns>
    static string InvertStringCase(string input)
    {
        for (short i = 0; i < input.length(); i++)
        {
            input[i] = InvertCharacter(input[i]);
        }
        return input;
    }

    void InvertStringCase()
    {
        _Value = InvertStringCase(_Value);
    }


    /// <summary>
    /// counts letters
    /// </summary>
    /// <param name="S1"></param>
    /// <param name="Case"></param>
    /// <returns> number of letters in string </returns>
    static short CountLetters(string S1, enCaseToCount Case = enCaseToCount::All)
    {
        if (Case == enCaseToCount::All)
            return S1.length();

        short Count = 0;

        for (short i = 0; i < S1.length(); i++)
        {
            if (Case == enCaseToCount::Small && islower(S1[i]))
                Count++;
            else if (Case == enCaseToCount::Capital && isupper(S1[i]))
                Count++;
        }

        return Count;
    }

    short CountLetters(enCaseToCount Case = enCaseToCount::All)
    {
        return CountLetters(_Value, Case);
    }


    /// <summary>
    /// Counts small letters
    /// </summary>
    /// <param name="S1"></param>
    /// <returns> number of small letters in string </returns>
    static short CountSmallLetters(string S1)
    {
        short Count = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (islower(S1[i]))
                Count++;
        }
        return Count;
    }

    short CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }


    /// <summary>
    /// Counts capital letters
    /// </summary>
    /// <param name="S1"></param>
    /// <returns> number of capital letters in string </returns>
    static short CountCapitalLetters(string S1)
    {
        short Count = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (isupper(S1[i]))
                Count++;
        }
        return Count;
    }

    short CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }


    /// <summary>
    /// Count a specific letter existence in a string
    /// </summary>
    /// <param name="S1"></param>
    /// <param name="C"></param>
    /// <param name="IgnoreCase"></param>
    /// <returns> number of times a letter present in string </returns>
    static short CountLetterInString(string S1, char C, bool IgnoreCase = false)
    {
        short Count = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (!IgnoreCase)
            {
                if (S1[i] == C)
                    Count++;
            }
            else
            {
                if (tolower(S1[i]) == tolower(C))
                    Count++;
            }
        }
        return Count;
    }

    short CountLetterInString(char C, bool IgnoreCase = false)
    {
        return CountLetterInString(_Value, C, IgnoreCase);
    }


    /// <summary>
    /// Count Vowels
    /// </summary>
    /// <param name="S1"></param>
    /// <returns> number of vowel letters in string </returns>
    static short CountVowelsInString(string S1)
    {
        short Count = 0;

        for (short i = 0; i < S1.length(); i++)
            if (IsVowel(S1[i]))
                Count++;

        return Count;
    }

    short CountVowelsInString()
    {
        return CountVowelsInString(_Value);
    }

    /// <summary>
    /// prints vowels
    /// </summary>
    /// <param name="S1"></param>
    static void PrintVowels(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
            if (IsVowel(S1[i]))
                cout << S1[i] << "\t";
    }

    void PrintVowels()
    {
        PrintVowels(_Value);
    }


    /// <summary>
    /// Prints each word in string
    /// </summary>
    /// <param name="S1"></param>
    static void PrintEachWordInString(string S1)
    {
        string delim = " ";
        short position = 0;
        string sWord;

        while ((position = S1.find(delim)) != string::npos)
        {
            sWord = S1.substr(0, position);
            if (sWord != "")
                cout << sWord << endl;

            S1.erase(0, position + delim.length());
        }

        if (S1 != "")
            cout << S1 << endl;
    }

    void PrintEachWordInString()
    {
        PrintEachWordInString(_Value);
    }


    /// <summary>
    /// Counts number of words in a string
    /// </summary>
    /// <param name="S1"></param>
    /// <returns> Count of words </returns>
    static short CountWords(string S1)
    {

        string delim = " "; // delimiter  
        short Counter = 0;
        short pos = 0;
        string sWord; // define a string variable  

        // use find() function to get the position of the delimiters  
        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos); // store the word   
            if (sWord != "")
            {
                Counter++;
            }

            //erase() until positon and move to next word.
            S1.erase(0, pos + delim.length());
        }

        if (S1 != "")
        {
            Counter++; // it counts the last word of the string.
        }

        return Counter;

    }

    short CountWords()
    {
        return CountWords(_Value);
    };


    /// <summary>
    /// Splits string words into vector
    /// </summary>
    /// <param name="S1"></param>
    /// <param name="delim"></param>
    /// <returns> vector of string words </returns>
    static vector<string> Split(string S1, string delim)
    {
        vector<string> vTokens;
        short position = 0;
        string Word;

        while ((position = S1.find(delim)) != string::npos)
        {
            Word = S1.substr(0, position);

            //if (Word != "")
                vTokens.push_back(Word);

            S1 = S1.erase(0, position + delim.length());
        }

        if (S1 != "")
            vTokens.push_back(S1);

        return vTokens;
    }

    vector<string> Split(string delim)
    {
        return Split(_Value, delim);
    }


    /// <summary>
    /// Join vector of string into one string
    /// </summary>
    /// <param name="vTokens"></param>
    /// <param name="Separator"></param>
    /// <returns> new string with joined words of a vector </returns>
    static string JoinString(vector<string> vTokens, string Separator)
    {
        string S1 = "";

        for (string& Token : vTokens)
            S1 += Token + Separator;

        return S1.substr(0, S1.length() - Separator.length());
    }

    static string JoinString(string vTokens[], short length, string Separator)
    {
        string S1 = "";

        for (short i = 0; i < length; i++)
            S1 += vTokens[i] + Separator;

        return S1.substr(0, S1.length() - Separator.length());
    }


    /// <summary>
    /// Trim spaces from string
    /// </summary>
    /// <param name="S1"></param>
    /// <returns> new trimmed string </returns>
    static string TrimLeft(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
            if (S1[i] != ' ')
            {
                return S1.substr(i, S1.length() - i);
            }
        return "";
    }

    void TrimLeft()
    {
        _Value = TrimLeft(_Value);
    }

    static string TrimRight(string S1)
    {
        for (short i = S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(0, i + 1);
            }
        }

        return "";
    }

    void TrimRight()
    {
        _Value = TrimRight(_Value);
    }

    static string Trim(string S1)
    {
        return TrimLeft(TrimRight(S1));
    }

    void Trim()
    {
        _Value = Trim(_Value);
    }


    /// <summary>
    /// reverses a string by words
    /// </summary>
    /// <param name="S1"></param>
    /// <returns> new string with its words reversed </returns>
    static string ReverseStringWords(string S1)
    {
        vector<string> vTokens = Split(S1, " ");

        string S2 = "";

        vector<string>::iterator iter = vTokens.end(); // end of vector is capacity {size+1}

        while (iter != vTokens.begin())
        {
            iter--;
            S2 += *iter + " ";
        }

        return S2.substr(0, S2.length() - 1);
    }

    void ReverseStringWords()
    {
        _Value = ReverseStringWords(_Value);
    }


    /// <summary>
    /// Replaces a word inside a string
    /// </summary>
    /// <param name="S1"></param>
    /// <param name="stringToReplace"></param>
    /// <param name="sReplaceTo"></param>
    /// <returns> a new string with a specific word replaced </returns>
    static string ReplaceWord(string S1, string stringToReplace, string sReplaceTo)
    {
        short position = S1.find(stringToReplace); //intitially

        while (position != string::npos)
        {
            S1 = S1.replace(position, stringToReplace.length(), sReplaceTo);
            position = S1.find(stringToReplace);

        }
        return S1;
    }

    string ReplaceWord(string stringToReplace, string sReplaceTo)
    {
        return ReplaceWord(_Value, stringToReplace, sReplaceTo);
    }


    /// <summary>
    /// Remove Punctuations from a string
    /// </summary>
    /// <param name="S1"></param>
    /// <returns> a new string with no punctuations </returns>
    static string RemovePunctuations(string S1)
    {
        string S2 = "";
        for (short i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
                S2 += S1[i];
        }
        return S2;
    }

    void RemovePunctuations()
    {
        _Value = RemovePunctuations(_Value);
    }

};
