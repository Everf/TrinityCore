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

/*
 * Scripts for spells with SPELLFAMILY_PRIEST and SPELLFAMILY_GENERIC spells used by priest players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_pri_".
 */

#include "Player.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GridNotifiers.h"

enum PriestSpells
{
    SPELL_PRIEST_ABSOLUTION                         = 33167,
    SPELL_PRIEST_BODY_AND_SOUL_DISPEL               = 64136,
    SPELL_PRIEST_BODY_AND_SOUL_SPEED                = 65081,
    SPELL_PRIEST_CURE_DISEASE                       = 528,
    SPELL_PRIEST_DISPEL_MAGIC_FRIENDLY              = 97690,
    SPELL_PRIEST_DISPEL_MAGIC_HOSTILE               = 97691,
    SPELL_PRIEST_DIVINE_AEGIS                       = 47753,
    SPELL_PRIEST_DIVINE_TOUCH                       = 63544,
    SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC              = 55677,
    SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC_HEAL         = 56131,
    SPELL_PRIEST_GLYPH_OF_LIGHTWELL                 = 55673,
    SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL    = 56161,
    SPELL_PRIEST_GLYPH_OF_SHADOW                    = 107906,
    SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL               = 48153,
    SPELL_PRIEST_ITEM_EFFICIENCY                    = 37595,
    SPELL_PRIEST_LEAP_OF_FAITH                      = 73325,
    SPELL_PRIEST_LEAP_OF_FAITH_EFFECT               = 92832,
    SPELL_PRIEST_LEAP_OF_FAITH_EFFECT_TRIGGER       = 92833,
    SPELL_PRIEST_LEAP_OF_FAITH_TRIGGERED            = 92572,
    SPELL_PRIEST_MANA_LEECH_PROC                    = 34650,
    SPELL_PRIEST_PENANCE_R1                         = 47540,
    SPELL_PRIEST_PENANCE_R1_DAMAGE                  = 47758,
    SPELL_PRIEST_PENANCE_R1_HEAL                    = 47757,
    SPELL_PRIEST_REFLECTIVE_SHIELD_R1               = 33201,
    SPELL_PRIEST_REFLECTIVE_SHIELD_TRIGGERED        = 33619,
    SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH    = 107903,
    SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH       = 107904,
    SPELL_PRIEST_SHADOW_WORD_PAIN                   = 589,
    SPELL_PRIEST_SHADOW_WORD_DEATH                  = 32409,
    SPELL_PRIEST_TWIN_DISCIPLINES_RANK_1            = 47586,
    SPELL_PRIEST_T9_HEALING_2P                      = 67201,
    SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL              = 15290,
    SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL              = 64085,
    SPELL_PRIEST_EVANGELISM_RANK_1                  = 81659,
    SPELL_PRIEST_EVANGELISM_RANK_2                  = 81662,
    SPELL_PRIEST_EVANGELISM_VISUAL_AURA             = 87154,
    SPELL_PRIEST_EVANGELISM_TRIGGERED_RANK_1        = 81660,
    SPELL_PRIEST_EVANGELISM_TRIGGERED_RANK_2        = 81661, 
    SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_RANK_1   = 87117,
    SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_RANK_2   = 87118,
    SPELL_PRIEST_ARCHANGEL                          = 87152,
    SPELL_PRIEST_ARCHANGEL_VISUAL_AURA              = 94709,
    SPELL_PRIEST_ARCHANGEL_MANA                     = 87152,
    SPELL_PRIEST_ARCHANGEL_TRIGGERED                = 81700,
    SPELL_PRIEST_DARK_ARCHANGEL_TRIGGERED           = 87153,
    SPELL_PRIEST_ATONEMENT_HEAL                     = 81751,
    SPELL_PRIEST_SMITE                              = 585,
    SPELL_PRIEST_HOLY_FIRE                          = 14914,
    SPELL_PRIEST_MIND_FLAY                          = 15407,
    SPELL_PRIEST_MIND_SPIKE                         = 73510,
    SPELL_PRIEST_MIND_SPIKE_AURA                    = 87178,
    SPELL_PRIEST_MIND_BLAST                         = 8092,
    SPELL_PRIEST_MIND_MELT_RANK_1                   = 14910,
    SPELL_PRIEST_MIND_MELT_RANK_2                   = 33371,
    SPELL_PRIEST_HEAL                               = 2050,
    SPELL_PRIEST_BINDING_HEAL                       = 32546,
    SPELL_PRIEST_FLASH_HEAL                         = 2061,
    SPELL_PRIEST_GREATER_HEAL                       = 2060,
    SPELL_PRIEST_PRAYER_OF_HEALING                  = 596,
    SPELL_PRIEST_PRAYER_OF_MENDING                  = 33076,
    SPELL_PRIEST_CHAKRA                             = 14751,
    SPELL_PRIEST_CHAKRA_SERENITY                    = 81208,
    SPELL_PRIEST_CHAKRA_SERENITY_AURA               = 81585,
    SPELL_PRIEST_CHAKRA_SANCTUARY                   = 81206,
    SPELL_PRIEST_CHAKRA_SANCTUARY_AURA              = 81207,
    SPELL_PRIEST_CHAKRA_CHASTISE                    = 81209,
    SPELL_PRIEST_REVELATIONS                        = 88627,
    SPELL_PRIEST_HOLY_WORD_SANCTUARY_HEAL           = 88686,
    SPELL_PRIEST_RENEW                              = 139,
    SPELL_PRIEST_ECHO_OF_LIGHT_MASTERY              = 77485,
    SPELL_PRIEST_ECHO_OF_LIGHT_HEAL                 = 77489,
    SPELL_PRIEST_SIN_AND_PUNISHMENT_RANK_1          = 87099,
    SPELL_PRIEST_SIN_AND_PUNISHMENT_RANK_2          = 87100,
    SPELL_PRIEST_SIN_AND_PUNISHMENT_FEAR            = 87204,
    SPELL_PRIEST_SHADOWFIEND                        = 34433,
    SPELL_PRIEST_SHADOW_ORB_MASTERY                 = 77486,
    SPELL_PRIEST_SHADOW_ORB                         = 77487,
};

