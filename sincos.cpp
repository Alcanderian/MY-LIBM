#include <math.h>
#include <endian.h>

#if !defined(__INTEL_COMPILER) && defined(USE_MY_LIBM)

namespace my_libm {

int
__branred(double x, double *a, double *aa);

typedef int int4;
typedef union { unsigned int u[2]; int4 i[2]; double x; double d; } mynumber;

#define max(x, y)  (((y) > (x)) ? (y) : (x))
#define min(x, y)  (((y) < (x)) ? (y) : (x))

#if (__BYTE_ORDER == __BIG_ENDIAN)

#define HIGH_HALF 0
#define  LOW_HALF 1

static const union {unsigned int u[880]; int4 i[880]; double x[440];} __sincostab = { .u = {
/**/                   0x00000000, 0x00000000,
/**/                   0x00000000, 0x00000000,
/**/                   0x3FF00000, 0x00000000,
/**/                   0x00000000, 0x00000000,
/**/                   0x3F7FFFEA, 0xAAAEEEEF,
/**/                   0xBC1E45E2, 0xEC67B77C,
/**/                   0x3FEFFFC0, 0x00155552,
/**/                   0x3C8F4A01, 0xA0196DAE,
/**/                   0x3F8FFFAA, 0xAAEEEED5,
/**/                   0xBC02AB63, 0x9A9F0777,
/**/                   0x3FEFFF00, 0x0155549F,
/**/                   0x3C828A28, 0xA03A5EF3,
/**/                   0x3F97FF70, 0x01033255,
/**/                   0x3BFEFE2B, 0x51527336,
/**/                   0x3FEFFDC0, 0x06BFF7E6,
/**/                   0x3C8AE6DA, 0xE86977BD,
/**/                   0x3F9FFEAA, 0xAEEEE86F,
/**/                   0xBC3CD406, 0xFB224AE2,
/**/                   0x3FEFFC00, 0x155527D3,
/**/                   0xBC83B544, 0x92D89B5B,
/**/                   0x3FA3FEB2, 0xB12D45D5,
/**/                   0x3C34EC54, 0x203D1C11,
/**/                   0x3FEFF9C0, 0x3414A7BA,
/**/                   0x3C6991F4, 0xBE6C59BF,
/**/                   0x3FA7FDC0, 0x1032FBA9,
/**/                   0xBC4599BD, 0xF46E997A,
/**/                   0x3FEFF700, 0x6BFDF99F,
/**/                   0xBC78B3B5, 0x60648D5F,
/**/                   0x3FABFC6D, 0x78586DAC,
/**/                   0x3C18E4FD, 0x03DBF236,
/**/                   0x3FEFF3C0, 0xC8103A31,
/**/                   0x3C74856D, 0xBDDC0E66,
/**/                   0x3FAFFAAA, 0xEEED4EDB,
/**/                   0xBC42D16D, 0x32684B69,
/**/                   0x3FEFF001, 0x5549F4D3,
/**/                   0x3C832838, 0x7B99426F,
/**/                   0x3FB1FC34, 0x3D808BEF,
/**/                   0xBC5F3D32, 0xE6F3BE4F,
/**/                   0x3FEFEBC2, 0x22A8EF9F,
/**/                   0x3C579349, 0x34F54C77,
/**/                   0x3FB3FACB, 0x12D1755B,
/**/                   0xBC592191, 0x5299468C,
/**/                   0x3FEFE703, 0x4129EF6F,
/**/                   0xBC6CBF43, 0x37C96F97,
/**/                   0x3FB5F911, 0xFD10B737,
/**/                   0xBC50184F, 0x02BE9102,
/**/                   0x3FEFE1C4, 0xC3C873EB,
/**/                   0xBC35A9C9, 0x057C4A02,
/**/                   0x3FB7F701, 0x032550E4,
/**/                   0x3C3AFC2D, 0x1800501A,
/**/                   0x3FEFDC06, 0xBF7E6B9B,
/**/                   0x3C831902, 0xB535F8DB,
/**/                   0x3FB9F490, 0x2D55D1F9,
/**/                   0x3C52696D, 0x7EAC1DC1,
/**/                   0x3FEFD5C9, 0x4B43E000,
/**/                   0xBC62E768, 0xCB4F92F9,
/**/                   0x3FBBF1B7, 0x8568391D,
/**/                   0x3C5E9184, 0x1DEA4CC8,
/**/                   0x3FEFCF0C, 0x800E99B1,
/**/                   0x3C6EA3D7, 0x86D186AC,
/**/                   0x3FBDEE6F, 0x16C1CCE6,
/**/                   0xBC450F8E, 0x2FB71673,
/**/                   0x3FEFC7D0, 0x78D1BC88,
/**/                   0x3C8075D2, 0x447DB685,
/**/                   0x3FBFEAAE, 0xEE86EE36,
/**/                   0xBC4AFCB2, 0xBCC6F03B,
/**/                   0x3FEFC015, 0x527D5BD3,
/**/                   0x3C8B68F3, 0x5094EFB8,
/**/                   0x3FC0F337, 0x8DDD71D1,
/**/                   0x3C6D8468, 0x724F0F9E,
/**/                   0x3FEFB7DB, 0x2BFE0695,
/**/                   0x3C821DAD, 0xF4F65AB1,
/**/                   0x3FC1F0D3, 0xD7AFCEAF,
/**/                   0xBC66EF95, 0x099769A5,
/**/                   0x3FEFAF22, 0x263C4BD3,
/**/                   0xBC552ACE, 0x133A2769,
/**/                   0x3FC2EE28, 0x5E4AB88F,
/**/                   0xBC6E4D0F, 0x05DEE058,
/**/                   0x3FEFA5EA, 0x641C36F2,
/**/                   0x3C404DA6, 0xED17CC7C,
/**/                   0x3FC3EB31, 0x2C5D66CB,
/**/                   0x3C647D66, 0x6B66CB91,
/**/                   0x3FEF9C34, 0x0A7CC428,
/**/                   0x3C8C5B6B, 0x063B7462,
/**/                   0x3FC4E7EA, 0x4DC5F27B,
/**/                   0x3C5949DB, 0x2AC072FC,
/**/                   0x3FEF91FF, 0x40374D01,
/**/                   0xBC67D03F, 0x4D3A9E4C,
/**/                   0x3FC5E44F, 0xCFA126F3,
/**/                   0xBC66F443, 0x063F89B6,
/**/                   0x3FEF874C, 0x2E1EECF6,
/**/                   0xBC8C6514, 0xE1332B16,
/**/                   0x3FC6E05D, 0xC05A4D4C,
/**/                   0xBBD32C5C, 0x8B81C940,
/**/                   0x3FEF7C1A, 0xFEFFDE24,
/**/                   0xBC78F55B, 0xC47540B1,
/**/                   0x3FC7DC10, 0x2FBAF2B5,
/**/                   0x3C45AB50, 0xE23C97C3,
/**/                   0x3FEF706B, 0xDF9ECE1C,
/**/                   0xBC8698C8, 0x0C36DCB4,
/**/                   0x3FC8D763, 0x2EFAA944,
/**/                   0xBC620FA2, 0x62CBB953,
/**/                   0x3FEF643E, 0xFEB82ACD,
/**/                   0x3C76B00A, 0xC1FE28AC,
/**/                   0x3FC9D252, 0xD0CEC312,
/**/                   0x3C59C43D, 0x80B1137D,
/**/                   0x3FEF5794, 0x8CFF6797,
/**/                   0x3C6E3A0D, 0x3E03B1D5,
/**/                   0x3FCACCDB, 0x297A0765,
/**/                   0xBC59883B, 0x57D6CDEB,
/**/                   0x3FEF4A6C, 0xBD1E3A79,
/**/                   0x3C813DF0, 0xEDAEBB57,
/**/                   0x3FCBC6F8, 0x4EDC6199,
/**/                   0x3C69C1A5, 0x6A7B0CAB,
/**/                   0x3FEF3CC7, 0xC3B3D16E,
/**/                   0xBC621A3A, 0xD28A3494,
/**/                   0x3FCCC0A6, 0x588289A3,
/**/                   0xBC6868D0, 0x9BC87C6B,
/**/                   0x3FEF2EA5, 0xD753FFED,
/**/                   0x3C8CC421, 0x5F56D583,
/**/                   0x3FCDB9E1, 0x5FB5A5D0,
/**/                   0xBC632E20, 0xD6CC6FC2,
/**/                   0x3FEF2007, 0x3086649F,
/**/                   0x3C7B9404, 0x16C1984B,
/**/                   0x3FCEB2A5, 0x7F8AE5A3,
/**/                   0xBC60BE06, 0xAF572CEB,
/**/                   0x3FEF10EC, 0x09C5873B,
/**/                   0x3C8D9072, 0x762C1283,
/**/                   0x3FCFAAEE, 0xD4F31577,
/**/                   0xBC615D88, 0x508E32B8,
/**/                   0x3FEF0154, 0x9F7DEEA1,
/**/                   0x3C8D3C1E, 0x99E5CAFD,
/**/                   0x3FD0515C, 0xBF65155C,
/**/                   0xBC79B8C2, 0x9DFD8EC8,
/**/                   0x3FEEF141, 0x300D2F26,
/**/                   0xBC82AA1B, 0x08DED372,
/**/                   0x3FD0CD00, 0xCEF36436,
/**/                   0xBC79FB0A, 0x0C93E2B5,
/**/                   0x3FEEE0B1, 0xFBC0F11C,
/**/                   0xBC4BFD23, 0x80BBC3B1,
/**/                   0x3FD14861, 0xAA94DDEB,
/**/                   0xBC6BE881, 0xB5B615A4,
/**/                   0x3FEECFA7, 0x44D5EFA1,
/**/                   0xBC556D0A, 0x4AF541D0,
/**/                   0x3FD1C37D, 0x64C6B876,
/**/                   0x3C746076, 0xFE0DCFF5,
/**/                   0x3FEEBE21, 0x4F76EFA8,
/**/                   0xBC802F9F, 0x12BA543E,
/**/                   0x3FD23E52, 0x111AAF36,
/**/                   0xBC74F080, 0x334EFF18,
/**/                   0x3FEEAC20, 0x61BBAF4F,
/**/                   0x3C62C1D5, 0x3E94658D,
/**/                   0x3FD2B8DD, 0xC43EB49F,
/**/                   0x3C615538, 0x99F2D807,
/**/                   0x3FEE99A4, 0xC3A7CD83,
/**/                   0xBC82264B, 0x1BC53CE8,
/**/                   0x3FD3331E, 0x94049F87,
/**/                   0x3C7E0CB6, 0xB40C302C,
/**/                   0x3FEE86AE, 0xBF29A9ED,
/**/                   0x3C89397A, 0xFDBB58A7,
/**/                   0x3FD3AD12, 0x9769D3D8,
/**/                   0x3C003D55, 0x04878398,
/**/                   0x3FEE733E, 0xA0193D40,
/**/                   0xBC86428B, 0x3546CE13,
/**/                   0x3FD426B7, 0xE69EE697,
/**/                   0xBC7F09C7, 0x5705C59F,
/**/                   0x3FEE5F54, 0xB436E9D0,
/**/                   0x3C87EB0F, 0xD02FC8BC,
/**/                   0x3FD4A00C, 0x9B0F3D20,
/**/                   0x3C7823BA, 0x6BB08EAD,
/**/                   0x3FEE4AF1, 0x4B2A449C,
/**/                   0xBC868CA0, 0x2E8A6833,
/**/                   0x3FD5190E, 0xCF68A77A,
/**/                   0x3C7B3571, 0x55EEF0F3,
/**/                   0x3FEE3614, 0xB680D6A5,
/**/                   0xBC727793, 0xAA015237,
/**/                   0x3FD591BC, 0x9FA2F597,
/**/                   0x3C67C74B, 0xAC3FE0CB,
/**/                   0x3FEE20BF, 0x49ACD6C1,
/**/                   0xBC5660AE, 0xC7EF636C,
/**/                   0x3FD60A14, 0x29078775,
/**/                   0x3C5B1FD8, 0x0BA89133,
/**/                   0x3FEE0AF1, 0x5A03DBCE,
/**/                   0x3C5FE8E7, 0x02771AE6,
/**/                   0x3FD68213, 0x8A38D7F7,
/**/                   0xBC7D8892, 0x02444AAD,
/**/                   0x3FEDF4AB, 0x3EBD875E,
/**/                   0xBC8E2D8A, 0x7E6736C4,
/**/                   0x3FD6F9B8, 0xE33A0255,
/**/                   0x3C742BC1, 0x4EE9DA0D,
/**/                   0x3FEDDDED, 0x50F228D6,
/**/                   0xBC6E80C8, 0xD42BA2BF,
/**/                   0x3FD77102, 0x55764214,
/**/                   0xBC66EAD7, 0x314BB6CE,
/**/                   0x3FEDC6B7, 0xEB995912,
/**/                   0x3C54B364, 0x776DCD35,
/**/                   0x3FD7E7EE, 0x03C86D4E,
/**/                   0xBC7B63BC, 0xDABF5AF2,
/**/                   0x3FEDAF0B, 0x6B888E83,
/**/                   0x3C8A249E, 0x2B5E5CEA,
/**/                   0x3FD85E7A, 0x12826949,
/**/                   0x3C78A40E, 0x9B5FACE0,
/**/                   0x3FED96E8, 0x2F71A9DC,
/**/                   0x3C8FF61B, 0xD5D2039D,
/**/                   0x3FD8D4A4, 0xA774992F,
/**/                   0x3C744A02, 0xEA766326,
/**/                   0x3FED7E4E, 0x97E17B4A,
/**/                   0xBC63B770, 0x352BED94,
/**/                   0x3FD94A6B, 0xE9F546C5,
/**/                   0xBC769CE1, 0x3E683F58,
/**/                   0x3FED653F, 0x073E4040,
/**/                   0xBC876236, 0x434BEC37,
/**/                   0x3FD9BFCE, 0x02E80510,
/**/                   0x3C709E39, 0xA320B0A4,
/**/                   0x3FED4BB9, 0xE1C619E0,
/**/                   0x3C8F34BB, 0x77858F61,
/**/                   0x3FDA34C9, 0x1CC50CCA,
/**/                   0xBC5A310E, 0x3B50CECD,
/**/                   0x3FED31BF, 0x8D8D7C06,
/**/                   0x3C7E60DD, 0x3089CBDD,
/**/                   0x3FDAA95B, 0x63A09277,
/**/                   0xBC66293E, 0xB13C0381,
/**/                   0x3FED1750, 0x727D94F0,
/**/                   0x3C80D52B, 0x1EC1A48E,
/**/                   0x3FDB1D83, 0x05321617,
/**/                   0xBC7AE242, 0xCB99F519,
/**/                   0x3FECFC6C, 0xFA52AD9F,
/**/                   0x3C88B5B5, 0x508F2A0D,
/**/                   0x3FDB913E, 0x30DBAC43,
/**/                   0xBC7E38AD, 0x2F6C3FF1,
/**/                   0x3FECE115, 0x909A82E5,
/**/                   0x3C81F139, 0xBB31109A,
/**/                   0x3FDC048B, 0x17B140A3,
/**/                   0x3C619FE6, 0x757E9FA7,
/**/                   0x3FECC54A, 0xA2B2972E,
/**/                   0x3C64EE16, 0x2BA83A98,
/**/                   0x3FDC7767, 0xEC7FD19E,
/**/                   0xBC5EB14D, 0x1A3D5826,
/**/                   0x3FECA90C, 0x9FC67D0B,
/**/                   0xBC646A81, 0x485E3462,
/**/                   0x3FDCE9D2, 0xE3D4A51F,
/**/                   0xBC62FC8A, 0x12DAE298,
/**/                   0x3FEC8C5B, 0xF8CE1A84,
/**/                   0x3C7AB3D1, 0xA1590123,
/**/                   0x3FDD5BCA, 0x34047661,
/**/                   0x3C728A44, 0xA75FC29C,
/**/                   0x3FEC6F39, 0x208BE53B,
/**/                   0xBC8741DB, 0xFBAADB42,
/**/                   0x3FDDCD4C, 0x15329C9A,
/**/                   0x3C70D4C6, 0xE171FD9A,
/**/                   0x3FEC51A4, 0x8B8B175E,
/**/                   0xBC61BBB4, 0x3B9AA880,
/**/                   0x3FDE3E56, 0xC1582A69,
/**/                   0xBC50A482, 0x1099F88F,
/**/                   0x3FEC339E, 0xB01DDD81,
/**/                   0xBC8CAAF5, 0xEE82C5C0,
/**/                   0x3FDEAEE8, 0x744B05F0,
/**/                   0xBC5789B4, 0x3C9B027D,
/**/                   0x3FEC1528, 0x065B7D50,
/**/                   0xBC889211, 0x1312E828,
/**/                   0x3FDF1EFF, 0x6BC4F97B,
/**/                   0x3C717212, 0xF8A7525C,
/**/                   0x3FEBF641, 0x081E7536,
/**/                   0x3C8B7BD7, 0x1628A9A1,
/**/                   0x3FDF8E99, 0xE76ABC97,
/**/                   0x3C59D950, 0xAF2D00A3,
/**/                   0x3FEBD6EA, 0x310294F5,
/**/                   0x3C731BBC, 0xC88C109D,
/**/                   0x3FDFFDB6, 0x28D2F57A,
/**/                   0x3C6F4A99, 0x2E905B6A,
/**/                   0x3FEBB723, 0xFE630F32,
/**/                   0x3C772BD2, 0x452D0A39,
/**/                   0x3FE03629, 0x39C69955,
/**/                   0xBC82D8CD, 0x78397B01,
/**/                   0x3FEB96EE, 0xEF58840E,
/**/                   0x3C545A3C, 0xC78FADE0,
/**/                   0x3FE06D36, 0x86946E5B,
/**/                   0x3C83F5AE, 0x4538FF1B,
/**/                   0x3FEB764B, 0x84B704C2,
/**/                   0xBC8F5848, 0xC21B389B,
/**/                   0x3FE0A402, 0x1E9E1001,
/**/                   0xBC86F643, 0xA13914F6,
/**/                   0x3FEB553A, 0x410C104E,
/**/                   0x3C58FF79, 0x47027A16,
/**/                   0x3FE0DA8B, 0x26B5672E,
/**/                   0xBC8A58DE, 0xF0BEE909,
/**/                   0x3FEB33BB, 0xA89C8948,
/**/                   0x3C8EA6A5, 0x1D1F6CA9,
/**/                   0x3FE110D0, 0xC4B69C3B,
/**/                   0x3C8D9189, 0x98809981,
/**/                   0x3FEB11D0, 0x4162A4C6,
/**/                   0x3C71DD56, 0x1EFBC0C2,
/**/                   0x3FE146D2, 0x1F8B7F82,
/**/                   0x3C7BF953, 0x5E2739A8,
/**/                   0x3FEAEF78, 0x930BD275,
/**/                   0xBC7F8362, 0x79746F94,
/**/                   0x3FE17C8E, 0x5F2EEDB0,
/**/                   0x3C635E57, 0x102E2488,
/**/                   0x3FEACCB5, 0x26F69DE5,
/**/                   0x3C88FB6A, 0x8DD6B6CC,
/**/                   0x3FE1B204, 0xACB02FDD,
/**/                   0xBC5F190C, 0x70CBB5FF,
/**/                   0x3FEAA986, 0x88308913,
/**/                   0xBC0B83D6, 0x07CD5070,
/**/                   0x3FE1E734, 0x3236574C,
/**/                   0x3C722A3F, 0xA4F41D5A,
/**/                   0x3FEA85ED, 0x4373E02D,
/**/                   0x3C69BE06, 0x385EC792,
/**/                   0x3FE21C1C, 0x1B0394CF,
/**/                   0x3C5E5B32, 0x4B23AA31,
/**/                   0x3FEA61E9, 0xE72586AF,
/**/                   0x3C858330, 0xE2FD453F,
/**/                   0x3FE250BB, 0x93788BBB,
/**/                   0x3C7EA3D0, 0x2457BCCE,
/**/                   0x3FEA3D7D, 0x0352BDCF,
/**/                   0xBC868DBA, 0xECA19669,
/**/                   0x3FE28511, 0xC917A067,
/**/                   0xBC801DF1, 0xD9A16B70,
/**/                   0x3FEA18A7, 0x29AEE445,
/**/                   0x3C395E25, 0x736C0358,
/**/                   0x3FE2B91D, 0xEA88421E,
/**/                   0xBC8FA371, 0xDB216AB0,
/**/                   0x3FE9F368, 0xED912F85,
/**/                   0xBC81D200, 0xC5791606,
/**/                   0x3FE2ECDF, 0x279A3082,
/**/                   0x3C8D3557, 0xE0E7E37E,
/**/                   0x3FE9CDC2, 0xE3F25E5C,
/**/                   0x3C83F991, 0x12993F62,
/**/                   0x3FE32054, 0xB148BC4F,
/**/                   0x3C8F6B42, 0x095A135B,
/**/                   0x3FE9A7B5, 0xA36A6514,
/**/                   0x3C8722CF, 0xCC9FA7A9,
/**/                   0x3FE3537D, 0xB9BE0367,
/**/                   0x3C6B327E, 0x7AF040F0,
/**/                   0x3FE98141, 0xC42E1310,
/**/                   0x3C8D1FF8, 0x0488F08D,
/**/                   0x3FE38659, 0x7456282B,
/**/                   0xBC710FAD, 0xA93B07A8,
/**/                   0x3FE95A67, 0xE00CB1FD,
/**/                   0xBC80BEFD, 0xA21F862D,
/**/                   0x3FE3B8E7, 0x15A2840A,
/**/                   0xBC797653, 0xA7D2F07B,
/**/                   0x3FE93328, 0x926D9E92,
/**/                   0xBC8BB770, 0x03600CDA,
/**/                   0x3FE3EB25, 0xD36CD53A,
/**/                   0xBC5BE570, 0xE1570FC0,
/**/                   0x3FE90B84, 0x784DDAF7,
/**/                   0xBC70FEB1, 0x0AB93B87,
/**/                   0x3FE41D14, 0xE4BA6790,
/**/                   0x3C84608F, 0xD287ECF5,
/**/                   0x3FE8E37C, 0x303D9AD1,
/**/                   0xBC6463A4, 0xB53D4BF8,
/**/                   0x3FE44EB3, 0x81CF386B,
/**/                   0xBC83ED6C, 0x1E6A5505,
/**/                   0x3FE8BB10, 0x5A5DC900,
/**/                   0x3C8863E0, 0x3E9474C1,
/**/                   0x3FE48000, 0xE431159F,
/**/                   0xBC8B194A, 0x7463ED10,
/**/                   0x3FE89241, 0x985D871F,
/**/                   0x3C8C48D9, 0xC413ED84,
/**/                   0x3FE4B0FC, 0x46AAB761,
/**/                   0x3C20DA05, 0x738CC59A,
/**/                   0x3FE86910, 0x8D77A6C6,
/**/                   0x3C7338FF, 0xE2BFE9DD,
/**/                   0x3FE4E1A4, 0xE54ED51B,
/**/                   0xBC8A492F, 0x89B7C76A,
/**/                   0x3FE83F7D, 0xDE701CA0,
/**/                   0xBC4152CF, 0x609BC6E8,
/**/                   0x3FE511F9, 0xFD7B351C,
/**/                   0xBC85C0E8, 0x61C48831,
/**/                   0x3FE8158A, 0x31916D5D,
/**/                   0xBC6DE8B9, 0x0B8228DE,
/**/                   0x3FE541FA, 0xCDDBB724,
/**/                   0x3C7232C2, 0x8520D391,
/**/                   0x3FE7EB36, 0x2EAA1488,
/**/                   0x3C5A1D65, 0xA4A5959F,
/**/                   0x3FE571A6, 0x966D59B3,
/**/                   0x3C5C843B, 0x4D0FB198,
/**/                   0x3FE7C082, 0x7F09E54F,
/**/                   0xBC6C73D6, 0xD72AEE68,
/**/                   0x3FE5A0FC, 0x98813A12,
/**/                   0xBC8D82E2, 0xB7D4227B,
/**/                   0x3FE7956F, 0xCD7F6543,
/**/                   0xBC8AB276, 0xE9D45AE4,
/**/                   0x3FE5CFFC, 0x16BF8F0D,
/**/                   0x3C896CB3, 0x70EB578A,
/**/                   0x3FE769FE, 0xC655211F,
/**/                   0xBC6827D5, 0xCF8C68C5,
/**/                   0x3FE5FEA4, 0x552A9E57,
/**/                   0x3C80B6CE, 0xF7EE20B7,
/**/                   0x3FE73E30, 0x174EFBA1,
/**/                   0xBC65D3AE, 0x3D94AD5F,
/**/                   0x3FE62CF4, 0x9921AC79,
/**/                   0xBC8EDD98, 0x55B6241A,
/**/                   0x3FE71204, 0x6FA77678,
/**/                   0x3C8425B0, 0xA5029C81,
/**/                   0x3FE65AEC, 0x2963E755,
/**/                   0x3C8126F9, 0x6B71053C,
/**/                   0x3FE6E57C, 0x800CF55E,
/**/                   0x3C860286, 0xDEDBD0A6,
/**/                   0x3FE6888A, 0x4E134B2F,
/**/                   0xBC86B7D3, 0x7644D5E6,
/**/                   0x3FE6B898, 0xFA9EFB5D,
/**/                   0x3C715AC7, 0x86CCF4B2,
/**/                   0x3FE6B5CE, 0x50B7821A,
/**/                   0xBC65D515, 0x8F702E0F,
/**/                   0x3FE68B5A, 0x92EB6253,
/**/                   0xBC89A91A, 0xD985F89C,
/**/                   0x3FE6E2B7, 0x7C40BDE1,
/**/                   0xBC70E729, 0x857FAD53,
/**/                   0x3FE65DC1, 0xFDEB8CBA,
/**/                   0xBC597C1B, 0x47337C77,
/**/                   0x3FE70F45, 0x1D0A8C40,
/**/                   0x3C697EDE, 0x3885770D,
/**/                   0x3FE62FCF, 0xF20191C7,
/**/                   0x3C6D9143, 0x895756EF,
/**/                   0x3FE73B76, 0x80DEA578,
/**/                   0xBC722483, 0x06DC12A2,
/**/                   0x3FE60185, 0x26F563DF,
/**/                   0x3C846CA5, 0xE0E432D0,
/**/                   0x3FE7674A, 0xF6F7B524,
/**/                   0x3C7E9D3F, 0x94AC84A8,
/**/                   0x3FE5D2E2, 0x55F1F17A,
/**/                   0x3C803141, 0x04C8892B,
/**/                   0x3FE792C1, 0xD0041D52,
/**/                   0xBC8ABF05, 0xEEB354EB,
/**/                   0x3FE5A3E8, 0x39824077,
/**/                   0x3C8428AA, 0x2759BE62,
/**/                   0x3FE7BDDA, 0x5E28B3C2,
/**/                   0x3C4AD119, 0x7CCD0393,
/**/                   0x3FE57497, 0x8D8E83F2,
/**/                   0x3C8F4714, 0xAF282D23,
/**/                   0x3FE7E893, 0xF5037959,
/**/                   0x3C80EEFB, 0xAA650C4C,
/**/                   0x3FE544F1, 0x0F592CA5,
/**/                   0xBC8E7AE8, 0xE6C7A62F,
/**/                   0x3FE812ED, 0xE9AE4BA4,
/**/                   0xBC87830A, 0xDF402DDA,
/**/                   0x3FE514F5, 0x7D7BF3DA,
/**/                   0x3C747A10, 0x8073C259 } };

#endif

#if (__BYTE_ORDER == __LITTLE_ENDIAN)

#define HIGH_HALF 1
#define  LOW_HALF 0

static const union {unsigned int u[880]; int4 i[880]; double x[440];} __sincostab = { .u = {
/**/                   0x00000000, 0x00000000,
/**/                   0x00000000, 0x00000000,
/**/                   0x00000000, 0x3FF00000,
/**/                   0x00000000, 0x00000000,
/**/                   0xAAAEEEEF, 0x3F7FFFEA,
/**/                   0xEC67B77C, 0xBC1E45E2,
/**/                   0x00155552, 0x3FEFFFC0,
/**/                   0xA0196DAE, 0x3C8F4A01,
/**/                   0xAAEEEED5, 0x3F8FFFAA,
/**/                   0x9A9F0777, 0xBC02AB63,
/**/                   0x0155549F, 0x3FEFFF00,
/**/                   0xA03A5EF3, 0x3C828A28,
/**/                   0x01033255, 0x3F97FF70,
/**/                   0x51527336, 0x3BFEFE2B,
/**/                   0x06BFF7E6, 0x3FEFFDC0,
/**/                   0xE86977BD, 0x3C8AE6DA,
/**/                   0xAEEEE86F, 0x3F9FFEAA,
/**/                   0xFB224AE2, 0xBC3CD406,
/**/                   0x155527D3, 0x3FEFFC00,
/**/                   0x92D89B5B, 0xBC83B544,
/**/                   0xB12D45D5, 0x3FA3FEB2,
/**/                   0x203D1C11, 0x3C34EC54,
/**/                   0x3414A7BA, 0x3FEFF9C0,
/**/                   0xBE6C59BF, 0x3C6991F4,
/**/                   0x1032FBA9, 0x3FA7FDC0,
/**/                   0xF46E997A, 0xBC4599BD,
/**/                   0x6BFDF99F, 0x3FEFF700,
/**/                   0x60648D5F, 0xBC78B3B5,
/**/                   0x78586DAC, 0x3FABFC6D,
/**/                   0x03DBF236, 0x3C18E4FD,
/**/                   0xC8103A31, 0x3FEFF3C0,
/**/                   0xBDDC0E66, 0x3C74856D,
/**/                   0xEEED4EDB, 0x3FAFFAAA,
/**/                   0x32684B69, 0xBC42D16D,
/**/                   0x5549F4D3, 0x3FEFF001,
/**/                   0x7B99426F, 0x3C832838,
/**/                   0x3D808BEF, 0x3FB1FC34,
/**/                   0xE6F3BE4F, 0xBC5F3D32,
/**/                   0x22A8EF9F, 0x3FEFEBC2,
/**/                   0x34F54C77, 0x3C579349,
/**/                   0x12D1755B, 0x3FB3FACB,
/**/                   0x5299468C, 0xBC592191,
/**/                   0x4129EF6F, 0x3FEFE703,
/**/                   0x37C96F97, 0xBC6CBF43,
/**/                   0xFD10B737, 0x3FB5F911,
/**/                   0x02BE9102, 0xBC50184F,
/**/                   0xC3C873EB, 0x3FEFE1C4,
/**/                   0x057C4A02, 0xBC35A9C9,
/**/                   0x032550E4, 0x3FB7F701,
/**/                   0x1800501A, 0x3C3AFC2D,
/**/                   0xBF7E6B9B, 0x3FEFDC06,
/**/                   0xB535F8DB, 0x3C831902,
/**/                   0x2D55D1F9, 0x3FB9F490,
/**/                   0x7EAC1DC1, 0x3C52696D,
/**/                   0x4B43E000, 0x3FEFD5C9,
/**/                   0xCB4F92F9, 0xBC62E768,
/**/                   0x8568391D, 0x3FBBF1B7,
/**/                   0x1DEA4CC8, 0x3C5E9184,
/**/                   0x800E99B1, 0x3FEFCF0C,
/**/                   0x86D186AC, 0x3C6EA3D7,
/**/                   0x16C1CCE6, 0x3FBDEE6F,
/**/                   0x2FB71673, 0xBC450F8E,
/**/                   0x78D1BC88, 0x3FEFC7D0,
/**/                   0x447DB685, 0x3C8075D2,
/**/                   0xEE86EE36, 0x3FBFEAAE,
/**/                   0xBCC6F03B, 0xBC4AFCB2,
/**/                   0x527D5BD3, 0x3FEFC015,
/**/                   0x5094EFB8, 0x3C8B68F3,
/**/                   0x8DDD71D1, 0x3FC0F337,
/**/                   0x724F0F9E, 0x3C6D8468,
/**/                   0x2BFE0695, 0x3FEFB7DB,
/**/                   0xF4F65AB1, 0x3C821DAD,
/**/                   0xD7AFCEAF, 0x3FC1F0D3,
/**/                   0x099769A5, 0xBC66EF95,
/**/                   0x263C4BD3, 0x3FEFAF22,
/**/                   0x133A2769, 0xBC552ACE,
/**/                   0x5E4AB88F, 0x3FC2EE28,
/**/                   0x05DEE058, 0xBC6E4D0F,
/**/                   0x641C36F2, 0x3FEFA5EA,
/**/                   0xED17CC7C, 0x3C404DA6,
/**/                   0x2C5D66CB, 0x3FC3EB31,
/**/                   0x6B66CB91, 0x3C647D66,
/**/                   0x0A7CC428, 0x3FEF9C34,
/**/                   0x063B7462, 0x3C8C5B6B,
/**/                   0x4DC5F27B, 0x3FC4E7EA,
/**/                   0x2AC072FC, 0x3C5949DB,
/**/                   0x40374D01, 0x3FEF91FF,
/**/                   0x4D3A9E4C, 0xBC67D03F,
/**/                   0xCFA126F3, 0x3FC5E44F,
/**/                   0x063F89B6, 0xBC66F443,
/**/                   0x2E1EECF6, 0x3FEF874C,
/**/                   0xE1332B16, 0xBC8C6514,
/**/                   0xC05A4D4C, 0x3FC6E05D,
/**/                   0x8B81C940, 0xBBD32C5C,
/**/                   0xFEFFDE24, 0x3FEF7C1A,
/**/                   0xC47540B1, 0xBC78F55B,
/**/                   0x2FBAF2B5, 0x3FC7DC10,
/**/                   0xE23C97C3, 0x3C45AB50,
/**/                   0xDF9ECE1C, 0x3FEF706B,
/**/                   0x0C36DCB4, 0xBC8698C8,
/**/                   0x2EFAA944, 0x3FC8D763,
/**/                   0x62CBB953, 0xBC620FA2,
/**/                   0xFEB82ACD, 0x3FEF643E,
/**/                   0xC1FE28AC, 0x3C76B00A,
/**/                   0xD0CEC312, 0x3FC9D252,
/**/                   0x80B1137D, 0x3C59C43D,
/**/                   0x8CFF6797, 0x3FEF5794,
/**/                   0x3E03B1D5, 0x3C6E3A0D,
/**/                   0x297A0765, 0x3FCACCDB,
/**/                   0x57D6CDEB, 0xBC59883B,
/**/                   0xBD1E3A79, 0x3FEF4A6C,
/**/                   0xEDAEBB57, 0x3C813DF0,
/**/                   0x4EDC6199, 0x3FCBC6F8,
/**/                   0x6A7B0CAB, 0x3C69C1A5,
/**/                   0xC3B3D16E, 0x3FEF3CC7,
/**/                   0xD28A3494, 0xBC621A3A,
/**/                   0x588289A3, 0x3FCCC0A6,
/**/                   0x9BC87C6B, 0xBC6868D0,
/**/                   0xD753FFED, 0x3FEF2EA5,
/**/                   0x5F56D583, 0x3C8CC421,
/**/                   0x5FB5A5D0, 0x3FCDB9E1,
/**/                   0xD6CC6FC2, 0xBC632E20,
/**/                   0x3086649F, 0x3FEF2007,
/**/                   0x16C1984B, 0x3C7B9404,
/**/                   0x7F8AE5A3, 0x3FCEB2A5,
/**/                   0xAF572CEB, 0xBC60BE06,
/**/                   0x09C5873B, 0x3FEF10EC,
/**/                   0x762C1283, 0x3C8D9072,
/**/                   0xD4F31577, 0x3FCFAAEE,
/**/                   0x508E32B8, 0xBC615D88,
/**/                   0x9F7DEEA1, 0x3FEF0154,
/**/                   0x99E5CAFD, 0x3C8D3C1E,
/**/                   0xBF65155C, 0x3FD0515C,
/**/                   0x9DFD8EC8, 0xBC79B8C2,
/**/                   0x300D2F26, 0x3FEEF141,
/**/                   0x08DED372, 0xBC82AA1B,
/**/                   0xCEF36436, 0x3FD0CD00,
/**/                   0x0C93E2B5, 0xBC79FB0A,
/**/                   0xFBC0F11C, 0x3FEEE0B1,
/**/                   0x80BBC3B1, 0xBC4BFD23,
/**/                   0xAA94DDEB, 0x3FD14861,
/**/                   0xB5B615A4, 0xBC6BE881,
/**/                   0x44D5EFA1, 0x3FEECFA7,
/**/                   0x4AF541D0, 0xBC556D0A,
/**/                   0x64C6B876, 0x3FD1C37D,
/**/                   0xFE0DCFF5, 0x3C746076,
/**/                   0x4F76EFA8, 0x3FEEBE21,
/**/                   0x12BA543E, 0xBC802F9F,
/**/                   0x111AAF36, 0x3FD23E52,
/**/                   0x334EFF18, 0xBC74F080,
/**/                   0x61BBAF4F, 0x3FEEAC20,
/**/                   0x3E94658D, 0x3C62C1D5,
/**/                   0xC43EB49F, 0x3FD2B8DD,
/**/                   0x99F2D807, 0x3C615538,
/**/                   0xC3A7CD83, 0x3FEE99A4,
/**/                   0x1BC53CE8, 0xBC82264B,
/**/                   0x94049F87, 0x3FD3331E,
/**/                   0xB40C302C, 0x3C7E0CB6,
/**/                   0xBF29A9ED, 0x3FEE86AE,
/**/                   0xFDBB58A7, 0x3C89397A,
/**/                   0x9769D3D8, 0x3FD3AD12,
/**/                   0x04878398, 0x3C003D55,
/**/                   0xA0193D40, 0x3FEE733E,
/**/                   0x3546CE13, 0xBC86428B,
/**/                   0xE69EE697, 0x3FD426B7,
/**/                   0x5705C59F, 0xBC7F09C7,
/**/                   0xB436E9D0, 0x3FEE5F54,
/**/                   0xD02FC8BC, 0x3C87EB0F,
/**/                   0x9B0F3D20, 0x3FD4A00C,
/**/                   0x6BB08EAD, 0x3C7823BA,
/**/                   0x4B2A449C, 0x3FEE4AF1,
/**/                   0x2E8A6833, 0xBC868CA0,
/**/                   0xCF68A77A, 0x3FD5190E,
/**/                   0x55EEF0F3, 0x3C7B3571,
/**/                   0xB680D6A5, 0x3FEE3614,
/**/                   0xAA015237, 0xBC727793,
/**/                   0x9FA2F597, 0x3FD591BC,
/**/                   0xAC3FE0CB, 0x3C67C74B,
/**/                   0x49ACD6C1, 0x3FEE20BF,
/**/                   0xC7EF636C, 0xBC5660AE,
/**/                   0x29078775, 0x3FD60A14,
/**/                   0x0BA89133, 0x3C5B1FD8,
/**/                   0x5A03DBCE, 0x3FEE0AF1,
/**/                   0x02771AE6, 0x3C5FE8E7,
/**/                   0x8A38D7F7, 0x3FD68213,
/**/                   0x02444AAD, 0xBC7D8892,
/**/                   0x3EBD875E, 0x3FEDF4AB,
/**/                   0x7E6736C4, 0xBC8E2D8A,
/**/                   0xE33A0255, 0x3FD6F9B8,
/**/                   0x4EE9DA0D, 0x3C742BC1,
/**/                   0x50F228D6, 0x3FEDDDED,
/**/                   0xD42BA2BF, 0xBC6E80C8,
/**/                   0x55764214, 0x3FD77102,
/**/                   0x314BB6CE, 0xBC66EAD7,
/**/                   0xEB995912, 0x3FEDC6B7,
/**/                   0x776DCD35, 0x3C54B364,
/**/                   0x03C86D4E, 0x3FD7E7EE,
/**/                   0xDABF5AF2, 0xBC7B63BC,
/**/                   0x6B888E83, 0x3FEDAF0B,
/**/                   0x2B5E5CEA, 0x3C8A249E,
/**/                   0x12826949, 0x3FD85E7A,
/**/                   0x9B5FACE0, 0x3C78A40E,
/**/                   0x2F71A9DC, 0x3FED96E8,
/**/                   0xD5D2039D, 0x3C8FF61B,
/**/                   0xA774992F, 0x3FD8D4A4,
/**/                   0xEA766326, 0x3C744A02,
/**/                   0x97E17B4A, 0x3FED7E4E,
/**/                   0x352BED94, 0xBC63B770,
/**/                   0xE9F546C5, 0x3FD94A6B,
/**/                   0x3E683F58, 0xBC769CE1,
/**/                   0x073E4040, 0x3FED653F,
/**/                   0x434BEC37, 0xBC876236,
/**/                   0x02E80510, 0x3FD9BFCE,
/**/                   0xA320B0A4, 0x3C709E39,
/**/                   0xE1C619E0, 0x3FED4BB9,
/**/                   0x77858F61, 0x3C8F34BB,
/**/                   0x1CC50CCA, 0x3FDA34C9,
/**/                   0x3B50CECD, 0xBC5A310E,
/**/                   0x8D8D7C06, 0x3FED31BF,
/**/                   0x3089CBDD, 0x3C7E60DD,
/**/                   0x63A09277, 0x3FDAA95B,
/**/                   0xB13C0381, 0xBC66293E,
/**/                   0x727D94F0, 0x3FED1750,
/**/                   0x1EC1A48E, 0x3C80D52B,
/**/                   0x05321617, 0x3FDB1D83,
/**/                   0xCB99F519, 0xBC7AE242,
/**/                   0xFA52AD9F, 0x3FECFC6C,
/**/                   0x508F2A0D, 0x3C88B5B5,
/**/                   0x30DBAC43, 0x3FDB913E,
/**/                   0x2F6C3FF1, 0xBC7E38AD,
/**/                   0x909A82E5, 0x3FECE115,
/**/                   0xBB31109A, 0x3C81F139,
/**/                   0x17B140A3, 0x3FDC048B,
/**/                   0x757E9FA7, 0x3C619FE6,
/**/                   0xA2B2972E, 0x3FECC54A,
/**/                   0x2BA83A98, 0x3C64EE16,
/**/                   0xEC7FD19E, 0x3FDC7767,
/**/                   0x1A3D5826, 0xBC5EB14D,
/**/                   0x9FC67D0B, 0x3FECA90C,
/**/                   0x485E3462, 0xBC646A81,
/**/                   0xE3D4A51F, 0x3FDCE9D2,
/**/                   0x12DAE298, 0xBC62FC8A,
/**/                   0xF8CE1A84, 0x3FEC8C5B,
/**/                   0xA1590123, 0x3C7AB3D1,
/**/                   0x34047661, 0x3FDD5BCA,
/**/                   0xA75FC29C, 0x3C728A44,
/**/                   0x208BE53B, 0x3FEC6F39,
/**/                   0xFBAADB42, 0xBC8741DB,
/**/                   0x15329C9A, 0x3FDDCD4C,
/**/                   0xE171FD9A, 0x3C70D4C6,
/**/                   0x8B8B175E, 0x3FEC51A4,
/**/                   0x3B9AA880, 0xBC61BBB4,
/**/                   0xC1582A69, 0x3FDE3E56,
/**/                   0x1099F88F, 0xBC50A482,
/**/                   0xB01DDD81, 0x3FEC339E,
/**/                   0xEE82C5C0, 0xBC8CAAF5,
/**/                   0x744B05F0, 0x3FDEAEE8,
/**/                   0x3C9B027D, 0xBC5789B4,
/**/                   0x065B7D50, 0x3FEC1528,
/**/                   0x1312E828, 0xBC889211,
/**/                   0x6BC4F97B, 0x3FDF1EFF,
/**/                   0xF8A7525C, 0x3C717212,
/**/                   0x081E7536, 0x3FEBF641,
/**/                   0x1628A9A1, 0x3C8B7BD7,
/**/                   0xE76ABC97, 0x3FDF8E99,
/**/                   0xAF2D00A3, 0x3C59D950,
/**/                   0x310294F5, 0x3FEBD6EA,
/**/                   0xC88C109D, 0x3C731BBC,
/**/                   0x28D2F57A, 0x3FDFFDB6,
/**/                   0x2E905B6A, 0x3C6F4A99,
/**/                   0xFE630F32, 0x3FEBB723,
/**/                   0x452D0A39, 0x3C772BD2,
/**/                   0x39C69955, 0x3FE03629,
/**/                   0x78397B01, 0xBC82D8CD,
/**/                   0xEF58840E, 0x3FEB96EE,
/**/                   0xC78FADE0, 0x3C545A3C,
/**/                   0x86946E5B, 0x3FE06D36,
/**/                   0x4538FF1B, 0x3C83F5AE,
/**/                   0x84B704C2, 0x3FEB764B,
/**/                   0xC21B389B, 0xBC8F5848,
/**/                   0x1E9E1001, 0x3FE0A402,
/**/                   0xA13914F6, 0xBC86F643,
/**/                   0x410C104E, 0x3FEB553A,
/**/                   0x47027A16, 0x3C58FF79,
/**/                   0x26B5672E, 0x3FE0DA8B,
/**/                   0xF0BEE909, 0xBC8A58DE,
/**/                   0xA89C8948, 0x3FEB33BB,
/**/                   0x1D1F6CA9, 0x3C8EA6A5,
/**/                   0xC4B69C3B, 0x3FE110D0,
/**/                   0x98809981, 0x3C8D9189,
/**/                   0x4162A4C6, 0x3FEB11D0,
/**/                   0x1EFBC0C2, 0x3C71DD56,
/**/                   0x1F8B7F82, 0x3FE146D2,
/**/                   0x5E2739A8, 0x3C7BF953,
/**/                   0x930BD275, 0x3FEAEF78,
/**/                   0x79746F94, 0xBC7F8362,
/**/                   0x5F2EEDB0, 0x3FE17C8E,
/**/                   0x102E2488, 0x3C635E57,
/**/                   0x26F69DE5, 0x3FEACCB5,
/**/                   0x8DD6B6CC, 0x3C88FB6A,
/**/                   0xACB02FDD, 0x3FE1B204,
/**/                   0x70CBB5FF, 0xBC5F190C,
/**/                   0x88308913, 0x3FEAA986,
/**/                   0x07CD5070, 0xBC0B83D6,
/**/                   0x3236574C, 0x3FE1E734,
/**/                   0xA4F41D5A, 0x3C722A3F,
/**/                   0x4373E02D, 0x3FEA85ED,
/**/                   0x385EC792, 0x3C69BE06,
/**/                   0x1B0394CF, 0x3FE21C1C,
/**/                   0x4B23AA31, 0x3C5E5B32,
/**/                   0xE72586AF, 0x3FEA61E9,
/**/                   0xE2FD453F, 0x3C858330,
/**/                   0x93788BBB, 0x3FE250BB,
/**/                   0x2457BCCE, 0x3C7EA3D0,
/**/                   0x0352BDCF, 0x3FEA3D7D,
/**/                   0xECA19669, 0xBC868DBA,
/**/                   0xC917A067, 0x3FE28511,
/**/                   0xD9A16B70, 0xBC801DF1,
/**/                   0x29AEE445, 0x3FEA18A7,
/**/                   0x736C0358, 0x3C395E25,
/**/                   0xEA88421E, 0x3FE2B91D,
/**/                   0xDB216AB0, 0xBC8FA371,
/**/                   0xED912F85, 0x3FE9F368,
/**/                   0xC5791606, 0xBC81D200,
/**/                   0x279A3082, 0x3FE2ECDF,
/**/                   0xE0E7E37E, 0x3C8D3557,
/**/                   0xE3F25E5C, 0x3FE9CDC2,
/**/                   0x12993F62, 0x3C83F991,
/**/                   0xB148BC4F, 0x3FE32054,
/**/                   0x095A135B, 0x3C8F6B42,
/**/                   0xA36A6514, 0x3FE9A7B5,
/**/                   0xCC9FA7A9, 0x3C8722CF,
/**/                   0xB9BE0367, 0x3FE3537D,
/**/                   0x7AF040F0, 0x3C6B327E,
/**/                   0xC42E1310, 0x3FE98141,
/**/                   0x0488F08D, 0x3C8D1FF8,
/**/                   0x7456282B, 0x3FE38659,
/**/                   0xA93B07A8, 0xBC710FAD,
/**/                   0xE00CB1FD, 0x3FE95A67,
/**/                   0xA21F862D, 0xBC80BEFD,
/**/                   0x15A2840A, 0x3FE3B8E7,
/**/                   0xA7D2F07B, 0xBC797653,
/**/                   0x926D9E92, 0x3FE93328,
/**/                   0x03600CDA, 0xBC8BB770,
/**/                   0xD36CD53A, 0x3FE3EB25,
/**/                   0xE1570FC0, 0xBC5BE570,
/**/                   0x784DDAF7, 0x3FE90B84,
/**/                   0x0AB93B87, 0xBC70FEB1,
/**/                   0xE4BA6790, 0x3FE41D14,
/**/                   0xD287ECF5, 0x3C84608F,
/**/                   0x303D9AD1, 0x3FE8E37C,
/**/                   0xB53D4BF8, 0xBC6463A4,
/**/                   0x81CF386B, 0x3FE44EB3,
/**/                   0x1E6A5505, 0xBC83ED6C,
/**/                   0x5A5DC900, 0x3FE8BB10,
/**/                   0x3E9474C1, 0x3C8863E0,
/**/                   0xE431159F, 0x3FE48000,
/**/                   0x7463ED10, 0xBC8B194A,
/**/                   0x985D871F, 0x3FE89241,
/**/                   0xC413ED84, 0x3C8C48D9,
/**/                   0x46AAB761, 0x3FE4B0FC,
/**/                   0x738CC59A, 0x3C20DA05,
/**/                   0x8D77A6C6, 0x3FE86910,
/**/                   0xE2BFE9DD, 0x3C7338FF,
/**/                   0xE54ED51B, 0x3FE4E1A4,
/**/                   0x89B7C76A, 0xBC8A492F,
/**/                   0xDE701CA0, 0x3FE83F7D,
/**/                   0x609BC6E8, 0xBC4152CF,
/**/                   0xFD7B351C, 0x3FE511F9,
/**/                   0x61C48831, 0xBC85C0E8,
/**/                   0x31916D5D, 0x3FE8158A,
/**/                   0x0B8228DE, 0xBC6DE8B9,
/**/                   0xCDDBB724, 0x3FE541FA,
/**/                   0x8520D391, 0x3C7232C2,
/**/                   0x2EAA1488, 0x3FE7EB36,
/**/                   0xA4A5959F, 0x3C5A1D65,
/**/                   0x966D59B3, 0x3FE571A6,
/**/                   0x4D0FB198, 0x3C5C843B,
/**/                   0x7F09E54F, 0x3FE7C082,
/**/                   0xD72AEE68, 0xBC6C73D6,
/**/                   0x98813A12, 0x3FE5A0FC,
/**/                   0xB7D4227B, 0xBC8D82E2,
/**/                   0xCD7F6543, 0x3FE7956F,
/**/                   0xE9D45AE4, 0xBC8AB276,
/**/                   0x16BF8F0D, 0x3FE5CFFC,
/**/                   0x70EB578A, 0x3C896CB3,
/**/                   0xC655211F, 0x3FE769FE,
/**/                   0xCF8C68C5, 0xBC6827D5,
/**/                   0x552A9E57, 0x3FE5FEA4,
/**/                   0xF7EE20B7, 0x3C80B6CE,
/**/                   0x174EFBA1, 0x3FE73E30,
/**/                   0x3D94AD5F, 0xBC65D3AE,
/**/                   0x9921AC79, 0x3FE62CF4,
/**/                   0x55B6241A, 0xBC8EDD98,
/**/                   0x6FA77678, 0x3FE71204,
/**/                   0xA5029C81, 0x3C8425B0,
/**/                   0x2963E755, 0x3FE65AEC,
/**/                   0x6B71053C, 0x3C8126F9,
/**/                   0x800CF55E, 0x3FE6E57C,
/**/                   0xDEDBD0A6, 0x3C860286,
/**/                   0x4E134B2F, 0x3FE6888A,
/**/                   0x7644D5E6, 0xBC86B7D3,
/**/                   0xFA9EFB5D, 0x3FE6B898,
/**/                   0x86CCF4B2, 0x3C715AC7,
/**/                   0x50B7821A, 0x3FE6B5CE,
/**/                   0x8F702E0F, 0xBC65D515,
/**/                   0x92EB6253, 0x3FE68B5A,
/**/                   0xD985F89C, 0xBC89A91A,
/**/                   0x7C40BDE1, 0x3FE6E2B7,
/**/                   0x857FAD53, 0xBC70E729,
/**/                   0xFDEB8CBA, 0x3FE65DC1,
/**/                   0x47337C77, 0xBC597C1B,
/**/                   0x1D0A8C40, 0x3FE70F45,
/**/                   0x3885770D, 0x3C697EDE,
/**/                   0xF20191C7, 0x3FE62FCF,
/**/                   0x895756EF, 0x3C6D9143,
/**/                   0x80DEA578, 0x3FE73B76,
/**/                   0x06DC12A2, 0xBC722483,
/**/                   0x26F563DF, 0x3FE60185,
/**/                   0xE0E432D0, 0x3C846CA5,
/**/                   0xF6F7B524, 0x3FE7674A,
/**/                   0x94AC84A8, 0x3C7E9D3F,
/**/                   0x55F1F17A, 0x3FE5D2E2,
/**/                   0x04C8892B, 0x3C803141,
/**/                   0xD0041D52, 0x3FE792C1,
/**/                   0xEEB354EB, 0xBC8ABF05,
/**/                   0x39824077, 0x3FE5A3E8,
/**/                   0x2759BE62, 0x3C8428AA,
/**/                   0x5E28B3C2, 0x3FE7BDDA,
/**/                   0x7CCD0393, 0x3C4AD119,
/**/                   0x8D8E83F2, 0x3FE57497,
/**/                   0xAF282D23, 0x3C8F4714,
/**/                   0xF5037959, 0x3FE7E893,
/**/                   0xAA650C4C, 0x3C80EEFB,
/**/                   0x0F592CA5, 0x3FE544F1,
/**/                   0xE6C7A62F, 0xBC8E7AE8,
/**/                   0xE9AE4BA4, 0x3FE812ED,
/**/                   0xDF402DDA, 0xBC87830A,
/**/                   0x7D7BF3DA, 0x3FE514F5,
/**/                   0x8073C259, 0x3C747A10 } };

#endif

static const double s1 =    /*  -0x1.5555555555555p-3;  */ -0.16666666666666666     ;
static const double s2 =    /*  0x1.1111111110ECEp-7;   */  0.0083333333333323288   ;
static const double s3 =    /*  -0x1.A01A019DB08B8p-13; */ -0.00019841269834414642  ;
static const double s4 =    /*  0x1.71DE27B9A7ED9p-19;  */  2.755729806860771e-06   ;
static const double s5 =    /*  -0x1.ADDFFC2FCDF59p-26; */ -2.5022014848318398e-08  ;
static const double aa =    /*  -0x1.5558000000000p-3;  */ -0.1666717529296875      ;
static const double bb =    /*  0x1.5555555556E24p-18;  */  5.0862630208387126e-06  ;
static const double big =   /*  0x1.8000000000000p45;   */  52776558133248          ;
static const double hp0 =   /*  0x1.921FB54442D18p0;    */  1.5707963267948966      ;
static const double hp1 =   /*  0x1.1A62633145C07p-54;  */  6.123233995736766e-17   ;
static const double mp1 =   /*  0x1.921FB58000000p0;    */  1.5707963407039642      ;
static const double mp2 =   /*  -0x1.DDE973C000000p-27; */ -1.3909067564377153e-08  ;
static const double mp3 =   /*  -0x1.CB3B399D747F2p-55; */ -4.9789962505147994e-17  ;
static const double pp3 =   /*  -0x1.CB3B398000000p-55; */ -4.9789962314799099e-17  ;
static const double pp4 =   /*  -0x1.d747f23e32ed7p-83; */ -1.9034889620193266e-25  ;
static const double hpinv = /*  0x1.45F306DC9C883p-1;   */  0.63661977236758138     ;
static const double toint = /*  0x1.8000000000000p52;   */  6755399441055744        ;

/* Helper macros to compute sin of the input values.  */
#define POLYNOMIAL2(xx) ((((s5 * (xx) + s4) * (xx) + s3) * (xx) + s2) * (xx))

#define POLYNOMIAL(xx) (POLYNOMIAL2 (xx) + s1)

/* The computed polynomial is a variation of the Taylor series expansion for
   sin(x):

   x - x^3/3! + x^5/5! - x^7/7! + x^9/9! - dx*x^2/2 + dx

   The constants s1, s2, s3, etc. are pre-computed values of 1/3!, 1/5! and so
   on.  The result is returned to LHS.  */
#define TAYLOR_SIN(xx, x, dx) \
({									      \
  double t = ((POLYNOMIAL (xx)  * (x) - 0.5 * (dx))  * (xx) + (dx));	      \
  double res = (x) + t;							      \
  res;									      \
})

#define SINCOS_TABLE_LOOKUP(u, sn, ssn, cs, ccs) \
({									      \
  int4 k = u.i[LOW_HALF] << 2;						      \
  sn = __sincostab.x[k];						      \
  ssn = __sincostab.x[k + 1];						      \
  cs = __sincostab.x[k + 2];						      \
  ccs = __sincostab.x[k + 3];						      \
})

static const double
  sn3 = -1.66666666666664880952546298448555E-01,
  sn5 = 8.33333214285722277379541354343671E-03,
  cs2 = 4.99999999999999999999950396842453E-01,
  cs4 = -4.16666666666664434524222570944589E-02,
  cs6 = 1.38888874007937613028114285595617E-03;

int __branred (double x, double *a, double *aa);

/* Given a number partitioned into X and DX, this function computes the cosine
   of the number by combining the sin and cos of X (as computed by a variation
   of the Taylor series) with the values looked up from the sin/cos table to
   get the result.  */
static __always_inline double
do_cos (double x, double dx)
{
  mynumber u;

  if (x < 0)
    dx = -dx;

  u.x = big + fabs (x);
  x = fabs (x) - (u.x - big) + dx;

  double xx, s, sn, ssn, c, cs, ccs, cor;
  xx = x * x;
  s = x + x * xx * (sn3 + xx * sn5);
  c = xx * (cs2 + xx * (cs4 + xx * cs6));
  SINCOS_TABLE_LOOKUP (u, sn, ssn, cs, ccs);
  cor = (ccs - s * ssn - cs * c) - sn * s;
  return cs + cor;
}

/* Given a number partitioned into X and DX, this function computes the sine of
   the number by combining the sin and cos of X (as computed by a variation of
   the Taylor series) with the values looked up from the sin/cos table to get
   the result.  */
static __always_inline double
do_sin (double x, double dx)
{
  double xold = x;
  /* Max ULP is 0.501 if |x| < 0.126, otherwise ULP is 0.518.  */
  if (fabs (x) < 0.126)
    return TAYLOR_SIN (x * x, x, dx);

  mynumber u;

  if (x <= 0)
    dx = -dx;
  u.x = big + fabs (x);
  x = fabs (x) - (u.x - big);

  double xx, s, sn, ssn, c, cs, ccs, cor;
  xx = x * x;
  s = x + (dx + x * xx * (sn3 + xx * sn5));
  c = x * dx + xx * (cs2 + xx * (cs4 + xx * cs6));
  SINCOS_TABLE_LOOKUP (u, sn, ssn, cs, ccs);
  cor = (ssn + s * ccs - sn * c) + cs * s;
  return copysign (sn + cor, xold);
}

/* Reduce range of x to within PI/2 with abs (x) < 105414350.  The high part
   is written to *a, the low part to *da.  Range reduction is accurate to 136
   bits so that when x is large and *a very close to zero, all 53 bits of *a
   are correct.  */
static __always_inline int4
reduce_sincos (double x, double *a, double *da)
{
  mynumber v;

  double t = (x * hpinv + toint);
  double xn = t - toint;
  v.x = t;
  double y = (x - xn * mp1) - xn * mp2;
  int4 n = v.i[LOW_HALF] & 3;

  double b, db, t1, t2;
  t1 = xn * pp3;
  t2 = y - t1;
  db = (y - t2) - t1;

  t1 = xn * pp4;
  b = t2 - t1;
  db += (t2 - b) - t1;

  *a = b;
  *da = db;
  return n;
}

/* Compute sin or cos (A + DA) for the given quadrant N.  */
static __always_inline double
do_sincos (double a, double da, int4 n)
{
  double retval;

  if (n & 1)
    /* Max ULP is 0.513.  */
    retval = do_cos (a, da);
  else
    /* Max ULP is 0.501 if xx < 0.01588, otherwise ULP is 0.518.  */
    retval = do_sin (a, da);

  return (n & 2) ? -retval : retval;
}


/*******************************************************************/
/* An ultimate sin routine. Given an IEEE double machine number x  */
/* it computes the rounded value of sin(x).			   */
/*******************************************************************/
double
__sin (double x)
{
  double t, a, da;
  mynumber u;
  int4 k, m, n;
  double retval = 0;

  u.x = x;
  m = u.i[HIGH_HALF];
  k = 0x7fffffff & m;		/* no sign           */
  if (k < 0x3e500000)		/* if x->0 =>sin(x)=x */
    {
      retval = x;
    }
/*--------------------------- 2^-26<|x|< 0.855469---------------------- */
  else if (k < 0x3feb6000)
    {
      /* Max ULP is 0.548.  */
      retval = do_sin (x, 0);
    }				/*   else  if (k < 0x3feb6000)    */

/*----------------------- 0.855469  <|x|<2.426265  ----------------------*/
  else if (k < 0x400368fd)
    {
      t = hp0 - fabs (x);
      /* Max ULP is 0.51.  */
      retval = copysign (do_cos (t, hp1), x);
    }				/*   else  if (k < 0x400368fd)    */

/*-------------------------- 2.426265<|x|< 105414350 ----------------------*/
  else if (k < 0x419921FB)
    {
      n = reduce_sincos (x, &a, &da);
      retval = do_sincos (a, da, n);
    }				/*   else  if (k <  0x419921FB )    */

/* --------------------105414350 <|x| <2^1024------------------------------*/
  else if (k < 0x7ff00000)
    {
      n = __branred (x, &a, &da);
      retval = do_sincos (a, da, n);
    }
/*--------------------- |x| > 2^1024 ----------------------------------*/
  else
    {
      if (k == 0x7ff00000 && u.i[LOW_HALF] == 0)
      retval = x / x;
    }

  return retval;
}


/*******************************************************************/
/* An ultimate cos routine. Given an IEEE double machine number x  */
/* it computes the rounded value of cos(x).			   */
/*******************************************************************/

double
__cos (double x)
{
  double y, a, da;
  mynumber u;
  int4 k, m, n;

  double retval = 0;

  u.x = x;
  m = u.i[HIGH_HALF];
  k = 0x7fffffff & m;

  /* |x|<2^-27 => cos(x)=1 */
  if (k < 0x3e400000)
    retval = 1.0;

  else if (k < 0x3feb6000)
    {				/* 2^-27 < |x| < 0.855469 */
      /* Max ULP is 0.51.  */
      retval = do_cos (x, 0);
    }				/*   else  if (k < 0x3feb6000)    */

  else if (k < 0x400368fd)
    { /* 0.855469  <|x|<2.426265  */ ;
      y = hp0 - fabs (x);
      a = y + hp1;
      da = (y - a) + hp1;
      /* Max ULP is 0.501 if xx < 0.01588 or 0.518 otherwise.
	 Range reduction uses 106 bits here which is sufficient.  */
      retval = do_sin (a, da);
    }				/*   else  if (k < 0x400368fd)    */

  else if (k < 0x419921FB)
    {				/* 2.426265<|x|< 105414350 */
      n = reduce_sincos (x, &a, &da);
      retval = do_sincos (a, da, n + 1);
    }				/*   else  if (k <  0x419921FB )    */

  /* 105414350 <|x| <2^1024 */
  else if (k < 0x7ff00000)
    {
      n = __branred (x, &a, &da);
      retval = do_sincos (a, da, n + 1);
    }

  else
    {
      if (k == 0x7ff00000 && u.i[LOW_HALF] == 0)
      retval = x / x;		/* |x| > 2^1024 */
    }

  return retval;
}


void
__sincos (double x, double *sinx, double *cosx)
{
  mynumber u;
  int k;

  u.x = x;
  k = u.i[HIGH_HALF] & 0x7fffffff;

  if (k < 0x400368fd)
    {
      double a, da, y;
      /* |x| < 2^-27 => cos (x) = 1, sin (x) = x.  */
      if (k < 0x3e400000)
	{
	  if (k < 0x3e500000)
	  *sinx = x;
	  *cosx = 1.0;
	  return;
	}
      /* |x| < 0.855469.  */
      else if (k < 0x3feb6000)
	{
	  *sinx = do_sin (x, 0);
	  *cosx = do_cos (x, 0);
	  return;
	}

      /* |x| < 2.426265.  */
      y = hp0 - fabs (x);
      a = y + hp1;
      da = (y - a) + hp1;
      *sinx = copysign (do_cos (a, da), x);
      *cosx = do_sin (a, da);
      return;
    }
  /* |x| < 2^1024.  */
  if (k < 0x7ff00000)
    {
      double a, da, xx;
      unsigned int n;

      /* If |x| < 105414350 use simple range reduction.  */
      n = k < 0x419921FB ? reduce_sincos (x, &a, &da) : __branred (x, &a, &da);
      n = n & 3;

      if (n == 1 || n == 2)
	{
	  a = -a;
	  da = -da;
	}

      if (n & 1)
	{
	  double *temp = cosx;
	  cosx = sinx;
	  sinx = temp;
	}

      *sinx = do_sin (a, da);
      xx = do_cos (a, da);
      *cosx = (n & 2) ? -xx : xx;
      return;
    }

  *sinx = *cosx = x / x;
}

};

#endif
