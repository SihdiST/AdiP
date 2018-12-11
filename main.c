#include <stdio.h>
#include "aufgabe1.h"
#include "aufgabe2.h"

int main(void) {
    char test_a1_1_1[100] = "Hallo";
    char test_a1_1_2[100] = "lagerregal";
    char test_a1_2_1[100];
    char test_a1_2_2[100];
    int k;
    DynArray *test_a2_1;
    DynArrayMin *test_a2_2;

    //a1 1
    reverse_string(test_a1_1_1);
    printf("%s\n", test_a1_1_1);
    printf("%i\n", palindrome_check(test_a1_1_2));

    //a1 2
    printf("\nBitte geben Sie ein Wort ein, das ROT13 verschlüsselt werden soll: ");
    scanf(" %s", test_a1_2_1);
    printf("\nverschlüsselt: %s\n", encrypt_rot13(test_a1_2_1));
    printf("entschlüsselt: %s\n\n", decrypt_rot13(test_a1_2_1));

    printf("Bitte geben Sie ein Wort ein, das verschlüsselt werden soll: ");
    scanf(" %s", test_a1_2_2);
    printf("\nBitte geben Sie ein, um wie viel die Buchstaben rotiert werden sollen: ");
    scanf(" %i",&k);
    printf("\nverschlüsselt: %s", encrypt(test_a1_2_2, k));
    printf("\nentschlüsselt: %s", decrypt(test_a1_2_2, k));

    //a2_1
    test_a2_1 = init_dynArray(1);
    test_a2_1 = dyn_array_add(test_a2_1, 7);
    print_DynArray(test_a2_1);
    printf("\n");
    test_a2_1 = dyn_array_add(test_a2_1, 8);
    test_a2_1 = dyn_array_add(test_a2_1, 8);
    test_a2_1 = dyn_array_add(test_a2_1, 8);

    print_DynArray(test_a2_1);
    printf("\n\n");

    /* der zweite ansatz bietet generell bessere speicherperformance ist aber langsamer,
 * da für jedes neue Element der Speicherplatz erweitert werden
 * muss, besonders bei größeren Mengen an Eingaben ist die erste weitaus
 * schneller, da hier nicht so oft der Speicher erweitert werden muss,
 * kann aber unnötig viel speicherplatz verbrauchen, wenn der verdoppelte Platz nicht
     * aufgefüllt wird*/

    //a2_2
    test_a2_2 = init_dynArrayMin(1);
    test_a2_2 = dyn_array_min_add(test_a2_2, 1);
    print_DynArrayMin(test_a2_2);
    printf("\n");

    test_a2_2 = dyn_array_min_add(test_a2_2, 8);
    test_a2_2 = dyn_array_min_add(test_a2_2, 8);

    print_DynArrayMin(test_a2_2);
    printf("\n\n");

    return 0;
}