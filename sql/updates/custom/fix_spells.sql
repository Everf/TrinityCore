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

DELETE FROM spell_proc_event WHERE  entry IN (16487,16489,16492);
INSERT INTO spell_proc_event VALUES
(16487, 0, 0, 0, 0, 0, 0x00100000, 0x03, 0, 0, 0),
(16489, 0, 0, 0, 0, 0, 0x00100000, 0x03, 0, 0, 0),
(16492, 0, 0, 0, 0, 0, 0x00100000, 0x03, 0, 0, 0);

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

DELETE FROM spell_proc_event WHERE entry IN (49018,49529,49530);
INSERT INTO spell_proc_event VALUES
(49018, 0, 0, 0, 0, 0, 0x00000004, 0x0000003, 1.76, 0, 0),
(49529, 0, 0, 0, 0, 0, 0x00000004, 0x0000003, 3.37, 0, 0),
(49530, 0, 0, 0, 0, 0, 0x00000004, 0x0000003, 4.96, 0, 0);

DELETE FROM spell_script_names WHERE spell_id IN(96269,96270,87151,81659,81662,14523,81749,81751); 
INSERT INTO spell_script_names VALUES 
(96269, 'spell_dk_deaths_advance'),
(96270, 'spell_dk_deaths_advance'),
(87151, 'spell_pri_archangel'),
(81659, 'spell_pri_evangelism'),
(81662, 'spell_pri_evangelism'),
(14523, 'spell_pri_atonement'),
(81749, 'spell_pri_atonement'),
(81751, 'spell_pri_atonement_heal');

-- Inner focus remove aura
DELETE FROM spell_linked_spell WHERE spell_trigger IN (2060, 596,2061,32546);
INSERT INTO spell_linked_spell VALUES (2060, -89485, 0, 'Remove Inner focus');
INSERT INTO spell_linked_spell VALUES (596, -89485, 0, 'Remove Inner focus');
INSERT INTO spell_linked_spell VALUES (2061, -89485, 0, 'Remove Inner focus');
INSERT INTO spell_linked_spell VALUES (32546, -89485, 0, 'Remove Inner focus');

DELETE FROM spell_linked_spell WHERE spell_effect = -88688;
INSERT INTO spell_linked_spell VALUES
(101062, -88688, 0, 'Remove Surge of Light');

DELETE FROM spell_script_names WHERE ScriptName IN ('spell_pri_chakra');
INSERT INTO spell_script_names VALUES
(33076, 'spell_pri_chakra'),
(2060, 'spell_pri_chakra'),
(2061, 'spell_pri_chakra'),
(2050, 'spell_pri_chakra'),
(596, 'spell_pri_chakra'),
(73510, 'spell_pri_chakra'),
(32546, 'spell_pri_chakra'),
(585, 'spell_pri_chakra');

DELETE FROM spell_script_names WHERE spell_id IN (88685, 81585,77485);
INSERT INTO spell_script_names VALUES
(77485, 'spell_pri_echo_of_light'),
(81585, 'spell_pri_chakra_serenity'),
(88685, 'spell_pri_holy_word_sanctuary');

DELETE FROM spell_linked_spell WHERE spell_trigger = 14751;
INSERT INTO spell_linked_spell VALUES
(14751, -81208, 0, 'Remove other chakras'),
(14751, -81206, 0, 'Remove other chakras'),
(14751, -81209, 0, 'Remove other chakras'),
(14751, 95644, 0, 'Visual aura');

DELETE FROM spell_bonus_data WHERE entry IN (88686,139);
INSERT INTO spell_bonus_data VALUES
(88686, 0.043, 0, 0, 0, 'Priest - Holy word: Sanctuary'),
(139, -1, 0.131, -1, -1, 'Priest - Renew');

DELETE FROM spell_proc_event WHERE entry IN (77485,95740);
INSERT INTO spell_proc_event VALUES
(77485,0,0,0,0,0,0x00004000,0,0,0,0);

DELETE FROM spell_proc_event WHERE entry IN (-33191,-87099);
INSERT INTO spell_proc_event VALUES
(-87099, 0, 0, 0, 0, 0, 0, 0x0000002, 0, 0, 0),
(-33191, 0, 0, 0, 0, 0, 0, 0x0000002, 0, 0, 0);

