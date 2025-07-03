#include <stdlib.h>
#include <string.h>

#include "vector.h"

#define INITIAL_CAPACITY 10

Vector *vector_construct() {
    Vector *v = calloc(1, sizeof(Vector));
    v->allocated = INITIAL_CAPACITY;
    v->data = calloc(v->allocated, sizeof(data_type));
    return v;
}

void vector_destroy(Vector *v) {
    free(v->data);
    free(v);
}

void vector_push_back(Vector *v, data_type val) {
    if (v->size >= v->allocated) {
        v->allocated *= 2;
        v->data = realloc(v->data, v->allocated * sizeof(data_type));
    }
    v->data[v->size++] = val;
}

int vector_size(Vector *v) {
    return v->size;
}

data_type vector_get(Vector *v, int i) {
    if (i < 0 || i >= v->size) {
        fprintf(stderr, "Error: Element index %d out of the interval.\n", i);
        exit(1);
    }
    return v->data[i];
}

void vector_set(Vector *v, int i, data_type val) {
    if (i < 0 || i >= v->size) {
        fprintf(stderr, "Error: Element index %d out of the interval.\n", i);
        exit(1);
    }
    v->data[i] = val;
}

int vector_find(Vector *v, data_type val) {
    for (int i = 0; i < v->size; i++)
        if (v->data[i] == val) return i;
    return -1;
}

data_type vector_max(Vector *v) {
    return v->data[vector_argmax(v)];
}

data_type vector_min(Vector *v) {
    return v->data[vector_argmin(v)];
}

int vector_argmax(Vector *v) {
    int max_index = 0;
    for (int i = 1; i < v->size; i++)
        if (v->data[i] > v->data[max_index]) max_index = i;
    return max_index;
}

int vector_argmin(Vector *v) {
    int min_index = 0;
    for (int i = 1; i < v->size; i++)
        if (v->data[i] < v->data[min_index]) min_index = i;
    return min_index;
}

data_type vector_remove(Vector *v, int i) {
    if (i < 0 || i >= v->size) {
        fprintf(stderr, "Error: Element index %d out of the interval.\n", i);
        exit(1);
    }
    data_type val = v->data[i];
    for (int j = i; j < v->size - 1; j++)
        v->data[j] = v->data[j + 1];
    v->size--;
    return val;
}

data_type vector_pop_front(Vector *v) {
    return vector_remove(v, 0);
}

data_type vector_pop_back(Vector *v) {
    return vector_remove(v, v->size - 1);
}

void vector_insert(Vector *v, int i, data_type val) {
    if (i < 0 || i > v->size) {
        fprintf(stderr, "Error: Element index %d out of the interval for insertion.\n", i);
        exit(1);
    }
    if (v->size >= v->allocated) {
        v->allocated *= 2;
        v->data = realloc(v->data, v->allocated * sizeof(data_type));
    }
    for (int j = v->size; j > i; j--)
        v->data[j] = v->data[j - 1];
    v->data[i] = val;
    v->size++;
}

void vector_swap(Vector *v, int i, int j) {
    data_type tmp = vector_get(v, i);
    vector_set(v, i, vector_get(v, j));
    vector_set(v, j, tmp);
}

void vector_sort(Vector *v) {
    int swapped;
    for (int i = 0; i < v->size - 1; i++) {
        swapped = 0;
        for (int j = 0; j < v->size - i - 1; j++) {
            if (v->data[j] > v->data[j + 1]) {
                vector_swap(v, j, j + 1);
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

int vector_binary_search(Vector *v, data_type val) {
    int low = 0, high = v->size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (v->data[mid] == val) return mid;
        else if (v->data[mid] < val) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void vector_reverse(Vector *v) {
    for (int i = 0; i < v->size / 2; i++)
        vector_swap(v, i, v->size - i - 1);
}

Vector *vector_copy(Vector *v) {
    Vector *copy = malloc(sizeof(Vector));
    copy->allocated = v->allocated;
    copy->size = v->size;
    copy->data = malloc(copy->allocated * sizeof(data_type));
    memcpy(copy->data, v->data, v->size * sizeof(data_type));
    return copy;
}

void print_vector(Vector *v) {
    printf("Vector[%d]: ", vector_size(v));
    for (int i = 0; i < vector_size(v); i++) {
        printf("%d ", vector_get(v, i));
    }
    printf("\n");
}

void vector_clear(Vector *v) {
    v->size = 0;
}