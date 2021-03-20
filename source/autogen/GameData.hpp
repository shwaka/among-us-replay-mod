#pragma once

#include <autogen/InnerNet/InnerNetObject.hpp>
#include <autogen/System/Collections/Generic/List.hpp>
#include <autogen/System/String.hpp>

struct PlayerControl;

// KIOIFEIADMB in 2020.10.8i
// BAGGGBBOHOH in 2020.10.22s
// BOMCDPPPECM in 2020.11.4s
// FLIHHNFFPAO in 2020.11.17s
// EGLJNOMOGNP in 2020.12.9s
// GameData in 2021.3.5s
struct GameData : InnerNet::InnerNetObject {
    // GameData.CBOMPDNBEIF in 2020.9.22
    // KIOIFEIADMB.FAECJOFPICI in 2020.10.8i
    // BAGGGBBOHOH.ALLADIFCEHO in 2020.10.22s
    // BOMCDPPPECM.IDFPHCCPCJC in 2020.11.4s
    // FLIHHNFFPAO.CJOIAHBNANN in 2020.11.17s
    // EGLJNOMOGNP.CAAACHLJJNE in 2020.12.9s
    // GameData.HKFJOIBBOBD in 2021.3.5s
    struct TaskInfo : ::Object {
        // [marker] is PlayerInfo.Tasks
        std::uint32_t Id;
        std::uint8_t TypeId;
        bool Complete;
    };
    CHECK_TYPE(TaskInfo, 0x8);

    // GameData.IHEKEPMDGIJ in 2020.9.22
    // KIOIFEIADMB.IOHELPMOCLM in 2020.10.8i
    // BAGGGBBOHOH.FGMBFCIIILC in 2020.10.22s
    // BOMCDPPPECM.FDGKOOFKODI in 2020.11.4s
    // FLIHHNFFPAO.LBGGNMFGAOO in 2020.11.17s
    // EGLJNOMOGNP.DCJMABDDJCF in 2020.12.9s
    // GameData.GOOIGLGKMCE in 2021.3.5s
    struct PlayerInfo : ::Object {
        // [marker] is GameData.AllPlayers
        std::uint8_t PlayerId;
        System::String* PlayerName;
        std::uint8_t ColorId;
        std::uint32_t HatId;
        std::uint32_t PetId;
        std::uint32_t SkinId;
        bool Disconnected;
        System::Collections::Generic::List<TaskInfo>* Tasks;
        bool IsImpostor;
        bool IsDead;
        PlayerControl *_object;
    };
    CHECK_TYPE(PlayerInfo, 0x28);

    System::Collections::Generic::List<PlayerInfo>* AllPlayers; // [marker]
    std::int32_t TotalTasks;
    std::int32_t CompletedTasks;

    struct StaticFields {
        GameData* instance;
    };

    static Class<GameData>* get_class() {
        switch (mod_info::get_game_version()) {
            case game_version::v2020_6_9s:   return Class<GameData>::find("GameData");
            case game_version::v2020_9_22s:  return Class<GameData>::find("GameData");
            case game_version::v2020_10_8i:  return Class<GameData>::find("KIOIFEIADMB");
            case game_version::v2020_10_22s: return Class<GameData>::find("BAGGGBBOHOH");
            case game_version::v2020_11_4s:  return Class<GameData>::find("BOMCDPPPECM");
            case game_version::v2020_11_17s: return Class<GameData>::find("FLIHHNFFPAO");
            case game_version::v2020_12_9s:  return Class<GameData>::find("EGLJNOMOGNP");
            case game_version::v2021_3_5s:  return Class<GameData>::find("GameData");
        }
        return nullptr;
    }

    static GameData* instance() {
        return get_class()->statics()->instance;
    }
};
CHECK_TYPE(GameData, 0x28);
