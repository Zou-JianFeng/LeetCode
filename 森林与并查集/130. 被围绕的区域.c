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
    return u;
}

int find(UnionSet *u, int index) {
    if (u->data[index] == index) return index;
    return u->data[index] = find(u, u->data[index]);
}

int merge(UnionSet *u, int a, int b) {
    int f_a = find(u, a), f_b = find(u, b);
    if (f_a == f_b) return 0;
    if (u->size[f_a] > u->size[f_b]) {
        u->data[f_b] = f_a;
        u->size[f_a] += u->size[f_b];
    } else {
        u->data[f_a] = f_b;
        u->size[f_b] += u->size[f_b];
    }
    return 1;
}

void clear(UnionSet *u) {
    if (u == NULL) return ;
    free(u->data);
    free(u->size);
    free(u);
    return ;
}

int ind(int x, int y, int m) {
    return x * m + y + 1;
}

void solve(char** board, int n, int m) {
    int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
    UnionSet *u = init(n * m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'X') continue;
            for (int k = 0; k < 2; k++) {
                int dx = i + dir[k][0];
                int dy = j + dir[k][1];
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    merge(u, 0, ind(i, j, m));
                }
                if (dx < 0 || dx >= n) continue;
                if (dy < 0 || dy >= m) continue;
                if (board[dx][dy] == 'X') continue;
                merge(u, ind(i, j, m), ind(dx, dy, m));
            }
        }
    }
    int f0 = find(u, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (find(u, ind(i, j, m)) == f0) continue;
            board[i][j] = 'X';
        }
    }
    clear(u);
    return ;
}