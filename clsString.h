#pragma once

#include <iostream>
#include <vector>

using namespace std;

class clsString 
{

    private:
        string _Value;

    public:

        clsString()
        {
        this->_Value = "";
        }

        clsString(string Value)
        {
            this->_Value = Value;
        }

        void SetValue(string Value) 
        {
            this->_Value = Value;
        }

        string GetValue()
        {
            return this->_Value;
        }
    
        static int Length(string Text)
        {
            return Text.length();
        }

        int Length()
        {
            return this->_Value.length();
        };

        static short CountWords(string Text)
        {
            string Separator = " ";  
            int Counter = 0;
            int Position = 0;
            string sWord; // define a string variable  

            // use find() function to get the position of the delimiters  
            while ((Position = Text.find(Separator)) != std::string::npos)
            {
                sWord = Text.substr(0, Position); // store the word   
                if (sWord != "")
                {
                    Counter++;
                }

                //erase() until positon and move to next word.
                Text.erase(0, Position + Separator.length());
            }

            if (Text != "")
            {
                Counter++; // it counts the last word of the string.
            }

            return Counter;
        }

        int CountWords()
        {
            return clsString::CountWords(this->_Value);
        }

        static int FindElementPosition(string Text, char SearchFor)
        {
            int Counter = -1;

            for (short i = 0; i < Text.length(); i++)
            {
                Counter++;   
                if (Text[i] == SearchFor)
                    return Counter;
            }

            return -1;
        }

        static int FindElementPosition(string Text, string SearchFor)
        {
            int Counter = -1;
            char* Element = &SearchFor[0];

            for (short i = 0; i < Text.length(); i++)
            {
                Counter++;   
                if (Text[i] == *Element)
                    return Counter;
            }

            return -1;
        }

        int FindElementPosition(char SearchFor)
        {
            return clsString::FindElementPosition(this->_Value, SearchFor);
        }

        int FindElementPosition(string SearchFor)
        {
            return clsString::FindElementPosition(this->_Value, SearchFor);
        }

        static string UpperFirstLetterOfEachWord(string Text)
        {
            bool isFirstLetter = true;

            for (short i = 0; i < Text.length(); i++)
            {

                if (Text[i] != ' ' && isFirstLetter)
                {
                    Text[i] = toupper(Text[i]);
                }

                isFirstLetter = (Text[i] == ' ' ? true : false);
            }

            return Text;
        }

        void UpperFirstLetterOfEachWord()
        {
            // no need to return value , this function will directly update the object value  
            this->_Value = clsString::UpperFirstLetterOfEachWord(this->_Value);
        }

        static string LowerFirstLetterOfEachWord(string Text)
        {

            bool isFirstLetter = true;

            for (short i = 0; i < Text.length(); i++)
            {

                if (Text[i] != ' ' && isFirstLetter)
                {
                    Text[i] = tolower(Text[i]);

                }

                isFirstLetter = (Text[i] == ' ' ? true : false);
            }

            return Text;
        }

        void LowerFirstLetterOfEachWord()
        {    
            // no need to return value , this function will directly update the object value  
            this->_Value = clsString::LowerFirstLetterOfEachWord(this->_Value);
        }
        
        static string UpperAllString(string Text)
        {
            for (short i = 0; i < Text.length(); i++)
            {
                Text[i] = toupper(Text[i]);
            }
            return Text;
        }

        void UpperAllString()
        {
            this->_Value = clsString::UpperAllString(this->_Value);
        }

        static string LowerAllString(string Text)
        {
            for (short i = 0; i < Text.length(); i++)
            {
                Text[i] = tolower(Text[i]);
            }
            return Text;
        }

        void LowerAllString()
        {
            this->_Value = clsString::LowerAllString(this->_Value);
        }

        static char InvertLetterCase(char Character)
        {
            return isupper(Character) ? tolower(Character) : toupper(Character);
        }

        static string InvertAllLettersCase(string Text)
        {
            for (short i = 0; i < Text.length(); i++)
            {
                Text[i] = InvertLetterCase(Text[i]);
            }
            return Text;
        }

        void InvertAllLettersCase()
        {
            this->_Value = clsString::InvertAllLettersCase(this->_Value);
        }

        enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

        static short CountLetters(string Text, enWhatToCount WhatToCount = enWhatToCount::All)
        {
            if (WhatToCount == enWhatToCount::All)
            {
                return Text.length();
            }

            short Counter = 0;

            for (short i = 0; i < Text.length(); i++)
            {
                if (WhatToCount == enWhatToCount::CapitalLetters && isupper(Text[i]))
                    Counter++;

                if (WhatToCount == enWhatToCount::SmallLetters && islower(Text[i]))
                    Counter++;
            }

            return Counter;
        }
    
        static short CountCapitalLetters(string Text)
        {

            short Counter = 0;

            for (short i = 0; i < Text.length(); i++)
            {

                if (isupper(Text[i]))
                    Counter++;
            }

            return Counter;
        }

        short CountCapitalLetters()
        {
            return clsString::CountCapitalLetters(this->_Value);
        }

