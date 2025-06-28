-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description
FROM crime_scene_reports
WHERE month='7' AND day=28
AND street='Humphrey Street';


 SELECT *
 FROM bakery_security_logs
 WHERE hour = 10
 AND minute >= 15
 AND month = 7
 AND day = 28;

SELECT transcript FROM interviews
WHERE month='7' AND day=28;
sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
| I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
+-----+------+-------+-----+------+--------+----------+---------------+


| id  | year | month | day | hour | minute | activity | license_plate |
+-----+------+-------+-----+------+--------+----------+---------------+
| 260 | 2021 | 7     | 28  | 10   | 16     | exit     | 5P2BI95       |
| 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
| 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
| 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
| 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
| 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
| 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
| 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55       |
| 268 | 2021 | 7     | 28  | 10   | 35     | exit     | 1106N58
S;


 SELECT  id  FROM atm_transactions
   ...>  WHERE month='7'
   ...>    AND day=28
   ...>    AND atm_location='Leggett Street'
   ...>    AND  transaction_type='withdraw';
+-----+
| id  |
+-----+
| 246 |
| 264 |
| 266 |
| 267 |
| 269 |
| 288 |
| 313 |
| 336 |
+-----+
SELECT id,caller,duration FROM phone_calls
WHERE month='7'
    AND day=28
    AND duration < 60;


 SELECT * FROM flights
 WHERE month='7'
    AND day=29;


SELECT *
FROM  flights
WHERE year = 2021
AND month = 7
AND day = 29
ORDER BY hour, minute
LIMIT 1;




SELECT  id  FROM atm_transactions
JOIN people ON atm_transactions.id =people.id
  WHERE month='7'
      AND day=28
     AND atm_location='Leggett Street'
    AND  transaction_type='withdraw';
+---------+
|  name   |
+---------+
| Bruce   |
| Diana   |
| Brooke  |
| Kenny   |
| Iman    |
| Luca    |
| Taylor  |
| Benista |
SELECT people.name
   ...> FROM atm_transactions
   ...> JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
   ...> JOIN people ON bank_accounts.person_id = people.id
   ...> WHERE atm_transactions.month = '7'
   ...>   AND atm_transactions.day = 28
   ...>   AND atm_transactions.atm_location = 'Leggett Street'
   ...>   AND atm_transactions.transaction_type = 'withdraw';

Vanessa | 10   | 16     | exit     |
| Bruce   | 10   | 18     | exit     |
| Barry   | 10   | 18     | exit     |
| Luca    | 10   | 19     | exit     |
| Sofia   | 10   | 20     | exit     |
| Iman    | 10   | 21     | exit     |
| Diana   | 10   | 23     | exit     |
| Kelsey  | 10   | 23     | exit     |
| Taylor  | 10   | 35     | exit     |
+---------+------+--------+----------+
SELECT p.name, bsl.hour, bsl.minute, bsl.activity
   ...> FROM bakery_security_logs bsl
   ...> JOIN people p ON bsl.license_plate = p.license_plate
   ...> WHERE bsl.month = '7'
   ...>   AND bsl.day = 28
   ...>   AND bsl.hour = 10
   ...>   AND bsl.minute BETWEEN 15 AND 35;


SELECT people.name FROM people
WHERE month='7'
    AND day=28
    AND duration < 60;
