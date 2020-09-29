#pragma once

#include "FunctionFwd.hpp"

START_NS_AO

enum SoundEffect
{
    Unknown_0 = 0,
    Bullet1_1 = 1,
    Bullet2_2 = 2,
    GreenTick_3 = 3,
    RedTick_4 = 4,
    ZPop_5 = 5,
    SligShoot_6 = 6,
    BulletShell_7 = 7,
    MenuTransition_8 = 8,
    BellHammer_9 = 9,
    Unknown_10 = 10,
    Unknown_11 = 11,
    Unknown_12 = 12,
    HandstoneTransition_13 = 13,
    Unknown_14 = 14,
    Unknown_15 = 15,
    BirdPortalIdle_16 = 16,
    Unknown_17 = 17,
    Unknown_18 = 18,
    Unknown_19 = 19,
    Unknown_20 = 20,
    PossessEffect_21 = 21,
    Respawn_22 = 22,
    Unknown_23 = 23,
    WellExit_24 = 24,
    WellEnter_25 = 25,
    Unknown_26 = 26,
    Leaf_27 = 27,
    AirStream_28 = 28,
    RockBounceOnMine_29 = 29,
    SackHit_30 = 30,
    RockBounce_31 = 31,
    ParticleBurst_32 = 32,
    PickupItem_33 = 33,
    SackWobble_34 = 34,
    LiftStop_35 = 35,
    WheelSqueak_36 = 36,
    AbeGenericMovement_37 = 37,
    Unknown_38 = 38,
    Unknown_39 = 39,
    Unknown_40 = 40,
    Bat1_41 = 41,
    Bat2_42 = 42,
    MeatBounce_43 = 43,
    Unknown_44 = 44,
    Alarm_45 = 45,
    ElectricZap_46 = 46,
    ElectricGateLoud_47 = 47,
    BirdPortalSpark_48 = 48,
    Unknown_49 = 49,
    BellChime1_50 = 50,
    BellChime2_51 = 51,
    BellChime3_52 = 52,
    FallingItemHit_53 = 53,
    Unknown_54 = 54,
    Unknown_55 = 55,
    SecurityOrb_56 = 56,
    Unknown_57 = 57,
    TouchingMotionDetector_58 = 58,
    Unknown_59 = 59,
    HintFly_60 = 60,
    MenuNavigation_61 = 61,
    Unknown_62 = 62,
    Unknown_63 = 63,
    Unknown_64 = 64,
    RingRopePull_65 = 65,
    Unknown_66 = 66,
    PortalOpening_67 = 67,
    Unknown_68 = 68,
    Fire_69 = 69,
    Unknown_70 = 70,
    Unknown_71 = 71,
    Unknown_72 = 72,
    Unknown_73 = 73,
    Unknown_74 = 74,
    LeverPull_75 = 75,
    Unknown_76 = 76,
    Unknown_77 = 77,
    KillEffect_78 = 78,
    Unknown_79 = 79,
    Unknown_80 = 80,
    Unknown_81 = 81,
    GrenadeBounce_82 = 82,
    Unknown_83 = 83,
    Unknown_84 = 84,
    Scrub1_85 = 85,
    Scrub2_86 = 86,
    LCDScreen_87 = 87,
    MeatsawOffscreen_88 = 88,
    MeatsawIdle_89 = 89,
    MeatsawUp_90 = 90,
    MeatsawDown_91 = 91,
    Unknown_92 = 92,
    Unknown_93 = 93,
    TrapdoorClose_94 = 94,
    Unknown_95 = 95,
    Vaporize_96 = 96,
    IndustrialTrigger_97 = 97,
    Choke_98 = 98,
    Gas1_99 = 99,
    Gas2_100 = 100,
    GlukkonKillHim1_101 = 101,
    GlukkonKillHim2_102 = 102,
    GlukkonLaugh1_103 = 103,
    GlukkonLaugh2_104 = 104,
    Unknown_105 = 105,
    Unknown_106 = 106,
    IngameTransition_107 = 107,
    Shrykull1_108 = 108,
    Shrykull2_109 = 109,
    SligLaugh_110 = 110
};

class BaseAnimatedWithPhysicsGameObject;
class BaseAliveGameObject;
class BaseGameObject;

enum class CameraPos : __int16;

struct SfxDefinition
{
    int field_0_block_idx;
    int field_4_program;
    int field_8_note;
    __int16 field_C_default_volume;
    __int16 field_E_pitch_min;
    __int16 field_10_pitch_max;
    __int16 field_12_pad;
};
ALIVE_ASSERT_SIZEOF(SfxDefinition, 0x14);

EXPORT int CC SFX_Play_real_43AE60(unsigned __int8 sfxId, int volume, int pitch, BaseAnimatedWithPhysicsGameObject* pObj = nullptr);

EXPORT int CC SFX_Play_real_43AD70(unsigned __int8 sfxId, int a2, BaseGameObject* a3 = nullptr);

EXPORT int CC SFX_Play_real_43ADE0(unsigned __int8 sfxId, int leftVol, int rightVol, BaseAliveGameObject* pObj);

EXPORT int CC SFX_Play_real_43AED0(unsigned __int8 sfxId, signed int volume, CameraPos direction);



EXPORT int CC SFX_Play_43AE60(unsigned __int8 sfxId, int volume, int pitch, BaseAnimatedWithPhysicsGameObject* pObj = nullptr);

EXPORT int CC SFX_Play_43AD70(unsigned __int8 sfxId, int a2, BaseGameObject* a3 = nullptr);

EXPORT int CC SFX_Play_43ADE0(unsigned __int8 sfxId, int leftVol, int rightVol, BaseAliveGameObject* pObj);

EXPORT int CC SFX_Play_43AED0(unsigned __int8 sfxId, signed int volume, CameraPos direction);

END_NS_AO
