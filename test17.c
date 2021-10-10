//testing hopen in hash.c

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <inttypes.h> 
#include <stdbool.h>
#include "hash.h"

#define TABLESIZE 10 

car_t *make_car(char *plate,double price,int year)  { 
	car_t *pp;
	if(!(pp = (car_t*)malloc(sizeof(car_t)))) {
		printf("[Error: malloc failed allocating car]\n");
		return NULL;
	}
	pp->next = NULL;
	strcpy(pp->plate,plate);
	pp->price=price;
	pp->year=year;
	return pp;
}


int main(void){


    exit(EXIT_FAILURE); 
}
