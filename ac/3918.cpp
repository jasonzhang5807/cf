#include <cstdio>
#include <vector>
#include <map>
using namespace std;

struct DSU {
    vector<int> parent;
    DSU(int n) : parent(n+1) {
        for(int i=1; i<=n; i++) parent[i] = i;
    }
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        int fa = find(a), fb = find(b);
        if(fa != fb) parent[fb] = fa;
    }
};

int main() {
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    int n, k, l;
    scanf("%d%d%d", &n, &k, &l);

    // 处理道路连通性
    DSU road(n), rail(n);
    for(int i=0; i<k; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        road.unite(a, b);
    }

    // 处理铁路连通性
    for(int i=0; i<l; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        rail.unite(a, b);
    }

    // 统计每个城市的（道路根，铁路根）组合
    map<pair<int, int>, int> cnt;
    for(int i=1; i<=n; i++) {
        pair<int, int> key = {road.find(i), rail.find(i)};
        cnt[key]++;
    }

    // 输出结果
    for(int i=1; i<=n; i++) {
        pair<int, int> key = {road.find(i), rail.find(i)};
        printf("%d ", cnt[key]);
    }

    return 0;
}
