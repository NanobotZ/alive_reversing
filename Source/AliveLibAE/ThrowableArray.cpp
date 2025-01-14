#include "stdafx.h"
#include "ThrowableArray.hpp"
#include "Function.hpp"
#include "stdlib.hpp"
#include "Map.hpp"
#include "PathData.hpp"
#include "Throwable.hpp"
#include "Abe.hpp"
#include "ChaosModHelpers.hpp"

ALIVE_VAR(1, 0x5d1e2c, ThrowableArray*, gpThrowableArray_5D1E2C, nullptr);

void CCSTD FreeResourceArray_49AEC0(DynamicArrayT<u8*>* pArray)
{
    while (pArray->Size())
    {
        auto item = pArray->ItemAt(0);
        ResourceManager::FreeResource_49C330(item);
        pArray->Remove_Item(item);
    }
}

void CC LoadRockTypes_49AB30(LevelIds levelNumber, u16 pathNumber)
{
    if (sActiveHero_5C1B68->field_chaos_throwableType != AETypes::eNone_0)
    {
        ChaosModHelpers::LoadThrowableResources(sActiveHero_5C1B68->field_chaos_throwableType);
        return;
    }

    Bool32 bDoLoadingLoop = FALSE;
    const u8 throwableTypeIdx = LOBYTE(Path_Get_Bly_Record_460F30(levelNumber, pathNumber)->field_C_overlay_id);

    if (!ResourceManager::GetLoadedResource_49C2A0(ResourceManager::Resource_Animation, AEResourceID::kAbepickResID, 0, 0))
    {
        bDoLoadingLoop = TRUE;
        ResourceManager::LoadResourceFile_49C130("ABEPICK.BAN", 0, 0, 0);
    }

    if (!ResourceManager::GetLoadedResource_49C2A0(ResourceManager::Resource_Animation, AEResourceID::kAbethrowResID, 0, 0))
    {
        bDoLoadingLoop = TRUE;
        ResourceManager::LoadResourceFile_49C130("ABETHROW.BAN", 0, 0, 0);
    }

    switch (throwable_types_55FAFC[throwableTypeIdx])
    {
        case AETypes::eBone_11:
            if (!ResourceManager::GetLoadedResource_49C2A0(ResourceManager::Resource_Animation, AEResourceID::kBoneResID, 0, 0))
            {
                bDoLoadingLoop = TRUE;
                ResourceManager::LoadResourceFile_49C130("BONE.BAN", 0, 0, 0);
            }
            break;

        case AETypes::eMetal_24:
            if (!ResourceManager::GetLoadedResource_49C2A0(ResourceManager::Resource_Animation, AEResourceID::kMetalGibResID, 0, 0))
            {
                bDoLoadingLoop = TRUE;
                ResourceManager::LoadResourceFile_49C130("METAL.BAN", 0, 0, 0);
            }

            if (!ResourceManager::GetLoadedResource_49C2A0(ResourceManager::Resource_Animation, AEResourceID::kGrenadeResID, 0, 0))
            {
                bDoLoadingLoop = TRUE;
                ResourceManager::LoadResourceFile_49C130("GRENADE.BAN", 0, 0, 0);
            }
            break;

        case AETypes::eGrenade_65:
            if (!ResourceManager::GetLoadedResource_49C2A0(ResourceManager::Resource_Animation, AEResourceID::kExplo2ResID, 0, 0))
            {
                bDoLoadingLoop = TRUE;
                ResourceManager::LoadResourceFile_49C130("EXPLO2.BAN", 0, 0, 0);
            }

            if (!ResourceManager::GetLoadedResource_49C2A0(ResourceManager::Resource_Animation, AEResourceID::kAbeblowResID, 0, 0))
            {
                bDoLoadingLoop = TRUE;
                ResourceManager::LoadResourceFile_49C130("ABEBLOW.BAN", 0, 0, 0);
            }

            if (!ResourceManager::GetLoadedResource_49C2A0(ResourceManager::Resource_Animation, AEResourceID::kSlogBlowResID, 0, 0))
            {
                bDoLoadingLoop = TRUE;
                ResourceManager::LoadResourceFile_49C130("DOGBLOW.BAN", 0, 0, 0);
            }

            if (!ResourceManager::GetLoadedResource_49C2A0(ResourceManager::Resource_Animation, AEResourceID::kMetalGibResID, 0, 0))
            {
                bDoLoadingLoop = TRUE;
                ResourceManager::LoadResourceFile_49C130("METAL.BAN", 0, 0, 0);
            }

            if (!ResourceManager::GetLoadedResource_49C2A0(ResourceManager::Resource_Animation, AEResourceID::kGrenadeResID, 0, 0))
            {
                bDoLoadingLoop = TRUE;
                ResourceManager::LoadResourceFile_49C130("GRENADE.BAN", 0, 0, 0);
            }
            break;

        case AETypes::eMeat_84:
            if (!ResourceManager::GetLoadedResource_49C2A0(ResourceManager::Resource_Animation, AEResourceID::kMeatResID, 0, 0))
            {
                bDoLoadingLoop = TRUE;
                ResourceManager::LoadResourceFile_49C130("MEAT.BAN", 0, 0, 0);
            }
            break;

        case AETypes::eRock_105:
            if (!ResourceManager::GetLoadedResource_49C2A0(ResourceManager::Resource_Animation, AEResourceID::kAberockResID, 0, 0))
            {
                bDoLoadingLoop = TRUE;
                ResourceManager::LoadResourceFile_49C130("PUIROCK.BAN", 0, 0, 0);
            }
            break;

        default:
            break;
    }

    if (bDoLoadingLoop)
    {
        pResourceManager_5C1BB0->LoadingLoop_465590(FALSE);
    }
}

