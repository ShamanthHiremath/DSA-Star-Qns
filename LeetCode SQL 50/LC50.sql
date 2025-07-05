-- LeetCode SQL 50 Questions

-- https://leetcode.com/studyplan/top-sql-50/



-- ******************************Select Questions*******************************


-- Query to find product IDs that are both low fat and recyclable
SELECT product_id
FROM Products
WHERE (low_fats = 'Y' AND recyclable = 'Y');


-- Find the names of the customer that are not referred by the customer with id = 2.
SELECT name
FROM Customer
WHERE referee_id != 2 OR referee_id IS NULL ;


-- Query to find the names of the countries with an area greater than or equal to 3,000,000 and a population greater than or equal to 25,000,000.
SELECT name, population, area
FROM World
WHERE (area >= 3000000 OR population >=25000000 );


-- Query to find unique ordered authors who viewed their own articles at least once.
SELECT DISTINCT author_id as id
FROM Views
WHERE author_id = viewer_id
ORDER BY author_id;


-- Query to find the tweet IDs of tweets that have more than 15 characters in their content.
SELECT tweet_id
FROM Tweets
WHERE LENGTH(content) >15;


-- ******************************************IMPORTANT************************************************************************

-- ******************************Basic Joins******************************

-- 1378. Replace Employee ID With The Unique Identifier

-- Query to find the unique IDs and names of employees, including those who do not have a corresponding entry in the EmployeeUNI table.
SELECT unique_id, name
FROM Employees as E
LEFT JOIN EmployeeUNI as EU
ON E.id = EU.id;


-- ******************************************IMPORTANT************************************************************************



-- Product Sales Analysis I


-- Query to find the product names, years, and prices from the Sales table, joining with the Product table.
-- 
SELECT p.product_name, s.year, s.price
FROM Sales as s 
JOIN Product as p
ON s.product_id = p.product_id;


-- ******************************************IMPORTANT************************************************************************


-- Customer Who Visited but Did Not Make Any Transactions


-- Query to find the names of customers who have not made any transactions from the Visits table, in Transactions table.
-- Write a solution to find the IDs of the users who visited without making any transactions and the number of times they made these types of visits. 
SELECT DISTINCT customer_id, COUNT(customer_id) as count_no_trans
FROM Visits
WHERE visit_id NOT IN (
    SELECT visit_id FROM Transactions
)
GROUP BY customer_id;

SELECT customer_id, COUNT(customer_id) AS count_no_trans
FROM Visits as v
LEFT JOIN Transactions t
ON v.visit_id = t.visit_id
WHERE transaction_id IS NULL
GROUP BY customer_id;


-- ******************************************IMPORTANT************************************************************************



-- Rising Temperature

-- 

SELECT today.id 
FROM Weather AS today
-- Combine every row of A with every other row of B
CROSS JOIN Weather AS yest  

WHERE today.temperature > yest.temperature
AND DATEDIFF(today.recordDate, yest.recordDate) = 1;

-- OR

SELECT w1.id
FROM Weather w1, Weather w2
WHERE DATEDIFF(w1.recordDate, w2.recordDate) = 1 AND w1.temperature > w2.temperature;


-- ******************************************IMPORTANT************************************************************************



-- Average Time of Process per Machine

-- Query to find the average processing time for each machine, rounded to 3 decimal places with the condition that the activity type is 'start' for the first activity and 'end' for the second activity.
-- The processing time is calculated as the difference between the timestamps of the 'end' and 'start' activities.
SELECT a.machine_id, ROUND(AVG(b.timestamp - a.timestamp), 3) AS processing_time 
FROM Activity a, Activity b
WHERE (a.machine_id = b.machine_id AND a.process_id = b.process_id AND a.activity_type = 'start' AND b.activity_type = 'end')
GROUP BY a.machine_id;

-- OR

SELECT a.machine_id, ROUND(AVG(b.timestamp - a.timestamp), 3) AS processing_time 
FROM Activity a
JOIN Activity b
ON (a.machine_id = b.machine_id AND a.process_id = b.process_id AND a.activity_type = 'start' AND b.activity_type = 'end')
GROUP BY a.machine_id;


-- ******************************************IMPORTANT************************************************************************



-- 577. Employee Bonus

-- Write a solution to report the name and bonus amount of each employee with a bonus less than 1000.
SELECT name, bonus
FROM Employee as e
LEFT JOIN Bonus as b
ON e.empId = b.empId
WHERE bonus IS NULL OR bonus < 1000;

-- *****************************************IMPORTANT************************************************************************

-- 1280. Students and Examinations

-- 

-- Write a solution to find the number of times each student attended each exam.
-- Return the result table ordered by student_id and subject_name.

