#include "src/game/envfx_snow.h"

const GeoLayout wmotr_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wmotr_dl__bg_mesh_layer_5),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wmotr_dl_g_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wmotr_dl_j_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wmotr_dl_mc_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wmotr_dl_mc_001_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_ALPHA, wmotr_dl_mc_002_mesh_layer_4),
		GEO_DISPLAY_LIST(LAYER_ALPHA, wmotr_dl_mc_003_mesh_layer_4),
		GEO_CULL(-20000, 3500, -20000, 20000, -20000, 3500),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, wmotr_dl_mc_004_mesh_layer_1),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout wmotr_area_1[] = {
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
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -200, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, wmotr_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_LAVA_BUBBLES, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wmotr_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, wmotr_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, wmotr_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
