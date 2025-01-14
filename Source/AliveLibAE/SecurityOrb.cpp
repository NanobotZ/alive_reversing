#include "stdafx.h"
#include "SecurityOrb.hpp"
#include "Sound/Midi.hpp"
#include "stdlib.hpp"
#include "Gibs.hpp"
#include "ScreenShake.hpp"
#include "Events.hpp"
#include "Flash.hpp"
#include "ParticleBurst.hpp"
#include "Particle.hpp"
#include "Abe.hpp"
#include "PossessionFlicker.hpp"
#include "Game.hpp"
#include "Sfx.hpp"
#include "Explosion.hpp"
#include "ZapLine.hpp"
#include "Function.hpp"
#include "Sparks.hpp"

const TintEntry sSecurityOrbTints_55C1EC[18] = {
    {LevelIds_s8::eMines_1, 127u, 127u, 127u},
    {LevelIds_s8::eNecrum_2, 137u, 137u, 137u},
    {LevelIds_s8::eMudomoVault_3, 127u, 127u, 127u},
    {LevelIds_s8::eMudancheeVault_4, 127u, 127u, 127u},
    {LevelIds_s8::eFeeCoDepot_5, 127u, 127u, 127u},
    {LevelIds_s8::eBarracks_6, 127u, 127u, 127u},
    {LevelIds_s8::eMudancheeVault_Ender_7, 127u, 127u, 127u},
    {LevelIds_s8::eBonewerkz_8, 127u, 127u, 127u},
    {LevelIds_s8::eBrewery_9, 127u, 127u, 127u},
    {LevelIds_s8::eBrewery_Ender_10, 127u, 127u, 127u},
    {LevelIds_s8::eMudomoVault_3, 127u, 127u, 127u}, // TODO: eMudomoVault_3 exists twice. eMudomoVault_Ender_11 should probably be here? OG bug?
    {LevelIds_s8::eFeeCoDepot_Ender_12, 127u, 127u, 127u},
    {LevelIds_s8::eBarracks_Ender_13, 127u, 127u, 127u},
    {LevelIds_s8::eBonewerkz_Ender_14, 127u, 127u, 127u},
    {LevelIds_s8::eNone, 127u, 127u, 127u}};


SecurityOrb* SecurityOrb::ctor_466350(Path_SecurityOrb* pTlv, s32 tlvInfo)
{
    ctor_408240(0);
    SetVTable(this, 0x545F3C);

    SetType(AETypes::eSecurityOrb_83);

    field_6_flags.Set(BaseGameObject::eCanExplode_Bit7);

    const AnimRecord& rec = AnimRec(AnimId::Security_Orb);
    u8** ppRes = Add_Resource_4DC130(ResourceManager::Resource_Animation, rec.mResourceId);
    Animation_Init_424E10(rec.mFrameTableOffset, rec.mMaxW, rec.mMaxH, ppRes, 1, 1);

    SetTint_425600(sSecurityOrbTints_55C1EC, gMap_5C3030.field_0_current_level);

    field_B8_xpos = FP_FromInteger(pTlv->field_8_top_left.field_0_x);
    field_BC_ypos = FP_FromInteger(pTlv->field_8_top_left.field_2_y);

    field_118_tlvInfo = tlvInfo;

    if (pTlv->field_10_scale == Scale_short::eHalf_1)
    {
        field_CC_sprite_scale = FP_FromDouble(0.5);
        field_D6_scale = 0;
        field_20_animation.field_C_render_layer = Layer::eLayer_8;
    }
    else
    {
        field_CC_sprite_scale = FP_FromInteger(1);
        field_D6_scale = 1;
        field_20_animation.field_C_render_layer = Layer::eLayer_27;
    }

    field_DC_bApplyShadows |= 2u;
    field_11C_state = 0;
    field_124_sound_channels_mask = 0;

    return this;
}

