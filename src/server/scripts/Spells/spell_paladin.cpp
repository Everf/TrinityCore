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
 * Scripts for spells with SPELLFAMILY_PALADIN and SPELLFAMILY_GENERIC spells used by paladin players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_pal_".
 */

#include "Player.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Group.h"

enum PaladinSpells
{
    SPELL_PALADIN_AVENGERS_SHIELD                = 31935,
    SPELL_PALADIN_AURA_MASTERY_IMMUNE            = 64364,
    SPELL_PALADIN_BEACON_OF_LIGHT_MARKER         = 53563,
    SPELL_PALADIN_BEACON_OF_LIGHT_HEAL           = 53652,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_DRUID   = 37878,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PALADIN = 37879,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PRIEST  = 37880,
    SPELL_PALADIN_BLESSING_OF_LOWER_CITY_SHAMAN  = 37881,
    SPELL_PALADIN_CONCENTRACTION_AURA            = 19746,
    SPELL_PALADIN_DIVINE_PURPOSE_PROC            = 90174,
    SPELL_PALADIN_DIVINE_SACRIFICE               = 64205,
    SPELL_PALADIN_DIVINE_STORM                   = 53385,
    SPELL_PALADIN_DIVINE_STORM_DUMMY             = 54171,
    SPELL_PALADIN_DIVINE_STORM_HEAL              = 54172,
    SPELL_PALADIN_EYE_FOR_AN_EYE_RANK_1          = 9799,
    SPELL_PALADIN_EYE_FOR_AN_EYE_DAMAGE          = 25997,
    SPELL_PALADIN_FORBEARANCE                    = 25771,
    SPELL_PALADIN_GLYPH_OF_SALVATION             = 63225,
    SPELL_PALADIN_HAND_OF_SACRIFICE              = 6940,
    SPELL_PALADIN_HOLY_LIGHT                     = 635,
    SPELL_PALADIN_HOLY_SHOCK_R1                  = 20473,
    SPELL_PALADIN_HOLY_SHOCK_R1_DAMAGE           = 25912,
    SPELL_PALADIN_HOLY_SHOCK_R1_HEALING          = 25914,
    SPELL_PALADIN_IMMUNE_SHIELD_MARKER           = 61988,
    SPELL_PALADIN_IMPROVED_CONCENTRACTION_AURA   = 63510,
    SPELL_PALADIN_IMPROVED_DEVOTION_AURA         = 63514,
    SPELL_PALADIN_ITEM_HEALING_TRANCE            = 37706,
    SPELL_PALADIN_RIGHTEOUS_DEFENSE_TAUNT        = 31790,
    SPELL_PALADIN_SANCTIFIED_RETRIBUTION_AURA    = 63531,
    SPELL_PALADIN_SANCTIFIED_RETRIBUTION_R1      = 31869,
    SPELL_PALADIN_SEAL_OF_RIGHTEOUSNESS          = 25742,
    SPELL_PALADIN_SWIFT_RETRIBUTION_R1           = 53379,
    SPELL_PALADIN_SPEED_OF_LIGHT                 = 85497,
    SPELL_PALADIN_SPEED_OF_LIGHT_RANK_1          = 85495,
    SPELL_PALADIN_JUDGEMENT_DAMAGE               = 54158,
    SPELL_PALADIN_ILLUMINATED_HEALING_MASTERY    = 76669,
    SPELL_PALADIN_ILLUMINATED_HEALING            = 86273,
    SPELL_PALADIN_GUARDIAN_ANCIENT_KINGS         = 86150,    
    SPELL_PALADIN_RETRI_GUARDIAN                 = 86698,
    SPELL_PALADIN_HOLY_GUARDIAN                  = 86669,
    SPELL_PALADIN_PROT_GUARDIAN                  = 86659,
    SPELL_PALADIN_INQUISITION                    = 84963,
    SPELL_PALADIN_TOWER_OF_RADIANCE_RANK_1       = 84800,
    SPELL_PALADIN_TOWER_OF_RADIANCE_TRIGGERED    = 88852,
    SPELL_PALADIN_HOLY_RADIANCE                  = 82327,
    SPELL_PALADIN_ETERNAL_GLORY_RANK_1           = 87163,
    SPELL_PALADIN_GUARDED_BY_THE_LIGHT_RANK_1    = 85639,
    SPELL_PALADIN_GUARDED_BY_THE_LIGHT_RANK_2    = 85646,
    SPELL_PALADIN_GUARDED_BY_THE_LIGHT_TRIGGERED = 88063,
    SPELL_PALADIN_ARDENT_DEFENDER_HEAL           = 66235,
    SPELL_PALADIN_CONSECRATION_SUMMON            = 82366,
    SPELL_PALADIN_CONSECRATION_DAMAGE            = 81297,
    SPELL_PALADIN_HAND_OF_LIGHT_MASTERY          = 76672,
    SPELL_PALADIN_HAND_OF_LIGHT_DAMAGE           = 96172,
    SPELL_PALADIN_SANCTIFIED_WRATH_RANK_1        = 53375,
    SPELL_PALADIN_SANCTIFIED_WRATH_TRIGGERED     = 57318,
    SPELL_PALADIN_COMMUNION                      = 31876,
    SPELL_PALADIN_PURSUIT_OF_JUSTICE_RANK_1      = 26022,
    SPELL_PALADIN_PURSUIT_OF_JUSTICE_TRIGGERED   = 89024,
    SPELL_PALADIN_SELFLESS_HEALER_RANK_1         = 85803,
    SPELL_PALADIN_SELFLESS_HEALER_TRIGGERED      = 90811,
    SPELL_PALADIN_LAST_WORD_RANK_1               = 20235,
    SPELL_PALADIN_LONG_HARM_OF_THE_LAW_RANK_1    = 87168,
    SPELL_PALADIN_LONG_HARM_OF_THE_LAW_RANK_2    = 87172,
    SPELL_PALADIN_LONG_HARM_OF_THE_LAW_TRIGGERED = 87173,
};

enum MiscSpells
{
    SPELL_GENERIC_ARENA_DAMPENING                = 74410,
    SPELL_GENERIC_BATTLEGROUND_DAMPENING         = 74411,
    SPELL_GEN_REPLENISHMENT                      = 57669
};

enum PaladinSpellIcons
{
    PALADIN_ICON_ID_RETRIBUTION_AURA             = 555
};


// 31850 - Ardent Defender
class spell_pal_ardent_defender : public SpellScriptLoader
{
    public:
        spell_pal_ardent_defender() : SpellScriptLoader("spell_pal_ardent_defender") { }

