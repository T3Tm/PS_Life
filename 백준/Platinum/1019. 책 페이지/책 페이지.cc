#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0) -> ios::sync_with_stdio(0);
    int n;cin >> n;
    string n_str = to_string(n);
    long long result[10]{};
    long long div = 10;
    long long mul = 1;
    int l = n_str.size();
    for(int i=0;i<n_str.size();i++){
        //i+1의 자리부터 개수세기 시작
        //제일 뒤에 수 비교
        for(int j=0;j<10;j++){
            //온전히 나오는 갯수
            int count = max(n / div + ((n_str[l - i - 1] - '0') > j) - (j == 0), 0LL);//n을 div자릿수로 나누었을 때 몇 번 반복이 될 수 있는지
            result[j] += count * mul;
            if(n_str[l - i - 1] - '0' == j){//같다면 갯수를 다르게 세주어야 된다.
                long long tmp{0};
                for(int idx = l - i;idx < l;idx++){
                    tmp = tmp * 10 + n_str[idx]-'0';
                }
                tmp++;
                result[j] += tmp;
            }
        }
        mul *=10;
        div *=10;
    }
    for(auto &v: result)cout << v << ' ';
    return 0;
}