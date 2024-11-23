#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
bool is_match(const string& target, const string& word, int idx){
    //target의 idx를 기점으로 word랑 맞는지 체크
    for(int i{}; i < word.size(); i++){
        if(target[idx - i] != word[word.size() - i - 1])return false;
    }
    return true;
}
int solution(vector<string> strs, string t)
{
    int dp[20002];memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    int t_size = t.size();
    t = ' ' + t;
    for(int i{1};i<=t_size;i++){
        
        for(auto &v: strs){
            if(i < v.size())continue;//이러면 안됨.
            
            //이제부터 문자열 매칭
            if(!is_match(t, v, i))continue;
            
            if(dp[i - v.size()] == INF)continue;
            dp[i] = min(dp[i], dp[i - v.size()] + 1);
        }
    }
    
    
    return (dp[t_size] == INF ? -1 : dp[t_size]);
}