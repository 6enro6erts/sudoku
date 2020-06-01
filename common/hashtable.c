/*
 * hashtable.c - CS50 hashtable module
 *
 * see hashtable.h for more information
 *
 * Ben Roberts, CS50, April 25, 2020
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"hashtable.h"
#include"jhash.h"
#include"set.h"

// file-local global variables
// none


// local types


// global types
typedef struct hashtable {
	struct set **array;
	int slots;
} hashtable_t;

// local functions
// prototypes
// none


// definitions
// hashtable_new - creates new hashtable
hashtable_t *hashtable_new(const int num_slots) {
	set_t **array = calloc(num_slots, sizeof(set_t*));
	if (array == NULL) {
		return NULL;
	}
	hashtable_t *new = malloc(sizeof(hashtable_t));
	if (new == NULL) {
		return NULL;
	}
	// initialize a pointer to an empty set in each slot of 
	// new array
	for (int i = 0; i < num_slots; i++) {
		array[i] = set_new();
	}
	new->array = array;
	new->slots = num_slots;
	return new;
}

// hashtable_insert - inserts key, item pair into hashtable
bool hashtable_insert(hashtable_t *ht, const char *key, void *item) {
	// copy key, set_new will do this also, so maybe unnecessary
	char * key_cp = (char *) calloc(strlen(key)+1, sizeof(char));            
        if (key_cp == NULL) {
                return false;                                                           
        }
	if (key == NULL) {
		free(key_cp);
		key_cp = NULL;
		return false;
	} 
	strcpy(key_cp, key);
	if (ht != NULL && item != NULL) {
		unsigned long idx = JenkinsHash(key_cp, (unsigned long) ht->slots);
		// if key already exists in hashtable, return false
		if ((set_find(ht->array[(int) idx], key_cp)) != NULL) {
			free(key_cp);
			key_cp = NULL;
			return false;
		}
		// if no key found, add the key, item pair
		set_insert(ht->array[(int) idx], key_cp, item);
		free(key_cp);
		key_cp = NULL;
		return true;
	}
	free(key_cp);
	key_cp = NULL;
	return false;
}

// hashtable_find - returns item given hashtable and key
void *hashtable_find(hashtable_t *ht, const char *key) {
	if (ht != NULL && key != NULL) {
		unsigned long idx = JenkinsHash(key, (unsigned long) ht->slots);
		// if no key found, return NULL
		if ((set_find(ht->array[(int) idx], key)) == NULL) {
			return NULL;
		}
		// if key found, return item
		return set_find(ht->array[(int) idx], key);
	}
	return NULL;

}

// hashtable_print - prints hashtable with slots on new lines
// and itemprint function handling how to print generic items
void hashtable_print(hashtable_t *ht, FILE *fp,
                     void (*itemprint)(FILE *fp, const char *key, void *item)) {
	if (fp != NULL) {
		if (ht == NULL) {
			fputs("(null)", fp);
		}
		else {
			// if itemprint is NULL, print empty slots
			if (itemprint == NULL) {
				for (int i = 0; i < ht->slots; i++) {
					fprintf(fp, "slot %d: \n", i);
				}
			}
			else {
				for (int i = 0; i < ht->slots; i++) {
					fprintf(fp, "slot %d: ", i);
					set_print(ht->array[i], fp, (*itemprint));	
					fputs("\n", fp);
				}
			}	

		}
	}
}

// hashtable_iterate - calls function itemfunc on all key, item pairs in hashtable
void hashtable_iterate(hashtable_t *ht, void *arg,
                       void (*itemfunc)(void *arg, const char *key, void *item) ) {
	if (ht != NULL && itemfunc != NULL) {
		for (int i = 0; i < ht->slots; i++) {
			set_iterate(ht->array[i], arg, (*itemfunc));
		}
	}	
}

// hashtable_delete – responsible for freeing outstanding memory
void hashtable_delete(hashtable_t *ht, void (*itemdelete)(void *item) ) {
	if (ht != NULL) {
		if (itemdelete != NULL) {
			for (int i = 0; i < ht->slots; i++) {
				set_delete(ht->array[i], (*itemdelete));
			}
			free(ht->array);
			ht->array = NULL;
			free(ht);
			ht = NULL;
		}
		else {
			for (int i = 0; i < ht->slots; i++) {
				set_delete(ht->array[i], NULL);
			}
			free(ht->array);
			ht->array = NULL;
			free(ht);
			ht = NULL;
		}
	}
}