enum PriestSpellIcons
{
    PRIEST_ICON_ID_BORROWED_TIME                    = 2899,
    PRIEST_ICON_ID_DIVINE_TOUCH_TALENT              = 3021,
    PRIEST_ICON_ID_PAIN_AND_SUFFERING               = 2874
};

enum MiscSpells
{
    SPELL_GEN_REPLENISHMENT                         = 57669
};

class RaidCheck
{
    public:
        explicit RaidCheck(Unit const* caster) : _caster(caster) { }

        bool operator()(WorldObject* obj) const
        {
            if (Unit* target = obj->ToUnit())
            return !_caster->IsInRaidWith(target);

            return true;
        }

    private:
        Unit const* _caster;
};

class spell_pri_body_and_soul : public SpellScriptLoader
{
    public:
        spell_pri_body_and_soul() : SpellScriptLoader("spell_pri_body_and_soul") { }

        class spell_pri_body_and_soul_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_body_and_soul_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_CURE_DISEASE) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PRIEST_BODY_AND_SOUL_DISPEL))
                    return false;
                return true;
            }

            void HandleEffectSpeedProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                // Proc only with Power Word: Shield or Leap of Faith
                if (!(eventInfo.GetDamageInfo()->GetSpellInfo()->SpellFamilyFlags[0] & 0x1 || eventInfo.GetDamageInfo()->GetSpellInfo()->SpellFamilyFlags[2] & 0x80000))
                    return;

                GetTarget()->CastCustomSpell(SPELL_PRIEST_BODY_AND_SOUL_SPEED, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), eventInfo.GetProcTarget(), true, NULL, aurEff);
            }

            void HandleEffectDispelProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                // Proc only with Cure Disease
                if (eventInfo.GetDamageInfo()->GetSpellInfo()->Id != SPELL_PRIEST_CURE_DISEASE || eventInfo.GetProcTarget() != GetTarget())
                    return;

                if (roll_chance_i(aurEff->GetAmount()))
                    GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_PRIEST_BODY_AND_SOUL_DISPEL, true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_pri_body_and_soul_AuraScript::HandleEffectSpeedProc, EFFECT_0, SPELL_AURA_DUMMY);
                OnEffectProc += AuraEffectProcFn(spell_pri_body_and_soul_AuraScript::HandleEffectDispelProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pri_body_and_soul_AuraScript();
        }
};

// 527 - Dispel magic
class spell_pri_dispel_magic : public SpellScriptLoader
{
public:
    spell_pri_dispel_magic() : SpellScriptLoader("spell_pri_dispel_magic") { }

    class spell_pri_dispel_magic_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pri_dispel_magic_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/)
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_ABSOLUTION))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC_HEAL))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC))
                return false;
            return true;
        }

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            Unit* target = GetExplTargetUnit();

            if (!target || (!caster->HasAura(SPELL_PRIEST_ABSOLUTION) && caster != target && target->IsFriendlyTo(caster)))
                return SPELL_FAILED_BAD_TARGETS;
            return SPELL_CAST_OK;
        }

        void AfterEffectHit(SpellEffIndex /*effIndex*/)
        {
            if (GetHitUnit()->IsFriendlyTo(GetCaster()))
            {
                GetCaster()->CastSpell(GetHitUnit(), SPELL_PRIEST_DISPEL_MAGIC_FRIENDLY, true);
                if (AuraEffect const* aurEff = GetHitUnit()->GetAuraEffect(SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC, EFFECT_0))
                {
                    int32 heal = GetHitUnit()->CountPctFromMaxHealth(aurEff->GetAmount());
                    GetCaster()->CastCustomSpell(SPELL_PRIEST_GLYPH_OF_DISPEL_MAGIC_HEAL, SPELLVALUE_BASE_POINT0, heal, GetHitUnit());
                }
            }
            else
                GetCaster()->CastSpell(GetHitUnit(), SPELL_PRIEST_DISPEL_MAGIC_HOSTILE, true);
        }

        void Register()
        {
            OnCheckCast += SpellCheckCastFn(spell_pri_dispel_magic_SpellScript::CheckCast);
            OnEffectHitTarget += SpellEffectFn(spell_pri_dispel_magic_SpellScript::AfterEffectHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_pri_dispel_magic_SpellScript();
    }
};

// -47509 - Divine Aegis
class spell_pri_divine_aegis : public SpellScriptLoader
{
    public:
        spell_pri_divine_aegis() : SpellScriptLoader("spell_pri_divine_aegis") { }

        class spell_pri_divine_aegis_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_divine_aegis_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_DIVINE_AEGIS))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetProcTarget();
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                int32 absorb = CalculatePct(int32(eventInfo.GetHealInfo()->GetHeal()), aurEff->GetAmount());

                // Multiple effects stack, so let's try to find this aura.
                if (AuraEffect const* aegis = eventInfo.GetProcTarget()->GetAuraEffect(SPELL_PRIEST_DIVINE_AEGIS, EFFECT_0))
                    absorb += aegis->GetAmount();

                absorb = std::min(absorb, eventInfo.GetProcTarget()->getLevel() * 125);

                GetTarget()->CastCustomSpell(SPELL_PRIEST_DIVINE_AEGIS, SPELLVALUE_BASE_POINT0, absorb, eventInfo.GetProcTarget(), true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                DoCheckProc += AuraCheckProcFn(spell_pri_divine_aegis_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_divine_aegis_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pri_divine_aegis_AuraScript();
        }
};

// 55680 - Glyph of Prayer of Healing
class spell_pri_glyph_of_prayer_of_healing : public SpellScriptLoader
{
    public:
        spell_pri_glyph_of_prayer_of_healing() : SpellScriptLoader("spell_pri_glyph_of_prayer_of_healing") { }

