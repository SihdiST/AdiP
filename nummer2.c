#include<stdio.h>

// Gibt den Nachfolger des ubergebenen Wertes zuruck
int succ(int x) {
	return ++x;
}
// Gibt den Vorganger des ubergebenen Wertes zuruck
int pre(int x) {
	return --x;
}

int add(int x, int y){
	if( y == 0)
		return x;
	else if(y > 0)
		return add(succ(x), pre(y));
	else
		return add(pre(x), succ(y));
}

int sub(int x, int y){
	if(y == 0)
		return x;
	else
		return sub(pre(x), pre(y));
}

int mult(int x, int y){
	if(y==1)
		return x;
	else if(x == 1)
		return y;
	else if(x == 0)
		return 0;
	else if(y == 0)
		return 0;
	else
		add(x, mult(x, pre(y))); // + statt add() fukntioniert
}

int main(void){
		printf("\n add von 2 und 0: %i", add(2,0));
		printf("\n add von -3 und 2: %i", add(-3, 2));

		printf("\n sub von 2 und 0: %i", sub(2,0));
		printf("\n sub von -3 und 2: %i", sub(-3, 2));

		printf("\n mult von 2 und 0: %i", mult(2, 0));
		printf("\n mutl von -3 und 2: %i", mult(-3, 2));

}
