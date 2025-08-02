-- 코드를 작성해주세요
select a.id, b.fish_name, a.length
from fish_info a
left join fish_name_info b
on a.fish_type = b.fish_type
where (a.fish_type, a.length) in (
    select aa.fish_type, max(length)
    from fish_info aa
    left join fish_name_info bb
    on aa.fish_type = bb.fish_type
    group by aa.fish_type
)
order by a.id asc;