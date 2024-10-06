#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    while (cin >> n)
    {
        vector<int> arr(n);
        for (auto &v : arr)
            cin >> v;

        vector<int> dp{0};
        for (int i{}; i < n; i++)
        {
            int it = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            if (it == (int)dp.size())
            {
                dp.push_back(arr[i]);
            }
            else
            {
                dp[it] = arr[i];
            }
        }
        cout << dp.size() - 1 << '\n';
    }
    return 0;
}