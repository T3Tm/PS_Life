#include <bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
    return b == 0 ? a : gcd(b, a%b);
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin >> n;
    vector<char>pattern(n);//여기에 얼만큼 맞는지 알아야됨.
    vector<char>word(n);
    for(auto &v:pattern)cin >> v;
    for(auto &v:word)cin >> v;
    
    for(int i=0;i<n-1;i++){
        word.push_back(word[i]);
    }
    pattern.insert(pattern.begin(),' ');
    word.insert(word.begin(),' ');
    vector<int>f(n+1);
    f[0] = -1;
    for(int i=1;i<=n;i++){
        int j = f[i-1];
        while(j >= 0 && pattern[j+1] != pattern[i]){
            j = f[j];
        }
        f[i] = j + 1;
    }

    //패턴 만들었음.
    
    int cnt{};
    int j = -1;
    for(int i=1;i<=2*n-1;i++){
        while(j >= 0 && pattern[j+1] != word[i]){
            j = f[j];
        }
        j++;
        if(j == n-1){
            cnt++;
            j = f[j];
        }
    }
    int value = gcd(cnt, n);
    cout << cnt/value << '/' << n / value;
    return 0;
}