#include "stdafx.h"
#include "Meat.hpp"
#include "Function.hpp"
#include "ResourceManager.hpp"
#include "ThrowableArray.hpp"
#include "Game.hpp"
#include "stdlib.hpp"
#include "Shadow.hpp"
#include "PlatformBase.hpp"
#include "Sfx.hpp"
#include "ObjectIds.hpp"
#include "Events.hpp"
#include "Abe.hpp"
#include "Particle.hpp"
#include "Grid.hpp"
#include "ChaosMod.hpp"

Meat* Meat::ctor_4694A0(FP xpos, FP ypos, s16 count)
{
    ctor_408240(0);
    SetVTable(this, 0x546040);

    field_11A_bDead = 0;
    SetType(AETypes::eMeat_84);

    if (!ResourceManager::GetLoadedResource_49C2A0(ResourceManager::Resource_Animation, AEResourceID::kMeatResID, 0, 0))
    {
        LoadRockTypes_49AB30(field_C2_lvl_number, field_C0_path_number);
    }

    const AnimRecord& rec = AnimRec(AnimId::Meat);
    u8** ppRes = Add_Resource_4DC130(ResourceManager::Resource_Animation, rec.mResourceId);
    Animation_Init_424E10(rec.mFrameTableOffset, rec.mMaxW, rec.mMaxH, ppRes, 1, 1);

    field_20_animation.field_4_flags.Clear(AnimFlags::eBit15_bSemiTrans);

    field_B8_xpos = xpos;
    field_BC_ypos = ypos;

    field_120_xpos = xpos;
    field_124_ypos = ypos;

    field_C4_velx = FP_FromInteger(0);
    field_C8_vely = FP_FromInteger(0);
    field_128_timer = 0;
    field_6_flags.Clear(BaseGameObject::eInteractive_Bit8);

    field_20_animation.field_4_flags.Clear(AnimFlags::eBit3_Render);

    field_12C_deadtimer = sGnFrame_5C1B84 + 600;
    field_130_pLine = nullptr;
    field_118_count = count;
    field_11C_state = MeatStates::eCreated_0;

    field_E0_pShadow = ae_new<Shadow>();
    if (field_E0_pShadow)
    {
        field_E0_pShadow->ctor_4AC990();
    }
    return this;
}

BaseGameObject* Meat::VDestructor(s32 flags)
{
    return vdtor_4696C0(flags);
}

void Meat::VUpdate()
{
    vUpdate_469BA0();
}

void Meat::VScreenChanged()
{
    vScreenChanged_46A130();
}

void Meat::VOnTrapDoorOpen()
{
    vOnTrapDoorOpen_46A2E0();
}

void Meat::VThrow_49E460(FP velX, FP velY)
{
    vThrow_469790(velX, velY);
}

Bool32 Meat::VCanThrow_49E350()
{
    return vCanThrow_469680();
}

Bool32 Meat::VIsFalling_49E330()
{
    return vIsFalling_469660();
}

void Meat::VTimeToExplodeRandom_411490()
{
    // TODO
}

s16 Meat::VGetCount_448080()
{
    return vGetCount_46A350();
}

Bool32 Meat::VCanEatMe_4696A0()
{
    return vCanEatMe_4696A0();
}

void Meat::vScreenChanged_46A130()
{
    if (gMap_5C3030.field_2_current_path != gMap_5C3030.field_C_path || gMap_5C3030.field_0_current_level != gMap_5C3030.field_A_level)
    {
        field_6_flags.Set(BaseGameObject::eDead_Bit3);
    }
}

void Meat::AddToPlatform_46A170()
{
    // TODO: OG bug - why doesn't meat check for trap doors ??
    BaseAddToPlatform([](AETypes type)
                      { return type == AETypes::eLiftPoint_78; });
}

void Meat::vOnTrapDoorOpen_46A2E0()
{
    auto pPlatform = static_cast<PlatformBase*>(sObjectIds_5C1B70.Find_449CF0(field_110_id));
    if (pPlatform)
    {
        pPlatform->VRemove(this);
        field_110_id = -1;
        if (field_11C_state == MeatStates::eBecomeAPickUp_3 || field_11C_state == MeatStates::eWaitForPickUp_4)
        {
            field_11C_state = MeatStates::eIdle_1;
        }
    }
}

