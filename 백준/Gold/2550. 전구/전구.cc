#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    while (cin >> n)
    {
        vector<int> arr(n);
        vector<int> numbering(10002);
        vector<int> tmp(n);
        for (int i{}; i < n; i++)
        {
            cin >> tmp[i];
            numbering[tmp[i]] = i; // tmp가 1번째 줄 value
        }

        for (int i{}; i < n; i++)
        {
            int t;
            cin >> t;
            arr[numbering[t]] = i;
        }
        vector<int> dp{-1};
        int result[10002]{};
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
            result[i] = it; // tmp[i]에 길이 매핑
        }
        cout << dp.size() - 1 << '\n';
        int last = dp.size() - 1;
        vector<int> p;
        for (int idx = 10000; idx >= 0 && last; idx--)
        {
            if (result[idx] == last)
            {
                p.push_back(tmp[idx]);
                last--;
            }
        }

        sort(p.begin(), p.end());
        for (auto &v : p)
            cout << v << ' ';
    }
    return 0;
}