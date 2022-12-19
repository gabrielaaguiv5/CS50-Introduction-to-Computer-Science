# Give count of titles from movie table, where from table ratings the rating is exactly 10.
SELECT COUNT(title) FROM movies WHERE id IN (SELECT movie_id FROM ratings WHERE rating = "10.0");