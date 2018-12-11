//
// Created by johan on 07.12.2018.
//
#include <stdio.h>
#include <stdlib.h>

#include "Aufgabe1.h"

void matrix_mult(size_t i_a, size_t j_a, int matrix_A[][j_a], size_t k_b, size_t l_b, int matrix_B[][l_b]){
    //TODO muss free anwenden
    int output = 0 ;
    if (j_a != k_b){
        printf("Fehler: J und B sind nicht gleich groß!");
    }
    else{
        printf("\n");
        for(size_t i = 0; i < i_a; i++){
            for(size_t l = 0; l < l_b; l++){
                for(size_t k = 0; k < k_b; k++){
                    output += matrix_A[i][k] * matrix_B[k][l];
                }
                printf("%i ", output);
                output = 0;
            }
            printf("\n");
        }
        printf("\n");
    }


}
