//
// Created by johan on 13.12.2018.
//

#include "list_node.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct DoubleNode{
    struct DoubleNode* next;
    double data;
}DoubleNode;

DoubleNode* insertFirst(DoubleNode* head, double value){
    //funktioniert auch, wenn head NULL ist
    DoubleNode* new_head = malloc(sizeof(DoubleNode));
    new_head->data = value;
    new_head->next = head;

    return new_head;
}

void print_List(DoubleNode* head){
    DoubleNode* current = head;

    while(current != NULL){
        printf("\n( %f ", current->data);
        current = current->next;
    }
    printf(")\n");

}

DoubleNode* insertLast(DoubleNode* head, double value){
    if(head == NULL)
        return insertFirst(head, value);

    DoubleNode* current = head;

    while(current->next != NULL)
        current = current->next;
    DoubleNode* new_last = malloc(sizeof(DoubleNode));
    new_last->data = value;
    new_last->next = NULL;
    current->next = new_last;
    return head;
}

DoubleNode* reverseDoubleListCon(DoubleNode* head){
    //so bleibt alte Liste erhalten
    //sonst free mit new node ausführen
    DoubleNode* new_node = head;
    DoubleNode* tmp;
    DoubleNode* res = NULL;

    while(new_node->next != NULL){
        tmp = malloc(sizeof(DoubleNode));
        tmp->next = res;
        tmp->data = new_node->data;
        //DoubleNode* next = new_node->next;
        //free(new_node);
        //statt zeile hiernach: new_node = next;
        new_node = new_node->next;
        res = tmp;
    }

    return res;


}

void reverseDoubleList(DoubleNode** head_ref){
    DoubleNode* prev = NULL;
    DoubleNode* current = *head_ref;
    DoubleNode* next;

    while(current!= NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

double get(DoubleNode* head, size_t i){
    DoubleNode* tmp = head;
    if(head == NULL){
        printf("\nListe ist leer");
        return 0.0;
    }
    for(size_t j = 0; j < i; j++){
        if(tmp->next == NULL){
            printf("\nIndex überschreitet die Grenzen!");
            return 0.0;
        }
        tmp = tmp->next;
    }
    return tmp->data;
}

DoubleNode* del(DoubleNode* head, size_t i){
    DoubleNode* tmp = head;
    DoubleNode* prev = NULL;
    if(head == NULL){
        printf("\nListe ist leer");
        return 0;
    }
    if(i == 0){
        DoubleNode* new_head = head->next;
        free(head);
        return new_head;
    }

    for(size_t j = 0; j < i; j++){
        prev = tmp;
        tmp = tmp->next;
        if(tmp == NULL){
            printf("\nIndex überschreitet die Grenzen!");
            return head;
        }
    }
    prev->next = tmp->next;
    free(tmp);
}

DoubleNode* insert(DoubleNode* head, double value, size_t index){

    if(index == 0)
        return insertFirst(head, value);

    DoubleNode* cursor = head;
    DoubleNode* prev;

    for(size_t i = 0; i < index; i++){
        prev = cursor;
        if(prev == NULL){
            printf("\nIndex überschreitet die Grenzen!");
            return head;
        }
        cursor = cursor->next;
    }

    DoubleNode* tmp = malloc(sizeof(DoubleNode));
    tmp->data = value;
    tmp->next = cursor;
    prev->next = tmp;

    return head;

}