        class spell_pri_glyph_of_prayer_of_healing_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_glyph_of_prayer_of_healing_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                SpellInfo const* triggeredSpellInfo = sSpellMgr->GetSpellInfo(SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL);
                int32 heal = int32(CalculatePct(int32(eventInfo.GetHealInfo()->GetHeal()), aurEff->GetAmount()) / triggeredSpellInfo->GetMaxTicks());
                GetTarget()->CastCustomSpell(SPELL_PRIEST_GLYPH_OF_PRAYER_OF_HEALING_HEAL, SPELLVALUE_BASE_POINT0, heal, eventInfo.GetProcTarget(), true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_pri_glyph_of_prayer_of_healing_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pri_glyph_of_prayer_of_healing_AuraScript();
        }
};

class spell_pri_improved_power_word_shield : public SpellScriptLoader
{
    public:
        spell_pri_improved_power_word_shield() : SpellScriptLoader("spell_pri_improved_power_word_shield") { }

        class spell_pri_improved_power_word_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_improved_power_word_shield_AuraScript);

            void HandleEffectCalcSpellMod(AuraEffect const* aurEff, SpellModifier*& spellMod)
            {
                if (!spellMod)
                {
                    spellMod = new SpellModifier(GetAura());
                    spellMod->op = SpellModOp(aurEff->GetMiscValue());
                    spellMod->type = SPELLMOD_PCT;
                    spellMod->spellId = GetId();
                    spellMod->mask = GetSpellInfo()->Effects[aurEff->GetEffIndex()].SpellClassMask;
                }

                spellMod->value = aurEff->GetAmount();
            }

            void Register() OVERRIDE
            {
                DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(spell_pri_improved_power_word_shield_AuraScript::HandleEffectCalcSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pri_improved_power_word_shield_AuraScript();
        }
};

// 37594 - Greater Heal Refund
class spell_pri_item_greater_heal_refund : public SpellScriptLoader
{
    public:
        spell_pri_item_greater_heal_refund() : SpellScriptLoader("spell_pri_item_greater_heal_refund") { }

        class spell_pri_item_greater_heal_refund_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_item_greater_heal_refund_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_ITEM_EFFICIENCY))
                    return false;
                return true;
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_PRIEST_ITEM_EFFICIENCY, true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_pri_item_greater_heal_refund_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pri_item_greater_heal_refund_AuraScript();
        }
};

// 47788 - Guardian Spirit
class spell_pri_guardian_spirit : public SpellScriptLoader
{
    public:
        spell_pri_guardian_spirit() : SpellScriptLoader("spell_pri_guardian_spirit") { }

        class spell_pri_guardian_spirit_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_guardian_spirit_AuraScript);

            uint32 healPct;

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL))
                    return false;
                return true;
            }

            bool Load() OVERRIDE
            {
                healPct = GetSpellInfo()->Effects[EFFECT_1].CalcValue();
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                // Set absorbtion amount to unlimited
                amount = -1;
            }

            void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                Unit* target = GetTarget();
                if (dmgInfo.GetDamage() < target->GetHealth())
                    return;

                int32 healAmount = int32(target->CountPctFromMaxHealth(healPct));
                // remove the aura now, we don't want 40% healing bonus
                Remove(AURA_REMOVE_BY_ENEMY_SPELL);
                target->CastCustomSpell(target, SPELL_PRIEST_GUARDIAN_SPIRIT_HEAL, &healAmount, NULL, NULL, true);
                absorbAmount = dmgInfo.GetDamage();
            }

            void Register() OVERRIDE
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_guardian_spirit_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_pri_guardian_spirit_AuraScript::Absorb, EFFECT_1);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pri_guardian_spirit_AuraScript();
        }
};

// 92833 - Leap of Faith
class spell_pri_leap_of_faith_effect_trigger : public SpellScriptLoader
{
    public:
        spell_pri_leap_of_faith_effect_trigger() : SpellScriptLoader("spell_pri_leap_of_faith_effect_trigger") { }

        class spell_pri_leap_of_faith_effect_trigger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_leap_of_faith_effect_trigger_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_LEAP_OF_FAITH_EFFECT))
                    return false;
                return true;
            }

            void HandleEffectDummy(SpellEffIndex /*effIndex*/)
            {
                Position destPos;
                GetHitDest()->GetPosition(&destPos);

                SpellCastTargets targets;
                targets.SetDst(destPos);
                targets.SetUnitTarget(GetCaster());
                GetHitUnit()->CastSpell(targets, sSpellMgr->GetSpellInfo(GetEffectValue()), NULL);
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pri_leap_of_faith_effect_trigger_SpellScript::HandleEffectDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pri_leap_of_faith_effect_trigger_SpellScript();
        }
};

// 7001 - Lightwell Renew
class spell_pri_lightwell_renew : public SpellScriptLoader
{
    public:
        spell_pri_lightwell_renew() : SpellScriptLoader("spell_pri_lightwell_renew") { }

        class spell_pri_lightwell_renew_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_lightwell_renew_AuraScript);

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                if (Unit* caster = GetCaster())
                {
                    // Bonus from Glyph of Lightwell
                    if (AuraEffect* modHealing = caster->GetAuraEffect(SPELL_PRIEST_GLYPH_OF_LIGHTWELL, EFFECT_0))
                        AddPct(amount, modHealing->GetAmount());
                }
            }

            void Register() OVERRIDE
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_lightwell_renew_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_PERIODIC_HEAL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pri_lightwell_renew_AuraScript();
        }
};

// 8129 - Mana Burn
class spell_pri_mana_burn : public SpellScriptLoader
{
    public:
        spell_pri_mana_burn() : SpellScriptLoader("spell_pri_mana_burn") { }

        class spell_pri_mana_burn_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_mana_burn_SpellScript);

            void HandleAfterHit()
            {
                if (Unit* unitTarget = GetHitUnit())
                    unitTarget->RemoveAurasWithMechanic((1 << MECHANIC_FEAR) | (1 << MECHANIC_POLYMORPH));
            }

            void Register() OVERRIDE
            {
                AfterHit += SpellHitFn(spell_pri_mana_burn_SpellScript::HandleAfterHit);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pri_mana_burn_SpellScript;
        }
};

// 28305 - Mana Leech (Passive) (Priest Pet Aura)
class spell_pri_mana_leech : public SpellScriptLoader
{
    public:
        spell_pri_mana_leech() : SpellScriptLoader("spell_pri_mana_leech") { }

