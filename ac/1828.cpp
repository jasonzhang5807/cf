#include <bits/stdc++.h>
#define maxn 500010
using namespace std;
int tag[maxn << 2], lr[maxn << 2], rr[maxn << 2], mr[maxn << 2];
inline void pushup(int rt, int l, int r) {
    int mid = (l + r) >> 1;
    lr[rt] = lr[rt << 1];
    if (lr[rt] == mid - l + 1) {
        lr[rt] += lr[rt << 1 | 1];
    }
    rr[rt] = rr[rt << 1 | 1];
    if (rr[rt] == r - mid) {
        rr[rt] += rr[rt << 1];
    }
    mr[rt] = max({mr[rt << 1], mr[rt << 1 | 1], rr[rt << 1] + lr[rt << 1 | 1]});
}
inline void pushdown(int rt, int l, int r) {
    if (tag[rt] != -1) {
        int mid = (l + r) >> 1;
        tag[rt << 1] = tag[rt];
        tag[rt << 1 | 1] = tag[rt];
        lr[rt << 1] = rr[rt << 1] = mr[rt << 1] = (tag[rt] ? 0 : mid - l + 1);
        lr[rt << 1 | 1] = rr[rt << 1 | 1] = mr[rt << 1 | 1] = (tag[rt] ? 0 : r - mid);
        tag[rt] = -1;
    }
}
void build(int rt, int l, int r) {
    tag[rt] = -1;
    if (l == r) {
        lr[rt] = rr[rt] = mr[rt] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt, l, r);
}
void update(int rt, int l, int r, int L, int R, int val) {
    if (L <= l && r <= R) {
        tag[rt] = val;
        lr[rt] = rr[rt] = mr[rt] = (val ? 0 : r - l + 1);
        return;
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update(rt << 1, l, mid, L, R, val);
    if (R > mid) update(rt << 1 | 1, mid + 1, r, L, R, val);
    pushup(rt, l, r);
}
int query(int rt, int l, int r, int len) {
    if (l == r) return l;
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (mr[rt << 1] >= len) return query(rt << 1, l, mid, len);
    if (rr[rt << 1] + lr[rt << 1 | 1] >= len) return mid - rr[rt << 1] + 1;
    return query(rt << 1 | 1, mid + 1, r, len);
}
int main() {
	freopen("seating.in", "r", stdin);
	freopen("seating.out", "w", stdout);
    int N, M;
    scanf("%d%d", &N, &M);
    build(1, 1, N);
    int ans = 0;
    while (M--) {
        char op[2];
        scanf("%s", op);
        if (op[0] == 'A') {
            int p;
            scanf("%d", &p);
            if (mr[1] < p) {
                ans++;
            } else {
                int pos = query(1, 1, N, p);
                update(1, 1, N, pos, pos + p - 1, 1);
            }
        } else {
            int a, b;
            scanf("%d%d", &a, &b);
            update(1, 1, N, a, b, 0);
        }
    }
    printf("%d\n", ans);
    return 0;
}
