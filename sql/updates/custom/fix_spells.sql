DELETE FROM `spell_proc_event` WHERE `entry` IN (80979, 80980, 50685,50686,50687,80979, 84619, 84621, 84604, 46916, 12964, 56611, 46867, 20502, 20503,12329,12950,12322,85741,85742, 61216, 61221,46915,46914,46913);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(46867, 0, 4, 0x22200000, 0, 0, 0, 0x0000002, 0, 50, 0),
(56611, 0, 4, 0x22200000, 0, 0, 0, 0x0000002, 0, 100, 0),
(20502, 0, 4, 0x20000000,0,0,0,0,0,0,0),
(20503, 0, 4, 0x20000000,0,0,0,0,0,0,0),
(12950, 0, 4, 0x400000, 4,0,0,0,0,0,0),
(12329, 0, 4, 0x400000, 4,0,0,0,0,0,0),
(12322, 0, 4, 0x50010, 0, 0, 0, 0, 0, 0, 0),
(85741, 0, 4, 0x50010, 0, 0, 0, 0, 0, 0, 0),
(85742, 0, 4, 0x50010, 0, 0, 0, 0, 0, 0, 0),
(61216, 0, 4, 0x30000, 0x80, 0, 0, 0, 0, 0, 0),
(61221, 0, 4, 0x30000, 0x80, 0, 0, 0, 0, 0, 0),
(46913, 0, 4, 0x50010, 0, 0, 0, 0, 0, 0, 0),
(46914, 0, 4, 0x50010, 0, 0, 0, 0, 0, 0, 0),
(46915, 0, 4, 0x50010, 0, 0, 0, 0, 0, 0, 0),
(84604, 0, 4, 0, 0, 0, 0, 0x0000020, 0, 0, 0),
(84621, 0, 4, 0, 0, 0, 0, 0x0000020, 0, 0, 0),
(50685, 0, 4, 0x64, 0, 0, 0, 0, 0, 0, 0),
(50686, 0, 4, 0x64, 0, 0, 0, 0, 0, 0, 0),
(50687, 0, 4, 0x64, 0, 0, 0, 0, 0, 0, 0),
(80979, 0, 4, 0x8000, 0, 0, 0, 0, 0, 0, 0),
(80980, 0, 4, 0x8000, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM spell_script_names WHERE spell_id IN (23881, 12294, 23922);
INSERT INTO spell_script_names VALUES
(23881, 'spell_warr_battle_trance'),
(12294, 'spell_warr_battle_trance'),
(23922, 'spell_warr_battle_trance'),
(23881, 'spell_warr_bloodthirst_heal'),
(23881, 'spell_warr_bloodthirst');

DELETE FROM spell_script_names WHERE spell_id IN (845);
INSERT INTO spell_script_names VALUES (845, 'spell_warr_cleave');

DELETE FROM spell_script_names WHERE ScriptName = 'spell_warr_intercept';
INSERT INTO spell_script_names VALUES (20253, 'spell_warr_intercept');

DELETE FROM spell_linked_spell WHERE spell_trigger = 100;
INSERT INTO spell_linked_spell VALUES
(100, 7922, 0, 'Warrior Chargue stun');

DELETE FROM spell_linked_spell WHERE spell_trigger = 49028;
INSERT INTO spell_linked_spell
VALUES (49028,81256,0,'DK dancing rune weapon parry');