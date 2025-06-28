SELECT DISTINCT Movies.title
FROM Movies
JOIN Stars ON Movies.id = Stars.movie_id
JOIN People AS Bradley_Cooper ON Bradley_Cooper.id = Stars.person_id AND Bradley_Cooper.name = 'Bradley Cooper'
JOIN Stars AS J_Law ON Movies.id = J_Law.movie_id
JOIN People AS Jennifer_Lawrence ON Jennifer_Lawrence.id = J_Law.person_id AND Jennifer_Lawrence.name = 'Jennifer Lawrence';
