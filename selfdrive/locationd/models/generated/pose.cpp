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
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_8209796417683535985) {
   out_8209796417683535985[0] = delta_x[0] + nom_x[0];
   out_8209796417683535985[1] = delta_x[1] + nom_x[1];
   out_8209796417683535985[2] = delta_x[2] + nom_x[2];
   out_8209796417683535985[3] = delta_x[3] + nom_x[3];
   out_8209796417683535985[4] = delta_x[4] + nom_x[4];
   out_8209796417683535985[5] = delta_x[5] + nom_x[5];
   out_8209796417683535985[6] = delta_x[6] + nom_x[6];
   out_8209796417683535985[7] = delta_x[7] + nom_x[7];
   out_8209796417683535985[8] = delta_x[8] + nom_x[8];
   out_8209796417683535985[9] = delta_x[9] + nom_x[9];
   out_8209796417683535985[10] = delta_x[10] + nom_x[10];
   out_8209796417683535985[11] = delta_x[11] + nom_x[11];
   out_8209796417683535985[12] = delta_x[12] + nom_x[12];
   out_8209796417683535985[13] = delta_x[13] + nom_x[13];
   out_8209796417683535985[14] = delta_x[14] + nom_x[14];
   out_8209796417683535985[15] = delta_x[15] + nom_x[15];
   out_8209796417683535985[16] = delta_x[16] + nom_x[16];
   out_8209796417683535985[17] = delta_x[17] + nom_x[17];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6976163533526622915) {
   out_6976163533526622915[0] = -nom_x[0] + true_x[0];
   out_6976163533526622915[1] = -nom_x[1] + true_x[1];
   out_6976163533526622915[2] = -nom_x[2] + true_x[2];
   out_6976163533526622915[3] = -nom_x[3] + true_x[3];
   out_6976163533526622915[4] = -nom_x[4] + true_x[4];
   out_6976163533526622915[5] = -nom_x[5] + true_x[5];
   out_6976163533526622915[6] = -nom_x[6] + true_x[6];
   out_6976163533526622915[7] = -nom_x[7] + true_x[7];
   out_6976163533526622915[8] = -nom_x[8] + true_x[8];
   out_6976163533526622915[9] = -nom_x[9] + true_x[9];
   out_6976163533526622915[10] = -nom_x[10] + true_x[10];
   out_6976163533526622915[11] = -nom_x[11] + true_x[11];
   out_6976163533526622915[12] = -nom_x[12] + true_x[12];
   out_6976163533526622915[13] = -nom_x[13] + true_x[13];
   out_6976163533526622915[14] = -nom_x[14] + true_x[14];
   out_6976163533526622915[15] = -nom_x[15] + true_x[15];
   out_6976163533526622915[16] = -nom_x[16] + true_x[16];
   out_6976163533526622915[17] = -nom_x[17] + true_x[17];
}
void H_mod_fun(double *state, double *out_6041543424531509265) {
   out_6041543424531509265[0] = 1.0;
   out_6041543424531509265[1] = 0;
   out_6041543424531509265[2] = 0;
   out_6041543424531509265[3] = 0;
   out_6041543424531509265[4] = 0;
   out_6041543424531509265[5] = 0;
   out_6041543424531509265[6] = 0;
   out_6041543424531509265[7] = 0;
   out_6041543424531509265[8] = 0;
   out_6041543424531509265[9] = 0;
   out_6041543424531509265[10] = 0;
   out_6041543424531509265[11] = 0;
   out_6041543424531509265[12] = 0;
   out_6041543424531509265[13] = 0;
   out_6041543424531509265[14] = 0;
   out_6041543424531509265[15] = 0;
   out_6041543424531509265[16] = 0;
   out_6041543424531509265[17] = 0;
   out_6041543424531509265[18] = 0;
   out_6041543424531509265[19] = 1.0;
   out_6041543424531509265[20] = 0;
   out_6041543424531509265[21] = 0;
   out_6041543424531509265[22] = 0;
   out_6041543424531509265[23] = 0;
   out_6041543424531509265[24] = 0;
   out_6041543424531509265[25] = 0;
   out_6041543424531509265[26] = 0;
   out_6041543424531509265[27] = 0;
   out_6041543424531509265[28] = 0;
   out_6041543424531509265[29] = 0;
   out_6041543424531509265[30] = 0;
   out_6041543424531509265[31] = 0;
   out_6041543424531509265[32] = 0;
   out_6041543424531509265[33] = 0;
   out_6041543424531509265[34] = 0;
   out_6041543424531509265[35] = 0;
   out_6041543424531509265[36] = 0;
   out_6041543424531509265[37] = 0;
   out_6041543424531509265[38] = 1.0;
   out_6041543424531509265[39] = 0;
   out_6041543424531509265[40] = 0;
   out_6041543424531509265[41] = 0;
   out_6041543424531509265[42] = 0;
   out_6041543424531509265[43] = 0;
   out_6041543424531509265[44] = 0;
   out_6041543424531509265[45] = 0;
   out_6041543424531509265[46] = 0;
   out_6041543424531509265[47] = 0;
   out_6041543424531509265[48] = 0;
   out_6041543424531509265[49] = 0;
   out_6041543424531509265[50] = 0;
   out_6041543424531509265[51] = 0;
   out_6041543424531509265[52] = 0;
   out_6041543424531509265[53] = 0;
   out_6041543424531509265[54] = 0;
   out_6041543424531509265[55] = 0;
   out_6041543424531509265[56] = 0;
   out_6041543424531509265[57] = 1.0;
   out_6041543424531509265[58] = 0;
   out_6041543424531509265[59] = 0;
   out_6041543424531509265[60] = 0;
   out_6041543424531509265[61] = 0;
   out_6041543424531509265[62] = 0;
   out_6041543424531509265[63] = 0;
   out_6041543424531509265[64] = 0;
   out_6041543424531509265[65] = 0;
   out_6041543424531509265[66] = 0;
   out_6041543424531509265[67] = 0;
   out_6041543424531509265[68] = 0;
   out_6041543424531509265[69] = 0;
   out_6041543424531509265[70] = 0;
   out_6041543424531509265[71] = 0;
   out_6041543424531509265[72] = 0;
   out_6041543424531509265[73] = 0;
   out_6041543424531509265[74] = 0;
   out_6041543424531509265[75] = 0;
   out_6041543424531509265[76] = 1.0;
   out_6041543424531509265[77] = 0;
   out_6041543424531509265[78] = 0;
   out_6041543424531509265[79] = 0;
   out_6041543424531509265[80] = 0;
   out_6041543424531509265[81] = 0;
   out_6041543424531509265[82] = 0;
   out_6041543424531509265[83] = 0;
   out_6041543424531509265[84] = 0;
   out_6041543424531509265[85] = 0;
   out_6041543424531509265[86] = 0;
   out_6041543424531509265[87] = 0;
   out_6041543424531509265[88] = 0;
   out_6041543424531509265[89] = 0;
   out_6041543424531509265[90] = 0;
   out_6041543424531509265[91] = 0;
   out_6041543424531509265[92] = 0;
   out_6041543424531509265[93] = 0;
   out_6041543424531509265[94] = 0;
   out_6041543424531509265[95] = 1.0;
   out_6041543424531509265[96] = 0;
   out_6041543424531509265[97] = 0;
   out_6041543424531509265[98] = 0;
   out_6041543424531509265[99] = 0;
   out_6041543424531509265[100] = 0;
   out_6041543424531509265[101] = 0;
   out_6041543424531509265[102] = 0;
   out_6041543424531509265[103] = 0;
   out_6041543424531509265[104] = 0;
   out_6041543424531509265[105] = 0;
   out_6041543424531509265[106] = 0;
   out_6041543424531509265[107] = 0;
   out_6041543424531509265[108] = 0;
   out_6041543424531509265[109] = 0;
   out_6041543424531509265[110] = 0;
   out_6041543424531509265[111] = 0;
   out_6041543424531509265[112] = 0;
   out_6041543424531509265[113] = 0;
   out_6041543424531509265[114] = 1.0;
   out_6041543424531509265[115] = 0;
   out_6041543424531509265[116] = 0;
   out_6041543424531509265[117] = 0;
   out_6041543424531509265[118] = 0;
   out_6041543424531509265[119] = 0;
   out_6041543424531509265[120] = 0;
   out_6041543424531509265[121] = 0;
   out_6041543424531509265[122] = 0;
   out_6041543424531509265[123] = 0;
   out_6041543424531509265[124] = 0;
   out_6041543424531509265[125] = 0;
   out_6041543424531509265[126] = 0;
   out_6041543424531509265[127] = 0;
   out_6041543424531509265[128] = 0;
   out_6041543424531509265[129] = 0;
   out_6041543424531509265[130] = 0;
   out_6041543424531509265[131] = 0;
   out_6041543424531509265[132] = 0;
   out_6041543424531509265[133] = 1.0;
   out_6041543424531509265[134] = 0;
   out_6041543424531509265[135] = 0;
   out_6041543424531509265[136] = 0;
   out_6041543424531509265[137] = 0;
   out_6041543424531509265[138] = 0;
   out_6041543424531509265[139] = 0;
   out_6041543424531509265[140] = 0;
   out_6041543424531509265[141] = 0;
   out_6041543424531509265[142] = 0;
   out_6041543424531509265[143] = 0;
   out_6041543424531509265[144] = 0;
   out_6041543424531509265[145] = 0;
   out_6041543424531509265[146] = 0;
   out_6041543424531509265[147] = 0;
   out_6041543424531509265[148] = 0;
   out_6041543424531509265[149] = 0;
   out_6041543424531509265[150] = 0;
   out_6041543424531509265[151] = 0;
   out_6041543424531509265[152] = 1.0;
   out_6041543424531509265[153] = 0;
   out_6041543424531509265[154] = 0;
   out_6041543424531509265[155] = 0;
   out_6041543424531509265[156] = 0;
   out_6041543424531509265[157] = 0;
   out_6041543424531509265[158] = 0;
   out_6041543424531509265[159] = 0;
   out_6041543424531509265[160] = 0;
   out_6041543424531509265[161] = 0;
   out_6041543424531509265[162] = 0;
   out_6041543424531509265[163] = 0;
   out_6041543424531509265[164] = 0;
   out_6041543424531509265[165] = 0;
   out_6041543424531509265[166] = 0;
   out_6041543424531509265[167] = 0;
   out_6041543424531509265[168] = 0;
   out_6041543424531509265[169] = 0;
   out_6041543424531509265[170] = 0;
   out_6041543424531509265[171] = 1.0;
   out_6041543424531509265[172] = 0;
   out_6041543424531509265[173] = 0;
   out_6041543424531509265[174] = 0;
   out_6041543424531509265[175] = 0;
   out_6041543424531509265[176] = 0;
   out_6041543424531509265[177] = 0;
   out_6041543424531509265[178] = 0;
   out_6041543424531509265[179] = 0;
   out_6041543424531509265[180] = 0;
   out_6041543424531509265[181] = 0;
   out_6041543424531509265[182] = 0;
   out_6041543424531509265[183] = 0;
   out_6041543424531509265[184] = 0;
   out_6041543424531509265[185] = 0;
   out_6041543424531509265[186] = 0;
   out_6041543424531509265[187] = 0;
   out_6041543424531509265[188] = 0;
   out_6041543424531509265[189] = 0;
   out_6041543424531509265[190] = 1.0;
   out_6041543424531509265[191] = 0;
   out_6041543424531509265[192] = 0;
   out_6041543424531509265[193] = 0;
   out_6041543424531509265[194] = 0;
   out_6041543424531509265[195] = 0;
   out_6041543424531509265[196] = 0;
   out_6041543424531509265[197] = 0;
   out_6041543424531509265[198] = 0;
   out_6041543424531509265[199] = 0;
   out_6041543424531509265[200] = 0;
   out_6041543424531509265[201] = 0;
   out_6041543424531509265[202] = 0;
   out_6041543424531509265[203] = 0;
   out_6041543424531509265[204] = 0;
   out_6041543424531509265[205] = 0;
   out_6041543424531509265[206] = 0;
   out_6041543424531509265[207] = 0;
   out_6041543424531509265[208] = 0;
   out_6041543424531509265[209] = 1.0;
   out_6041543424531509265[210] = 0;
   out_6041543424531509265[211] = 0;
   out_6041543424531509265[212] = 0;
   out_6041543424531509265[213] = 0;
   out_6041543424531509265[214] = 0;
   out_6041543424531509265[215] = 0;
   out_6041543424531509265[216] = 0;
   out_6041543424531509265[217] = 0;
   out_6041543424531509265[218] = 0;
   out_6041543424531509265[219] = 0;
   out_6041543424531509265[220] = 0;
   out_6041543424531509265[221] = 0;
   out_6041543424531509265[222] = 0;
   out_6041543424531509265[223] = 0;
   out_6041543424531509265[224] = 0;
   out_6041543424531509265[225] = 0;
   out_6041543424531509265[226] = 0;
   out_6041543424531509265[227] = 0;
   out_6041543424531509265[228] = 1.0;
   out_6041543424531509265[229] = 0;
   out_6041543424531509265[230] = 0;
   out_6041543424531509265[231] = 0;
   out_6041543424531509265[232] = 0;
   out_6041543424531509265[233] = 0;
   out_6041543424531509265[234] = 0;
   out_6041543424531509265[235] = 0;
   out_6041543424531509265[236] = 0;
   out_6041543424531509265[237] = 0;
   out_6041543424531509265[238] = 0;
   out_6041543424531509265[239] = 0;
   out_6041543424531509265[240] = 0;
   out_6041543424531509265[241] = 0;
   out_6041543424531509265[242] = 0;
   out_6041543424531509265[243] = 0;
   out_6041543424531509265[244] = 0;
   out_6041543424531509265[245] = 0;
   out_6041543424531509265[246] = 0;
   out_6041543424531509265[247] = 1.0;
   out_6041543424531509265[248] = 0;
   out_6041543424531509265[249] = 0;
   out_6041543424531509265[250] = 0;
   out_6041543424531509265[251] = 0;
   out_6041543424531509265[252] = 0;
   out_6041543424531509265[253] = 0;
   out_6041543424531509265[254] = 0;
   out_6041543424531509265[255] = 0;
   out_6041543424531509265[256] = 0;
   out_6041543424531509265[257] = 0;
   out_6041543424531509265[258] = 0;
   out_6041543424531509265[259] = 0;
   out_6041543424531509265[260] = 0;
   out_6041543424531509265[261] = 0;
   out_6041543424531509265[262] = 0;
   out_6041543424531509265[263] = 0;
   out_6041543424531509265[264] = 0;
   out_6041543424531509265[265] = 0;
   out_6041543424531509265[266] = 1.0;
   out_6041543424531509265[267] = 0;
   out_6041543424531509265[268] = 0;
   out_6041543424531509265[269] = 0;
   out_6041543424531509265[270] = 0;
   out_6041543424531509265[271] = 0;
   out_6041543424531509265[272] = 0;
   out_6041543424531509265[273] = 0;
   out_6041543424531509265[274] = 0;
   out_6041543424531509265[275] = 0;
   out_6041543424531509265[276] = 0;
   out_6041543424531509265[277] = 0;
   out_6041543424531509265[278] = 0;
   out_6041543424531509265[279] = 0;
   out_6041543424531509265[280] = 0;
   out_6041543424531509265[281] = 0;
   out_6041543424531509265[282] = 0;
   out_6041543424531509265[283] = 0;
   out_6041543424531509265[284] = 0;
   out_6041543424531509265[285] = 1.0;
   out_6041543424531509265[286] = 0;
   out_6041543424531509265[287] = 0;
   out_6041543424531509265[288] = 0;
   out_6041543424531509265[289] = 0;
   out_6041543424531509265[290] = 0;
   out_6041543424531509265[291] = 0;
   out_6041543424531509265[292] = 0;
   out_6041543424531509265[293] = 0;
   out_6041543424531509265[294] = 0;
   out_6041543424531509265[295] = 0;
   out_6041543424531509265[296] = 0;
   out_6041543424531509265[297] = 0;
   out_6041543424531509265[298] = 0;
   out_6041543424531509265[299] = 0;
   out_6041543424531509265[300] = 0;
   out_6041543424531509265[301] = 0;
   out_6041543424531509265[302] = 0;
   out_6041543424531509265[303] = 0;
   out_6041543424531509265[304] = 1.0;
   out_6041543424531509265[305] = 0;
   out_6041543424531509265[306] = 0;
   out_6041543424531509265[307] = 0;
   out_6041543424531509265[308] = 0;
   out_6041543424531509265[309] = 0;
   out_6041543424531509265[310] = 0;
   out_6041543424531509265[311] = 0;
   out_6041543424531509265[312] = 0;
   out_6041543424531509265[313] = 0;
   out_6041543424531509265[314] = 0;
   out_6041543424531509265[315] = 0;
   out_6041543424531509265[316] = 0;
   out_6041543424531509265[317] = 0;
   out_6041543424531509265[318] = 0;
   out_6041543424531509265[319] = 0;
   out_6041543424531509265[320] = 0;
   out_6041543424531509265[321] = 0;
   out_6041543424531509265[322] = 0;
   out_6041543424531509265[323] = 1.0;
}
void f_fun(double *state, double dt, double *out_5172544763827630996) {
   out_5172544763827630996[0] = atan2((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), -(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]));
   out_5172544763827630996[1] = asin(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]));
   out_5172544763827630996[2] = atan2(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), -(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]));
   out_5172544763827630996[3] = dt*state[12] + state[3];
   out_5172544763827630996[4] = dt*state[13] + state[4];
   out_5172544763827630996[5] = dt*state[14] + state[5];
   out_5172544763827630996[6] = state[6];
   out_5172544763827630996[7] = state[7];
   out_5172544763827630996[8] = state[8];
   out_5172544763827630996[9] = state[9];
   out_5172544763827630996[10] = state[10];
   out_5172544763827630996[11] = state[11];
   out_5172544763827630996[12] = state[12];
   out_5172544763827630996[13] = state[13];
   out_5172544763827630996[14] = state[14];
   out_5172544763827630996[15] = state[15];
   out_5172544763827630996[16] = state[16];
   out_5172544763827630996[17] = state[17];
}
void F_fun(double *state, double dt, double *out_1597941670573176708) {
   out_1597941670573176708[0] = ((-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*cos(state[0])*cos(state[1]) - sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*cos(state[0])*cos(state[1]) - sin(dt*state[6])*sin(state[0])*cos(dt*state[7])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1597941670573176708[1] = ((-sin(dt*state[6])*sin(dt*state[8]) - sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*cos(state[1]) - (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*sin(state[1]) - sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(state[0]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*sin(state[1]) + (-sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) + sin(dt*state[8])*cos(dt*state[6]))*cos(state[1]) - sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(state[0]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1597941670573176708[2] = 0;
   out_1597941670573176708[3] = 0;
   out_1597941670573176708[4] = 0;
   out_1597941670573176708[5] = 0;
   out_1597941670573176708[6] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(dt*cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) - dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1597941670573176708[7] = (-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[6])*sin(dt*state[7])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[6])*sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) - dt*sin(dt*state[6])*sin(state[1])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + (-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))*(-dt*sin(dt*state[7])*cos(dt*state[6])*cos(state[0])*cos(state[1]) + dt*sin(dt*state[8])*sin(state[0])*cos(dt*state[6])*cos(dt*state[7])*cos(state[1]) - dt*sin(state[1])*cos(dt*state[6])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1597941670573176708[8] = ((dt*sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + dt*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (dt*sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]))*(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2)) + ((dt*sin(dt*state[6])*sin(dt*state[8]) + dt*sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (-dt*sin(dt*state[6])*cos(dt*state[8]) + dt*sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]))*(-(sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) + (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) - sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/(pow(-(sin(dt*state[6])*sin(dt*state[8]) + sin(dt*state[7])*cos(dt*state[6])*cos(dt*state[8]))*sin(state[1]) + (-sin(dt*state[6])*cos(dt*state[8]) + sin(dt*state[7])*sin(dt*state[8])*cos(dt*state[6]))*sin(state[0])*cos(state[1]) + cos(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2) + pow((sin(dt*state[6])*sin(dt*state[7])*sin(dt*state[8]) + cos(dt*state[6])*cos(dt*state[8]))*sin(state[0])*cos(state[1]) - (sin(dt*state[6])*sin(dt*state[7])*cos(dt*state[8]) - sin(dt*state[8])*cos(dt*state[6]))*sin(state[1]) + sin(dt*state[6])*cos(dt*state[7])*cos(state[0])*cos(state[1]), 2));
   out_1597941670573176708[9] = 0;
   out_1597941670573176708[10] = 0;
   out_1597941670573176708[11] = 0;
   out_1597941670573176708[12] = 0;
   out_1597941670573176708[13] = 0;
   out_1597941670573176708[14] = 0;
   out_1597941670573176708[15] = 0;
   out_1597941670573176708[16] = 0;
   out_1597941670573176708[17] = 0;
   out_1597941670573176708[18] = (-sin(dt*state[7])*sin(state[0])*cos(state[1]) - sin(dt*state[8])*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1597941670573176708[19] = (-sin(dt*state[7])*sin(state[1])*cos(state[0]) + sin(dt*state[8])*sin(state[0])*sin(state[1])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1597941670573176708[20] = 0;
   out_1597941670573176708[21] = 0;
   out_1597941670573176708[22] = 0;
   out_1597941670573176708[23] = 0;
   out_1597941670573176708[24] = 0;
   out_1597941670573176708[25] = (dt*sin(dt*state[7])*sin(dt*state[8])*sin(state[0])*cos(state[1]) - dt*sin(dt*state[7])*sin(state[1])*cos(dt*state[8]) + dt*cos(dt*state[7])*cos(state[0])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1597941670573176708[26] = (-dt*sin(dt*state[8])*sin(state[1])*cos(dt*state[7]) - dt*sin(state[0])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/sqrt(1 - pow(sin(dt*state[7])*cos(state[0])*cos(state[1]) - sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1]) + sin(state[1])*cos(dt*state[7])*cos(dt*state[8]), 2));
   out_1597941670573176708[27] = 0;
   out_1597941670573176708[28] = 0;
   out_1597941670573176708[29] = 0;
   out_1597941670573176708[30] = 0;
   out_1597941670573176708[31] = 0;
   out_1597941670573176708[32] = 0;
   out_1597941670573176708[33] = 0;
   out_1597941670573176708[34] = 0;
   out_1597941670573176708[35] = 0;
   out_1597941670573176708[36] = ((sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1597941670573176708[37] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-sin(dt*state[7])*sin(state[2])*cos(state[0])*cos(state[1]) + sin(dt*state[8])*sin(state[0])*sin(state[2])*cos(dt*state[7])*cos(state[1]) - sin(state[1])*sin(state[2])*cos(dt*state[7])*cos(dt*state[8]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(-sin(dt*state[7])*cos(state[0])*cos(state[1])*cos(state[2]) + sin(dt*state[8])*sin(state[0])*cos(dt*state[7])*cos(state[1])*cos(state[2]) - sin(state[1])*cos(dt*state[7])*cos(dt*state[8])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1597941670573176708[38] = ((-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (-sin(state[0])*sin(state[1])*sin(state[2]) - cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1597941670573176708[39] = 0;
   out_1597941670573176708[40] = 0;
   out_1597941670573176708[41] = 0;
   out_1597941670573176708[42] = 0;
   out_1597941670573176708[43] = (-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))*(dt*(sin(state[0])*cos(state[2]) - sin(state[1])*sin(state[2])*cos(state[0]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*sin(state[2])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + ((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))*(dt*(-sin(state[0])*sin(state[2]) - sin(state[1])*cos(state[0])*cos(state[2]))*cos(dt*state[7]) - dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[7])*sin(dt*state[8]) - dt*sin(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1597941670573176708[44] = (dt*(sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*sin(state[2])*cos(dt*state[7])*cos(state[1]))*(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2)) + (dt*(sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*cos(dt*state[7])*cos(dt*state[8]) - dt*sin(dt*state[8])*cos(dt*state[7])*cos(state[1])*cos(state[2]))*((-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) - (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) - sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]))/(pow(-(sin(state[0])*sin(state[2]) + sin(state[1])*cos(state[0])*cos(state[2]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*cos(state[2]) - sin(state[2])*cos(state[0]))*sin(dt*state[8])*cos(dt*state[7]) + cos(dt*state[7])*cos(dt*state[8])*cos(state[1])*cos(state[2]), 2) + pow(-(-sin(state[0])*cos(state[2]) + sin(state[1])*sin(state[2])*cos(state[0]))*sin(dt*state[7]) + (sin(state[0])*sin(state[1])*sin(state[2]) + cos(state[0])*cos(state[2]))*sin(dt*state[8])*cos(dt*state[7]) + sin(state[2])*cos(dt*state[7])*cos(dt*state[8])*cos(state[1]), 2));
   out_1597941670573176708[45] = 0;
   out_1597941670573176708[46] = 0;
   out_1597941670573176708[47] = 0;
   out_1597941670573176708[48] = 0;
   out_1597941670573176708[49] = 0;
   out_1597941670573176708[50] = 0;
   out_1597941670573176708[51] = 0;
   out_1597941670573176708[52] = 0;
   out_1597941670573176708[53] = 0;
   out_1597941670573176708[54] = 0;
   out_1597941670573176708[55] = 0;
   out_1597941670573176708[56] = 0;
   out_1597941670573176708[57] = 1;
   out_1597941670573176708[58] = 0;
   out_1597941670573176708[59] = 0;
   out_1597941670573176708[60] = 0;
   out_1597941670573176708[61] = 0;
   out_1597941670573176708[62] = 0;
   out_1597941670573176708[63] = 0;
   out_1597941670573176708[64] = 0;
   out_1597941670573176708[65] = 0;
   out_1597941670573176708[66] = dt;
   out_1597941670573176708[67] = 0;
   out_1597941670573176708[68] = 0;
   out_1597941670573176708[69] = 0;
   out_1597941670573176708[70] = 0;
   out_1597941670573176708[71] = 0;
   out_1597941670573176708[72] = 0;
   out_1597941670573176708[73] = 0;
   out_1597941670573176708[74] = 0;
   out_1597941670573176708[75] = 0;
   out_1597941670573176708[76] = 1;
   out_1597941670573176708[77] = 0;
   out_1597941670573176708[78] = 0;
   out_1597941670573176708[79] = 0;
   out_1597941670573176708[80] = 0;
   out_1597941670573176708[81] = 0;
   out_1597941670573176708[82] = 0;
   out_1597941670573176708[83] = 0;
   out_1597941670573176708[84] = 0;
   out_1597941670573176708[85] = dt;
   out_1597941670573176708[86] = 0;
   out_1597941670573176708[87] = 0;
   out_1597941670573176708[88] = 0;
   out_1597941670573176708[89] = 0;
   out_1597941670573176708[90] = 0;
   out_1597941670573176708[91] = 0;
   out_1597941670573176708[92] = 0;
   out_1597941670573176708[93] = 0;
   out_1597941670573176708[94] = 0;
   out_1597941670573176708[95] = 1;
   out_1597941670573176708[96] = 0;
   out_1597941670573176708[97] = 0;
   out_1597941670573176708[98] = 0;
   out_1597941670573176708[99] = 0;
   out_1597941670573176708[100] = 0;
   out_1597941670573176708[101] = 0;
   out_1597941670573176708[102] = 0;
   out_1597941670573176708[103] = 0;
   out_1597941670573176708[104] = dt;
   out_1597941670573176708[105] = 0;
   out_1597941670573176708[106] = 0;
   out_1597941670573176708[107] = 0;
   out_1597941670573176708[108] = 0;
   out_1597941670573176708[109] = 0;
   out_1597941670573176708[110] = 0;
   out_1597941670573176708[111] = 0;
   out_1597941670573176708[112] = 0;
   out_1597941670573176708[113] = 0;
   out_1597941670573176708[114] = 1;
   out_1597941670573176708[115] = 0;
   out_1597941670573176708[116] = 0;
   out_1597941670573176708[117] = 0;
   out_1597941670573176708[118] = 0;
   out_1597941670573176708[119] = 0;
   out_1597941670573176708[120] = 0;
   out_1597941670573176708[121] = 0;
   out_1597941670573176708[122] = 0;
   out_1597941670573176708[123] = 0;
   out_1597941670573176708[124] = 0;
   out_1597941670573176708[125] = 0;
   out_1597941670573176708[126] = 0;
   out_1597941670573176708[127] = 0;
   out_1597941670573176708[128] = 0;
   out_1597941670573176708[129] = 0;
   out_1597941670573176708[130] = 0;
   out_1597941670573176708[131] = 0;
   out_1597941670573176708[132] = 0;
   out_1597941670573176708[133] = 1;
   out_1597941670573176708[134] = 0;
   out_1597941670573176708[135] = 0;
   out_1597941670573176708[136] = 0;
   out_1597941670573176708[137] = 0;
   out_1597941670573176708[138] = 0;
   out_1597941670573176708[139] = 0;
   out_1597941670573176708[140] = 0;
   out_1597941670573176708[141] = 0;
   out_1597941670573176708[142] = 0;
   out_1597941670573176708[143] = 0;
   out_1597941670573176708[144] = 0;
   out_1597941670573176708[145] = 0;
   out_1597941670573176708[146] = 0;
   out_1597941670573176708[147] = 0;
   out_1597941670573176708[148] = 0;
   out_1597941670573176708[149] = 0;
   out_1597941670573176708[150] = 0;
   out_1597941670573176708[151] = 0;
   out_1597941670573176708[152] = 1;
   out_1597941670573176708[153] = 0;
   out_1597941670573176708[154] = 0;
   out_1597941670573176708[155] = 0;
   out_1597941670573176708[156] = 0;
   out_1597941670573176708[157] = 0;
   out_1597941670573176708[158] = 0;
   out_1597941670573176708[159] = 0;
   out_1597941670573176708[160] = 0;
   out_1597941670573176708[161] = 0;
   out_1597941670573176708[162] = 0;
   out_1597941670573176708[163] = 0;
   out_1597941670573176708[164] = 0;
   out_1597941670573176708[165] = 0;
   out_1597941670573176708[166] = 0;
   out_1597941670573176708[167] = 0;
   out_1597941670573176708[168] = 0;
   out_1597941670573176708[169] = 0;
   out_1597941670573176708[170] = 0;
   out_1597941670573176708[171] = 1;
   out_1597941670573176708[172] = 0;
   out_1597941670573176708[173] = 0;
   out_1597941670573176708[174] = 0;
   out_1597941670573176708[175] = 0;
   out_1597941670573176708[176] = 0;
   out_1597941670573176708[177] = 0;
   out_1597941670573176708[178] = 0;
   out_1597941670573176708[179] = 0;
   out_1597941670573176708[180] = 0;
   out_1597941670573176708[181] = 0;
   out_1597941670573176708[182] = 0;
   out_1597941670573176708[183] = 0;
   out_1597941670573176708[184] = 0;
   out_1597941670573176708[185] = 0;
   out_1597941670573176708[186] = 0;
   out_1597941670573176708[187] = 0;
   out_1597941670573176708[188] = 0;
   out_1597941670573176708[189] = 0;
   out_1597941670573176708[190] = 1;
   out_1597941670573176708[191] = 0;
   out_1597941670573176708[192] = 0;
   out_1597941670573176708[193] = 0;
   out_1597941670573176708[194] = 0;
   out_1597941670573176708[195] = 0;
   out_1597941670573176708[196] = 0;
   out_1597941670573176708[197] = 0;
   out_1597941670573176708[198] = 0;
   out_1597941670573176708[199] = 0;
   out_1597941670573176708[200] = 0;
   out_1597941670573176708[201] = 0;
   out_1597941670573176708[202] = 0;
   out_1597941670573176708[203] = 0;
   out_1597941670573176708[204] = 0;
   out_1597941670573176708[205] = 0;
   out_1597941670573176708[206] = 0;
   out_1597941670573176708[207] = 0;
   out_1597941670573176708[208] = 0;
   out_1597941670573176708[209] = 1;
   out_1597941670573176708[210] = 0;
   out_1597941670573176708[211] = 0;
   out_1597941670573176708[212] = 0;
   out_1597941670573176708[213] = 0;
   out_1597941670573176708[214] = 0;
   out_1597941670573176708[215] = 0;
   out_1597941670573176708[216] = 0;
   out_1597941670573176708[217] = 0;
   out_1597941670573176708[218] = 0;
   out_1597941670573176708[219] = 0;
   out_1597941670573176708[220] = 0;
   out_1597941670573176708[221] = 0;
   out_1597941670573176708[222] = 0;
   out_1597941670573176708[223] = 0;
   out_1597941670573176708[224] = 0;
   out_1597941670573176708[225] = 0;
   out_1597941670573176708[226] = 0;
   out_1597941670573176708[227] = 0;
   out_1597941670573176708[228] = 1;
   out_1597941670573176708[229] = 0;
   out_1597941670573176708[230] = 0;
   out_1597941670573176708[231] = 0;
   out_1597941670573176708[232] = 0;
   out_1597941670573176708[233] = 0;
   out_1597941670573176708[234] = 0;
   out_1597941670573176708[235] = 0;
   out_1597941670573176708[236] = 0;
   out_1597941670573176708[237] = 0;
   out_1597941670573176708[238] = 0;
   out_1597941670573176708[239] = 0;
   out_1597941670573176708[240] = 0;
   out_1597941670573176708[241] = 0;
   out_1597941670573176708[242] = 0;
   out_1597941670573176708[243] = 0;
   out_1597941670573176708[244] = 0;
   out_1597941670573176708[245] = 0;
   out_1597941670573176708[246] = 0;
   out_1597941670573176708[247] = 1;
   out_1597941670573176708[248] = 0;
   out_1597941670573176708[249] = 0;
   out_1597941670573176708[250] = 0;
   out_1597941670573176708[251] = 0;
   out_1597941670573176708[252] = 0;
   out_1597941670573176708[253] = 0;
   out_1597941670573176708[254] = 0;
   out_1597941670573176708[255] = 0;
   out_1597941670573176708[256] = 0;
   out_1597941670573176708[257] = 0;
   out_1597941670573176708[258] = 0;
   out_1597941670573176708[259] = 0;
   out_1597941670573176708[260] = 0;
   out_1597941670573176708[261] = 0;
   out_1597941670573176708[262] = 0;
   out_1597941670573176708[263] = 0;
   out_1597941670573176708[264] = 0;
   out_1597941670573176708[265] = 0;
   out_1597941670573176708[266] = 1;
   out_1597941670573176708[267] = 0;
   out_1597941670573176708[268] = 0;
   out_1597941670573176708[269] = 0;
   out_1597941670573176708[270] = 0;
   out_1597941670573176708[271] = 0;
   out_1597941670573176708[272] = 0;
   out_1597941670573176708[273] = 0;
   out_1597941670573176708[274] = 0;
   out_1597941670573176708[275] = 0;
   out_1597941670573176708[276] = 0;
   out_1597941670573176708[277] = 0;
   out_1597941670573176708[278] = 0;
   out_1597941670573176708[279] = 0;
   out_1597941670573176708[280] = 0;
   out_1597941670573176708[281] = 0;
   out_1597941670573176708[282] = 0;
   out_1597941670573176708[283] = 0;
   out_1597941670573176708[284] = 0;
   out_1597941670573176708[285] = 1;
   out_1597941670573176708[286] = 0;
   out_1597941670573176708[287] = 0;
   out_1597941670573176708[288] = 0;
   out_1597941670573176708[289] = 0;
   out_1597941670573176708[290] = 0;
   out_1597941670573176708[291] = 0;
   out_1597941670573176708[292] = 0;
   out_1597941670573176708[293] = 0;
   out_1597941670573176708[294] = 0;
   out_1597941670573176708[295] = 0;
   out_1597941670573176708[296] = 0;
   out_1597941670573176708[297] = 0;
   out_1597941670573176708[298] = 0;
   out_1597941670573176708[299] = 0;
   out_1597941670573176708[300] = 0;
   out_1597941670573176708[301] = 0;
   out_1597941670573176708[302] = 0;
   out_1597941670573176708[303] = 0;
   out_1597941670573176708[304] = 1;
   out_1597941670573176708[305] = 0;
   out_1597941670573176708[306] = 0;
   out_1597941670573176708[307] = 0;
   out_1597941670573176708[308] = 0;
   out_1597941670573176708[309] = 0;
   out_1597941670573176708[310] = 0;
   out_1597941670573176708[311] = 0;
   out_1597941670573176708[312] = 0;
   out_1597941670573176708[313] = 0;
   out_1597941670573176708[314] = 0;
   out_1597941670573176708[315] = 0;
   out_1597941670573176708[316] = 0;
   out_1597941670573176708[317] = 0;
   out_1597941670573176708[318] = 0;
   out_1597941670573176708[319] = 0;
   out_1597941670573176708[320] = 0;
   out_1597941670573176708[321] = 0;
   out_1597941670573176708[322] = 0;
   out_1597941670573176708[323] = 1;
}
void h_4(double *state, double *unused, double *out_7358615542883756797) {
   out_7358615542883756797[0] = state[6] + state[9];
   out_7358615542883756797[1] = state[7] + state[10];
   out_7358615542883756797[2] = state[8] + state[11];
}
void H_4(double *state, double *unused, double *out_8247164004478167319) {
   out_8247164004478167319[0] = 0;
   out_8247164004478167319[1] = 0;
   out_8247164004478167319[2] = 0;
   out_8247164004478167319[3] = 0;
   out_8247164004478167319[4] = 0;
   out_8247164004478167319[5] = 0;
   out_8247164004478167319[6] = 1;
   out_8247164004478167319[7] = 0;
   out_8247164004478167319[8] = 0;
   out_8247164004478167319[9] = 1;
   out_8247164004478167319[10] = 0;
   out_8247164004478167319[11] = 0;
   out_8247164004478167319[12] = 0;
   out_8247164004478167319[13] = 0;
   out_8247164004478167319[14] = 0;
   out_8247164004478167319[15] = 0;
   out_8247164004478167319[16] = 0;
   out_8247164004478167319[17] = 0;
   out_8247164004478167319[18] = 0;
   out_8247164004478167319[19] = 0;
   out_8247164004478167319[20] = 0;
   out_8247164004478167319[21] = 0;
   out_8247164004478167319[22] = 0;
   out_8247164004478167319[23] = 0;
   out_8247164004478167319[24] = 0;
   out_8247164004478167319[25] = 1;
   out_8247164004478167319[26] = 0;
   out_8247164004478167319[27] = 0;
   out_8247164004478167319[28] = 1;
   out_8247164004478167319[29] = 0;
   out_8247164004478167319[30] = 0;
   out_8247164004478167319[31] = 0;
   out_8247164004478167319[32] = 0;
   out_8247164004478167319[33] = 0;
   out_8247164004478167319[34] = 0;
   out_8247164004478167319[35] = 0;
   out_8247164004478167319[36] = 0;
   out_8247164004478167319[37] = 0;
   out_8247164004478167319[38] = 0;
   out_8247164004478167319[39] = 0;
   out_8247164004478167319[40] = 0;
   out_8247164004478167319[41] = 0;
   out_8247164004478167319[42] = 0;
   out_8247164004478167319[43] = 0;
   out_8247164004478167319[44] = 1;
   out_8247164004478167319[45] = 0;
   out_8247164004478167319[46] = 0;
   out_8247164004478167319[47] = 1;
   out_8247164004478167319[48] = 0;
   out_8247164004478167319[49] = 0;
   out_8247164004478167319[50] = 0;
   out_8247164004478167319[51] = 0;
   out_8247164004478167319[52] = 0;
   out_8247164004478167319[53] = 0;
}
void h_10(double *state, double *unused, double *out_897342477259466820) {
   out_897342477259466820[0] = 9.8100000000000005*sin(state[1]) - state[4]*state[8] + state[5]*state[7] + state[12] + state[15];
   out_897342477259466820[1] = -9.8100000000000005*sin(state[0])*cos(state[1]) + state[3]*state[8] - state[5]*state[6] + state[13] + state[16];
   out_897342477259466820[2] = -9.8100000000000005*cos(state[0])*cos(state[1]) - state[3]*state[7] + state[4]*state[6] + state[14] + state[17];
}
void H_10(double *state, double *unused, double *out_7119477149316586896) {
   out_7119477149316586896[0] = 0;
   out_7119477149316586896[1] = 9.8100000000000005*cos(state[1]);
   out_7119477149316586896[2] = 0;
   out_7119477149316586896[3] = 0;
   out_7119477149316586896[4] = -state[8];
   out_7119477149316586896[5] = state[7];
   out_7119477149316586896[6] = 0;
   out_7119477149316586896[7] = state[5];
   out_7119477149316586896[8] = -state[4];
   out_7119477149316586896[9] = 0;
   out_7119477149316586896[10] = 0;
   out_7119477149316586896[11] = 0;
   out_7119477149316586896[12] = 1;
   out_7119477149316586896[13] = 0;
   out_7119477149316586896[14] = 0;
   out_7119477149316586896[15] = 1;
   out_7119477149316586896[16] = 0;
   out_7119477149316586896[17] = 0;
   out_7119477149316586896[18] = -9.8100000000000005*cos(state[0])*cos(state[1]);
   out_7119477149316586896[19] = 9.8100000000000005*sin(state[0])*sin(state[1]);
   out_7119477149316586896[20] = 0;
   out_7119477149316586896[21] = state[8];
   out_7119477149316586896[22] = 0;
   out_7119477149316586896[23] = -state[6];
   out_7119477149316586896[24] = -state[5];
   out_7119477149316586896[25] = 0;
   out_7119477149316586896[26] = state[3];
   out_7119477149316586896[27] = 0;
   out_7119477149316586896[28] = 0;
   out_7119477149316586896[29] = 0;
   out_7119477149316586896[30] = 0;
   out_7119477149316586896[31] = 1;
   out_7119477149316586896[32] = 0;
   out_7119477149316586896[33] = 0;
   out_7119477149316586896[34] = 1;
   out_7119477149316586896[35] = 0;
   out_7119477149316586896[36] = 9.8100000000000005*sin(state[0])*cos(state[1]);
   out_7119477149316586896[37] = 9.8100000000000005*sin(state[1])*cos(state[0]);
   out_7119477149316586896[38] = 0;
   out_7119477149316586896[39] = -state[7];
   out_7119477149316586896[40] = state[6];
   out_7119477149316586896[41] = 0;
   out_7119477149316586896[42] = state[4];
   out_7119477149316586896[43] = -state[3];
   out_7119477149316586896[44] = 0;
   out_7119477149316586896[45] = 0;
   out_7119477149316586896[46] = 0;
   out_7119477149316586896[47] = 0;
   out_7119477149316586896[48] = 0;
   out_7119477149316586896[49] = 0;
   out_7119477149316586896[50] = 1;
   out_7119477149316586896[51] = 0;
   out_7119477149316586896[52] = 0;
   out_7119477149316586896[53] = 1;
}
void h_13(double *state, double *unused, double *out_9114003749945995778) {
   out_9114003749945995778[0] = state[3];
   out_9114003749945995778[1] = state[4];
   out_9114003749945995778[2] = state[5];
}
void H_13(double *state, double *unused, double *out_5034890179145834518) {
   out_5034890179145834518[0] = 0;
   out_5034890179145834518[1] = 0;
   out_5034890179145834518[2] = 0;
   out_5034890179145834518[3] = 1;
   out_5034890179145834518[4] = 0;
   out_5034890179145834518[5] = 0;
   out_5034890179145834518[6] = 0;
   out_5034890179145834518[7] = 0;
   out_5034890179145834518[8] = 0;
   out_5034890179145834518[9] = 0;
   out_5034890179145834518[10] = 0;
   out_5034890179145834518[11] = 0;
   out_5034890179145834518[12] = 0;
   out_5034890179145834518[13] = 0;
   out_5034890179145834518[14] = 0;
   out_5034890179145834518[15] = 0;
   out_5034890179145834518[16] = 0;
   out_5034890179145834518[17] = 0;
   out_5034890179145834518[18] = 0;
   out_5034890179145834518[19] = 0;
   out_5034890179145834518[20] = 0;
   out_5034890179145834518[21] = 0;
   out_5034890179145834518[22] = 1;
   out_5034890179145834518[23] = 0;
   out_5034890179145834518[24] = 0;
   out_5034890179145834518[25] = 0;
   out_5034890179145834518[26] = 0;
   out_5034890179145834518[27] = 0;
   out_5034890179145834518[28] = 0;
   out_5034890179145834518[29] = 0;
   out_5034890179145834518[30] = 0;
   out_5034890179145834518[31] = 0;
   out_5034890179145834518[32] = 0;
   out_5034890179145834518[33] = 0;
   out_5034890179145834518[34] = 0;
   out_5034890179145834518[35] = 0;
   out_5034890179145834518[36] = 0;
   out_5034890179145834518[37] = 0;
   out_5034890179145834518[38] = 0;
   out_5034890179145834518[39] = 0;
   out_5034890179145834518[40] = 0;
   out_5034890179145834518[41] = 1;
   out_5034890179145834518[42] = 0;
   out_5034890179145834518[43] = 0;
   out_5034890179145834518[44] = 0;
   out_5034890179145834518[45] = 0;
   out_5034890179145834518[46] = 0;
   out_5034890179145834518[47] = 0;
   out_5034890179145834518[48] = 0;
   out_5034890179145834518[49] = 0;
   out_5034890179145834518[50] = 0;
   out_5034890179145834518[51] = 0;
   out_5034890179145834518[52] = 0;
   out_5034890179145834518[53] = 0;
}
void h_14(double *state, double *unused, double *out_5800236474318007471) {
   out_5800236474318007471[0] = state[6];
   out_5800236474318007471[1] = state[7];
   out_5800236474318007471[2] = state[8];
}
void H_14(double *state, double *unused, double *out_4283923148138682790) {
   out_4283923148138682790[0] = 0;
   out_4283923148138682790[1] = 0;
   out_4283923148138682790[2] = 0;
   out_4283923148138682790[3] = 0;
   out_4283923148138682790[4] = 0;
   out_4283923148138682790[5] = 0;
   out_4283923148138682790[6] = 1;
   out_4283923148138682790[7] = 0;
   out_4283923148138682790[8] = 0;
   out_4283923148138682790[9] = 0;
   out_4283923148138682790[10] = 0;
   out_4283923148138682790[11] = 0;
   out_4283923148138682790[12] = 0;
   out_4283923148138682790[13] = 0;
   out_4283923148138682790[14] = 0;
   out_4283923148138682790[15] = 0;
   out_4283923148138682790[16] = 0;
   out_4283923148138682790[17] = 0;
   out_4283923148138682790[18] = 0;
   out_4283923148138682790[19] = 0;
   out_4283923148138682790[20] = 0;
   out_4283923148138682790[21] = 0;
   out_4283923148138682790[22] = 0;
   out_4283923148138682790[23] = 0;
   out_4283923148138682790[24] = 0;
   out_4283923148138682790[25] = 1;
   out_4283923148138682790[26] = 0;
   out_4283923148138682790[27] = 0;
   out_4283923148138682790[28] = 0;
   out_4283923148138682790[29] = 0;
   out_4283923148138682790[30] = 0;
   out_4283923148138682790[31] = 0;
   out_4283923148138682790[32] = 0;
   out_4283923148138682790[33] = 0;
   out_4283923148138682790[34] = 0;
   out_4283923148138682790[35] = 0;
   out_4283923148138682790[36] = 0;
   out_4283923148138682790[37] = 0;
   out_4283923148138682790[38] = 0;
   out_4283923148138682790[39] = 0;
   out_4283923148138682790[40] = 0;
   out_4283923148138682790[41] = 0;
   out_4283923148138682790[42] = 0;
   out_4283923148138682790[43] = 0;
   out_4283923148138682790[44] = 1;
   out_4283923148138682790[45] = 0;
   out_4283923148138682790[46] = 0;
   out_4283923148138682790[47] = 0;
   out_4283923148138682790[48] = 0;
   out_4283923148138682790[49] = 0;
   out_4283923148138682790[50] = 0;
   out_4283923148138682790[51] = 0;
   out_4283923148138682790[52] = 0;
   out_4283923148138682790[53] = 0;
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
void pose_err_fun(double *nom_x, double *delta_x, double *out_8209796417683535985) {
  err_fun(nom_x, delta_x, out_8209796417683535985);
}
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6976163533526622915) {
  inv_err_fun(nom_x, true_x, out_6976163533526622915);
}
void pose_H_mod_fun(double *state, double *out_6041543424531509265) {
  H_mod_fun(state, out_6041543424531509265);
}
void pose_f_fun(double *state, double dt, double *out_5172544763827630996) {
  f_fun(state,  dt, out_5172544763827630996);
}
void pose_F_fun(double *state, double dt, double *out_1597941670573176708) {
  F_fun(state,  dt, out_1597941670573176708);
}
void pose_h_4(double *state, double *unused, double *out_7358615542883756797) {
  h_4(state, unused, out_7358615542883756797);
}
void pose_H_4(double *state, double *unused, double *out_8247164004478167319) {
  H_4(state, unused, out_8247164004478167319);
}
void pose_h_10(double *state, double *unused, double *out_897342477259466820) {
  h_10(state, unused, out_897342477259466820);
}
void pose_H_10(double *state, double *unused, double *out_7119477149316586896) {
  H_10(state, unused, out_7119477149316586896);
}
void pose_h_13(double *state, double *unused, double *out_9114003749945995778) {
  h_13(state, unused, out_9114003749945995778);
}
void pose_H_13(double *state, double *unused, double *out_5034890179145834518) {
  H_13(state, unused, out_5034890179145834518);
}
void pose_h_14(double *state, double *unused, double *out_5800236474318007471) {
  h_14(state, unused, out_5800236474318007471);
}
void pose_H_14(double *state, double *unused, double *out_4283923148138682790) {
  H_14(state, unused, out_4283923148138682790);
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
