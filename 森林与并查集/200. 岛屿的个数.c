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
    printf("%d\n", u->n);
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

int merge(UnionSet *u, int a, int b) {
    int fa = find(u, a), fb = find(u, b);
    if (fa == fb) return 0;
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

int ind(int x, int y, int m) {
    return x * m + y;
}

int numIslands(char** grid, int n, int m) {
    UnionSet *u = init(n * m);
    int dir[2][2] = {0, 1, 1, 0};
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '0') {
                u->n--;
                continue;
            }
            for (int k = 0; k < 2; k++) {
                int dx = i + dir[k][0];
                int dy = j + dir[k][1];
                if (dx < 0 || dx >= n) continue;
                if (dy < 0 || dy >= m) continue;
                if (grid[dx][dy] == '0') continue;
                merge(u, ind(i, j, m), ind(dx, dy, m));
            }
        }
    }  
    return u->n;
}