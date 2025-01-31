const Collision tree_root_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(10),
	COL_VERTEX(179, 182, -433),
	COL_VERTEX(45, 298, -433),
	COL_VERTEX(45, 196, 232),
	COL_VERTEX(-162, 158, 166),
	COL_VERTEX(-162, 194, -433),
	COL_VERTEX(0, 0, 628),
	COL_VERTEX(-298, 0, 341),
	COL_VERTEX(-298, 0, -433),
	COL_VERTEX(354, 0, -471),
	COL_VERTEX(298, 0, 341),
	COL_TRI_INIT(SURFACE_NOT_SLIPPERY, 13),
	COL_TRI(0, 1, 2),
	COL_TRI(3, 2, 1),
	COL_TRI(3, 1, 4),
	COL_TRI(5, 6, 7),
	COL_TRI(7, 8, 9),
	COL_TRI(7, 9, 5),
	COL_TRI(0, 2, 8),
	COL_TRI(8, 2, 9),
	COL_TRI(9, 2, 5),
	COL_TRI(2, 3, 6),
	COL_TRI(2, 6, 5),
	COL_TRI(4, 6, 3),
	COL_TRI(7, 6, 4),
	COL_TRI_STOP(),
	COL_END()
};
