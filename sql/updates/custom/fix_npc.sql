-- Fix jewelcrafting npc vendor
UPDATE creature_template SET gossip_menu_id = 0 WHERE entry = 50482;
-- Fix therazane reputation vendor
UPDATE creature_template SET gossip_menu_id = 0 WHERE entry = 45408;