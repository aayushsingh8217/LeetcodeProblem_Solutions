# Write your MySQL query statement below
select eu.unique_id, e.name
from Employees as e
#foreign key concept
left join EmployeeUNI as eu
on e.id=eu.id