ThrowableArray* ThrowableArray::ctor_49A630()
{
    BaseGameObject_ctor_4DBFA0(1, 0);
    SetVTable(this, 0x5469E4);
    field_24_throwables.ctor_40C9E0(0);
    field_6_flags.Clear(BaseGameObject::eUpdatable_Bit2);
    field_20_count = 0;
    gpThrowableArray_5D1E2C = this;
    field_22_flags.Clear(Flags_22::eBit1_Unknown);
    field_22_flags.Clear(Flags_22::eBit2_Unknown);
    field_22_flags.Clear(Flags_22::eBit3_Unknown);
    return this;
}

void ThrowableArray::dtor_49A6F0()
{
    SetVTable(this, 0x5469E4);
    gpThrowableArray_5D1E2C = 0;
    FreeResourceArray_49AEC0(&field_24_throwables);
    field_24_throwables.dtor_40CAD0();
    BaseGameObject_dtor_4DBEC0();
}

BaseGameObject* ThrowableArray::vdtor_49A6C0(s32 flags)
{
    dtor_49A6F0();
    if (flags & 1)
    {
        ae_delete_free_495540(this);
    }
    return this;
}

void ThrowableArray::Remove_49AA00(s16 count)
{
    field_20_count -= count;
    if (field_20_count > 0)
    {
        if (field_22_flags.Get(Flags_22::eBit1_Unknown) && field_22_flags.Get(Flags_22::eBit2_Unknown))
        {
            FreeResourceArray_49AEC0(&field_10_resources_array);
            field_22_flags.Clear(Flags_22::eBit2_Unknown);
        }
    }
    else
    {
        field_6_flags.Set(BaseGameObject::eDead_Bit3);
    }
}

void ThrowableArray::vUpdate_49AA50()
{
    if (field_22_flags.Get(Flags_22::eBit1_Unknown))
    {
        LoadRockTypes_49AB30(gMap_5C3030.field_0_current_level, gMap_5C3030.field_2_current_path);
        Add_49A7A0(0);
        field_22_flags.Clear(Flags_22::eBit1_Unknown);
        field_6_flags.Clear(BaseGameObject::eUpdatable_Bit2);
    }
}

s32 ThrowableArray::vGetSaveState_49B2A0(u8* pSaveBuffer)
{
    ThrowableArray_SaveState* pState = reinterpret_cast<ThrowableArray_SaveState*>(pSaveBuffer);
    pState->field_0_unused = 102; // never gets read back, no idea what it means :)
    pState->field_2_item_count = field_20_count;
    return sizeof(ThrowableArray_SaveState);
}

void ThrowableArray::vScreenChange_49AAA0()
{
    if (gMap_5C3030.field_A_level != LevelIds::eMenu_0 && gMap_5C3030.field_A_level != LevelIds::eCredits_16)
    {
        if (throwable_types_55FAFC[gMap_5C3030.field_22_overlayID] != throwable_types_55FAFC[gMap_5C3030.GetOverlayId_480710()])
        {
            if (!(field_22_flags.Get(Flags_22::eBit1_Unknown)))
            {
                field_6_flags.Set(BaseGameObject::eUpdatable_Bit2);
                field_22_flags.Set(Flags_22::eBit1_Unknown);
                Remove_49AA00(0);
            }
        }
    }
    else
    {
        field_6_flags.Set(BaseGameObject::eDead_Bit3);
    }
}

