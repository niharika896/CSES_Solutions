#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> towers(n);
    for (int i = 0; i < n; i++) {
        cin >> towers[i];
    }

    multiset<int> tops;

    for (int i = 0; i < n; i++) {
        auto it = tops.upper_bound(towers[i]);
        if (it != tops.end()) {
            tops.erase(it);
        }
        tops.insert(towers[i]);
    }

    cout << tops.size();
    return 0;
}