        static short CountSmallLetters(string Text)
        {

            short Counter = 0;

            for (short i = 0; i < Text.length(); i++)
            {
                if (islower(Text[i]))
                    Counter++;
            }

            return Counter;
        }

        short CountSmallLetters()
        {
            return clsString::CountSmallLetters(this->_Value);
        }
    
        static short CountSpecificLetter(string Text, char Letter, bool MatchCase = true)
        {
            short Counter = 0;

            for (short i = 0; i < Text.length(); i++)
            {
                if (MatchCase)
                    {
                        if (Text[i] == Letter)
                            Counter++;
                    }
                else
                    {
                        if (tolower(Text[i]) == tolower(Letter))
                            Counter++;
                    }
            }

            return Counter;
        }

        short CountSpecificLetter(char Letter, bool MatchCase = true)
        {
            return clsString::CountSpecificLetter(this->_Value, Letter, MatchCase);
        }

        static bool IsVowel(char Character)
        {
            Character = tolower(Character);

            return ((Character == 'a') || (Character == 'e') || (Character == 'i') || (Character == 'o') || (Character == 'u'));

        }

        static short CountVowels(string Text)
        {
            short Counter = 0;

            for (short i = 0; i < Text.length(); i++)
            {
                if (IsVowel(Text[i]))
                    Counter++;
            }

            return Counter;
        }

        short CountVowels()
        {
            return clsString::CountVowels(this->_Value);
        }

        static vector<string> Split(string Text, string Separator)
        {
            vector<string> vStrings;

            short Position = 0;
            string sWord; // define a string variable  

            // use find() function to get the position of the delimiters  
            while ((Position = Text.find(Separator)) != std::string::npos)
            {
                sWord = Text.substr(0, Position); // store the word   
                if (sWord != "")
                {
                    vStrings.push_back(sWord);
                }

                Text.erase(0, Position + Separator.length());  /* erase() until positon and move to next word. */
            }

            if (Text != "")
            {
                vStrings.push_back(Text); // it adds last word of the string.
            }

            return vStrings;

        }

        vector<string> Split(string Separator)
        {
            return clsString::Split(this->_Value, Separator);
        }

        static string TrimLeft(string Text)
        {
            for (short i = 0; i < Text.length(); i++)
            {
                if (Text[i] != ' ')
                {
                    return Text.substr(i, Text.length() - i);
                }
            }

            return "";
        }

        void TrimLeft()
        {
            this->_Value = clsString::TrimLeft(this->_Value);
        }

        static string TrimRight(string Text)
        {
            for (short i = Text.length() - 1; i >= 0; i--)
            {
                if (Text[i] != ' ')
                {
                    return Text.substr(0, i + 1);
                }
            }
            return "";
        }
    
        void TrimRight()
        {
            this->_Value = clsString::TrimRight(this->_Value);
        }

        static string Trim(string Text)
        {
            return (clsString::TrimLeft(clsString::TrimRight(Text)));
        }

        void Trim()
        {
            this->_Value = clsString::Trim(this->_Value);
        }

        static string JoinStrings(vector<string> vStrings, string Separator)
        {
            string Text = "";

            for (string& s : vStrings)
            {
                Text = Text + s + Separator;
            }

            return Text.substr(0, Text.length() - Separator.length());      
        }

        static string JoinStrings(string arrStrings[], short Length, string Separator)
        {
            string Text = "";

            for (short i = 0; i < Length; i++)
            {
                Text = Text + arrStrings[i] + Separator;
            }

            return Text.substr(0, Text.length() - Separator.length());
        }

        static string ReverseWordsInString(string S1)
        {
            vector<string> vStrings;
            string S2 = "";

            vStrings = clsString::Split(S1, " ");

            // declare iterator
            vector<string>::iterator iter = vStrings.end();

            while (iter != vStrings.begin())
            {

                --iter;

                S2 += *iter + " ";

            }

            S2 = S2.substr(0, S2.length() - 1); //remove last space.

            return S2;
        }

        void ReverseWordsInString()
        {
            this->_Value = clsString::ReverseWordsInString(this->_Value);
        }

        static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
        {
            vector<string> vStrings = clsString::Split(S1, " ");

            for (string& s : vStrings)
            {
                if (MatchCase)
                {
                    if (s == StringToReplace)
                    {
                        s = sRepalceTo;
                    }
                }
                else
                {
                    if (clsString::LowerAllString(s) == clsString::LowerAllString(StringToReplace))
                    {
                        s = sRepalceTo;
                    }
                }
            }

            return clsString::JoinStrings(vStrings, " ");
        }

        string ReplaceWord(string StringToReplace, string sRepalceTo)
        {
            return clsString::ReplaceWord(this->_Value, StringToReplace, sRepalceTo);
        }

        static string RemovePunctuations(string S1)
        {
            string S2 = "";

            for (short i = 0; i < S1.length(); i++)
            {
                if (!ispunct(S1[i]))
                {
                    S2 += S1[i];
                }
            }

            return S2;
        }

        void RemovePunctuations()
        {
            this->_Value = clsString::RemovePunctuations(this->_Value);
        }
};


