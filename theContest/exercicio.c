#include <stdio.h>
#include <string.h>

#define MAX 1000000

int n;
int k1, k2, k3;
int v[MAX];
int tb[MAX][3];

int DC(int idx, int vez) {
    if (idx >= n) return 0;

    if (tb[idx][vez] != -1) return tb[idx][vez];

    int troca = 1e8, ntroca, tres = 1e8;
    if (vez == 0) {
        troca = (v[idx] != 2) + DC(idx + 1, 1);
        tres = (v[idx] != 3) + DC(idx + 1, 2);
        ntroca = (v[idx] != 1) + DC(idx + 1, vez);
    } else if (vez == 1) {
        troca = (v[idx] != 3) + DC(idx + 1, 2);
        ntroca = (v[idx] != 2) + DC(idx + 1, vez);
    } else {
        ntroca = (v[idx] != 3) + DC(idx + 1, 2);
    }

    return tb[idx][vez] = (troca < ntroca) ? ((troca < tres) ? troca : tres) : ((ntroca < tres) ? ntroca : tres);
}

int main() {
    memset(tb, -1, sizeof tb);
    scanf("%d %d %d", &k1, &k2, &k3);
    n = k1 + k2 + k3;

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (i < k1) {
            v[a - 1] = 1;
        } else if (i < k1 + k2) {
            v[a - 1] = 2;
        } else {
            v[a - 1] = 3;
        }
    }

    printf("%d\n", DC(0, 0));

    return 0;
}