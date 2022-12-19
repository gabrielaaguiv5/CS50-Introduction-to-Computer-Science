# Search for title in movies table, when the year of the movie is after or on 2018, going from oldest to newest.
SELECT title FROM movies WHERE year >= 2018 ORDER BY title ASC;