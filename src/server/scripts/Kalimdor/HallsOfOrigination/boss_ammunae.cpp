/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "halls_of_origination.h"

class boss_ammunae : public CreatureScript
{
public:
    boss_ammunae() : CreatureScript("boss_ammunae") { }

    struct boss_ammunaeAI : public BossAI
    {
        boss_ammunaeAI(Creature* creature) : BossAI(creature, DATA_AMMUNAE) { }

        void Reset() OVERRIDE
        {
            _Reset();
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            _EnterCombat();
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
        }

        void KilledUnit(Unit* victim) OVERRIDE
        {
        }

        void JustReachedHome() OVERRIDE
        {
            _JustReachedHome();
        }

        void DoAction(int32 action) OVERRIDE
        {
        }
        void UpdateAI(uint32 diff) OVERRIDE
        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetHallsOfOriginationAI<boss_ammunaeAI>(creature);
    }
};

void AddSC_boss_ammunae()
{
    new boss_ammunae();
}
