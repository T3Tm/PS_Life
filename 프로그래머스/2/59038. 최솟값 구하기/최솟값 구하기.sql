-- 코드를 입력하세요
-- 가장 먼저 들어온 동물은 언제 들어왔는지 조회해라.
SELECT min(datetime) as "시간"
    from animal_ins