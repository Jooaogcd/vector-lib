# Vector Library

## Introduction

The vector data structure is an ordered collection of elements that can be accessed by indices. Unlike static arrays in C, this vector is dynamic, allowing its size to grow or shrink as needed. It is implemented to store elements of type `data_type`, which is defined as `int` in the `vector.h` file.

## Vector Structure

The `Vector` structure is defined in the `vector.h` file and has the following members:

- **`data_type *data`**: A pointer to the array that stores the vector's elements.
- **`int size`**: The current number of elements stored in the vector.
- **`int allocated`**: The amount of memory allocated for the `data` array, which may be larger than `size` to allow for efficient expansion.

## Available Functions

The following functions are declared in `vector.h` and implemented in `vector.c`. They provide an interface to manipulate the vector:

- **`Vector *vector_construct()`**  
  Creates a new vector with an initial capacity of 10 elements and returns a pointer to it.

- **`void vector_destroy(Vector *v)`**  
  Frees all memory allocated for the vector and its data.

- **`void vector_push_back(Vector *v, data_type val)`**  
  Adds an element `val` to the end of the vector. If necessary, doubles the allocated capacity.

- **`int vector_size(Vector *v)`**  
  Returns the current number of elements in the vector.

- **`data_type vector_get(Vector *v, int i)`**  
  Returns the element at position `i`. If `i` is out of bounds, displays an error message and terminates the program.

- **`void vector_set(Vector *v, int i, data_type val)`**  
  Sets the element at position `i` to `val`. If `i` is out of bounds, displays an error message and terminates the program.

- **`int vector_find(Vector *v, data_type val)`**  
  Returns the index of the first occurrence of `val` in the vector, or -1 if not found.

- **`data_type vector_max(Vector *v)`**  
  Returns the largest element in the vector.

- **`data_type vector_min(Vector *v)`**  
  Returns the smallest element in the vector.

- **`int vector_argmax(Vector *v)`**  
  Returns the index of the largest element in the vector.

- **`int vector_argmin(Vector *v)`**  
  Returns the index of the smallest element in the vector.

- **`data_type vector_remove(Vector *v, int i)`**  
  Removes and returns the element at position `i`, shifting subsequent elements. If `i` is out of bounds, displays an error message and terminates the program.

- **`data_type vector_pop_front(Vector *v)`**  
  Removes and returns the first element of the vector.

- **`data_type vector_pop_back(Vector *v)`**  
  Removes and returns the last element of the vector.

- **`void vector_insert(Vector *v, int i, data_type val)`**  
  Inserts `val` at position `i`, shifting subsequent elements to the right. If `i` is out of the allowed bounds (0 to `size`), displays an error message and terminates the program.

- **`void vector_swap(Vector *v, int i, int j)`**  
  Swaps the elements at positions `i` and `j`.

- **`void vector_sort(Vector *v)`**  
  Sorts the vector in ascending order using the bubble sort algorithm.

- **`int vector_binary_search(Vector *v, data_type val)`**  
  Performs a binary search on the vector (which must be sorted) to find `val`, returning its index or -1 if not found.

- **`void vector_reverse(Vector *v)`**  
  Reverses the order of elements in the vector.

- **`Vector *vector_copy(Vector *v)`**  
  Creates and returns a copy of the vector.

- **`void print_vector(Vector *v)`**  
  Prints the vector's content to the console in the format `Vector[size]: element1 element2 ...`.

- **`void vector_clear(Vector *v)`**  
  Removes all elements from the vector, setting its size to 0.

## Usage Examples

Here are practical examples of how to use the vector functions:

```c
#include "vector.h"

int main() {
    // Create a vector
    Vector *v = vector_construct();

    // Add elements
    vector_push_back(v, 1);
    vector_push_back(v, 3);
    vector_push_back(v, 2);
    print_vector(v);  // Output: Vector[3]: 1 3 2

    // Sort the vector
    vector_sort(v);
    print_vector(v);  // Output: Vector[3]: 1 2 3

    // Search for an element
    int index = vector_binary_search(v, 2);
    printf("Index of 2: %d\n", index);  // Output: Index of 2: 1

    // Free memory
    vector_destroy(v);
    return 0;
}
```

## Considerations for Future

- **Memory Management**:  
  The vector uses `calloc` for initial allocation and `realloc` for dynamic expansion. The initial capacity is 10, and it doubles when the vector becomes full, ensuring amortized efficiency in `vector_push_back`.

- **Error Handling**:  
  Functions such as `vector_get`, `vector_set`, `vector_remove`, and `vector_insert` check index bounds. If an invalid index is provided, the program displays an error message and terminates.

- **Efficiency**:  
  - `vector_push_back`: O(1) amortized.  
  - `vector_insert` and `vector_remove`: O(n) in the worst case due to element shifting.  
  - `vector_sort`: O(n²) due to the use of bubble sort.  
  - `vector_binary_search`: O(log n), but requires the vector to be sorted.