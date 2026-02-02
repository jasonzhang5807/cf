#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
vector<pair<int, int>> g[10010];
int dis[10010];
int main() {
    memset(dis, 0x3f, sizeof(dis)); 
    int n, s, t;
    cin >> n >> s >> t;
    for (int u = 1, m, v; u <= n; ++u) {
        scanf("%d", &m);
        if (!m) continue;
        --m;
        scanf("%d", &v);
        g[u].push_back({v, 0});
        while (m--) {
            scanf("%d", &v);
            g[u].push_back({v, 1});
        }
    }
    deque<pair<int, int>> q;
    q.push_back({s, 0});
    dis[s] = 0;
    while (!q.empty()) {
        auto u = q.front();
        q.pop_front();
        if (u.first == t) {
            cout << u.second;
            return 0;
        }
        for (auto x : g[u.first]) {
            int new_dist = u.second + x.second;
            if (dis[x.first] > new_dist) {
                dis[x.first] = new_dist;
                if (x.second == 0) q.push_front({x.first, new_dist});
                else q.push_back({x.first, new_dist});
            }
        }
    }
    cout << -1;
    return 0;
}
