# Write your MySQL query statement below
select e.name , b.bonus from Employee as e
left join Bonus as b on e.empId = b.empId
where b.bonus <1000 or b.bonus is null