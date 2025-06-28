SELECT DISTINCT p.name
FROM people p
JOIN stars s ON p.id = s.person_id
JOIN movies m ON m.id = s.movie_id
JOIN stars s_kb ON s_kb.movie_id = m.id
JOIN people kb ON kb.id = s_kb.person_id
WHERE kb.name = 'Kevin Bacon' AND kb.birth = 1958 AND p.name != 'Kevin Bacon';

