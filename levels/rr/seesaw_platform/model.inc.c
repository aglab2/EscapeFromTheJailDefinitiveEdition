// US: 0x0701B0C8
// 0x0701B290 - 0x0701B370
static const Vtx rr_seg7_vertex_0701B290[] = {
    {{{  -306,    102,   -818}, 0, {  3716,   -714}, {0xaf, 0xcf, 0xc1, 0xff}}},
    {{{  -306,    102,    819}, 0, {   990,   2010}, {0xaf, 0xcf, 0xc1, 0xff}}},
    {{{   307,    102,    819}, 0, {     0,    990}, {0xaf, 0xcf, 0xc1, 0xff}}},
    {{{   307,    102,   -818}, 0, {  2694,  -1736}, {0xaf, 0xcf, 0xc1, 0xff}}},
    {{{   307,      0,   -767}, 0, {  2438,  -1820}, {0x53, 0x73, 0x76, 0xff}}},
    {{{  -306,      0,    768}, 0, { -1138,   -288}, {0x53, 0x73, 0x76, 0xff}}},
    {{{  -306,      0,   -767}, 0, {  1416,  -2842}, {0x53, 0x73, 0x76, 0xff}}},
    {{{   307,      0,    768}, 0, {  -116,    734}, {0x53, 0x73, 0x76, 0xff}}},
    {{{  -306,    102,   -818}, 0, {  3716,   -714}, {0x63, 0x80, 0x88, 0xff}}},
    {{{  -306,      0,   -767}, 0, {  3800,   -458}, {0x63, 0x80, 0x88, 0xff}}},
    {{{  -306,      0,    768}, 0, {  1246,   2096}, {0x63, 0x80, 0x88, 0xff}}},
    {{{  -306,    102,    819}, 0, {   990,   2010}, {0x63, 0x80, 0x88, 0xff}}},
    {{{   307,    102,    819}, 0, {     0,    990}, {0x63, 0x80, 0x88, 0xff}}},
    {{{   307,      0,    768}, 0, {  -116,    734}, {0x63, 0x80, 0x88, 0xff}}},
    {{{   307,      0,   -767}, 0, {  2438,  -1820}, {0x63, 0x80, 0x88, 0xff}}},
    {{{   307,    102,   -818}, 0, {  2694,  -1736}, {0x63, 0x80, 0x88, 0xff}}},
};

// US: 0x0701B1C8
// 0x0701B370 - 0x0701B430
static const Vtx rr_seg7_vertex_0701B370[] = {
    {{{   307,    102,   -818}, 0, {  2694,  -1736}, {0x79, 0x9c, 0x9f, 0xff}}},
    {{{   307,      0,   -767}, 0, {  2884,  -1926}, {0x79, 0x9c, 0x9f, 0xff}}},
    {{{  -306,      0,   -767}, 0, {  3906,   -904}, {0x79, 0x9c, 0x9f, 0xff}}},
    {{{  -306,    102,   -818}, 0, {  3716,   -714}, {0x79, 0x9c, 0x9f, 0xff}}},
    {{{  -306,    102,    819}, 0, {   990,   2010}, {0x79, 0x9c, 0x9f, 0xff}}},
    {{{   307,      0,    768}, 0, {  -220,   1178}, {0x79, 0x9c, 0x9f, 0xff}}},
    {{{   307,    102,    819}, 0, {     0,    990}, {0x79, 0x9c, 0x9f, 0xff}}},
    {{{  -306,      0,    768}, 0, {   800,   2200}, {0x79, 0x9c, 0x9f, 0xff}}},
};

// 0x0701B430 - 0x0701B4C0
static const Gfx rr_seg7_dl_0701B430[] = {
    gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, sky_09007800),
    gsDPLoadSync(),
    gsDPLoadBlock(G_TX_LOADTILE, 0, 0, 32 * 32 - 1, CALC_DXT(32, G_IM_SIZ_16b_BYTES)),
    gsSPVertex(rr_seg7_vertex_0701B290, 16, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSP2Triangles( 4,  5,  6, 0x0,  4,  7,  5, 0x0),
    gsSP2Triangles( 8,  9, 10, 0x0,  8, 10, 11, 0x0),
    gsSP2Triangles(12, 13, 14, 0x0, 12, 14, 15, 0x0),
    gsSPVertex(rr_seg7_vertex_0701B370, 8, 0),
    gsSP2Triangles( 0,  1,  2, 0x0,  0,  2,  3, 0x0),
    gsSP2Triangles( 4,  5,  6, 0x0,  4,  7,  5, 0x0),
    gsSPEndDisplayList(),
};

// 0x0701B4C0 - 0x0701B530
const Gfx rr_seg7_dl_0701B4C0[] = {
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_MODULATERGB, G_CC_MODULATERGB),
    gsSPClearGeometryMode(G_LIGHTING),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, G_TX_NOMASK, G_TX_NOLOD),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPTileSync(),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_16b, 8, 0, G_TX_RENDERTILE, 0, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD, G_TX_WRAP | G_TX_NOMIRROR, 5, G_TX_NOLOD),
    gsDPSetTileSize(0, 0, 0, (32 - 1) << G_TEXTURE_IMAGE_FRAC, (32 - 1) << G_TEXTURE_IMAGE_FRAC),
    gsSPDisplayList(rr_seg7_dl_0701B430),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_OFF),
    gsDPPipeSync(),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsSPSetGeometryMode(G_LIGHTING),
    gsSPEndDisplayList(),
};
