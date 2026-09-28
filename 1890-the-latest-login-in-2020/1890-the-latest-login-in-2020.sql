# Write your MySQL query statement below
select user_id, max(time_stamp) as last_stamp
from logins
where year(time_stamp) = 2020
group by user_id;

-- Synced seamlessly with LeetHub Pro
-- Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
-- Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna