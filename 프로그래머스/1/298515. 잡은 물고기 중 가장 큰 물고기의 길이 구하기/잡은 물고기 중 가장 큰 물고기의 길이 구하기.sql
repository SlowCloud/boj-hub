-- 코드를 작성해주세요
select concat(max(ifnull(length, 10)), 'cm') as max_length
from fish_info;