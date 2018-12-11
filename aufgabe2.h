//
// Created by johan on 20.11.2018.
//

#ifndef UEBUNG5_AUFGABE2_H
#define UEBUNG5_AUFGABE2_H

#endif //UEBUNG5_AUFGABE2_H

struct DynArray;
struct DynArrayMin;

typedef struct DynArray{
    size_t max_size;
    size_t current_size;
    int* int_array;
} DynArray;

typedef struct DynArrayMin{
    size_t max_size;
    size_t current_size;
    int* int_array;
} DynArrayMin;

DynArray* init_dynArray(size_t max_size);

DynArrayMin* init_dynArrayMin(size_t max_size);

void del_dynArray(DynArray* array_to_free);

void del_dynArrayMin(DynArrayMin* array_to_free);

DynArray* dyn_array_add(DynArray* array, int value);

DynArrayMin* dyn_array_min_add(DynArrayMin* array, int value);

void print_DynArray(DynArray* to_print);

void print_DynArrayMin(DynArrayMin* to_print);


