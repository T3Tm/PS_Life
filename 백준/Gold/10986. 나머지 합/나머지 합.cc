#include <bits/stdc++.h>
using namespace std;
const int MX = (int)1e6 + 2;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin >> n>> m;
    map<int, vector<int>>mod;
    long long prefix[MX]{};
    for(int i{1};i<=n;i++){
        cin >> prefix[i];
        prefix[i] += prefix[i-1];
    }
    long long result{};
    for(int i{1};i<=n;i++){
        auto num = prefix[i]%m;//i까지의 합
        //그럼 i를 더했을 때니까 [1: j]까지의 합이 remain인 것들 갯수 세주면 됨.
        result += mod[num].size() + (num==0);
        mod[num].push_back(i);//
    }
    cout << result;
    return 0;
}