void ThrowableArray::Add_49A7A0(s16 count, AETypes forceType)
{
    if (field_6_flags.Get(BaseGameObject::eDead_Bit3))
    {
        field_6_flags.Clear(BaseGameObject::eDead_Bit3);
    }

    if (field_20_count == 0)
    {
        if (!field_22_flags.Get(Flags_22::eBit3_Unknown))
        {
            u8** ppRes1 = ResourceManager::GetLoadedResource_49C2A0(ResourceManager::Resource_Animation, AEResourceID::kAbepickResID, 1, 0);
            if (ppRes1)
            {
                field_24_throwables.Push_Back_40CAF0(ppRes1);
            }

            u8** ppRes2 = ResourceManager::GetLoadedResource_49C2A0(ResourceManager::Resource_Animation, AEResourceID::kAbethrowResID, 1, 0);
            if (ppRes2)
            {
                field_24_throwables.Push_Back_40CAF0(ppRes2);
            }

            field_22_flags.Set(Flags_22::eBit3_Unknown);
        }
    }

    if (field_20_count == 0 || field_22_flags.Get(Flags_22::eBit1_Unknown))
    {
        if (!field_22_flags.Get(Flags_22::eBit2_Unknown))
        {
            switch (forceType == AETypes::eNone_0 ? throwable_types_55FAFC[gMap_5C3030.field_22_overlayID] : forceType)
            {
                case AETypes::eBone_11:
                    Add_Resource_4DC130(ResourceManager::Resource_Animation, AEResourceID::kBoneResID);
                    break;

                case AETypes::eMetal_24:
                    Add_Resource_4DC130(ResourceManager::Resource_Animation, AEResourceID::kMetalGibResID);
                    Add_Resource_4DC130(ResourceManager::Resource_Animation, AEResourceID::kGrenadeResID);
                    Add_Resource_4DC130(ResourceManager::Resource_Palt, AEResourceID::kGrenadeResID);
                    break;

                case AETypes::eGrenade_65:
                    Add_Resource_4DC130(ResourceManager::Resource_Animation, AEResourceID::kExplo2ResID);
                    Add_Resource_4DC130(ResourceManager::Resource_Animation, AEResourceID::kAbeblowResID);
                    Add_Resource_4DC130(ResourceManager::Resource_Animation, AEResourceID::kSlogBlowResID);
                    Add_Resource_4DC130(ResourceManager::Resource_Animation, AEResourceID::kMetalGibResID);
                    Add_Resource_4DC130(ResourceManager::Resource_Animation, AEResourceID::kGrenadeResID);
                    Add_Resource_4DC130(ResourceManager::Resource_Palt, AEResourceID::kGrenadeResID);
                    break;

                case AETypes::eMeat_84:
                    Add_Resource_4DC130(ResourceManager::Resource_Animation, AEResourceID::kMeatResID);
                    break;

                case AETypes::eRock_105:
                    Add_Resource_4DC130(ResourceManager::Resource_Animation, AEResourceID::kAberockResID);
                    Add_Resource_4DC130(ResourceManager::Resource_Palt, AEResourceID::kAberockResID);
                    break;

                default:
                    break;
            }

            field_22_flags.Set(Flags_22::eBit2_Unknown);
        }
    }

    field_20_count += count;
}

s32 CC ThrowableArray::CreateFromSaveState_49B200(const u8* pState)
{
    LoadRockTypes_49AB30(gMap_5C3030.field_0_current_level, gMap_5C3030.field_2_current_path);
    auto pArray = ae_new<ThrowableArray>();
    if (pArray)
    {
        pArray->ctor_49A630();
    }
    pArray->Add_49A7A0(reinterpret_cast<const ThrowableArray_SaveState*>(pState)->field_2_item_count);
    return sizeof(ThrowableArray_SaveState);
}

BaseGameObject* ThrowableArray::VDestructor(s32 flags)
{
    return vdtor_49A6C0(flags);
}

void ThrowableArray::VUpdate()
{
    vUpdate_49AA50();
}

void ThrowableArray::VRender(PrimHeader** /*ppOt*/)
{
    // Empty 0x4DBF80
}

s32 ThrowableArray::VGetSaveState(u8* pSaveBuffer)
{
    return vGetSaveState_49B2A0(pSaveBuffer);
}

void ThrowableArray::VScreenChanged()
{
    vScreenChange_49AAA0();
}
