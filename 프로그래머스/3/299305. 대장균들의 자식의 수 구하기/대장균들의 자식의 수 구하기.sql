select a.id, count(b.parent_id) as child_count
from ecoli_data a
left join ecoli_data b
on a.id = b.parent_id
group by id
order by id asc