        class spell_pri_mana_leech_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_mana_leech_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_MANA_LEECH_PROC))
                    return false;
                return true;
            }

            bool Load() OVERRIDE
            {
                _procTarget = NULL;
                return true;
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                _procTarget = GetTarget()->GetOwner();
                return _procTarget;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(_procTarget, SPELL_PRIEST_MANA_LEECH_PROC, true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                DoCheckProc += AuraCheckProcFn(spell_pri_mana_leech_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_mana_leech_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }

        private:
            Unit* _procTarget;
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pri_mana_leech_AuraScript();
        }
};

// 49821 - Mind Sear
class spell_pri_mind_sear : public SpellScriptLoader
{
    public:
        spell_pri_mind_sear() : SpellScriptLoader("spell_pri_mind_sear") { }

        class spell_pri_mind_sear_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_mind_sear_SpellScript);

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                unitList.remove_if(Trinity::ObjectGUIDCheck(GetCaster()->GetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT)));
            }

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_mind_sear_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pri_mind_sear_SpellScript();
        }
};

// 47948 - Pain and Suffering (Proc)
class spell_pri_pain_and_suffering_proc : public SpellScriptLoader
{
    public:
        spell_pri_pain_and_suffering_proc() : SpellScriptLoader("spell_pri_pain_and_suffering_proc") { }

        class spell_pri_pain_and_suffering_proc_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_pain_and_suffering_proc_SpellScript);

            void HandleEffectScriptEffect(SpellEffIndex /*effIndex*/)
            {
                // Refresh Shadow Word: Pain on target
                if (Unit* unitTarget = GetHitUnit())
                    if (AuraEffect* aur = unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_PRIEST, 0x8000, 0, 0, GetCaster()->GetGUID()))
                        aur->GetBase()->RefreshDuration();
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pri_pain_and_suffering_proc_SpellScript::HandleEffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pri_pain_and_suffering_proc_SpellScript;
        }
};

// 47540 - Penance
class spell_pri_penance : public SpellScriptLoader
{
    public:
        spell_pri_penance() : SpellScriptLoader("spell_pri_penance") { }

        class spell_pri_penance_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_penance_SpellScript);

            bool Load() OVERRIDE
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            bool Validate(SpellInfo const* spellInfo) OVERRIDE
            {
                SpellInfo const* firstRankSpellInfo = sSpellMgr->GetSpellInfo(SPELL_PRIEST_PENANCE_R1);
                if (!firstRankSpellInfo)
                    return false;

                // can't use other spell than this penance due to spell_ranks dependency
                if (!spellInfo->IsRankOf(firstRankSpellInfo))
                    return false;

                uint8 rank = spellInfo->GetRank();
                if (!sSpellMgr->GetSpellWithRank(SPELL_PRIEST_PENANCE_R1_DAMAGE, rank, true))
                    return false;
                if (!sSpellMgr->GetSpellWithRank(SPELL_PRIEST_PENANCE_R1_HEAL, rank, true))
                    return false;

                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* unitTarget = GetHitUnit())
                {
                    if (!unitTarget->IsAlive())
                        return;

                    uint8 rank = GetSpellInfo()->GetRank();

                    if (caster->IsFriendlyTo(unitTarget))
                        caster->CastSpell(unitTarget, sSpellMgr->GetSpellWithRank(SPELL_PRIEST_PENANCE_R1_HEAL, rank), false);
                    else
                        caster->CastSpell(unitTarget, sSpellMgr->GetSpellWithRank(SPELL_PRIEST_PENANCE_R1_DAMAGE, rank), false);
                }
            }

            SpellCastResult CheckCast()
            {
                Player* caster = GetCaster()->ToPlayer();
                if (Unit* target = GetExplTargetUnit())
                    if (!caster->IsFriendlyTo(target) && !caster->IsValidAttackTarget(target))
                        return SPELL_FAILED_BAD_TARGETS;
                return SPELL_CAST_OK;
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pri_penance_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnCheckCast += SpellCheckCastFn(spell_pri_penance_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pri_penance_SpellScript;
        }
};

// -47569 - Phantasm
class spell_pri_phantasm : public SpellScriptLoader
{
    public:
        spell_pri_phantasm() : SpellScriptLoader("spell_pri_phantasm") { }

        class spell_pri_phantasm_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_phantasm_AuraScript);

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                return roll_chance_i(GetEffect(EFFECT_0)->GetAmount());
            }

            void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->RemoveMovementImpairingAuras();
            }

            void Register() OVERRIDE
            {
                DoCheckProc += AuraCheckProcFn(spell_pri_phantasm_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_phantasm_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pri_phantasm_AuraScript();
        }
};

// 17 - Power Word: Shield
class spell_pri_power_word_shield : public SpellScriptLoader
{
    public:
        spell_pri_power_word_shield() : SpellScriptLoader("spell_pri_power_word_shield") { }

        class spell_pri_power_word_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_power_word_shield_AuraScript);

            void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)
            {
                canBeRecalculated = false;
                if (Unit* caster = GetCaster())
                {
                    // +87% from sp bonus
                    float bonus = 0.87f;

                    // Borrowed Time
                    if (AuraEffect const* borrowedTime = caster->GetDummyAuraEffect(SPELLFAMILY_PRIEST, PRIEST_ICON_ID_BORROWED_TIME, EFFECT_1))
                        bonus += CalculatePct(1.0f, borrowedTime->GetAmount());

                    bonus *= caster->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask());

                    // Improved PW: Shield: its weird having a SPELLMOD_ALL_EFFECTS here but its blizzards doing :)
                    // Improved PW: Shield is only applied at the spell healing bonus because it was already applied to the base value in CalculateSpellDamage
                    bonus = caster->ApplyEffectModifiers(GetSpellInfo(), aurEff->GetEffIndex(), bonus);
                    bonus *= caster->CalculateLevelPenalty(GetSpellInfo());

                    amount += int32(bonus);

                    // Twin Disciplines
                    if (AuraEffect const* twinDisciplines = caster->GetAuraEffectOfRankedSpell(SPELL_PRIEST_TWIN_DISCIPLINES_RANK_1, EFFECT_1))
                        AddPct(amount, twinDisciplines->GetAmount());

                    // Focused Power
                    amount *= caster->GetTotalAuraMultiplier(SPELL_AURA_MOD_HEALING_DONE_PERCENT);
                }
            }

            void ReflectDamage(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
            {
                Unit* target = GetTarget();
                if (dmgInfo.GetAttacker() == target)
                    return;

                if (AuraEffect const* talentAurEff = target->GetAuraEffectOfRankedSpell(SPELL_PRIEST_REFLECTIVE_SHIELD_R1, EFFECT_0))
                {
                    int32 bp = CalculatePct(absorbAmount, talentAurEff->GetAmount());
                    target->CastCustomSpell(dmgInfo.GetAttacker(), SPELL_PRIEST_REFLECTIVE_SHIELD_TRIGGERED, &bp, NULL, NULL, true, NULL, aurEff);
                }
            }

            void Register() OVERRIDE
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pri_power_word_shield_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                AfterEffectAbsorb += AuraEffectAbsorbFn(spell_pri_power_word_shield_AuraScript::ReflectDamage, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pri_power_word_shield_AuraScript();
        }
};

