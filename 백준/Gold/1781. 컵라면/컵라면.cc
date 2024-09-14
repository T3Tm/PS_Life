#include <bits/stdc++.h>
using namespace std;
int arr[200002];
pair<int,int> noodle[200002];
int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n;cin >> n;//n개의 대학
    
    for(int i=0;i<n;i++){
        cin >> noodle[i].first >> noodle[i].second;
    }
    sort(noodle, noodle + n,[](const pair<int,int>&a, const pair<int,int>&b){
        return a.second > b.second;
    });

    set<int, greater<int>> day;
    for(int i=1;i<=n;i++)day.insert(i);

    int total{};
    for(int i=0;i<n;i++){
        auto &[days, cost] = noodle[i];
        //days보다 작거나 같은 값 중 제일 큰 값
        auto it = day.lower_bound(days);
        if(it == day.end())continue;
        day.erase(it);
        total += cost;
    }
    cout << total;
    return 0;
}