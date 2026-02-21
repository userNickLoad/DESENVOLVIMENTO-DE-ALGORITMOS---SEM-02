#include "numeros.h"

int is_pair(int a){
	return a % 2 == 0;
};

int is_cousin(int a){
	int result, i;
	
	for (i = 2; i < a; i++){
		if(result % i) return 0;
	}
	
	return 1;
};

int fatorial(int a){
	int acc = 1, i;
	
	for (i = 2; i <= a; i++){
		acc *= i;
	}
	
	return acc;
	
};

int whos_bigger(int a, int b){
	
	return a > b;
	
};

int pow(int a, int e){
	
	int acc, i;
	
	for(i = 2; i <= e; i++){
		acc *= a;
	}
	
	return acc;
	
};
