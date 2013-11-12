#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void b_sort(int tablica[10], int ile_liczb)
{
	int temp,i,zmiana;
	do
	{
		zmiana=0;
		i=ile_liczb-1;
		do
		{
			i--;
			if (tablica[i+1]< tablica[i])
			{
				temp=tablica[i];
				tablica[i]=tablica[i+1];
				tablica[i+1]=temp;
				zmiana=1;
			}
		}
		while (i!=0);
	}
	while (zmiana!=0);
	 
	printf("\nTablica po posortowaniu:");
	for(i=0; i<ile_liczb; i++) printf("\n%i",tablica[i]);
}
void main(void)
{
	int ile_liczb,i,liczba;
	int tablica[10];
	clrscr();
	printf("Ile liczb chesz posortowac (do 10) ? ");
	scanf("%i",&ile_liczb);
	for(i=0; i<ile_liczb; i++)
	{
		printf("Wprowadz liczbe #%i: ",i+1);
		scanf("%i",&liczba);
		tablica[i]=liczba;
	}
	clrscr();
	printf("Tablica przed posortowaniem:");
	for(i=0; i<ile_liczb; i++) printf("\n%i",tablica[i]);
	b_sort(tablica,ile_liczb);
	printf("\nDowolny klawisz...");
	getch();
}