        class spell_pal_ardent_defender_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_ardent_defender_AuraScript);

            uint32 absorbPct, healPct;

            bool Load() OVERRIDE
            {
                healPct = GetSpellInfo()->Effects[EFFECT_1].CalcValue();
                absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue();
                return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
            }

            void CalculateAmount(AuraEffect const* aurEff, int32 & amount, bool & canBeRecalculated)
            {
                // Set absorbtion amount to unlimited
                amount = -1;
            }

            void Absorb(AuraEffect* aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                Unit* victim = GetTarget();
                int32 remainingHealth = victim->GetHealth() - dmgInfo.GetDamage();
                // If damage kills us
                if (remainingHealth <= 0)
                {
                    // Cast healing spell, completely avoid damage
                    absorbAmount = dmgInfo.GetDamage();

                    int32 healAmount = int32(victim->CountPctFromMaxHealth(healPct));
                    victim->CastCustomSpell(victim, SPELL_PALADIN_ARDENT_DEFENDER_HEAL, &healAmount, NULL, NULL, true, NULL, aurEff);
                }

                uint32 damageToReduce = dmgInfo.GetDamage();
                absorbAmount = CalculatePct(damageToReduce, absorbPct);
            }

            void Register() OVERRIDE
            {
                 DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_ardent_defender_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                 OnEffectAbsorb += AuraEffectAbsorbFn(spell_pal_ardent_defender_AuraScript::Absorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_ardent_defender_AuraScript();
        }
};

// 31821 - Aura Mastery
class spell_pal_aura_mastery : public SpellScriptLoader
{
    public:
        spell_pal_aura_mastery() : SpellScriptLoader("spell_pal_aura_mastery") { }

        class spell_pal_aura_mastery_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_aura_mastery_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_AURA_MASTERY_IMMUNE))
                    return false;
                return true;
            }

            void HandleEffectApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->CastSpell(GetTarget(), SPELL_PALADIN_AURA_MASTERY_IMMUNE, true);
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->RemoveOwnedAura(SPELL_PALADIN_AURA_MASTERY_IMMUNE, GetCasterGUID());
            }

            void Register() OVERRIDE
            {
                AfterEffectApply += AuraEffectApplyFn(spell_pal_aura_mastery_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_pal_aura_mastery_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_aura_mastery_AuraScript();
        }
};

// 64364 - Aura Mastery Immune
class spell_pal_aura_mastery_immune : public SpellScriptLoader
{
    public:
        spell_pal_aura_mastery_immune() : SpellScriptLoader("spell_pal_aura_mastery_immune") { }

        class spell_pal_aura_mastery_immune_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_aura_mastery_immune_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_CONCENTRACTION_AURA))
                    return false;
                return true;
            }

            bool CheckAreaTarget(Unit* target)
            {
                return target->HasAura(SPELL_PALADIN_CONCENTRACTION_AURA, GetCasterGUID());
            }

            void Register() OVERRIDE
            {
                DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_pal_aura_mastery_immune_AuraScript::CheckAreaTarget);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_aura_mastery_immune_AuraScript();
        }
};

// 53651 - Beacon of Light
class spell_pal_beacon_of_light : public SpellScriptLoader
{
    public:
        spell_pal_beacon_of_light() : SpellScriptLoader("spell_pal_beacon_of_light") { }

        class spell_pal_beacon_of_light_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_beacon_of_light_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_BEACON_OF_LIGHT_HEAL))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (eventInfo.GetActionTarget()->GetAura(SPELL_PALADIN_BEACON_OF_LIGHT_MARKER, GetCasterGUID()))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 heal = eventInfo.GetHealInfo()->GetHeal();

                if(eventInfo.GetDamageInfo()->GetSpellInfo()->Id == SPELL_PALADIN_HOLY_RADIANCE)
                    return;

                if (eventInfo.GetDamageInfo()->GetSpellInfo()->Id != SPELL_PALADIN_HOLY_LIGHT)
                    heal = int32(CalculatePct(heal, aurEff->GetAmount()));

                Unit::AuraList const& auras = GetCaster()->GetSingleCastAuras();
                for (Unit::AuraList::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
                {
                    if ((*itr)->GetId() == SPELL_PALADIN_BEACON_OF_LIGHT_MARKER)
                    {
                        std::list<AuraApplication*> applications;
                        (*itr)->GetApplicationList(applications);
                        if (applications.empty())
                            return;

                        GetCaster()->CastCustomSpell(SPELL_PALADIN_BEACON_OF_LIGHT_HEAL, SPELLVALUE_BASE_POINT0, heal, applications.front()->GetTarget(), true, NULL, aurEff);
                        return;
                    }
                }
            }

            void Register() OVERRIDE
            {
                DoCheckProc += AuraCheckProcFn(spell_pal_beacon_of_light_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pal_beacon_of_light_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_beacon_of_light_AuraScript();
        }
};

// 37877 - Blessing of Faith
class spell_pal_blessing_of_faith : public SpellScriptLoader
{
    public:
        spell_pal_blessing_of_faith() : SpellScriptLoader("spell_pal_blessing_of_faith") { }

        class spell_pal_blessing_of_faith_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_blessing_of_faith_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_BLESSING_OF_LOWER_CITY_DRUID) || !sSpellMgr->GetSpellInfo(SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PALADIN) || !sSpellMgr->GetSpellInfo(SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PRIEST) || !sSpellMgr->GetSpellInfo(SPELL_PALADIN_BLESSING_OF_LOWER_CITY_SHAMAN))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* unitTarget = GetHitUnit())
                {
                    uint32 spell_id = 0;
                    switch (unitTarget->getClass())
                    {
                        case CLASS_DRUID:
                            spell_id = SPELL_PALADIN_BLESSING_OF_LOWER_CITY_DRUID;
                            break;
                        case CLASS_PALADIN:
                            spell_id = SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PALADIN;
                            break;
                        case CLASS_PRIEST:
                            spell_id = SPELL_PALADIN_BLESSING_OF_LOWER_CITY_PRIEST;
                            break;
                        case CLASS_SHAMAN:
                            spell_id = SPELL_PALADIN_BLESSING_OF_LOWER_CITY_SHAMAN;
                            break;
                        default:
                            return; // ignore for non-healing classes
                    }
                    Unit* caster = GetCaster();
                    caster->CastSpell(caster, spell_id, true);
                }
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_blessing_of_faith_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_blessing_of_faith_SpellScript();
        }
};

// 64205 - Divine Sacrifice
class spell_pal_divine_sacrifice : public SpellScriptLoader
{
    public:
        spell_pal_divine_sacrifice() : SpellScriptLoader("spell_pal_divine_sacrifice") { }

