# Give avarage rating from ratings table, when year from movies tables is 2012.
SELECT AVG(rating) from ratings WHERE movie_id IN (SELECT id FROM movies WHERE year = "2012");