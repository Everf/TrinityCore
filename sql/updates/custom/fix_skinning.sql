DELETE FROM skinning_loot_template
WHERE entry IN (46910,52795,40754,47263,41029,39348);
INSERT INTO skinning_loot_template VALUES
-- Loot type 1
(46910, 52976, 50, 1, 0, 1, 6),
(46910, 52977, 50, 1, 0, 2, 9),
(46910, 67495, 3, 1, 0, 1, 1),
-- Loot type 2
(52795, 52976, 100, 1, 0, 1, 6),
-- Loot type 3
(40754, 52976, 50, 1, 0, 1, 5),
(40754, 52977, 50, 1, 0, 2, 7),
(40754, 67495, 3, 1, 0, 1, 1),
(40754, 52979, 20, 1, 0, 1, 6),
-- Loot type 4
(47263, 52976, 50, 1, 0, 1, 2),
(47263, 52977, 50, 1, 0, 2, 5),
(47263, 67495, 4, 1, 0, 1, 1),
-- Loot type 5
(41029, 52976, 50, 1, 0, 1, 6),
(41029, 52977, 50, 1, 0, 2, 9),
(41029, 67495, 3, 1, 0, 1, 1),
(41029, 52979, 20, 1, 0, 1, 6),
-- Loot type 6
(40340, 52976, 55, 1, 0, 1, 4),
(40340, 52977, 55, 1, 0, 2, 9);

UPDATE creature_template SET skinloot = 46910 WHERE entry IN (46910);
UPDATE creature_template SET skinloot = 52795 WHERE entry IN (52795);
UPDATE creature_template SET skinloot = 46910 WHERE entry IN (40755);
UPDATE creature_template SET skinloot = 40754 WHERE entry IN (40754);
UPDATE creature_template SET skinloot = 46910 WHERE entry IN (40336);
UPDATE creature_template SET skinloot = 46910 WHERE entry IN (46925);
UPDATE creature_template SET skinloot = 39588 WHERE entry IN (39588);
UPDATE creature_template SET skinloot = 47263 WHERE entry IN (47263);
UPDATE creature_template SET skinloot = 40340 WHERE entry IN (40340);
UPDATE creature_template SET skinloot = 40340 WHERE entry IN (41614);
UPDATE creature_template SET skinloot = 46910 WHERE entry IN (40819);
UPDATE creature_template SET skinloot = 41029 WHERE entry IN (41226);
UPDATE creature_template SET skinloot = 46910 WHERE entry IN (39658);
UPDATE creature_template SET skinloot = 46910 WHERE entry IN (48724);
UPDATE creature_template SET skinloot = 46910 WHERE entry IN (40403);
UPDATE creature_template SET skinloot = 46910 WHERE entry IN (50058);
UPDATE creature_template SET skinloot = 41029 WHERE entry IN (41029);
UPDATE creature_template SET skinloot = 41029 WHERE entry IN (41030);
UPDATE creature_template SET skinloot = 41029 WHERE entry IN (41031);
UPDATE creature_template SET skinloot = 41029 WHERE entry IN (40687);
UPDATE creature_template SET skinloot = 40340 WHERE entry IN (39348);