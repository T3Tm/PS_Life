def solution(n):
    #0, 1
    a, b = 0, 1
    counting = 1
    
    while counting < n:
        a, b = b, (a + b) % 1234567
        counting += 1
    return b