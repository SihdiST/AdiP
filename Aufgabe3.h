//
// Created by johan on 07.12.2018.
//

#ifndef UEBUNG6_AUFGABE3_H
#define UEBUNG6_AUFGABE3_H

#endif //UEBUNG6_AUFGABE3_H

typedef struct student{
    unsigned matrikelnummer;
    char vorname[20];
    char nachname[30];
}student;

student* create_student(unsigned matrikelnummer_f, char* vorname_f, char* nachname_f);
void clear_student(student* to_clear);
void print_student(student* to_print);
void print_students(student ** array_to_print);
void clear_students(student** array_to_clear);
void get_name(unsigned mat_number, student** array_to_search);
int add_student(student* array[], unsigned mat_number, char* vorname, char* nachname);
void remove_student(student* array[], unsigned mat_number);
