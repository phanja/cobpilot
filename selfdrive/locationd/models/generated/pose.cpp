#include "pose.h"

namespace {
#define DIM 18
#define EDIM 18
#define MEDIM 18
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_4 = 7.814727903251177;
const static double MAHA_THRESH_10 = 7.814727903251177;
const static double MAHA_THRESH_13 = 7.814727903251177;
const static double MAHA_THRESH_14 = 7.814727903251177;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_6780222169695424143) {
   out_6780222169695424143[0] = delta_x[0] + nom_x[0];
   out_6780222169695424143[1] = delta_x[1] + nom_x[1];
   out_6780222169695424143[2] = delta_x[2] + nom_x[2];
   out_6780222169695424143[3] = delta_x[3] + nom_x[3];
   out_6780222169695424143[4] = delta_x[4] + nom_x[4];
   out_6780222169695424143[5] = delta_x[5] + nom_x[5];
   out_6780222169695424143[6] = delta_x[6] + nom_x[6];
   out_6780222169695424143[7] = delta_x[7] + nom_x[7];
   out_6780222169695424143[8] = delta_x[8] + nom_x[8];
   out_6780222169695424143[9] = delta_x[9] + nom_x[9];
   out_6780222169695424143[10] = delta_x[10] + nom_x[10];
   out_6780222169695424143[11] = delta_x[11] + nom_x[11];
   out_6780222169695424143[12] = delta_x[12] + nom_x[12];
   out_6780222169695424143[13] = delta_x[13] + nom_x[13];
   out_6780222169695424143[14] = delta_x[14] + nom_x[14];
   out_6780222169695424143[15] = delta_x[15] + nom_x[15];
   out_6780222169695424143[16] = delta_x[16] + nom_x[16];
   out_6780222169695424143[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_8876249299301829416) {
   out_8876249299301829416[0] = -nom_x[0] + true_x[0];
   out_8876249299301829416[1] = -nom_x[1] + true_x[1];
   out_8876249299301829416[2] = -nom_x[2] + true_x[2];
   out_8876249299301829416[3] = -nom_x[3] + true_x[3];
   out_8876249299301829416[4] = -nom_x[4] + true_x[4];
   out_8876249299301829416[5] = -nom_x[5] + true_x[5];
   out_8876249299301829416[6] = -nom_x[6] + true_x[6];
   out_8876249299301829416[7] = -nom_x[7] + true_x[7];
   out_8876249299301829416[8] = -nom_x[8] + true_x[8];
   out_8876249299301829416[9] = -nom_x[9] + true_x[9];
   out_8876249299301829416[10] = -nom_x[10] + true_x[10];
   out_8876249299301829416[11] = -nom_x[11] + true_x[11];
   out_8876249299301829416[12] = -nom_x[12] + true_x[12];
   out_8876249299301829416[13] = -nom_x[13] + true_x[13];
   out_8876249299301829416[14] = -nom_x[14] + true_x[14];
   out_8876249299301829416[15] = -nom_x[15] + true_x[15];
   out_8876249299301829416[16] = -nom_x[16] + true_x[16];
   out_8876249299301829416[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_3838064112468561781) {
   out_3838064112468561781[0] = 1.0;
   out_3838064112468561781[1] = 0.0;
   out_3838064112468561781[2] = 0.0;
   out_3838064112468561781[3] = 0.0;
   out_3838064112468561781[4] = 0.0;
   out_3838064112468561781[5] = 0.0;
   out_3838064112468561781[6] = 0.0;
   out_3838064112468561781[7] = 0.0;
   out_3838064112468561781[8] = 0.0;
   out_3838064112468561781[9] = 0.0;
   out_3838064112468561781[10] = 0.0;
   out_3838064112468561781[11] = 0.0;
   out_3838064112468561781[12] = 0.0;
   out_3838064112468561781[13] = 0.0;
   out_3838064112468561781[14] = 0.0;
   out_3838064112468561781[15] = 0.0;
   out_3838064112468561781[16] = 0.0;
   out_3838064112468561781[17] = 0.0;
   out_3838064112468561781[18] = 0.0;
   out_3838064112468561781[19] = 1.0;
   out_3838064112468561781[20] = 0.0;
   out_3838064112468561781[21] = 0.0;
   out_3838064112468561781[22] = 0.0;
   out_3838064112468561781[23] = 0.0;
   out_3838064112468561781[24] = 0.0;
   out_3838064112468561781[25] = 0.0;
   out_3838064112468561781[26] = 0.0;
   out_3838064112468561781[27] = 0.0;
   out_3838064112468561781[28] = 0.0;
   out_3838064112468561781[29] = 0.0;
   out_3838064112468561781[30] = 0.0;
   out_3838064112468561781[31] = 0.0;
   out_3838064112468561781[32] = 0.0;
   out_3838064112468561781[33] = 0.0;
   out_3838064112468561781[34] = 0.0;
   out_3838064112468561781[35] = 0.0;
   out_3838064112468561781[36] = 0.0;
   out_3838064112468561781[37] = 0.0;
   out_3838064112468561781[38] = 1.0;
   out_3838064112468561781[39] = 0.0;
   out_3838064112468561781[40] = 0.0;
   out_3838064112468561781[41] = 0.0;
   out_3838064112468561781[42] = 0.0;
   out_3838064112468561781[43] = 0.0;
   out_3838064112468561781[44] = 0.0;
   out_3838064112468561781[45] = 0.0;
   out_3838064112468561781[46] = 0.0;
   out_3838064112468561781[47] = 0.0;
   out_3838064112468561781[48] = 0.0;
   out_3838064112468561781[49] = 0.0;
   out_3838064112468561781[50] = 0.0;
   out_3838064112468561781[51] = 0.0;
   out_3838064112468561781[52] = 0.0;
   out_3838064112468561781[53] = 0.0;
   out_3838064112468561781[54] = 0.0;
   out_3838064112468561781[55] = 0.0;
   out_3838064112468561781[56] = 0.0;
   out_3838064112468561781[57] = 1.0;
   out_3838064112468561781[58] = 0.0;
   out_3838064112468561781[59] = 0.0;
   out_3838064112468561781[60] = 0.0;
   out_3838064112468561781[61] = 0.0;
   out_3838064112468561781[62] = 0.0;
   out_3838064112468561781[63] = 0.0;
   out_3838064112468561781[64] = 0.0;
   out_3838064112468561781[65] = 0.0;
   out_3838064112468561781[66] = 0.0;
   out_3838064112468561781[67] = 0.0;
   out_3838064112468561781[68] = 0.0;
   out_3838064112468561781[69] = 0.0;
   out_3838064112468561781[70] = 0.0;
   out_3838064112468561781[71] = 0.0;
   out_3838064112468561781[72] = 0.0;
   out_3838064112468561781[73] = 0.0;
   out_3838064112468561781[74] = 0.0;
   out_3838064112468561781[75] = 0.0;
   out_3838064112468561781[76] = 1.0;
   out_3838064112468561781[77] = 0.0;
   out_3838064112468561781[78] = 0.0;
   out_3838064112468561781[79] = 0.0;
   out_3838064112468561781[80] = 0.0;
   out_3838064112468561781[81] = 0.0;
   out_3838064112468561781[82] = 0.0;
   out_3838064112468561781[83] = 0.0;
   out_3838064112468561781[84] = 0.0;
   out_3838064112468561781[85] = 0.0;
   out_3838064112468561781[86] = 0.0;
   out_3838064112468561781[87] = 0.0;
   out_3838064112468561781[88] = 0.0;
   out_3838064112468561781[89] = 0.0;
   out_3838064112468561781[90] = 0.0;
   out_3838064112468561781[91] = 0.0;
   out_3838064112468561781[92] = 0.0;
   out_3838064112468561781[93] = 0.0;
   out_3838064112468561781[94] = 0.0;
   out_3838064112468561781[95] = 1.0;
   out_3838064112468561781[96] = 0.0;
   out_3838064112468561781[97] = 0.0;
   out_3838064112468561781[98] = 0.0;
   out_3838064112468561781[99] = 0.0;
   out_3838064112468561781[100] = 0.0;
   out_3838064112468561781[101] = 0.0;
   out_3838064112468561781[102] = 0.0;
   out_3838064112468561781[103] = 0.0;
   out_3838064112468561781[104] = 0.0;
   out_3838064112468561781[105] = 0.0;
   out_3838064112468561781[106] = 0.0;
   out_3838064112468561781[107] = 0.0;
   out_3838064112468561781[108] = 0.0;
   out_3838064112468561781[109] = 0.0;
   out_3838064112468561781[110] = 0.0;
   out_3838064112468561781[111] = 0.0;
   out_3838064112468561781[112] = 0.0;
   out_3838064112468561781[113] = 0.0;
   out_3838064112468561781[114] = 1.0;
   out_3838064112468561781[115] = 0.0;
   out_3838064112468561781[116] = 0.0;
   out_3838064112468561781[117] = 0.0;
   out_3838064112468561781[118] = 0.0;
   out_3838064112468561781[119] = 0.0;
   out_3838064112468561781[120] = 0.0;
   out_3838064112468561781[121] = 0.0;
   out_3838064112468561781[122] = 0.0;
   out_3838064112468561781[123] = 0.0;
   out_3838064112468561781[124] = 0.0;
   out_3838064112468561781[125] = 0.0;
   out_3838064112468561781[126] = 0.0;
   out_3838064112468561781[127] = 0.0;
   out_3838064112468561781[128] = 0.0;
   out_3838064112468561781[129] = 0.0;
   out_3838064112468561781[130] = 0.0;
   out_3838064112468561781[131] = 0.0;
   out_3838064112468561781[132] = 0.0;
   out_3838064112468561781[133] = 1.0;
   out_3838064112468561781[134] = 0.0;
   out_3838064112468561781[135] = 0.0;
   out_3838064112468561781[136] = 0.0;
   out_3838064112468561781[137] = 0.0;
   out_3838064112468561781[138] = 0.0;
   out_3838064112468561781[139] = 0.0;
   out_3838064112468561781[140] = 0.0;
   out_3838064112468561781[141] = 0.0;
   out_3838064112468561781[142] = 0.0;
   out_3838064112468561781[143] = 0.0;
   out_3838064112468561781[144] = 0.0;
   out_3838064112468561781[145] = 0.0;
   out_3838064112468561781[146] = 0.0;
   out_3838064112468561781[147] = 0.0;
   out_3838064112468561781[148] = 0.0;
   out_3838064112468561781[149] = 0.0;
   out_3838064112468561781[150] = 0.0;
   out_3838064112468561781[151] = 0.0;
   out_3838064112468561781[152] = 1.0;
   out_3838064112468561781[153] = 0.0;
   out_3838064112468561781[154] = 0.0;
   out_3838064112468561781[155] = 0.0;
   out_3838064112468561781[156] = 0.0;
   out_3838064112468561781[157] = 0.0;
   out_3838064112468561781[158] = 0.0;
   out_3838064112468561781[159] = 0.0;
   out_3838064112468561781[160] = 0.0;
   out_3838064112468561781[161] = 0.0;
   out_3838064112468561781[162] = 0.0;
   out_3838064112468561781[163] = 0.0;
   out_3838064112468561781[164] = 0.0;
   out_3838064112468561781[165] = 0.0;
   out_3838064112468561781[166] = 0.0;
   out_3838064112468561781[167] = 0.0;
   out_3838064112468561781[168] = 0.0;
   out_3838064112468561781[169] = 0.0;
   out_3838064112468561781[170] = 0.0;
   out_3838064112468561781[171] = 1.0;
   out_3838064112468561781[172] = 0.0;
   out_3838064112468561781[173] = 0.0;
   out_3838064112468561781[174] = 0.0;
   out_3838064112468561781[175] = 0.0;
   out_3838064112468561781[176] = 0.0;
   out_3838064112468561781[177] = 0.0;
   out_3838064112468561781[178] = 0.0;
   out_3838064112468561781[179] = 0.0;
   out_3838064112468561781[180] = 0.0;
   out_3838064112468561781[181] = 0.0;
   out_3838064112468561781[182] = 0.0;
   out_3838064112468561781[183] = 0.0;
   out_3838064112468561781[184] = 0.0;
   out_3838064112468561781[185] = 0.0;
   out_3838064112468561781[186] = 0.0;
   out_3838064112468561781[187] = 0.0;
   out_3838064112468561781[188] = 0.0;
   out_3838064112468561781[189] = 0.0;
   out_3838064112468561781[190] = 1.0;
   out_3838064112468561781[191] = 0.0;
   out_3838064112468561781[192] = 0.0;
   out_3838064112468561781[193] = 0.0;
   out_3838064112468561781[194] = 0.0;
   out_3838064112468561781[195] = 0.0;
   out_3838064112468561781[196] = 0.0;
   out_3838064112468561781[197] = 0.0;
   out_3838064112468561781[198] = 0.0;
   out_3838064112468561781[199] = 0.0;
   out_3838064112468561781[200] = 0.0;
   out_3838064112468561781[201] = 0.0;
   out_3838064112468561781[202] = 0.0;
   out_3838064112468561781[203] = 0.0;
   out_3838064112468561781[204] = 0.0;
   out_3838064112468561781[205] = 0.0;
   out_3838064112468561781[206] = 0.0;
   out_3838064112468561781[207] = 0.0;
   out_3838064112468561781[208] = 0.0;
   out_3838064112468561781[209] = 1.0;
   out_3838064112468561781[210] = 0.0;
   out_3838064112468561781[211] = 0.0;
   out_3838064112468561781[212] = 0.0;
   out_3838064112468561781[213] = 0.0;
   out_3838064112468561781[214] = 0.0;
   out_3838064112468561781[215] = 0.0;
   out_3838064112468561781[216] = 0.0;
   out_3838064112468561781[217] = 0.0;
   out_3838064112468561781[218] = 0.0;
   out_3838064112468561781[219] = 0.0;
   out_3838064112468561781[220] = 0.0;
   out_3838064112468561781[221] = 0.0;
   out_3838064112468561781[222] = 0.0;
   out_3838064112468561781[223] = 0.0;
   out_3838064112468561781[224] = 0.0;
   out_3838064112468561781[225] = 0.0;
   out_3838064112468561781[226] = 0.0;
   out_3838064112468561781[227] = 0.0;
   out_3838064112468561781[228] = 1.0;
   out_3838064112468561781[229] = 0.0;
   out_3838064112468561781[230] = 0.0;
   out_3838064112468561781[231] = 0.0;
   out_3838064112468561781[232] = 0.0;
   out_3838064112468561781[233] = 0.0;
   out_3838064112468561781[234] = 0.0;
   out_3838064112468561781[235] = 0.0;
   out_3838064112468561781[236] = 0.0;
   out_3838064112468561781[237] = 0.0;
   out_3838064112468561781[238] = 0.0;
   out_3838064112468561781[239] = 0.0;
   out_3838064112468561781[240] = 0.0;
   out_3838064112468561781[241] = 0.0;
   out_3838064112468561781[242] = 0.0;
   out_3838064112468561781[243] = 0.0;
   out_3838064112468561781[244] = 0.0;
   out_3838064112468561781[245] = 0.0;
   out_3838064112468561781[246] = 0.0;
   out_3838064112468561781[247] = 1.0;
   out_3838064112468561781[248] = 0.0;
   out_3838064112468561781[249] = 0.0;
   out_3838064112468561781[250] = 0.0;
   out_3838064112468561781[251] = 0.0;
   out_3838064112468561781[252] = 0.0;
   out_3838064112468561781[253] = 0.0;
   out_3838064112468561781[254] = 0.0;
   out_3838064112468561781[255] = 0.0;
   out_3838064112468561781[256] = 0.0;
   out_3838064112468561781[257] = 0.0;
   out_3838064112468561781[258] = 0.0;
   out_3838064112468561781[259] = 0.0;
   out_3838064112468561781[260] = 0.0;
   out_3838064112468561781[261] = 0.0;
   out_3838064112468561781[262] = 0.0;
   out_3838064112468561781[263] = 0.0;
   out_3838064112468561781[264] = 0.0;
   out_3838064112468561781[265] = 0.0;
   out_3838064112468561781[266] = 1.0;
   out_3838064112468561781[267] = 0.0;
   out_3838064112468561781[268] = 0.0;
   out_3838064112468561781[269] = 0.0;
   out_3838064112468561781[270] = 0.0;
   out_3838064112468561781[271] = 0.0;
   out_3838064112468561781[272] = 0.0;
   out_3838064112468561781[273] = 0.0;
   out_3838064112468561781[274] = 0.0;
   out_3838064112468561781[275] = 0.0;
   out_3838064112468561781[276] = 0.0;
   out_3838064112468561781[277] = 0.0;
   out_3838064112468561781[278] = 0.0;
   out_3838064112468561781[279] = 0.0;
   out_3838064112468561781[280] = 0.0;
   out_3838064112468561781[281] = 0.0;
   out_3838064112468561781[282] = 0.0;
   out_3838064112468561781[283] = 0.0;
   out_3838064112468561781[284] = 0.0;
   out_3838064112468561781[285] = 1.0;
   out_3838064112468561781[286] = 0.0;
   out_3838064112468561781[287] = 0.0;
   out_3838064112468561781[288] = 0.0;
   out_3838064112468561781[289] = 0.0;
   out_3838064112468561781[290] = 0.0;
   out_3838064112468561781[291] = 0.0;
   out_3838064112468561781[292] = 0.0;
   out_3838064112468561781[293] = 0.0;
   out_3838064112468561781[294] = 0.0;
   out_3838064112468561781[295] = 0.0;
   out_3838064112468561781[296] = 0.0;
   out_3838064112468561781[297] = 0.0;
   out_3838064112468561781[298] = 0.0;
   out_3838064112468561781[299] = 0.0;
   out_3838064112468561781[300] = 0.0;
   out_3838064112468561781[301] = 0.0;
   out_3838064112468561781[302] = 0.0;
   out_3838064112468561781[303] = 0.0;
   out_3838064112468561781[304] = 1.0;
   out_3838064112468561781[305] = 0.0;
   out_3838064112468561781[306] = 0.0;
   out_3838064112468561781[307] = 0.0;
   out_3838064112468561781[308] = 0.0;
   out_3838064112468561781[309] = 0.0;
   out_3838064112468561781[310] = 0.0;
   out_3838064112468561781[311] = 0.0;
   out_3838064112468561781[312] = 0.0;
   out_3838064112468561781[313] = 0.0;
   out_3838064112468561781[314] = 0.0;
   out_3838064112468561781[315] = 0.0;
   out_3838064112468561781[316] = 0.0;
   out_3838064112468561781[317] = 0.0;
   out_3838064112468561781[318] = 0.0;
   out_3838064112468561781[319] = 0.0;
   out_3838064112468561781[320] = 0.0;
   out_3838064112468561781[321] = 0.0;
   out_3838064112468561781[322] = 0.0;
   out_3838064112468561781[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_3082222889402326840) {
   out_3082222889402326840[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_3082222889402326840[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_3082222889402326840[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_3082222889402326840[3] = dt*state[12] + state[3];
   out_3082222889402326840[4] = dt*state[13] + state[4];
   out_3082222889402326840[5] = dt*state[14] + state[5];
   out_3082222889402326840[6] = state[6];
   out_3082222889402326840[7] = state[7];
   out_3082222889402326840[8] = state[8];
   out_3082222889402326840[9] = state[9];
   out_3082222889402326840[10] = state[10];
   out_3082222889402326840[11] = state[11];
   out_3082222889402326840[12] = state[12];
   out_3082222889402326840[13] = state[13];
   out_3082222889402326840[14] = state[14];
   out_3082222889402326840[15] = state[15];
   out_3082222889402326840[16] = state[16];
   out_3082222889402326840[17] = state[17];
}
void F_fun(double *state, double dt, double *out_574273013645914746) {
   out_574273013645914746[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_574273013645914746[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_574273013645914746[2] = 0;
   out_574273013645914746[3] = 0;
   out_574273013645914746[4] = 0;
   out_574273013645914746[5] = 0;
   out_574273013645914746[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_574273013645914746[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_574273013645914746[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_574273013645914746[9] = 0;
   out_574273013645914746[10] = 0;
   out_574273013645914746[11] = 0;
   out_574273013645914746[12] = 0;
   out_574273013645914746[13] = 0;
   out_574273013645914746[14] = 0;
   out_574273013645914746[15] = 0;
   out_574273013645914746[16] = 0;
   out_574273013645914746[17] = 0;
   out_574273013645914746[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_574273013645914746[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_574273013645914746[20] = 0;
   out_574273013645914746[21] = 0;
   out_574273013645914746[22] = 0;
   out_574273013645914746[23] = 0;
   out_574273013645914746[24] = 0;
   out_574273013645914746[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_574273013645914746[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_574273013645914746[27] = 0;
   out_574273013645914746[28] = 0;
   out_574273013645914746[29] = 0;
   out_574273013645914746[30] = 0;
   out_574273013645914746[31] = 0;
   out_574273013645914746[32] = 0;
   out_574273013645914746[33] = 0;
   out_574273013645914746[34] = 0;
   out_574273013645914746[35] = 0;
   out_574273013645914746[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_574273013645914746[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_574273013645914746[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_574273013645914746[39] = 0;
   out_574273013645914746[40] = 0;
   out_574273013645914746[41] = 0;
   out_574273013645914746[42] = 0;
   out_574273013645914746[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_574273013645914746[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_574273013645914746[45] = 0;
   out_574273013645914746[46] = 0;
   out_574273013645914746[47] = 0;
   out_574273013645914746[48] = 0;
   out_574273013645914746[49] = 0;
   out_574273013645914746[50] = 0;
   out_574273013645914746[51] = 0;
   out_574273013645914746[52] = 0;
   out_574273013645914746[53] = 0;
   out_574273013645914746[54] = 0;
   out_574273013645914746[55] = 0;
   out_574273013645914746[56] = 0;
   out_574273013645914746[57] = 1;
   out_574273013645914746[58] = 0;
   out_574273013645914746[59] = 0;
   out_574273013645914746[60] = 0;
   out_574273013645914746[61] = 0;
   out_574273013645914746[62] = 0;
   out_574273013645914746[63] = 0;
   out_574273013645914746[64] = 0;
   out_574273013645914746[65] = 0;
   out_574273013645914746[66] = dt;
   out_574273013645914746[67] = 0;
   out_574273013645914746[68] = 0;
   out_574273013645914746[69] = 0;
   out_574273013645914746[70] = 0;
   out_574273013645914746[71] = 0;
   out_574273013645914746[72] = 0;
   out_574273013645914746[73] = 0;
   out_574273013645914746[74] = 0;
   out_574273013645914746[75] = 0;
   out_574273013645914746[76] = 1;
   out_574273013645914746[77] = 0;
   out_574273013645914746[78] = 0;
   out_574273013645914746[79] = 0;
   out_574273013645914746[80] = 0;
   out_574273013645914746[81] = 0;
   out_574273013645914746[82] = 0;
   out_574273013645914746[83] = 0;
   out_574273013645914746[84] = 0;
   out_574273013645914746[85] = dt;
   out_574273013645914746[86] = 0;
   out_574273013645914746[87] = 0;
   out_574273013645914746[88] = 0;
   out_574273013645914746[89] = 0;
   out_574273013645914746[90] = 0;
   out_574273013645914746[91] = 0;
   out_574273013645914746[92] = 0;
   out_574273013645914746[93] = 0;
   out_574273013645914746[94] = 0;
   out_574273013645914746[95] = 1;
   out_574273013645914746[96] = 0;
   out_574273013645914746[97] = 0;
   out_574273013645914746[98] = 0;
   out_574273013645914746[99] = 0;
   out_574273013645914746[100] = 0;
   out_574273013645914746[101] = 0;
   out_574273013645914746[102] = 0;
   out_574273013645914746[103] = 0;
   out_574273013645914746[104] = dt;
   out_574273013645914746[105] = 0;
   out_574273013645914746[106] = 0;
   out_574273013645914746[107] = 0;
   out_574273013645914746[108] = 0;
   out_574273013645914746[109] = 0;
   out_574273013645914746[110] = 0;
   out_574273013645914746[111] = 0;
   out_574273013645914746[112] = 0;
   out_574273013645914746[113] = 0;
   out_574273013645914746[114] = 1;
   out_574273013645914746[115] = 0;
   out_574273013645914746[116] = 0;
   out_574273013645914746[117] = 0;
   out_574273013645914746[118] = 0;
   out_574273013645914746[119] = 0;
   out_574273013645914746[120] = 0;
   out_574273013645914746[121] = 0;
   out_574273013645914746[122] = 0;
   out_574273013645914746[123] = 0;
   out_574273013645914746[124] = 0;
   out_574273013645914746[125] = 0;
   out_574273013645914746[126] = 0;
   out_574273013645914746[127] = 0;
   out_574273013645914746[128] = 0;
   out_574273013645914746[129] = 0;
   out_574273013645914746[130] = 0;
   out_574273013645914746[131] = 0;
   out_574273013645914746[132] = 0;
   out_574273013645914746[133] = 1;
   out_574273013645914746[134] = 0;
   out_574273013645914746[135] = 0;
   out_574273013645914746[136] = 0;
   out_574273013645914746[137] = 0;
   out_574273013645914746[138] = 0;
   out_574273013645914746[139] = 0;
   out_574273013645914746[140] = 0;
   out_574273013645914746[141] = 0;
   out_574273013645914746[142] = 0;
   out_574273013645914746[143] = 0;
   out_574273013645914746[144] = 0;
   out_574273013645914746[145] = 0;
   out_574273013645914746[146] = 0;
   out_574273013645914746[147] = 0;
   out_574273013645914746[148] = 0;
   out_574273013645914746[149] = 0;
   out_574273013645914746[150] = 0;
   out_574273013645914746[151] = 0;
   out_574273013645914746[152] = 1;
   out_574273013645914746[153] = 0;
   out_574273013645914746[154] = 0;
   out_574273013645914746[155] = 0;
   out_574273013645914746[156] = 0;
   out_574273013645914746[157] = 0;
   out_574273013645914746[158] = 0;
   out_574273013645914746[159] = 0;
   out_574273013645914746[160] = 0;
   out_574273013645914746[161] = 0;
   out_574273013645914746[162] = 0;
   out_574273013645914746[163] = 0;
   out_574273013645914746[164] = 0;
   out_574273013645914746[165] = 0;
   out_574273013645914746[166] = 0;
   out_574273013645914746[167] = 0;
   out_574273013645914746[168] = 0;
   out_574273013645914746[169] = 0;
   out_574273013645914746[170] = 0;
   out_574273013645914746[171] = 1;
   out_574273013645914746[172] = 0;
   out_574273013645914746[173] = 0;
   out_574273013645914746[174] = 0;
   out_574273013645914746[175] = 0;
   out_574273013645914746[176] = 0;
   out_574273013645914746[177] = 0;
   out_574273013645914746[178] = 0;
   out_574273013645914746[179] = 0;
   out_574273013645914746[180] = 0;
   out_574273013645914746[181] = 0;
   out_574273013645914746[182] = 0;
   out_574273013645914746[183] = 0;
   out_574273013645914746[184] = 0;
   out_574273013645914746[185] = 0;
   out_574273013645914746[186] = 0;
   out_574273013645914746[187] = 0;
   out_574273013645914746[188] = 0;
   out_574273013645914746[189] = 0;
   out_574273013645914746[190] = 1;
   out_574273013645914746[191] = 0;
   out_574273013645914746[192] = 0;
   out_574273013645914746[193] = 0;
   out_574273013645914746[194] = 0;
   out_574273013645914746[195] = 0;
   out_574273013645914746[196] = 0;
   out_574273013645914746[197] = 0;
   out_574273013645914746[198] = 0;
   out_574273013645914746[199] = 0;
   out_574273013645914746[200] = 0;
   out_574273013645914746[201] = 0;
   out_574273013645914746[202] = 0;
   out_574273013645914746[203] = 0;
   out_574273013645914746[204] = 0;
   out_574273013645914746[205] = 0;
   out_574273013645914746[206] = 0;
   out_574273013645914746[207] = 0;
   out_574273013645914746[208] = 0;
   out_574273013645914746[209] = 1;
   out_574273013645914746[210] = 0;
   out_574273013645914746[211] = 0;
   out_574273013645914746[212] = 0;
   out_574273013645914746[213] = 0;
   out_574273013645914746[214] = 0;
   out_574273013645914746[215] = 0;
   out_574273013645914746[216] = 0;
   out_574273013645914746[217] = 0;
   out_574273013645914746[218] = 0;
   out_574273013645914746[219] = 0;
   out_574273013645914746[220] = 0;
   out_574273013645914746[221] = 0;
   out_574273013645914746[222] = 0;
   out_574273013645914746[223] = 0;
   out_574273013645914746[224] = 0;
   out_574273013645914746[225] = 0;
   out_574273013645914746[226] = 0;
   out_574273013645914746[227] = 0;
   out_574273013645914746[228] = 1;
   out_574273013645914746[229] = 0;
   out_574273013645914746[230] = 0;
   out_574273013645914746[231] = 0;
   out_574273013645914746[232] = 0;
   out_574273013645914746[233] = 0;
   out_574273013645914746[234] = 0;
   out_574273013645914746[235] = 0;
   out_574273013645914746[236] = 0;
   out_574273013645914746[237] = 0;
   out_574273013645914746[238] = 0;
   out_574273013645914746[239] = 0;
   out_574273013645914746[240] = 0;
   out_574273013645914746[241] = 0;
   out_574273013645914746[242] = 0;
   out_574273013645914746[243] = 0;
   out_574273013645914746[244] = 0;
   out_574273013645914746[245] = 0;
   out_574273013645914746[246] = 0;
   out_574273013645914746[247] = 1;
   out_574273013645914746[248] = 0;
   out_574273013645914746[249] = 0;
   out_574273013645914746[250] = 0;
   out_574273013645914746[251] = 0;
   out_574273013645914746[252] = 0;
   out_574273013645914746[253] = 0;
   out_574273013645914746[254] = 0;
   out_574273013645914746[255] = 0;
   out_574273013645914746[256] = 0;
   out_574273013645914746[257] = 0;
   out_574273013645914746[258] = 0;
   out_574273013645914746[259] = 0;
   out_574273013645914746[260] = 0;
   out_574273013645914746[261] = 0;
   out_574273013645914746[262] = 0;
   out_574273013645914746[263] = 0;
   out_574273013645914746[264] = 0;
   out_574273013645914746[265] = 0;
   out_574273013645914746[266] = 1;
   out_574273013645914746[267] = 0;
   out_574273013645914746[268] = 0;
   out_574273013645914746[269] = 0;
   out_574273013645914746[270] = 0;
   out_574273013645914746[271] = 0;
   out_574273013645914746[272] = 0;
   out_574273013645914746[273] = 0;
   out_574273013645914746[274] = 0;
   out_574273013645914746[275] = 0;
   out_574273013645914746[276] = 0;
   out_574273013645914746[277] = 0;
   out_574273013645914746[278] = 0;
   out_574273013645914746[279] = 0;
   out_574273013645914746[280] = 0;
   out_574273013645914746[281] = 0;
   out_574273013645914746[282] = 0;
   out_574273013645914746[283] = 0;
   out_574273013645914746[284] = 0;
   out_574273013645914746[285] = 1;
   out_574273013645914746[286] = 0;
   out_574273013645914746[287] = 0;
   out_574273013645914746[288] = 0;
   out_574273013645914746[289] = 0;
   out_574273013645914746[290] = 0;
   out_574273013645914746[291] = 0;
   out_574273013645914746[292] = 0;
   out_574273013645914746[293] = 0;
   out_574273013645914746[294] = 0;
   out_574273013645914746[295] = 0;
   out_574273013645914746[296] = 0;
   out_574273013645914746[297] = 0;
   out_574273013645914746[298] = 0;
   out_574273013645914746[299] = 0;
   out_574273013645914746[300] = 0;
   out_574273013645914746[301] = 0;
   out_574273013645914746[302] = 0;
   out_574273013645914746[303] = 0;
   out_574273013645914746[304] = 1;
   out_574273013645914746[305] = 0;
   out_574273013645914746[306] = 0;
   out_574273013645914746[307] = 0;
   out_574273013645914746[308] = 0;
   out_574273013645914746[309] = 0;
   out_574273013645914746[310] = 0;
   out_574273013645914746[311] = 0;
   out_574273013645914746[312] = 0;
   out_574273013645914746[313] = 0;
   out_574273013645914746[314] = 0;
   out_574273013645914746[315] = 0;
   out_574273013645914746[316] = 0;
   out_574273013645914746[317] = 0;
   out_574273013645914746[318] = 0;
   out_574273013645914746[319] = 0;
   out_574273013645914746[320] = 0;
   out_574273013645914746[321] = 0;
   out_574273013645914746[322] = 0;
   out_574273013645914746[323] = 1;
}
void h_4(double *state, double *unused, double *out_1822046223765446894) {
   out_1822046223765446894[0] = state[6] + state[9];
   out_1822046223765446894[1] = state[7] + state[10];
   out_1822046223765446894[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_8760598154489031114) {
   out_8760598154489031114[0] = 0;
   out_8760598154489031114[1] = 0;
   out_8760598154489031114[2] = 0;
   out_8760598154489031114[3] = 0;
   out_8760598154489031114[4] = 0;
   out_8760598154489031114[5] = 0;
   out_8760598154489031114[6] = 1;
   out_8760598154489031114[7] = 0;
   out_8760598154489031114[8] = 0;
   out_8760598154489031114[9] = 1;
   out_8760598154489031114[10] = 0;
   out_8760598154489031114[11] = 0;
   out_8760598154489031114[12] = 0;
   out_8760598154489031114[13] = 0;
   out_8760598154489031114[14] = 0;
   out_8760598154489031114[15] = 0;
   out_8760598154489031114[16] = 0;
   out_8760598154489031114[17] = 0;
   out_8760598154489031114[18] = 0;
   out_8760598154489031114[19] = 0;
   out_8760598154489031114[20] = 0;
   out_8760598154489031114[21] = 0;
   out_8760598154489031114[22] = 0;
   out_8760598154489031114[23] = 0;
   out_8760598154489031114[24] = 0;
   out_8760598154489031114[25] = 1;
   out_8760598154489031114[26] = 0;
   out_8760598154489031114[27] = 0;
   out_8760598154489031114[28] = 1;
   out_8760598154489031114[29] = 0;
   out_8760598154489031114[30] = 0;
   out_8760598154489031114[31] = 0;
   out_8760598154489031114[32] = 0;
   out_8760598154489031114[33] = 0;
   out_8760598154489031114[34] = 0;
   out_8760598154489031114[35] = 0;
   out_8760598154489031114[36] = 0;
   out_8760598154489031114[37] = 0;
   out_8760598154489031114[38] = 0;
   out_8760598154489031114[39] = 0;
   out_8760598154489031114[40] = 0;
   out_8760598154489031114[41] = 0;
   out_8760598154489031114[42] = 0;
   out_8760598154489031114[43] = 0;
   out_8760598154489031114[44] = 1;
   out_8760598154489031114[45] = 0;
   out_8760598154489031114[46] = 0;
   out_8760598154489031114[47] = 1;
   out_8760598154489031114[48] = 0;
   out_8760598154489031114[49] = 0;
   out_8760598154489031114[50] = 0;
   out_8760598154489031114[51] = 0;
   out_8760598154489031114[52] = 0;
   out_8760598154489031114[53] = 0;
}
void h_10(double *state, double *unused, double *out_714441176925206643) {
   out_714441176925206643[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_714441176925206643[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_714441176925206643[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_6206202842202479986) {
   out_6206202842202479986[0] = 0;
   out_6206202842202479986[1] = 9.8100000000000005*cos(state[1]);
   out_6206202842202479986[2] = 0;
   out_6206202842202479986[3] = 0;
   out_6206202842202479986[4] = -state[8];
   out_6206202842202479986[5] = state[7];
   out_6206202842202479986[6] = 0;
   out_6206202842202479986[7] = state[5];
   out_6206202842202479986[8] = -state[4];
   out_6206202842202479986[9] = 0;
   out_6206202842202479986[10] = 0;
   out_6206202842202479986[11] = 0;
   out_6206202842202479986[12] = 1;
   out_6206202842202479986[13] = 0;
   out_6206202842202479986[14] = 0;
   out_6206202842202479986[15] = 1;
   out_6206202842202479986[16] = 0;
   out_6206202842202479986[17] = 0;
   out_6206202842202479986[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_6206202842202479986[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_6206202842202479986[20] = 0;
   out_6206202842202479986[21] = state[8];
   out_6206202842202479986[22] = 0;
   out_6206202842202479986[23] = -state[6];
   out_6206202842202479986[24] = -state[5];
   out_6206202842202479986[25] = 0;
   out_6206202842202479986[26] = state[3];
   out_6206202842202479986[27] = 0;
   out_6206202842202479986[28] = 0;
   out_6206202842202479986[29] = 0;
   out_6206202842202479986[30] = 0;
   out_6206202842202479986[31] = 1;
   out_6206202842202479986[32] = 0;
   out_6206202842202479986[33] = 0;
   out_6206202842202479986[34] = 1;
   out_6206202842202479986[35] = 0;
   out_6206202842202479986[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_6206202842202479986[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_6206202842202479986[38] = 0;
   out_6206202842202479986[39] = -state[7];
   out_6206202842202479986[40] = state[6];
   out_6206202842202479986[41] = 0;
   out_6206202842202479986[42] = state[4];
   out_6206202842202479986[43] = -state[3];
   out_6206202842202479986[44] = 0;
   out_6206202842202479986[45] = 0;
   out_6206202842202479986[46] = 0;
   out_6206202842202479986[47] = 0;
   out_6206202842202479986[48] = 0;
   out_6206202842202479986[49] = 0;
   out_6206202842202479986[50] = 1;
   out_6206202842202479986[51] = 0;
   out_6206202842202479986[52] = 0;
   out_6206202842202479986[53] = 1;
}
void h_13(double *state, double *unused, double *out_1455872266858412491) {
   out_1455872266858412491[0] = state[3];
   out_1455872266858412491[1] = state[4];
   out_1455872266858412491[2] = state[5];
}
void H_13(double *state, double *unused, double *out_6473872093888187701) {
   out_6473872093888187701[0] = 0;
   out_6473872093888187701[1] = 0;
   out_6473872093888187701[2] = 0;
   out_6473872093888187701[3] = 1;
   out_6473872093888187701[4] = 0;
   out_6473872093888187701[5] = 0;
   out_6473872093888187701[6] = 0;
   out_6473872093888187701[7] = 0;
   out_6473872093888187701[8] = 0;
   out_6473872093888187701[9] = 0;
   out_6473872093888187701[10] = 0;
   out_6473872093888187701[11] = 0;
   out_6473872093888187701[12] = 0;
   out_6473872093888187701[13] = 0;
   out_6473872093888187701[14] = 0;
   out_6473872093888187701[15] = 0;
   out_6473872093888187701[16] = 0;
   out_6473872093888187701[17] = 0;
   out_6473872093888187701[18] = 0;
   out_6473872093888187701[19] = 0;
   out_6473872093888187701[20] = 0;
   out_6473872093888187701[21] = 0;
   out_6473872093888187701[22] = 1;
   out_6473872093888187701[23] = 0;
   out_6473872093888187701[24] = 0;
   out_6473872093888187701[25] = 0;
   out_6473872093888187701[26] = 0;
   out_6473872093888187701[27] = 0;
   out_6473872093888187701[28] = 0;
   out_6473872093888187701[29] = 0;
   out_6473872093888187701[30] = 0;
   out_6473872093888187701[31] = 0;
   out_6473872093888187701[32] = 0;
   out_6473872093888187701[33] = 0;
   out_6473872093888187701[34] = 0;
   out_6473872093888187701[35] = 0;
   out_6473872093888187701[36] = 0;
   out_6473872093888187701[37] = 0;
   out_6473872093888187701[38] = 0;
   out_6473872093888187701[39] = 0;
   out_6473872093888187701[40] = 0;
   out_6473872093888187701[41] = 1;
   out_6473872093888187701[42] = 0;
   out_6473872093888187701[43] = 0;
   out_6473872093888187701[44] = 0;
   out_6473872093888187701[45] = 0;
   out_6473872093888187701[46] = 0;
   out_6473872093888187701[47] = 0;
   out_6473872093888187701[48] = 0;
   out_6473872093888187701[49] = 0;
   out_6473872093888187701[50] = 0;
   out_6473872093888187701[51] = 0;
   out_6473872093888187701[52] = 0;
   out_6473872093888187701[53] = 0;
}
void h_14(double *state, double *unused, double *out_1008373994480511149) {
   out_1008373994480511149[0] = state[6];
   out_1008373994480511149[1] = state[7];
   out_1008373994480511149[2] = state[8];
}
void H_14(double *state, double *unused, double *out_5722905062881035973) {
   out_5722905062881035973[0] = 0;
   out_5722905062881035973[1] = 0;
   out_5722905062881035973[2] = 0;
   out_5722905062881035973[3] = 0;
   out_5722905062881035973[4] = 0;
   out_5722905062881035973[5] = 0;
   out_5722905062881035973[6] = 1;
   out_5722905062881035973[7] = 0;
   out_5722905062881035973[8] = 0;
   out_5722905062881035973[9] = 0;
   out_5722905062881035973[10] = 0;
   out_5722905062881035973[11] = 0;
   out_5722905062881035973[12] = 0;
   out_5722905062881035973[13] = 0;
   out_5722905062881035973[14] = 0;
   out_5722905062881035973[15] = 0;
   out_5722905062881035973[16] = 0;
   out_5722905062881035973[17] = 0;
   out_5722905062881035973[18] = 0;
   out_5722905062881035973[19] = 0;
   out_5722905062881035973[20] = 0;
   out_5722905062881035973[21] = 0;
   out_5722905062881035973[22] = 0;
   out_5722905062881035973[23] = 0;
   out_5722905062881035973[24] = 0;
   out_5722905062881035973[25] = 1;
   out_5722905062881035973[26] = 0;
   out_5722905062881035973[27] = 0;
   out_5722905062881035973[28] = 0;
   out_5722905062881035973[29] = 0;
   out_5722905062881035973[30] = 0;
   out_5722905062881035973[31] = 0;
   out_5722905062881035973[32] = 0;
   out_5722905062881035973[33] = 0;
   out_5722905062881035973[34] = 0;
   out_5722905062881035973[35] = 0;
   out_5722905062881035973[36] = 0;
   out_5722905062881035973[37] = 0;
   out_5722905062881035973[38] = 0;
   out_5722905062881035973[39] = 0;
   out_5722905062881035973[40] = 0;
   out_5722905062881035973[41] = 0;
   out_5722905062881035973[42] = 0;
   out_5722905062881035973[43] = 0;
   out_5722905062881035973[44] = 1;
   out_5722905062881035973[45] = 0;
   out_5722905062881035973[46] = 0;
   out_5722905062881035973[47] = 0;
   out_5722905062881035973[48] = 0;
   out_5722905062881035973[49] = 0;
   out_5722905062881035973[50] = 0;
   out_5722905062881035973[51] = 0;
   out_5722905062881035973[52] = 0;
   out_5722905062881035973[53] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_4, H_4, NULL, in_z, in_R, in_ea, MAHA_THRESH_4);
}
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_10, H_10, NULL, in_z, in_R, in_ea, MAHA_THRESH_10);
}
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_13, H_13, NULL, in_z, in_R, in_ea, MAHA_THRESH_13);
}
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<3, 3, 0>(in_x, in_P, h_14, H_14, NULL, in_z, in_R, in_ea, MAHA_THRESH_14);
}
void pose_err_fun(double *nom_x, double *delta_x, double *out_6780222169695424143) {
  err_fun(nom_x, delta_x, out_6780222169695424143);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8876249299301829416) {
  inv_err_fun(nom_x, true_x, out_8876249299301829416);
}
void pose_H_mod_fun(double *state, double *out_3838064112468561781) {
  H_mod_fun(state, out_3838064112468561781);
}
void pose_f_fun(double *state, double dt, double *out_3082222889402326840) {
  f_fun(state,  dt, out_3082222889402326840);
}
void pose_F_fun(double *state, double dt, double *out_574273013645914746) {
  F_fun(state,  dt, out_574273013645914746);
}
void pose_h_4(double *state, double *unused, double *out_1822046223765446894) {
  h_4(state, unused, out_1822046223765446894);
}
void pose_H_4(double *state, double *unused, double *out_8760598154489031114) {
  H_4(state, unused, out_8760598154489031114);
}
void pose_h_10(double *state, double *unused, double *out_714441176925206643) {
  h_10(state, unused, out_714441176925206643);
}
void pose_H_10(double *state, double *unused, double *out_6206202842202479986) {
  H_10(state, unused, out_6206202842202479986);
}
void pose_h_13(double *state, double *unused, double *out_1455872266858412491) {
  h_13(state, unused, out_1455872266858412491);
}
void pose_H_13(double *state, double *unused, double *out_6473872093888187701) {
  H_13(state, unused, out_6473872093888187701);
}
void pose_h_14(double *state, double *unused, double *out_1008373994480511149) {
  h_14(state, unused, out_1008373994480511149);
}
void pose_H_14(double *state, double *unused, double *out_5722905062881035973) {
  H_14(state, unused, out_5722905062881035973);
}
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF pose = {
  .name = "pose",
  .kinds = { 4, 10, 13, 14 },
  .feature_kinds = {  },
  .f_fun = pose_f_fun,
  .F_fun = pose_F_fun,
  .err_fun = pose_err_fun,
  .inv_err_fun = pose_inv_err_fun,
  .H_mod_fun = pose_H_mod_fun,
  .predict = pose_predict,
  .hs = {
    { 4, pose_h_4 },
    { 10, pose_h_10 },
    { 13, pose_h_13 },
    { 14, pose_h_14 },
  },
  .Hs = {
    { 4, pose_H_4 },
    { 10, pose_H_10 },
    { 13, pose_H_13 },
    { 14, pose_H_14 },
  },
  .updates = {
    { 4, pose_update_4 },
    { 10, pose_update_10 },
    { 13, pose_update_13 },
    { 14, pose_update_14 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_lib_init(pose)
