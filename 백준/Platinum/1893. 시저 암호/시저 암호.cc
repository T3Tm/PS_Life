#include <bits/stdc++.h>
using namespace std;


map<char, int> trans;
void precomputation(const string& s){
    trans.clear();//전에 계산된 거 삭제
    for(int i{};i<s.size();i++){
        trans[s[i]] = i;//char : idx 맵핑
    }
}

vector<int> init(const string &s, int alpha, const string &order){
    int n = trans.size();
    int l = s.size();
    vector<int> f(l);
    f[0] = -1;

    for(int i= 1;i<s.size();i++){
        int j = f[i-1];
        while(j >= 0 && order[(trans[s[j+1]]+alpha)%n] != order[(trans[s[i]]+alpha)%n]){
            j = f[j];
        }
        f[i] = j + 1;
    }

    return f;
}


//실패함수, 문자열, 쉬프트 값, 문자열에서 쉬프트로 인해 다음 문자
bool kmp(const vector<int> &f,const string&w, const string&s, int alpha, const string& order){
    int n = order.size();

    int l = f.size();
    int j = 0;
    int cnt{};
    for(int i = 1; i<s.size(); i++){
        while(j >= 0 && order[(trans[w[j+1]]+alpha)%n] != s[i]){
            j = f[j];
        }

        j++;
        if(j == l-1){
            if(cnt)return false;
            cnt++;
            j = f[j];
        }
    }
    return cnt == 1;//1이면 한 번만 나타남
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t;cin >> t;
    while(t--){
        string a,w,s;
        cin >> a >> w >> s;
        w = ' ' + w;//앞에 공백 하나 처리
        s = ' ' + s;//문자열 하나 앞에 공백 처리해서 깔끔하게 처리 하기 위함

        //각 문자를 숫자에 맵핑
        precomputation(a);//62
        //s에 0번 부터 a.size() - 1 한하여 쉬프트가 몇 번 가능한지 판단
        vector<int> result;
        for(int alpha{};alpha<a.size();alpha++){
            vector<int>f = init(w,alpha, a);//kmp 하나 생성하기 alpha된 만큼 f함수 만들어주기
            //50000

            //500000
            if(kmp(f,w ,s,alpha, a)){//해당 kmp가 한 번만 해당되는지 확인
                result.push_back(alpha);
            }
        }

        if(result.size() == 1){
            cout << "unique: " << result[0]<< '\n';
        }
        else if(result.empty()){
            cout << "no solution\n";
        }else{
            cout << "ambiguous: ";
            for(auto &v:result)cout << v << ' ';
            cout << '\n';
        }
    }
    return 0;
}