DELETE FROM spell_script_names WHERE ScriptName IN ('spell_pri_shadow_orb', 'spell_pri_sin_and_punishment');
INSERT INTO spell_script_names VALUES
(73510, 'spell_pri_shadow_orb'),
(8092, 'spell_pri_shadow_orb'),
(87100, 'spell_pri_sin_and_punishment'),
(87099, 'spell_pri_sin_and_punishment');

UPDATE spell_bonus_data SET direct_bonus = 0.316 WHERE entry = 32379;

DELETE FROM spell_proc_event WHERE entry IN (-31828,20177, 20179,26016,-53486, -53709);
INSERT INTO spell_proc_event VALUES
(-31828, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8),
(20177, 0, 4, 0, 0, 0, 0, 0x0000040, 0, 0, 0),
(20179, 0, 4, 0, 0, 0, 0, 0x0000040, 0, 0, 0);

DELETE FROM spell_script_names WHERE ScriptName IN ('spell_pal_judgement','spell_pal_word_of_glory','spell_pal_light_of_dawn','spell_pal_illuminated_healing','spell_pal_guardian_ancient_kings','spell_pal_inquisiton','spell_pal_tower_of_radiance','spell_pal_speed_of_light');
INSERT INTO spell_script_names VALUES
(76669, 'spell_pal_illuminated_healing'),
(86150, 'spell_pal_guardian_ancient_kings'),
(84963, 'spell_pal_inquisiton'),
(-84800, 'spell_pal_tower_of_radiance'),
(85222, 'spell_pal_light_of_dawn'),
(85673, 'spell_pal_word_of_glory'),
(20271,'spell_pal_judgement'),
(498, 'spell_pal_speed_of_light');

DELETE FROM spell_bonus_data WHERE entry IN (87188, 87189, 85222,53600,85673,96172);
INSERT INTO spell_bonus_data VALUES
(85222, 0.132, 0, 0, 0, 'Paladin - Light of Dawn'),
(87188, 0.101, 0, 0, 0, 'Paladin - Enlightened Judgements Rank 1'),
(87189, 0.202, 0, 0, 0, 'Paladin - Enlightened Judgements Rank 2'),
(96172, 0, 0, 0, 0, 'Paladin - Hand of Light'),
(85673, 0.209, 0.209, 0.198, 0, 'Paladin - Word of Glory'),
(53600, 0, 0, 0.1, 0, 'Paladin - Shield of righteous');

DELETE FROM spell_script_names WHERE ScriptName IN ('spell_pal_hand_of_light', 'spell_pal_exorcism','spell_pal_judgements_of_the_wise_and_bold', 'spell_pal_consecration','spell_pal_shield_of_righteous');
INSERT INTO spell_script_names VALUES
(76672, 'spell_pal_hand_of_light'),
(53600, 'spell_pal_shield_of_righteous'),
(31930, 'spell_pal_judgements_of_the_wise_and_bold'),
(89906, 'spell_pal_judgements_of_the_wise_and_bold'),
(26573, 'spell_pal_consecration');

DELETE FROM spell_bonus_data WHERE entry IN (9799, 25988);
INSERT INTO spell_bonus_data VALUES
(9799, 0, 0, 0, 0, 'Paladin - Eye for an Eye Rank 1'),
(25988, 0, 0, 0, 0, 'Paladin - Eye for an Eye Rank 1');

UPDATE spell_proc_event SET procFlags = 0x00020000 WHERE entry = -9799;

DELETE FROM spell_script_names WHERE ScriptName IN ('spell_pal_divine_purpose','spell_pal_pursuit_of_justice','spell_pal_holy_wrath','spell_pal_sanctified_wrath');
INSERT INTO spell_script_names VALUES
(85177, 'spell_pal_divine_purpose'),
(86172, 'spell_pal_divine_purpose'),
(26022, 'spell_pal_pursuit_of_justice'),
(26023, 'spell_pal_pursuit_of_justice'),
(2812, 'spell_pal_holy_wrath'),
(31884, 'spell_pal_sanctified_wrath');

DELETE FROM spell_proc_event WHERE entry IN (85285);
INSERT INTO spell_proc_event VALUES
(85285, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60);
