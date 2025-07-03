#include <stdio.h>

#include "vector.h"

int main() {

    Vector *v = vector_construct();

    printf("INSERTING VALUES\n");
    for (int i = 1; i <= 10; i++) {
        vector_push_back(v, i);
    }
    print_vector(v);

    printf("\n");

    printf("INSERTING AT A GIVEN POSITION\n");
    vector_insert(v, 5, 99);
    print_vector(v);

    printf("\n");

    printf("REMOVING FROM A GIVEN POSITION\n");
    vector_remove(v, 2);
    print_vector(v);

    printf("\n");

    printf("ACCESS AND MODIFY THE ELEMENT AT A GIVEN POSITION\n");
    printf("Element at position v[3]: %d\n", vector_get(v, 3));

    printf("MODIFYING THE VALUE OU v[3] FOR 42\n");
    vector_set(v, 3, 42);
    print_vector(v);

    printf("\n");

    printf("SEARCH\n");
    printf("Index of 42: %d\n", vector_find(v, 42));
    printf("Index of 77 (not exists): %d\n", vector_find(v, 77));

    printf("\n");

    printf("MAX AND MIN\n");
    printf("Max: %d\n", vector_max(v));
    printf("Min: %d\n", vector_min(v));
    printf("Argmax: %d\n", vector_argmax(v));
    printf("Argmin: %d\n", vector_argmin(v));

    printf("\n");

    printf("SORTING FUNCTIONS\n");
    vector_set(v, 0, 500);
    vector_sort(v);
    print_vector(v);

    printf("\n");

    printf("BINARY SEARCH\n");
    printf("Binary search for 42: %d\n", vector_binary_search(v, 42));

    printf("\n");

    printf("INVERT\n");
    vector_reverse(v);
    print_vector(v);

    printf("\n");

    printf("COPYING\n");
    Vector *copia = vector_copy(v);
    printf("Copy -> ");
    print_vector(copia);

    printf("\n");

    printf("CLEANING\n");
    vector_clear(v);
    print_vector(v);

    // Memory cleanup
    vector_destroy(v);
    vector_destroy(copia);
    printf("Memory clean!\n");

    return 0;
}
