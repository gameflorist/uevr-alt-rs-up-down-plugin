# UEVR Plugin providing alternative `RightStick` up/down mappings

In UEVR the `RightStick` is normally used for turning. This leaves up/down unused in most cases. As the amount of buttons is often very limited in contrast to the functions/actions possible in a game, it is very handy to be able to map these inputs (e.g. to jump and crouch).

This plugin provides 2 variants mapping `RightStick` up/down to:

- Gamepad `DPad` up/down
- Keyboard keys `U`/`D`

The keyboard mapping is preferable in most cases, as it does not duplicate two already mapped inputs (`DPad` up/down are accessible in UEVR via DPad Shifting). Furthermore many games do not allow custom mapping of gamepad inputs. So the keyboard variants gives you two new and fully customizable inputs.

The downside of the keyboard mapping is, that the game switches from gamepad to keyboard input and back. It is possible, that games do not allow this or have problems with it. But mainly the only side effect should be a quick switch of on-screen input-hints.

## Download

You can download the latest version from the [release page](https://github.com/gameflorist/uevr-alt-rs-mapping-plugin/releases).

The downloaded zip file will contain DLL files for both variants:

- `uevr-alt-rs-up-down-dpad.dll` for the `DPad` variant
- `uevr-alt-rs-up-down-keyboard.dll` for the Keyboard variant

## Installation

You can install the plugin either globally to be active for all UEVR games, or only for a single games.

### Global installation

1. Go to UEVR's global directory by either clicking the `Open Global Dir` button in UEVR or by navigating to `%appdata%\UnrealVRMod`.
2. Create a folder named `UEVR` and inside that a subfolder called `plugins`.
3. Extract the DLL file of the preferred variant from the downloaded zip file into the `plugins` folder, so that the dll file resides in e.g. `%appdata%\UnrealVRMod\UEVR\plugins\uevr-alt-rs-up-down-dpad.dll`

### Per-game installation

1. Go to UEVR's global directory by either clicking the `Open Global Dir` button in UEVR or by navigating to `%appdata%\UnrealVRMod`.
2. Open the subfolder containing the profile for your game (e.g. `Borderlands3`).
3. If it does not yet exist, create a subfolder called `plugins`.
4. Extract the DLL file of the preferred variant from the downloaded zip file into the `plugins` folder, so that the dll file resides in e.g. `%appdata%\UnrealVRMod\Borderlands3\plugins\uevr-alt-rs-up-down-dpad.dll`

## Compatibility

Please note that game profiles may already contain input-altering plugins. So there might be incompatibilities with various game profiles.

## Thanks

Many thanks to Markmon, who's great [Index Controls Plugin](https://github.com/mark-mon/uevr-index-controls) served as a boilerplate for this plugin.

And of course also many thanks to Praydog for creating UEVR and all others contributing to the ecosystem. It cannot be overstated how much ever evolving value UEVR adds to the world of PCVR!