        class spell_pal_divine_sacrifice_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_divine_sacrifice_AuraScript);

            uint32 groupSize, minHpPct;
            int32 remainingAmount;

            bool Load() OVERRIDE
            {

                if (Unit* caster = GetCaster())
                {
                    if (caster->GetTypeId() == TYPEID_PLAYER)
                    {
                        if (caster->ToPlayer()->GetGroup())
                            groupSize = caster->ToPlayer()->GetGroup()->GetMembersCount();
                        else
                            groupSize = 1;
                    }
                    else
                        return false;

                    remainingAmount = (caster->CountPctFromMaxHealth(GetSpellInfo()->Effects[EFFECT_2].CalcValue(caster)) * groupSize);
                    minHpPct = GetSpellInfo()->Effects[EFFECT_1].CalcValue(caster);
                    return true;
                }
                return false;
            }

            void Split(AuraEffect* /*aurEff*/, DamageInfo & /*dmgInfo*/, uint32 & splitAmount)
            {
                remainingAmount -= splitAmount;
                // break when absorbed everything it could, or if the casters hp drops below 20%
                if (Unit* caster = GetCaster())
                    if (remainingAmount <= 0 || (caster->GetHealthPct() < minHpPct))
                        caster->RemoveAura(SPELL_PALADIN_DIVINE_SACRIFICE);
            }

            void Register() OVERRIDE
            {
                OnEffectSplit += AuraEffectSplitFn(spell_pal_divine_sacrifice_AuraScript::Split, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_divine_sacrifice_AuraScript();
        }
};

// 53385 - Divine Storm
class spell_pal_divine_storm : public SpellScriptLoader
{
    public:
        spell_pal_divine_storm() : SpellScriptLoader("spell_pal_divine_storm") { }

        class spell_pal_divine_storm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_divine_storm_SpellScript);

            uint32 healPct;

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_DIVINE_STORM_DUMMY))
                    return false;
                return true;
            }

            bool Load() OVERRIDE
            {
                healPct = GetSpellInfo()->Effects[EFFECT_1].CalcValue(GetCaster());
                return true;
            }
            
            void CountTargets(std::list<WorldObject*>& targetList)
            {
                _targetCount = targetList.size();
            }

            void TriggerHeal()
            {
                Unit *caster = GetCaster();
                caster->CastCustomSpell(SPELL_PALADIN_DIVINE_STORM_DUMMY, SPELLVALUE_BASE_POINT0, (GetHitDamage() * healPct) / 100, caster, true);
            }

            void Check()
            {
                if(_targetCount < 4)
                    PreventHitEffect(EFFECT_0);
            }

            void Register() OVERRIDE
            {
                BeforeHit += SpellHitFn(spell_pal_divine_storm_SpellScript::Check);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_divine_storm_SpellScript::CountTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);          
                AfterHit += SpellHitFn(spell_pal_divine_storm_SpellScript::TriggerHeal);
            }
        private:
            uint32 _targetCount;
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_divine_storm_SpellScript();
        }
};

// 54171 - Divine Storm (Dummy)
class spell_pal_divine_storm_dummy : public SpellScriptLoader
{
    public:
        spell_pal_divine_storm_dummy() : SpellScriptLoader("spell_pal_divine_storm_dummy") { }

        class spell_pal_divine_storm_dummy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_divine_storm_dummy_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_DIVINE_STORM_HEAL))
                    return false;
                return true;
            }

            void CountTargets(std::list<WorldObject*>& targetList)
            {
                _targetCount = targetList.size();
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (!_targetCount || ! GetHitUnit())
                    return;

                int32 heal = GetEffectValue() / _targetCount;
                GetCaster()->CastCustomSpell(GetHitUnit(), SPELL_PALADIN_DIVINE_STORM_HEAL, &heal, NULL, NULL, true);
            }
        private:
            uint32 _targetCount;

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_divine_storm_dummy_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_pal_divine_storm_dummy_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_divine_storm_dummy_SpellScript();
        }
};

// 33695 - Exorcism and Holy Wrath Damage
class spell_pal_exorcism_and_holy_wrath_damage : public SpellScriptLoader
{
    public:
        spell_pal_exorcism_and_holy_wrath_damage() : SpellScriptLoader("spell_pal_exorcism_and_holy_wrath_damage") { }

        class spell_pal_exorcism_and_holy_wrath_damage_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_exorcism_and_holy_wrath_damage_AuraScript);

            void HandleEffectCalcSpellMod(AuraEffect const* aurEff, SpellModifier*& spellMod)
            {
                if (!spellMod)
                {
                    spellMod = new SpellModifier(aurEff->GetBase());
                    spellMod->op = SPELLMOD_DAMAGE;
                    spellMod->type = SPELLMOD_FLAT;
                    spellMod->spellId = GetId();
                    spellMod->mask[1] = 0x200002;
                }

                spellMod->value = aurEff->GetAmount();
            }

            void Register() OVERRIDE
            {
                DoEffectCalcSpellMod += AuraEffectCalcSpellModFn(spell_pal_exorcism_and_holy_wrath_damage_AuraScript::HandleEffectCalcSpellMod, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_exorcism_and_holy_wrath_damage_AuraScript();
        }
};

// -75806 - Grand Crusader
class spell_pal_grand_crusader : public SpellScriptLoader
{
    public:
        spell_pal_grand_crusader() : SpellScriptLoader("spell_pal_grand_crusader") { }

        class spell_pal_grand_crusader_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_grand_crusader_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_AVENGERS_SHIELD))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                return GetTarget()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                GetTarget()->ToPlayer()->RemoveSpellCooldown(SPELL_PALADIN_AVENGERS_SHIELD, true);
            }

            void Register() OVERRIDE
            {
                DoCheckProc += AuraCheckProcFn(spell_pal_grand_crusader_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pal_grand_crusader_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_grand_crusader_AuraScript();
        }
};

// -9799 - Eye for an Eye
class spell_pal_eye_for_an_eye : public SpellScriptLoader
{
    public:
        spell_pal_eye_for_an_eye() : SpellScriptLoader("spell_pal_eye_for_an_eye") { }

        class spell_pal_eye_for_an_eye_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_eye_for_an_eye_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_EYE_FOR_AN_EYE_DAMAGE))
                    return false;
                return true;
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 damage = eventInfo.GetDamageInfo()->GetDamage();
                damage = ApplyPct(damage, aurEff->GetAmount());
                GetTarget()->CastCustomSpell(SPELL_PALADIN_EYE_FOR_AN_EYE_DAMAGE, SPELLVALUE_BASE_POINT0, damage, eventInfo.GetProcTarget(), true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_eye_for_an_eye_AuraScript::HandleEffectProc, EFFECT_0, m_scriptSpellId == SPELL_PALADIN_EYE_FOR_AN_EYE_RANK_1 ? SPELL_AURA_DUMMY : SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_eye_for_an_eye_AuraScript();
        }
};

// 6940 - Hand of Sacrifice
class spell_pal_hand_of_sacrifice : public SpellScriptLoader
{
    public:
        spell_pal_hand_of_sacrifice() : SpellScriptLoader("spell_pal_hand_of_sacrifice") { }

