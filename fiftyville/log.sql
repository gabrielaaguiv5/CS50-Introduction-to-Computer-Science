-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Let's first discover the information we can access to with the databse fiftyville.db.
.schema

-- We shall begin at the crime scene, learning from witnesses testimonies and security details.
SELECT description
  FROM crime_scene_reports
 WHERE month = 7
   AND day = 28
   AND year = 2021
   AND street = "Humphrey Street";

-- The description of the crime scene reports from the 28th of July 2021, Humphrey Street, depicted two different crimes: The CS50 duck theft at 10:15am and Littering to the place at 16:36pm.

-- The investigation continues with the content from the interviews mentioned in the crime scene reports, following the keyword "bakery" in the transcripts.

-- Accessing to the information from the interview transcripts of the day of the crime, with filter to find the word "bakery" in the transcripts.
SELECT name, transcript
  FROM interviews
 WHERE day = 28
   AND month = 7
   AND year = 2021
   AND transcript LIKE "%bakery%";

-- Following the testimonies from witnesses Ruth and Eugene, with cross examination of car license plate and account number.
-- First with the license plate.
SELECT license_plate, activity
  FROM bakery_security_logs
 WHERE day = 28
   AND month = 7
   AND year = 2021
   AND hour = 10
   AND minute = 35;

SELECT id, name
  FROM people
 WHERE license_plate = "1106N58";

 -- Following up with the account number.
 SELECT bank_accounts.person_id, atm_transactions.account_number
   FROM atm_transactions
   JOIN bank_accounts
     ON atm_transactions.account_number = bank_accounts.account_number
   JOIN people
     ON bank_accounts.person_id = people.id
  WHERE day = 28
    AND month = 7
    AND year = 2021
    AND atm_location = "Leggett Street"
    AND transaction_type = "withdraw"
    AND license_plate = "1106N58";

-- Following this investigation there is one match "Taylor", with a car at the time of the report from Ruth, and an atm withdraw from Leggett Street on the day of the crime.

-- We proceed with the discovery of the accomplice and the city of escape, following Raymond testimony.
SELECT phone_number
  FROM people
 WHERE id = 449774;

SELECT receiver, duration
  FROM phone_calls
 WHERE caller = "(286) 555-6063"
   AND day = 28
   AND month = 7
   AND year = 2021;

-- Given the duration of the call (in seconds), and the witness statement, phone number (676) 555-6554 is the accomplice.
SELECT id, name
  FROM people
 WHERE phone_number = "(676) 555-6554";

-- Accomplice goes by James, id = 250277. With this information we can track the city of escape.
SELECT passport_number
  FROM people
 WHERE id = 449774;

 SELECT flight_id
   FROM passengers
  WHERE passport_number = 1988161715;

  SELECT destination_airport_id
  


