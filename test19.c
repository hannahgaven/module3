//testing hremove empty hash in hash.c

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

bool searchplate (void *elementp, const void *keyp){
	car_t* car = elementp; 
	printf("plate: %s\n", car->plate); 
	if(strcmp(car->plate, keyp) == 0) {
		return true;
	} 
	return false; 
}


int main(void){
	hashtable_t* table = hopen(TABLESIZE); 

	
	happly(table, printcar); 


	void* result = hremove(table,searchplate, "truck", strlen("truck")); 
	happly(result, printcar);     


	void* result2= hsearch(table, searchplate, "truck", strlen("truck"));
	happly(result2, printcar);       

	if(result!=NULL && result2!=NULL){
		hclose(table);
		free(result);
		free(result2);
		//	free(p1);
		//	free(p2);
		//	free(p3);
		exit(EXIT_SUCCESS);
	}
	free(result);
	hclose(table); 

	
    exit(EXIT_FAILURE); 
}
