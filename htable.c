#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "htable.h"
#include "mylib.h"

struct htablerec {
  int capacity;
  int num_keys;
  char **keys;
};

static unsigned int htable_word_to_int(char *word) {
  unsigned int result = 0;

  while (*word != '\0') {
     result = (*word++ + 31 * result);
  }
  return result;
}

static unsigned int htable_hash(htable h, unsigned int i_key) {
  return i_key % h->capacity;
}

htable htable_new(int capacity) {
    int i;
    htable result = emalloc(sizeof *result);
    result->capacity = capacity;
    result->num_keys = 0;
    result->keys = emalloc(result->capacity * sizeof result->keys[0]);
    for(i = 0; i < result->capacity; i++){
        result->keys[i] = 0;
    }
    return result;
}

void htable_free(htable h) {
    int i;
    for(i = 0; i < h->num_keys; i++){
        free(h->keys[i]);
    }
    free(h->keys);
    free(h);
}

int htable_insert(htable h, char *key) {
    int n = htable_word_to_int(key) % h->capacity;
    int c = 0;

    while(c < h->capacity){
        if(h->keys[n] == 0){
            h->keys[n] = emalloc((strlen(key)+1) * sizeof h->keys[0][0]);
            strcpy(h->keys[n], key);
            h->num_keys++;
            return 1;
        }
        if(strcmp(h->keys[n], key) == 0){
            return 0;
        }
        c++;
        n = htable_hash(h, n+1);
    }
    return 0;

}

void htable_print(htable h, FILE *stream) {
    int i;
    for (i = 0; i < h->capacity; i++) {
        fprintf(stream, "%2d %s\n", i, h->keys[i] == NULL ? "" : h->keys[i]);
    }
}
