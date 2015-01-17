/**
	Zadanie 2: Trzy podzbiory.
	Autor: Michał Zagórski

	Rozwiązanie wzorcowe.

	Złożoność rozwiązania: O(3^n)

	Opis rozwiązania:
		Algorytm polega na stworzeniu wszyskich możliwych podziałów
		multizbioru liczb na trzy podzbiory poprzez przypisanie numeru
		podzbioru każdemu elementowi. Następnie, po przypisaniu wszystkch
		elementów sprawdzany jest warunek: równość ilości jedynek potrzebnych
		do zapisu elementów w systemie dwójkowym.

		Funkcja ones_count zwraca ilość jedynek potrzebnych do zapisu elementu
		w systemie dwójkowym

		Funkcja sets_division przypisuje każdy element kolejno do pierwszego,
		drugiego i trzeciego zbioru, przy okazji wywołując się do kolejnego
		elementu. Warunkiem zakończenia rekurencji jest dojście do końca
		tablicy elementów zbioru. Ostatnia instancja zwraca 1, gdy jest to
		oczekiwany podział lub 0 w przeciwnym wypadku. 
**/

#include <cstdio>

int ones_count(int a);
int sets_division(int ones[], int sets[], int i, int n);

int main(void){
	int n;
	scanf("%d", &n);
	int *ones = new int[n];
	int tmp = 0;
	int sum = 0;
	int *sets = new int[n];
	for(int i = 0;i < n; i++){
		scanf("%d", &tmp);
		ones[i] = ones_count(tmp);
		sets[i] = 0;
	}
	int result = 0;
		result = sets_division(ones, sets, 0, n);
		result = result/6;
/*	Dzielę wynik przez liczbę permutacji tego samego podziału na trzy podzbiory */
	printf("%Ld\n", result);
	delete[] ones;
	delete[] sets;
	return 0;
}

int ones_count(int a){
	int result = 0;
	while(a > 0){
		result += a%2;
		a /= 2;
	}
	return result;
}

int sets_division(int ones[], int sets[], int i, int n){
	/* sets_division(ones, sets, 0, n) */
	if(i == n){
		int set1 = 0, set2 = 0, set3 = 0;
		for(int j = 0;j < n; j++){
			if(sets[j] == 1){
				set1 += ones[j];
			}
			if(sets[j] == 2){
				set2 += ones[j];
			}
			if(sets[j] == 3){
				set3 += ones[j];
			}
		}
		if(set1 == set2 and set2 == set3){
			return 1;
		}
		else{
			return 0;
		}
	}
	int result = 0;
	sets[i] = 1;
	result += sets_division(ones, sets, i+1, n);
	sets[i] = 2;
	result += sets_division(ones, sets, i+1, n);
	sets[i] = 3;
	result += sets_division(ones, sets, i+1, n);
	return result;
}