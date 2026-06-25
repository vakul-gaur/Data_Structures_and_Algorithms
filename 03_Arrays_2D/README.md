# 📦 Arrays 2D — Complete Revision Guide

> A **2D array** is a matrix - an array of arrays, accessed with two indices: `arr[row][col]`.  
> C++ stores it in **row-major order** (row by row) in contiguous memory.

---

## 📁 Files in This Folder

| File                                 | Topic                                           |
|--------------------------------------|-------------------------------------------------| 
| `01_representation_declaration.cpp`  | 5 ways to declare, memory layout, row-major     |
| `02_input_output_traversal.cpp`      | I/O, row/col/diagonal/zigzag traversal          |
| `03_2d_array_into_functions.cpp`     | Passing arrays — column count required          |
| `04_max_element_2d.cpp`              | Global, row-wise, col-wise max/min              |
| `05_add_two_matrices.cpp`            | Element-wise add, subtract, scalar multiply     |
| `06_transpose_matrix.cpp`            | In-place (square), new matrix (non-square)      |
| `07_rotate_image.cpp`                | 90°/180° rotation — transpose + reverse         |
| `08_matrix_multiplication.cpp`       | A(m×k) × B(k×n) = C(m×n), triple loop           |
| `09_2d_vectors.cpp`                  | Dynamic 2D, I/O, Passing to Functions           |
| `10_wave_matrix.cpp`                 | Column/row zigzag traversal                     |
| `11_spiral_matrix.cpp`               | 4-boundary spiral print + generate spiral       |
| `12_pascal_triangle.cpp`             | Build triangle, nth row, C(n,k)                 |
| `13_score_after_flipping_matrix.cpp` | Greedy — flip rows/cols to maximize score       |
| `14_search_in_matrix.cpp`            | Staircase O(n+m) search                         |

---

## 🧠 Concept 1 — Declaration

```cpp
int arr[3][4];    // 3 rows, 4 cols - garbage values
int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};    // full init
int arr[3][4] = {0};    // all zeros
int arr[][4]  = {{1,2,3,4},{5,6,7,8}};    // rows auto-deduced (cols must be given)
```

Memory layout:
```
arr[0][0] arr[0][1] arr[0][2] arr[1][0] arr[1][1] ...
← continuous in memory, row by row (row-major) →
```

---

## 🧠 Concept 2 — Passing to Functions

```cpp
// Cols MUST be a compile-time constant:
void f(int arr[][4], int rows, int cols);

// Flexible alternative using pointer:
void f(int* arr, int rows, int cols) {
    arr[i * cols + j];   // manual offset
}

// Best modern way: 2D vector
void f(const vector<vector<int>>& mat);   // read-only
void f(vector<vector<int>>& mat);         // modifiable
```

---

## 🧠 Concept 3 — 2D Vectors

```cpp
vector<vector<int>> mat(rows, vector<int>(cols, 0));  // uniform
vector<vector<int>> mat = {{1,2},{3,4},{5,6}};        // init list

mat.size()       // rows
mat[0].size()    // cols in row 0
mat[i][j]        // access element

mat.push_back({7, 8});   // add row
mat.pop_back();          // remove last row
```

---

## 🔧 Key Traversal Patterns

```cpp
// Row-wise
for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)

// Column-wise
for (int j = 0; j < cols; j++)
    for (int i = 0; i < rows; i++)

// Main diagonal(square): 
arr[i][i]

// Anti-diagonal(square): 
arr[i][n-1-i]

// All main-diagonals share same 
(i - j)

// All anti-diagonals share same 
(i + j)
```

---

## 🔧 Algorithm Quick Reference

### Transpose (Square, In-Place)
```cpp
for (int i = 0; i < n; i++)
    for (int j = i+1; j < n; j++)   // j starts from i+1
        swap(mat[i][j], mat[j][i]);
```

### Rotate 90° Clockwise
```cpp
// Step 1: Transpose
// Step 2: Reverse each row
for (int i = 0; i < n; i++) reverse(mat[i].begin(), mat[i].end());
```

### Matrix Multiplication A(m×k) × B(k×n)
```cpp
for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
        for (int p = 0; p < k; p++)
            C[i][j] += A[i][p] * B[p][j];
```

### Spiral Traversal (4 Boundaries)
```cpp
int top=0, bottom=rows-1, left=0, right=cols-1;
while (top<=bottom && left<=right) {
    // RIGHT across top, DOWN right, LEFT across bottom, UP left
    // shrink boundary after each direction
}
```

### Search in Matrix — Staircase O(n+m)
```cpp
int row = 0, col = cols - 1;   // start TOP-RIGHT
while (row < rows && col >= 0) {
    if (mat[row][col] == target) return true;
    else if (mat[row][col] > target) col--;   // go left
    else row++;    // go down
}
```

### Score After Flipping (Greedy)
```cpp
// Step 1: Flip any row where first element is 0
// Step 2: For each column, if 0s > 1s → flip the column
// Use XOR: bit ^= 1 to flip or use bit = 1 - bit;
```

### Pascal's Triangle
```cpp
triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
// First and last of each row = 1
```

---

## ⏱️ Time Complexities

| Operation                    | Time     | Space  |
|------------------------------|----------|--------|
| Traversal (all elements)     | O(n×m)   | O(1)   |
| Max/Min element              | O(n×m)   | O(1)   |
| Matrix Addition              | O(n×m)   | O(n×m) |
| Transpose (square, in-place) | O(n²)    | O(1)   |
| Rotate 90°                   | O(n²)    | O(1)   |
| Matrix Multiplication        | O(m×k×n) | O(m×n) |
| Spiral Traversal             | O(n×m)   | O(1)   |
| Pascal's Triangle            | O(n²)    | O(n²)  |
| Search in Matrix (staircase) | O(n+m)   | O(1)   |
| Score After Flipping         | O(n×m)   | O(1)   |

---