        class spell_pal_hand_of_sacrifice_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_hand_of_sacrifice_AuraScript);

            int32 remainingAmount;

            bool Load() OVERRIDE
            {
                if (Unit* caster = GetCaster())
                {
                    remainingAmount = caster->GetMaxHealth();
                    return true;
                }
                return false;
            }

            void Split(AuraEffect* /*aurEff*/, DamageInfo & /*dmgInfo*/, uint32 & splitAmount)
            {
                remainingAmount -= splitAmount;

                if (remainingAmount <= 0)
                {
                    GetTarget()->RemoveAura(SPELL_PALADIN_HAND_OF_SACRIFICE);
                }
            }

            void Register() OVERRIDE
            {
                OnEffectSplit += AuraEffectSplitFn(spell_pal_hand_of_sacrifice_AuraScript::Split, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_hand_of_sacrifice_AuraScript();
        }
};

// 20473 - Holy Shock
class spell_pal_holy_shock : public SpellScriptLoader
{
    public:
        spell_pal_holy_shock() : SpellScriptLoader("spell_pal_holy_shock") { }

        class spell_pal_holy_shock_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_holy_shock_SpellScript);

            bool Validate(SpellInfo const* spellInfo) OVERRIDE
            {
                SpellInfo const* firstRankSpellInfo = sSpellMgr->GetSpellInfo(SPELL_PALADIN_HOLY_SHOCK_R1);
                if (!firstRankSpellInfo)
                    return false;

                // can't use other spell than holy shock due to spell_ranks dependency
                if (!spellInfo->IsRankOf(firstRankSpellInfo))
                    return false;

                uint8 rank = spellInfo->GetRank();
                if (!sSpellMgr->GetSpellWithRank(SPELL_PALADIN_HOLY_SHOCK_R1_DAMAGE, rank, true) || !sSpellMgr->GetSpellWithRank(SPELL_PALADIN_HOLY_SHOCK_R1_HEALING, rank, true))
                    return false;

                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* unitTarget = GetHitUnit())
                {
                    uint8 rank = GetSpellInfo()->GetRank();
                    if (caster->IsFriendlyTo(unitTarget))
                        caster->CastSpell(unitTarget, sSpellMgr->GetSpellWithRank(SPELL_PALADIN_HOLY_SHOCK_R1_HEALING, rank), true);
                    else
                        caster->CastSpell(unitTarget, sSpellMgr->GetSpellWithRank(SPELL_PALADIN_HOLY_SHOCK_R1_DAMAGE, rank), true);
                }
            }

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetExplTargetUnit())
                {
                    if (!caster->IsFriendlyTo(target))
                    {
                        if (!caster->IsValidAttackTarget(target))
                            return SPELL_FAILED_BAD_TARGETS;

                        if (!caster->isInFront(target))
                            return SPELL_FAILED_UNIT_NOT_INFRONT;
                    }
                }
                else
                    return SPELL_FAILED_BAD_TARGETS;
                return SPELL_CAST_OK;
            }

            void Register() OVERRIDE
            {
                OnCheckCast += SpellCheckCastFn(spell_pal_holy_shock_SpellScript::CheckCast);
                OnEffectHitTarget += SpellEffectFn(spell_pal_holy_shock_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_holy_shock_SpellScript();
        }
};

// 63510 - Improved Concentraction Aura (Area Aura)
// 63514 - Improved Devotion Aura (Area Aura)
// 63531 - Sanctified Retribution (Area Aura)
class spell_pal_improved_aura_effect : public SpellScriptLoader
{
    public:
        spell_pal_improved_aura_effect(char const* name) : SpellScriptLoader(name) { }

        class spell_pal_improved_aura_effect_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_improved_aura_effect_AuraScript);

            bool CheckAreaTarget(Unit* target)
            {
                Unit::AuraApplicationMap& appliedAuras = target->GetAppliedAuras();
                for (Unit::AuraApplicationMap::iterator itr = appliedAuras.begin(); itr != appliedAuras.end(); ++itr)
                {
                    Aura const* aura = itr->second->GetBase();
                    if (aura->GetSpellInfo()->GetSpellSpecific() == SPELL_SPECIFIC_AURA && aura->GetCasterGUID() == GetCasterGUID())
                    {
                        // Not allow for Retribution Aura (prevent stacking) - Retribution Aura Overflow and Retribution Aura has same spell effects
                        if (GetSpellInfo()->Id == SPELL_PALADIN_SANCTIFIED_RETRIBUTION_AURA && aura->GetSpellInfo()->SpellIconID == PALADIN_ICON_ID_RETRIBUTION_AURA)
                            return false;
                        return true;
                    }
                }

                return false;
            }

            void Register() OVERRIDE
            {
                DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_pal_improved_aura_effect_AuraScript::CheckAreaTarget);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_improved_aura_effect_AuraScript();
        }
};

// 37705 - Healing Discount
class spell_pal_item_healing_discount : public SpellScriptLoader
{
    public:
        spell_pal_item_healing_discount() : SpellScriptLoader("spell_pal_item_healing_discount") { }

        class spell_pal_item_healing_discount_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_item_healing_discount_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_ITEM_HEALING_TRANCE))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_PALADIN_ITEM_HEALING_TRANCE, true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_item_healing_discount_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_item_healing_discount_AuraScript();
        }
};

// 633 - Lay on Hands
class spell_pal_lay_on_hands : public SpellScriptLoader
{
    public:
        spell_pal_lay_on_hands() : SpellScriptLoader("spell_pal_lay_on_hands") { }

        class spell_pal_lay_on_hands_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_lay_on_hands_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_FORBEARANCE) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PALADIN_IMMUNE_SHIELD_MARKER))
                    return false;
                return true;
            }

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetExplTargetUnit())
                    if (caster == target)
                        if (target->HasAura(SPELL_PALADIN_FORBEARANCE) ||
                            target->HasAura(SPELL_PALADIN_IMMUNE_SHIELD_MARKER))
                        {
                            return SPELL_FAILED_TARGET_AURASTATE;
                        }

                return SPELL_CAST_OK;
            }

            void HandleScript()
            {
                Unit* caster = GetCaster();
                if (caster == GetHitUnit())
                {
                    caster->CastSpell(caster, SPELL_PALADIN_FORBEARANCE, true);
                    caster->CastSpell(caster, SPELL_PALADIN_IMMUNE_SHIELD_MARKER, true);
                }
            }

            void Register() OVERRIDE
            {
                OnCheckCast += SpellCheckCastFn(spell_pal_lay_on_hands_SpellScript::CheckCast);
                AfterHit += SpellHitFn(spell_pal_lay_on_hands_SpellScript::HandleScript);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_lay_on_hands_SpellScript();
        }
};

