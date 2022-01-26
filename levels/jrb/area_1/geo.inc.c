#include "src/game/envfx_snow.h"

const GeoLayout jrb_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, jrb_dl__hflower_mesh_layer_1),
		GEO_CULL(-7000, 20000, -20000, 20000, -1600, 20000),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, jrb_dl_b0_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_CULL(-9500, 10000, -20000, 20000, -6000, 20000),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, jrb_dl_b1_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-20000, 20000, -20000, 20000, -20000, 2000),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, jrb_dl_b2_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_CULL(-2380, 20000, -20000, 20000, -20000, 20000),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_ALPHA, jrb_dl_b3_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_CULL(-9500, 10000, -20000, 20000, -6000, 20000),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, jrb_dl_c3_005_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, jrb_dl_c3_005_mesh_layer_5),
			GEO_DISPLAY_LIST(LAYER_OPAQUE_INTER, jrb_dl_c3_005_mesh_layer_3),
		GEO_CLOSE_NODE(),
		GEO_CULL(-20000, 10000, -20000, 20000, -6000, 20000),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, jrb_dl_c3_006_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_CULL(-20000, -7000, -20000, 20000, -20000, 20000),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, jrb_dl_c3_007_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_ALPHA, jrb_dl_c3_007_mesh_layer_4),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, jrb_dl_c3_007_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_CULL(-7000, 20000, -20000, 20000, -1600, 20000),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, jrb_dl_c3_008_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, jrb_dl_c3_008_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_CULL(-2380, 20000, -20000, 20000, -20000, 20000),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, jrb_dl_c3_009_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, jrb_dl_c3_009_mesh_layer_5),
		GEO_CLOSE_NODE(),
		GEO_CULL(10, -10, -20000, 20000, -1600, 20000),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE_INTER, jrb_dl_c3_010_mesh_layer_3),
		GEO_CLOSE_NODE(),
		GEO_CULL(-20000, 20000, -20000, 20000, -20000, 2000),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE_INTER, jrb_dl_c3_012_mesh_layer_3),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, jrb_dl_c3_012_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_TRANSPARENT, jrb_dl_c3_012_mesh_layer_5),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout jrb_area_1[] = {
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
					GEO_BRANCH(1, jrb_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_INTER, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_ALPHA, jrb_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT, jrb_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
