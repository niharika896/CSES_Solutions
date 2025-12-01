#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> tp(n);
    for (int i = 0; i < n; i++) cin >> tp[i];

    vector<int> wtp(m);
    for (int i = 0; i < m; i++) cin >> wtp[i];

    multiset<int> s(tp.begin(), tp.end());

    vector<int> answer;
    answer.reserve(m);

    for (int w : wtp) {
        auto it = s.upper_bound(w);

        if (it == s.begin()) {
            answer.push_back(-1);
        } else {
            --it;
            answer.push_back(*it);
            s.erase(it);
        }
    }

    for (int x : answer) cout << x << "\n";

    return 0;
}
