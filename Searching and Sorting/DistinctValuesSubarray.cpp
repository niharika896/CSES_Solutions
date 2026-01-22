#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> last;
    last.reserve(n * 2);
    last.max_load_factor(0.25); 

    long long ans = 0;
    int l = 0;

    for (int r = 0; r < n; r++) {
        if (last.count(a[r])) {
            l = max(l, last[a[r]] + 1);
        }
        last[a[r]] = r;
        ans += (r - l + 1);
    }

    cout << ans;
    return 0;
}
