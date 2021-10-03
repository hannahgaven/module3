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

#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <stdint.h>
#include <string.h>

void printing(car_t *cp){

	printf("prints plate: %s", cp->plate);
}
int main(){

	car_t *p = malloc(sizeof(car_t));
	strcpy(p->plate, "ABC");
	
	lput(p);
	lapply(printing);

	// free memory
	free(p);
	return 0;
}