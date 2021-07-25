#include "stdafx_common.h"
#include "AnimResources.hpp"
#include "Sys_common.hpp"

constexpr PalDetails kNullPalDetails = {};
constexpr CombinedPalRecord kPalRecords[] = {
    {PalId::BlindMud, {"MUDPAL.BND", kMudblindResID}, kNullPalDetails },
};

constexpr AnimDetails kNullAnimDetails = {};

constexpr CombinedAnimRecord kAnimRecords[] = {
    {AnimId::Abe_Head_Gib, { "ABEBLOW.BAN", 7732, 50, 25, kAbeblowResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Arm_Gib, { "ABEBLOW.BAN", 7772, 50, 25, kAbeblowResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Body_Gib, { "ABEBLOW.BAN", 7812, 50, 25, kAbeblowResID, PalId::Default}, kNullAnimDetails },

    {AnimId::BlindMud_Head_Gib, { "ABEBLOW.BAN", 7732, 50, 25, kAbeblowResID, PalId::BlindMud}, kNullAnimDetails },
    {AnimId::BlindMud_Arm_Gib, { "ABEBLOW.BAN", 7772, 50, 25, kAbeblowResID, PalId::BlindMud}, kNullAnimDetails },
    {AnimId::BlindMud_Body_Gib, { "ABEBLOW.BAN", 7812, 50, 25, kAbeblowResID, PalId::BlindMud}, kNullAnimDetails },

    {AnimId::Glukkon_Head_Gib, { "GLUKKON.BND", 8140, 48, 28, kGlukkonResID_801, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Arm_Gib, { "GLUKKON.BND", 8188, 48, 28, kGlukkonResID_801, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Body_Gib, { "GLUKKON.BND", 8188, 48, 28, kGlukkonResID_801, PalId::Default}, kNullAnimDetails },

    {AnimId::Aslik_Head_Gib, { "ASLIK.BND", 8140, 48, 28, kAslikResID_803, PalId::Default}, kNullAnimDetails },
    {AnimId::Aslik_Arm_Gib, { "ASLIK.BND", 8188, 48, 28, kAslikResID_803, PalId::Default}, kNullAnimDetails },
    {AnimId::Aslik_Body_Gib, { "ASLIK.BND", 8188, 48, 28, kAslikResID_803, PalId::Default}, kNullAnimDetails },

    {AnimId::Dripik_Head_Gib, { "DRIPIK.BND", 8140, 48, 28, kDripikResID_805, PalId::Default}, kNullAnimDetails },
    {AnimId::Dripik_Arm_Gib, { "DRIPIK.BND", 8188, 48, 28, kDripikResID_805, PalId::Default}, kNullAnimDetails },
    {AnimId::Dripik_Body_Gib, { "DRIPIK.BND", 8188, 48, 28, kDripikResID_805, PalId::Default}, kNullAnimDetails },

    {AnimId::Phleg_Head_Gib, { "PHLEG.BND", 8140, 48, 28, kPhlegResID_807, PalId::Default}, kNullAnimDetails },
    {AnimId::Phleg_Arm_Gib, { "PHLEG.BND", 8188, 48, 28, kPhlegResID_807, PalId::Default}, kNullAnimDetails },
    {AnimId::Phleg_Body_Gib, { "PHLEG.BND", 8188, 48, 28, kPhlegResID_807, PalId::Default}, kNullAnimDetails },

    {AnimId::Fleech_Head_Gib, { "FLEEBLOW.BAN", 1088, 19, 8, kFleeBlowResID_580, PalId::Default}, kNullAnimDetails },
    {AnimId::Fleech_Body_Gib, { "FLEEBLOW.BAN", 1128, 19, 8, kFleeBlowResID_580, PalId::Default}, kNullAnimDetails },
    // Note: Fleech hasn't got arms

    {AnimId::Metal_Gib, { "METAL.BAN", 2244, 38, 29, kMetalGib, PalId::Default}, kNullAnimDetails },

    {AnimId::Slig_Head_Gib, { "SLGBLOW.BAN", 6480, 44, 26, kSligBlowResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Arm_Gib, { "SLGBLOW.BAN", 6560, 44, 26, kSligBlowResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Body_Gib, { "SLGBLOW.BAN", 6520, 44, 26, kSligBlowResID, PalId::Default}, kNullAnimDetails },

    {AnimId::Slog_Head_Gib, { "DOGBLOW.BAN", 7504, 53, 28, kSlogBlowResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Body_Gib, { "DOGBLOW.BAN", 7544, 53, 28, kSlogBlowResID, PalId::Default}, kNullAnimDetails },
    // Note: Slog hasn't got arms (apparently)

    // Note: Fleech animations are sorted by order of appearance under Fleech.cpp (line 242)
    // Lots of idle animations, they might be used for other things but I can't immediately identify their use otherwise.
    {AnimId::Fleech_Idle_A, { "FLEECH.BAN", 37808, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Fleech_Unknown_A, { "FLEECH.BAN", 37884, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails }, // Still frame of some kind
    {AnimId::Fleech_Unknown_B, { "FLEECH.BAN", 37896, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails }, // Slow broken animation, probably unused
    {AnimId::Fleech_Idle_B, { "FLEECH.BAN", 37704, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Fleech_Walk, { "FLEECH.BAN", 37748, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Fleech_Speak, { "FLEECH.BAN", 37784, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Fleech_Unknown_C, { "FLEECH.BAN", 37924, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails }, // Another still frame
    {AnimId::Fleech_Idle_C, { "FLEECH.BAN", 37936, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Fleech_Idle_D, { "FLEECH.BAN", 37960, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Fleech_Falling, { "FLEECH.BAN", 37984, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Fleech_Landing, { "FLEECH.BAN", 38060, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Fleech_Tongue, { "FLEECH.BAN", 38112, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails },    // Used when the fleech attacks or grabbing a ledge
    {AnimId::Fleech_Climb_A, { "FLEECH.BAN", 38156, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails },   // Used while swinging up a ledge
    {AnimId::Fleech_Climb_B, { "FLEECH.BAN", 38208, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails },   // Used when fleech has reached the top of a ledge
    {AnimId::Fleech_Unknown_D, { "FLEECH.BAN", 38260, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails }, // Some sort of quick 2 frame animation
    {AnimId::Fleech_Unknown_E, { "FLEECH.BAN", 37848, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails }, // Seems to be a much slowed down version of Fleech_Tongue
    {AnimId::Fleech_Unknown_F, { "FLEECH.BAN", 38248, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails }, // Another still frame
    {AnimId::Fleech_Sleep, { "FLEECH.BAN", 38396, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Fleech_Eat, { "FLEECH.BAN", 38276, 73, 35u, kFleechResID, PalId::Default}, kNullAnimDetails },

    {AnimId::Flying_Slig_Idle, { "FLYSLIG.BND", 116888, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Move_Horizontal, { "FLYSLIG.BND", 116912, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Idle_Turn_Around, { "FLYSLIG.BND", 117084, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Move_Down, { "FLYSLIG.BND", 116988, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Move_Down_Turn_Around, { "FLYSLIG.BND", 117584, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Move_Up, { "FLYSLIG.BND", 117012, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Move_Up_Turn_Around, { "FLYSLIG.BND", 117616, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Pull_Lever, { "FLYSLIG.BND", 117188, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Speak, { "FLYSLIG.BND", 117132, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Possession, { "FLYSLIG.BND", 117524, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Move_Horizontal_End, { "FLYSLIG.BND", 117060, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Move_Up_Start, { "FLYSLIG.BND", 117316, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Move_Horizontal_To_Down, { "FLYSLIG.BND", 117276, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Move_Up_To_Horizontal, { "FLYSLIG.BND", 117444, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Move_Down_To_Horizontal, { "FLYSLIG.BND", 117376, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Turn_Quick, { "FLYSLIG.BND", 116936, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Idle_To_Horizontal, { "FLYSLIG.BND", 117036, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Move_Down_Start, { "FLYSLIG.BND", 117336, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Move_Down_End, { "FLYSLIG.BND", 117356, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Knockback_Down, { "FLYSLIG.BND", 117396, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Knockback_Up, { "FLYSLIG.BND", 117464, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Move_Up_End, { "FLYSLIG.BND", 117424, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Up_Turn_Instant, { "FLYSLIG.BND", 117552, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Down_Turn_Instant, { "FLYSLIG.BND", 117492, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Move_Horizontal_To_Up, { "FLYSLIG.BND", 117296, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Flying_Slig_Turn_Horizontal, { "FLYSLIG.BND", 117752, 107, 48u, kFlySligResID, PalId::Default}, kNullAnimDetails },

    // Note: Glukkon animations are sorted by order of appearance under Glukkon.ccp (line 80)
    {AnimId::Glukkon_Normal_Idle, { "GLUKKON.BND", 169608, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Normal_Walk, { "GLUKKON.BND", 169644, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Normal_Turn_Around, { "GLUKKON.BND", 169724, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Normal_Fall_Over, { "GLUKKON.BND", 169772, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Normal_Jump, { "GLUKKON.BND", 169828, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Normal_Unknown_A, { "GLUKKON.BND", 169900, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails }, // Segmented jump animation?
    {AnimId::Glukkon_Normal_Unknown_B, { "GLUKKON.BND", 169920, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails }, // ^
    {AnimId::Glukkon_Normal_Unknown_C, { "GLUKKON.BND", 169952, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails }, // ^
    {AnimId::Glukkon_Normal_Unknown_D, { "GLUKKON.BND", 169968, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails }, // Segmented standing back up?
    {AnimId::Glukkon_Normal_Landing, { "GLUKKON.BND", 170000, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Normal_Possessed_A, { "GLUKKON.BND", 170152, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Normal_Speak_A, { "GLUKKON.BND", 170216, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails }, // Speak: "Hey", "Do it", "Help"
    {AnimId::Glukkon_Normal_Speak_B, { "GLUKKON.BND", 170268, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails }, // Speak: "Come here", "Kill em", "All of ya"
    {AnimId::Glukkon_Normal_Laugh, { "GLUKKON.BND", 170056, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Normal_Unknown_E, { "GLUKKON.BND", 170312, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails },   // No idea what this could be for...
    {AnimId::Glukkon_Normal_Unknown_F, { "GLUKKON.BND", 170332, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails },   // ^
    {AnimId::Glukkon_Normal_Unknown_G, { "GLUKKON.BND", 170352, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails },   // ^
    {AnimId::Glukkon_Normal_Unknown_H, { "GLUKKON.BND", 170372, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails },   // ^
    {AnimId::Glukkon_Normal_Unknown_I, { "GLUKKON.BND", 170392, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails },   // ^
    {AnimId::Glukkon_Normal_Unknown_J, { "GLUKKON.BND", 170412, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails },   // Segmented landing animation?
    {AnimId::Glukkon_Normal_Stand_Up_A, { "GLUKKON.BND", 170432, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails },  // First half of standing up
    {AnimId::Glukkon_Normal_Possessed_B, { "GLUKKON.BND", 170152, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails }, // Same as Possessed_A?
    {AnimId::Glukkon_Normal_Stand_Up_B, { "GLUKKON.BND", 170472, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails },  // Second half of standing up
    {AnimId::Glukkon_Normal_Speak_C, { "GLUKKON.BND", 170504, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails },     // Speak: "Stay here"
    {AnimId::Glukkon_Normal_Unknown_K, { "GLUKKON.BND", 170560, 163, 79, kGlkbasicResID, PalId::Default}, kNullAnimDetails },   // No idea what this could be for...

    {AnimId::Glukkon_Aslik_Idle, { "ASLIK.BND", 171356, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Walk, { "ASLIK.BND", 171392, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Turn_Around, { "ASLIK.BND", 171472, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Fall_Over, { "ASLIK.BND", 171520, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Jump, { "ASLIK.BND", 171576, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Unknown_A, { "ASLIK.BND", 171648, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Unknown_B, { "ASLIK.BND", 171668, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Unknown_C, { "ASLIK.BND", 171700, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Unknown_D, { "ASLIK.BND", 171716, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Landing, { "ASLIK.BND", 171748, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Possessed_A, { "ASLIK.BND", 171900, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Speak_A, { "ASLIK.BND", 171964, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Speak_B, { "ASLIK.BND", 172016, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Laugh, { "ASLIK.BND", 171804, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Unknown_E, { "ASLIK.BND", 172060, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Unknown_F, { "ASLIK.BND", 172080, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Unknown_G, { "ASLIK.BND", 172100, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Unknown_H, { "ASLIK.BND", 172120, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Unknown_I, { "ASLIK.BND", 172140, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Unknown_J, { "ASLIK.BND", 172160, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Stand_Up_A, { "ASLIK.BND", 172180, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Possessed_B, { "ASLIK.BND", 171900, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Stand_Up_B, { "ASLIK.BND", 172220, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Speak_C, { "ASLIK.BND", 172252, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Aslik_Unknown_K, { "ASLIK.BND", 172308, 157, 76, kGlukAslikResID, PalId::Default}, kNullAnimDetails },

    {AnimId::Glukkon_Phleg_Idle, { "PHLEG.BND", 199500, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Walk, { "PHLEG.BND", 199536, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Turn_Around, { "PHLEG.BND", 199616, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Fall_Over, { "PHLEG.BND", 199664, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Jump, { "PHLEG.BND", 199720, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Unknown_A, { "PHLEG.BND", 199792, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Unknown_B, { "PHLEG.BND", 199812, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Unknown_C, { "PHLEG.BND", 199844, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Unknown_D, { "PHLEG.BND", 199860, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Landing, { "PHLEG.BND", 199892, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Possessed_A, { "PHLEG.BND", 200044, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Speak_A, { "PHLEG.BND", 200108, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Speak_B, { "PHLEG.BND", 200160, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Laugh, { "PHLEG.BND", 199948, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Unknown_E, { "PHLEG.BND", 200204, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Unknown_F, { "PHLEG.BND", 200224, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Unknown_G, { "PHLEG.BND", 200244, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Unknown_H, { "PHLEG.BND", 200264, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Unknown_I, { "PHLEG.BND", 200284, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Unknown_J, { "PHLEG.BND", 200304, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Stand_Up_A, { "PHLEG.BND", 200324, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Possessed_B, { "PHLEG.BND", 200044, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Stand_Up_B, { "PHLEG.BND", 200364, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Speak_C, { "PHLEG.BND", 200396, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Phleg_Unknown_K, { "PHLEG.BND", 200452, 145, 72, kGlukPhlegResID, PalId::Default}, kNullAnimDetails },

    {AnimId::Glukkon_Dripik_Idle, { "DRIPIK.BND", 193064, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Walk, { "DRIPIK.BND", 193100, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Turn_Around, { "DRIPIK.BND", 193180, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Fall_Over, { "DRIPIK.BND", 193228, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Jump, { "DRIPIK.BND", 193284, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Unknown_A, { "DRIPIK.BND", 193356, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Unknown_B, { "DRIPIK.BND", 193376, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Unknown_C, { "DRIPIK.BND", 193408, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Unknown_D, { "DRIPIK.BND", 193424, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Landing, { "DRIPIK.BND", 193456, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Possessed_A, { "DRIPIK.BND", 193608, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Speak_A, { "DRIPIK.BND", 193672, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Speak_B, { "DRIPIK.BND", 193724, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Laugh, { "DRIPIK.BND", 193512, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Unknown_E, { "DRIPIK.BND", 193768, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Unknown_F, { "DRIPIK.BND", 193788, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Unknown_G, { "DRIPIK.BND", 193808, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Unknown_H, { "DRIPIK.BND", 193828, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Unknown_I, { "DRIPIK.BND", 193848, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Unknown_J, { "DRIPIK.BND", 193868, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Stand_Up_A, { "DRIPIK.BND", 193888, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Possessed_B, { "DRIPIK.BND", 193608, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Stand_Up_B, { "DRIPIK.BND", 193928, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Speak_C, { "DRIPIK.BND", 193960, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Glukkon_Dripik_Unknown_K, { "DRIPIK.BND", 194016, 145, 72, kGlukDripikResID, PalId::Default}, kNullAnimDetails },

    {AnimId::Greeter_Idle, { "GREETER.BAN", 50028, 65, 60, kGreeterResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Greeter_Turn_Around, { "GREETER.BAN", 50072, 65, 60, kGreeterResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Greeter_Hit, { "GREETER.BAN", 50236, 65, 60, kGreeterResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Greeter_Speak, { "GREETER.BAN", 50104, 65, 60, kGreeterResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Greeter_Chase, { "GREETER.BAN", 50144, 65, 60, kGreeterResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Greeter_Falling, { "GREETER.BAN", 50212, 65, 60, kGreeterResID, PalId::Default}, kNullAnimDetails },

    {AnimId::Mine_Car_Closed, { "BAYROLL.BAN", 20836, 130, 62u, kBayrollResID_6013, PalId::Default}, kNullAnimDetails },
    {AnimId::Mine_Car_Open, { "BAYROLL.BAN", 20812, 130, 62u, kBayrollResID_6013, PalId::Default}, kNullAnimDetails },
    {AnimId::Mine_Car_Shake_A, { "BAYROLL.BAN", 20872, 130, 62u, kBayrollResID_6013, PalId::Default}, kNullAnimDetails },
    {AnimId::Mine_Car_Shake_B, { "BAYROLL.BAN", 20900, 130, 62u, kBayrollResID_6013, PalId::Default}, kNullAnimDetails },
    {AnimId::Mine_Car_Tread_Idle, { "BAYROLL.BAN", 20824, 130, 62u, kBayrollResID_6013, PalId::Default}, kNullAnimDetails },
    {AnimId::Mine_Car_Tread_Move_A, { "BAYROLL.BAN", 20848, 130, 62u, kBayrollResID_6013, PalId::Default}, kNullAnimDetails },
    {AnimId::Mine_Car_Tread_Move_B, { "BAYROLL.BAN", 20788, 130, 62u, kBayrollResID_6013, PalId::Default}, kNullAnimDetails },

    // The Mudokon section includes all of abe's animations as well since they share many animations
    {AnimId::Abe_Unknown_A, { "ABEBSIC1.BAN", 59112, 135, 80, kAbebsic1ResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Unknown_B, { "ABEBSIC.BAN", 270240, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Crouch_Talk_A, { "ABEBSIC.BAN", 271080, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Crouch_Talk_B, { "ABEBSIC.BAN", 271120, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Roll_Start, { "ABEBSIC.BAN", 269688, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Roll, { "ABEBSIC.BAN", 269708, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Roll_End, { "ABEBSIC.BAN", 269764, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Hop_Start, { "ABEBSIC.BAN", 271004, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Hop, { "ABEBSIC.BAN", 271056, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Hop_End, { "ABEBSIC.BAN", 270964, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Unknown_C, { "ABEBSIC.BAN", 270488, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Shrug_End, { "ABEBSIC.BAN", 270616, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Crouch_Start, { "ABEBSIC.BAN", 270708, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Unknown_D, { "ABEBSIC.BAN", 270140, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Unknown_E, { "ABEBSIC.BAN", 269784, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Unknown_F, { "ABEBSIC.BAN", 269856, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Unknown_G, { "ABEBSIC.BAN", 270944, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Sorry_Start, { "ABEBSIC.BAN", 271192, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Sorry_End, { "ABEBSIC.BAN", 271248, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Hoist_Up, { "ABEHOIST.BAN", 57440, 135, 80, kAbehoistResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Hoist_Down, { "ABEHOIST.BAN", 57580, 135, 80, kAbehoistResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Hoist, { "ABEHOIST.BAN", 57540, 135, 80, kAbehoistResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Hoist_Swing, { "ABEHOIST.BAN", 57712, 135, 80, kAbehoistResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Hoist_High, { "ABEHOIST.BAN", 57680, 135, 80, kAbehoistResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Push, { "ABEKNBK.BAN", 49912, 135, 80, kAbeknbkResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Knock_Back, { "ABEKNBK.BAN", 49856, 135, 80, kAbeknbkResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Well_Enter_Start, { "ABEWELL.BAN", 20572, 135, 80, kAbewellResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Well, { "ABEWELL.BAN", 20552, 135, 80, kAbewellResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Well_Enter, { "ABEWELL.BAN", 20404, 135, 80, kAbewellResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Death_Fall, { "ABESMASH.BAN", 8104, 135, 80, kAbesmashResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Fall_A, { "ABEFALL.BAN", 5724, 135, 80, kAbefallResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Handstone_Start, { "ABESTONE.BAN", 16096, 135, 80, kAbestoneResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Handstone_End, { "ABESTONE.BAN", 16040, 135, 80, kAbestoneResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Handstone_Short, { "ABESTONE.BAN", 16220, 135, 80, kAbestoneResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Fall_B, { "ABEEDGE.BAN", 32068, 135, 80, kAbeedgeResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Fall_C, { "ABEEDGE.BAN", 32112, 135, 80, kAbeedgeResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Unknown_H, { "ABEEDGE.BAN", 32168, 135, 80, kAbeedgeResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Unknown_I, { "ABEEDGE.BAN", 32152, 135, 80, kAbeedgeResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Unknown_J, { "ABEEDGE.BAN", 32132, 135, 80, kAbeedgeResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Slap_Bomb, { "ABEBOMB.BAN", 6520, 135, 80, kAbebombResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Knock_Forward, { "ABEKNFD.BAN", 17180, 135, 80, kAbeknfdResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Rock, { "ABETHROW.BAN", 31504, 135, 80, kAbethrowResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Rock_Throw, { "ABETHROW.BAN", 31392, 135, 80, kAbethrowResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Rock_Cancel, { "ABETHROW.BAN", 31632, 135, 80, kAbethrowResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Rock_Crouch, { "ABETHROW.BAN", 31576, 135, 80, kAbethrowResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Rock_Crouch_Throw, { "ABETHROW.BAN", 31432, 135, 80, kAbethrowResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Death_Z_A, { "ABEKNOKZ.BAN", 24580, 135, 80, kAbeknokzResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Death_Z_B, { "ABEKNOKZ.BAN", 24628, 135, 80, kAbeknokzResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Item_Grab, { "ABEPICK.BAN", 6004, 135, 80, kAbepickResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Door_Enter, { "ABEDOOR.BAN", 19040, 135, 80, kAbedoorResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Door_Exit, { "ABEDOOR.BAN", 19088, 135, 80, kAbedoorResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Mine_Car_Enter, { "ABECAR.BAN", 8540, 135, 80, kAbeCarResId, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Mine_Car_Exit, { "ABECAR.BAN", 8588, 135, 80, kAbeCarResId, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Shrykull_Start, { "ABEMORPH.BAN", 8732, 135, 80, kAbemorphResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Shrykull_End, { "ABEMORPH.BAN", 8772, 135, 80, kAbemorphResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Lift_Start, { "ABELIFT.BAN", 22548, 135, 80, kAbeliftResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Lift_End, { "ABELIFT.BAN", 22572, 135, 80, kAbeliftResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Lift, { "ABELIFT.BAN", 22464, 135, 80, kAbeliftResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Lift_Up, { "ABELIFT.BAN", 22596, 135, 80, kAbeliftResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Lift_Down, { "ABELIFT.BAN", 22496, 135, 80, kAbeliftResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Abe_Death_Gas, { "ABEGAS.BAN", 28824, 135, 80, kAbegasResID, PalId::Default}, kNullAnimDetails },

    {AnimId::Mudokon_Idle, { "ABEBSIC1.BAN", 58888, 135, 80, kAbebsic1ResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Walk, { "ABEBSIC1.BAN", 58808, 135, 80, kAbebsic1ResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Turn_Around, { "ABEBSIC1.BAN", 59064, 135, 80, kAbebsic1ResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Talk_A, { "ABEBSIC1.BAN", 59028, 135, 80, kAbebsic1ResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Talk_B, { "ABEBSIC1.BAN", 58956, 135, 80, kAbebsic1ResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Talk_C, { "ABEBSIC1.BAN", 58992, 135, 80, kAbebsic1ResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Talk_D, { "ABEBSIC1.BAN", 58920, 135, 80, kAbebsic1ResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Unknown_A, { "ABEBSIC1.BAN", 58768, 135, 80, kAbebsic1ResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Unknown_B, { "ABEBSIC1.BAN", 58788, 135, 80, kAbebsic1ResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Unknown_C, { "ABEBSIC1.BAN", 58748, 135, 80, kAbebsic1ResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Lever_Pull, { "ABEPULL.BAN", 11396, 135, 80, kAbepullResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Chisel_Mining, { "MUDCHSL.BAN", 5276, 135, 80, kMudchslResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Unknown_E, { "MUDCHSL.BAN", 5308, 135, 80, kMudchslResID, PalId::Default}, kNullAnimDetails }, // might be scrubbing anim
    {AnimId::Mudokon_Unknown_F, { "MUDCHSL.BAN", 5320, 135, 80, kMudchslResID, PalId::Default}, kNullAnimDetails }, // ^
    {AnimId::Mudokon_Scrub_Cleaning, { "MUDSCRUB.BAN", 9388, 135, 80, kMudscrubResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Crouch, { "ABEBSIC.BAN", 270092, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Crouch_Turn_Around, { "ABEBSIC.BAN", 270428, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Stand_To_Crouch, { "ABEBSIC.BAN", 269876, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Crouch_To_Stand, { "ABEBSIC.BAN", 270060, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Unknown_G, { "ABEBSIC.BAN", 270120, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Unknown_H, { "ABEBSIC.BAN", 270268, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Run, { "ABEBSIC.BAN", 270748, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Unknown_I, { "ABEBSIC.BAN", 270668, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Unknown_J, { "ABEBSIC.BAN", 270820, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Run_End_A, { "ABEBSIC.BAN", 270860, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Run_End_B, { "ABEBSIC.BAN", 270328, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Unknown_K, { "ABEBSIC.BAN", 270408, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Sneak, { "ABEBSIC.BAN", 270508, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Sneak_Start, { "ABEBSIC.BAN", 270688, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Unknown_L, { "ABEBSIC.BAN", 270596, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Unknown_M, { "ABEBSIC.BAN", 270840, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Unknown_N, { "ABEBSIC.BAN", 270728, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Unknown_O, { "ABEBSIC.BAN", 270288, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Unknown_P, { "ABEBSIC.BAN", 270160, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Unknown_Q, { "ABEBSIC.BAN", 270308, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Run_Jump_Start, { "ABEBSIC.BAN", 270468, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Run_Jump, { "ABEBSIC.BAN", 269804, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Unknown_R, { "ABEBSIC.BAN", 270252, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Slap, { "ABEBSIC.BAN", 271152, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Hoist_Start, { "ABEBSIC.BAN", 269976, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Hoist, { "ABEBSIC.BAN", 270024, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Hoist_End, { "ABEBSIC.BAN", 269928, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Shrug_Start, { "ABEBSIC.BAN", 270180, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Shrug_End, { "ABEBSIC.BAN", 270616, 135, 80, kAbebasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Knocked_Back_Face_Down, { "ABEKNFD.BAN", 17240, 135, 80, kAbeknfdResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Knocked_Back_Face_Up, { "ABEKNBK.BAN", 49740, 135, 80, kAbeknbkResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Get_Up, { "ABEKNBK.BAN", 49800, 135, 80, kAbeknbkResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Fall, { "ABEEDGE.BAN", 32040, 135, 80, kAbeedgeResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Unknown_S, { "ABEEDGE.BAN", 32012, 135, 80, kAbeedgeResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Chant, { "ABEOMM.BAN", 9992, 135, 80, kAbeommResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Chant_End, { "ABEOMM.BAN", 10040, 135, 80, kAbeommResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Crouch_To_Duck, { "MUDWORK.BND", 5236, 135, 80, kMudoduckResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Duck, { "MUDWORK.BND", 5256, 135, 80, kMudoduckResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Duck_To_Crouch, { "MUDWORK.BND", 5280, 135, 80, kMudoduckResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Unknown_T, { "MUDBTLNK.BAN", 5328, 135, 80, kMudbtlnkResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Hit_Self, { "MUDIDLE.BAN", 9640, 135, 80, kMudidleResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Wheel_Start, { "ABEWORK.BAN", 11856, 135, 80, kAbeworkResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Wheel, { "ABEWORK.BAN", 11816, 135, 80, kAbeworkResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mudokon_Wheel_End, { "ABEWORK.BAN", 11888, 135, 80, kAbeworkResID, PalId::Default}, kNullAnimDetails },

    {AnimId::Paramite_Idle, { "PARAMITE.BND", 96696, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Idle_To_Move, { "PARAMITE.BND", 96676, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Move, { "PARAMITE.BND", 96548, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Run_A, { "PARAMITE.BND", 96612, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Turn_Around, { "PARAMITE.BND", 96792, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Run_B, { "PARAMITE.BND", 96728, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Unknown_A, { "PARAMITE.BND", 97164, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails }, // crashes the game when used
    {AnimId::Paramite_Unknown_B, { "PARAMITE.BND", 97172, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Unknown_C, { "PARAMITE.BND", 96828, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Unknown_D, { "PARAMITE.BND", 96868, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Unknown_E, { "PARAMITE.BND", 96848, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Unknown_F, { "PARAMITE.BND", 96888, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Jump_Up_Start, { "PARAMITE.BND", 96904, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Jump_Up, { "PARAMITE.BND", 96932, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Jump_Up_End, { "PARAMITE.BND", 96944, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Unknown_G, { "PARAMITE.BND", 96972, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Unknown_H, { "PARAMITE.BND", 97192, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Unknown_I, { "PARAMITE.BND", 97096, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Unknown_J, { "PARAMITE.BND", 97120, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Unknown_K, { "PARAMITE.BND", 97136, 137, 65u, kArjbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Talk_Start, { "PARAMITE.BND", 17032, 137, 65u, kArjpumpResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Scared, { "PARAMITE.BND", 17072, 137, 65u, kArjpumpResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Yell_A, { "PARAMITE.BND", 17088, 137, 65u, kArjpumpResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Talk, { "PARAMITE.BND", 17192, 137, 65u, kArjpumpResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Yell_B, { "PARAMITE.BND", 17120, 137, 65u, kArjpumpResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Talk_End, { "PARAMITE.BND", 17152, 137, 65u, kArjpumpResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Pounce, { "PARAMITE.BND", 19068, 137, 65u, kArjponceResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Web_Sling, { "PARAMITE.BND", 52312, 137, 65u, kArjclimbResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Climb_End_Down, { "PARAMITE.BND", 52344, 137, 65u, kArjclimbResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Climb_Idle, { "PARAMITE.BND", 52476, 137, 65u, kArjclimbResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Climb_Up, { "PARAMITE.BND", 52428, 137, 65u, kArjclimbResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Climb_Down, { "PARAMITE.BND", 52380, 137, 65u, kArjclimbResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Climb_Start_Down, { "PARAMITE.BND", 52548, 137, 65u, kArjclimbResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Climb_End_Up, { "PARAMITE.BND", 52588, 137, 65u, kArjclimbResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Eat, { "PARAMITE.BND", 15628, 137, 65u, kArjeatResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Fall_Death, { "PARAMITE.BND", 8108, 137, 65u, kArjfalrkResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Wasps, { "PARAMITE.BND", 9636, 137, 65u, kArjwaspResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Paramite_Attack, { "PARAMITE.BND", 10948, 137, 65u, kArjscrchResID, PalId::Default}, kNullAnimDetails },

    {AnimId::Scrab_Idle, { "SCRAB.BND", 224764, 156, 69, kArsbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Walk, { "SCRAB.BND", 224668, 156, 69, kArsbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Run, { "SCRAB.BND", 224796, 156, 69, kArsbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Turn_Around, { "SCRAB.BND", 224860, 156, 69, kArsbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Run_Stop, { "SCRAB.BND", 224916, 156, 69, kArsbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Landing_A, { "SCRAB.BND", 224964, 156, 69, kArsbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Jump, { "SCRAB.BND", 224988, 156, 69, kArsbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Landing_B, { "SCRAB.BND", 225028, 156, 69, kArsbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Unknown_A, { "SCRAB.BND", 225112, 156, 69, kArsbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Unknown_B, { "SCRAB.BND", 225052, 156, 69, kArsbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Unknown_C, { "SCRAB.BND", 225072, 156, 69, kArsbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Unknown_D, { "SCRAB.BND", 225092, 156, 69, kArsbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Unknown_E, { "SCRAB.BND", 225132, 156, 69, kArsbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Unknown_F, { "SCRAB.BND", 225168, 156, 69, kArsbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Unknown_G, { "SCRAB.BND", 225188, 156, 69, kArsbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Landing_C, { "SCRAB.BND", 225208, 156, 69, kArsbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Unknown_H, { "SCRAB.BND", 225280, 156, 69, kArsbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Dance, { "SCRAB.BND", 24480, 156, 69, kArsdanceResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Dead, { "SCRAB.BND", 1340, 156, 69, kArsdeadResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Unknown_I, { "SCRAB.BND", 11228, 156, 69, kArsgrwlResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Showl, { "SCRAB.BND", 17260, 156, 69, kArshowlResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Showl_Start, { "SCRAB.BND", 17328, 156, 69, kArshowlResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Roar, { "SCRAB.BND", 11532, 156, 69, kArsroarResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Whirl_Fight, { "SCRAB.BND", 31648, 156, 69, kArswhirlResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Whirl, { "SCRAB.BND", 31704, 156, 69, kArswhirlResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Chew, { "SCRAB.BND", 35180, 156, 69, kArschewResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Unknown_J, { "SCRAB.BND", 35248, 156, 69, kArschewResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Eat_Start, { "SCRAB.BND", 20840, 156, 69, kArseatResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Eat, { "SCRAB.BND", 20896, 156, 69, kArseatResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Unknown_K, { "SCRAB.BND", 8356, 156, 69, kArsprceResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Kick, { "SCRAB.BND", 14508, 156, 69, kArsskwrResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Scrab_Unknown_L, { "SCRAB.BND", 15600, 156, 69, kArscrshResID, PalId::Default}, kNullAnimDetails },

    {AnimId::Slig_Idle, { "SLIG.BND", 135512, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Walk_Start, { "SLIG.BND", 135804, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Walk, { "SLIG.BND", 135360, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Run_Start, { "SLIG.BND", 135824, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Run, { "SLIG.BND", 135440, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Turn_Around, { "SLIG.BND", 136088, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Shoot, { "SLIG.BND", 135544, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Run_Stop, { "SLIG.BND", 135696, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Run_Turn_Around, { "SLIG.BND", 135576, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Unknown_A, { "SLIG.BND", 135916, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Unknown_B, { "SLIG.BND", 135632, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Reload, { "SLIG.BND", 135652, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Idle_To_Shoot, { "SLIG.BND", 135768, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Shuffle, { "SLIG.BND", 135844, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Unknown_C, { "SLIG.BND", 135876, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Unknown_D, { "SLIG.BND", 135788, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Unknown_E, { "SLIG.BND", 135896, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Shoot_Step, { "SLIG.BND", 135936, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Talk_A, { "SLIG.BND", 136048, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Talk_B, { "SLIG.BND", 135976, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Talk_C, { "SLIG.BND", 136132, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Talk_D, { "SLIG.BND", 136012, 160, 68, kSlgbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Sleep, { "SLGSLEEP.BAN", 33552, 160, 68, kSlgsleepResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Wake_Up, { "SLGSLEEP.BAN", 33448, 160, 68, kSlgsleepResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Knocked_Down, { "SLIG.BND", 33184, 160, 68, kSlgknbkResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Get_Up, { "SLIG.BND", 33228, 160, 68, kSlgknbkResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Possessed, { "SLIG.BND", 33348, 160, 68, kSlgknbkResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Fall, { "SLGEDGE.BAN", 30560, 160, 68, kSlgedgeResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Fall_Start, { "SLGEDGE.BAN", 30592, 160, 68, kSlgedgeResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Fall_End, { "SLGEDGE.BAN", 30628, 160, 68, kSlgedgeResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Fall_Death_A, { "SLGSMASH.BAN", 9204, 160, 68, kSlgsmashResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Shoot_Z, { "SLIGZ.BND", 9208, 160, 68, kSlgzshotResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Shoot_Z_End, { "SLIGZ.BND", 9260, 160, 68, kSlgzshotResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Fall_Death_B, { "SLGKNFD.BAN", 13016, 160, 68, kSlgknfdResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Lever, { "SLGLEVER.BAN", 12612, 160, 68, kSlgleverResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Lift_Start_A, { "SLGLIFT.BAN", 23048, 160, 68, kSlgliftResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Lift_Start_B, { "SLGLIFT.BAN", 23072, 160, 68, kSlgliftResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Lift_Idle, { "SLGLIFT.BAN", 23200, 160, 68, kSlgliftResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Lift_Move_A, { "SLGLIFT.BAN", 23148, 160, 68, kSlgliftResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Lift_Move_B, { "SLGLIFT.BAN", 23096, 160, 68, kSlgliftResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slig_Beat, { "SLGBEAT.BAN", 12660, 160, 68, kSlgbeatResID, PalId::Default}, kNullAnimDetails },

    {AnimId::Slog_Idle_A, { "SLOG.BND", 96464, 121, 57, kDogbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Walk, { "SLOG.BND", 96344, 121, 57, kDogbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Run, { "SLOG.BND", 96424, 121, 57, kDogbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Turn_Around, { "SLOG.BND", 96764, 121, 57, kDogbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Falling, { "SLOG.BND", 96692, 121, 57, kDogbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Bark, { "SLOG.BND", 96496, 121, 57, kDogbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Run_Stop, { "SLOG.BND", 96532, 121, 57, kDogbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Run_Turn_Around, { "SLOG.BND", 96580, 121, 57, kDogbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Unknown_A, { "SLOG.BND", 96640, 121, 57, kDogbasicResID, PalId::Default}, kNullAnimDetails }, // Very short animation
    {AnimId::Slog_Unknown_B, { "SLOG.BND", 96660, 121, 57, kDogbasicResID, PalId::Default}, kNullAnimDetails }, // ^
    {AnimId::Slog_Unknown_C, { "SLOG.BND", 96876, 121, 57, kDogbasicResID, PalId::Default}, kNullAnimDetails }, // ^
    {AnimId::Slog_Unknown_D, { "SLOG.BND", 96716, 121, 57, kDogbasicResID, PalId::Default}, kNullAnimDetails }, // Just a still frame
    {AnimId::Slog_Bark_Short_A, { "SLOG.BND", 96728, 121, 57, kDogbasicResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Unknown_E, { "SLOG.BND", 96752, 121, 57, kDogbasicResID, PalId::Default}, kNullAnimDetails }, // Another still frame
    {AnimId::Slog_Bark_Short_B, { "SLOG.BND", 15068, 121, 57, kDogrstnResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Sleep_A, { "SLOG.BND", 15108, 121, 57, kDogrstnResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Sleep_B, { "SLOG.BND", 15156, 121, 57, kDogrstnResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Sleep_C, { "SLOG.BND", 15132, 121, 57, kDogrstnResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Lunge, { "SLOG.BND", 38904, 121, 57, kDogattkResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Jump_Up, { "SLOG.BND", 38960, 121, 57, kDogattkResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Eat, { "SLOG.BND", 39064, 121, 57, kDogattkResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Die, { "SLOG.BND", 12412, 121, 57, kDogknfdResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Scratch, { "SLOG.BND", 12724, 121, 57, kDogidleResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slog_Idle_B, { "SLOG.BND", 12812, 121, 57, kDogidleResID, PalId::Default}, kNullAnimDetails },

    {AnimId::Slurg_Move, { "SLURG.BAN", 2708, 46, 15, kSlurgResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slurg_Burst, { "SLURG.BAN", 2808, 46, 15, kSlurgResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slurg_Turn_Around, { "SLURG.BAN", 2740, 46, 15, kSlurgResID, PalId::Default}, kNullAnimDetails },

    {AnimId::Bone, { "BTHROW.BND", 456, 15, 9, kBoneResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Bone_Bag_A, { "BONEBAG.BAN", 8748, 64, 60, kBoneBagResID_590, PalId::Default}, kNullAnimDetails },
    {AnimId::Bone_Bag_B, { "BONEBAG.BAN", 8708, 64, 60, kBoneBagResID_590, PalId::Default}, kNullAnimDetails },
    {AnimId::Bone_Bag_C, { "BONEBAG.BAN", 8788, 64, 60, kBoneBagResID_590, PalId::Default}, kNullAnimDetails },
    {AnimId::Bone_Saw_Horizontal_Off, { "DRILL.BAN", 6736, 65, 33, kDrillResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Bone_Saw_Horizontal_On, { "DRILL.BAN", 6712, 65, 33, kDrillResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Bone_Saw_Vertical_Off, { "DRILL.BAN", 6676, 65, 33, kDrillResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Bone_Saw_Vertical_On, { "DRILL.BAN", 6688, 65, 33, kDrillResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Bullet_Casing, { "SHELL.BAN", 320, 5, 5u, kShellResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Barracks_Closed, { "DOOR.BAN", 5652, 56, 62, kF2p3dorResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Barracks_Closing, { "DOOR.BAN", 5664, 56, 62, kF2p3dorResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Bonewerkz_Closed, { "DOOR.BAN", 6304, 59, 58, kF2p3dorResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Bonewerkz_Closing, { "DOOR.BAN", 6316, 59, 58, kF2p3dorResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Brewery_Closed, { "DOOR.BAN", 6224, 54, 71, kF2p3dorResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Brewery_Closing, { "DOOR.BAN", 6236, 54, 71, kF2p3dorResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Feeco_Closed, { "DOOR.BAN", 7636, 62, 70, kF2p3dorResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Feeco_Closing, { "DOOR.BAN", 7648, 62, 70, kF2p3dorResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Flame, { "FIRE.BAN", 5156, 22, 21u, kHubFireResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Flame_Glow, { "FIRE.BAN", 1400, 52, 30, kGlowResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Flame_Spark, { "FIRE.BAN", 1672, 39, 21, kOmmflareResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Lock_Idle, { "DOORLOCK.BAN", 1624, 87, 14, kDoorLockResID_374, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Lock_Open, { "DOORLOCK.BAN", 1608, 87, 14, kDoorLockResID_374, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Mines_Closed, { "DOOR.BAN", 8692, 77, 69, kF2p3dorResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Mines_Closing, { "DOOR.BAN", 8704, 77, 69, kF2p3dorResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Temple_Closed, { "DOOR.BAN", 5436, 67, 62, kF2p3dorResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Temple_Closing, { "DOOR.BAN", 5448, 67, 62, kF2p3dorResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Train_Closed, { "DOOR.BAN", 4740, 44, 56u, kDoorResID_2013, PalId::Default}, kNullAnimDetails },
    {AnimId::Door_Train_Closing, { "DOOR.BAN", 4752, 44, 56u, kDoorResID_2013, PalId::Default}, kNullAnimDetails },
    {AnimId::Dove_Idle, { "DOVE.BAN", 5580, 41, 20, 60, PalId::Default}, kNullAnimDetails },
    {AnimId::Dove_Flying, { "DOVE.BAN", 5516, 41, 20, 60, PalId::Default}, kNullAnimDetails },
    {AnimId::Electric_Wall, { "ELECWALL.BAN", 15384, 50, 80, kElecwallResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Explosion, { "EXPLO2.BAN", 51156, 202, 91, kExplo2ResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Explosion_Mine, { "EXPLODE.BND", 51588, 214, 0x31u, kBgexpldResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Explosion_Small, { "SMEXP.BAN", 14108, 99, 46, kSmallExplo2ResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Falling_Crate_A, { "FALLBONZ.BAN", 8076, 86, 47, kF2rockResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Falling_Crate_B, { "FALLBONZ.BAN", 8100, 86, 47, kF2rockResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Falling_Rock_A, { "FALLROCK.BAN", 4232, 64, 28, kF2rockResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Falling_Rock_B, { "FALLROCK.BAN", 4256, 64, 28, kF2rockResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Fart, { "EVILFART.BAN", 3532, 61, 39, kEvilFartResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Foot_Switch_Bonewerkz_Idle, { "BWTRIGGR.BAN", 548, 46, 11, kTriggerResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Foot_Switch_Bonewerkz_Pressed, { "BWTRIGGR.BAN", 568, 46, 11, kTriggerResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Foot_Switch_Industrial_Idle, { "TRIGGER.BAN", 568, 45, 11, kTriggerResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Foot_Switch_Industrial_Pressed, { "TRIGGER.BAN", 588, 45, 11, kTriggerResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Foot_Switch_Vault_Idle, { "VLTTRIGR.BAN", 972, 72, 18, kTriggerResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Foot_Switch_Vault_Pressed, { "VLTTRIGR.BAN", 992, 72, 18, kTriggerResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Grenade, { "GRENADE.BAN", 1252, 17, 11, kGrenadeResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Grenade_Machine_Button_Off, { "GMACHINE.BND1", 1736, 26, 17u, kR1buttonResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Grenade_Machine_Button_On, { "GMACHINE.BND1", 1708, 26, 17u, kR1buttonResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Grenade_Machine_Nozzle, { "GMACHINE.BND1", 3700, 67, 36u, kR1bpipeResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Grenade_Machine_Nozzle_Drop_Grenade, { "GMACHINE.BND1", 3672, 67, 36u, kR1bpipeResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Lift_Rope, { "ROPES.BAN", 748, 9, 16, kRopesResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Mine, { "MINE.BND", 784, 38, 0, kLandmineResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Motion_Detector_Flare, { "MFLARE.BAN", 1736, 55, 22, kMflareResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Motion_Detector_Laser, { "MOTION.BAN", 23280, 37, 60, kMotionResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Moving_Bomb, { "MOVEBOMB.BAN", 17548, 76, 30, kMovebombResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Rock, { "RTHROW.BND", 488, 17, 9, kAberockResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Rock_Sack_A, { "ROCKBAG.BAN", 29748, 71, 60u, kP2c2bagResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Rock_Sack_B, { "ROCKBAG.BAN", 29772, 71, 60u, kP2c2bagResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Rock_Sack_Hit, { "ROCKBAG.BAN", 29700, 71, 60u, kP2c2bagResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Security_Door_Idle, { "SECDOOR.BAN", 1512, 70, 19u, kR1sdosResID_6027, PalId::Default}, kNullAnimDetails },
    {AnimId::Security_Door_Speak, { "SECDOOR.BAN", 1528, 70, 19u, kR1sdosResID_6027, PalId::Default}, kNullAnimDetails },
    {AnimId::Security_Orb, { "MAIMORB.BAN", 2228, 53, 28u, kMaimGameResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slam_Door_Industrial_Closed, { "SLAM.BAN", 2688, 29, 68, kSlamResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slam_Door_Industrial_Closing, { "SLAM.BAN", 2672, 29, 68, kSlamResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slam_Door_Industrial_Opening, { "SLAM.BAN", 2640, 29, 68, kSlamResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slam_Door_Vault_Closed, { "SLAMVLTS.BAN", 2384, 32, 68, kSlamResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slam_Door_Vault_Closing, { "SLAMVLTS.BAN", 2368, 32, 68, kSlamResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slam_Door_Vault_Opening, { "SLAMVLTS.BAN", 2396, 32, 68, kSlamResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Slap_Lock_Idle_A, { "GHOSTTRP.BAN", 7068, 58, 44, kGhostTrpResID_1053, PalId::Default}, kNullAnimDetails },
    {AnimId::Slap_Lock_Idle_B, { "GHOSTTRP.BAN", 7056, 58, 44, kGhostTrpResID_1053, PalId::Default}, kNullAnimDetails },
    {AnimId::Slap_Lock_Shake, { "GHOSTTRP.BAN", 6976, 58, 44, kGhostTrpResID_1053, PalId::Default}, kNullAnimDetails },
    {AnimId::Sparks, { "SPARKS.BAN", 808, 19, 11, kSparksResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Status_Light_Green, { "STATUSLT.BAN", 240, 14, 9u, kStatusLightResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Status_Light_Red, { "STATUSLT.BAN", 252, 14, 9u, kStatusLightResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Switch_Idle, { "SWITCH1.BAN", 5696, 66, 40, kSwitchResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Switch_Pull_Left_A, { "SWITCH1.BAN", 5708, 66, 40, kSwitchResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Switch_Pull_Left_B, { "SWITCH1.BAN", 5760, 66, 40, kSwitchResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Switch_Pull_Right_A, { "SWITCH1.BAN", 5796, 66, 40, kSwitchResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Switch_Pull_Right_B, { "SWITCH1.BAN", 5848, 66, 40, kSwitchResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Timed_Mine_Armed, { "BOMB.BND", 848, 35, 0x11u, kBombResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Timed_Mine_Idle, { "BOMB.BND", 836, 35, 0x11u, kBombResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Tortured_Modukon, { "MUDTORT.BAN", 20892, 101, 0x44u, kTorturedMud, PalId::Default}, kNullAnimDetails },
    {AnimId::Tortured_Modukon_Released, { "MUDTORT.BAN", 20864, 101, 0x44u, kTorturedMud, PalId::Default}, kNullAnimDetails },
    {AnimId::Tortured_Modukon_Zap, { "MUDTORT.BAN", 21000, 101, 0x44u, kTorturedMud, PalId::Default}, kNullAnimDetails },
    {AnimId::Trap_Door_Closed, { "TRAPDOOR.BAN", 4788, 72, 41, kP6c1trapResID, PalId::Default}, kNullAnimDetails },         // These still need implementation somehow under line 24 of TrapDoor.cpp
    {AnimId::Trap_Door_Closing, { "TRAPDOOR.BAN", 4812, 72, 41, kP6c1trapResID, PalId::Default}, kNullAnimDetails },        // ^
    {AnimId::Trap_Door_Open, { "TRAPDOOR.BAN", 4800, 72, 41, kP6c1trapResID, PalId::Default}, kNullAnimDetails },           // ^
    {AnimId::Trap_Door_Opening, { "TRAPDOOR.BAN", 4840, 72, 41, kP6c1trapResID, PalId::Default}, kNullAnimDetails },        // ^
    {AnimId::Trap_Door_Tribal_Closed, { "VLTSTRAP.BAN", 5328, 72, 41, kP6c1trapResID, PalId::Default}, kNullAnimDetails },  // ^
    {AnimId::Trap_Door_Tribal_Closing, { "VLTSTRAP.BAN", 5368, 72, 41, kP6c1trapResID, PalId::Default}, kNullAnimDetails }, // ^
    {AnimId::Trap_Door_Tribal_Open, { "VLTSTRAP.BAN", 5316, 72, 41, kP6c1trapResID, PalId::Default}, kNullAnimDetails },    // ^
    {AnimId::Trap_Door_Tribal_Opening, { "VLTSTRAP.BAN", 5340, 72, 41, kP6c1trapResID, PalId::Default}, kNullAnimDetails }, // ^
    {AnimId::UXB_Active, { "UXB.BND", 8048, 59, 19, kTbombResID, PalId::Default}, kNullAnimDetails },
    {AnimId::UXB_Toggle, { "UXB.BND", 8120, 59, 19, kTbombResID, PalId::Default}, kNullAnimDetails },
    {AnimId::UXB_Disabled, { "UXB.BND", 0x2000, 59, 19, kTbombResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Well_Leaf, { "WELLLEAF.BAN", 476, 16, 11, kWellLeafResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Work_Wheel_Idle, { "WORKWHEL.BAN", 2716, 49, 24, kWorkwhelResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Work_Wheel_Turning, { "WORKWHEL.BAN", 2728, 49, 24, kWorkwhelResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Zap_Line_Blue, { "SPLINE.BAN", 276, 14, 9, kSplineResID, PalId::Default}, kNullAnimDetails },
    {AnimId::Zap_Line_Red, { "SPLINE.BAN", 288, 14, 9, kSplineResID, PalId::Default}, kNullAnimDetails },

    // Background animations
    {AnimId::BG_Brewery_Barrel_Anim, { "BRP02C10.CAM", 42112, 130, 55, 1206, PalId::Default}, kNullAnimDetails },
    {AnimId::BG_Mine_Fan, { "MINEFAN.BAN", 15632, 113, 55, 1201, PalId::Default}, kNullAnimDetails },
    {AnimId::BG_Feeco_Small_Fan, { "FDP01C01.CAM", 4208, 57, 28, 1202, PalId::Default}, kNullAnimDetails },
    {AnimId::BG_Heat_Extractor_Fan, { "MIP04C18.CAM", 7104, 89, 24, 1204, PalId::Default}, kNullAnimDetails },

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    {AnimId::Anim_Tester, { "SPLINE.BAN", 288, 14, 9, kSplineResID, PalId::Default}, kNullAnimDetails },
    ////////////////////////////////////////////////////////////////////////////////////////////////////
};

static const PalRecord PalRec(bool isAe, PalId toFind)
{
    for (const CombinedPalRecord& pal : kPalRecords)
    {
        if (pal.mId == toFind)
        {
            const PalDetails& data = isAe ? pal.mAEData : pal.mAOData;
            return PalRecord{pal.mId, data.mBanName, data.mResourceId };
        }
    }
    ALIVE_FATAL("Missing pal entry");
}


const PalRecord PalRec(PalId toFind)
{
    return PalRec(true, toFind);
}

static const AnimRecord AnimRec(bool isAe, AnimId toFind)
{
    for (const CombinedAnimRecord& anim : kAnimRecords)
    {
        if (anim.mId == toFind)
        {
            const AnimDetails& data = isAe ? anim.mAEData : anim.mAOData;
            return AnimRecord{ anim.mId, data.mBanName, data.mFrameTableOffset, data.mMaxW, data.mMaxH, data.mResourceId, data.mPalOverride };
        }
    }
    ALIVE_FATAL("Missing animation entry");
}

const AnimRecord AnimRec(AnimId toFind)
{
    return AnimRec(true, toFind);
}

namespace AO
{
    const PalRecord PalRec(PalId toFind)
    {
        return PalRec(false, toFind);
    }

    const AnimRecord AnimRec(AnimId toFind)
    {
        return AnimRec(false, toFind);
    }
}