// 31789 - Righteous Defense
class spell_pal_righteous_defense : public SpellScriptLoader
{
    public:
        spell_pal_righteous_defense() : SpellScriptLoader("spell_pal_righteous_defense") { }

        class spell_pal_righteous_defense_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_righteous_defense_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_RIGHTEOUS_DEFENSE_TAUNT))
                    return false;
                return true;
            }

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                if (caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_DONT_REPORT;

                if (Unit* target = GetExplTargetUnit())
                {
                    if (!target->IsFriendlyTo(caster) || target->getAttackers().empty())
                        return SPELL_FAILED_BAD_TARGETS;
                }
                else
                    return SPELL_FAILED_BAD_TARGETS;

                return SPELL_CAST_OK;
            }

            void HandleTriggerSpellLaunch(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
            }

            void HandleTriggerSpellHit(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Unit* target = GetHitUnit())
                    GetCaster()->CastSpell(target, SPELL_PALADIN_RIGHTEOUS_DEFENSE_TAUNT, true);
            }

            void Register() OVERRIDE
            {
                OnCheckCast += SpellCheckCastFn(spell_pal_righteous_defense_SpellScript::CheckCast);
                //! WORKAROUND
                //! target select will be executed in hitphase of effect 0
                //! so we must handle trigger spell also in hit phase (default execution in launch phase)
                //! see issue #3718
                OnEffectLaunchTarget += SpellEffectFn(spell_pal_righteous_defense_SpellScript::HandleTriggerSpellLaunch, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
                OnEffectHitTarget += SpellEffectFn(spell_pal_righteous_defense_SpellScript::HandleTriggerSpellHit, EFFECT_1, SPELL_EFFECT_TRIGGER_SPELL);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_righteous_defense_SpellScript();
        }
};

// 85285 - Sacred Shield
/*class spell_pal_sacred_shield : public SpellScriptLoader
{
    public:
        spell_pal_sacred_shield() : SpellScriptLoader("spell_pal_sacred_shield") { }

        class spell_pal_sacred_shield_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_sacred_shield_SpellScript);

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                if (caster->GetTypeId() != TYPEID_PLAYER)
                    return SPELL_FAILED_DONT_REPORT;

                if (!caster->HealthBelowPct(30))
                    return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

                return SPELL_CAST_OK;
            }

            void Register() OVERRIDE
            {
                OnCheckCast += SpellCheckCastFn(spell_pal_sacred_shield_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_sacred_shield_SpellScript();
        }
};*/

// 85256 - Templar's Verdict
/// Updated 4.3.4
class spell_pal_templar_s_verdict : public SpellScriptLoader
{
    public:
        spell_pal_templar_s_verdict() : SpellScriptLoader("spell_pal_templar_s_verdict") { }

        class spell_pal_templar_s_verdict_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_templar_s_verdict_SpellScript);

            bool Validate (SpellInfo const* /*spellEntry*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_DIVINE_PURPOSE_PROC))
                    return false;

                return true;
            }

            bool Load() OVERRIDE
            {
                if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
                    return false;

                if (GetCaster()->ToPlayer()->getClass() != CLASS_PALADIN)
                    return false;

                return true;
            }

            void ChangeDamage(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                int32 damage = GetHitDamage();

                if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_PROC))
                    damage *= 7.5;  // 7.5*30% = 225%
                else
                {
                    switch (caster->GetPower(POWER_HOLY_POWER))
                    {
                        case 0: // 1 Holy Power
                            damage = damage;
                            break;
                        case 1: // 2 Holy Power
                            damage *= 3;    // 3*30 = 90%
                            break;
                        case 2: // 3 Holy Power
                            damage *= 7.5;  // 7.5*30% = 225%
                            break;
                    }
                }

                SetHitDamage(damage);
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_templar_s_verdict_SpellScript::ChangeDamage, EFFECT_0, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_templar_s_verdict_SpellScript();
        }
};

// 20154, 21084 - Seal of Righteousness - melee proc dummy (addition ${$MWS*(0.022*$AP+0.044*$SPH)} damage)
class spell_pal_seal_of_righteousness : public SpellScriptLoader
{
    public:
        spell_pal_seal_of_righteousness() : SpellScriptLoader("spell_pal_seal_of_righteousness") { }

        class spell_pal_seal_of_righteousness_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_seal_of_righteousness_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_SEAL_OF_RIGHTEOUSNESS))
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

                float ap = GetTarget()->GetTotalAttackPowerValue(BASE_ATTACK);
                int32 holy = GetTarget()->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_HOLY);
                holy += eventInfo.GetProcTarget()->SpellBaseDamageBonusTaken(SPELL_SCHOOL_MASK_HOLY);
                int32 bp = int32((ap * 0.022f + 0.044f * holy) * GetTarget()->GetAttackTime(BASE_ATTACK) / 1000);
                GetTarget()->CastCustomSpell(SPELL_PALADIN_SEAL_OF_RIGHTEOUSNESS, SPELLVALUE_BASE_POINT0, bp, eventInfo.GetProcTarget(), true, NULL, aurEff);
            }

            void Register() OVERRIDE
            {
                DoCheckProc += AuraCheckProcFn(spell_pal_seal_of_righteousness_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pal_seal_of_righteousness_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_seal_of_righteousness_AuraScript();
        }
};

// -85495 - Speed of light
class spell_pal_speed_of_light : public SpellScriptLoader
{
    public:
        spell_pal_speed_of_light() : SpellScriptLoader("spell_pal_speed_of_light") { }

        class spell_pal_speed_of_light_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_speed_of_light_SpellScript);

            void HandleEffect(SpellEffIndex /*effIndex*/)
            {
                if(AuraEffect *pAura = GetCaster()->GetAuraEffectOfRankedSpell(SPELL_PALADIN_SPEED_OF_LIGHT_RANK_1, EFFECT_1))
                {
                    int32 bp = pAura->GetAmount();
                    GetCaster()->CastCustomSpell(GetCaster(), SPELL_PALADIN_SPEED_OF_LIGHT, &bp, NULL, NULL, true);
                }
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_speed_of_light_SpellScript::HandleEffect, EFFECT_1, SPELL_EFFECT_ANY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_speed_of_light_SpellScript();
        }
};

// 20271 - Judgement
/// Updated 4.3.4
class spell_pal_judgement : public SpellScriptLoader
{
    public:
        spell_pal_judgement() : SpellScriptLoader("spell_pal_judgement") { }

