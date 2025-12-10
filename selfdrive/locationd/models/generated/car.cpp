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
void err_fun(double *nom_x, double *delta_x, double *out_5464706606166523011) {
   out_5464706606166523011[0] = delta_x[0] + nom_x[0];
   out_5464706606166523011[1] = delta_x[1] + nom_x[1];
   out_5464706606166523011[2] = delta_x[2] + nom_x[2];
   out_5464706606166523011[3] = delta_x[3] + nom_x[3];
   out_5464706606166523011[4] = delta_x[4] + nom_x[4];
   out_5464706606166523011[5] = delta_x[5] + nom_x[5];
   out_5464706606166523011[6] = delta_x[6] + nom_x[6];
   out_5464706606166523011[7] = delta_x[7] + nom_x[7];
   out_5464706606166523011[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6467031187671732107) {
   out_6467031187671732107[0] = -nom_x[0] + true_x[0];
   out_6467031187671732107[1] = -nom_x[1] + true_x[1];
   out_6467031187671732107[2] = -nom_x[2] + true_x[2];
   out_6467031187671732107[3] = -nom_x[3] + true_x[3];
   out_6467031187671732107[4] = -nom_x[4] + true_x[4];
   out_6467031187671732107[5] = -nom_x[5] + true_x[5];
   out_6467031187671732107[6] = -nom_x[6] + true_x[6];
   out_6467031187671732107[7] = -nom_x[7] + true_x[7];
   out_6467031187671732107[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_3516066999229599607) {
   out_3516066999229599607[0] = 1.0;
   out_3516066999229599607[1] = 0.0;
   out_3516066999229599607[2] = 0.0;
   out_3516066999229599607[3] = 0.0;
   out_3516066999229599607[4] = 0.0;
   out_3516066999229599607[5] = 0.0;
   out_3516066999229599607[6] = 0.0;
   out_3516066999229599607[7] = 0.0;
   out_3516066999229599607[8] = 0.0;
   out_3516066999229599607[9] = 0.0;
   out_3516066999229599607[10] = 1.0;
   out_3516066999229599607[11] = 0.0;
   out_3516066999229599607[12] = 0.0;
   out_3516066999229599607[13] = 0.0;
   out_3516066999229599607[14] = 0.0;
   out_3516066999229599607[15] = 0.0;
   out_3516066999229599607[16] = 0.0;
   out_3516066999229599607[17] = 0.0;
   out_3516066999229599607[18] = 0.0;
   out_3516066999229599607[19] = 0.0;
   out_3516066999229599607[20] = 1.0;
   out_3516066999229599607[21] = 0.0;
   out_3516066999229599607[22] = 0.0;
   out_3516066999229599607[23] = 0.0;
   out_3516066999229599607[24] = 0.0;
   out_3516066999229599607[25] = 0.0;
   out_3516066999229599607[26] = 0.0;
   out_3516066999229599607[27] = 0.0;
   out_3516066999229599607[28] = 0.0;
   out_3516066999229599607[29] = 0.0;
   out_3516066999229599607[30] = 1.0;
   out_3516066999229599607[31] = 0.0;
   out_3516066999229599607[32] = 0.0;
   out_3516066999229599607[33] = 0.0;
   out_3516066999229599607[34] = 0.0;
   out_3516066999229599607[35] = 0.0;
   out_3516066999229599607[36] = 0.0;
   out_3516066999229599607[37] = 0.0;
   out_3516066999229599607[38] = 0.0;
   out_3516066999229599607[39] = 0.0;
   out_3516066999229599607[40] = 1.0;
   out_3516066999229599607[41] = 0.0;
   out_3516066999229599607[42] = 0.0;
   out_3516066999229599607[43] = 0.0;
   out_3516066999229599607[44] = 0.0;
   out_3516066999229599607[45] = 0.0;
   out_3516066999229599607[46] = 0.0;
   out_3516066999229599607[47] = 0.0;
   out_3516066999229599607[48] = 0.0;
   out_3516066999229599607[49] = 0.0;
   out_3516066999229599607[50] = 1.0;
   out_3516066999229599607[51] = 0.0;
   out_3516066999229599607[52] = 0.0;
   out_3516066999229599607[53] = 0.0;
   out_3516066999229599607[54] = 0.0;
   out_3516066999229599607[55] = 0.0;
   out_3516066999229599607[56] = 0.0;
   out_3516066999229599607[57] = 0.0;
   out_3516066999229599607[58] = 0.0;
   out_3516066999229599607[59] = 0.0;
   out_3516066999229599607[60] = 1.0;
   out_3516066999229599607[61] = 0.0;
   out_3516066999229599607[62] = 0.0;
   out_3516066999229599607[63] = 0.0;
   out_3516066999229599607[64] = 0.0;
   out_3516066999229599607[65] = 0.0;
   out_3516066999229599607[66] = 0.0;
   out_3516066999229599607[67] = 0.0;
   out_3516066999229599607[68] = 0.0;
   out_3516066999229599607[69] = 0.0;
   out_3516066999229599607[70] = 1.0;
   out_3516066999229599607[71] = 0.0;
   out_3516066999229599607[72] = 0.0;
   out_3516066999229599607[73] = 0.0;
   out_3516066999229599607[74] = 0.0;
   out_3516066999229599607[75] = 0.0;
   out_3516066999229599607[76] = 0.0;
   out_3516066999229599607[77] = 0.0;
   out_3516066999229599607[78] = 0.0;
   out_3516066999229599607[79] = 0.0;
   out_3516066999229599607[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_6875244830634783359) {
   out_6875244830634783359[0] = state[0];
   out_6875244830634783359[1] = state[1];
   out_6875244830634783359[2] = state[2];
   out_6875244830634783359[3] = state[3];
   out_6875244830634783359[4] = state[4];
   out_6875244830634783359[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_6875244830634783359[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_6875244830634783359[7] = state[7];
   out_6875244830634783359[8] = state[8];
}
void F_fun(double *state, double dt, double *out_1432432365405807483) {
   out_1432432365405807483[0] = 1;
   out_1432432365405807483[1] = 0;
   out_1432432365405807483[2] = 0;
   out_1432432365405807483[3] = 0;
   out_1432432365405807483[4] = 0;
   out_1432432365405807483[5] = 0;
   out_1432432365405807483[6] = 0;
   out_1432432365405807483[7] = 0;
   out_1432432365405807483[8] = 0;
   out_1432432365405807483[9] = 0;
   out_1432432365405807483[10] = 1;
   out_1432432365405807483[11] = 0;
   out_1432432365405807483[12] = 0;
   out_1432432365405807483[13] = 0;
   out_1432432365405807483[14] = 0;
   out_1432432365405807483[15] = 0;
   out_1432432365405807483[16] = 0;
   out_1432432365405807483[17] = 0;
   out_1432432365405807483[18] = 0;
   out_1432432365405807483[19] = 0;
   out_1432432365405807483[20] = 1;
   out_1432432365405807483[21] = 0;
   out_1432432365405807483[22] = 0;
   out_1432432365405807483[23] = 0;
   out_1432432365405807483[24] = 0;
   out_1432432365405807483[25] = 0;
   out_1432432365405807483[26] = 0;
   out_1432432365405807483[27] = 0;
   out_1432432365405807483[28] = 0;
   out_1432432365405807483[29] = 0;
   out_1432432365405807483[30] = 1;
   out_1432432365405807483[31] = 0;
   out_1432432365405807483[32] = 0;
   out_1432432365405807483[33] = 0;
   out_1432432365405807483[34] = 0;
   out_1432432365405807483[35] = 0;
   out_1432432365405807483[36] = 0;
   out_1432432365405807483[37] = 0;
   out_1432432365405807483[38] = 0;
   out_1432432365405807483[39] = 0;
   out_1432432365405807483[40] = 1;
   out_1432432365405807483[41] = 0;
   out_1432432365405807483[42] = 0;
   out_1432432365405807483[43] = 0;
   out_1432432365405807483[44] = 0;
   out_1432432365405807483[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_1432432365405807483[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_1432432365405807483[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_1432432365405807483[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_1432432365405807483[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_1432432365405807483[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_1432432365405807483[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_1432432365405807483[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_1432432365405807483[53] = -9.8100000000000005*dt;
   out_1432432365405807483[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_1432432365405807483[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_1432432365405807483[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1432432365405807483[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1432432365405807483[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_1432432365405807483[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_1432432365405807483[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_1432432365405807483[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_1432432365405807483[62] = 0;
   out_1432432365405807483[63] = 0;
   out_1432432365405807483[64] = 0;
   out_1432432365405807483[65] = 0;
   out_1432432365405807483[66] = 0;
   out_1432432365405807483[67] = 0;
   out_1432432365405807483[68] = 0;
   out_1432432365405807483[69] = 0;
   out_1432432365405807483[70] = 1;
   out_1432432365405807483[71] = 0;
   out_1432432365405807483[72] = 0;
   out_1432432365405807483[73] = 0;
   out_1432432365405807483[74] = 0;
   out_1432432365405807483[75] = 0;
   out_1432432365405807483[76] = 0;
   out_1432432365405807483[77] = 0;
   out_1432432365405807483[78] = 0;
   out_1432432365405807483[79] = 0;
   out_1432432365405807483[80] = 1;
}
void h_25(double *state, double *unused, double *out_1636264287155512060) {
   out_1636264287155512060[0] = state[6];
}
void H_25(double *state, double *unused, double *out_2980955960660430344) {
   out_2980955960660430344[0] = 0;
   out_2980955960660430344[1] = 0;
   out_2980955960660430344[2] = 0;
   out_2980955960660430344[3] = 0;
   out_2980955960660430344[4] = 0;
   out_2980955960660430344[5] = 0;
   out_2980955960660430344[6] = 1;
   out_2980955960660430344[7] = 0;
   out_2980955960660430344[8] = 0;
}
void h_24(double *state, double *unused, double *out_818308934285529692) {
   out_818308934285529692[0] = state[4];
   out_818308934285529692[1] = state[5];
}
void H_24(double *state, double *unused, double *out_7849770825688137196) {
   out_7849770825688137196[0] = 0;
   out_7849770825688137196[1] = 0;
   out_7849770825688137196[2] = 0;
   out_7849770825688137196[3] = 0;
   out_7849770825688137196[4] = 1;
   out_7849770825688137196[5] = 0;
   out_7849770825688137196[6] = 0;
   out_7849770825688137196[7] = 0;
   out_7849770825688137196[8] = 0;
   out_7849770825688137196[9] = 0;
   out_7849770825688137196[10] = 0;
   out_7849770825688137196[11] = 0;
   out_7849770825688137196[12] = 0;
   out_7849770825688137196[13] = 0;
   out_7849770825688137196[14] = 1;
   out_7849770825688137196[15] = 0;
   out_7849770825688137196[16] = 0;
   out_7849770825688137196[17] = 0;
}
void h_30(double *state, double *unused, double *out_5134570939194838876) {
   out_5134570939194838876[0] = state[4];
}
void H_30(double *state, double *unused, double *out_7508652290788038542) {
   out_7508652290788038542[0] = 0;
   out_7508652290788038542[1] = 0;
   out_7508652290788038542[2] = 0;
   out_7508652290788038542[3] = 0;
   out_7508652290788038542[4] = 1;
   out_7508652290788038542[5] = 0;
   out_7508652290788038542[6] = 0;
   out_7508652290788038542[7] = 0;
   out_7508652290788038542[8] = 0;
}
void h_26(double *state, double *unused, double *out_8310499866853867095) {
   out_8310499866853867095[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6722459279534486568) {
   out_6722459279534486568[0] = 0;
   out_6722459279534486568[1] = 0;
   out_6722459279534486568[2] = 0;
   out_6722459279534486568[3] = 0;
   out_6722459279534486568[4] = 0;
   out_6722459279534486568[5] = 0;
   out_6722459279534486568[6] = 0;
   out_6722459279534486568[7] = 1;
   out_6722459279534486568[8] = 0;
}
void h_27(double *state, double *unused, double *out_54183547580168900) {
   out_54183547580168900[0] = state[3];
}
void H_27(double *state, double *unused, double *out_5285058219604095325) {
   out_5285058219604095325[0] = 0;
   out_5285058219604095325[1] = 0;
   out_5285058219604095325[2] = 0;
   out_5285058219604095325[3] = 1;
   out_5285058219604095325[4] = 0;
   out_5285058219604095325[5] = 0;
   out_5285058219604095325[6] = 0;
   out_5285058219604095325[7] = 0;
   out_5285058219604095325[8] = 0;
}
void h_29(double *state, double *unused, double *out_4152486845859540764) {
   out_4152486845859540764[0] = state[1];
}
void H_29(double *state, double *unused, double *out_6998420946473646358) {
   out_6998420946473646358[0] = 0;
   out_6998420946473646358[1] = 1;
   out_6998420946473646358[2] = 0;
   out_6998420946473646358[3] = 0;
   out_6998420946473646358[4] = 0;
   out_6998420946473646358[5] = 0;
   out_6998420946473646358[6] = 0;
   out_6998420946473646358[7] = 0;
   out_6998420946473646358[8] = 0;
}
void h_28(double *state, double *unused, double *out_6310008269539216154) {
   out_6310008269539216154[0] = state[0];
}
void H_28(double *state, double *unused, double *out_6365924110166374684) {
   out_6365924110166374684[0] = 1;
   out_6365924110166374684[1] = 0;
   out_6365924110166374684[2] = 0;
   out_6365924110166374684[3] = 0;
   out_6365924110166374684[4] = 0;
   out_6365924110166374684[5] = 0;
   out_6365924110166374684[6] = 0;
   out_6365924110166374684[7] = 0;
   out_6365924110166374684[8] = 0;
}
void h_31(double *state, double *unused, double *out_1793450955506641205) {
   out_1793450955506641205[0] = state[8];
}
void H_31(double *state, double *unused, double *out_7348667381767838044) {
   out_7348667381767838044[0] = 0;
   out_7348667381767838044[1] = 0;
   out_7348667381767838044[2] = 0;
   out_7348667381767838044[3] = 0;
   out_7348667381767838044[4] = 0;
   out_7348667381767838044[5] = 0;
   out_7348667381767838044[6] = 0;
   out_7348667381767838044[7] = 0;
   out_7348667381767838044[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_5464706606166523011) {
  err_fun(nom_x, delta_x, out_5464706606166523011);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_6467031187671732107) {
  inv_err_fun(nom_x, true_x, out_6467031187671732107);
}
void car_H_mod_fun(double *state, double *out_3516066999229599607) {
  H_mod_fun(state, out_3516066999229599607);
}
void car_f_fun(double *state, double dt, double *out_6875244830634783359) {
  f_fun(state,  dt, out_6875244830634783359);
}
void car_F_fun(double *state, double dt, double *out_1432432365405807483) {
  F_fun(state,  dt, out_1432432365405807483);
}
void car_h_25(double *state, double *unused, double *out_1636264287155512060) {
  h_25(state, unused, out_1636264287155512060);
}
void car_H_25(double *state, double *unused, double *out_2980955960660430344) {
  H_25(state, unused, out_2980955960660430344);
}
void car_h_24(double *state, double *unused, double *out_818308934285529692) {
  h_24(state, unused, out_818308934285529692);
}
void car_H_24(double *state, double *unused, double *out_7849770825688137196) {
  H_24(state, unused, out_7849770825688137196);
}
void car_h_30(double *state, double *unused, double *out_5134570939194838876) {
  h_30(state, unused, out_5134570939194838876);
}
void car_H_30(double *state, double *unused, double *out_7508652290788038542) {
  H_30(state, unused, out_7508652290788038542);
}
void car_h_26(double *state, double *unused, double *out_8310499866853867095) {
  h_26(state, unused, out_8310499866853867095);
}
void car_H_26(double *state, double *unused, double *out_6722459279534486568) {
  H_26(state, unused, out_6722459279534486568);
}
void car_h_27(double *state, double *unused, double *out_54183547580168900) {
  h_27(state, unused, out_54183547580168900);
}
void car_H_27(double *state, double *unused, double *out_5285058219604095325) {
  H_27(state, unused, out_5285058219604095325);
}
void car_h_29(double *state, double *unused, double *out_4152486845859540764) {
  h_29(state, unused, out_4152486845859540764);
}
void car_H_29(double *state, double *unused, double *out_6998420946473646358) {
  H_29(state, unused, out_6998420946473646358);
}
void car_h_28(double *state, double *unused, double *out_6310008269539216154) {
  h_28(state, unused, out_6310008269539216154);
}
void car_H_28(double *state, double *unused, double *out_6365924110166374684) {
  H_28(state, unused, out_6365924110166374684);
}
void car_h_31(double *state, double *unused, double *out_1793450955506641205) {
  h_31(state, unused, out_1793450955506641205);
}
void car_H_31(double *state, double *unused, double *out_7348667381767838044) {
  H_31(state, unused, out_7348667381767838044);
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
