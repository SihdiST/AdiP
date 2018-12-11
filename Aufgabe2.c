//
// Created by johan on 07.12.2018.
//

#include "Aufgabe2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void noten_berechnung(){
    int n_studenten;
    student_note * student_array;
    char nachname[30];
    float note;
    float beste_note;
    int check_var;
    float sum;

    printf("\nBitte geben Sie die Anzahl der Studenten ein, die Sie einlesen möchten: ");
    scanf(" %i", &n_studenten);

    student_array = malloc(n_studenten * sizeof(student_note));


    for(int i = 0; i < n_studenten; i++){
        //einlesen
        printf("\nBitte geben Sie den %i. Nachnamen ein: ", i+1);
        scanf(" %s", nachname);

        while(1){
            printf("\nBitte geben Sie die %i. Note zwischen 1.0 und 5.0 ein: ", i+1);
            check_var = scanf(" %f", &note);
            if(note < 1.0 || note > 5.0 || check_var != 1){
                printf("\nSie haben eine falsche Eingabe getätigt!");
            }
            else
                break;
        }

        strcpy(student_array[i].nachname, nachname);
        student_array[i].note = note;
    }

    beste_note = student_array[0].note;
    sum = student_array[0].note;

    for(int j = 1; j < n_studenten; j++){
        sum += student_array[j].note;
        if(student_array[j].note < beste_note)
            beste_note = student_array[j].note;
    }

    for(int k = 0; k < n_studenten; k++){
        if(student_array[k].note == beste_note)
            printf("\n%s hat die beste Note mit %f", student_array[k].nachname, beste_note);
    }

    printf("\nDie Durchschnittsnote aller Studenten beträgt: %f", sum /n_studenten);
    free(student_array);
}