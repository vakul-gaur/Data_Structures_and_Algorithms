// ======================================================================
//  Topic   : Check Left & Right Neighbours
//  Problem : Count characters whose available neighbours are different.
//            - First character  -> check only right neighbour
//            - Last character   -> check only left neighbour
//            - Middle character -> both left & right must differ
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;

    int count = 0;

    for (int i = 0; i < s.length(); i++) {
        // First character
        if (i == 0) {
            cout << s[i] << " -> Right: ";
            if (s[i] != s[i + 1]) {
                cout << "Different --> (Count++)";
                count++;
            } else {
                cout << "Same";
            }
        }

        // Last character
        else if (i == s.length() - 1) {
            cout << s[i] << " -> Left: ";
            if (s[i] != s[i - 1]) {
                cout << "Different --> (Count++)";
                count++;
            } else {
                cout << "Same";
            }
        }

        // Middle characters
        else {
            cout << s[i] << " -> Left: ";

            if (s[i] != s[i - 1])
                cout << "Different";
            else
                cout << "Same";

            cout << " | Right: ";

            if (s[i] != s[i + 1])
                cout << "Different";
            else
                cout << "Same";

            if (s[i] != s[i - 1] && s[i] != s[i + 1]) {
                cout << " -->(Count++)";
                count++;
            }
        }

        cout << endl;
    }

    cout << "\nFinal Count = " << count << endl;

    return 0;
}

/*
 KEY POINTS:
  - First character has only a right neighbour.
  - Last character has only a left neighbour.
  - Middle characters have both left and right neighbours.
  - Increment the count:
      * If the first character differs from its right neighbour.
      * If the last character differs from its left neighbour.
      * If a middle character differs from both its left and right neighbours.
*/