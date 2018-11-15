#include <sdtio.h>
#include <stdlib.h>

int main(void){
	int user_input;
	int check_var;
	int random_number = rand();
	int difference;
	
	printf("\nDie zufällige Nummer ist %i", random_number);
	printf("\nBitte geben Sie nun eine ganze Zahl ein, die höher ist: ");
	
	check_var = scanf(" %i", &user_input);
	
	if(check_var != 1){
		printf("\nFalsche Eingabe! Abbruch...\n");
		return 0;
	}
	
	if(user_input <= random_number){
		printf("\n Die Eingabe ist nicht größer! Abbruch...\n");
		return 0;
	}
	
	difference = random_number - user_input;
	
	printf("\n%i mal 50", difference / 50);
	difference %= 50;
	printf("\n%i mal 20", difference / 20);
	difference %= 20;
	printf("\n%i mal 10", difference / 10);
	difference %= 10;
	printf("\n%i mal 5", difference / 5);
	difference %= 5;
	printf("\n%i mal 2", difference / 2);
	difference %= 2;
	printf("\n%i mal 1", difference );
	
	
	
	return 0;
}
