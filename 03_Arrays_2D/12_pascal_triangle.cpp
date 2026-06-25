// ====================================================
//  Topic   : 2D Arrays - Pascal's Triangle
//  Problem : Generate Pascal's triangle with n rows
//  Leetcode: 118, 119
//  Time    : O(n²)  |  Space: O(n²)
// ====================================================

#include <iostream>
#include <vector>
using namespace std;

// Generate full Pascal's Triangle (n rows)
// Each element = sum of top-left + top-right elements
vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> v;

    for (int i = 0; i < n; i++) {    // Build each row one by one
        vector<int> a(i+1);    // Row i has (i+1) elements
        v.push_back(a);    // Add row to triangle
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                v[i][j]=1;    // First and last element of each row = 1
            } else {
                v[i][j]=(v[i-1][j-1] + v[i-1][j]);    // Fill interior elements
            }
        }
    }
    return v;
}

//  Print Pascal Triangle in a centered format
void printTriangle(const vector<vector<int>>& v) {

    int n = v.size();

    for (int i = 0; i < n; i++) {
        // Print leading spaces for alignment
        for (int s = 0; s < n - i - 1; s++) {
            cout << "  ";
        }

        // Print all elements of current row
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << "   ";
        }
        cout << "\n";
    }
}

//  Get nth row of Pascal's Triangle (O(n) space)
//  Formula : row[j] = row[j-1] * (n-j+1) / j
vector<int> getNthRow(int n) {
    // Initialize row with all 1s
    vector<int> row(n + 1, 1);

    // Compute values using formula
    for (int j = 1; j < n; j++) {
        row[j] = row[j - 1] * (n - j + 1) / j;
    }

    return row;
}

//  Get a specific element C(n, r)
//  Use optimized multiplicative formula
long long getElement(int n, int r) {

    // Use symmetry property: C(n,r) = C(n,n-r)
    if (r > n - r) {
        r = n - r;
    }

    long long ans = 1;

    // Compute using iterative multiplication
    for (int i = 0; i < r; i++) {
        ans = ans * (n - i) / (i + 1);
    }

    return ans;
}

int main() {

    int n = 6;
    vector<vector<int>> v = pascalTriangle(n);    // Generate Pascal's Triangle with n rows

    cout << "Pascal Triangle\n\n";

    // Print formatted triangle
    printTriangle(v);

    cout << "\nRow-wise output:\n";
    // Print each row separately
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    // Get specific row
    int target = 5;
    vector<int> row = getNthRow(target);

    cout << "\nRow " << target << ": ";

    for (int i = 0; i < row.size(); i++) {
        cout << row[i] << " ";
    }
    cout << "\n";

    // Get specific elements
    cout << "\nC(5,2) = " << getElement(5, 2) << "\n";
    cout << "C(6,3) = " << getElement(6, 3) << "\n";

    return 0;
}

/*
 KEY POINTS:
  - First and last element of every row = 1
  - Interior: triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]
  - Row i has (i+1) elements (0-indexed)
  - Elements = binomial coefficients: C(n, k) = n! / (k! * (n-k)!)
  - Nth row only: use formula row[j] = row[j-1] * (n-j+1) / j -> O(n) space
*/