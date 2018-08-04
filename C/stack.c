#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct Stack {
  int val;
  struct Stack *next;
} stack;


void push(stack **h,int val) {
  stack *s = malloc(sizeof(stack));
  s->val = val;
  s->next = *h;
  *h = s;
}

int pop(stack **h) {
  int val;
  stack *current;
   if (h == NULL) {
     return 0;
   }
   else {
     val = (*h)->val;
     current = *h;
     *h = (*h)->next;
     free(current);
     return val;
   }
}
//main function
int main() {
    stack *s = NULL;
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    printf("pop:\n");
    printf("%d\n", pop(&s));
    printf("%d\n ", pop(&s));
    return 0;
}
