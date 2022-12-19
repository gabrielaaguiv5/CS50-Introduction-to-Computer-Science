# Search title from movies table, giving back the Harry Potter movies from oldest to newest.
SELECT title, year FROM movies WHERE title LIKE "Harry Potter%" ORDER BY year ASC;