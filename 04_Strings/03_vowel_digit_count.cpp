// ===================================================================
//  Topic   : Strings - isVowel Check, Count Digits/Vowels/Consonants
//  Concept : Character classification using conditions and ASCII
// ===================================================================

#include <iostream>
#include <string>
#include <cctype>    // toupper, tolower, isalpha, isdigit
using namespace std;

// Function to check if a character is a vowel
bool isVowel(char c) {
    c = tolower(c);     // normalize to lowercase before checking
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Function to check if a character is a consonant
bool isConsonant(char c) {
    return isalpha(c) && !isVowel(c);  // is a letter ans not a vowel
}

int main() {

    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    int spaces = 0;
    int special = 0;

    for (char c : s) {
        if(isVowel(c)) vowels++;
        else if(isConsonant(c)) consonants++;
        else if(isdigit(c)) digits++;
        else if(isspace(c)) spaces++;
        else special++;    // punctuation, symbols, etc.
    }

    cout << "\nString: " << s << endl;
    cout << "Length: " << s.length() << endl;
    cout << "Vowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Digits: " << digits << endl;
    cout << "Spaces: " << spaces << endl;
    cout << "Special: " << special << endl;

    return 0;
}

/*
 KEY POINTS:
  - Always normalize to lower/upper case before vowel check
  - isalpha(c): true for letters (a-z, A-Z)
  - isdigit(c): true for digits (0-9)
  - isspace(c): true for spaces, tabs, newlines
  - isupper(c) / islower(c) : case check
  - Consonant = letter and not vowel
*/
