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

#include "queue.h"
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>

queue_t* qopen(void){

}

void qclose(queue_t *qp){

}

int32_t qput(queue_t *qp, void *elementp){

}

void* qget(queue_t *qp){

}

void qapply(queue_t *qp, void (*fn)(void* elementp)){

}

void* qsearch(queue_t *qp, bool (*searchfn)(void* elementp,const void* keyp),
const void* skeyp){

}

void* qremove(queue_t *qp,bool (*searchfn)(void* elementp,const void* keyp),
const void* skeyp) {

}

void qconcat(queue_t *q1p, queue_t *q2p){

}

