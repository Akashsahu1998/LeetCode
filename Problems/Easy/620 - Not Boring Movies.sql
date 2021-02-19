
-- Question) 620. Not Boring Movies


-- Query

-- MySQL & MS SQL Server

select * from cinema
where id%2 = 1 and description != 'boring' 
order by rating Desc;