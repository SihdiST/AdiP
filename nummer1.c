#include <stdio.h>

unsigned faculty(unsigned n){
	if(n == 0) 
		return 1;
	unsigned prod = 1;
	for(unsigned i = 1; i <= n; i++) 
		prod *= i;
	return prod;
}

unsigned bincoef(unsigned n, unsigned k){
	if(0 <= k && k <= n){
		return faculty(n)/(faculty(k)*faculty(n-k));
	}
	else if( 0 <= n && n < k){
		return 0;
	}
}

unsigned mod_lotto(unsigned n, unsigned k){
	return bincoef(n, k) * faculty(k);
}

int main(void){
	printf("\n faculty von 5: %i", faculty(5));
	printf("\n bincoef von n = 10 und k = 3: %i", bincoef(10, 3));
	printf("\n mod_lotto von n = 10 und k = 3: %i", mod_lotto(10, 3));
	return 0;
}
