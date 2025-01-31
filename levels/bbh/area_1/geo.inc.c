#include "src/game/envfx_snow.h"

const GeoLayout bbh_area_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_INTER, bbh_dl__0_mesh_layer_3),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl__0_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_INTER, bbh_dl__1_mesh_layer_3),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl__1_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_INTER, bbh_dl__2_mesh_layer_3),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl__2_mesh_layer_1),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_c5_mesh_layer_1),
		GEO_CULL(0, 20000, -20000, 20000, -20000, 8500),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_c5_001_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_ROTATION_NODE_WITH_DL(LAYER_ALPHA, 90, 0, 0, bbh_dl_c5_002_mesh_layer_4),
		GEO_CULL(-20000, -2500, -20000, 20000, -20000, 8900),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_c5_006_mesh_layer_1),
			GEO_DISPLAY_LIST(LAYER_ALPHA, bbh_dl_c5_006_mesh_layer_4),
		GEO_CLOSE_NODE(),
		GEO_CULL(-2000, 20000, -20000, 20000, -20000, 20000),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bbh_dl_c5_007_mesh_layer_1),
		GEO_CLOSE_NODE(),
		GEO_ROTATION_NODE(LAYER_OPAQUE, 90, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(-2000, 20000, -20000, 20000, -20000, 20000),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE_INTER, bbh_dl_c5_008_mesh_layer_3),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE_INTER, bbh_dl_c5_009_mesh_layer_3),
		GEO_ROTATION_NODE(LAYER_OPAQUE, 90, 0, 0),
		GEO_OPEN_NODE(),
			GEO_CULL(0, 20000, -20000, 20000, -20000, 8500),
			GEO_OPEN_NODE(),
				GEO_DISPLAY_LIST(LAYER_OPAQUE_INTER, bbh_dl_c5_011_mesh_layer_3),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bbh_area_1[] = {
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
					GEO_BRANCH(1, bbh_area_1_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
