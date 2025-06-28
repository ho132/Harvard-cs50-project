SELECT title
FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN ratings r ON movies.id = r.movie_id
JOIN people ON stars.person_id = people.id
WHERE name = 'Chadwick Boseman'
ORDER BY r.rating DESC
LIMIT 5;
