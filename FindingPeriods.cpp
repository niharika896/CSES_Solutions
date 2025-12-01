#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();

    for (int len = 1; len <= n; len++) {
        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (s[j] != s[j % len]) { // compare with repeating prefix
                ok = false;
                break;
            }
        }
        if (ok) cout << len << " ";
    }
    return 0;
}
