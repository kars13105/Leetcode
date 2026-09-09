# Write your MySQL query statement below
select w2.id 
from weather as w1
cross join weather as w2
where w2.temperature>w1.temperature AND datediff(w2.recordDate,w1.recordDate) = 1; 


