#Display only top 5 longest songs, from longest to shortest.
SELECT name FROM songs ORDER BY length DESC LIMIT 5;