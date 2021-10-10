

/* 
 * hash.c -- implements a generic hash table as an indexed set of queues.
 *
 */
#include <stdint.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

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
    hashelement_t* elements; 
    int size; 
    int count; 
}hashtable_t; 

hashelement_t *make_element(char* key, char* value){
    hashelement_t* element = (hashelement_t*)malloc(sizeof(hashelement_t)); 
    element->key = (char*)malloc(strlen(key)); 
    element->value = (char*)malloc(strlen(value)); 
    strpcpy(element->key,key); 
    strcpy(element->value,value); 
    
    return element; 
}

hashtable_t *hopen(uint32_t hsize) {
    hashtable_t* table = (hashtable_t*)malloc(sizeof(hashtable_t)); 
    table->size = hsize; 
    table->count = 0; 
    table->elements = (hashelement_t*)malloc(table->size, sizeof(hashelement_t)); 
    for (int i=0; i <table->size; i++){
      table->elements[i] = NULL; 
    }

    return table; 
}

void hclose(hashtable_t *htp) {

}

int32_t hput(hashtable_t *htp, void *ep, const char *key, int keylen) {

}

void happly(hashtable_t *htp, void (*fn)(void* ep)) {
    hashtable_t *htp = (hashtable_t*)hp; 
    
    for (int i=0; i <hp->size; i++){
        hashtable_element_t *currentp = hp->elements[i]; 
        fn(currentp); 
    }

}

void *hsearch(hashtable_t *htp, bool (*searchfn)(void* elementp, const void* searchkeyp), const char *key, nt32_t keylen) {
    hashtable_t *htp = (hashtable_t*)hp; 
    
    for (int i=0; i <hp->size; i++){
        hashtable_element_t *currentp = hp->elements[i]; 
        if(searchfn((void *)currentp,currentp->key)){
          prinf("Element found!"); 
          return(void *)currentp; 
        }
    }

    return NULL; 
} 


void *hremove(hashtable_t *htp, bool (*searchfn)(void* elementp, const void* searchkeyp), const char *key, int32_t keylen) {
      hashtable_t *htp = (hashtable_t*)hp; 

      if (hp == NULL) {
        return NULL; 
      }

      for (int i=0; i <hp->size; i++){
        hashtable_element_t *currentp = hp->elements[i]; 
        if (searchfn(currentp->key, key){
          prinf("Element found! Removing it\n"); 
          return currentp->key; 
        }
        else{
          printf("Element does not match key\n"); 
          return NULL; 
        }
      }
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


