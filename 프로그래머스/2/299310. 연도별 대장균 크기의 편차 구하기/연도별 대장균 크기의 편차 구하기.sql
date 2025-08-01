select year(differentiation_date) as year, mx - size_of_colony as year_dev, id
from ecoli_data a
left join (
    select year(differentiation_date) as year, max(size_of_colony) as mx
    from ecoli_data
    group by year
) b
on year(differentiation_date) = b.year
order by year asc, year_dev asc