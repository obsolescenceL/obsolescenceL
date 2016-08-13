#include<cstdio>
#include<iostream>
#define MAXN 400010
#define PushUp(x) num[x] = num[next[x][0]] + num[next[x][1]] + 1;
using namespace std;
pair<int, int> edge[MAXN];
int first[MAXN], next[MAXN], cost[MAXN], e;
int father[MAXN];
bool del[MAXN];
struct ASK {
    char cmd;
    int x, k;
} a[MAXN];
struct SplayTree {
    int root;
    int next[MAXN][2], pre[MAXN], key[MAXN], num[MAXN];
    void Init() {
        root = next[0][0] = next[0][1] = pre[0] = num[0] = key[0] = 0;
    }
    inline void NewNode(int &x, int loc, int father, int val) {
        x = loc;
        next[x][0] = next[x][1] = 0;
        pre[x] = father;
        key[x] = val;
        num[x] = 1;
    }
    inline void Rotate(int x, int kind) {
        int y, z;
        y = pre[x];
        z = pre[y];
        next[y][!kind] = next[x][kind];
        pre[next[x][kind]] = y;
        next[z][next[z][1] == y] = x;
        pre[x] = z;
        next[x][kind] = y;
        pre[y] = x;
        PushUp(y);
    }
    void Splay(int x, int goal) {
        if (x != goal) {
            while (pre[x] != goal) {
                if (next[pre[x]][0] == x)
                    Rotate(x, 1);
                else
                    Rotate(x, 0);
            }
            PushUp(x);
            if (!goal)
                root = x;
        }
    }
    int Select(int x, int k) {
        k = num[x] - k + 1;
        while (num[next[x][0]] + 1 != k) {
            if (num[next[x][0]] + 1 > k)
                x = next[x][0];
            else {
                k -= num[next[x][0]] + 1;
                x = next[x][1];
            }
        }
        Splay(x, 0);
        return x;
    }
    void Insert(int x, int y, int val) {
        while (next[y][val > key[y]])
            y = next[y][val > key[y]];
        NewNode(next[y][val > key[y]], x, y, val);
    }
    void DFS(int x) {
        if (x) {
            DFS(next[x][0]);
            DFS(next[x][1]);
            Insert(x, root, key[x]);
            Splay(x, 0);
        }
    }
    void Join(int x, int y) {
        Splay(x, 0);
        Splay(y, 0);
        if (num[x] > num[y])
            swap(x, y);
        root = y;
        DFS(x);
    }
    int Query(int x, int k) {
        if (k < 1)
            return 0;
        Splay(x, 0);
        if (num[x] < k)
            return 0;
        return key[Select(x, k)];
    }
    void Change(int x, int val) {
        int a, b;
        Splay(x, 0);
        a = next[x][0];
        b = next[x][1];
        pre[a] = pre[b] = 0;
        if (a && b) {
            while (next[b][0])
                b = next[b][0];
            next[b][0] = a;
            pre[a] = b;
            Splay(a, 0);
            Insert(x, a, val);
        } else if (a)
            Insert(x, a, val);
        else if (b)
            Insert(x, b, val);
        else
            key[x] = val;
        Splay(x, 0);
    }
} spt;
int INT() {
    bool neg;
    int res;
    char ch;
    while (ch = getchar(), !isdigit(ch) && ch != '-')
        ;
    if (ch == '-') {
        neg = true;
        res = 0;
    } else {
        neg = false;
        res = ch - '0';
    }
    for (; ch = getchar(), isdigit(ch);)
        res = res * 10 + ch - '0';
    return neg ? -res : res;
}
char CHAR() {
    char ch;
    while (ch = getchar(), !isalpha(ch))
        ;
    return ch;
}
int FindSet(int x) {
    if (x != father[x])
        father[x] = FindSet(father[x]);
    return father[x];
}
inline void AddEdge(int x, int val) {
    cost[e] = val;
    next[e] = first[x];
    first[x] = e++;
}
int main() {
    int ca = 1;
    double ans;
    int n, m, q, i, cnt;
    int x, y;
    freopen("ac.out","w",stdout);
    while (true) {
        n = INT(), m = INT();
        if (!n && !m)
            break;
        spt.Init();
        for (e = 0, i = 1; i <= n; i++) {
            father[i] = i;
            first[i] = -1;
            AddEdge(i, INT());
        }
        for (i = 1; i <= m; i++) {
            edge[i] = make_pair(INT(), INT());
            del[i] = false;
        }
        for (q = 0;; q++) {
            a[q].cmd = CHAR();
            if (a[q].cmd == 'E')
                break;
            a[q].x = INT();
            if (a[q].cmd == 'D')
                del[a[q].x] = true;
            else {
                a[q].k = INT();
                if (a[q].cmd == 'C')
                    AddEdge(a[q].x, a[q].k);
            }
        }
        for (i = 1; i <= n; i++) {
            spt.NewNode(spt.root, i, 0, cost[first[i]]);
            first[i] = next[first[i]];
        }
        for (i = 1; i <= m; i++) {
            if (!del[i]) {
                x = FindSet(edge[i].first);
                y = FindSet(edge[i].second);
                if (x != y) {
                    spt.Join(edge[i].first, edge[i].second);
                    father[x] = y;
                }
            }
        }
        ans = cnt = 0;
        for (i = q - 1; i >= 0; i--) {
            if (a[i].cmd == 'Q') {
                cnt++;
                ans += spt.Query(a[i].x, a[i].k);
            } else if (a[i].cmd == 'D') {
                x = FindSet(edge[a[i].x].first);
                y = FindSet(edge[a[i].x].second);
                if (x != y) {
                    spt.Join(edge[a[i].x].first, edge[a[i].x].second);
                    father[x] = y;
                }
            } else {
                spt.Change(a[i].x, cost[first[a[i].x]]);
                first[a[i].x] = next[first[a[i].x]];
            }
        }
        printf("Case %d: %lf\n", ca++, ans / cnt);
    }
    return 0;
}
