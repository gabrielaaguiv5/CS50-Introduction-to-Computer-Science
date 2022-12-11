# Display only top 5 longest songs, from longest to shortest.
SELECT name FROM songs ORDER BY duration_ms DESC LIMIT 5;