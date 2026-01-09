#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                      Code generated with SymPy 1.14.0                      *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_8548163524830503035) {
   out_8548163524830503035[0] = delta_x[0] + nom_x[0];
   out_8548163524830503035[1] = delta_x[1] + nom_x[1];
   out_8548163524830503035[2] = delta_x[2] + nom_x[2];
   out_8548163524830503035[3] = delta_x[3] + nom_x[3];
   out_8548163524830503035[4] = delta_x[4] + nom_x[4];
   out_8548163524830503035[5] = delta_x[5] + nom_x[5];
   out_8548163524830503035[6] = delta_x[6] + nom_x[6];
   out_8548163524830503035[7] = delta_x[7] + nom_x[7];
   out_8548163524830503035[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_849499763456993611) {
   out_849499763456993611[0] = -nom_x[0] + true_x[0];
   out_849499763456993611[1] = -nom_x[1] + true_x[1];
   out_849499763456993611[2] = -nom_x[2] + true_x[2];
   out_849499763456993611[3] = -nom_x[3] + true_x[3];
   out_849499763456993611[4] = -nom_x[4] + true_x[4];
   out_849499763456993611[5] = -nom_x[5] + true_x[5];
   out_849499763456993611[6] = -nom_x[6] + true_x[6];
   out_849499763456993611[7] = -nom_x[7] + true_x[7];
   out_849499763456993611[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_676289759090364752) {
   out_676289759090364752[0] = 1.0;
   out_676289759090364752[1] = 0.0;
   out_676289759090364752[2] = 0.0;
   out_676289759090364752[3] = 0.0;
   out_676289759090364752[4] = 0.0;
   out_676289759090364752[5] = 0.0;
   out_676289759090364752[6] = 0.0;
   out_676289759090364752[7] = 0.0;
   out_676289759090364752[8] = 0.0;
   out_676289759090364752[9] = 0.0;
   out_676289759090364752[10] = 1.0;
   out_676289759090364752[11] = 0.0;
   out_676289759090364752[12] = 0.0;
   out_676289759090364752[13] = 0.0;
   out_676289759090364752[14] = 0.0;
   out_676289759090364752[15] = 0.0;
   out_676289759090364752[16] = 0.0;
   out_676289759090364752[17] = 0.0;
   out_676289759090364752[18] = 0.0;
   out_676289759090364752[19] = 0.0;
   out_676289759090364752[20] = 1.0;
   out_676289759090364752[21] = 0.0;
   out_676289759090364752[22] = 0.0;
   out_676289759090364752[23] = 0.0;
   out_676289759090364752[24] = 0.0;
   out_676289759090364752[25] = 0.0;
   out_676289759090364752[26] = 0.0;
   out_676289759090364752[27] = 0.0;
   out_676289759090364752[28] = 0.0;
   out_676289759090364752[29] = 0.0;
   out_676289759090364752[30] = 1.0;
   out_676289759090364752[31] = 0.0;
   out_676289759090364752[32] = 0.0;
   out_676289759090364752[33] = 0.0;
   out_676289759090364752[34] = 0.0;
   out_676289759090364752[35] = 0.0;
   out_676289759090364752[36] = 0.0;
   out_676289759090364752[37] = 0.0;
   out_676289759090364752[38] = 0.0;
   out_676289759090364752[39] = 0.0;
   out_676289759090364752[40] = 1.0;
   out_676289759090364752[41] = 0.0;
   out_676289759090364752[42] = 0.0;
   out_676289759090364752[43] = 0.0;
   out_676289759090364752[44] = 0.0;
   out_676289759090364752[45] = 0.0;
   out_676289759090364752[46] = 0.0;
   out_676289759090364752[47] = 0.0;
   out_676289759090364752[48] = 0.0;
   out_676289759090364752[49] = 0.0;
   out_676289759090364752[50] = 1.0;
   out_676289759090364752[51] = 0.0;
   out_676289759090364752[52] = 0.0;
   out_676289759090364752[53] = 0.0;
   out_676289759090364752[54] = 0.0;
   out_676289759090364752[55] = 0.0;
   out_676289759090364752[56] = 0.0;
   out_676289759090364752[57] = 0.0;
   out_676289759090364752[58] = 0.0;
   out_676289759090364752[59] = 0.0;
   out_676289759090364752[60] = 1.0;
   out_676289759090364752[61] = 0.0;
   out_676289759090364752[62] = 0.0;
   out_676289759090364752[63] = 0.0;
   out_676289759090364752[64] = 0.0;
   out_676289759090364752[65] = 0.0;
   out_676289759090364752[66] = 0.0;
   out_676289759090364752[67] = 0.0;
   out_676289759090364752[68] = 0.0;
   out_676289759090364752[69] = 0.0;
   out_676289759090364752[70] = 1.0;
   out_676289759090364752[71] = 0.0;
   out_676289759090364752[72] = 0.0;
   out_676289759090364752[73] = 0.0;
   out_676289759090364752[74] = 0.0;
   out_676289759090364752[75] = 0.0;
   out_676289759090364752[76] = 0.0;
   out_676289759090364752[77] = 0.0;
   out_676289759090364752[78] = 0.0;
   out_676289759090364752[79] = 0.0;
   out_676289759090364752[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_7161712672522226435) {
   out_7161712672522226435[0] = state[0];
   out_7161712672522226435[1] = state[1];
   out_7161712672522226435[2] = state[2];
   out_7161712672522226435[3] = state[3];
   out_7161712672522226435[4] = state[4];
   out_7161712672522226435[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_7161712672522226435[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_7161712672522226435[7] = state[7];
   out_7161712672522226435[8] = state[8];
}
void F_fun(double *state, double dt, double *out_4848459659569724868) {
   out_4848459659569724868[0] = 1;
   out_4848459659569724868[1] = 0;
   out_4848459659569724868[2] = 0;
   out_4848459659569724868[3] = 0;
   out_4848459659569724868[4] = 0;
   out_4848459659569724868[5] = 0;
   out_4848459659569724868[6] = 0;
   out_4848459659569724868[7] = 0;
   out_4848459659569724868[8] = 0;
   out_4848459659569724868[9] = 0;
   out_4848459659569724868[10] = 1;
   out_4848459659569724868[11] = 0;
   out_4848459659569724868[12] = 0;
   out_4848459659569724868[13] = 0;
   out_4848459659569724868[14] = 0;
   out_4848459659569724868[15] = 0;
   out_4848459659569724868[16] = 0;
   out_4848459659569724868[17] = 0;
   out_4848459659569724868[18] = 0;
   out_4848459659569724868[19] = 0;
   out_4848459659569724868[20] = 1;
   out_4848459659569724868[21] = 0;
   out_4848459659569724868[22] = 0;
   out_4848459659569724868[23] = 0;
   out_4848459659569724868[24] = 0;
   out_4848459659569724868[25] = 0;
   out_4848459659569724868[26] = 0;
   out_4848459659569724868[27] = 0;
   out_4848459659569724868[28] = 0;
   out_4848459659569724868[29] = 0;
   out_4848459659569724868[30] = 1;
   out_4848459659569724868[31] = 0;
   out_4848459659569724868[32] = 0;
   out_4848459659569724868[33] = 0;
   out_4848459659569724868[34] = 0;
   out_4848459659569724868[35] = 0;
   out_4848459659569724868[36] = 0;
   out_4848459659569724868[37] = 0;
   out_4848459659569724868[38] = 0;
   out_4848459659569724868[39] = 0;
   out_4848459659569724868[40] = 1;
   out_4848459659569724868[41] = 0;
   out_4848459659569724868[42] = 0;
   out_4848459659569724868[43] = 0;
   out_4848459659569724868[44] = 0;
   out_4848459659569724868[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_4848459659569724868[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_4848459659569724868[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4848459659569724868[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_4848459659569724868[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_4848459659569724868[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_4848459659569724868[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_4848459659569724868[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_4848459659569724868[53] = -9.8100000000000005*dt;
   out_4848459659569724868[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_4848459659569724868[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_4848459659569724868[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4848459659569724868[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4848459659569724868[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_4848459659569724868[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_4848459659569724868[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_4848459659569724868[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_4848459659569724868[62] = 0;
   out_4848459659569724868[63] = 0;
   out_4848459659569724868[64] = 0;
   out_4848459659569724868[65] = 0;
   out_4848459659569724868[66] = 0;
   out_4848459659569724868[67] = 0;
   out_4848459659569724868[68] = 0;
   out_4848459659569724868[69] = 0;
   out_4848459659569724868[70] = 1;
   out_4848459659569724868[71] = 0;
   out_4848459659569724868[72] = 0;
   out_4848459659569724868[73] = 0;
   out_4848459659569724868[74] = 0;
   out_4848459659569724868[75] = 0;
   out_4848459659569724868[76] = 0;
   out_4848459659569724868[77] = 0;
   out_4848459659569724868[78] = 0;
   out_4848459659569724868[79] = 0;
   out_4848459659569724868[80] = 1;
}
void h_25(double *state, double *unused, double *out_1992277201445650583) {
   out_1992277201445650583[0] = state[6];
}
void H_25(double *state, double *unused, double *out_8516898466821872485) {
   out_8516898466821872485[0] = 0;
   out_8516898466821872485[1] = 0;
   out_8516898466821872485[2] = 0;
   out_8516898466821872485[3] = 0;
   out_8516898466821872485[4] = 0;
   out_8516898466821872485[5] = 0;
   out_8516898466821872485[6] = 1;
   out_8516898466821872485[7] = 0;
   out_8516898466821872485[8] = 0;
}
void h_24(double *state, double *unused, double *out_6265279802125261131) {
   out_6265279802125261131[0] = state[4];
   out_6265279802125261131[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1154953199075508237) {
   out_1154953199075508237[0] = 0;
   out_1154953199075508237[1] = 0;
   out_1154953199075508237[2] = 0;
   out_1154953199075508237[3] = 0;
   out_1154953199075508237[4] = 1;
   out_1154953199075508237[5] = 0;
   out_1154953199075508237[6] = 0;
   out_1154953199075508237[7] = 0;
   out_1154953199075508237[8] = 0;
   out_1154953199075508237[9] = 0;
   out_1154953199075508237[10] = 0;
   out_1154953199075508237[11] = 0;
   out_1154953199075508237[12] = 0;
   out_1154953199075508237[13] = 0;
   out_1154953199075508237[14] = 1;
   out_1154953199075508237[15] = 0;
   out_1154953199075508237[16] = 0;
   out_1154953199075508237[17] = 0;
}
void h_30(double *state, double *unused, double *out_1717083139161144694) {
   out_1717083139161144694[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1600208125330255730) {
   out_1600208125330255730[0] = 0;
   out_1600208125330255730[1] = 0;
   out_1600208125330255730[2] = 0;
   out_1600208125330255730[3] = 0;
   out_1600208125330255730[4] = 1;
   out_1600208125330255730[5] = 0;
   out_1600208125330255730[6] = 0;
   out_1600208125330255730[7] = 0;
   out_1600208125330255730[8] = 0;
}
void h_26(double *state, double *unused, double *out_3624784096724885869) {
   out_3624784096724885869[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6188342288013622907) {
   out_6188342288013622907[0] = 0;
   out_6188342288013622907[1] = 0;
   out_6188342288013622907[2] = 0;
   out_6188342288013622907[3] = 0;
   out_6188342288013622907[4] = 0;
   out_6188342288013622907[5] = 0;
   out_6188342288013622907[6] = 0;
   out_6188342288013622907[7] = 1;
   out_6188342288013622907[8] = 0;
}
void h_27(double *state, double *unused, double *out_3009396066215195062) {
   out_3009396066215195062[0] = state[3];
}
void H_27(double *state, double *unused, double *out_7625743347944014150) {
   out_7625743347944014150[0] = 0;
   out_7625743347944014150[1] = 0;
   out_7625743347944014150[2] = 0;
   out_7625743347944014150[3] = 1;
   out_7625743347944014150[4] = 0;
   out_7625743347944014150[5] = 0;
   out_7625743347944014150[6] = 0;
   out_7625743347944014150[7] = 0;
   out_7625743347944014150[8] = 0;
}
void h_29(double *state, double *unused, double *out_4753869190605477379) {
   out_4753869190605477379[0] = state[1];
}
void H_29(double *state, double *unused, double *out_5912380621074463117) {
   out_5912380621074463117[0] = 0;
   out_5912380621074463117[1] = 1;
   out_5912380621074463117[2] = 0;
   out_5912380621074463117[3] = 0;
   out_5912380621074463117[4] = 0;
   out_5912380621074463117[5] = 0;
   out_5912380621074463117[6] = 0;
   out_5912380621074463117[7] = 0;
   out_5912380621074463117[8] = 0;
}
void h_28(double *state, double *unused, double *out_404990745406497411) {
   out_404990745406497411[0] = state[0];
}
void H_28(double *state, double *unused, double *out_7876010892639789368) {
   out_7876010892639789368[0] = 1;
   out_7876010892639789368[1] = 0;
   out_7876010892639789368[2] = 0;
   out_7876010892639789368[3] = 0;
   out_7876010892639789368[4] = 0;
   out_7876010892639789368[5] = 0;
   out_7876010892639789368[6] = 0;
   out_7876010892639789368[7] = 0;
   out_7876010892639789368[8] = 0;
}
void h_31(double *state, double *unused, double *out_6504383479818089409) {
   out_6504383479818089409[0] = state[8];
}
void H_31(double *state, double *unused, double *out_8486252504944912057) {
   out_8486252504944912057[0] = 0;
   out_8486252504944912057[1] = 0;
   out_8486252504944912057[2] = 0;
   out_8486252504944912057[3] = 0;
   out_8486252504944912057[4] = 0;
   out_8486252504944912057[5] = 0;
   out_8486252504944912057[6] = 0;
   out_8486252504944912057[7] = 0;
   out_8486252504944912057[8] = 1;
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

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_8548163524830503035) {
  err_fun(nom_x, delta_x, out_8548163524830503035);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_849499763456993611) {
  inv_err_fun(nom_x, true_x, out_849499763456993611);
}
void car_H_mod_fun(double *state, double *out_676289759090364752) {
  H_mod_fun(state, out_676289759090364752);
}
void car_f_fun(double *state, double dt, double *out_7161712672522226435) {
  f_fun(state,  dt, out_7161712672522226435);
}
void car_F_fun(double *state, double dt, double *out_4848459659569724868) {
  F_fun(state,  dt, out_4848459659569724868);
}
void car_h_25(double *state, double *unused, double *out_1992277201445650583) {
  h_25(state, unused, out_1992277201445650583);
}
void car_H_25(double *state, double *unused, double *out_8516898466821872485) {
  H_25(state, unused, out_8516898466821872485);
}
void car_h_24(double *state, double *unused, double *out_6265279802125261131) {
  h_24(state, unused, out_6265279802125261131);
}
void car_H_24(double *state, double *unused, double *out_1154953199075508237) {
  H_24(state, unused, out_1154953199075508237);
}
void car_h_30(double *state, double *unused, double *out_1717083139161144694) {
  h_30(state, unused, out_1717083139161144694);
}
void car_H_30(double *state, double *unused, double *out_1600208125330255730) {
  H_30(state, unused, out_1600208125330255730);
}
void car_h_26(double *state, double *unused, double *out_3624784096724885869) {
  h_26(state, unused, out_3624784096724885869);
}
void car_H_26(double *state, double *unused, double *out_6188342288013622907) {
  H_26(state, unused, out_6188342288013622907);
}
void car_h_27(double *state, double *unused, double *out_3009396066215195062) {
  h_27(state, unused, out_3009396066215195062);
}
void car_H_27(double *state, double *unused, double *out_7625743347944014150) {
  H_27(state, unused, out_7625743347944014150);
}
void car_h_29(double *state, double *unused, double *out_4753869190605477379) {
  h_29(state, unused, out_4753869190605477379);
}
void car_H_29(double *state, double *unused, double *out_5912380621074463117) {
  H_29(state, unused, out_5912380621074463117);
}
void car_h_28(double *state, double *unused, double *out_404990745406497411) {
  h_28(state, unused, out_404990745406497411);
}
void car_H_28(double *state, double *unused, double *out_7876010892639789368) {
  H_28(state, unused, out_7876010892639789368);
}
void car_h_31(double *state, double *unused, double *out_6504383479818089409) {
  h_31(state, unused, out_6504383479818089409);
}
void car_H_31(double *state, double *unused, double *out_8486252504944912057) {
  H_31(state, unused, out_8486252504944912057);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
