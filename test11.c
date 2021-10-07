/* test1.c --- 
 * 
 * 
 * Author: Ezgi Okutan
 * Created: Thu Sep 30 21:34:08 2021 (-0400)
 * Version: 
 * 
 * Description: This is a test file that tests if we can put to an empty list
 * 
 */

/* test1.c --- 
 * 
 * 
 * Author: Ezgi Okutan
 * Created: Thu Sep 30 21:20:51 2021 (-0400)
 * Version: 
 * 
 * Description: This is a test file. It tests if we can put to an empty list 
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "queue.h"

#define MAXREG 10

typedef struct car {
	struct car *next;
	char plate[MAXREG];
	double price;
	int year;
} car_t;


static void printcar(car_t *cp) {
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
  car_t *queuep= qopen();
	car_t *p1 = make_car("1",3000,2005);

  qput(queuep,p1);
  qapply(p1,(void *)*printcar((void *)p1));

	// free memory
	free(p1);
	exit(EXIT_SUCCESS);
}
