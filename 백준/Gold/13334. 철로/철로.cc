#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin >> n;

    
    vector<long long>s_pos;
    vector<long long>e_pos;
    vector<pair<int,int>> arr(n);
    for(auto&[x,y]:arr){
        cin >> x >> y;
        if(x > y)swap(x,y);
    }
    long long dis;cin >> dis;
    for(auto&[x,y]:arr){
        if(y-x <= dis){
            s_pos.push_back(x);
            e_pos.push_back(y);
        }
    }
    sort(s_pos.begin(), s_pos.end());
    sort(e_pos.begin(), e_pos.end());
    
    //end_point 갯수
    //start_point 갯수
    

    int result{};
    for(auto &s : s_pos){
        //s보다 작은 아이를 알아내기
        int front_cnt = n - (upper_bound(s_pos.rbegin(), s_pos.rend(), s, greater<>()) - s_pos.rbegin());
        
        
        long long end_point = dis + s;//여기까지의 end_point 갯수
        int end_cnt = n - (lower_bound(e_pos.rbegin(), e_pos.rend(), end_point, greater<>()) - e_pos.rbegin());

        result = max(result,end_cnt - front_cnt);
    }

    cout << result;
    return 0;
}