Bool32 Meat::vIsFalling_469660()
{
    return field_11C_state == MeatStates::eFall_5;
}

Bool32 Meat::vCanThrow_469680()
{
    return field_11C_state == MeatStates::eBeingThrown_2;
}

void Meat::dtor_4696F0()
{
    SetVTable(this, 0x546040);
    if (!field_11A_bDead)
    {
        if (gpThrowableArray_5D1E2C)
        {
            gpThrowableArray_5D1E2C->Remove_49AA00(field_118_count >= 1 ? field_118_count : 1);
        }
    }
    dtor_4080B0();
}

Meat* Meat::vdtor_4696C0(s32 flags)
{
    dtor_4696F0();
    if (flags & 1)
    {
        ae_delete_free_495540(this);
    }
    return this;
}

void Meat::vThrow_469790(FP velX, FP velY)
{
    field_20_animation.field_4_flags.Set(AnimFlags::eBit3_Render);

    field_C4_velx = velX;
    field_C8_vely = velY;

    if (field_118_count == 0)
    {
        field_11C_state = MeatStates::eBeingThrown_2;
    }
    else
    {
        field_11C_state = MeatStates::eIdle_1;
    }
}

s16 Meat::vGetCount_46A350()
{
    if (field_11C_state == MeatStates::eWaitForPickUp_4 && field_118_count == 0)
    {
        return 1;
    }

    return field_118_count;
}

void Meat::InTheAir_4697E0()
{
    field_120_xpos = field_B8_xpos;
    field_124_ypos = field_BC_ypos;

    if (field_C8_vely < FP_FromInteger(18))
    {
        field_C8_vely += FP_FromInteger(1);
    }

    field_B8_xpos += field_C4_velx;
    field_BC_ypos += field_C8_vely;

    FP hitX = {};
    FP hitY = {};
    if (sCollisions_DArray_5C1128->Raycast_417A60(field_120_xpos, field_124_ypos, field_B8_xpos, field_BC_ypos, &field_130_pLine, &hitX, &hitY, field_D6_scale == 0 ? 0xF0 : 0xF) == 1)
    {
        switch (field_130_pLine->field_8_type)
        {
            case eLineTypes::eFloor_0:
            case eLineTypes::eBackgroundFloor_4:
            case eLineTypes::eUnknown_32:
            case eLineTypes::eUnknown_36:
                if (field_C8_vely > FP_FromInteger(0))
                {
                    field_B8_xpos = FP_FromInteger(SnapToXGrid_449930(field_CC_sprite_scale, FP_GetExponent(hitX)));
                    field_BC_ypos = hitY;

                    if (chaosMod.getActiveEffect() == ChaosEffect::BouncyThrowables)
                    {
                        field_C8_vely = -field_C8_vely;
                        chaosMod.markEffectAsUsed();
                    }
                    else
                    {
                        field_11C_state = MeatStates::eBecomeAPickUp_3;
                        field_C8_vely = FP_FromInteger(0);
                        field_C4_velx = FP_FromInteger(0);
                    }

                    SFX_Play_46FBA0(SoundEffect::MeatBounce_36, 0, -650);
                    Event_Broadcast_422BC0(kEventNoise, this);
                    Event_Broadcast_422BC0(kEventSuspiciousNoise, this);
                    AddToPlatform_46A170();
                }
                break;

            case eLineTypes::eWallLeft_1:
            case eLineTypes::eBackgroundWallLeft_5:
                if (field_C4_velx < FP_FromInteger(0))
                {
                    field_B8_xpos = hitX;
                    field_BC_ypos = hitY;

                    if (chaosMod.getActiveEffect() == ChaosEffect::BouncyThrowables)
                    {
                        field_C4_velx = -field_C4_velx;
                        chaosMod.markEffectAsUsed();
                    }
                    else
                    {
                        field_C4_velx = (-field_C4_velx / FP_FromInteger(4));
                    }

                    SFX_Play_46FBA0(SoundEffect::MeatBounce_36, 0, -650);
                    Event_Broadcast_422BC0(kEventNoise, this);
                    Event_Broadcast_422BC0(kEventSuspiciousNoise, this);
                    if (field_C8_vely < FP_FromInteger(0))
                    {
                        field_C8_vely = FP_FromInteger(0);
                    }
                }
                field_130_pLine = nullptr;
                break;

            case eLineTypes::eWallRight_2:
            case eLineTypes::eBackgroundWallRight_6:
                if (field_C4_velx > FP_FromInteger(0))
                {
                    field_B8_xpos = hitX;
                    field_BC_ypos = hitY;

                    if (chaosMod.getActiveEffect() == ChaosEffect::BouncyThrowables)
                    {
                        field_C4_velx = -field_C4_velx;
                        chaosMod.markEffectAsUsed();
                    }
                    else
                    {
                        field_C4_velx = (-field_C4_velx / FP_FromInteger(4));
                    }

                    SFX_Play_46FBA0(SoundEffect::MeatBounce_36, 0, -650);
                    Event_Broadcast_422BC0(kEventNoise, this);
                    Event_Broadcast_422BC0(kEventSuspiciousNoise, this);
                    if (field_C8_vely < FP_FromInteger(0))
                    {
                        field_C8_vely = FP_FromInteger(0);
                    }
                }
                field_130_pLine = nullptr;
                break;

            case eLineTypes::eCeiling_3:
            case eLineTypes::eBackgroundCeiling_7:
                if (field_C8_vely < FP_FromInteger(0))
                {
                    field_B8_xpos = hitX;
                    field_BC_ypos = hitY + FP_FromInteger(1);
                    if (chaosMod.getActiveEffect() == ChaosEffect::BouncyThrowables)
                    {
                        field_C8_vely = -field_C8_vely;
                        chaosMod.markEffectAsUsed();
                    }
                    else
                    {
                        field_C8_vely = FP_FromInteger(0);
                    }
                    SFX_Play_46FBA0(SoundEffect::MeatBounce_36, 0, -650);
                    Event_Broadcast_422BC0(kEventNoise, this);
                    Event_Broadcast_422BC0(kEventSuspiciousNoise, this);
                }
                break;
        }
    }
}

