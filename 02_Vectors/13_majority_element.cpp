// =======================================================
//  Topic   : Vectors - Majority Element
//  Problem : Find element appearing more than n/2 times
//  Leetcode: 169
//  Time    : O(n log n)  |  Space: O(1)
// =======================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    // Sort - middle element is majority O(n log n)`
    // If majority exists and appears > n/2 times, it must occupy the middle

    vector<int> v1 = {1, 3, 2, 3, 3, 2, 3};
    sort(v1.begin(), v1.end());
    cout << "Majority element: " << v1[v1.size() / 2] << endl;
    
    return 0;
}