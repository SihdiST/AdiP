//
// Created by johan on 20.11.2018.
//

#include <stdlib.h>
#include "aufgabe2.h"
#include <stdio.h>

//in header definiert
/*
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
*/


DynArray* init_dynArray(size_t max_size){
    DynArray* init = malloc(sizeof(DynArray));
    init->max_size = max_size;
    init->current_size = 0;
    init->int_array = malloc(max_size* sizeof(int));
    return init;
}

DynArrayMin* init_dynArrayMin(size_t max_size){
    DynArrayMin* init = malloc(sizeof(DynArrayMin));
    init->max_size = max_size;
    init->current_size = 0;
    init->int_array = malloc(max_size* sizeof(int));
    return init;
}

void del_dynArray(DynArray* array_to_free){
    free(array_to_free -> int_array);
    free(array_to_free);
}

void del_dynArrayMin(DynArrayMin* array_to_free){
    free(array_to_free -> int_array);
    free(array_to_free);
}

DynArray* dyn_array_add(DynArray* array, int value){
    // über realloc auch möglich
    if(array -> current_size == array -> max_size){
        //erweitern und kapazität verdoppeln, altes int_array löschen
        DynArray* new_array = init_dynArray((array->max_size) *2);
        new_array -> current_size = (array -> current_size) +1;

        //aus altem in neues kopieren
        for(size_t i = 0; i < array-> max_size; i++){
            new_array->int_array[i] = array->int_array[i];
        }

        new_array->int_array[new_array->current_size -1] = value;
        del_dynArray(array);
        return new_array;

    }
    else{
      array->int_array[array->current_size] = value;
      array->current_size += 1;
      return array;
    }
}

DynArrayMin* dyn_array_min_add(DynArrayMin* array, int value){

    if(array -> current_size == array -> max_size){
        //kapazität um 1 erweitern, altes int_array löschen
        DynArrayMin* new_array = init_dynArrayMin(array->max_size +1);
        new_array -> current_size = array -> current_size +1;

        //aus altem in neues kopieren
        for(size_t i = 0; i < array-> max_size; i++){
            new_array->int_array[i] = array->int_array[i];
        }

        new_array->int_array[new_array->current_size-1] = value;
        del_dynArrayMin(array);
        return new_array;

    }
    else{
        array->int_array[array->current_size] = value;
        array->current_size += 1;
        return array;
    }
}

void print_DynArray(DynArray* to_print){
    for(size_t i = 0; i < to_print->current_size; i++){
        printf("\n%i", to_print->int_array[i]);
    }
}

void print_DynArrayMin(DynArrayMin* to_print){
    for(size_t i = 0; i < to_print->current_size; i++){
        printf("\n%i", to_print->int_array[i]);
    }
}