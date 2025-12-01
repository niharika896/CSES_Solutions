#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> ticket_prices(n);
    for (int i = 0; i < n; i++) cin >> ticket_prices[i];

    vector<int> willing_to_pay(m);
    for (int i = 0; i < m; i++) cin >> willing_to_pay[i];

    multiset<int> s(ticket_prices.begin(), ticket_prices.end());

    vector<int> answer;
    answer.reserve(m);

    for (int w : willing_to_pay) {
        auto it = s.upper_bound(w);

        if (it == s.begin()) {
            answer.push_back(-1);
        } else {
            --it; //we want the number just less than upper bound;
            answer.push_back(*it);
            s.erase(it);
        }
    }

    for (int x : answer) cout << x << "\n";

    return 0;
}

//using a multiset becomes necessary here considering that the time complexity can be large. multiset allows lookup in log(n) TC thus making the TC of the algo O(m*log(n))
