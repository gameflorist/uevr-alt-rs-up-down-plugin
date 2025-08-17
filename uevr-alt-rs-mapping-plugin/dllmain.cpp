#define _CRT_SECURE_NO_WARNINGS 1
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <memory>

#include "uevr/Plugin.hpp"

#define KEYDOWN false
#define KEYUP true
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

    void send_key(WORD key, bool key_up)
    {
        INPUT input;
        ZeroMemory(&input, sizeof(INPUT));
        input.type = INPUT_KEYBOARD;
        input.ki.wVk = key;
        if (key_up)
            input.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input, sizeof(INPUT));
    }

    //*******************************************************************************************
    // This is the controller input routine. Everything happens here.
    //*******************************************************************************************
    void on_xinput_get_state(uint32_t *retval, uint32_t user_index, XINPUT_STATE *state)
    {

        if (state == NULL)
            return;
        if (!m_VR->is_using_controllers())
            return; // If not using controllers, none of this applies.

        static bool UpKeyDown = false;
        static bool DownKeyDown = false;

        // Right stick down
        if (state->Gamepad.sThumbRY <= -25000)
        {
            if (DownKeyDown == false)
            {
                send_key('D', KEYDOWN);
                DownKeyDown = true;
            }
        }
        else if (DownKeyDown == true)
        {
            send_key('D', KEYUP);
            DownKeyDown = false;
        }

        // Right stick up
        if (state->Gamepad.sThumbRY >= 25000)
        {
            if (UpKeyDown == false)
            {
                send_key('U', KEYDOWN);
                UpKeyDown = true;
            }
        }
        else if (UpKeyDown == true)
        {
            send_key('U', KEYUP);
            UpKeyDown = false;
        }

        // Right stick Y-axis should always be 0 for the game.
        state->Gamepad.sThumbRY = 0;
    }
};
// Actually creates the plugin. Very important that this global is created.
// The fact that it's using std::unique_ptr is not important, as long as the constructor is called in some way.
std::unique_ptr<RemapPlugin> g_plugin{new RemapPlugin()};