// 33110 - Prayer of Mending Heal
class spell_pri_prayer_of_mending_heal : public SpellScriptLoader
{
    public:
        spell_pri_prayer_of_mending_heal() : SpellScriptLoader("spell_pri_prayer_of_mending_heal") { }

        class spell_pri_prayer_of_mending_heal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_prayer_of_mending_heal_SpellScript);

            void HandleHeal(SpellEffIndex /*effIndex*/)
            {
                if (Unit* caster = GetOriginalCaster())
                {
                    if (AuraEffect* aurEff = caster->GetAuraEffect(SPELL_PRIEST_T9_HEALING_2P, EFFECT_0))
                    {
                        int32 heal = GetHitHeal();
                        AddPct(heal, aurEff->GetAmount());
                        SetHitHeal(heal);
                    }
                }
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pri_prayer_of_mending_heal_SpellScript::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pri_prayer_of_mending_heal_SpellScript();
        }
};

// 139 - Renew
class spell_pri_renew : public SpellScriptLoader
{
    public:
        spell_pri_renew() : SpellScriptLoader("spell_pri_renew") { }

        class spell_pri_renew_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_renew_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_DIVINE_TOUCH))
                    return false;
                return true;
            }

            bool Load() OVERRIDE
            {
                return GetCaster() && GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleApplyEffect(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    // Divine Touch
                    if (AuraEffect const* empoweredRenewAurEff = caster->GetDummyAuraEffect(SPELLFAMILY_PRIEST, PRIEST_ICON_ID_DIVINE_TOUCH_TALENT, EFFECT_0))
                    {
                        uint32 heal = caster->SpellHealingBonusDone(GetTarget(), GetSpellInfo(), aurEff->GetAmount(), DOT);
                        heal = GetTarget()->SpellHealingBonusTaken(caster, GetSpellInfo(), heal, DOT);
                        int32 basepoints0 = CalculatePct(int32(heal) * aurEff->GetTotalTicks(), empoweredRenewAurEff->GetAmount());
                        caster->CastCustomSpell(GetTarget(), SPELL_PRIEST_DIVINE_TOUCH, &basepoints0, NULL, NULL, true, NULL, aurEff);
                    }
                }
            }

            void Register() OVERRIDE
            {
                OnEffectApply += AuraEffectApplyFn(spell_pri_renew_AuraScript::HandleApplyEffect, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pri_renew_AuraScript();
        }
};

// 32379 - Shadow Word Death
class spell_pri_shadow_word_death : public SpellScriptLoader
{
    public:
        spell_pri_shadow_word_death() : SpellScriptLoader("spell_pri_shadow_word_death") { }

        class spell_pri_shadow_word_death_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_shadow_word_death_SpellScript);

            void HandleDamage()
            {
                int32 damage = GetHitDamage();

                // Damage x 3 if target has <25% hp
                if(GetHitUnit()->HealthBelowPct(25))
                {
                    damage *= 3;
                    if (Aura* aura = GetCaster()->GetAura(SPELL_PRIEST_MIND_MELT_RANK_1))
                        AddPct(damage,aura->GetEffect(EFFECT_0)->GetAmount());
                    else if (Aura* aura = GetCaster()->GetAura(SPELL_PRIEST_MIND_MELT_RANK_2))
                        AddPct(damage,aura->GetEffect(EFFECT_0)->GetAmount());
                }
                SetHitDamage(damage);

                int32 selfDamage = damage;
                // Pain and Suffering reduces damage
                if (AuraEffect* aurEff = GetCaster()->GetDummyAuraEffect(SPELLFAMILY_PRIEST, PRIEST_ICON_ID_PAIN_AND_SUFFERING, EFFECT_1))
                    AddPct(selfDamage, aurEff->GetAmount());

                GetCaster()->CastCustomSpell(GetCaster(), SPELL_PRIEST_SHADOW_WORD_DEATH, &selfDamage, 0, 0, true);
            }

            void Register() OVERRIDE
            {
                OnHit += SpellHitFn(spell_pri_shadow_word_death_SpellScript::HandleDamage);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pri_shadow_word_death_SpellScript();
        }
};

// 15473 - Shadowform
class spell_pri_shadowform : public SpellScriptLoader
{
    public:
        spell_pri_shadowform() : SpellScriptLoader("spell_pri_shadowform") { }