s16 Meat::OnCollision_469FF0(BaseGameObject* pHit)
{
    // TODO: Check if pHit type is correct for all throwables

    if (!pHit->field_6_flags.Get(BaseGameObject::eCanExplode_Bit7))
    {
        return 1;
    }

    if (pHit->Type() == AETypes::eMine_88 || pHit->Type() == AETypes::eUXB_143 || pHit->Type() == AETypes::eTimedMine_or_MovingBomb_10)
    {
        return 1;
    }

    PSX_RECT bRect = {};
    static_cast<BaseAliveGameObject*>(pHit)->vGetBoundingRect_424FD0(&bRect, 1);

    if (field_120_xpos < FP_FromInteger(bRect.x) || field_120_xpos > FP_FromInteger(bRect.w))
    {
        field_B8_xpos -= field_C4_velx;
        if (chaosMod.getActiveEffect() == ChaosEffect::BouncyThrowables)
        {
            field_C4_velx = -field_C4_velx;
            chaosMod.markEffectAsUsed();
        }
        else
        {
            field_C4_velx = (-field_C4_velx / FP_FromInteger(2));
        }
    }
    else
    {
        field_BC_ypos -= field_C8_vely;
        if (chaosMod.getActiveEffect() == ChaosEffect::BouncyThrowables)
        {
            field_C8_vely = -field_C8_vely;
            chaosMod.markEffectAsUsed();
        }
        else
        {
            field_C8_vely = (-field_C8_vely / FP_FromInteger(2));
        }
    }

    static_cast<BaseAliveGameObject*>(pHit)->VOnThrowableHit(this);

    SFX_Play_46FBA0(SoundEffect::MeatBounce_36, 0, -650);

    return 0;
}

