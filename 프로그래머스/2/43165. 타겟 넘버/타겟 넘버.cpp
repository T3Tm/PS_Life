#include <string>
#include <vector>

using namespace std;
int answer;
void bact(int& target, vector<int>& numbers, int depth, int now = 0){
    if(depth == numbers.size()){//끝
        answer += target == now;
        return;
    }
    
    bact(target, numbers, depth + 1, now + numbers[depth]);
    bact(target, numbers, depth + 1, now - numbers[depth]);
}
int solution(vector<int> numbers, int target) {
    bact(target, numbers, 0);
    return answer;
}