        class spell_pri_shadowform_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_shadowform_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH))
                    return false;
                return true;
            }

            void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->CastSpell(GetTarget(), GetTarget()->HasAura(SPELL_PRIEST_GLYPH_OF_SHADOW) ? SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH : SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH, true);
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->RemoveAurasDueToSpell(GetTarget()->HasAura(SPELL_PRIEST_GLYPH_OF_SHADOW) ? SPELL_PRIEST_SHADOWFORM_VISUAL_WITH_GLYPH : SPELL_PRIEST_SHADOWFORM_VISUAL_WITHOUT_GLYPH);
            }

            void Register() OVERRIDE
            {
                AfterEffectApply += AuraEffectApplyFn(spell_pri_shadowform_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                AfterEffectRemove += AuraEffectRemoveFn(spell_pri_shadowform_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_MOD_SHAPESHIFT, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pri_shadowform_AuraScript();
        }
};

// 15286 - Vampiric Embrace
class spell_pri_vampiric_embrace : public SpellScriptLoader
{
    public:
        spell_pri_vampiric_embrace() : SpellScriptLoader("spell_pri_vampiric_embrace") { }

        class spell_pri_vampiric_embrace_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_vampiric_embrace_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                // Not proc from Mind Sear
                return !(eventInfo.GetDamageInfo()->GetSpellInfo()->SpellFamilyFlags[1] & 0x80000);
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 self = int32(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount()));
                int32 team = int32(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount() / 2));

                GetTarget()->CastCustomSpell((Unit*)NULL, SPELL_PRIEST_VAMPIRIC_EMBRACE_HEAL, &team, &self, NULL, true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                DoCheckProc += AuraCheckProcFn(spell_pri_vampiric_embrace_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_vampiric_embrace_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pri_vampiric_embrace_AuraScript();
        }
};

// 15290 - Vampiric Embrace (heal)
class spell_pri_vampiric_embrace_target : public SpellScriptLoader
{
    public:
        spell_pri_vampiric_embrace_target() : SpellScriptLoader("spell_pri_vampiric_embrace_target") { }

        class spell_pri_vampiric_embrace_target_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_vampiric_embrace_target_SpellScript);

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                unitList.remove(GetCaster());
            }

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_vampiric_embrace_target_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_PARTY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pri_vampiric_embrace_target_SpellScript();
        }
};

// 34914 - Vampiric Touch
class spell_pri_vampiric_touch : public SpellScriptLoader
{
    public:
        spell_pri_vampiric_touch() : SpellScriptLoader("spell_pri_vampiric_touch") { }

        class spell_pri_vampiric_touch_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_vampiric_touch_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL) ||
                    !sSpellMgr->GetSpellInfo(SPELL_GEN_REPLENISHMENT))
                    return false;
                return true;
            }

            void HandleDispel(DispelInfo* /*dispelInfo*/)
            {
                if (Unit* caster = GetCaster())
                    if (Unit* target = GetUnitOwner())
                        if (AuraEffect const* aurEff = GetEffect(EFFECT_1))
                        {                            
                            if(caster->HasAura(SPELL_PRIEST_SIN_AND_PUNISHMENT_RANK_2) || (caster->HasAura(SPELL_PRIEST_SIN_AND_PUNISHMENT_RANK_1) && roll_chance_i(50)))
                                target->CastSpell(target, SPELL_PRIEST_SIN_AND_PUNISHMENT_FEAR, true);

                            int32 damage = aurEff->GetAmount() * 8;
                            // backfire damage
                            caster->CastCustomSpell(target, SPELL_PRIEST_VAMPIRIC_TOUCH_DISPEL, &damage, NULL, NULL, true, NULL, aurEff);
                        }
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetProcTarget() == GetCaster();
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                eventInfo.GetProcTarget()->CastSpell((Unit*)NULL, SPELL_GEN_REPLENISHMENT, true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                AfterDispel += AuraDispelFn(spell_pri_vampiric_touch_AuraScript::HandleDispel);
                DoCheckProc += AuraCheckProcFn(spell_pri_vampiric_touch_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_vampiric_touch_AuraScript::HandleEffectProc, EFFECT_2, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pri_vampiric_touch_AuraScript();
        }
};

class spell_pri_evangelism : public SpellScriptLoader
{
    public:
        spell_pri_evangelism() : SpellScriptLoader("spell_pri_evangelism") { }

        class spell_pri_evangelism_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_evangelism_AuraScript);

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return (eventInfo.GetDamageInfo()->GetSpellInfo()->Id == SPELL_PRIEST_SMITE ||
                    eventInfo.GetDamageInfo()->GetSpellInfo()->Id == SPELL_PRIEST_HOLY_FIRE ||
                    eventInfo.GetDamageInfo()->GetSpellInfo()->Id == SPELL_PRIEST_MIND_FLAY);
            }

            void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetCaster()->CastCustomSpell(SPELL_PRIEST_ARCHANGEL_VISUAL_AURA, SPELLVALUE_BASE_POINT0, 0, GetCaster(), TRIGGERED_CAST_DIRECTLY);
                GetCaster()->CastSpell(GetCaster(), SPELL_PRIEST_EVANGELISM_VISUAL_AURA, true);
                if(GetCaster()->GetShapeshiftForm() == FORM_SHADOW)
                {
                    if(GetCaster()->HasAura(SPELL_PRIEST_EVANGELISM_RANK_1))
                    {
                        GetCaster()->RemoveAurasDueToSpell(SPELL_PRIEST_EVANGELISM_TRIGGERED_RANK_1);
                        GetCaster()->CastSpell(GetCaster(), SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_RANK_1, true);
                    }
                    else if (GetCaster()->HasAura(SPELL_PRIEST_EVANGELISM_RANK_2))
                    {
                        GetCaster()->RemoveAurasDueToSpell(SPELL_PRIEST_EVANGELISM_TRIGGERED_RANK_2);
                        GetCaster()->CastSpell(GetCaster(), SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_RANK_2, true);
                    }
                }
                else
                {
                    if(GetCaster()->HasAura(SPELL_PRIEST_EVANGELISM_RANK_1))
                    {
                        GetCaster()->RemoveAurasDueToSpell(SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_RANK_1);
                        GetCaster()->CastSpell(GetCaster(), SPELL_PRIEST_EVANGELISM_TRIGGERED_RANK_1, true);
                    }
                    else if (GetCaster()->HasAura(SPELL_PRIEST_EVANGELISM_RANK_2))
                    {
                        GetCaster()->RemoveAurasDueToSpell(SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_RANK_2);
                        GetCaster()->CastSpell(GetCaster(), SPELL_PRIEST_EVANGELISM_TRIGGERED_RANK_2, true);
                    }
                }
                // Aura without duration, should be 20 seconds
                if(Aura *pAura = GetCaster()->GetAura(SPELL_PRIEST_ARCHANGEL_VISUAL_AURA))
                    pAura->SetDuration(20000);
            }

            void Register() OVERRIDE
            {
                DoCheckProc += AuraCheckProcFn(spell_pri_evangelism_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_evangelism_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pri_evangelism_AuraScript();
        }
};

