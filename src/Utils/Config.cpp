#include "Config.h"

#include <sol/sol.hpp>

namespace gamescope::Config
{
    class CScriptState
    {
    public:
        CScriptState()
        {
            m_State.open_libraries();

            m_GamescopeTable = m_State.create_named_table( "gamescope" );
        }

        const sol::state *operator->() const { return &m_State; }
              sol::state *operator->()       { return &m_State; }

        const sol::table &Gamescope() const { return m_GamescopeTable; }
              sol::table &Gamescope()       { return m_GamescopeTable; }

        static CScriptState &Get();
    private:
        sol::state m_State;
        sol::table m_GamescopeTable;
    };

    #define DECLARE_SCRIPTDESC( x ) \
        static sol::usertype<x> s_ScriptType;
    #define START_SCRIPTDESC( type, lua_name ) \
        sol::usertype<type> type::s_ScriptType = CScriptState::Get().Gamescope().new_usertype<type>( lua_name,
    #define END_SCRIPTDESC() );

    CScriptState &CScriptState::Get()
    {
        static CScriptState s_State;
        return s_State;
    }

    struct DisplayHDR_t
    {
        DECLARE_SCRIPTDESC( DisplayHDR_t );

        bool bSupported = false;
        bool bForceEnabled = false;
        uint32_t eotf = 0;
        float flMaxContentLightLevel = 500.0f;
        float flMaxFrameAverageLuminance = 400.0f;
        float flMinContentLightLevel = 0.0f;

    };
    START_SCRIPTDESC( DisplayHDR_t, "display_hdr" )
        "supported", &DisplayHDR_t::bSupported,
        "force_enabled", &DisplayHDR_t::bForceEnabled,
        "eotf", &DisplayHDR_t::eotf,
        "max_content_light_level", &DisplayHDR_t::flMaxContentLightLevel,
        "max_frame_average_luminance", &DisplayHDR_t::flMaxFrameAverageLuminance,
        "min_content_light_level", &DisplayHDR_t::flMinContentLightLevel
    END_SCRIPTDESC();

    struct KnownDisplay_t
    {
        DECLARE_SCRIPTDESC( KnownDisplay_t );

        std::string sId = "unknown_display";
        std::string sPrettyName = "Unknown Display";
        DisplayHDR_t HDR{};
        std::vector<uint32_t> uDynamicRefreshRates;
        sol::function fnMatches;
    };
    START_SCRIPTDESC( KnownDisplay_t, "known_display" )
        "id", &KnownDisplay_t::sId,
        "pretty_name", &KnownDisplay_t::sPrettyName,
        "hdr", &KnownDisplay_t::HDR,
        "dynamic_refresh_rates", &KnownDisplay_t::uDynamicRefreshRates,
        "matches", &KnownDisplay_t::fnMatches
    END_SCRIPTDESC();

    void TestConfig()
    {
        CScriptState::Get()->script( R"(
            local test = gamescope.known_display.new()
            print( test.hdr.max_content_light_level )
        )" );
    }

}

void TestConfig()
{
    gamescope::Config::TestConfig();
}
