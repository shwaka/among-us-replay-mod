#include "mod_info.hpp"

#include <autogen/UnityEngine/Application.hpp>

#include <fmt/format.h>

#include <map>

namespace mod_info {

game_version get_game_version() {
    static const auto current_version = []{
        static const std::map<std::string_view, game_version> mapping {
            { "2020.6.9",   game_version::v2020_6_9s   },
            { "2020.9.22",  game_version::v2020_9_22s  },
            { "2020.10.8",  game_version::v2020_10_8i  },
            { "2020.10.22", game_version::v2020_10_22s },
            { "2020.11.4",  game_version::v2020_11_4s  },
            { "2020.11.17", game_version::v2020_11_17s },
            { "2020.12.9",  game_version::v2020_12_9s  },
            { "2021.3.5",   game_version::v2021_3_5s   }
        };

        auto app_version = UnityEngine::Application::get_version();
        auto it = mapping.find(app_version);
        if (it == mapping.end()) {
            throw std::runtime_error(fmt::format("unknown game version: v{}", app_version));
        }

        return it->second;
    }();

    return current_version;
}

} // namespace mod_info
