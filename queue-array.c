#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "queue.h"

struct queue {
    double *items;
    int head;
    int capacity;
    int num_items;
};

queue queue_new() {
    int i;
    int default_size = 7;
    queue result = emalloc(sizeof *result);
    result->head = 0;
    result->capacity = default_size;
    result->num_items = 0;
    result->items = emalloc(result->capacity * sizeof result->items[0]);
    for(i = 0; i < result->capacity; i++){
        result->items[i] = 0.0;
    }
    return result;
}

void enqueue(queue q, double item) {
   if (q->num_items < q->capacity) {
      q->items[(q->head + q->num_items++) % q->capacity] = item;
   }
}

double dequeue(queue q) {
    int rm = q->head;
    if(q->num_items > 0){
        q->num_items--;
        q->head++;
        return q->items[rm];
    } else {
        return 0.0;
    }
}

void queue_print(queue q) {
   /* print queue contents one per line to 2 decimal places */
    int i;
    if(q->num_items != 0){
    for(i = 0; i < q->num_items; i++){
        printf("%0.2f\n", q->items[(q->head + i) % q->capacity]);
    }}
}

void queue_print_info(queue q) {
   int i;
   printf("capacity %d, num_items %d, head %d\n[", q->capacity,
         q->num_items, q->head);
   for (i = 0; i < q->capacity; i++) {
      printf("%s%.2f", i == 0 ? "" : ", ", q->items[i]);
   }
   printf("]\n");
}

int queue_size(queue q) {
    return q->num_items;
}

queue queue_free(queue q) {
    free(q->items);
    free(q);
    return q;
}
