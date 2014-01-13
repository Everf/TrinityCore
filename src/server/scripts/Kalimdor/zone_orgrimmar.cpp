/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

enum
{
    QUEST_WEAPONS_OF_MASS_DYSFUNCTION   = 26294,
};

#define GOSSIP_SQUIRE_ITEM_1 "Discipline chief engineer"
#define GOSSIP_SQUIRE_ITEM_2 "Look for faulty demolisher"

class npc_chief_engineer_or_hellscream_demolisher : public CreatureScript
{
public:
    npc_chief_engineer_or_hellscream_demolisher() : CreatureScript("npc_chief_engineer_or_hellscream_demolisher") { }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (player->GetQuestStatus(QUEST_WEAPONS_OF_MASS_DYSFUNCTION) == QUEST_STATUS_INCOMPLETE)
        {
            if(creature->GetEntry() == 42671)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SQUIRE_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            else if (creature->GetEntry() == 42673)
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SQUIRE_ITEM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
        }

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->KilledMonsterCredit(42675);
            player->CLOSE_GOSSIP_MENU();
        }
        else if (action == GOSSIP_ACTION_INFO_DEF+2)
        {
            player->KilledMonsterCredit(42674);
            player->CLOSE_GOSSIP_MENU();
        }
        return true;
    }
};

void AddSC_orgrimmar()
{
    new npc_chief_engineer_or_hellscream_demolisher();
};
