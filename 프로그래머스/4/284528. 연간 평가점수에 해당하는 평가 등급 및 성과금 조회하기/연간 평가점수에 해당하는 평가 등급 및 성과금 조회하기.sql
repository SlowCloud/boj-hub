select a.emp_no, emp_name, grade, case
    when grade = 'S' then 0.2 * sal
    when grade = 'A' then 0.15 * sal
    when grade = 'B' then 0.1 * sal
    else 0
    end bonus
from hr_employees a
left join (select emp_no, case
    when avg(score) >= 96 then 'S'
    when avg(score) >= 90 then 'A'
    when avg(score) >= 80 then 'B'
    else 'C'
    end grade
from hr_grade
group by emp_no) b
on a.emp_no = b.emp_no