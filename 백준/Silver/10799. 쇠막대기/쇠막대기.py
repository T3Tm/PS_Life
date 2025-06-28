import sys
input = sys.stdin.readline

def main():
    s = []
    lazer = input()
    output = 0
    for idx, st in enumerate(lazer):
        if st == ')': #레이저 닫힘
            pre_idx, now_lazer = s.pop()
            if pre_idx +1 == idx:#lazer 처리
                if s:
                    s[-1][1] += 1
            else:#쇠막대기
                output += now_lazer + 1
                if s:
                    s[-1][1] += now_lazer
        else:
            #idx, 몇 층, 레이저 개수
            s.append([idx, 0])
    print(output)
main()