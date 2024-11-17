-- 코드를 입력하세요
-- 동물 이름 중 두번 이상 쓰인 이름과, 해당 이름이 쓰인 횟수를 조회해라
select B.name, B.COUNT
from (select name, count(name) as COUNT from animal_ins group by name) B
where B.COUNT >=2
order by B.name