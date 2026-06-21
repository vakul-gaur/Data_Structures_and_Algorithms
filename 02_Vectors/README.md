# 📦 Vectors — Complete Revision Guide

> A **vector** is a dynamic array in C++ that can grow and shrink at runtime. It is part of the STL and lives in `#include <vector>`.

---

## 📁 Files in This Folder

|                 File                  |                   Topic                     |
|---------------------------------------|---------------------------------------------|
| `01_basics_of_vectors.cpp`            | Declaration, access, push_back, 2D vectors  |
| `02_passing_vectors_to_functions.cpp` | By value, by reference, const reference     |
| `03_two_sum.cpp`                      | Two Sum — brute, two pointer                |
| `04_reverse_of_array.cpp`             | Reverse array in-place — two pointer, STL   |
| `05_reverse_part_of_array.cpp`        | Reverse only a subarray [l..r]              |
| `06_rotate_array.cpp`                 | Rotate left/right by k — reverse trick      |
| `07_sort_0s_and_1s.cpp`               | Sort binary array — count, two pointer      |
| `08_dutch_flag_algo.cpp`              | Sort 0s, 1s, 2s in one pass — 3 pointer     |
| `09_merge_two_sorted_arrays.cpp`      | Merge sorted arrays — two pointer, in-place |
| `10_next_permutation.cpp`             | Lexicographically next arrangement          |
| `11_trapping_rain_water.cpp`          | Water trapped between bars — two pointer    |
| `12_move_zeroes.cpp`                  | Move all 0s to end, keep order              |
| `13_majority_element.cpp`             | Element appearing > n/2 times               |
| `14_missing_number.cpp`               | Find missing in [0..n] — sum formula, XOR   |
| `15_kadanes_algorithm.cpp`            | Maximum subarray sum — Kadane's O(n)        |

---

## 🧠 Concept 1 — Vector Basics

```cpp
vector<int> v;    // empty
vector<int> v(5, 0);    // 5 zeros
vector<int> v = {1, 2, 3};    // init list

v.push_back(x);    // add to end     O(1)
v.pop_back();      // remove last    O(1)
v.size();          // element count  O(1)
v.empty();         // true if empty  O(1)
v.front(); v.back();   // first / last element
v[i]; v.at(i);    // access (at throws on bad index)
```

---

## 🧠 Concept 2 — Passing Vectors

```cpp
void function(vector<int> v)              // by VALUE    — copy, expensive
void function(vector<int>& v)             // by REF      — modifies original
void function(const vector<int>& v)       // by CONST REF — read-only, no copy (BEST for input)
```

---

## 🔧 Algorithm Quick Reference

### Two Sum
```cpp
for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        if (nums[i] + nums[j] == target) {
            return {i, j};
        }
    }
    
    }
```

### Reverse Array — Two Pointer O(n)
```cpp
int l = 0, r = n - 1;
while (l < r) { swap(v[l++], v[r--]); }
```

### Rotate Right by k — Reverse Trick O(n)
```cpp
k %= n;
reverse(v, 0, n-1);    // reverse all
reverse(v, 0, k-1);    // reverse first k
reverse(v, k, n-1);    // reverse rest
```

### Dutch National Flag — 3 Pointer O(n)
```cpp
int lo = 0, mid = 0, hi = n - 1;
while (mid <= hi) {
    if (v[mid] == 0) { swap(v[lo++], v[mid++]); }
    else if (v[mid] == 1) { mid++; }
    else { swap(v[mid], v[hi--]); }
}
```

### Merge Two Sorted Arrays — Two Pointer O(m+n)
```cpp
int i = 0, j = 0;
while (i < m && j < n) {
    if (a[i] <= b[j]) result.push_back(a[i++]);
    else result.push_back(b[j++]);
}
// then copy remaining
```

### Next Permutation O(n)
```cpp
// 1. Find rightmost pivot where v[i] < v[i+1]
// 2. Find rightmost element > v[pivot] and swap
// 3. Reverse suffix after pivot
```

### Trapping Rain Water — Two Pointer O(n)
```cpp
// Water at i = min(maxLeft, maxRight) - height[i]
while (left < right) {
    if (h[left] < h[right]) { water += leftMax - h[left]; left++; }
    else { water += rightMax - h[right]; right--; }
}
```

### Move Zeroes O(n)
```cpp
int j = 0;
for (int i = 0; i < n; i++) if (v[i] != 0) v[j++] = v[i];
while (j < n) v[j++] = 0;
```

### Majority Element — O(n log n) O(1)
```cpp
// Sort - middle element is majority O(n log n)`
// If majority exists and appears > n/2 times, it must occupy the middle
sort(v1.begin(), v1.end());
cout << "Majority element: " << v1[v1.size() / 2] << endl;
```

### Missing Number — XOR O(n) O(1)
```cpp
int xr = 0;
for (int i = 0; i <= n; i++) xr ^= i;
for (int x : v) xr ^= x;
return xr;  // missing number
```

### Kadane's Algorithm O(n)
```cpp
int cur = v[0], mx = v[0];
for (int i = 1; i < n; i++) {
    cur = max(v[i], cur + v[i]);
    mx  = max(mx, cur);
}
return mx;
```

---

## ⏱️ Time & Space Complexities

| Problem            | Time       | Space  | Method          | 
|--------------------|------------|--------|-----------------|
| Two Sum            | O(n log n) | O(1)   | Two Pointer     |
| Reverse Array      | O(n)       | O(1)   | Two Pointer     |
| Rotate Array       | O(n)       | O(1)   | Reverse Trick   |
| Sort 0s 1s         | O(n)       | O(1)   | Two Pointer     |
| Dutch Flag         | O(n)       | O(1)   | 3 Pointer       |
| Merge Sorted       | O(m+n)     | O(m+n) | Two Pointer     |
| Next Permutation   | O(n)       | O(1)   | Pivot + Reverse |
| Rain Water         | O(n)       | O(1)   | Two Pointer     |
| Move Zeroes        | O(n)       | O(1)   | Write Pointer   |
| Majority Element   | O(n log n) | O(1)   | Sorting         |
| Missing Number     | O(n)       | O(1)   | XOR / Sum       |
| Kadane's Algo.     | O(n)       | O(1)   | DP/Greedy       |

---