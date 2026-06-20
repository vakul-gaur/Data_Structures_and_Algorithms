# 📦 Arrays 1D — Complete Revision Guide

> A 1D array is a collection of elements of the **same data type** stored in **contiguous memory locations**, accessed using an index.

---

## 📁 Files in This Folder

| File                                | Topic                                        |
|-------------------------------------|----------------------------------------------|
| `01_syntax_and_declaration.cpp`     | Declaring and initializing arrays (5 ways)   |
| `02_access_elements.cpp`            | Reading and writing elements by index        |
| `03_input_output.cpp`               | Taking user input and printing array         |
| `04_size_and_sizeof.cpp`            | Using sizeof to get array length             |
| `05_memory_allocation.cpp`          | Stack memory, contiguous layout              |
| `06_sum_of_array.cpp`               | Sum and average of all elements              |
| `07_linear_search.cpp`              | Search an element one by one                 |
| `08_find_max_value.cpp`             | Find max and min in a single pass            |
| `09_second_largest.cpp`             | Second distinct largest in O(n)              |
| `10_passing_array_to_functions.cpp` | How arrays behave when passed to functions   |
| `1_arrays_and_pointers.cpp`         | Deep connection between arrays and pointers   |

---

## 🧠 Concept 1 — Syntax and Declaration

```cpp
int arr[5];                  // uninitialized (garbage values)
int arr[5] = {1, 2, 3, 4, 5};  // fully initialized
int arr[]  = {1, 2, 3};     // size auto-deduced (= 3)
int arr[5] = {1, 2};        // partial: rest become 0
int arr[5] = {0};           // all zeros
```

- Index runs from `0` to `size - 1`
- Accessing out-of-bound index -> **undefined behavior** (no error in C++)

---

## 🧠 Concept 2 — Accessing Elements

```cpp
arr[0]       // read first element
arr[i] = 10; // write to index i
```

- `arr[i]` and `*(arr + i)` are **identical**
- Range-based for loop: `for (int x : arr)` — no index needed

---

## 🧠 Concept 3 — sizeof Operator

```cpp
int arr[] = {1, 2, 3, 4, 5};

sizeof(arr)        // 20 bytes  (5 × 4)
sizeof(arr[0])     // 4 bytes   (one int)
sizeof(arr) / sizeof(arr[0])   // = 5 (number of elements)
```

> ⚠️ When passed to a function, `sizeof(arr)` returns **pointer size (8 bytes)**, not array size. Always pass `n` separately.

---

## 🧠 Concept 4 — Memory Layout

```
arr[0]  arr[1]  arr[2]  arr[3]  arr[4]
  10      20      30      40      50
 1000    1004    1008    1012    1016   ← memory addresses (4 bytes apart)
```

- **Stack array**: fixed size at compile time.

---

## 🧠 Concept 5 — Arrays & Pointers

```cpp
int arr[] = {10, 20, 30};

arr          // address of arr[0]
*arr         // value = 10
arr[i]       // same as *(arr + i)
&arr[i]      // address of element i

int* ptr = arr;
ptr++;       // moves to arr[1]  (arr++ is INVALID — arr is const pointer)
```

---

## 🔧 Common Patterns (Quick Reference)

### Input
```cpp
for (int i = 0; i < n; i++) cin >> arr[i];
```

### Print
```cpp
for (int i = 0; i < n; i++) cout << arr[i] << " ";
```

### Sum
```cpp
int sum = 0;
for (int i = 0; i < n; i++) sum += arr[i];
```

### Max
```cpp
int mx = arr[0];
for (int i = 1; i < n; i++) if (arr[i] > mx) mx = arr[i];
```

### Linear Search
```cpp
for (int i = 0; i < n; i++)
    if (arr[i] == target) return i;
return -1;
```

### Second Largest
```cpp
int first = INT_MIN, second = INT_MIN;
for (int i = 0; i < n; i++) {
    if (arr[i] > first) { second = first; first = arr[i]; }
    else if (arr[i] > second && arr[i] != first) second = arr[i];
}
```

---

## ⏱️ Time Complexities

| Operation            | Time |
|----------------------|------|
| Access by index      | O(1) |
| Linear Search        | O(n) |
| Find Max / Min       | O(n) |
| Second Largest       | O(n) |
| Sum of array         | O(n) |

---