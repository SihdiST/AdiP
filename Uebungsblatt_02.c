#include<stdio.h>
#include<math.h>

unsigned long  fib_even(long pN);
unsigned long fib_rec(long pN);
int aufgabe1();
int is_perfect(int pN);
int is_deficient(int pN);
void perfect_numbers_to(int pR);
int amount_deficient_numbers_to(int pR);
void multiplication_table();
int aufgabe5_a(int pA,unsigned int pN);
int aufgabe5_b(int pA, unsigned int pN);

int main(void){
	/* 
	//Test Aufgabe 2
	
	printf("First 50 even: \n");
	for(long i = 2; i <= 50;i++)  printf("%lu \n",fib_even(i));
	
	printf("First 10 even and odd: \n");
	for(long i = 0; i <= 10;i++)  printf("%lu \n",fib_rec(i));
	return 0;
	*/
	
	/* 
	//Test Aufgabe 3
	
	printf("Das is true: %i\n", 2==2);
	printf("Das is false: %i\n\n\n", 2==1);
	printf("14 is perfect?: %i\n", is_perfect(14));
	printf("18 is perfect?: %i\n", is_perfect(18));
	printf("25 is perfect?: %i\n", is_perfect(25));
	printf("28 is perfect?: %i\n", is_perfect(28));
	printf("51 is perfect?: %i\n\n\n", is_perfect(51));
	
	printf("14 is deficient?: %i\n", is_deficient(14));
	printf("18 is deficient?: %i\n", is_deficient(18));
	printf("25 is deficient?: %i\n", is_deficient(25));
	printf("28 is deficient?: %i\n", is_deficient(28));
	printf("51 is deficient?: %i\n\n\n", is_deficient(51));
	
	printf("Perfect numbers to 499:\n");
	perfect_numbers_to(499);	
	printf("\n\n");
	
	printf("Amount of deficient numbers to 499: %i\n\n\n", amount_deficient_numbers_to(499));
	*/
	
	/* 
	//Test Aufgabe 4
	
	multiplication_table();
	*/
	
	/*
	//Test Aufgabe 5
	
	printf("(a) 2^17 = %i\n\n\n", aufgabe5_a(2, 17));
	printf("(b) 2^17 = %i\n\n\n", aufgabe5_b(2, 17));
	*/
}

unsigned long  fib_even(long pN){
	if(pN <= 1) return pN;
	int i = 2;
	unsigned long  fibLast = 1;
	unsigned long  fibpreLast = 0;
	unsigned long  fib = 0;
	while(i <= pN){
		fib = fibLast + fibpreLast;
		
		unsigned long  tmp = fibLast + fibpreLast;
		fibpreLast = fibLast;
		fibLast = tmp;
		if(!(fib % 2 == 0)) continue;
		
		i++;
	}
	return fib;
}

unsigned long fib_rec(long pN){
	if(pN <= 1) return pN;
	return fib_rec(pN - 1) + fib_rec(pN - 2);
}

int aufgabe1(){
	char x,y,result;
	
	x = 35;
	y = 85;
	result = x + y;
	printf("%hi + %hi = %hi\n", x,y,result);
	
	x = 85;
	y = 85;
	result = x + y;
	printf("%hi + %hi = %hi\n", x,y,result);
		
	return 0;
}

int is_perfect(int pN){
	if(pN <= 1) return 0;
	int divisor_sum = 1;
	for(int i = 2; i <= sqrt(pN); i++){
		if((pN % i) == 0){
			divisor_sum += i;
			if((pN / i) != i){
				divisor_sum += (pN / i);
			}
		}
	}
	return (divisor_sum == pN);
	
}

int is_deficient(int pN){
	if(pN == 1) return 1;
	int divisor_sum = 1;
	for(int i = 2; i <= sqrt(pN); i++){
		if((pN % i) == 0){
			divisor_sum += i;
			if((pN / i) != i){
				divisor_sum += (pN / i);
			}
		}
	}
	return (divisor_sum < pN);
	
}

void perfect_numbers_to(int pR){
	for(int i = 0; i < pR; i++){
		if(is_perfect(i)) printf("%i\n", i);
	}
}

int amount_deficient_numbers_to(int pR){
	int amount = 0;
	for(int i = 0; i < pR; i++){
		if(is_deficient(i)) amount++;
	}
	return amount;
}

void multiplication_table(){
	for(int i = 1; i <= 10; i++){
		for(int k = 1; k <= 10; k++){
			printf("%i x %i = %i\n", i, k, (i*k));
		}
		printf("\n\n\n");
	}
}

int aufgabe5_a(int pA, unsigned int pN){
	if(pN == 0) return 1;
	int loop_passes = 0;
	int result = pA;
	for(int i = (pN - 1); i > 0; i--,loop_passes++) result = result * pA;
	printf("loop passes: %i\n", loop_passes);
	return result;

}

int aufgabe5_b(int pA, unsigned int pN){
	if(pN == 0) return 1;
	int loop_passes = 0;
	int result = 0;
	
	if((pN % 2) == 0){
		int tmp = pA;
		for(int i = (pN/2) - 1; i > 0; i--, loop_passes++) tmp *= pA;
		result = tmp * tmp;
	}else{
		result = pA;
		int tmp = pA;
		for(int i = ((pN - 1) / 2) - 1; i > 0;i--,loop_passes++) tmp *= pA;
		tmp = tmp * tmp;
		result *= tmp;
	}
	printf("Loop passes: %i\n", loop_passes);
	return result;
}