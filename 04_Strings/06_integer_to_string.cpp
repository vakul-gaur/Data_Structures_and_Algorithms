// =======================================================
//  Topic   : Strings - Integer to String Conversion
//  Concept : Multiple ways to convert numbers <-> strings
// =======================================================

#include <iostream>
#include <string>
#include <sstream>      // for stringstream
#include <algorithm>    // for reverse, sort
#include <cmath>        // for abs()
using namespace std;

// Manual int -> string (without library)
string intToStringManual(int n) {
    if (n == 0) return "0";

    bool negative = (n < 0);
    if (negative) n = -n;   // work with positive

    string result = "";
    while (n > 0) {
        char digit = '0' + (n % 10);   // extract last digit, convert to char
        result = digit + result;       // prepend
        n /= 10;
    }

    if (negative) result = "-" + result;
    return result;
}

// Manual string -> int (without library)
int stringToIntManual(const string& s) {
    int result = 0;
    int sign = 1;
    int i = 0;

    if (s[0] == '-') { sign = -1; i = 1; }

    for (; i < (int)s.length(); i++) {
        result = result * 10 + (s[i] - '0');   // s[i]-'0' converts char to digit
    }
    return sign * result;
}

int main() {

    // int -> string
    cout << "Integer to String:\n";

    int n = 12345;

    // Method 1: to_string() -> simplest
    string s1 = to_string(n);
    cout << "to_string(" << n << ")= " << s1 << endl;

    // Method 2: stringstream
    stringstream ss;
    ss << n;
    string s2 = ss.str();
    cout << "stringstream = " << s2 << endl;

    // Method 3: Manual
    string s3 = intToStringManual(n);
    cout << "Manual conversion = " << s3 << endl;

    // Negative numbers
    cout << "to_string(-42) = " << to_string(-42) << endl;
    cout << "Manual(-42) = " << intToStringManual(-42) << endl;

    // Float to string
    cout << "to_string(3.14159) = " << to_string(3.14159) << endl;

    // string -> int
    cout << "\nString to Integer:\n";

    string str1 = "9876";

    // Method 1: stoi (string to int)
    int i1 = stoi(str1);
    cout << "stoi(" << str1 << ") = " << i1 << endl;

    // Method 2: stoll (string to long long)
    long long l1 = stoll("123456789012345");
    cout << "stoll(\"123456789012345\") = " << l1 << endl;

    // Method 3: stringstream
    int i2;
    stringstream ss2("4321");
    ss2 >> i2;
    cout << "stringstream(4321) = " << i2 << endl;

    // Method 4: Manual
    int i3 = stringToIntManual("9876");
    cout << "Manual(9876) = " << i3 << endl;

    // Arithmetic on digit-characters
    cout << "Char <-> Digit:" << endl;
    char c = '7';
    int digit = c - '0';    // char to int: '7' - '0' = 7
    cout << "'" << c << "' - '0' = " << digit << endl;

    int d = 5;
    char ch = '0' + d;      // int to char: '0' + 5 = '5'
    cout << "'0' + " << d << " = " << ch << endl;

    return 0;
}

/*
 KEY POINTS:
  - to_string(n)        : easiest int -> string
  - stoi(s)             : easiest string -> int (throws if invalid)
  - stoll(s)            : string→long long (for large numbers)
  - stof/stod(s)        : string -> float/double
  - c - '0'             : char digit to int  ('7'→7)
  - '0' + d             : int to char digit  (7→'7')
  - stringstream        : flexible, can chain multiple conversions
*/