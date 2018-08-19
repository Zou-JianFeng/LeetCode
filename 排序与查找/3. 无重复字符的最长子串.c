typedef struct Queue {
    char *data;
    int head, tail, length, count;
} Queue;

Queue *init(int)
void clear(Queue *);
int push(Queue *, char);
char top(Queue *);
void pop(Queue *);
int empty(Queue *);

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s), ans = 0;
    if (n == 1)  return 1;
    Queue *q = init(n);
    for (int i = 0; i < n; i++) {
        for (int j = q->head; j <= q->tail; j++) {
            if (s[j] == s[i]) {
                if (q->count > ans) ans = q->count;
                for (int z = q->head; z <= j; z++) {
                    pop(q);
                }
                break;
            } 
        }
        push(q, s[i]);
        if (q->count > ans) ans = q->count;
        printf("%d ", q->count);
    }
    return ans;
}

Queue *init(int length) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (char *)malloc(sizeof(char) * length);
    q->head = 0;
    q->tail = -1;
    q->count = 0;
    q->length = length;
    return q;
}

int push(Queue *q, char s) {
    if (q->length == q->count) return 0;
    q->tail++;
    q->count++;
    q->data[q->tail] = s;
    return 1;
}

char top(Queue *q) {
    return q->data[q->head];
}

void pop(Queue *q) {
    if (empty(q)) return ;
    q->head++;
    q->count--;
    return ;
}

int empty(Queue *q) {
    return q->count == 0;
}

void clear(Queue *q) {
    if (q == NULL) return;
    free(q->data);
    free(q);
    return ;
}