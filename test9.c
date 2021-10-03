/* test9.c --- remove() from a non-empty list at the beginning
 * 
 * 
 * Author: Hannah M. Gaven
 * Created: Fri Oct  1 12:00:09 2021 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */

#include "list.h"
#include <stdlib.h>

car_t *front=NULL;


int main(void) {
	void *cp = malloc(5);
	car_t *pp = (car_t*)malloc(sizeof(car_t));
	car_t *p1 = make_car(12345,3000,2005);
	car_t *p2 = make_car(12346,3002,2006);
	car_t *p3 = make_car(12347,3004,2007);
	car_t *p3 = make_car(12348,3006,2008);
	car_t *p3 = make_car(12349,3008,2009);
	front=p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	lremove(12345);
}


car_t *make_car(char *platep,double price,int year)  { 
	car_t *pp;
	if(!(pp = (car_t*)malloc(sizeof(car_t)))) {
		printf("[Error: malloc failed allocating car]\n");
		return NULL;
	}
	pp->next = NULL;
	strcpy(pp->plate,platep);
	pp->price=price;
	pp->year=year;
	return pp;
}