SELECT s.student_id, s.student_name, sb.subject_name, COUNT(e.student_id) as attended_exams
FROM Students as s
CROSS JOIN Subjects AS sb
LEFT JOIN Examinations AS e
    ON s.student_id = e.student_id 
    AND sb.subject_name = e.subject_name
GROUP BY s.student_id, sb.subject_name
ORDER BY s.student_id, s.student_name, ct_name ;


-- *****************************************IMPORTANT************************************************************************

-- 570. Managers with at Least 5 Direct Reports

-- Write a solution to find managers with at least five direct reports.

SELECT e.name
FROM Employee e
JOIN (
    SELECT managerID
    FROM Employee 
    GROUP BY managerID
    HAVING COUNT(*) >= 5
) AS m
ON e.id = m.managerID;

SELECT name
FROM Employee
WHERE id IN (
    SELECT managerId
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(*) >= 5
);



-- 1934. Confirmation Rate

-- The confirmation rate of a user is the number of 'confirmed' messages divided by the total number of requested confirmation messages. The confirmation rate of a user that did not request any confirmation messages is 0. Round the confirmation rate to two decimal places.
-- Write a solution to find the confirmation rate of each user.

SELECT s.user_id, 
ROUND(AVG(if(c.action = "confirmed", 1, 0)), 2) as confirmation_rate 
FROM Signups s
LEFT JOIN Confirmations c
ON s.user_id = c.user_id
GROUP BY s.user_id;


-- **************************************************Basic Aggregate Functions*********************************************************



-- 620. Not Boring Movies

-- Write a solution to report the movies with an odd-numbered ID and a description that is not "boring".

SELECT *
FROM Cinema
WHERE id%2 =1 AND description != "boring"
ORDER BY rating DESC



-- *****************************************IMPORTANT************************************************************************

-- 1211. Queries Quality and Percentage

-- We define query quality as: The average of the ratio between query rating and its position.
-- We also define poor query percentage as:
-- The percentage of all queries with rating less than 3.
-- Write a solution to find each query_name, the quality and poor_query_percentage.
-- Both quality and poor_query_percentage should be rounded to 2 decimal places.

SELECT 
    query_name ,
    ROUND(SUM( rating / position) / COUNT(query_name) , 2) AS quality,
    ROUND((SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) / COUNT(rating)) * 100, 2) AS poor_query_percentage
FROM Queries
WHERE query_name IS NOT NULL
GROUP BY query_name;


-- *****************************************IMPORTANT************************************************************************


-- 1251. Average Selling Price

-- Write a solution to find the average selling price for each product. average_price should be rounded to 2 decimal places. If a product does not have any sold units, its average selling price is assumed to be 0.

SELECT p.product_id, 
ROUND(
    IFNULL(SUM(u.units * p.price) / SUM(u.units), 0), 2
  ) AS average_price
FROM Prices p
LEFT JOIN UnitsSold u
ON p.product_id = u.product_id
AND u.purchase_date >=  p.start_date AND u.purchase_date <= p.end_date
GROUP BY p.product_id;


-- 1075. Project Employees I

-- Write an SQL query that reports the average experience years of all the employees for each project, rounded to 2 digits.

SELECT p.project_id, 
ROUND(AVG(e.experience_years), 2) as average_years
FROM Project p
JOIN Employee e
ON e.employee_id = p.employee_id 
GROUP BY p.project_id;




-- 1633. Percentage of Users Attended a Contest

-- Write a solution to find the percentage of the users registered in each contest rounded to two decimals.
-- Return the result table ordered by percentage in descending order. In case of a tie, order it by contest_id in ascending order.


# Write your MySQL query statement below
SELECT contest_id,
ROUND(COUNT(DISTINCT r.user_id) * 100.0 / (SELECT COUNT(*) FROM Users), 2)  as percentage
FROM Register r
LEFT JOIN Users u
ON u.user_id = r.user_id
GROUP BY r.contest_id
ORDER BY percentage DESC, r.contest_id ASC;



-- ******************************************IMPORTANT*****************************************************************


-- 1193. Monthly Transactions I

-- Write an SQL query to find for each month and country, the number of transactions and their total amount, the number of approved transactions and their total amount.

