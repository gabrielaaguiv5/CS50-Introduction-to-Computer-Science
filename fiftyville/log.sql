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
SELECT bakery_security_logs.license_plate, activity, name
  FROM bakery_security_logs
  JOIN people
    ON bakery_security_logs.license_plate = people.license_plate
 WHERE day = 28
   AND month = 7
   AND year = 2021
   AND hour = 10
   AND 15 < minute < 25
   AND activity = "exit";

-- With these results we now have nine suspects: Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana, Kelsey and Taylor. We will filter this list with the result of investigating the other witnesses statements.

-- Following up with the account withdraw and account number.
 SELECT bank_accounts.person_id, atm_transactions.account_number, name
   FROM atm_transactions
   JOIN bank_accounts
     ON atm_transactions.account_number = bank_accounts.account_number
   JOIN people
     ON bank_accounts.person_id = people.id
  WHERE day = 28
    AND month = 7
    AND year = 2021
    AND atm_location = "Leggett Street"
    AND transaction_type = "withdraw";

-- Following this investigation there are five matches "Bruce, Luca, Iman, Diana and Taylor", with a car at the time of the report from Ruth, and an atm withdraw from Leggett Street on the day of the crime.

-- We proceed the suspects who conducted a phonecall in the timeframe, following Raymond testimony.
SELECT caller, name
  FROM phone_calls
  JOIN people
    ON phone_calls.caller = people.phone_number
 WHERE day = 28
   AND month = 7
   AND year = 2021
   AND duration < 60;

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

SELECT airports.full_name
  FROM airports
  JOIN flights
    ON airports.id = flights.destination_airport_id
 WHERE flights.id = 36;

SELECT city
  FROM airports
 WHERE full_name = "LaGuardia Airport";


