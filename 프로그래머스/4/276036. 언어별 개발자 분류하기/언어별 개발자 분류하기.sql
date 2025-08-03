-- 코드를 작성해주세요

with info as (
    select *
    from skillcodes a
    left join developers b
    on a.code & b.skill_code
)
select (
    case
    when
        (id, 'Front end') in (select id, category from info) and
        (id, 'Python') in (select id, name from info)
    then 'A'
    when (id, 'C#') in (select id, name from info)
    then 'B'
    when (id, 'Front end') in (select id, category from info)
    then 'C'
    end
) as grade, id, email
from developers
having grade is not null
order by grade, id asc