class spell_pri_archangel : public SpellScriptLoader
{
    public:
        spell_pri_archangel() : SpellScriptLoader("spell_pri_archangel") { }

        class spell_pri_archangel_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_archangel_SpellScript);

            void HandleEffectScriptEffect(SpellEffIndex /*effIndex*/)
            {
                Aura *pAura = NULL;
                uint32 stacks = 0;
                if (pAura = GetCaster()->GetAura(SPELL_PRIEST_EVANGELISM_TRIGGERED_RANK_2))
                {
                    stacks = pAura->GetStackAmount();
                    int32 bp = 3 * stacks;
                    int32 bp1 = stacks;
                    GetCaster()->CastCustomSpell(GetCaster(), SPELL_PRIEST_ARCHANGEL_TRIGGERED, &bp, NULL, NULL, true);
                    GetCaster()->CastCustomSpell(GetCaster(), SPELL_PRIEST_ARCHANGEL_MANA, &bp1, NULL, NULL, true);
                    GetCaster()->RemoveAurasDueToSpell(SPELL_PRIEST_EVANGELISM_TRIGGERED_RANK_2);
                }
                else if (pAura = GetCaster()->GetAura(SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_RANK_2))
                {
                    stacks = pAura->GetStackAmount();
                    int32 bp = 4 * stacks;
                    int32 bp1 = 5 * stacks;
                    GetCaster()->CastCustomSpell(GetCaster(), SPELL_PRIEST_DARK_ARCHANGEL_TRIGGERED, &bp, &bp, NULL, true);
                    GetCaster()->CastCustomSpell(GetCaster(), SPELL_PRIEST_ARCHANGEL_MANA, &bp1, NULL, NULL, true);
                    GetCaster()->RemoveAurasDueToSpell(SPELL_PRIEST_DARK_EVANGELISM_TRIGGERED_RANK_2);
                }
                GetCaster()->RemoveAurasDueToSpell(SPELL_PRIEST_ARCHANGEL_VISUAL_AURA);
                GetCaster()->RemoveAurasDueToSpell(SPELL_PRIEST_EVANGELISM_VISUAL_AURA);
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pri_archangel_SpellScript::HandleEffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pri_archangel_SpellScript;
        }
};

class spell_pri_atonement : public SpellScriptLoader
{
    public:
        spell_pri_atonement() : SpellScriptLoader("spell_pri_atonement") { }

        class spell_pri_atonement_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_atonement_AuraScript);

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return (eventInfo.GetDamageInfo()->GetSpellInfo()->Id == SPELL_PRIEST_SMITE ||
                    (eventInfo.GetDamageInfo()->GetSpellInfo()->Id == SPELL_PRIEST_HOLY_FIRE));
            }

            void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 bp = eventInfo.GetDamageInfo()->GetDamage();
                GetCaster()->CastCustomSpell(NULL, SPELL_PRIEST_ATONEMENT_HEAL, &bp, NULL, NULL, true);
            }

            void Register() OVERRIDE
            {
                DoCheckProc += AuraCheckProcFn(spell_pri_atonement_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_atonement_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);           
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pri_atonement_AuraScript();
        }
};

class spell_pri_atonement_heal : public SpellScriptLoader
{
    public:
        spell_pri_atonement_heal() : SpellScriptLoader("spell_pri_atonement_heal") { }

        class spell_pri_atonement_heal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_atonement_heal_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                // TODO: Should target low HP raid member in range
                targets.remove_if(RaidCheck(GetCaster()));
                targets.resize(1);
            }

            void HandleHeal(SpellEffIndex /*effIndex*/)
            {
                int32 heal = GetEffectValue();
                if(GetCaster() == GetHitUnit())
                    heal *= 0.5f;

                SetHitHeal(heal);
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pri_atonement_heal_SpellScript::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pri_atonement_heal_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY); 
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pri_atonement_heal_SpellScript();
        }
};

class spell_pri_chakra : public SpellScriptLoader
{
    public:
        spell_pri_chakra() : SpellScriptLoader("spell_pri_chakra") { }

        class spell_pri_chakra_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_chakra_SpellScript);

            void HandleEffect(SpellEffIndex /*effIndex*/)
            {
                if(GetCaster()->HasAura(SPELL_PRIEST_CHAKRA))
                {
                    uint32 id = 0;
                    int32 bp = 0;
                    switch(GetSpell()->GetSpellInfo()->Id)
                    {
                    case SPELL_PRIEST_SMITE:
                    case SPELL_PRIEST_MIND_SPIKE:
                        id = SPELL_PRIEST_CHAKRA_CHASTISE;
                        break;
                    case SPELL_PRIEST_HEAL:
                    case SPELL_PRIEST_BINDING_HEAL:
                    case SPELL_PRIEST_FLASH_HEAL:
                    case SPELL_PRIEST_GREATER_HEAL:
                        id = SPELL_PRIEST_CHAKRA_SERENITY;
                        break;
                    case SPELL_PRIEST_PRAYER_OF_HEALING:
                    case SPELL_PRIEST_PRAYER_OF_MENDING:
                        id = SPELL_PRIEST_CHAKRA_SANCTUARY;
                        break;
                    default:
                        break;
                    }
                    if(!GetCaster()->HasAura(SPELL_PRIEST_REVELATIONS))
                    {
                        // If caster has not talent, ability holy word should not change
                        GetCaster()->CastCustomSpell(id, SPELLVALUE_BASE_POINT2, 88625, GetCaster(), true);
                    }
                    else
                        GetCaster()->CastSpell(GetCaster(), id, true);

                    GetCaster()->RemoveAura(SPELL_PRIEST_CHAKRA);
                }
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pri_chakra_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_ANY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pri_chakra_SpellScript();
        }
};

