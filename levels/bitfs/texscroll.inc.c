void scroll_bitfs_dl_bully_mesh_layer_1_vtx_0() {
	int i = 0;
	int count = 18;
	int width = 64 * 0x20;
	int height = 64 * 0x20;

	static int currentY = 0;
	int deltaY;
	Vtx *vertices = segmented_to_virtual(bitfs_dl_bully_mesh_layer_1_vtx_0);

	deltaY = (int)(-0.23000001907348633 * 0x20) % height;

	if (absi(currentY) > height) {
		deltaY -= (int)(absi(currentY) / height) * height * signum_positive(deltaY);
	}

	for (i = 0; i < count; i++) {
		vertices[i].n.tc[1] += deltaY;
	}
	currentY += deltaY;
}

void scroll_bitfs() {
	scroll_bitfs_dl_bully_mesh_layer_1_vtx_0();
}
