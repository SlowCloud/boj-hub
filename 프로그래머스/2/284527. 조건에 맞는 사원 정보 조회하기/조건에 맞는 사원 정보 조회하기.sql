-- 코드를 작성해주세요
select score, a.emp_no, a.emp_name, a.position, a.email
from hr_employees a
left join
(
    select aa.emp_no, sum(bb.score) as score
    from hr_employees aa
    right join hr_grade bb
    on aa.emp_no = bb.emp_no
    where bb.year = 2022
    group by aa.emp_no
) b
on a.emp_no = b.emp_no
order by score desc
limit 1;