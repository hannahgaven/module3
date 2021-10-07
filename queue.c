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
    }
}


int32_t qput(queue_t *qp, void *elementp){
    rq_t *rqp = (rq_t *)qp; 
    relement_t *rep = (relement_t *)elementp; 
		relement_t *end = rqp->back;
		relement_t *new;
		
		if(rqp ==NULL){
		  new = make_element(rqp->front,rep);
			rqp->back= new;
		}else{
			relement_t *end = rqp->back; 
			new = make_element(end->next,rep); 
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
	}
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

}