void Meat::vUpdate_469BA0()
{
    auto v2 = sObjectIds_5C1B70.Find_449CF0(field_110_id);
    if (sNum_CamSwappers_5C1B66 == 0)
    {
        if (Event_Get_422C00(kEventDeathReset))
        {
            field_6_flags.Set(BaseGameObject::eDead_Bit3);
        }

        switch (field_11C_state)
        {
            case MeatStates::eIdle_1:
                InTheAir_4697E0();
                break;

            case MeatStates::eBeingThrown_2:
            {
                InTheAir_4697E0();
                PSX_RECT bRect = {};
                vGetBoundingRect_424FD0(&bRect, 1);
                const PSX_Point xy = {bRect.x, static_cast<s16>(bRect.y + 5)};
                const PSX_Point wh = {bRect.w, static_cast<s16>(bRect.h + 5)};
                vOnCollisionWith_424EE0(
                    xy,
                    wh,
                    gBaseGameObject_list_BB47C4,
                    1,
                    (TCollisionCallBack) &Meat::OnCollision_469FF0);

                // TODO: OG bug - why only checking for out of the bottom of the map?? Nades check for death object - probably should check both
                if (field_BC_ypos > FP_FromInteger(gMap_5C3030.field_D4_ptr->field_6_bBottom))
                {
                    field_6_flags.Set(BaseGameObject::eDead_Bit3);
                }
            }
            break;

            case MeatStates::eBecomeAPickUp_3:
                if (FP_Abs(field_C4_velx) < FP_FromInteger(1))
                {
                    field_20_animation.field_4_flags.Clear(AnimFlags::eBit8_Loop);
                }

                if (FP_Abs(field_C4_velx) >= FP_FromDouble(0.5))
                {
                    if (field_C4_velx <= FP_FromInteger(0))
                    {
                        field_C4_velx += FP_FromDouble(0.01);
                    }
                    else
                    {
                        field_C4_velx -= FP_FromDouble(0.01);
                    }

                    field_130_pLine = field_130_pLine->MoveOnLine_418260(&field_B8_xpos, &field_BC_ypos, field_C4_velx);
                    if (!field_130_pLine)
                    {
                        field_20_animation.field_4_flags.Set(AnimFlags::eBit8_Loop);
                        field_11C_state = MeatStates::eBeingThrown_2;
                    }
                }
                else
                {
                    field_C4_velx = FP_FromInteger(0);

                    field_E4_collection_rect.x = field_B8_xpos - (ScaleToGridSize_4498B0(field_CC_sprite_scale) / FP_FromInteger(2));
                    field_E4_collection_rect.y = field_BC_ypos - ScaleToGridSize_4498B0(field_CC_sprite_scale);
                    field_E4_collection_rect.w = (ScaleToGridSize_4498B0(field_CC_sprite_scale) / FP_FromInteger(2)) + field_B8_xpos;
                    field_E4_collection_rect.h = field_BC_ypos;

                    field_6_flags.Set(BaseGameObject::eInteractive_Bit8);
                    field_11C_state = MeatStates::eWaitForPickUp_4;
                }
                break;

            case MeatStates::eWaitForPickUp_4:
                if (gMap_5C3030.Is_Point_In_Current_Camera_4810D0(field_C2_lvl_number, field_C0_path_number, field_B8_xpos, field_BC_ypos, 0))
                {
                    field_12C_deadtimer = sGnFrame_5C1B84 + 600;
                }

                if (static_cast<s32>(sGnFrame_5C1B84) > field_128_timer && !v2)
                {
                    // That strange "shimmer" the meat gives off
                    New_TintShiny_Particle_426C30(
                        (field_CC_sprite_scale * FP_FromInteger(1)) + field_B8_xpos,
                        field_BC_ypos + (field_CC_sprite_scale * FP_FromInteger(-7)),
                        FP_FromDouble(0.3),
                        Layer::eLayer_Foreground_36);
                    field_128_timer = Math_NextRandom() % 16 + sGnFrame_5C1B84 + 60;
                }
                if (field_12C_deadtimer < (s32) sGnFrame_5C1B84)
                {
                    field_6_flags.Set(BaseGameObject::eDead_Bit3);
                }
                break;

            case MeatStates::eFall_5:
                field_C8_vely += FP_FromInteger(1);
                field_B8_xpos += field_C4_velx;
                field_BC_ypos = field_C8_vely + field_BC_ypos;
                if (!gMap_5C3030.Is_Point_In_Current_Camera_4810D0(field_C2_lvl_number, field_C0_path_number, field_B8_xpos, field_BC_ypos, 0))
                {
                    field_6_flags.Set(BaseGameObject::eDead_Bit3);
                }
                break;

            default:
                return;
        }
    }
}

