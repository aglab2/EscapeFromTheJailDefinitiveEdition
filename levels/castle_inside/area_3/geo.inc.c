#include "src/game/envfx_snow.h"

const GeoLayout castle_inside_area_3_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE_DECAL, -9215, 2470, 7141, castle_inside_dl_ow1_004_mesh_layer_2),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_inside_dl_ow1_004_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -9215, 2470, 7141, castle_inside_dl_ow1_005_mesh_layer_1),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -9215, 2470, 7141, castle_inside_dl_ow1_006_mesh_layer_1),
		GEO_ASM(0, geo_painting_update),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -8492, -3444, 3301),
		GEO_ASM(PAINTING_ID(0, 1), geo_painting_draw),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, -8492, -3444, 3301),
		GEO_ASM(PAINTING_ID(1, 1), geo_painting_draw),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 2113, 3433, -3315),
		GEO_ASM(PAINTING_ID(2, 1), geo_painting_draw),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 1964, 3392, 1899),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout castle_inside_area_3[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x0001),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 30000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 15191, -2194, -4474, 15191, -2394, -4474, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, castle_inside_area_3_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, castle_inside_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_DECAL, castle_inside_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