SecurityOrb* SecurityOrb::vdtor_4664B0(s32 flags)
{
    dtor_4664E0();
    if (flags & 1)
    {
        ae_delete_free_495540(this);
    }
    return this;
}

void SecurityOrb::dtor_4664E0()
{
    SetVTable(this, 0x545F3C);

    if (field_124_sound_channels_mask)
    {
        SND_Stop_Channels_Mask_4CA810(field_124_sound_channels_mask);
    }

    if (field_10C_health > FP_FromInteger(0))
    {
        Path::TLV_Reset_4DB8E0(field_118_tlvInfo, -1, 0, 0);
    }
    else
    {
        Path::TLV_Reset_4DB8E0(field_118_tlvInfo, -1, 0, 1);
    }

    dtor_4080B0();
}

void SecurityOrb::vScreenChanged_466D20()
{
    field_6_flags.Set(BaseGameObject::eDead_Bit3);
}

s16 SecurityOrb::vTakeDamage_466BB0(BaseGameObject* pFrom)
{
    if (field_6_flags.Get(BaseGameObject::eDead_Bit3))
    {
        return 0;
    }

    field_6_flags.Set(BaseGameObject::eDead_Bit3);
    field_10C_health = FP_FromInteger(0);

    if (pFrom->Type() == AETypes::eMineCar_89 || pFrom->Type() == AETypes::eAbilityRing_104 || pFrom->Type() == AETypes::eShrykull_121 || pFrom->Type() == AETypes::eGrenade_65)
    {
        auto pExplosionMem = ae_new<Explosion>();
        if (pExplosionMem)
        {
            pExplosionMem->ctor_4A1200(
                field_B8_xpos,
                field_BC_ypos - (field_CC_sprite_scale * FP_FromInteger(5)),
                field_CC_sprite_scale,
                0);
        }

        auto pGibsMem = ae_new<Gibs>();
        if (pGibsMem)
        {
            pGibsMem->ctor_40FB40(
                GibType::Metal_5,
                field_B8_xpos,
                field_BC_ypos,
                FP_FromInteger(0),
                FP_FromInteger(0),
                field_CC_sprite_scale,
                0);
        }
    }

    return 1;
}