// =================================================================================



const TintEntry kMeatTints_55C254[] = {
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
    {LevelIds_s8::eMudomoVault_Ender_11, 127u, 127u, 127u},
    {LevelIds_s8::eFeeCoDepot_Ender_12, 127u, 127u, 127u},
    {LevelIds_s8::eBarracks_Ender_13, 127u, 127u, 127u},
    {LevelIds_s8::eBonewerkz_Ender_14, 127u, 127u, 127u},
    {LevelIds_s8::eNone, 127u, 127u, 127u},
};


MeatSack* MeatSack::ctor_46A410(Path_MeatSack* pTlv, s32 tlvInfo)
{
    ctor_408240(0);
    SetVTable(this, 0x5460D4);

    SetType(AETypes::eMeatSack_85);

    const AnimRecord& rec = AnimRec(AnimId::MeatSack_Idle);
    u8** ppRes = Add_Resource_4DC130(ResourceManager::Resource_Animation, rec.mResourceId);
    Animation_Init_424E10(rec.mFrameTableOffset, rec.mMaxW, rec.mMaxH, ppRes, 1, 1);
    SetTint_425600(&kMeatTints_55C254[0], gMap_5C3030.field_0_current_level);

    field_DC_bApplyShadows &= ~1u;
    field_118_tlvInfo = tlvInfo;

    field_11C_bDoMeatSackIdleAnim = 0;

    field_B8_xpos = FP_FromInteger(pTlv->field_8_top_left.field_0_x);
    field_BC_ypos = FP_FromInteger(pTlv->field_8_top_left.field_2_y);

    field_124_velX = FP_FromRaw(pTlv->field_12_xVel << 8);

    // Throw the meat up into the air as it falls from the sack
    field_128_velY = -FP_FromRaw(pTlv->field_14_yVel << 8);

    if (pTlv->field_10_meat_fall_direction == XDirection_short::eLeft_0)
    {
        field_124_velX = -field_124_velX;
    }

    if (pTlv->field_16_scale == Scale_short::eHalf_1)
    {
        field_CC_sprite_scale = FP_FromDouble(0.5);
        field_20_animation.field_C_render_layer = Layer::eLayer_8;
        field_D6_scale = 0;
    }
    else if (pTlv->field_16_scale == Scale_short::eFull_0)
    {
        field_CC_sprite_scale = FP_FromInteger(1);
        field_20_animation.field_C_render_layer = Layer::eLayer_27;
        field_D6_scale = 1;
    }

    field_11E_amount_of_meat = pTlv->field_18_amount_of_meat;

    field_E0_pShadow = ae_new<Shadow>();
    if (field_E0_pShadow)
    {
        field_E0_pShadow->ctor_4AC990();
    }

    return this;
}

BaseGameObject* MeatSack::VDestructor(s32 flags)
{
    return vdtor_46A5E0(flags);
}

void MeatSack::VScreenChanged()
{
    vScreenChanged_46A9C0();
}

void MeatSack::VUpdate()
{
    vUpdate_46A6A0();
}

s32 Meat::VGetSaveState(u8* pSaveBuffer)
{
    return vGetSaveState_46AC40(reinterpret_cast<Meat_SaveState*>(pSaveBuffer));
}

