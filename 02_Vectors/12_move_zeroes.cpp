// ============================================================================
//  Topic   : Vectors - Move Zeroes
//  Problem : Move all 0s to end while maintaining relative order of non-zeros
//  Leetcode: 283
//  Time    : O(n)  |  Space: O(1)
// ============================================================================

#include <iostream>
#include <vector>
using namespace std;

void print(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

// Method 1: Two Pointer (Optimal)
void moveZeroes(vector<int>& v) {
    int j = 0;  // pointer for placing non-zero elements

    // Shift all non-zero elements to front (maintaining order)
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != 0) {
            v[j] = v[i];
            j++;
        }
    }

    // Phase 2: fill remaining positions with 0
    while (j < v.size()) {
        v[j] = 0;
        j++;
    }
}

// Method 2: Swap-based (also O(n) but more swaps)
void moveZeroesSwap(vector<int>& v) {
    int j = 0;    // position of next 0 to be replaced
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != 0) {
            swap(v[i], v[j]);   // swap non-zero to front
            j++;
        }
    }
}

// Method 3: Extra space
vector<int> moveZeroesExtra(vector<int>& v) {
    vector<int> result;
    int zeroCount = 0;
    for (int x : v) {
        if (x != 0) result.push_back(x);
        else zeroCount++;
    }
    while (zeroCount--) result.push_back(0);
    return result;
}

int main() {

    vector<int> v1 = {0, 1, 0, 3, 12};
    cout << "Original: ";
    print(v1);
    moveZeroes(v1);
    cout << "After moveZeroes: ";
    print(v1);

    vector<int> v2 = {0, 0, 1};
    cout << "\nOriginal: ";
    print(v2);
    moveZeroesSwap(v2);
    cout << "After moveZeroesSwap: ";
    print(v2);

    vector<int> v3 = {1, 0, 0, 0, 4, 0, 5};
    cout << "\nOriginal: ";
    print(v3);
    vector<int> result = moveZeroesExtra(v3);
    cout << "After moveZeroesExtra: ";
    print(result);

    return 0;
}