        class spell_pal_judgement_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_judgement_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_JUDGEMENT_DAMAGE))
                    return false;
                return true;
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                uint32 spellId = SPELL_PALADIN_JUDGEMENT_DAMAGE;

                // some seals have SPELL_AURA_DUMMY in EFFECT_2
                Unit::AuraEffectList const& auras = GetCaster()->GetAuraEffectsByType(SPELL_AURA_DUMMY);
                for (Unit::AuraEffectList::const_iterator i = auras.begin(); i != auras.end(); ++i)
                {
                    if ((*i)->GetSpellInfo()->GetSpellSpecific() == SPELL_SPECIFIC_SEAL && (*i)->GetEffIndex() == EFFECT_2)
                        if (sSpellMgr->GetSpellInfo((*i)->GetAmount()))
                        {
                            spellId = (*i)->GetAmount();
                            break;
                        }
                }

                GetCaster()->CastSpell(GetHitUnit(), spellId, true);

                if(GetCaster()->HasAura(SPELL_PALADIN_COMMUNION))
                    GetCaster()->CastSpell(GetCaster(), SPELL_GEN_REPLENISHMENT, true);

                if(GetCaster()->HasAura(SPELL_PALADIN_LONG_HARM_OF_THE_LAW_RANK_2) || (roll_chance_i(50) && GetCaster()->HasAura(SPELL_PALADIN_LONG_HARM_OF_THE_LAW_RANK_1)))
                    if(GetCaster()->GetDistance(GetHitUnit()) > 15)
                        GetCaster()->CastSpell(GetCaster(), SPELL_PALADIN_LONG_HARM_OF_THE_LAW_TRIGGERED, true);
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_judgement_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_judgement_SpellScript();
        }
};

// 84963 - Inquisiton
/// Updated 4.3.4
class spell_pal_inquisiton : public SpellScriptLoader
{
    public:
        spell_pal_inquisiton() : SpellScriptLoader("spell_pal_inquisiton") { }

        class spell_pal_inquisiton_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_inquisiton_SpellScript);

            int32 holyPower;

            bool Load()
            {
                if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
                    return false;

                if (GetCaster()->ToPlayer()->getClass() != CLASS_PALADIN)
                    return false;

                return true;
            }

            void GetHP(SpellEffIndex /*effIndex*/)
            {
                holyPower = GetCaster()->GetPower(POWER_HOLY_POWER);
            }

            void UpdateDuration()
            {
                if (Aura* aura = GetCaster()->GetAura(SPELL_PALADIN_INQUISITION))
                {
                    int32 duration = aura->GetMaxDuration();
                    aura->SetDuration(duration*(holyPower+1));
                    GetCaster()->SetPower(POWER_HOLY_POWER, 0);
                }
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_inquisiton_SpellScript::GetHP, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
                AfterHit += SpellHitFn(spell_pal_inquisiton_SpellScript::UpdateDuration);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_pal_inquisiton_SpellScript();
        }
};

// -86150 - Guardian of Ancient Kings
// Fix: Summon guardian, need to implement other spells yet like Ancient Power and Ancient Fury
class spell_pal_guardian_ancient_kings : public SpellScriptLoader
{
public:
    spell_pal_guardian_ancient_kings() : SpellScriptLoader("spell_pal_guardian_ancient_kings") { }

    class spell_pal_guardian_ancient_kings_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_pal_guardian_ancient_kings_SpellScript)

        bool Load() OVERRIDE
        {
            if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
                return false;
            return true;
        }

        bool Validate (SpellInfo const* /*spellEntry*/) OVERRIDE
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_GUARDIAN_ANCIENT_KINGS))
                return false;

            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (caster->ToPlayer()->HasSpell(20473)) // Holy Shock
                {
                    caster->CastSpell(caster, SPELL_PALADIN_HOLY_GUARDIAN, false);
                    return;
                }
                if (caster->ToPlayer()->HasSpell(85256)) // Templar's Verdict
                {
                    caster->CastSpell(caster, SPELL_PALADIN_RETRI_GUARDIAN, false);
                    return;
                }
                if (caster->ToPlayer()->HasSpell(31935)) // Avenger's shield
                {
                    caster->CastSpell(caster, SPELL_PALADIN_PROT_GUARDIAN, false);
                    return;
                }
            }
        }

        void Register() OVERRIDE
        {
            OnEffectLaunch += SpellEffectFn(spell_pal_guardian_ancient_kings_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const OVERRIDE
    {
        return new spell_pal_guardian_ancient_kings_SpellScript();
    }
};

// 76669 - Illuminated healing
class spell_pal_illuminated_healing : public SpellScriptLoader
{
    public:
        spell_pal_illuminated_healing() : SpellScriptLoader("spell_pal_illuminated_healing") { }

        class spell_pal_illuminated_healing_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_illuminated_healing_AuraScript);

            void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 bp = eventInfo.GetHealInfo()->GetHeal();
                
                if (AuraEffect const* aurEff = GetCaster()->GetAuraEffect(SPELL_PALADIN_ILLUMINATED_HEALING_MASTERY, EFFECT_0))
                    ApplyPct(bp, aurEff->GetAmount());

                GetCaster()->CastCustomSpell(eventInfo.GetProcTarget(), SPELL_PALADIN_ILLUMINATED_HEALING, &bp, NULL, NULL, true);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_illuminated_healing_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_illuminated_healing_AuraScript();
        }
};

// 
class spell_pal_tower_of_radiance : public SpellScriptLoader
{
    public:
        spell_pal_tower_of_radiance() : SpellScriptLoader("spell_pal_tower_of_radiance") { }

        class spell_pal_tower_of_radiance_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_tower_of_radiance_AuraScript);

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                //return (eventInfo.GetActionTarget()->HasAura(SPELL_PALADIN_BEACON_OF_LIGHT_MARKER,eventInfo.GetProcTarget());
                return true;
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                GetCaster()->CastSpell(GetCaster(), 46916, true);
                GetCaster()->CastSpell(GetCaster(), SPELL_PALADIN_TOWER_OF_RADIANCE_TRIGGERED, true);
                /*if(AuraEffect *pAuraEff = GetCaster()->GetAuraEffectOfRankedSpell(SPELL_PALADIN_TOWER_OF_RADIANCE_RANK_1, EFFECT_0))
                {
                    if(roll_chance_i(pAuraEff->GetAmount()))
                        GetCaster()->CastSpell(GetCaster(), SPELL_PALADIN_TOWER_OF_RADIANCE_TRIGGERED, true);
                }*/
            }

            void Register() OVERRIDE
            {
                DoCheckProc += AuraCheckProcFn(spell_pal_tower_of_radiance_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_pal_tower_of_radiance_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_tower_of_radiance_AuraScript();
        }
};

// 85222 - Light of Dawn
class spell_pal_light_of_dawn : public SpellScriptLoader
{
    public:
        spell_pal_light_of_dawn() : SpellScriptLoader("spell_pal_light_of_dawn") { }

