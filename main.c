#include <stdio.h>
#include <math.h>
#include "Aufgabe1.h"
#include "Aufgabe2.h"
#include "Aufgabe3.h"
#include "Aufgabe4.h"

int main() {
    int test_matrix1[2][3] = {{0, 1, 2}, {3, 4, 5}};
    int test_matrix2[3][2] = {{6, 7}, {9, 11}, {12, 13}};

    //matrix_mult(2, 3, test_matrix1, 3, 2, test_matrix2);


    //noten_berechnung();

/*
    student* array_stud[20] = {NULL};


    add_student(array_stud, 42, "Peter", "Johanns");
    get_name(42, array_stud);

    add_student(array_stud, 30, "Claude", "Jordan");

    get_name(30, array_stud);

    remove_student(array_stud, 42);
    print_students(array_stud);

    clear_students(array_stud);
    print_students(array_stud);

*/
    printf("\nIntegral von Sinus [0, pi]: %f\n", integrate(&sin, 0, M_PI, 0.0001)); //2
    printf("Integral von Sinus [0, 2pi]: %f\n", integrate(&sin, 0, 2*M_PI, 0.0001)); //0
    printf("Integral von f(x)=0.4x^5+x^3 [0, 3]: %f\n", integrate(&f, 0, 3, 0.0001)); //ca. 68,84


    return 0;
}