// ================================================================
//  Topic   : Strings - Indexing of Characters
//  Concept : Accessing, modifying, and iterating over characters
// ================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {

    string str = "Hello World";

    cout << "String: " << str << endl;
    cout << "Length: " << str.length() << endl;

    // Access by index (0-based)
    cout << "str[0]= " << str[0] << endl;             // 'H'
    cout << "str[6]= " << str[6] << endl;             // 'W'
    cout << "str.at(4)= " << str.at(4) << endl;       // 'o' (bounds-checked)
    cout << "str.front()= " << str.front()<< endl;    // first char 'H'
    cout << "str.back()= " << str.back() << endl;     // last char 'd'

    // Last character: str[str.length() - 1]
    int n = str.length();
    cout << "Last char = " << str[n - 1] << endl;

    // Modify a character
    str[0] = 'h';   // change 'H' -> 'h'
    cout << "\nAfter str[0]='h': " << str << endl;

    // Iterate with index
    cout << "Characters with index: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "str[" << i << "] = " << str[i] << endl;
    }

    // Range-based for loop 
    cout << "\nRange-based for: ";
    for(int i=0; i<n; i++) cout << str[i];
    cout << "\n";

    // Range-based with reference (can modify)
    for (char& c : str) c = toupper(c);    // convert all to uppercase
    cout << "After toupper: " << str << "\n";

    // Pointer-based traversal
    cout << "Pointer traversal: ";
    for (char* ptr = &str[0]; *ptr != '\0'; ptr++) {
        cout << *ptr;
    }

    // ASCII values
    cout << "\n\nASCII values:\n";
    string t = "Az09";
    for (char c : t) {
        cout << c << " = " << (int)c << "\n";
    }
    // 'A'=65, 'Z'=90, 'a'=97, 'z'=122, '0'=48, '9'=57

    return 0;
}

/*
 KEY POINTS:
  - Indexing is 0-based, last char at s[s.length() - 1]
  - s[i]: no bounds check (fast but unsafe)
  - s.at(i): bounds check, throws std::out_of_range if invalid
  - s.front(), s.back(): first and last character
  - char& c in range-based for -> can modify; char c -> read-only copy
  - 'a' - 'A' = 32  -> adding 32 converts upper to lower
*/
