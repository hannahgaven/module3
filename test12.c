
#include <bool.h> 
#include "queue.h" 

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

bool searchfn (void *elementp, const void *keyp){

    if(*elementp->element == keyp){
        return TRUE; 
    }
    else{
        return FALSE; 
    }

}

int main(void){
    car_t *queuep = qopen(); 
    car_t *p1 = make_car("1",3000,2005);
    car_t *p2 = make_car("2",2000,2000);
    car_t *p3 = make_car("3",4000,2006);
    car_t *p4 = make_car("4",3500,2008);
    car_t *p5 = make_car("5",1200,2001);

    

    qput(queue,p1); 
    qapply(p1,(void*)*printcar((void *)p1)); 
    car_t *result = qsearch(queue,searchfn, "1"); 
    printcar(*result); 

    free(p1); 
    free(p2); 
    free(p3); 
    free(p4); 
    free(p5); 
    exit(EXIT_SUCCESS); 
}

