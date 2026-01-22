#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin>>a>>b;
        arr.push_back({a,b,i});
    }
    sort(arr.begin(), arr.end(), [](const vector<int> &a, const vector<int> &b)
        {
        if(a[0]!=b[0])return a[0]<b[0];
        return a[1]>b[1]; 
    });

    vector<int> contains(n, 0);
    vector<int> isContainedBy(n, 0);
    int largestEnd = INT_MIN;
    int smallestEnd = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][1] <= largestEnd)
        {
            isContainedBy[arr[i][2]] = 1;
        }
        largestEnd = max(largestEnd, arr[i][1]);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i][1] >= smallestEnd)
        {
            contains[arr[i][2]] = 1;
        }
        smallestEnd = min(smallestEnd, arr[i][1]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << contains[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < n; i++)
    {
        cout << isContainedBy[i] << " ";
    }

    return 0;
}