void SecurityOrb::vUpdate_4665A0()
{
    if (Event_Get_422C00(kEventDeathReset))
    {
        field_6_flags.Set(BaseGameObject::eDead_Bit3);
    }

    // TODO: untangle
    if (field_11C_state)
    {
        const s32 stateM1 = field_11C_state - 1;
        if (stateM1)
        {
            if (stateM1 == 1)
            {
                if (static_cast<s32>(sGnFrame_5C1B84) == field_120_timer - 5 || static_cast<s32>(sGnFrame_5C1B84) == field_120_timer - 1)
                {
                    auto pFlash1 = ae_new<Flash>();
                    if (pFlash1)
                    {
                        pFlash1->ctor_428570(Layer::eLayer_Above_FG1_39, 255, 0, 0, 1, TPageAbr::eBlend_3, 1);
                    }
                }
                if (static_cast<s32>(sGnFrame_5C1B84) == field_120_timer - 4)
                {
                    auto pFlash2 = ae_new<Flash>();
                    if (pFlash2)
                    {
                        pFlash2->ctor_428570(Layer::eLayer_Above_FG1_39, 255, 0, 0, 1, TPageAbr::eBlend_1, 1);
                    }
                }

                const s32 timerFrame = field_120_timer - sGnFrame_5C1B84;
                if (timerFrame == 4)
                {
                    SFX_Play_46FA90(SoundEffect::Zap1_49, 0, field_CC_sprite_scale);
                }
                else if (timerFrame == 1)
                {
                    SFX_Play_46FA90(SoundEffect::Zap2_50, 0, field_CC_sprite_scale);
                }

                if (static_cast<s32>(sGnFrame_5C1B84) > field_120_timer)
                {
                    field_11C_state = 0;
                }
            }
        }
        else if (static_cast<s32>(sGnFrame_5C1B84) > field_120_timer)
        {
            PSX_RECT bRect = {};
            sActiveHero_5C1B68->vGetBoundingRect_424FD0(&bRect, 1);

            const FP xpos = FP_FromInteger((bRect.x + bRect.w) / 2);
            const FP ypos = FP_FromInteger((bRect.y + bRect.h) / 2);

            auto pZapLine = ae_new<ZapLine>();
            if (pZapLine)
            {
                pZapLine->ctor_4CC690(
                    field_B8_xpos,
                    field_BC_ypos - (FP_FromInteger(8) * field_CC_sprite_scale),
                    xpos,
                    ypos,
                    8,
                    ZapLineType::eThick_0,
                    Layer::eLayer_ZapLinesMuds_28);
            }

            auto pFlicker = ae_new<PossessionFlicker>();
            if (pFlicker)
            {
                pFlicker->ctor_4319E0(sActiveHero_5C1B68, 8, 255, 100, 100);
            }

            if (sActiveHero_5C1B68->field_10C_health > FP_FromInteger(0))
            {
                sActiveHero_5C1B68->VTakeDamage_408730(this);
            }

            field_120_timer = sGnFrame_5C1B84 + 8;
            field_11C_state = 2;

            auto pScreenShake = ae_new<ScreenShake>();
            if (pScreenShake)
            {
                pScreenShake->ctor_4ACF70(1, 0);
            }

            auto pSpark = ae_new<Sparks>();
            if (pSpark)
            {
                pSpark->ctor_416390(field_B8_xpos, field_BC_ypos - (FP_FromInteger(8) * field_CC_sprite_scale), field_CC_sprite_scale);

                pSpark->field_D2_g = 65;
                pSpark->field_D4_b = 65;
                pSpark->field_D0_r = 255;
            }

            auto pSpark2 = ae_new<Sparks>();
            if (pSpark2)
            {
                pSpark2->ctor_416390(field_B8_xpos, field_BC_ypos - (FP_FromInteger(8) * field_CC_sprite_scale), field_CC_sprite_scale);

                pSpark2->field_D2_g = 65;
                pSpark2->field_D4_b = 65;
                pSpark2->field_D0_r = 255;
            }

            for (s32 i = 0; i < 9; i++)
            {
                auto pSpark3 = ae_new<Sparks>();
                if (pSpark3)
                {
                    pSpark3->ctor_416390(xpos, ypos, field_CC_sprite_scale);
                    pSpark3->field_D2_g = 65;
                    pSpark3->field_D4_b = 65;
                    pSpark3->field_D0_r = 255;
                }
            }
        }
    }
    else
    {
        if (field_20_animation.field_92_current_frame == 2 || field_20_animation.field_92_current_frame == 6 || field_20_animation.field_92_current_frame == 10)
        {
            if (field_124_sound_channels_mask)
            {
                SND_Stop_Channels_Mask_4CA810(field_124_sound_channels_mask);
            }

            if (field_CC_sprite_scale == FP_FromDouble(0.5))
            {
                field_124_sound_channels_mask = SFX_Play_46FBA0(SoundEffect::SecurityOrb_48, 35, 720, field_CC_sprite_scale);
            }
            else
            {
                field_124_sound_channels_mask = SFX_Play_46FBA0(SoundEffect::SecurityOrb_48, 55, 700, field_CC_sprite_scale);
            }
        }

        if (Event_Get_422C00(kEventAbeOhm))
        {
            if (!sActiveHero_5C1B68->field_168_ring_pulse_timer || !sActiveHero_5C1B68->field_16C_bHaveShrykull || sActiveHero_5C1B68->field_CC_sprite_scale != FP_FromInteger(1))
            {
                field_11C_state = 1;
                field_120_timer = sGnFrame_5C1B84 + 20;
            }
        }
    }
}
