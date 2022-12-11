# Display table with only one output of average of the energy of all songs by Drake.
SELECT AVG(energy FROM songs WHERE artist_id IN (SELECT id FROM artists WHERE name = "Drake")) FROM songs;