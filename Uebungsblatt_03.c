#include<stdio.h>

void aufgabe2();
void aufgabe3();
double arithmetisches_Mittel(double* pArr, int pLength);
double korr_Stichprvar(double* pArr, int pLength);

int main(void){
	//aufgabe2();
	aufgabe3();

    int keepTheTerminalAlive = 0;
    scanf("%i", &keepTheTerminalAlive);
	return 1;
}

double arithmetisches_Mittel(double* pArr, int pLength){
	double result = 0;
	double tmp = 0;
	for( int i = 0; i < pLength; i++) tmp += pArr[i];
	result = tmp/pLength;
	return result;
}

double korr_Stichprvar(double* pArr, int pLength){
	double result = 0;
	double tmp = 0;
	double arithMittel = arithmetisches_Mittel(pArr, pLength);
	for( int i = 0; i < pLength; i++) tmp += (pArr[i] - arithMittel) * (pArr[i] - arithMittel);
	result = tmp/(pLength - 1);
	return result;
}

void aufgabe2(){
	printf("Wie gro\xE1 \b soll die Stichprobe sein?\n");
	int n = 0;
	scanf("%i", &n);

	double arr[100];
	printf("Geben sie die Werte nacheinander ein\n");
	for(int i = 0; i < n; i++) scanf("%le", arr + i );

	printf("Sie haben folgende Daten mitgegeben:\n		[");
	for(int i = 0; i < (n - 1); i++) printf("%le, ", arr[i]);
	printf("%le]\n", arr[(n-1)]);

	printf("Das arithmetische Mittel beträgt folglich: %le\n", arithmetisches_Mittel(arr, n));
	printf("Und die korrigierte Stichprobenvarianz: %le\n", korr_Stichprvar(arr, n));
}

void aufgabe3(){
    int toWrite = 0;
    while(toWrite < 20 || toWrite > 69){
        printf("Welche Zahl wollen Sie schreiben? ");
        scanf("%i", &toWrite);

        if(toWrite < 20 || toWrite > 69)
                printf("Diese Zahl ist leider au\xE1 \berhalb des Wertebereichs.\n\n");
    }

    printf("Die Zahl %i wird folgenderma\xE1 \ben geschrieben: ", toWrite);

    switch(toWrite % 10) {
	case 0:
            break;
    case 1:
            printf("ein-und-");
            break;
    case 2:
            printf("zwei-und-");
            break;
    case 3:
            printf("drei-und-");
            break;
    case 4:
            printf("vier-und-");
            break;
    case 5:
            printf("fünf-und-");
            break;
    case 6:
            printf("sechs-und-");
            break;
    case 7:
            printf("sieben-und-");
            break;
    case 8:
            printf("acht-und-");
            break;
    case 9:
            printf("neun-und-");
            break;
	default:
            printf("ERROR");
            return;
            break;
    }


    switch(toWrite / 10) {
	case 2:
            printf("zwanzig\n");
            break;
	case 3:
            printf("drei\xE1 \big\n");
            break;
    case 4:
            printf("vierzig\n");
            break;
    case 5:
            printf("fünfzig\n");
            break;
    case 6:
            printf("sechzig\n");
            break;
    default:
            printf("ERROR");
            return;
            break;
    }	
}

int Aufgabe_4(){
	float x[5] = { 10000.0f , -0.001f / 9.0f , 2500.0f , 0.001f / 7.0 , -12500.0f };
	double y[5] = { 10000.0 , -0.001 / 9.0 , 2500.0 , 0.001 / 7.0 , -12500.0 };
	float f_summe = x[0] + x[1] + x[2] + x[3] + x[4];
	//Output: 0.000000
	printf("Float Summe: %f\n", f_summe);
	double d_summe = y[0] + y[1] + y[2] + y[3] + y[4];
	//Output: 0.000032
	printf("Double Summe %f\n", d_summe);
	float s = 0.0, sAlt = 0.0, d = 0.0f;
	for (unsigned int i = 0; i < 5; i++)
	{
		sAlt = s;
		s += x[i];
		d += (x[i] - (s - sAlt));
		s += d;
	}
	//Output: 0.000032
	printf("s = %f\n", s);
	double s2 = 0.0f, sAlt2 = 0.0f, d2 = 0.0f;
	for (unsigned int i = 0; i < 5; i++)
	{
		sAlt2 = s2;
		s2 += y[i];
		d2 += (y[i] - (s2 - sAlt2));
		s2 += d2;
	}
	//Output: 0.000032
	printf("s2 = %f", s2);	
}
