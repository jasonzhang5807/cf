#include <bits/stdc++.h>
using namespace std;
struct iint {
    long long num;
    bool nag;
    bool operator>(const iint &a) const {
        if (num != a.num) return num > a.num;
        return nag;
    }
};
int main() {
    int n;
    cin >> n;
    priority_queue<iint, vector<iint>, greater<iint>> q;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        q.push({abs(x), x < 0});
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        iint a = q.top();
        q.pop();
        ans ^= a.num;
        long long x;
        cin >> x;
        x += a.num * (a.nag ? -1 : 1);
        q.push({abs(x), x < 0});
    }
    cout << ans;
}

