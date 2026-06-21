// =================================================================
//  Topic   : Vectors - Passing to Functions
//  Concept : Pass by value (copy), by reference, by const reference
// =================================================================

#include <iostream>
#include <vector>
using namespace std;

// Pass by VALUE: function gets a COPY, original unchanged
void passByValue(vector<int> v) {
    v[0] = 999;     // only modifies the copy
    cout << "Inside passByValue: v[0] = " << v[0] << endl;
}

// Pass by REFERENCE: function works on original
void passByRef(vector<int>& v) {
    v[0] = 999;     // modifies the original
    cout << "Inside passByRef: v[0] = " << v[0] << endl;
}

// Pass by CONST REFERENCE: read-only, no copy made (efficient)
void passByConstRef(const vector<int>& v) {
    // v[0] = 100;  // ERROR: cannot modify const
    int sum = 0;
    for (int x : v) sum += x;
    cout << "Sum (const ref) = " << sum << endl;
}

int main() {

    vector<int> v = {10, 20, 30, 40, 50};

    cout << "Original v[0] = " << v[0] << endl;

    passByValue(v);
    cout << "After passByValue, v[0] = " << v[0] << " (unchanged)\n\n";
  
    passByRef(v);
    cout << "After passByRef, v[0] = " << v[0] << " (changed)\n\n";

    passByConstRef(v);    // sum = 999 + 20 +30 +40 +50 = 1139

    return 0;
}

/*
 KEY POINTS:
  - Pass by value      -> safe but makes a full copy (expensive for large vectors)
  - Pass by reference  -> no copy, modifications affect original
  - Pass by const ref  -> no copy, read-only (BEST for input-only parameters)
*/