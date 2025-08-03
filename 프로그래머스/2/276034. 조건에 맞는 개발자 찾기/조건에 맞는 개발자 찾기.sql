-- 코드를 작성해주세요

select id, email, first_name, last_name
from developers
where skill_code & (select sum(code) from skillcodes where name like 'C#' or name like 'Python')
order by id asc