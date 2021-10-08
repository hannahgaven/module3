/* queue.c --- Implements queue functions
 * 
 * 
 * Author: Hannah M. Gaven
 * Created: Fri Oct  1 14:52:14 2021 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "queue.h"     

/* creates a structure of the "real element type"
which is the element within the real queue; each element has a next 
pointer (which points to the next element in the queue) and has a pointer 
to the information/structure stored in this element, which is void 
*/

typedef struct relementstruct{
    struct relementstruct *next; 
    void *element; 
} relement_t;

typedef struct rq {
    relement_t *front; 
    relement_t *back; 
}rq_t;

relement_t *make_element(relement_t *next_el, void *el){
    relement_t *rep; 
    rep = (relement_t *)malloc(sizeof(relement_t)); 
    rep->next = next_el; 
    rep->element = el; 
    return rep; 
}



queue_t* qopen(void){
	//this is so not right lmao
	//if malloc fails, it should return NULL, p arrow front undefined
	rq_t* p = (rq_t*)malloc(sizeof(rq_t));
	if (!(p = (rq_t*)malloc(sizeof(rq_t)))){
		printf("Error!");
		return NULL;
	}else{
		p->front = NULL; 
		p->back = NULL; 
		return (queue_t *)p; 
	}
}

void qclose(queue_t *qp){
    rq_t *rqp = (rq_t *)qp;
    relement_t *p = rqp->front;
    while(p != rqp->back) {
        relement_t *temp = p->next;
        //need to free void element pointer
        void *el = p->element; 
        free(el); 
		free(p);
        p=temp;
		free(temp);
    }
	free(rqp);
}


int32_t qput(queue_t *qp, void *elementp){
    rq_t *rqp = (rq_t *)qp; 
    //relement_t *rep = (void *)elementp; 
		relement_t *end = rqp->back;
		relement_t *new;
		
		if(rqp->back ==NULL){
		  new = make_element(rqp->front,elementp);
			rqp->back= new;
			rqp->front=new;
		}else{
			relement_t *end = rqp->back; 
			new = make_element(end->next,elementp); 
			end->next= new;
			rqp->back= end->next;
		}
		if(end != new){
				return 1;
			}
		return 0;
}

void* qget(queue_t *qp){
    rq_t *rqp = (rq_t *)qp;
    relement_t *p = rqp->front;
    relement_t *pp = NULL;

	if(p!= NULL){
		pp= p;
		p=p->next;
		rqp->front=p;
		//free(p->element);
		//free(p->next);
	}
	else {
		pp=p;
		return (void *)pp;
	}
	//free(p);
	return (void *)pp->element;
}

void qapply(queue_t *qp, void (*fn)(void* elementp)){
	rq_t *rqp = (rq_t *)qp;
	relement_t *elementp = rqp->front;
	
	while (elementp!=NULL){
		fn(elementp->element);
		elementp=elementp->next;
	}
}

void* qsearch(queue_t *qp, bool (*searchfn)(void* elementp,const void* keyp),const void* skeyp){
	rq_t *rqp = (rq_t *)qp;
	relement_t *elementp = rqp->front;
	int k=0;
	
	while(elementp!=NULL){
		if (searchfn(elementp->element, skeyp)==1){
			printf("Element found!");
			k=1;
			return(elementp); 
		}
		elementp=elementp->next;  
	}

	if (k!=1){
		return NULL;
	}
	return(elementp);   
}

void* qremove(queue_t *qp,bool (*searchfn)(void* elementp,const void* keyp),const void* skeyp) {
	rq_t *rqp = (rq_t *)qp;											 
	relement_t *elementp = rqp->front;
  relement_t *p = (relement_t*)malloc(sizeof(relement_t));
	int k=0;
	
	 if (!(p = (relement_t*)malloc(sizeof(relement_t)))){
		 printf("Error!");
		 return NULL;  
	 }
	 if (qp== NULL){
		 return NULL;
	 }
	 
	 while(elementp!=NULL){
		 if (searchfn(elementp->element, skeyp)==1){                                                                               
			 printf("Element found!Removing it");
			 p= elementp;
			 rqp->front= elementp->next;
			 k=1;
		 }                                                                                                                         
    elementp=elementp->next;                                                                                                   
	 }
	 
	 if (k!=1){
		 return NULL;                                                                                            
	 }
	 return((void*)p);
}

void qconcat(queue_t *q1p, queue_t *q2p){
	rq_t *rqp1 = (rq_t *)q1p; 
	rq_t *rqp2 = (rq_t *)q2p; 
	relement_t *back1 = rqp1->back; 

	if (rqp1->front == NULL) {
		rqp1->front = rqp2->front; 
		rqp1->back = rqp2->back;
		rqp1->front = NULL; 
		rqp2->back = NULL;
	}
	else if (rqp2->front != NULL) { 
		back1->next = rqp2->front;
		rqp1->back = rqp2->back; 
		rqp2->front = NULL; 
		rqp2->back = NULL; 
		qclose(rqp2); 
	}
<<<<<<< HEAD

	}
=======
}
>>>>>>> f2c294e073aa941fb35d3daf30cc8c18d3631486

