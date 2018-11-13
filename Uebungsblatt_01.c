#include<stdio.h>
#include<math.h>

/**
	Die Methode aufgabe2 vereint zwei Operationen, die man über den Parameter pAufgabenteil seperat ansteuern kann.
	Die Operation, welche den Aufgabenteil 1 implementiert gibt die Summe aller Zahlen von 1 bis pEingabe mithilfe der Gaußschen Summenformel zurück.
	Die zweite Operation summiert alle Quadratzahlen von 1 bis n mithilfe einer for-Schleife und gibt die finale Summe als Ergebnis zurück.
	Wenn pAufgabenteil keinem Element der Menge {1,2} entsprechen sollte gibt die Methode -1 zurück, was sich eindeutig als Fehlermeldung identifizieren lässt,
	da die obigen Operationen, dem Datentyp von pEingabe geschuldet, nur positive Ergebnisse liefern können.

*/

int aufgabe2(unsigned int pEingabe, int pAufgabenteil){
	
	if(pAufgabenteil == 1)	return (pEingabe * (pEingabe + 1)) / 2;
	else if(pAufgabenteil == 2) {
		int sum = 0;
		for(int i = 1; i*i <= pEingabe;i++){
			sum += i*i;
		} 
		return sum;
	}
	return -1;
	
}

/**
	Die Methode aufgabe 3 überprüft ob eine Zahl pEingabe eine Primzahl ist. Hierzu wird die Eingabe zunächst auf Negativität geprüft, welche eine Fehlermeldung (-1) auslösen würde.
	Daraufhin, werden die Sonderfälle 0, 1 abgefragt, da diese zwar keine Primzahlen sind, von folgender Formel aber als solche erkannt werden würden. Da sie keine Primzahlen sind
	entspräche der Rückgabewert hier 1, welchen ich in dieser Methode als false benutze.
	Nun folgt die eben erwähnte Formel, welche die Eingabe auf folgende Vorraussetzung testet:
	
	Eine Zahl x ist genau dann eine Primzahl, wenn keine Zahl k < sqrt(x) existiert für die gilt: x % k == 0 
*/

int aufgabe3(int pEingabe){
	if(pEingabe < 0) return -1;
	else if(pEingabe == 0 || pEingabe == 1) return 1;
	double sqr = sqrt(pEingabe);
	for(int i = 2; i =< sqr;i++){
		if(pEingabe % i == 0) return 1;
		
	}
	return 0;
}

int main(void){
	/*
		Ausgabenblock zum Test der Methoden:
	
		int a210 = aufgabe2(0, 1);
		int a214 = aufgabe2(4, 1);
		int a220 = aufgabe2(0, 2);
		int a224 = aufgabe2(4, 2);
	
		int a3f = aufgabe3(-1);
		int a31 = aufgabe3(1);
		int a32 = aufgabe3(2);
		int a38 = aufgabe3(8);
		int a313 = aufgabe3(13);
	
		printf("Aufgabe 2.1 mit 0:%i\n", a210);
		printf("Aufgabe 2.1 mit 4:%i\n\n\n\n",a214);
		printf("Aufgabe 2.2 mit 0:%i\n",a220);
		printf("Aufgabe 2.2 mit 4:%i\n\n\n\n",a224);
		printf("Aufgabe 3 mit -1:%i\n",a3f);
		printf("Aufgabe 3 mit 1:%i\n",a31);
		printf("Aufgabe 3 mit 2:%i\n",a32);
		printf("Aufgabe 3 mit 8:%i\n",a38);
		printf("Aufgabe 3 mit 13:%i\n",a313);
	
	*/
	return 1;
}