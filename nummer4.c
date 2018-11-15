#include<stdio.h>
#include<math.h>

void pyth_triplet(){
	
	for(unsigned a = 1; a < 1000; a++){
		for(unsigned b = a+1; b < 1000; b++){
			for(unsigned c = b+1; c < 1000; c++){
				if(pow(a, 2) + pow(b, 2) == pow(c, 2))
					printf("\na: %i; b: %i, c: %i", a, b, c);
			}
		}
	}
}

int main(void){
	pyth_triplet();
	return 0;
}