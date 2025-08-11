#define _CRT_SECURE_NO_WARNINGS 1
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <memory>

#include "uevr/Plugin.hpp"

using namespace uevr;

#define PLUGIN_LOG_ONCE(...)               \
    static bool _logged_ = false;          \
    if (!_logged_)                         \
    {                                      \
        _logged_ = true;                   \
        API::get()->log_info(__VA_ARGS__); \
    }

class RemapPlugin : public uevr::Plugin
{
public:
    const UEVR_PluginInitializeParam *m_Param;
    const UEVR_VRData *m_VR;

    RemapPlugin() = default;

    void on_initialize() override
    {

        // This shows how to get to the API functions.
        m_Param = API::get()->param();
        m_VR = m_Param->vr;

        API::get()->log_info("UEVR Initializing...");
    }

    //*******************************************************************************************
    // This is the controller input routine. Everything happens here.
    //*******************************************************************************************
    void on_xinput_get_state(uint32_t *retval, uint32_t user_index, XINPUT_STATE *state)
    {

        // See branches `dpad` and `keyboard` for implementations.
    }
};
// Actually creates the plugin. Very important that this global is created.
// The fact that it's using std::unique_ptr is not important, as long as the constructor is called in some way.
std::unique_ptr<RemapPlugin> g_plugin{new RemapPlugin()};
