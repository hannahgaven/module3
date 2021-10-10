

/* 
 * hash.c -- implements a generic hash table as an indexed set of queues.
 *
 */
#include <stdint.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "queue.h"
#include "hash.h"

/* 
 * SuperFastHash() -- produces a number between 0 and the tablesize-1.
 * 
 * The following (rather complicated) code, has been taken from Paul
 * Hsieh's website under the terms of the BSD license. It's a hash
 * function used all over the place nowadays, including Google Sparse
 * Hash.
 */
#define get16bits(d) (*((const uint16_t *) (d)))


typedef struct hashstruct_element { 
    char* key; 
    char* value; 
}hashelement_t; 


typedef struct hashstruct_table {
    queue_t** queues; 
    int size; 
    int count; 
}ht_t; 

hashelement_t *make_element(char* key, char* value){
    //hashelement_t* element = (hashelement_t*)malloc(sizeof(hashelement_t)); 
    element->key = (char*)malloc(strlen(key)); 
    element->value = (char*)malloc(strlen(value)); 
    strpcpy(element->key,key); 
    strcpy(element->value,value); 
    
    return element; 
}

hashtable_t* hopen(uint32_t hsize) {
    ht_t* table = (ht_t*)malloc(sizeof(ht_t)); 
    table->size = hsize; 
    table->count = 0; 
    table->queues = (queue_t**)malloc(table->size, sizeof(queue_t*)); 
    for (int i=0; i <table->size; i++){
      table->queues[i] = qopen(); 
    }
    return table; 
}

void hclose(hashtable_t *htp) {
    ht_t *hp = (ht_t*)htp;
    for (int i=0; i <hp->size; i++){
      qclose(hp->queues[i]); 
    }
  free(hp);
}

int32_t hput(hashtable_t *htp, void *ep, const char *key, int keylen) {
    ht_t *hp = (ht_t*)htp;
    if(table == NULL){
      return 1; 
    }
    //get the index using SuperFastHash (const char *data,int len,uint32_t tablesize)
    i = SuperFastHash((char *)ep, keylen, htp->size);
    qput(hp->queues[i], ep); 
    //put in using qput
    return 0; 
}

void happly(hashtable_t *htp, void (*fn)(void* ep)) {
    ht_t *hp = (ht_t*)htp; 
    for (int i=0; i <hp->size; i++){
      qapply(hp->queues[i], fn); 
    }

}

void *hsearch(hashtable_t *htp, bool (*searchfn)(void* elementp, const void* searchkeyp), const char *key, int32_t keylen) {
    ht_t *hp = (ht_t*)htp; 
    
    key_index = SuperFastHash((char *)ep, keylen, htp->size);
    
    if(qsearch(hp->queues[key_index], searchfn, key)){
      return (void*) qsearch(hp->queues[key_index], searchfn, key);     
    }
      return NULL; 
} 


void *hremove(hashtable_t *htp, bool (*searchfn)(void* elementp, const void* searchkeyp), const char *key, int32_t keylen) {
      ht_t *hp = (ht_t*)htp; 
      key_index = SuperFastHash((char *)ep, keylen, htp->size);

      if(qremove(hp->queues[key_index], searchfn, key)){
      return (void*) qremove(hp->queues[key_index], searchfn, key);     
    }
      return NULL; 

} 
      

static uint32_t SuperFastHash (const char *data,int len,uint32_t tablesize) {
  uint32_t hash = len, tmp;
  int rem;
  
  if (len <= 0 || data == NULL)
    return 0;
  rem = len & 3;
  len >>= 2;
  /* Main loop */
  for (;len > 0; len--) {
    hash  += get16bits (data);
    tmp    = (get16bits (data+2) << 11) ^ hash;
    hash   = (hash << 16) ^ tmp;
    data  += 2*sizeof (uint16_t);
    hash  += hash >> 11;
  }
  /* Handle end cases */
  switch (rem) {
  case 3: hash += get16bits (data);
    hash ^= hash << 16;
    hash ^= data[sizeof (uint16_t)] << 18;
    hash += hash >> 11;
    break;
  case 2: hash += get16bits (data);
    hash ^= hash << 11;
    hash += hash >> 17;
    break;
  case 1: hash += *data;
    hash ^= hash << 10;
    hash += hash >> 1;
  }
  /* Force "avalanching" of final 127 bits */
  hash ^= hash << 3;
  hash += hash >> 5;
  hash ^= hash << 4;
  hash += hash >> 17;
  hash ^= hash << 25;
  hash += hash >> 6;
  return hash % tablesize;
}


