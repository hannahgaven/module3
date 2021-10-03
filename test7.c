/* test7.c --- test remove() from an empty list
 * 
 * 
 * Author: Hannah M. Gaven
 * Created: Fri Oct  1 11:51:24 2021 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */

#include "list.h"
#include <stdlib.h>

int main(void) {
	char *plate = "555555";
	lremove(plate);
	exit(EXIT_SUCCESS);
}
