#include<bits/stdc++.h>

using namespace std;

/* 회원등록시 정현이가 원하는 제품을 모두 할인을 받을 수 있는 총 일 수 */

bool check(vector<string>& want,vector<int>number ,unordered_map<string, int>& cnt){
    for(int i{};i< want.size();i++){
        string& word = want[i];
        int& counts = number[i];
        if(!cnt.count(word))return false;
        if(cnt[word] != counts)return false;
    }
    return true;
}
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int left = 0;
    
    unordered_map<string, int> now_cnt; 
    int right{};
    for(;right< 10;right++){
        now_cnt[discount[right]]++;
    }
    answer += check(want, number, now_cnt);
    for(; right < discount.size(); right++){
        now_cnt[discount[right]]++;
        now_cnt[discount[left++]]--;
        answer += check(want, number, now_cnt);
    }
    return answer;
}