s32 CC Meat::CreateFromSaveState_46A9E0(const u8* pBuffer)
{
    const auto pState = reinterpret_cast<const Meat_SaveState*>(pBuffer);

    auto pMeat = ae_new<Meat>();
    pMeat->ctor_4694A0(pState->field_8_xpos, pState->field_C_ypos, pState->field_2A_count);

    pMeat->field_C_objectId = pState->field_4_obj_id;

    pMeat->field_B8_xpos = pState->field_8_xpos;
    pMeat->field_BC_ypos = pState->field_C_ypos;

    pMeat->field_E4_collection_rect.x = pMeat->field_B8_xpos - (ScaleToGridSize_4498B0(pMeat->field_CC_sprite_scale) / FP_FromInteger(2));
    pMeat->field_E4_collection_rect.y = pMeat->field_BC_ypos - ScaleToGridSize_4498B0(pMeat->field_CC_sprite_scale);
    pMeat->field_E4_collection_rect.w = (ScaleToGridSize_4498B0(pMeat->field_CC_sprite_scale) / FP_FromInteger(2)) + pMeat->field_B8_xpos;
    pMeat->field_E4_collection_rect.h = pMeat->field_BC_ypos;

    pMeat->field_C4_velx = pState->field_10_velx;
    pMeat->field_C8_vely = pState->field_14_vely;

    pMeat->field_C0_path_number = pState->field_1C_path_number;
    pMeat->field_C2_lvl_number = pState->field_1E_lvl_number;

    pMeat->field_CC_sprite_scale = pState->field_18_sprite_scale;

    pMeat->field_20_animation.field_4_flags.Set(AnimFlags::eBit8_Loop, pState->field_20_flags.Get(Meat_SaveState::eBit3_bLoop));
    pMeat->field_20_animation.field_4_flags.Set(AnimFlags::eBit3_Render, pState->field_20_flags.Get(Meat_SaveState::eBit1_bRender));

    pMeat->field_6_flags.Set(BaseGameObject::eDrawable_Bit4, pState->field_20_flags.Get(Meat_SaveState::eBit2_bDrawable));
    pMeat->field_6_flags.Set(BaseGameObject::eInteractive_Bit8, pState->field_20_flags.Get(Meat_SaveState::eBit4_bInteractive));

    pMeat->field_114_flags.Set(Flags_114::e114_Bit9_RestoredFromQuickSave);

    pMeat->field_128_timer = sGnFrame_5C1B84;
    pMeat->field_104_collision_line_type = pState->field_28_line_type;

    pMeat->field_118_count = pState->field_2A_count;
    pMeat->field_11C_state = pState->field_2C_state;

    pMeat->field_120_xpos = pState->field_30_xpos;
    pMeat->field_124_ypos = pState->field_34_ypos;

    pMeat->field_12C_deadtimer = pState->field_38_savedfield12C;
    return sizeof(Meat_SaveState);
}

MeatSack* MeatSack::vdtor_46A5E0(s32 flags)
{
    dtor_46A610();
    if (flags & 1)
    {
        ae_delete_free_495540(this);
    }
    return this;
}

void MeatSack::dtor_46A610()
{
    SetVTable(this, 0x5460D4);
    Path::TLV_Reset_4DB8E0(field_118_tlvInfo, -1, 0, 0);
    dtor_4080B0();
}

void MeatSack::vScreenChanged_46A9C0()
{
    field_6_flags.Set(BaseGameObject::eDead_Bit3);
}

