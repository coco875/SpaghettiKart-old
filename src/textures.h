#ifndef TEXTURES_H
#define TEXTURES_H

#ifndef TARGET_N64
#include <libultraship.h>
#include <assets/texture_tkmk00.h>
#else
#include <PR/ultratypes.h>
#endif

/**
 * @brief struct for a texture use in menu mainly
 *
 */
typedef struct {
    /* 0x00 */ s32 type;
    /* 0x04 */ u64* textureData; // This should be interpreted as a segmented address
    /* 0x08 */ u16 width;
    /* 0x0A */ u16 height;
    /* 0x0C */ u16 dX;
    /* 0x0E */ u16 dY;
    /* 0x10 */ u16 size; // This size is NOT equal to width*height. Its likely the size of the compressed texture
} MenuTexture; // size = 0x14

/**
 * @brief struct for an animation
 *
 */
typedef struct {
    /* 0x00 */ MenuTexture* mk64Texture; // This should be interpreted as a segmented address
    /* 0x04 */ s32 frame_length;
} MkAnimation; // size = 0x8

extern MenuTexture D_02000000[2];
extern MenuTexture D_02000028[2];
extern MenuTexture D_02000050[2];
extern MenuTexture D_02000078[2];
extern MenuTexture D_020000A0[2];
extern MenuTexture D_020000C8[2];
extern MenuTexture D_020000F0[2];
extern MenuTexture D_02000118[2];
extern MenuTexture D_02000140[2];
extern MenuTexture D_02000168[2];
extern MenuTexture D_02000190[2];
extern MenuTexture D_020001B8[2];
extern MenuTexture D_020001E0[2];
extern MenuTexture D_02000208[2];
extern MenuTexture D_02000230[2];
extern MenuTexture D_02000258[2];
extern MenuTexture D_02000280[2];
extern MenuTexture D_020002A8[2];
extern MenuTexture D_020002D0[2];
extern MenuTexture D_020002F8[2];
extern MenuTexture D_02000320[2];
extern MenuTexture D_02000348[2];
extern MenuTexture D_02000370[2];
extern MenuTexture D_02000398[2];
extern MenuTexture D_020003C0[2];
extern MenuTexture D_020003E8[2];
extern MenuTexture D_02000410[2];
extern MenuTexture D_02000438[2];
extern MenuTexture D_02000460[2];
extern MenuTexture D_02000488[2];
extern MenuTexture D_020004B0[2];
extern MenuTexture D_020004D8[2];
extern MenuTexture D_02000500[2];
extern MenuTexture D_02000528[2];
extern MenuTexture D_02000550[2];
extern MenuTexture D_02000578[2];
extern MenuTexture D_020005A0[2];
extern MenuTexture D_020005C8[2];
extern MenuTexture D_020005F0[2];
extern MenuTexture D_02000618[2];
extern MenuTexture D_02000640[2];
extern MenuTexture D_02000668[2];
extern MenuTexture D_02000690[2];
extern MenuTexture D_020006B8[2];
extern MenuTexture D_020006E0[2];
extern MenuTexture D_02000708[2];
extern MenuTexture D_02000730[2];
extern MenuTexture D_02000758[2];
extern MenuTexture D_02000780[2];
extern MenuTexture D_020007A8[2];
extern MenuTexture D_020007D0[2];
extern MenuTexture D_020007F8[2];
extern MenuTexture D_02000820[2];
extern MenuTexture D_02000848[2];
extern MenuTexture D_02000870[2];
extern MenuTexture D_02000898[2];
extern MenuTexture D_020008C0[2];
extern MenuTexture D_020008E8[2];
extern MenuTexture D_02000910[2];
extern MenuTexture D_02000938[2];
extern MenuTexture D_02000960[2];
extern MenuTexture D_02000988[2];
extern MenuTexture D_020009B0[2];
extern MenuTexture D_020009D8[2];
extern MenuTexture D_02000A00[2];
extern MenuTexture D_02000A28[2];
extern MenuTexture D_02000A50[2];
extern MenuTexture D_02000A78[2];
extern MenuTexture D_02000AA0[2];
extern MenuTexture D_02000AC8[2];
extern MenuTexture D_02000AF0[2];
extern MenuTexture D_02000B18[2];
extern MenuTexture D_02000B40[2];
extern MenuTexture D_02000B68[2];
extern MenuTexture D_02000B90[2];
extern MenuTexture D_02000BB8[2];
extern MenuTexture D_02000BE0[2];
extern MenuTexture D_02000C08[2];
extern MenuTexture D_02000C30[2];
extern MenuTexture D_02000C58[2];
extern MenuTexture D_02000C80[2];
extern MenuTexture D_02000CA8[2];
extern MenuTexture D_02000CD0[2];
extern MenuTexture D_02000CF8[2];
extern MenuTexture D_02000D20[2];
extern MenuTexture D_02000D48[2];
extern MenuTexture D_02000D70[2];
extern MenuTexture D_02000D98[2];
extern MenuTexture D_02000DC0[2];
extern MenuTexture D_02000DE8[2];
extern MenuTexture D_02000E10[2];
extern MenuTexture D_02000E38[2];
extern MenuTexture D_02000E60[2];
extern MenuTexture D_02000E88[2];
extern MenuTexture D_02000EB0[2];
extern MenuTexture D_02000ED8[2];
extern MenuTexture D_02000F00[2];
extern MenuTexture D_02000F28[2];
extern MenuTexture D_02000F50[2];
extern MenuTexture D_02000F78[2];
extern MenuTexture D_02000FA0[2];
extern MenuTexture D_02000FC8[2];
extern MenuTexture D_02000FF0[2];
extern MenuTexture D_02001018[2];
extern MenuTexture D_02001040[2];
extern MenuTexture D_02001068[2];
extern MenuTexture D_02001090[2];
extern MenuTexture D_020010B8[2];
extern MenuTexture D_020010E0[2];
extern MenuTexture D_02001108[2];
extern MenuTexture D_02001130[2];
extern MenuTexture D_02001158[2];
extern MenuTexture D_02001180[2];
extern MenuTexture D_020011A8[2];
extern MenuTexture D_020011D0[2];
extern MenuTexture D_020011F8[2];
extern MenuTexture D_02001220[2];
extern MenuTexture D_02001248[2];
extern MenuTexture D_02001270[2];
extern MenuTexture D_02001298[2];
extern MenuTexture D_020012C0[2];
extern MenuTexture D_020012E8[2];
extern MenuTexture D_02001310[2];
extern MenuTexture D_02001338[2];
extern MenuTexture D_02001360[2];
extern MenuTexture D_02001388[2];
extern MenuTexture D_020013B0[2];
extern MenuTexture D_020013D8[2];
extern MenuTexture D_02001400[2];
extern MenuTexture D_02001428[2];
extern MenuTexture D_02001450[2];
extern MenuTexture D_02001478[2];
extern MenuTexture D_020014A0[2];
extern MenuTexture D_020014C8[6];
extern MenuTexture D_02001540[3];
extern MenuTexture D_0200157C[2];
extern MenuTexture D_020015A4[2];
extern MenuTexture D_020015CC[5];
extern MenuTexture D_02001630[2];
extern MenuTexture D_02001658[5];
extern MenuTexture D_020016BC[2];
extern MenuTexture D_020016E4[2];
extern MenuTexture D_0200170C[2];
extern MenuTexture D_02001734[2];
extern MenuTexture D_0200175C[2];
extern MenuTexture D_02001784[2];
extern MenuTexture D_020017AC[2];
extern MenuTexture D_020017D4[2];
extern MenuTexture D_020017FC[2];
extern MenuTexture D_02001824[2];
extern MenuTexture D_0200184C[2];
extern MenuTexture D_02001874[2];
extern MenuTexture D_0200189C[2];
extern MenuTexture D_020018C4[2];
extern MenuTexture D_020018EC[2];
extern MenuTexture D_02001914[2];
extern MenuTexture D_0200193C[2];
extern MenuTexture D_02001964[2];
extern MkAnimation D_0200198C[2];
extern MkAnimation D_0200199C[2];
extern MkAnimation D_020019AC[2];
extern MkAnimation D_020019BC[2];
extern MkAnimation D_020019CC[2];
extern MkAnimation D_020019DC[2];
extern MenuTexture D_020019EC[2];
extern MenuTexture D_02001A14[2];
extern MenuTexture D_02001A3C[2];
extern MenuTexture D_02001A64[2];
extern MenuTexture D_02001A8C[2];
extern MenuTexture D_02001AB4[2];
extern MenuTexture D_02001ADC[2];
extern MenuTexture D_02001B04[2];
extern MenuTexture seg2_mario_raceway_preview_texture[2];
extern MenuTexture D_02001B54[2];
extern MenuTexture D_02001B7C[2];
extern MenuTexture D_02001BA4[2];
extern MenuTexture D_02001BCC[2];
extern MenuTexture D_02001BF4[2];
extern MenuTexture D_02001C1C[2];
extern MenuTexture D_02001C44[2];
extern MenuTexture D_02001C6C[2];
extern MenuTexture D_02001C94[2];
extern MenuTexture D_02001CBC[2];
extern MenuTexture D_02001CE4[2];
extern MenuTexture D_02001D0C[2];
extern MenuTexture D_02001D34[2];
extern MenuTexture D_02001D5C[2];
extern MenuTexture D_02001D84[2];
extern MenuTexture D_02001DAC[2];
extern MenuTexture D_02001DD4[2];
extern MenuTexture D_02001DFC[2];
extern MenuTexture D_02001E24[2];
extern MkAnimation D_02001E4C[3];
extern MkAnimation D_02001E64[2];
extern MkAnimation D_02001E74[2];
extern MkAnimation D_02001E84[2];
extern MkAnimation D_02001E94[2];
extern MkAnimation D_02001EA4[2];
extern MkAnimation D_02001EB4[2];
extern MkAnimation D_02001EC4[2];
extern MkAnimation D_02001ED4[2];
extern MkAnimation D_02001EE4[2];
extern MkAnimation D_02001EF4[2];
extern MkAnimation D_02001F04[2];
extern MkAnimation D_02001F14[2];
extern MkAnimation D_02001F24[2];
extern MkAnimation D_02001F34[2];
extern MkAnimation D_02001F44[2];
extern MkAnimation D_02001F54[2];
extern MkAnimation D_02001F64[2];
extern MkAnimation D_02001F74[2];
extern MkAnimation D_02001F84[2];
extern MkAnimation D_02001F94[2];
extern MenuTexture D_02001FA4[2];
extern MenuTexture D_02001FCC[2];
extern MenuTexture D_02001FF4[2];
extern MenuTexture D_0200201C[2];
extern MenuTexture D_02002044[2];
extern MenuTexture D_0200206C[2];
extern MenuTexture D_02002094[2];
extern MkAnimation D_020020BC[2];
extern MkAnimation D_020020CC[2];
extern MkAnimation D_020020DC[2];
extern MkAnimation D_020020EC[2];
extern MkAnimation D_020020FC[2];
extern MkAnimation D_0200210C[2];
extern MenuTexture D_0200211C[2];
extern MenuTexture D_02002144[2];
extern MenuTexture D_0200216C[2];
extern MenuTexture D_02002194[2];
extern MenuTexture D_020021BC[2];
extern MenuTexture D_020021E4[2];
extern MenuTexture D_0200220C[2];
extern MenuTexture D_02002234[2];
extern MenuTexture D_0200225C[2];
extern MenuTexture D_02002284[2];
extern MenuTexture D_020022AC[2];
extern MenuTexture D_020022D4[2];
extern MenuTexture D_020022FC[2];
extern MenuTexture D_02002324[2];
extern MenuTexture D_0200234C[2];
extern MenuTexture D_02002374[2];
extern MenuTexture D_0200239C[2];
extern MenuTexture D_020023C4[2];
extern MenuTexture D_020023EC[2];
extern MenuTexture D_02002414[2];
extern MenuTexture D_0200243C[2];
extern MenuTexture D_02002464[2];
extern MenuTexture D_0200248C[2];
extern MenuTexture D_020024B4[2];
extern MenuTexture D_020024DC[2];
extern MenuTexture D_02002504[2];
extern MenuTexture D_0200252C[2];
extern MenuTexture D_02002554[2];
extern MenuTexture D_0200257C[2];
extern MenuTexture D_020025A4[2];
extern MenuTexture D_020025CC[2];
extern MenuTexture D_020025F4[2];
extern MenuTexture D_0200261C[2];
extern MenuTexture D_02002644[2];
extern MenuTexture D_0200266C[2];
extern MenuTexture D_02002694[2];
extern MenuTexture D_020026BC[2];
extern MenuTexture D_020026E4[2];
extern MenuTexture D_0200270C[2];
extern MenuTexture D_02002734[2];
extern MenuTexture D_0200275C[2];
extern MenuTexture D_02002784[2];
extern MenuTexture D_020027AC[2];
extern MenuTexture D_020027D4[2];
extern MenuTexture D_020027FC[2];
extern MenuTexture D_02002824[2];
extern MenuTexture D_0200284C[2];
extern MenuTexture D_02002874[2];
extern MenuTexture D_0200289C[2];
extern MenuTexture D_020028C4[2];
extern MenuTexture D_020028EC[2];
extern MenuTexture D_02002914[2];
extern MenuTexture D_0200293C[2];
extern MenuTexture D_02002964[2];
extern MenuTexture D_0200298C[2];
extern MenuTexture D_020029B4[2];
extern MenuTexture D_020029DC[2];
extern MenuTexture D_02002A04[2];
extern MenuTexture D_02002A2C[2];
extern MenuTexture D_02002A54[2];
extern MenuTexture D_02002A7C[2];
extern MenuTexture D_02002AA4[2];
extern MenuTexture D_02002ACC[2];
extern MenuTexture D_02002AF4[2];
extern MenuTexture D_02002B1C[2];
extern MenuTexture D_02002B44[2];
extern MenuTexture D_02002B6C[2];
extern MenuTexture D_02002B94[2];
extern MenuTexture D_02002BBC[2];
extern MenuTexture D_02002BE4[2];
extern MenuTexture D_02002C0C[2];
extern MenuTexture D_02002C34[2];
extern MenuTexture D_02002C5C[2];
extern MenuTexture D_02002C84[2];
extern MenuTexture D_02002CAC[2];
extern MenuTexture D_02002CD4[2];
extern MenuTexture D_02002CFC[2];
extern MenuTexture D_02002D24[2];
extern MenuTexture D_02002D4C[2];
extern MenuTexture D_02002D74[2];
extern MenuTexture D_02002D9C[2];
extern MenuTexture D_02002DC4[2];
extern MenuTexture D_02002DEC[2];
extern MenuTexture D_02002E14[2];
extern MenuTexture D_02002E3C[2];
extern MenuTexture D_02002E64[2];
extern MenuTexture D_02002E8C[2];
extern MenuTexture D_02002EB4[2];
extern MenuTexture D_02002EDC[2];
extern MenuTexture D_02002F04[2];
extern MenuTexture D_02002F2C[2];
extern MenuTexture D_02002F54[2];
extern MenuTexture D_02002F7C[2];
extern MenuTexture D_02002FA4[2];
extern MenuTexture D_02002FCC[2];
extern MenuTexture D_02002FF4[2];
extern MenuTexture D_0200301C[2];
extern MenuTexture D_02003044[2];
extern MenuTexture D_0200306C[2];
extern MenuTexture D_02003094[2];
extern MenuTexture D_020030BC[2];
extern MenuTexture D_020030E4[2];
extern MenuTexture D_0200310C[2];
extern MenuTexture D_02003134[2];
extern MenuTexture D_0200315C[2];
extern MenuTexture D_02003184[2];
extern MenuTexture D_020031AC[2];
extern MenuTexture D_020031D4[2];
extern MenuTexture D_020031FC[2];
extern MenuTexture D_02003224[2];
extern MenuTexture D_0200324C[2];
extern MenuTexture D_02003274[2];
extern MenuTexture D_0200329C[2];
extern MenuTexture D_020032C4[2];
extern MenuTexture D_020032EC[2];
extern MenuTexture D_02003314[2];
extern MenuTexture D_0200333C[2];
extern MenuTexture D_02003364[2];
extern MenuTexture D_0200338C[2];
extern MenuTexture D_020033B4[2];
extern MenuTexture D_020033DC[2];
extern MenuTexture D_02003404[2];
extern MenuTexture D_0200342C[2];
extern MenuTexture D_02003454[2];
extern MenuTexture D_0200347C[2];
extern MenuTexture D_020034A4[2];
extern MenuTexture D_020034CC[2];
extern MenuTexture D_020034F4[2];
extern MenuTexture D_0200351C[2];
extern MenuTexture D_02003544[2];
extern MenuTexture D_0200356C[2];
extern MenuTexture D_02003594[2];
extern MenuTexture D_020035BC[2];
extern MenuTexture D_020035E4[2];
extern MenuTexture D_0200360C[2];
extern MenuTexture D_02003634[2];
extern MenuTexture D_0200365C[2];
extern MenuTexture D_02003684[2];
extern MenuTexture D_020036AC[2];
extern MenuTexture D_020036D4[2];
extern MenuTexture D_020036FC[2];
extern MenuTexture D_02003724[2];
extern MenuTexture D_0200374C[2];
extern MenuTexture D_02003774[2];
extern MenuTexture D_0200379C[2];
extern MenuTexture D_020037C4[2];
extern MenuTexture D_020037EC[2];
extern MenuTexture D_02003814[2];
extern MenuTexture D_0200383C[2];
extern MenuTexture D_02003864[2];
extern MenuTexture D_0200388C[2];
extern MenuTexture D_020038B4[2];
extern MenuTexture D_020038DC[2];
extern MenuTexture D_02003904[2];
extern MenuTexture D_0200392C[2];
extern MenuTexture D_02003954[2];
extern MenuTexture D_0200397C[2];
extern MenuTexture D_020039A4[2];
extern MenuTexture D_020039CC[2];
extern MenuTexture D_020039F4[2];
extern MenuTexture D_02003A1C[2];
extern MenuTexture D_02003A44[2];
extern MenuTexture D_02003A6C[2];
extern MenuTexture D_02003A94[2];
extern MenuTexture D_02003ABC[2];
extern MenuTexture D_02003AE4[2];
extern MenuTexture D_02003B0C[2];
extern MenuTexture D_02003B34[2];
extern MenuTexture D_02003B5C[2];
extern MenuTexture D_02003B84[2];
extern MenuTexture D_02003BAC[2];
extern MenuTexture D_02003BD4[2];
extern MenuTexture D_02003BFC[2];
extern MenuTexture D_02003C24[2];
extern MenuTexture D_02003C4C[2];
extern MenuTexture D_02003C74[2];
extern MenuTexture D_02003C9C[2];
extern MenuTexture D_02003CC4[2];
extern MenuTexture D_02003CEC[2];
extern MenuTexture D_02003D14[2];
extern MenuTexture D_02003D3C[2];
extern MenuTexture D_02003D64[2];
extern MenuTexture D_02003D8C[2];
extern MenuTexture D_02003DB4[2];
extern MenuTexture D_02003DDC[2];
extern MenuTexture D_02003E04[2];
extern MenuTexture D_02003E2C[2];
extern MenuTexture D_02003E54[2];
extern MenuTexture D_02003E7C[2];
extern MenuTexture D_02003EA4[2];
extern MenuTexture D_02003ECC[2];
extern MenuTexture D_02003EF4[2];
extern MenuTexture D_02003F1C[2];
extern MenuTexture D_02003F44[2];
extern MenuTexture D_02003F6C[2];
extern MenuTexture D_02003F94[2];
extern MenuTexture D_02003FBC[2];
extern MenuTexture D_02003FE4[2];
extern MenuTexture D_0200400C[2];
extern MenuTexture D_02004034[2];
extern MenuTexture D_0200405C[2];
extern MenuTexture D_02004084[2];
extern MenuTexture D_020040AC[2];
extern MenuTexture D_020040D4[2];
extern MenuTexture D_020040FC[2];
extern MenuTexture D_02004124[2];
extern MenuTexture D_0200414C[2];
extern MenuTexture D_02004174[2];
extern MenuTexture D_0200419C[2];
extern MenuTexture D_020041C4[2];
extern MenuTexture D_020041EC[2];
extern MenuTexture D_02004214[2];
extern MenuTexture D_0200423C[2];
extern MenuTexture D_02004264[2];
extern MenuTexture D_0200428C[2];
extern MenuTexture D_020042B4[2];
extern MenuTexture D_020042DC[2];
extern MenuTexture D_02004304[2];
extern MenuTexture D_0200432C[2];
extern MenuTexture D_02004354[2];
extern MenuTexture D_0200437C[2];
extern MenuTexture D_020043A4[2];
extern MenuTexture D_020043CC[2];
extern MenuTexture D_020043F4[2];
extern MenuTexture D_0200441C[2];
extern MenuTexture D_02004444[2];
extern MenuTexture D_0200446C[2];
extern MenuTexture D_02004494[2];
extern MenuTexture D_020044BC[2];
extern MenuTexture D_020044E4[2];
extern MenuTexture D_0200450C[2];
extern MenuTexture D_02004534[2];
extern MenuTexture D_0200455C[2];
extern MenuTexture D_02004584[1];
extern MenuTexture seg2_blue_sky_background_texture[2];
extern MenuTexture seg2_sunset_background_texture[2];
extern MenuTexture seg2_copyright_1996_texture[2];
extern MenuTexture seg2_push_start_button_texture[2];
extern MenuTexture D_02004638[2];
extern MenuTexture seg2_game_select_texture[2];
extern MenuTexture seg2_menu_1p_column[4];
extern MenuTexture seg2_menu_2p_column[5];
extern MenuTexture seg2_menu_3p_column[4];
extern MenuTexture seg2_menu_4p_column[4];
extern MenuTexture D_020047DC[2];
extern MenuTexture D_02004804[2];
extern MenuTexture D_0200482C[2];
extern MenuTexture D_02004854[2];
extern MenuTexture D_0200487C[2];
extern MenuTexture D_020048A4[2];
extern MenuTexture D_020048CC[2];
extern MenuTexture seg2_50_CC_texture[2];
extern MenuTexture seg2_100_CC_texture[2];
extern MenuTexture seg2_150_CC_texture[2];
extern MenuTexture seg2_extra_CC_texture[2];
extern MenuTexture seg2_menu_no_item_texture[2];
extern MenuTexture D_020049BC[2];
extern MenuTexture D_020049E4[2];
extern MenuTexture D_02004A0C[2];
extern MenuTexture seg2_data_texture[2];
extern MenuTexture seg2_P1_border_texture[3];
extern MenuTexture seg2_P2_border_texture[3];
extern MenuTexture seg2_P3_border_texture[3];
extern MenuTexture seg2_P4_border_texture[3];
extern MenuTexture D_02004B4C[2];
extern MenuTexture D_02004B74[2];
extern MenuTexture seg2_menu_select_texture[2];
extern MenuTexture seg2_mushroom_cup_texture[2];
extern MenuTexture seg2_flower_cup_texture[2];
extern MenuTexture seg2_star_cup_texture[2];
extern MenuTexture seg2_special_cup_texture[2];
extern MenuTexture seg2_mario_raceway_preview_small_texture[2];
extern MenuTexture seg2_mushroom_cup_title_texture[5];
extern MenuTexture seg2_flower_cup_title_texture[5];
extern MenuTexture seg2_star_cup_title_texture[5];
extern MenuTexture seg2_special_cup_title_texture[5];
extern MenuTexture seg2_battle_title_texture[5];
extern MenuTexture D_02004E80[2];
extern MenuTexture seg2_mario_raceway_title_texture[2];
extern MenuTexture seg2_choco_mountain_title_texture[2];
extern MenuTexture D_02004EF8[2];
extern MenuTexture D_02004F20[2];
extern MenuTexture D_02004F48[2];
extern MenuTexture D_02004F70[2];
extern MenuTexture D_02004F98[2];
extern MenuTexture D_02004FC0[2];
extern MenuTexture D_02004FE8[2];
extern MenuTexture D_02005010[2];
extern MenuTexture D_02005038[2];
extern MenuTexture D_02005060[2];
extern MenuTexture D_02005088[2];
extern MenuTexture D_020050B0[2];
extern MenuTexture D_020050D8[2];
extern MenuTexture D_02005100[2];
extern MenuTexture D_02005128[2];
extern MenuTexture D_02005150[2];
extern MenuTexture D_02005178[2];
extern MenuTexture D_020051A0[2];
extern MenuTexture D_020051C8[2];
extern MenuTexture D_020051F0[2];
extern MenuTexture D_02005218[2];
extern MenuTexture D_02005240[2];
extern MenuTexture D_02005268[2];
extern MenuTexture D_02005290[2];
extern MenuTexture D_020052B8[2];
extern MenuTexture D_020052E0[2];
extern MenuTexture D_02005308[2];
extern MenuTexture D_02005330[2];
extern MenuTexture D_02005358[2];
extern MenuTexture D_02005380[2];
extern MenuTexture D_020053A8[2];
extern MenuTexture D_020053D0[2];
extern MenuTexture D_020053F8[2];
extern MenuTexture D_02005420[2];
extern MenuTexture D_02005448[2];
extern MenuTexture D_02005470[2];
extern MenuTexture D_02005498[2];
extern MenuTexture D_020054C0[2];
extern MenuTexture D_020054E8[2];
extern MenuTexture D_02005510[2];
extern MenuTexture D_02005538[2];
extern MenuTexture D_02005560[2];
extern MenuTexture D_02005588[2];
extern MenuTexture D_020055B0[2];
extern MenuTexture D_020055D8[2];
extern MenuTexture D_02005600[2];
extern MenuTexture D_02005628[2];
extern MenuTexture D_02005650[2];
extern MenuTexture D_02005678[2];
extern MenuTexture D_020056A0[2];
extern MenuTexture D_020056C8[2];
extern MenuTexture D_020056F0[2];
extern MenuTexture D_02005718[2];
extern MenuTexture D_02005740[2];
extern MenuTexture D_02005768[2];
extern MenuTexture D_02005790[2];
extern MenuTexture D_020057B8[2];
extern MenuTexture D_020057E0[2];
extern MenuTexture D_02005808[2];
extern MenuTexture D_02005830[2];
extern MenuTexture D_02005858[2];
extern MenuTexture D_02005880[2];
extern MenuTexture D_020058A8[2];
extern MenuTexture D_020058D0[2];
extern MenuTexture D_020058F8[2];
extern MenuTexture D_02005920[2];
extern MenuTexture D_02005948[2];
extern MenuTexture D_02005970[2];
extern MenuTexture D_02005998[2];
extern MenuTexture D_020059C0[2];
extern MenuTexture D_020059E8[2];
extern MenuTexture D_02005A10[2];
extern MenuTexture D_02005A38[2];
extern MenuTexture D_02005A60[2];
extern MenuTexture D_02005A88[2];
extern MenuTexture D_02005AB0[2];
extern MenuTexture D_02005AD8[2];
extern MenuTexture D_02005B00[2];
extern MenuTexture D_02005B28[2];
extern MenuTexture D_02005B50[2];
extern MenuTexture D_02005B78[2];
extern MenuTexture D_02005BA0[2];
extern MenuTexture D_02005BC8[2];
extern MenuTexture D_02005BF0[2];
extern MenuTexture D_02005C18[2];
extern MenuTexture D_02005C40[2];
extern MenuTexture D_02005C68[2];
extern MenuTexture D_02005C90[2];
extern MenuTexture D_02005CB8[2];
extern MenuTexture D_02005CE0[2];
extern MenuTexture D_02005D08[2];
extern MenuTexture D_02005D30[2];
extern MenuTexture D_02005D58[2];
extern MenuTexture D_02005D80[2];
extern MenuTexture D_02005DA8[2];
extern MenuTexture D_02005DD0[2];
extern MenuTexture D_02005DF8[2];
extern MenuTexture D_02005E20[2];
extern MenuTexture D_02005E48[2];
extern MenuTexture D_02005E70[2];
extern MenuTexture D_02005E98[2];
extern MenuTexture D_02005EC0[2];
extern MenuTexture D_02005EE8[2];
extern MenuTexture D_02005F10[2];
extern MenuTexture D_02005F38[2];
extern MenuTexture D_02005F60[2];
extern MenuTexture D_02005F88[2];
extern MenuTexture D_02005FB0[2];
extern MenuTexture D_02005FD8[2];
extern MenuTexture D_02006000[2];
extern MenuTexture D_02006028[2];
extern MenuTexture D_02006050[2];
extern MenuTexture D_02006078[2];
extern MenuTexture D_020060A0[2];
extern MenuTexture D_020060C8[2];
extern MenuTexture D_020060F0[2];
extern MenuTexture D_02006118[2];
extern MenuTexture D_02006140[2];
extern MenuTexture D_02006168[2];
extern MenuTexture D_02006190[2];
extern MenuTexture D_020061B8[2];
extern MenuTexture D_020061E0[2];
extern MenuTexture D_02006208[2];
extern MenuTexture D_02006230[2];
extern MenuTexture D_02006258[2];
extern MenuTexture D_02006280[2];
extern MenuTexture D_020062A8[2];
extern MenuTexture D_020062D0[2];
extern MenuTexture D_020062F8[2];
extern MenuTexture D_02006320[2];
extern MenuTexture D_02006348[2];
extern MenuTexture D_02006370[2];
extern MenuTexture D_02006398[2];
extern MenuTexture D_020063C0[2];
extern MenuTexture D_020063E8[2];
extern MenuTexture D_02006410[2];
extern MenuTexture D_02006438[2];
extern MenuTexture D_02006460[2];
extern MenuTexture D_02006488[2];
extern MenuTexture D_020064B0[2];
extern MenuTexture D_020064D8[2];
extern MenuTexture D_02006500[2];
extern MenuTexture D_02006528[2];
extern MenuTexture D_02006550[2];
extern MenuTexture D_02006578[2];
extern MenuTexture D_020065A0[2];
extern MenuTexture D_020065C8[2];
extern MenuTexture D_020065F0[2];
extern MenuTexture D_02006618[2];
extern MenuTexture D_02006640[2];
extern MenuTexture D_02006668[2];
extern MenuTexture D_02006690[2];
extern MenuTexture D_020066B8[2];
extern MenuTexture D_020066E0[2];
extern MkAnimation D_02006708[2];
extern MkAnimation D_02006718[12];
extern MkAnimation D_02006778[2];
extern MkAnimation D_02006788[11];
extern MkAnimation D_020067E0[11];
extern MkAnimation D_02006838[21];
extern MkAnimation D_020068E0[2];
extern MkAnimation D_020068F0[2];
extern MkAnimation D_02006900[12];
extern MkAnimation D_02006960[2];
extern MkAnimation D_02006970[11];
extern MkAnimation D_020069C8[11];
extern MkAnimation D_02006A20[21];
extern MkAnimation D_02006AC8[2];
extern MkAnimation D_02006AD8[2];
extern MkAnimation D_02006AE8[12];
extern MkAnimation D_02006B48[2];
extern MkAnimation D_02006B58[11];
extern MkAnimation D_02006BB0[11];
extern MkAnimation D_02006C08[21];
extern MkAnimation D_02006CB0[2];
extern MkAnimation D_02006CC0[2];
extern MkAnimation D_02006CD0[12];
extern MkAnimation D_02006D30[2];
extern MkAnimation D_02006D40[11];
extern MkAnimation D_02006D98[11];
extern MkAnimation D_02006DF0[21];
extern MkAnimation D_02006E98[2];
extern MkAnimation D_02006EA8[2];
extern MkAnimation D_02006EB8[12];
extern MkAnimation D_02006F18[2];
extern MkAnimation D_02006F28[11];
extern MkAnimation D_02006F80[11];
extern MkAnimation D_02006FD8[21];
extern MkAnimation D_02007080[2];
extern MkAnimation D_02007090[2];
extern MkAnimation D_020070A0[12];
extern MkAnimation D_02007100[2];
extern MkAnimation D_02007110[12];
extern MkAnimation D_02007170[11];
extern MkAnimation D_020071C8[21];
extern MkAnimation D_02007270[2];
extern MkAnimation D_02007280[2];
extern MkAnimation D_02007290[12];
extern MkAnimation D_020072F0[2];
extern MkAnimation D_02007300[11];
extern MkAnimation D_02007358[11];
extern MkAnimation D_020073B0[21];
extern MkAnimation D_02007458[2];
extern MkAnimation D_02007468[2];
extern MkAnimation D_02007478[12];
extern MkAnimation D_020074D8[2];
extern MkAnimation D_020074E8[11];
extern MkAnimation D_02007540[11];
extern MkAnimation D_02007598[21];
extern MkAnimation D_02007640[2];

#endif
