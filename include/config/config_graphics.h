#pragma once

/*********************
 * GRAPHICS SETTINGS *
 *********************/

// Use HD versions of the intro splash screen textures. This includes "Made with HackerSM64".
#define HD_INTRO_TEXTURES

// Enable widescreen (16:9) support
#define WIDE

// Skybox size modifier, changing this will add support for larger skybox images. NOTE: Vanilla skyboxes may break if you change this option. Be sure to rescale them accordingly.
// Whenever you change this, make sure to run "make -C tools clean" to rebuild the skybox tool (alternatively go into skyconv.c and change the file in any way (like adding/deleting a space) to specifically rebuild that tool).
// When increasing this, you should probably also increase the GFX pool size. (the GFX_POOL_SIZE define in src/game/game_init.h)
#define SKYBOX_SIZE 1

// When this option is enabled, LODs will ONLY work on console.
// When this option is disabled, LODs will work regardless of whether console or emulator is used.
// Regardless of whether this setting is enabled or not, you can use gIsConsole to wrap your own code in a console check.
#define AUTO_LOD

// Disable AA (Improves console performance but causes visible seams between unconnected geometry).
#define DISABLE_AA

// Makes the coins ia8 64x64 instead of ia16 32x32. Uses new ia8 textures so that vanilla coins look better.
#define IA8_COINS

// Similar to the above, but 30 FPS (Textures by InTheBeef, cleaned up by Arceveti)
#define IA8_30FPS_COINS

// Use .rej microcode for certain objects (experimental - only should be used when F3DZEX_GBI_2 is defined).
// So far - recent tests have show that this has reduced performance overall due to CPU load,
// though in some cases it may perform better.
// #define OBJECTS_REJ

/**
 * Mario's silhouette when behind solid objects/surfaces
 * Also enables new render layers, such as LAYER_ALPHA_DECAL.
 * The number is the intensity of the silhouette, from 0-255.
 * NOTE: The overlap between Mario's model parts is visible on certain HLE plugins.
 * Also, this also disables anti-aliasing on Mario.
 * NOTE: Regarding performance, silhouette seems to lose 1-2 frames on console.
 */
// #define SILHOUETTE 127

// Use 64x64 quarter shadow textures (Vanilla are 16x16).
#define HD_SHADOWS

// Makes certain objects (mainly trees) transparent when the camera gets close.
#define OBJ_OPACITY_BY_CAM_DIST

// Fixes the game reading the ia8 burn smoke texture as an rgba16.
#define BURN_SMOKE_FIX

// Disable the fix to Koopa's unshelled model.
#define KOOPA_KEEP_PINK_SHORTS

// Lightweight directional lighting engine by Fazana. Intended for giving proximity and positional pointlights to small objects.
// NOTE: Stil breaks occasionally, and PUPPYLIGHT_NODE doesn't work in areas that aren't area 1.
// #define PUPPYLIGHTS

// Uses the correct "up" vector for the guLookAtReflect call in geo_process_master_list_sub.
// It is sideways in vanilla, and since vanilla's environment map textures are sideways too, they will appear as sideways in-game if this is enabled.
// Make sure your custom environment map textures are the correct orientation.
// #define FIX_REFLECT_MTX

// This improves performance a bit, and does not seem to break anything.
#define DISABLE_GRAPH_NODE_TYPE_FUNCTIONAL

// Disables object shadows. You'll probably only want this either as a last resort for performance or if you're making a super stylized hack.
// #define DISABLE_SHADOWS

// Use old shadow IDs for Fast64 compatibility
#define LEGACY_SHADOW_IDS

// -- Compatibility safeguards. Don't mess with these unless you know what you're doing. --

#ifndef F3DZEX_GBI_2
#undef OBJECTS_REJ // OBJECTS_REJ requires f3dzex.
#endif // !F3DZEX_GBI_2

#ifndef F3DEX_GBI_SHARED
#undef OBJECTS_REJ // Non F3DEX-based ucodes do NOT support ucode switching.
#endif // !F3DEX_GBI_SHARED

#ifdef OBJECTS_REJ
// Enable required ucodes.
#define F3DEX2_REJ_GBI
#define F3DLX2_REJ_GBI
#endif // OBJECTS_REJ
