#include "PathDataExtensions.hpp"
#include "PathData.hpp"
#include "LvlArchive.hpp"
#include "LCDScreen.hpp"
#include "HintFly.hpp"
#include "ResourceManager.hpp"
#include "Collisions.hpp"
#include "../AliveLibCommon/PathDataExtensionsTypes.hpp"

namespace AO {

static s32 sTotalMuds = 99;
static s32 sBadEndingMuds = 75;
static s32 sGoodEndingMuds = 50;

s32 Path_GetTotalMuds()
{
    return sTotalMuds;
}

s32 Path_BadEndingMuds()
{
    return sBadEndingMuds;
}

s32 Path_GoodEndingMuds()
{
    return sGoodEndingMuds;
}

static u8* sPathExtData[static_cast<u32>(LevelIds::eDesertEscape) + 1] = {};

EXPORT s32 sub_402560();

template<typename T>
static void SetAndLog(const char_type* propertyName, T& dst, T newVal)
{
    if (dst != newVal)
    {
        LOG_INFO("Update " << propertyName << " from " << static_cast<s32>(dst) << " to " << static_cast<s32>(newVal));
        dst = newVal;
    }
}

void Path_Set_NewData_FromLvls()
{
    for (s32 lvlIdx = 0; lvlIdx < Path_Get_Paths_Count(); lvlIdx++)
    {
        // Open the LVL
        LvlArchive archive;
        const char_type* pCdLvlName = CdLvlName(static_cast<LevelIds>(lvlIdx));
        if (pCdLvlName)
        {
            archive.OpenArchive(pCdLvlName, 0); // can't check if it worked in AO, nice
            // Check for hard coded data replacement
            LvlFileRecord* pRec = archive.Find_File_Record_41BED0(Path_Get_BndName(static_cast<LevelIds>(lvlIdx)));
            if (pRec)
            {
                // Load the file data
                delete[] sPathExtData[lvlIdx];

                u8* pTmp = new u8[pRec->field_10_num_sectors * 2048];
                archive.Read_File_41BE40(pRec, pTmp);

                // Keep the loaded data in scope for however long the game is running
                sPathExtData[lvlIdx] = pTmp;

                // Iterate the chunks
                ResourceManager::Header* pHeader = reinterpret_cast<ResourceManager::Header*>(pTmp);
                while (pHeader->field_8_type != ResourceManager::Resource_End)
                {
                    if (pHeader->field_8_type == Resource_Pxtd)
                    {
                        auto pChunkData = reinterpret_cast<u8*>(&pHeader[1]);
                        auto pExt = reinterpret_cast<const PerPathExtension*>(pChunkData);

                        LOG_INFO("Applying " << pExt->mBlyName);

                        pChunkData += sizeof(PerPathExtension);

                        // Apply led messages
                        auto pLedMsgs = reinterpret_cast<StringTable*>(pChunkData);
                        pChunkData = StringTable::MakeTable(pLedMsgs);
                        SetLcdMessagesForLvl(*pLedMsgs, static_cast<LevelIds>(lvlIdx), pExt->mPathId);

                        // Apply hint fly messages
                        auto pHintFlyMsgs = reinterpret_cast<StringTable*>(pChunkData);
                        pChunkData = StringTable::MakeTable(pHintFlyMsgs);
                        SetHintFlyMessagesForLvl(*pHintFlyMsgs, static_cast<LevelIds>(lvlIdx), pExt->mPathId);

                        // Apply the data
                        PathRoot& rPath = *Path_Get_PathRoot(lvlIdx);
                        rPath.field_0_pBlyArrayPtr[pExt->mPathId].field_0_blyName = pExt->mBlyName;

                        PathBlyRec& rBlyRec = rPath.field_0_pBlyArrayPtr[pExt->mPathId];
                        PathData& rPathData = *rBlyRec.field_4_pPathData;

                        rPathData.field_0 = sub_402560;
                        rPathData.field_4_bLeft = 0;
                        rPathData.field_6_bRight = 0;
                        SetAndLog("top", rPathData.field_8_bTop, static_cast<s16>(pExt->mXSize * pExt->mGridWidth));
                        SetAndLog("bottom",rPathData.field_A_bBottom, static_cast<s16>(pExt->mYSize * pExt->mGridHeight));

                        SetAndLog("grid width", rPathData.field_C_grid_width, static_cast<s16>(pExt->mGridWidth));
                        SetAndLog("grid height", rPathData.field_E_grid_height, static_cast<s16>(pExt->mGridHeight));
   
                        SetAndLog("field_10", rPathData.field_10, static_cast<s16>(pExt->mGridWidth));
                        SetAndLog("field_12", rPathData.field_12, static_cast<s16>(pExt->mGridHeight));

                        SetAndLog<s32>("object offset", rPathData.field_14_object_offset, pExt->mObjectOffset);
                        SetAndLog<s32>("index table offset", rPathData.field_18_object_index_table_offset, pExt->mIndexTableOffset);

                        rPathData.field_1C_object_funcs = kObjectFactory;

                        rBlyRec.field_8_pCollisionData = &GetCollisions(lvlIdx)[pExt->mPathId];

                        CollisionInfo& rColInfo = *rBlyRec.field_8_pCollisionData;
                        rColInfo.field_0_fn_ptr = Collisions::Factory_40CEC0;
                        rColInfo.field_4_left = 0;
                        rColInfo.field_6_right = 0;
                        SetAndLog("top", rColInfo.field_8_top, static_cast<s16>(pExt->mXSize * pExt->mGridWidth));
                        SetAndLog("bottom",rColInfo.field_A_bottom, static_cast<s16>(pExt->mYSize * pExt->mGridHeight));
                        SetAndLog("collision offset",rColInfo.field_C_collision_offset, pExt->mCollisionOffset);
                        SetAndLog("num collision items",rColInfo.field_10_num_collision_items, pExt->mNumCollisionLines);
                        SetAndLog<u32>("grid width",rColInfo.field_14_grid_width, pExt->mGridWidth);
                        SetAndLog<u32>("grid height",rColInfo.field_18_grid_height, pExt->mGridHeight);

                        if (pExt->mTotalMuds != 0)
                        {
                            SetAndLog("sTotalMuds", sTotalMuds, pExt->mTotalMuds);
                        }

                        if (pExt->mBadEndingMuds != 0)
                        {
                            SetAndLog("sBadEndingMuds", sBadEndingMuds, pExt->mBadEndingMuds);
                        }

                        if (pExt->mGoodEndingMuds)
                        {
                            SetAndLog("sGoodEndingMuds", sGoodEndingMuds, pExt->mGoodEndingMuds);
                        }
                    }

                    // To the next chunk
                    pHeader = reinterpret_cast<ResourceManager::Header*>(reinterpret_cast<u8*>(pHeader) + pHeader->field_0_size);
                }
            }
            archive.Free_41BEB0();
        }
    }
}
} // namespace AO
