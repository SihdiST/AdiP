//
// Created by johan on 20.11.2018.
//

#include "aufgabe1.h"
#include <string.h>

void reverse_string(char* s){
    size_t s_len = strlen(s);
    char help;
    for(size_t i = 0; i < s_len / 2; i++){
        help = s[i];
        s[i] = s[s_len-1-i];
        s[s_len-1-i] = help;
    }

}

int palindrome_check(char* s){
    size_t n = strlen(s);
    char reversed_string[n];
    strcpy(reversed_string, s);
    reverse_string(reversed_string);
    if(!strcmp(s, reversed_string))
        return 1;
    else
        return 0;

}

char* encrypt_rot13(char*s){
    size_t s_len = strlen(s);
    for(size_t i = 0; i < s_len; i++){
        if(s[i] <= 90 && s[i] >= 65) {
            if (s[i] + 13 > 90)
                s[i] = 65 + (s[i] + 13 - 91);
            else
                s[i] = s[i] + 13;
        }
        else if(s[i] <= 122 && s[i] >= 97){
            if(s[i] + 13 > 122)
                s[i] = 97 + (s[i] + 13 - 123);
            else
                s[i] = s[i] + 13;
        }
    }

    return s;
}

char* decrypt_rot13(char*s){
    //gleicher code wie encrypt
    size_t s_len = strlen(s);
    for(size_t i = 0; i < s_len; i++){
        if(s[i] <= 90 && s[i] >= 65) {
            if (s[i] + 13 > 90)
                s[i] = 65 + (s[i] + 13 - 91);
            else
                s[i] = s[i] + 13;
        }
        else if(s[i] <= 122 && s[i] >= 97){
            if(s[i] + 13 > 122)
                s[i] = 97 + (s[i] + 13 - 123);
            else
                s[i] = s[i] + 13;
        }
    }

    return s;
}

char*encrypt(char*s, int k){
    k %= 27;
    size_t s_len = strlen(s);
    for(size_t i = 0; i < s_len; i++){
        if(s[i] <= 90 && s[i] >= 65) {
            if (s[i] + k > 90)
                s[i] = 65 + (s[i] + k - 91);
            else
                s[i] = s[i] + k;
        }
        else if(s[i] <= 122 && s[i] >= 97){
            if(s[i] + k > 122)
                s[i] = 97 + (s[i] + k - 123);
            else
                s[i] = s[i] + k;
        }
    }

    return s;
}

char*decrypt(char*s, int k){
    k %= 27;
    k = 26 - k;
    size_t s_len = strlen(s);
    for(size_t i = 0; i < s_len; i++){
        if(s[i] <= 90 && s[i] >= 65) {
            if (s[i] + k > 90)
                s[i] = 65 + (s[i] + k - 91);
            else
                s[i] = s[i] + k;
        }
        else if(s[i] <= 122 && s[i] >= 97){
            if(s[i] + k > 122)
                s[i] = 97 + (s[i] + k - 123);
            else
                s[i] = s[i] + k;
        }
    }

    return s;
}