#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

double calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool canReach(const vector<vector<double>>& dist, int n, double maxJump) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0); // 1号石头是索引0
    visited[0] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == 1) { // 2号石头是索引1
            return true;
        }

        for (int neighbor = 0; neighbor < n; ++neighbor) {
            if (!visited[neighbor] && dist[current][neighbor] <= maxJump) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> stones(n);
    for (int i = 0; i < n; ++i) {
        cin >> stones[i].first >> stones[i].second;
    }

    vector<vector<double>> dist(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = calculateDistance(stones[i].first, stones[i].second, stones[j].first, stones[j].second);
        }
    }

    double low = 0.0;
    double high = 0.0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] > high) {
                high = dist[i][j];
            }
        }
    }

    double answer = high;
    while (high - low > 1e-7) {
        double mid = (low + high) / 2;
        if (canReach(dist, n, mid)) {
            answer = mid;
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << fixed << setprecision(3) << answer << endl;

    return 0;
}
