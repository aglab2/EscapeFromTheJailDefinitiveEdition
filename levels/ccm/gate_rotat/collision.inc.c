const Collision gate_rotat_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(13),
	COL_VERTEX(-89, 0, -51),
	COL_VERTEX(-1849, 0, 991),
	COL_VERTEX(-1849, 1766, 991),
	COL_VERTEX(-89, 1766, -51),
	COL_VERTEX(-89, 1766, -2049),
	COL_VERTEX(-89, 0, -2049),
	COL_VERTEX(89, 0, 51),
	COL_VERTEX(89, 0, -2056),
	COL_VERTEX(89, 1766, -2056),
	COL_VERTEX(89, 1766, 51),
	COL_VERTEX(-1690, 1766, 1088),
	COL_VERTEX(-1690, 0, 1088),
	COL_VERTEX(-1690, 0, 1078),
	COL_TRI_INIT(SURFACE_DEFAULT, 9),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(3, 4, 5),
	COL_TRI(3, 5, 0),
	COL_TRI(6, 7, 8),
	COL_TRI(6, 8, 9),
	COL_TRI(9, 10, 11),
	COL_TRI(9, 11, 6),
	COL_TRI(6, 11, 12),
	COL_TRI_STOP(),
	COL_END()
};
