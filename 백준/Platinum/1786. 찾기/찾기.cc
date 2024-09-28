#include <bits/stdc++.h>
using namespace std;
vector<int> failure(const string& word){
    int l = word.size();
    vector<int>f(l);
    f[0]= -1;
    for(int i=1;i<l;i++){
        int j = f[i-1];
        while(j >= 0 && word[j+1] != word[i]){
            j = f[j];
        }
        f[i] = j + 1;
    }
    return f;
}

vector<int> kmp(vector<int>&f, const string&word, const string& target){
    int j = 0;
    int l = target.size();
    int n = word.size();
    vector<int>ret;
    for(int i=1; i< l;i++){
        while(j >= 0 && word[j+1] != target[i]){
            j = f[j];
        }
        j++;
        if(j == n-1){
            ret.push_back(i - n + 2);
            j = f[j];
        }
    }
    return ret;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    string target;
    getline(cin, target);//한 줄 읽고
    string pattern;
    getline(cin, pattern);
    pattern = ' ' + pattern;
    target = ' ' + target;
    vector<int>f = failure(pattern);//실패함수 만들기 
    vector<int>result = kmp(f,pattern ,target);//
    cout << result.size() << '\n';
    for(auto &idx : result)cout << idx << ' ';
    return 0;
}