class spell_pri_chakra_serenity : public SpellScriptLoader
{
    public:
        spell_pri_chakra_serenity() : SpellScriptLoader("spell_pri_chakra_serenity") { }

        class spell_pri_chakra_serenity_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_chakra_serenity_SpellScript);

            void HandleEffectScriptEffect(SpellEffIndex /*effIndex*/)
            {
                if(Aura *pAura = GetHitUnit()->GetAura(SPELL_PRIEST_RENEW, GetCaster()->GetGUID()))
                {
                    pAura->RefreshDuration();
                }
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pri_chakra_serenity_SpellScript::HandleEffectScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pri_chakra_serenity_SpellScript();
        }
};

class spell_pri_echo_of_light : public SpellScriptLoader
{
    public:
        spell_pri_echo_of_light() : SpellScriptLoader("spell_pri_echo_of_light") { }

        class spell_pri_echo_of_light_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_echo_of_light_AuraScript);

            void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 bp = eventInfo.GetHealInfo()->GetHeal() / 6;
                
                if (AuraEffect const* aurEff = GetCaster()->GetAuraEffect(SPELL_PRIEST_ECHO_OF_LIGHT_MASTERY, EFFECT_0))
                    ApplyPct(bp, aurEff->GetAmount());

                GetCaster()->CastCustomSpell(eventInfo.GetProcTarget(), SPELL_PRIEST_ECHO_OF_LIGHT_HEAL, &bp, NULL, NULL, true);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_pri_echo_of_light_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pri_echo_of_light_AuraScript();
        }
};

class spell_pri_sin_and_punishment : public SpellScriptLoader
{
    public:
        spell_pri_sin_and_punishment() : SpellScriptLoader("spell_pri_sin_and_punishment") { }

        class spell_pri_sin_and_punishment_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pri_sin_and_punishment_AuraScript);

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return (eventInfo.GetDamageInfo()->GetSpellInfo()->Id == SPELL_PRIEST_MIND_FLAY);
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                if(Player *player = GetCaster()->ToPlayer())
                {
                    if(player->HasSpellCooldown(SPELL_PRIEST_SHADOWFIEND))
                    {
                        float cd = player->GetSpellCooldownDelay(SPELL_PRIEST_SHADOWFIEND);
                        if (cd <= 10)
                             cd = 0;
                         else
                             cd -= 10;
                        player->AddSpellCooldown(SPELL_PRIEST_SHADOWFIEND, 0, uint32(time(NULL) + cd));
                        WorldPacket data(SMSG_MODIFY_COOLDOWN, 4 + 8 + 4);
                        data << uint32(SPELL_PRIEST_SHADOWFIEND);
                        data << uint64(player->GetGUID());
                        data << int32(-10000);
                        player->GetSession()->SendPacket(&data);
                    }
                }
            }

            void Register() OVERRIDE
            {
                DoCheckProc += AuraCheckProcFn(spell_pri_sin_and_punishment_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pri_sin_and_punishment_AuraScript::HandleEffectProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pri_sin_and_punishment_AuraScript();
        }
};

class spell_pri_shadow_orb : public SpellScriptLoader
{
    public:
        spell_pri_shadow_orb() : SpellScriptLoader("spell_pri_shadow_orb") { }

        class spell_pri_shadow_orb_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pri_shadow_orb_SpellScript);

            void HandleEffect(SpellEffIndex /*effIndex*/)
            {
                if(AuraEffect *pAuraEff = GetCaster()->GetAuraEffect(SPELL_PRIEST_SHADOW_ORB_MASTERY, EFFECT_0))
                {
                    if(Aura *pAura = GetCaster()->GetAura(SPELL_PRIEST_SHADOW_ORB))
                    {
                        uint32 damage = GetEffectValue();
                        damage = GetCaster()->SpellDamageBonusDone(GetHitUnit(), GetSpellInfo(), uint32(damage), SPELL_DIRECT_DAMAGE);
                        damage = GetHitUnit()->SpellDamageBonusTaken(GetCaster(), GetSpellInfo(), uint32(damage), SPELL_DIRECT_DAMAGE);
                        uint32 stack = pAura->GetStackAmount() * 30;
                        uint32 orbDmg = AddPct(stack, pAuraEff->GetAmount());
                        damage = AddPct(damage, orbDmg);
                        SetHitDamage(damage);
                        GetCaster()->RemoveAura(SPELL_PRIEST_SHADOW_ORB);
                    }
                }
                if(GetHitUnit()->HasAura(SPELL_PRIEST_MIND_SPIKE_AURA) && GetSpellInfo()->Id == SPELL_PRIEST_MIND_BLAST)
                    GetHitUnit()->RemoveAura(SPELL_PRIEST_MIND_SPIKE_AURA);
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pri_shadow_orb_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_ANY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pri_shadow_orb_SpellScript();
        }
};



void AddSC_priest_spell_scripts()
{
    new spell_pri_body_and_soul();
    new spell_pri_dispel_magic();
    new spell_pri_divine_aegis();
    new spell_pri_glyph_of_prayer_of_healing();
    new spell_pri_improved_power_word_shield();
    new spell_pri_item_greater_heal_refund();
    new spell_pri_guardian_spirit();
    new spell_pri_leap_of_faith_effect_trigger();
    new spell_pri_lightwell_renew();
    new spell_pri_mana_burn();
    new spell_pri_mana_leech();
    new spell_pri_mind_sear();
    new spell_pri_pain_and_suffering_proc();
    new spell_pri_penance();
    new spell_pri_phantasm();
    new spell_pri_power_word_shield();
    new spell_pri_prayer_of_mending_heal();
    new spell_pri_renew();
    new spell_pri_shadow_word_death();
    new spell_pri_shadowform();
    new spell_pri_vampiric_embrace();
    new spell_pri_vampiric_embrace_target();
    new spell_pri_vampiric_touch();
    new spell_pri_evangelism();
    new spell_pri_archangel();
    new spell_pri_atonement();
    new spell_pri_atonement_heal();
    new spell_pri_chakra();
    new spell_pri_chakra_serenity();
    new spell_pri_echo_of_light();
    new spell_pri_sin_and_punishment();
    new spell_pri_shadow_orb();
}
