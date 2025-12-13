'''
'25. 12. 13.(토)

1. m명이 늘어날 때마다 서버 1대가 추가 설치
2. 한 번 증설된 서버는 k시간만 운영하고 이후에는 반납한다.

k = 5
10 ~ 15이다.

단순 시뮬레이션 문제같아 보임.

1. 게임
    1. 증설 횟수
    2. 현재 시간
    3. 이용자 수
    4. 현재 증설된 서버 수
    
2. 플레이어
    1. 어느 서버
    2. 언제 투입
'''
class player:
    def __init__(self, server: int, into: int):
        self.server = server
        self.into = into

from collections import deque
def solution(players: list, m: int, k: int):
    # 플레이어들이 각각 언제 들어왔는지 알 수 있음.
    # 시간순서대로 언제 증설됐는지 기억(서버 당)
    
    answer = 0
    player_list = []
    now_server = deque()#증설된 서버 k시간만 열려있을 수 있음.
    #index + k에는 나와야함.
    for idx, now_player in enumerate(players):
        while now_server and now_server[0] + k <= idx:
            pre_idx = now_server.popleft()
            #print(pre_idx, "서버", idx, "에 날라감")
        # idx ~ idx + 1 시간 대에 now_player만큼 있음.
        
        required_server = now_player // m #필요한 서버 수
        now_number_server = len(now_server)
        #서버 증설해야 됨.
        if required_server > now_number_server:
            gap = required_server - now_number_server
            #print(idx, "에 서버", gap, "만큼 추가됨.")
            for _ in range(gap):
                now_server.append(idx)
            answer += gap
        
            
    return answer