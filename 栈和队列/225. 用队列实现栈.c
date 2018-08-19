typedef struct {
    int *data;
    int head, tail, size;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    obj->data = (int *)malloc(sizeof(int) * maxSize);
    obj->head = 0;
    obj->tail = -1;
    obj->size = maxSize;
    return obj;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    if (obj->tail + 1 == obj->size) return ;
    obj->tail++;
    obj->data[obj->tail] = x;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int n = obj->data[obj->tail];
    obj->tail--;
    return n;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    return obj->data[obj->tail];
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    if (obj->head <= obj->tail) return false;
    return true;
}

void myStackFree(MyStack* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * struct MyStack* obj = myStackCreate(maxSize);
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */