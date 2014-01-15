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

/*enum
{
    QUEST_MADNESS   = 26549,
};

class npc_ornak : public CreatureScript
{
public:
    npc_ornak() : CreatureScript("npc_ornak") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) OVERRIDE
    {
        if (quest->GetQuestId() == QUEST_MADNESS)
            creature->CastSpell(creature, 80786, true); // Summon horde negotiator

        return true;
    }
};

#define GOSSIP_SQUIRE_ITEM_NEGOTIATOR "Acabar negociaciones"

class npc_horde_negotiator : public CreatureScript
{
public:
    npc_horde_negotiator() : CreatureScript("npc_horde_negotiator") { }

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (player->GetQuestStatus(QUEST_MADNESS) == QUEST_STATUS_INCOMPLETE)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SQUIRE_ITEM_NEGOTIATOR, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        }

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) OVERRIDE
    {
        player->PlayerTalkClass->ClearMenus();
        if (action == GOSSIP_ACTION_INFO_DEF+1)
        {
            player->KilledMonsterCredit(43243);
            player->CLOSE_GOSSIP_MENU();
        }
        return true;
    }
};*/

void AddSC_twilight_highlands()
{
    //new npc_ornak();
    //new npc_horde_negotiator();
};