-- Input: 
-- Transactions table:
-- +------+---------+----------+--------+------------+
-- | id   | country | state    | amount | trans_date |
-- +------+---------+----------+--------+------------+
-- | 121  | US      | approved | 1000   | 2018-12-18 |
-- | 122  | US      | declined | 2000   | 2018-12-19 |
-- | 123  | US      | approved | 2000   | 2019-01-01 |
-- | 124  | DE      | approved | 2000   | 2019-01-07 |
-- +------+---------+----------+--------+------------+
-- Output: 
-- +----------+---------+-------------+----------------+--------------------+-----------------------+
-- | month    | country | trans_count | approved_count | trans_total_amount | approved_total_amount |
-- +----------+---------+-------------+----------------+--------------------+-----------------------+
-- | 2018-12  | US      | 2           | 1              | 3000               | 1000                  |
-- | 2019-01  | US      | 1           | 1              | 2000               | 2000                  |
-- | 2019-01  | DE      | 1           | 1              | 2000               | 2000                  |


SELECT 
DATE_FORMAT(trans_date, '%Y-%m') as month, 
country, 
COUNT(*) as trans_count, 
COUNT(CASE WHEN state = 'approved' THEN 1 END) as approved_count , 
SUM(amount) as trans_total_amount, 
SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) as approved_total_amount 

FROM Transactions
GROUP BY month, country;



-- ******************************************IMPORTANT*****************************************************************


-- 550. Game Play Analysis IV

-- Write a solution to report the fraction of players that logged in again on the day after the day they first logged in, rounded to 2 decimal places. In other words, you need to determine the number of players who logged in on the day immediately following their initial login, and divide it by the number of total players.


SELECT
-- does the job of calculating fraction
ROUND( COUNT(*) / ( SELECT COUNT(DISTINCT player_id) FROM Activity) , 2) AS fraction
-- fetch the FIRST LOGIN DATE of an user 
FROM (
    SELECT player_id, MIN(event_date) AS first_login_date
    FROM Activity
    GROUP BY player_id
) 
A
JOIN Activity b
ON A.player_id = B.player_id 
AND DATEDIFF(B.event_date, a.first_login_date) = 1


-- ******************************************IMPORTANT*****************************************************************

-- 1174. Immediate Food Delivery II

-- If the customer's preferred delivery date is the same as the order date, then the order is called immediate; otherwise, it is called scheduled.
-- The first order of a customer is the order with the earliest order date that the customer made. It is guaranteed that a customer has precisely one first order.
-- Write a solution to find the percentage of immediate orders in the first orders of all customers, rounded to 2 decimal places.



SELECT 
-- summing up ORDERS that are on THE SAME DAY
ROUND(SUM(CASE WHEN D.customer_pref_delivery_date = D.order_date THEN 1 ELSE 0 END) * 100.0 / COUNT(*), 2) AS immediate_percentage
-- selecting only FIRST ORDER (min) per USER
FROM (
    SELECT customer_id,
    MIN(order_date) AS first_order_date
    FROM Delivery
    GROUP BY customer_id
)
AS first_orders
JOIN Delivery D
ON first_orders.customer_id = D.customer_id 
AND first_orders.first_order_date = D.order_date;




-- *******************************************Sorting and Grouping**********************************************

-- 2356. Number of Unique Subjects Taught by Each Teacher

-- Write a solution to calculate the number of unique subjects each teacher teaches in the university.

SELECT teacher_id, COUNT(DISTINCT subject_id) as cnt
FROM Teacher
GROUP BY teacher_id


-- 1141. User Activity for the Past 30 Days I

-- Write a solution to find the daily active user count for a period of 30 days ending 2019-07-27 inclusively. A user was active on someday if they made at least one activity on that day.

SELECT activity_date as day,
COUNT(DISTINCT user_id) as active_users
FROM Activity
WHERE (activity_type IS NOT NULL) AND DATEDIFF('2019-07-27', activity_date) <=30
GROUP BY activity_date;

-- OR

SELECT activity_date as day,
COUNT(DISTINCT user_id) as active_users
FROM Activity
WHERE (activity_type IS NOT NULL) AND (activity_date >= '2019-06-28' AND activity_date <= '2019-07-27')
GROUP BY activity_date;


-- 1070. Product Sales Analysis III

-- Write a solution to find all sales that occurred in the first year each product was sold.
-- For each product_id, identify the earliest year it appears in the Sales table.
-- Return all sales entries for that product in that year.

SELECT product_id, year as first_year, quantity, price
FROM Sales
WHERE (product_id, year) IN (
    SELECT product_id, 
    MIN(year)
    FROM Sales
    GROUP BY product_id
);


-- 1045. Customers Who Bought All Products

-- Write a solution to report the customer ids from the Customer table that bought all the products in the Product table.

SELECT customer_id
FROM Customer
GROUP BY customer_id
-- HAVING COUNT() always checks for individual count of each of the groups,
-- so here we want count of Products of each customer
HAVING COUNT(DISTINCT product_key) = (SELECT COUNT(*) FROM Product);


