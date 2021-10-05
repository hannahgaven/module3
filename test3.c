/* test3.c --- test get() from an empty list
 * 
 * 
 * Author: Julia Martin 
 * Created: Fri Oct  1 11:51:24 2021 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void printcar(car_t *cp) {
	printf("Plate : %s, Price: %f, Year: %d\n", cp->plate, cp->price, cp->year);
}

int main(void) {
	char *plate = "5";
	lget();
	lapply(printcar);
	exit(EXIT_SUCCESS);
}