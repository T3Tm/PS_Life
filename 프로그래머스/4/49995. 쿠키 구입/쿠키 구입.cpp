#include <string>
#include <vector>

using namespace std;
int prefix[2002];
int is_right(int left, int right){
    if((prefix[right] - prefix[left-1])&1)return 0;
    int l = left, r = right;

    while(l <= r){
        int mid = (l + r) >> 1;
        
        int front = prefix[mid] - prefix[left - 1];
        int back = prefix[right] - prefix[mid];
        if(front == back) return (prefix[right] - prefix[left-1]) >> 1;
        if(front > back)  r = mid - 1;
        else  l = mid + 1 ;
    }
    return 0;
}

int solution(vector<int> cookie) {
    int answer{};
    for(int i{}; i < cookie.size(); i++){
        prefix[i+1] = prefix[i] + cookie[i];
    }
    
    for(int i{}; i < cookie.size(); i++){
        for(int j{i+1}; j < cookie.size(); j++){
            answer = max(answer, is_right(i+1, j + 1));
        }
    }
    return answer;
}