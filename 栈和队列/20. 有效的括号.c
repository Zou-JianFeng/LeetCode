#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    char *data;
    int top, size; 
} Stack;

Stack *init(int n) {
    Stack *k = (Stack *)malloc(sizeof(Stack));
    k->data = (char *)malloc(sizeof(char) * n);
    k->top = -1;
    return k;
}

int push(Stack *k, char s) {
    k->top++;
    k->data[k->top] = s;
    return 1;
}

char top(Stack *k) {
   return k->data[k->top]; 
}

int empty(Stack *k) {
    return k->top == -1;
}

void clear(Stack *k) {
    free(k->data);
    free(k);
}

bool isValid(char* s) {
    int n = strlen(s);

    Stack *k = init(n);
    
    while(*s) {
        switch (*s) {
            case '(': {
                push(k, *s);
                break;
            }
            case ')': {
                if(empty(k)) return false;
                else if (top(k) == '(') k->top--;
                else push(k, *s);
                break;
            }  
            case '{': {
                push(k, *s);    
                break;  
            }
            case '}': {
                if(empty(k)) return false;
                else if (top(k) == '{') k->top--;
                else push(k, *s);
                break;
            }
            case '[': {
                push(k, *s);
                break; 
            }
            case ']': {
                if(empty(k)) return false;
                else if (top(k) == '[') k->top--;
                else push(k, *s);
                break;
            }
        }
        *s++;
    }
    if (empty(k)) return true;
    else return false;
}