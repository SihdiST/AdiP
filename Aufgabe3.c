//
// Created by johan on 07.12.2018.
//

#include "Aufgabe3.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

student* create_student(unsigned matrikelnummer_f, char* vorname_f, char* nachname_f){
    student* studentf;
    studentf = malloc(sizeof(student));
    studentf->matrikelnummer = matrikelnummer_f;
    strcpy(studentf->vorname, vorname_f);
    strcpy(studentf->nachname, nachname_f);
    return studentf;
}


void clear_student(student* to_clear){
    free(to_clear);
}
void print_student(student* to_print){
    if(to_print == NULL){
        printf("");
    }
    else{
        printf("\nVorname: %s, Nachname: %s, Matrikelnummer: %u",
                to_print->vorname, to_print->nachname, to_print->matrikelnummer);
    }

}

void print_students(student ** array_to_print){
    //size always 20
    for(size_t i = 0; i < 20; i++){
        if(array_to_print[i] == NULL)
            printf("\nleer");
        else
            print_student(array_to_print[i]);
    }
}

void clear_students(student** array_to_clear){
    //size = 20
    for(size_t i = 0; i < 20; i++){
        clear_student(array_to_clear[i]);
        array_to_clear[i] = NULL;
    }
}

void get_name(unsigned mat_number, student** array_to_search){
    for(size_t i = 0; i<20; i++){
        if(array_to_search[i]->matrikelnummer == mat_number){
            print_student(array_to_search[i]);
            break;
        }
    }
}

int add_student(student** array, unsigned mat_number, char* vorname, char* nachname){
    for(size_t i = 0; i < 20; i++){
        if(array[i] == NULL){
            array[i] = create_student(mat_number, vorname, nachname);
            return 1; //erfolgreich hinzugefügt
        }
    }
    return 0; //nicht erfolgreich
}

void remove_student(student** array, unsigned mat_number){
    for(size_t i = 0; i<20; i++){
        if(array[i]->matrikelnummer == mat_number){
            clear_student(array[i]);
            array[i] = NULL;
            break;
        }
    }
}