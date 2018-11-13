#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int player = 0;
int playerSum = 0;
int dealerSum = 0;
int dealer = 0;

//Methoden
void end(int pHow);
int getkarte();
void firstTurn();
void print(int pKartenwert);
void turnDealer();
void turnPlayer(void);

void initializegenerator() {
    srand(time(NULL));
}

void end(int pHow){
	if(pHow == 0){
		printf("Sie haben eine %i erreicht. Der Dealer kommt auf %i.\n", playerSum, dealerSum);

		if(playerSum <= dealerSum) printf("Somit hat der Dealer gewonnen.\nViel Gl\x81\bck beim n\x84 \bchsten Mal.\n");
		else printf("Somit haben Sie gewonnen.\nHerzlichen Gl\x81 \bckwunsch!\n");

	}
	else if(pHow == 1) printf("Sie haben die 21 \x81 \bberschritten. Somit haben Sie das Eau de Claude nicht gewonnen.\nViel Gl\x81 \bck beim n\x84 \bchsten Mal.\n");
	else printf("Der Dealer hat die 21 \x81 \bberschritten. Somit haben Sie das Eau de Claude gewonnen.\nHerzlichen Gl\x81 \bckwunsch!\n");

	int x = 0;
	printf("Wollen Sie noch eine Runde spielen? (1/0)");
	scanf("%i", &x);
	if(x == 1) firstTurn();
	else return;
}


int getkarte() {
    // Sie koennen Zufallszahlen generieren, indem Sie die Funktion rand() aufrufen
    int zufall = rand() % 9 + 2;

    // z.B. int zufall = rand();
    return zufall;
}
void firstTurn(){
	playerSum = 0;
	dealerSum = 0;
	player = 0;
	printf("\n#######################################################\n \nNeue Runde neues Gl\x81 \bck\n#######################################################\n \n");
	int kartenwert = getkarte();
	printf("Der Dealer hat eine %i gezogen.\n", kartenwert);
	dealerSum += kartenwert;
	turnPlayer();
}

void print(int pKartenwert){
	if(player == 1) printf("Sie haben eine %i gezogen.\nDie Summe ihrer Kartenwerte liegt aktuell bei %i\n", pKartenwert,playerSum);
	else printf("Der Dealer hat eine %i gezogen.\nDie Summe seiner Kartenwerte liegt aktuell bei %i\n", pKartenwert,dealerSum);
}

void turnDealer(){
	printf("Der Dealer ist am Zug. Er hat bereits eine %i gezogen.\n", dealerSum);

	while(dealerSum < 16){
		int x = getkarte();
		dealerSum += x;
		print(x);

		if(dealerSum > 21){
		end(2);
		return;
		}
	}

	end(0);
}

void turnPlayer(void){
	if(player == 0) printf("Sie sind am Zug. ");
	player = 1;
	int kartenwert = getkarte();
	playerSum += kartenwert;

	int newTurn = 0;
	print(kartenwert);

	if(playerSum > 21){
		end(1);
		return;
	 }

	int i = 0;
	while(i < 1){

		printf("Wollen Sie weiterziehen?(1/0)\n");
		scanf("%i", &newTurn);

		if(newTurn == 1){
			turnPlayer();
			i++;
		}
		else if(newTurn == 0) {
			player = 0;
			turnDealer();
			i++;
		}
		else printf("invalid statement");
	}


}

int main() {
    initializegenerator();
    // Code fuer den Spielablauf
	firstTurn();

    return 0;
}