void MeatSack::vUpdate_46A6A0()
{
    if (Event_Get_422C00(kEventDeathReset))
    {
        field_6_flags.Set(BaseGameObject::eDead_Bit3);
    }

    if (field_20_animation.field_92_current_frame == 2)
    {
        if (field_120_bPlayWobbleSound)
        {
            if (Math_NextRandom() < 40u || field_122_always_0)
            {
                field_120_bPlayWobbleSound = 0;
                field_122_always_0 = 0;
                SFX_Play_46FBA0(SoundEffect::SackWobble_29, 24, Math_RandomRange_496AB0(-2400, -2200));
            }
        }
    }
    else
    {
        field_120_bPlayWobbleSound = 1;
    }

    if (field_11C_bDoMeatSackIdleAnim)
    {
        if (field_11C_bDoMeatSackIdleAnim == 1 && field_20_animation.field_4_flags.Get(AnimFlags::eBit18_IsLastFrame))
        {
            const AnimRecord& rec = AnimRec(AnimId::MeatSack_Idle);
            field_20_animation.Set_Animation_Data_409C80(rec.mFrameTableOffset, 0);
            field_11C_bDoMeatSackIdleAnim = 0;
        }
    }
    else
    {
        PSX_RECT abeRect = {};
        sActiveHero_5C1B68->vGetBoundingRect_424FD0(&abeRect, 1);

        PSX_RECT ourRect = {};
        vGetBoundingRect_424FD0(&ourRect, 1);

        if (RectsOverlap(ourRect, abeRect) && field_CC_sprite_scale == sActiveHero_5C1B68->field_CC_sprite_scale)
        {
            const AnimRecord& MeatSackHitRec = AnimRec(AnimId::MeatSack_Hit);
            if (gpThrowableArray_5D1E2C)
            {
                if (gpThrowableArray_5D1E2C->field_20_count)
                {
                    field_20_animation.Set_Animation_Data_409C80(MeatSackHitRec.mFrameTableOffset, 0);
                    field_11C_bDoMeatSackIdleAnim = 1;
                    return;
                }
            }
            else
            {
                gpThrowableArray_5D1E2C = ae_new<ThrowableArray>();
                gpThrowableArray_5D1E2C->ctor_49A630();
            }

            gpThrowableArray_5D1E2C->Add_49A7A0(field_11E_amount_of_meat);

            auto pMeat = ae_new<Meat>();
            if (pMeat)
            {
                pMeat->ctor_4694A0(field_B8_xpos, field_BC_ypos - FP_FromInteger(30), field_11E_amount_of_meat);
            }

            pMeat->VThrow_49E460(field_124_velX, field_128_velY);
            pMeat->field_CC_sprite_scale = field_CC_sprite_scale;

            SFX_Play_46FA90(SoundEffect::SackHit_25, 0);
            Environment_SFX_457A40(EnvironmentSfx::eDeathNoise_7, 0, 0x7FFF, 0);

            field_20_animation.Set_Animation_Data_409C80(MeatSackHitRec.mFrameTableOffset, 0);
            field_11C_bDoMeatSackIdleAnim = 1;
        }
    }
}

s32 Meat::vGetSaveState_46AC40(Meat_SaveState* pState)
{
    pState->field_0_type = AETypes::eMeat_84;
    pState->field_4_obj_id = field_C_objectId;

    pState->field_8_xpos = field_B8_xpos;
    pState->field_C_ypos = field_BC_ypos;

    pState->field_10_velx = field_C4_velx;
    pState->field_14_vely = field_C8_vely;

    pState->field_1C_path_number = field_C0_path_number;
    pState->field_1E_lvl_number = field_C2_lvl_number;

    pState->field_18_sprite_scale = field_CC_sprite_scale;

    pState->field_20_flags.Set(Meat_SaveState::eBit3_bLoop, field_20_animation.field_4_flags.Get(AnimFlags::eBit8_Loop));
    pState->field_20_flags.Set(Meat_SaveState::eBit1_bRender, field_20_animation.field_4_flags.Get(AnimFlags::eBit3_Render));

    pState->field_20_flags.Set(Meat_SaveState::eBit2_bDrawable, field_6_flags.Get(BaseGameObject::eDrawable_Bit4));
    pState->field_20_flags.Set(Meat_SaveState::eBit4_bInteractive, field_6_flags.Get(BaseGameObject::eInteractive_Bit8));

    if (field_130_pLine)
    {
        pState->field_28_line_type = field_130_pLine->field_8_type;
    }
    else
    {
        pState->field_28_line_type = -1;
    }

    pState->field_24_base_id = field_110_id;
    pState->field_2A_count = field_118_count;
    pState->field_2C_state = field_11C_state;

    pState->field_30_xpos = field_120_xpos;
    pState->field_34_ypos = field_124_ypos;

    pState->field_38_savedfield12C = field_12C_deadtimer;

    return sizeof(Meat_SaveState);
}

Bool32 Meat::vCanEatMe_4696A0()
{
    return field_11C_state != MeatStates::eCreated_0;
}
