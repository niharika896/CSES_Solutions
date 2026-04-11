#include <bits/stdc++.h>
using namespace std;

void update(int i, int add, vector<int> &fen)
{
    while (i < fen.size())
    {
        fen[i] += add;
        i += (i & -i);
    }
}

int sum(int i, vector<int> &fen)
{
    int s = 0;
    while (i > 0)
    {
        s += fen[i];
        i -= (i & -i);
    }
    return s;
}

int rangeSum(int l, int r, vector<int> &fen)
{
    return sum(r, fen) - sum(l - 1, fen);
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> fen(n + 1, 0);

    for(int i = 0; i < n; i++)
        update(i + 1, a[i], fen);

    cout << sum(5, fen) << endl;
    cout << rangeSum(1, 2, fen) << endl;

    a[1] += 6;
    update(2, 6, fen);

    cout << rangeSum(1, 2, fen);
}