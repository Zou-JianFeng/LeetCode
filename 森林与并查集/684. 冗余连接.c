/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct UnionSet {
    int *data, *size;
    int n;
} UnionSet;

UnionSet *init(int n) {
    UnionSet *u = (UnionSet *)malloc(sizeof(UnionSet));
    u->data = (int *)malloc(sizeof(int) * n);
    u->size = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        u->data[i] = i;
        u->size[i] = 1;
    }
    u->n = n;
    return u;
} 

void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->data);
    free(u->size);
    free(u);
    return ;
}

int find(UnionSet *u, int ind) {
    if (u->data[ind] == ind) return ind;
    return u->data[ind] = find(u, u->data[ind]);
}

int A, B; 
int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) {
        A = a;
        B = b;
        return 0;
    }
    if (u->size[fa] > u->size[fb]) {
        u->data[fb] = fa;
        u->size[fa] += u->size[fb];
    } else {
        u->data[fa] = fb;
        u->size[fb] += u->size[fb];
    }
    u->n--;
    return 1;
}

int* findRedundantConnection(int** edges, int n, int m, int* returnSize) {
    UnionSet *u = init(n * m);
    for (int i = 0; i < n; i++) {
        merge(u, edges[i][0], edges[i][1]);
    }
    *returnSize = 2;
    int *ans = (int *)malloc(sizeof(int) * 2);
    ans[0] = A;
    ans[1] = B;
    //for (int i = 0; i < 2; i++) printf("%d ", returnSize[i]);
    return ans;
}