        class spell_pal_light_of_dawn_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_light_of_dawn_SpellScript);

            void HandleBeforeCast()
            {
                if (Unit* caster = GetCaster())
                    holyPower = caster->GetPower(POWER_HOLY_POWER);
            }

            void ChangeHeal(SpellEffIndex effIndex)
            {
                Unit* caster = GetCaster();
                int32 heal = GetHitHeal();

                heal *= holyPower + 1;

                // Why self healing is doubled?
                if (GetCaster() == GetHitUnit())
                    heal /= 2;

                SetHitHeal(heal);
            }

            void HandleAfterCast()
            {
                if(GetCaster() != GetHitUnit())
                    GetCaster()->SetPower(POWER_HOLY_POWER, 0);
            }

            void Register() OVERRIDE
            {            
                BeforeCast += SpellCastFn(spell_pal_light_of_dawn_SpellScript::HandleBeforeCast);
                OnEffectHitTarget += SpellEffectFn(spell_pal_light_of_dawn_SpellScript::ChangeHeal, EFFECT_0, SPELL_EFFECT_HEAL);
                AfterCast += SpellCastFn(spell_pal_light_of_dawn_SpellScript::HandleAfterCast);

            }
        private:
            uint32 holyPower;
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_light_of_dawn_SpellScript();
        }
};

// 85673 - Word of glory
class spell_pal_word_of_glory : public SpellScriptLoader
{
    public:
        spell_pal_word_of_glory() : SpellScriptLoader("spell_pal_word_of_glory") { }

        class spell_pal_word_of_glory_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_word_of_glory_SpellScript);

            void HandleBeforeCast()
            {
                holyPower = GetCaster()->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_PROC) ? 3 : GetCaster()->GetPower(POWER_HOLY_POWER); 
            }

            void HandleAfterCast()
            {
                if(GetCaster()->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_PROC))
                    return;

                // Eternal Glory
                if (Unit* caster = GetCaster())
                    if (AuraEffect const* pAurEff = caster->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_PALADIN, 2944, 0))
                        if (roll_chance_i(pAurEff->GetAmount()))
                            caster->CastCustomSpell(caster, 88676, &holyPower, NULL, NULL, true);
	        }

            void ChangeHeal(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                int32 heal = GetHitHeal();
                uint32 ap = caster->GetTotalAttackPowerValue(BASE_ATTACK) * 0.198;
                uint32 sp = 0.209*(caster->SpellBaseHealingBonusDone(SPELL_SCHOOL_MASK_HOLY));
                heal = ((GetHitHeal()+sp / 2) + ap) * (holyPower);
                GetCaster()->SetPower(POWER_HOLY_POWER, 0);

                if(GetHitUnit() == GetCaster())
                {
                    if(AuraEffect *pAura = caster->GetAuraEffect(SPELL_PALADIN_GUARDED_BY_THE_LIGHT_RANK_1, EFFECT_0))
                        AddPct(heal, pAura->GetAmount());
                }
                else if (AuraEffect *pAura = caster->GetAuraEffectOfRankedSpell(SPELL_PALADIN_SELFLESS_HEALER_RANK_1, EFFECT_0))
                {
                    AddPct(heal, pAura->GetAmount());
                    int32 bp = pAura->GetBase()->GetEffect(EFFECT_1)->GetAmount() * holyPower;
                    GetCaster()->CastCustomSpell(GetCaster(), SPELL_PALADIN_SELFLESS_HEALER_TRIGGERED, &bp, NULL, NULL, true);
                }
                
                // Increase 60% crit chance against <35%hpPct targets
                /*if (AuraEffect *pAura = caster->GetAuraEffectOfRankedSpell(SPELL_PALADIN_LAST_WORD_RANK_1, EFFECT_0))
                {
                    int32 bp = pAura->GetAmount();
                    caster->ToPlayer()->ApplySpellMod(GetSpellInfo()->Id, SPELLMOD_CRITICAL_CHANCE, bp);
                }*/

                if (AuraEffect *pAura = caster->GetAuraEffect(SPELL_PALADIN_GUARDED_BY_THE_LIGHT_RANK_2, EFFECT_0))
                {
                    int32 overHeal = 0;
                    uint32 healthBeforeHeal = uint32(heal) + GetHitUnit()->GetHealth();
                    if(healthBeforeHeal > GetHitUnit()->GetMaxHealth())
                    {
                        overHeal = healthBeforeHeal - GetHitUnit()->GetMaxHealth();
                        GetCaster()->CastCustomSpell(GetHitUnit(), SPELL_PALADIN_GUARDED_BY_THE_LIGHT_TRIGGERED, &overHeal, NULL, NULL, true);
                    }
                }

                SetHitHeal(heal);
            }

            void HandlePeriodic()
            {
                // Glyph of Long Word
                if (!GetCaster()->HasAura(93466))
                    PreventHitAura();
            }

            void Register() OVERRIDE
            {
                BeforeCast += SpellCastFn(spell_pal_word_of_glory_SpellScript::HandleBeforeCast);
                OnEffectHitTarget += SpellEffectFn(spell_pal_word_of_glory_SpellScript::ChangeHeal, EFFECT_0, SPELL_EFFECT_HEAL);
                AfterHit += SpellHitFn(spell_pal_word_of_glory_SpellScript::HandlePeriodic);
                AfterCast += SpellCastFn(spell_pal_word_of_glory_SpellScript::HandleAfterCast);
            }
        private:
            int32 holyPower;
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_word_of_glory_SpellScript();
        }
};

class spell_pal_consecration : public SpellScriptLoader
{
public:
    spell_pal_consecration() : SpellScriptLoader("spell_pal_consecration") { }

    class spell_pal_consecration_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_pal_consecration_AuraScript)
        
        float x, y, z;

        bool Load() OVERRIDE
        {
           if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
               return false;

            return true;
        }

        void HandlePeriodicDummy(AuraEffect const* /*aurEff*/)
        {
            uint64 consecrationNpcGUID = GetCaster()->m_SummonSlot[1];

            if (!consecrationNpcGUID)
               return;

            Unit* consecrationNpc = ObjectAccessor::GetCreature(*GetCaster(),consecrationNpcGUID);

            if (!consecrationNpc)
                return;

            consecrationNpc->GetPosition(x, y, z);
            consecrationNpc->SetInCombatState(true);
            consecrationNpc->CastSpell(consecrationNpc, SPELL_PALADIN_CONSECRATION_DAMAGE, true, NULL, NULL, GetCaster()->GetGUID());  
        }

        void Register() OVERRIDE
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_pal_consecration_AuraScript::HandlePeriodicDummy, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_pal_consecration_AuraScript();
    }
};

// 31878 - Judgement of the wise
// 89901 - Judgement of the Bold
class spell_pal_judgements_of_the_wise_and_bold : public SpellScriptLoader
{
    public:
        spell_pal_judgements_of_the_wise_and_bold() : SpellScriptLoader("spell_pal_judgements_of_the_wise_and_bold") { }

