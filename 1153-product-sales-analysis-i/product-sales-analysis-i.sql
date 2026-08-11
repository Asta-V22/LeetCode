# Write your MySQL query statement below
SELECT s.product_name, f.year, f.price FROM Sales as f
LEFT JOIN Product as s ON f.product_id = s.product_id;