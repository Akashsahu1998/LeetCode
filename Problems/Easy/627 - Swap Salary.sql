// Question) 627. Swap Salary

// SQL Question
// Implementation


// 1st Approach in MySQL

update salary
 set sex = if(sex = 'm', 'f', 'm')


// 2nd Approach in MySQL

update salary
set sex = (case when sex = 'm' 
                    then 'f' 
                else 'm' 
            end) 