        class spell_pal_judgements_of_the_wise_and_bold_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_judgements_of_the_wise_and_bold_AuraScript);

            void CalculateMana(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
            {
                if (Unit* caster = GetCaster())
                {
                    canBeRecalculated = true;
                    int32 basemana = caster->ToPlayer()->GetCreateMana();
                    if(GetSpellInfo()->Id == 31930)
                        amount = ApplyPct(basemana, 3);
                    else if (GetSpellInfo()->Id == 89906)
                        amount = ApplyPct(basemana, 2.5);
                }
            }

            void Register() OVERRIDE
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_pal_judgements_of_the_wise_and_bold_AuraScript::CalculateMana, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_judgements_of_the_wise_and_bold_AuraScript();
        }
};

// 53600 - Shield of righteous
class spell_pal_shield_of_righteous : public SpellScriptLoader
{
    public:
        spell_pal_shield_of_righteous() : SpellScriptLoader("spell_pal_shield_of_righteous") { }

        class spell_pal_shield_of_righteous_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_shield_of_righteous_SpellScript);

            bool Validate (SpellInfo const* /*spellEntry*/)
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PALADIN_DIVINE_PURPOSE_PROC))
                    return false;

                return true;
            }

            bool Load() OVERRIDE
            {
                if (GetCaster()->GetTypeId() != TYPEID_PLAYER)
                    return false;

                if (GetCaster()->ToPlayer()->getClass() != CLASS_PALADIN)
                    return false;

                return true;
            }

            void ChangeDamage(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                int32 damage = GetHitDamage();

                if (caster->HasAura(SPELL_PALADIN_DIVINE_PURPOSE_PROC))
                    damage *= 6;
                else
                {
                    switch (caster->GetPower(POWER_HOLY_POWER))
                    {
                        case 0: // 1 Holy Power
                            damage = damage;
                            break;
                        case 1: // 2 Holy Power
                            damage *= 3;
                            break;
                        case 2: // 3 Holy Power
                            damage *= 6;
                            break;
                    }
                }

                SetHitDamage(damage);
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_shield_of_righteous_SpellScript::ChangeDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_shield_of_righteous_SpellScript();
        }
};

// 76672 - Hand of Light
class spell_pal_hand_of_light : public SpellScriptLoader
{
    public:
        spell_pal_hand_of_light() : SpellScriptLoader("spell_pal_hand_of_light") { }

        class spell_pal_hand_of_light_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pal_hand_of_light_AuraScript);

            void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 bp = eventInfo.GetDamageInfo()->GetDamage();
                
                if (AuraEffect const* aurEff = GetCaster()->GetAuraEffect(SPELL_PALADIN_HAND_OF_LIGHT_MASTERY, EFFECT_0))
                    ApplyPct(bp, aurEff->GetAmount());

                GetCaster()->CastCustomSpell(eventInfo.GetDamageInfo()->GetVictim(), SPELL_PALADIN_HAND_OF_LIGHT_DAMAGE, &bp, NULL, NULL, true);
            }

            void Register() OVERRIDE
            {
                OnEffectProc += AuraEffectProcFn(spell_pal_hand_of_light_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const OVERRIDE
        {
            return new spell_pal_hand_of_light_AuraScript();
        }
};

// -53375 - Sanctified Wrath
class spell_pal_sanctified_wrath : public SpellScriptLoader
{
    public:
        spell_pal_sanctified_wrath() : SpellScriptLoader("spell_pal_sanctified_wrath") { }

        class spell_pal_sanctified_wrath_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_sanctified_wrath_SpellScript);

            void HandleEffect(SpellEffIndex /*effIndex*/)
            {
                if(AuraEffect *pAura = GetCaster()->GetAuraEffectOfRankedSpell(SPELL_PALADIN_SANCTIFIED_WRATH_RANK_1, EFFECT_0))
                {
                    GetCaster()->CastSpell(GetCaster(), SPELL_PALADIN_SANCTIFIED_WRATH_TRIGGERED, true);
                    GetCaster()->ToPlayer()->AddSpellCooldown(SPELL_PALADIN_SANCTIFIED_WRATH_TRIGGERED, 0, uint32(time(NULL) + (pAura->GetAmount()*0.001)));
                }
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_sanctified_wrath_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_ANY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_sanctified_wrath_SpellScript();
        }
};

// 2812 - Holy Wrath
class spell_pal_holy_wrath : public SpellScriptLoader
{
    public:
        spell_pal_holy_wrath() : SpellScriptLoader("spell_pal_holy_wrath") { }

        class spell_pal_holy_wrath_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_pal_holy_wrath_SpellScript);

            void HandleEffect(SpellEffIndex /*effIndex*/)
            {
                if((GetHitUnit()->GetCreatureTypeMask() &CREATURE_TYPEMASK_DEMON_OR_UNDEAD) == 0)
                    PreventHitAura();
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_pal_holy_wrath_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_pal_holy_wrath_SpellScript();
        }
};

void AddSC_paladin_spell_scripts()
{
    new spell_pal_ardent_defender();
    new spell_pal_aura_mastery();
    new spell_pal_aura_mastery_immune();
    new spell_pal_beacon_of_light();
    new spell_pal_blessing_of_faith();
    new spell_pal_divine_sacrifice();
    new spell_pal_divine_storm();
    new spell_pal_divine_storm_dummy();
    new spell_pal_exorcism_and_holy_wrath_damage();
    new spell_pal_eye_for_an_eye();
    new spell_pal_grand_crusader();
    new spell_pal_hand_of_sacrifice();
    new spell_pal_holy_shock();
    new spell_pal_improved_aura_effect("spell_pal_improved_concentraction_aura_effect");
    new spell_pal_improved_aura_effect("spell_pal_improved_devotion_aura_effect");
    new spell_pal_improved_aura_effect("spell_pal_sanctified_retribution_effect");
    new spell_pal_item_healing_discount();
    new spell_pal_lay_on_hands();
    new spell_pal_righteous_defense();
    //new spell_pal_sacred_shield();
    new spell_pal_templar_s_verdict();
    new spell_pal_seal_of_righteousness();
    new spell_pal_speed_of_light();
    new spell_pal_judgement();
    new spell_pal_inquisiton();
    new spell_pal_guardian_ancient_kings();
    new spell_pal_illuminated_healing();
    new spell_pal_tower_of_radiance();
    new spell_pal_light_of_dawn();
    new spell_pal_word_of_glory();
    new spell_pal_consecration();
    new spell_pal_judgements_of_the_wise_and_bold();
    new spell_pal_shield_of_righteous();
    new spell_pal_hand_of_light();
    new spell_pal_sanctified_wrath();
    new spell_pal_holy_wrath();
}
