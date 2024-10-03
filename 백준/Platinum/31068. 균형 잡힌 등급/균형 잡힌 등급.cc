#include <bits/stdc++.h>
using namespace std;
/*
*/
const int INF = 2 * (int)1e5 + 1;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin >> n;

    vector<pair<int,int>> person(n);//각 학생들의 점수
    for(auto &[x,y]:person)cin >> x >> y;

    map<int,pair<int,int>>mapping;//나온 x를 기준으로 해당 숫자들 최댓값 맵핑
    map<int,int>cnt;//해당 x개수 세주기
    for(auto &[x,y]:person){//n
        if(mapping.find(x) == mapping.end()){
            mapping[x] = {y,y};
        }else{
            mapping[x].first = min(mapping[x].first ,y);
            mapping[x].second = max(mapping[x].second, y);
        }
        cnt[x]++;//해당 갯수 세주기
    }

    vector<pair<int, pair<int,int>>> data;//유일한 x : 최소 y, 최대 y
    for(auto &[key,value]: mapping){
        data.push_back({key,value});//x, (최소 y, 최대 y)
    }
    
    
    map<int,multiset<int>, greater<>>y_pos;//최소 y : 해당 최대 y들
    for(auto&[x,y]:data){
        auto &[y_min, y_max] = y;
        y_pos[y_min].insert(y_max);
    }
    
    //각 b의 갯수, cnt를 구해보자
    vector<int>candidate;
    int b{};
    int lasty = -1;
    for(int i{};i<data.size();i++){
        auto &[x,y] = data[i];
        auto &[y_min, y_max] = y;
        lasty = max(lasty, y_max);//최대 계속해서 갱신해주기
        auto its = y_pos[y_min].lower_bound(y_max);
        y_pos[y_min].erase(its);//자기 자신 삭제
        if(y_pos[y_min].empty())y_pos.erase(y_min);//없으면 삭제
        auto it = y_pos.lower_bound(lasty);//찾았을 때 내 이하의 수가 없다면?
        b += cnt[x];
        if(it == y_pos.end()){//내 이하의 숫자가 없으므로
            candidate.push_back(b);
            b = 0;
        }
    }
    int result{INF};
    if(candidate.empty() || candidate.size() < 3){
        cout << -1;
        exit(0);
    }else{
        for(int i=1;i<candidate.size();i++){
            candidate[i] += candidate[i-1];
        }
        //누적합 해주고
        //7 4 1
        //7 11 9
        //  10 10
        for(int i{};i+2<candidate.size();i++){//
            int a = candidate[i];
            //나머지 b와 c의 갯수를 막대 한 개를 두고 적절히 분배해보자.
            int remain = (n - a)>>1;//그럼 최대한 절반으로 나누는 것이 이득이다.
            //b와 c를 최대한 remain에 가깝게 둘을 쪼개보자.
            int left = i+1, right = candidate.size() - 1;
            while(left<=right){
                int mid = (left+right)>>1;//mid index 까지 b가 먹었음
                if(candidate[mid] - candidate[i] >= remain){//너무 많이 자름
                    right = mid -1;
                }else{//더 잘라서 작게 
                    left = mid + 1;
                }
            }
            for(int index = left - 2; index <= left + 2; index++){
                if(index < i)continue;
                if(index >= candidate.size())break;
                int b = candidate[index] - candidate[i];
                int c = n - (b + a);
                if(b > 0 && c > 0){
                    result = min(result, max({a,b,c}) - min({a,b,c}));
                }    
            }
        }
    }
    if(result == INF)cout << -1;
    else cout << result;
    return 0;
}