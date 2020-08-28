
/*
QN

This tutorial is about strings in pig Latin form. The following are the rules for doing so:
• Program prompts user to input a string
− Then outputs the string in the pig Latin form
• The rules for converting a string into pig Latin form are as follows:
− If the string begins with a vowel, add the string "-way" at the end of the string
• Example: the pig Latin form of "eye" is "eye-way"
− If the string does not begin with a vowel, first add "-" at the end of the string
• Then move the first character of the string to the end of the string until the first
character of the string becomes a vowel
• Next, add the string "ay" at the end
• Example: pig Latin form of "There" is "ere-Thay"
− Strings such as "by" contain no vowels
• The letter 'y' can be considered a vowel
• For this program the vowels are a, e, i, o, u, y, A, E, I, O, U, and Y
− Strings such as "1234" contain no vowels
• The pig Latin form of a string that has no vowels in it is the string followed by
the string "-way"
• Example: pig Latin form of "1234" is "1234-way"
• If str denotes a string:
− Check the first character, str[0], of str
− If it is a vowel, add "-way" at the end of str
− If it is not a vowel:
• First add "-" at the end of the string
• Remove the first character of str from str and put it at end of str
• Now the second character of str becomes the first character of str
− This process is repeated until either
• The first character of str is a vowel 
• All characters of str are processed, in which case str does not contain any
vowels



*/


















#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// function that checks if the string starts with a,e,i or u
bool startWithVowelString(string string_name)
{
    char first_character = string_name[0];
    /*using ASCII American Starndard Code of Infomation Interchange
    to detemine if the string starts with a vowel
    */
    bool found_at_first_index = !true;
    // voews  are [a,e,i,o,u,A,E,I,O,U,Y,y] in this program
    int vowel_ascii[12] = {97, 101, 105, 111, 117, 65, 69, 73, 48, 85, 89, 121};
    for (size_t i = 0; i < sizeof(vowel_ascii) / sizeof(vowel_ascii[0]);)
    {
        if (first_character == vowel_ascii[i])
        {
            // NAGATE found_at_first_index and jump outside the loop
            found_at_first_index = !found_at_first_index;
            break;
        }
        i++;
    }
    return found_at_first_index;
}

// THIS FUNCTION IS RESPONSIBLE FOR HANDLING WORDS THAT DOESN'T END WITH VOWELS BASED ON THE FOLLOWING CONDITION
/*
If the string does not begin with a vowel, first add "-" at the end of the string
• Then move the first character of the string to the end of the string until the first
character of the string becomes a vowel
• Next, add the string "ay" at the end
• Example: pig Latin form of "There" is "ere-Thay"
*/

string nonStartVoew(string str)
{
    //  apped a - to the string that we are going to return
    string returned_string = str.append("-");
    if (startWithVowelString(returned_string))
    {
        //  of cause this condition won't stand true
        return returned_string;
    }
    else
    {
        // loop for each character in a string ad look for a voew at the begining
        for (int i = 0; i < str.length(); i++)
        {
            // grab the first character at index 0
            char first_character = returned_string.at(-1 + 1);
            /*
            reove the first character of the returned string and then append the first character to the end of a string
            ? erasing the first character using erase() func that takes index and number of chars to be erased

            */
            returned_string = returned_string.erase(0, 1) + first_character;
            // call our function that checks if the string starts with a voew
            if (startWithVowelString(returned_string))
            {
                //  if that is the case append ay to the returned string and exit the loop JOB DONE!!!
                returned_string += "ay";
                goto finish;
            }
        }
    }
finish:
    return returned_string;
}
// A function that checks if string is made up of numbers onl

bool isANumberString(string str)
{
    bool solution = false;
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (int(str[i]) >= 48 && str[i] <= 57)
        {
            count++;
        }
    }
    //  check if the string contains numbers in in otherwise return false
    /*
    if the string consist of numbers only then return true otherwise
    return true if the count becomes 3 less than the length of the string. Why because a string like "123abje" can be converted (because it have some vowels in it) through the process of the nonStartVoew() method and stand but string like 125bbbb can not be converted hence

    */
    if (count >= str.length() - 3)
    {
        solution = !false;
    }
    return solution;
}

// this function is responsible for all the logic of converting a single string that will be passed to it to a latin string
string pigLatinConvetor(string string_)
{
    if (startWithVowelString(string_))
    {
        return string_.append("-way");
    }
    else
    {
        // IF A STRING CONSIST OF NUMBERS THEN NO VOEWS WILL BE IN IT HENCE WE MUST CHECK FOR THOSE STRINGS HERE
        if (isANumberString(string_))
        {
            // do the clever way of calling that function
            return string_.append("-way");
        }
        else
        {
            // CALL OUR FUNCTION nonStartVoew() TO PERFOM THE TASK FOR US
            return nonStartVoew(string_);
        }
    }
}

// THIS FUNCTION WILL BREAK THE LONG STRING INTO AN ARRAY WHITH WORD SURPARETED BY SPACES
string stringBreaker(string long_string)
{

    // FIND THE NUMBER OF SPACES IN THE WORD
    int spaces = 0;
    for (size_t i = 0; i < long_string.size(); i++)
    {
        if (isspace(int(long_string[i])))
        {
            spaces += 1;
        }
        else
        {
            spaces = spaces;
        }
    }
    //  the string that helps indentify a new word
    string delimeter = " ";
    //  we don't know how many words the string will contain so our array will have the following declaration
    string words_array[spaces + 1];
    for (size_t j = 0; j < spaces + 1; j++)
    {
        // return the index of the delimeter
        int delimeter_position = long_string.find(delimeter);
        // each word starts starts from index 0 till it reaches the delimeter
        string word = long_string.substr(0, delimeter_position);
        // APPEND A WORD TO OUR ARRAY
        words_array[j] = word;
        // ERASE THE STRING  FROM THE THE BEGINING TO THE DELIMETER " "
        string temporary_token = long_string.erase(0, delimeter_position + delimeter.size());
    }

    /* update the array strings based on the condition of
        − If the string begins with a vowel, add the string "-way" at the end of the string
         − If the string does not begin with a vowel, first add "-" at the end of the string
    */

    int k = 0;
    for (string i : words_array)
    {
        //    convert the string in the array
        words_array[k] = pigLatinConvetor(i);

        k++;
    }
    // RETURN THE WHOLE STRING NOW
    string final_string("");
    int a = 0;
    for (string i : words_array)
    {
        // for the first loop i dont want to append the space
        if (a == 0)
        {
            final_string += i;
        }
        else
        {
            final_string = final_string + " " + i;
        }
        a++;
    }

    return final_string;
}

int main()
{
    // string arr =  stringBreaker("THIA is a test string okay");

    string string_input;
    cout << "ENTER A STRING THAT YOU WANT TO OUTPUT IN PIG LATIN FORM" << endl;

    // GET THE WHOLE LINE STRING FROM THE USER;
    getline(cin, string_input);

    cout<<endl;
    cout<<"THE STRING ("<<string_input<<") TO PIG LATIN FORM IS:"<<endl;

    cout << stringBreaker(string_input) << endl;

    return 0;
}

}*/
