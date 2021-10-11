//testing hopen in hash.c

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <inttypes.h> 
#include <stdbool.h>
#include "hash.h"
#include "queue.h"

#define TABLESIZE 10 
#define MAXREG 10 


typedef struct car {
	struct car *next;
	char plate[MAXREG];
	double price;
	int year;
} car_t;

static void printcar(void *p) {
	car_t* cp = (car_t *)p;
	printf("Plate : %s, Price: %f, Year: %d\n", cp->plate, cp->price, cp->year);
}

car_t *front=NULL; 

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
	car_t *car1 = hopen(TABLESIZE); 

	car_t *p1 = make_car("1", 1500, 2002); 
	//car_t *p2 = make_car("2", 2000, 2000);
	//car_t *p3 = make_car("3", 3000, 2008);
	hput(car1, (void *)p1, "vehicle", strlen("vehicle")); 

	printf("Printing cars now\n"); 
	happly(car1, printcar); 
	
	hclose(car1); 

    exit(EXIT_SUCCESS); 
}
