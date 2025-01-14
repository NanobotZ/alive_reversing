#pragma once

#include "BaseAliveGameObject.hpp"
#include "../AliveLibCommon/FunctionFwd.hpp"

class Explosion final : public ::BaseAnimatedWithPhysicsGameObject
{
public:
    EXPORT Explosion* ctor_4A1200(FP xpos, FP ypos, FP scale, s16 bSmall);

    virtual BaseGameObject* VDestructor(s32 flags) override;

    virtual void VUpdate() override;

    virtual void VScreenChanged() override;

private:
    EXPORT void DealBlastDamage_4A1BD0(PSX_RECT* pRect);

    EXPORT void vUpdate_4A1510();

    EXPORT void vScreenChanged_4A1EE0();

    EXPORT void dtor_4A14F0();

    EXPORT Explosion* vdtor_4A14C0(s32 flags);

private:
    s16 field_F4_bSmall;
    // s16 field_F6_pad;
    FP field_F8_scale;
    FP field_FC_explosion_size;

public:
    bool dontDoDamageToAbe;
};
ALIVE_ASSERT_SIZEOF(Explosion, 0x100);
