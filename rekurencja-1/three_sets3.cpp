/**
	Zadanie 2: Trzy podzbiory.
	Autor: Michał Zagórski

	Rozwiązanie bez użycia drugiej tablicy.

	Złożoność rozwiązania: O(3^n)

	Opis rozwiązania:
		W algorytmie liczymy sumy jedynek w potencjalnych podzbiorach.

		Funkcja ones_count zwraca ilość jedynek potrzebnych do zapisu elementu
		w systemie dwójkowym

		Funkcja sets_division przpisuje zmiennym set1, set2, set3 sumę jedynek elementów
		zawartych w odpowiednich zbiorach. W funkcji sprawdzany jest porządek zbiorów oraz warunek,
		że liczba jedynek w każdym zbiorze nie przekracza 1/3 całości, dzięki temu funkcja wywołuje się mniej razy. 
		Warunkiem zakończenia rekurencji jest dojście do końca
		tablicy elementów zbioru. Ostatnia instancja zwraca 1, gdy jest to
		oczekiwany podział lub 0 w przeciwnym wypadku. 
**/

#include <cstdio>

int ones_count(int a);
int sets_division(int ones[], int i, int n,int sum, int set1, int set2, int set3, bool flag1, bool flag2);

int main(void){
	int n;
	scanf("%d", &n);
	int *ones = new int[n];
	int tmp = 0;
	int sum = 0;
	for(int i = 0;i < n; i++){
		scanf("%d", &tmp);
		ones[i] = ones_count(tmp);
		sum = sum+ones[i];
	}
	int result = 0;
	if(sum%3 == 0){
		result = sets_division(ones, 0, n, sum, 0, 0, 0, false, false);
	}
	printf("%Ld\n", result);
	delete[] ones;
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
int compare(int a, int b, int c){
	return (a == b && a == c) ? 1 : 0 ;
}
int sets_division(int ones[], int i, int n, int sum, int set1, int set2, int set3, bool flag1, bool flag2){
	/* sets_division(ones, 0, n, sum, 0, 0, 0, false, false) */
	if(i == n){
		return compare(set1, set2, set3);
	}
	int result = 0;
	if(set1 <= (sum/3)){
		result += sets_division(ones, i+1, n, sum, set1+ones[i], set2, set3, true, flag2);
		if(flag1 && (set2 <= (sum/3))){
			result += sets_division(ones, i+1, n, sum, set1, set2+ones[i], set3, flag1, true);
			if(flag2 && (set3 <= (sum/3))){
				result += sets_division(ones, i+1, n, sum, set1, set2, set3+ones[i], flag1, flag2);
			}
		}
	}
	return result;
}