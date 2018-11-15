#include<stdio.h>
#include<math.h>

unsigned faculty(unsigned n){
	if(n == 0) 
		return 1;
	unsigned prod = 1;
	for(unsigned i = 1; i <= n; i++) 
		prod *= i;
	return prod;
}

long double sin(long double x){
	long double result = 0.0;
	
	for(unsigned n = 0; n < 6; n++){
		result += pow(-1, n) * (pow(x, 2*n+1)/faculty(2*n+1));
	}
	
	return result;
}

long double cos(long double x){
	long double result = 0.0;
	
	for(unsigned n = 0; n < 6; n++){
		result += pow(-1, n) * (pow(x, 2*n) / faculty(2*n));
	}
	
	return result;
}

long double exp(long double x){
	long double result = 0.0;
	
	for(unsigned n = 0; n < 11; n++){
		result *= pow(x, n)/faculty(n);
	}
	
	return result;
}

int main(void){
	long double user_input;
	int check_var;
	
	printf("\nBitte geben Sie eine Zahl x für sin, cos und exp ein: ");
	check_var = scanf(" %lf", &user_input);
	
	if(check_var != 1){
		printf("\nFalsche Eingabe! Abbruch...\n");
		return 0;
	}
	
	printf("\nsin von Eingabe: %Lf\n", sin(user_input));
	printf("\ncos von Eingabe: %Lf\n", cos(user_input));
	printf("\nexo von Eingabe: %Lf\n", exp(user_input));

}