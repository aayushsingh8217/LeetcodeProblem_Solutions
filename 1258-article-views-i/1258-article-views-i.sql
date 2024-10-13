# Write your MySQL query statement below
select distinct #duplicates hatane ke liye
author_id as id  #alias as id result mein id hai
from Views
where author_id=viewer_id  #table mein duplicates bhi hai
order by author_id