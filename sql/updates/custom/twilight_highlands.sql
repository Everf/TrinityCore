UPDATE creature_template SET npcflag = 1, gossip_menu_id = 14407, ScriptName = 'npc_chief_engineer_or_hellscream_demolisher' WHERE entry = 42671 OR entry = 42673;
UPDATE creature_template SET npcflag = 1, gossip_menu_id = 14407, ScriptName = 'npc_awol_troop' WHERE entry = 42646;
UPDATE creature_template SET npcflag = 1, gossip_menu_id = 14407, ScriptName = 'npc_bilgewater_dockworker' WHERE entry = 42775;
UPDATE creature_template SET npcflag = 1, ScriptName = 'npc_smoot' WHERE entry = 42644;
UPDATE quest_template SET ExclusiveGroup = 0 WHERE entry = 26372; -- temp fix
UPDATE quest_template SET Method = 0 WHERE entry = 26388;