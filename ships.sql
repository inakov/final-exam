SELECT Classes.class, MIN(Batlles.date), MAX(Battles.date), COUNT(Battles.name)
FROM Classes JOIN Ships ON (Classes.class = Ships.class)
	JOIN Outcomes ON (Outomes.ship = Ships.name)
	JOIN Battles ON (Outcome.battle = Battles.name)
WHERE Class.class LIKE 'N%'
GROUP BY Class.class;

SELECT Outcome.battle
FROM Outcomes
WHERE Outcome.ship 
IN (SELECT name
	FROM (SELECT Ships.name, Count(Ships.name) as bbCount
		FROM Ships JOIN Classes ON (Ships.class = Classes.class)
		JOIN Outcomes ON (Outcomes.ship = Ships.name)
		WHERE Classes.type = 'bb') as bbShips
	JOIN (SELECT Ships.name, Count(Ships.name) as bcCount
		FROM Ships JOIN Classes ON (Ships.class = Classes.class)
		JOIN Outcomes ON (Outcomes.ship = Ships.name)
		WHERE Classes.type = 'bc') as bcShips
	ON (bbShips.battle = bcShips.battle)
	WHERE bbCount > bcCount);