-- 619. Biggest Single Number

-- A single number is a number that appeared only once in the MyNumbers table.
-- Find the largest single number. If there is no single number, report null.

SELECT MAX(num) AS num
FROM (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(*) = 1
) AS unique_numbers;


-- OR

SELECT 
    (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(num) = 1
    ORDER BY num DESC
    LIMIT 1
) AS num;



-- 1729. Find Followers Count

-- Write a solution that will, for each user, return the number of followers.
-- Return the result table ordered by user_id in ascending order.

SELECT DISTINCT user_id ,
COUNT(user_id) as followers_count
FROM Followers
GROUP BY user_id
ORDER BY user_id



-- 596. Classes With at Least 5 Students

-- Write a solution to find all the classes that have at least five students.

SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(*) > 4;



-- ********************************************Advanced Select and Joins**************************************************
















-- ***************************************************Subqueries**************************************************











-- ***************************************Advanced String Functions / Regex / Clause**************************************


-- 1667. Fix Names in a Table

-- Write a solution to capitalize the first letter of each name in the Users table, while keeping the rest of the letters in lowercase.
-- aLicE as Alice, bOB as Bob, and so on.
SELECT user_id,
CONCAT( UPPER( LEFT(name, 1)), LOWER( SUBSTRING(name, 2))) AS name
FROM Users
ORDER BY user_id;

-- 1527. Patients With a Condition

-- Write a solution to find the patient_id, patient_name, and conditions of the patients who have Type I Diabetes. Type I Diabetes always starts with DIAB1 prefix.

-- DIAB100 MYOP, ACNE DIAB100, : CORRECT
-- DIAB1, DIAB2, DIAB3 : CORRECT
-- SADIAB100 : WRONG

SELECT patient_id, patient_name, conditions
FROM Patients
WHERE conditions LIKE 'DIAB1%' OR conditions LIKE '% DIAB1%'


-- 196. Delete Duplicate Emails

-- Write a solution to delete all duplicate emails, keeping only one unique email with the smallest id.
-- For SQL users, please note that you are supposed to write a DELETE statement and not a SELECT one.

DELETE p1 
FROM Person p1, Person p2
WHERE p1.email = p2.email 
AND p1.id > p2.id;


-- 176. Second Highest Salary

-- Write a solution to find the second highest salary from the Employee table. If there is no second highest salary, the query should return null.

SELECT MAX(salary) AS SecondHighestSalary

FROM Employee
WHERE salary NOT IN (SELECT MAX(salary) FROM Employee);

SELECT 
    (
    SELECT DISTINCT salary 
    FROM Employee 
    ORDER BY salary DESC 
    LIMIT 1 OFFSET 1
)
AS SecondHighestSalary;

-- Nth Highest Salary
SELECT 
  IFNULL(
    (SELECT DISTINCT salary 
     FROM Employee 
     ORDER BY salary DESC 
     LIMIT 1 OFFSET N), 
    NULL
  ) AS Nth_HighestSalary;




-- 1484. Group Sold Products By The Date

-- Input: 
-- Activities table:
-- +------------+------------+
-- | sell_date  | product     |
-- +------------+------------+
-- | 2020-05-30 | Headphone  |
-- | 2020-06-01 | Pencil     |
-- | 2020-06-02 | Mask       |
-- | 2020-05-30 | Basketball |
-- | 2020-06-01 | Bible      |
-- | 2020-06-02 | Mask       |
-- | 2020-05-30 | T-Shirt    |
-- +------------+------------+
-- Output: 
-- +------------+----------+------------------------------+
-- | sell_date  | num_sold | products                     |
-- +------------+----------+------------------------------+
-- | 2020-05-30 | 3        | Basketball,Headphone,T-shirt |
-- | 2020-06-01 | 2        | Bible,Pencil                 |
-- | 2020-06-02 | 1        | Mask                         |
-- +------------+----------+------------------------------+

SELECT sell_date, 
COUNT(DISTINCT product) AS num_sold,
GROUP_CONCAT( DISTINCT product order by product ASC separator ',' ) AS products
FROM Activities
GROUP BY sell_date
ORDER BY sell_date ASC;

-- 1517. Find Users With Valid E-Mails

-- A valid e-mail has a prefix name and a domain where:
-- The prefix name is a string that may contain letters (upper or lower case), digits, underscore '_', period '.', and/or dash '-'. The prefix name must start with a letter.
-- The domain is '@leetcode.com'.
-- abc@leetcode.com


SELECT *
FROM Users
WHERE REGEXP_LIKE(mail, '^[a-zA-Z][a-zA-Z0-9._-]*@leetcode\\.com$', 'c');