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
void err_fun(double *nom_x, double *delta_x, double *out_8668144528362342596) {
   out_8668144528362342596[0] = delta_x[0] + nom_x[0];
   out_8668144528362342596[1] = delta_x[1] + nom_x[1];
   out_8668144528362342596[2] = delta_x[2] + nom_x[2];
   out_8668144528362342596[3] = delta_x[3] + nom_x[3];
   out_8668144528362342596[4] = delta_x[4] + nom_x[4];
   out_8668144528362342596[5] = delta_x[5] + nom_x[5];
   out_8668144528362342596[6] = delta_x[6] + nom_x[6];
   out_8668144528362342596[7] = delta_x[7] + nom_x[7];
   out_8668144528362342596[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_3996262106928164937) {
   out_3996262106928164937[0] = -nom_x[0] + true_x[0];
   out_3996262106928164937[1] = -nom_x[1] + true_x[1];
   out_3996262106928164937[2] = -nom_x[2] + true_x[2];
   out_3996262106928164937[3] = -nom_x[3] + true_x[3];
   out_3996262106928164937[4] = -nom_x[4] + true_x[4];
   out_3996262106928164937[5] = -nom_x[5] + true_x[5];
   out_3996262106928164937[6] = -nom_x[6] + true_x[6];
   out_3996262106928164937[7] = -nom_x[7] + true_x[7];
   out_3996262106928164937[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_8798921732928723077) {
   out_8798921732928723077[0] = 1.0;
   out_8798921732928723077[1] = 0.0;
   out_8798921732928723077[2] = 0.0;
   out_8798921732928723077[3] = 0.0;
   out_8798921732928723077[4] = 0.0;
   out_8798921732928723077[5] = 0.0;
   out_8798921732928723077[6] = 0.0;
   out_8798921732928723077[7] = 0.0;
   out_8798921732928723077[8] = 0.0;
   out_8798921732928723077[9] = 0.0;
   out_8798921732928723077[10] = 1.0;
   out_8798921732928723077[11] = 0.0;
   out_8798921732928723077[12] = 0.0;
   out_8798921732928723077[13] = 0.0;
   out_8798921732928723077[14] = 0.0;
   out_8798921732928723077[15] = 0.0;
   out_8798921732928723077[16] = 0.0;
   out_8798921732928723077[17] = 0.0;
   out_8798921732928723077[18] = 0.0;
   out_8798921732928723077[19] = 0.0;
   out_8798921732928723077[20] = 1.0;
   out_8798921732928723077[21] = 0.0;
   out_8798921732928723077[22] = 0.0;
   out_8798921732928723077[23] = 0.0;
   out_8798921732928723077[24] = 0.0;
   out_8798921732928723077[25] = 0.0;
   out_8798921732928723077[26] = 0.0;
   out_8798921732928723077[27] = 0.0;
   out_8798921732928723077[28] = 0.0;
   out_8798921732928723077[29] = 0.0;
   out_8798921732928723077[30] = 1.0;
   out_8798921732928723077[31] = 0.0;
   out_8798921732928723077[32] = 0.0;
   out_8798921732928723077[33] = 0.0;
   out_8798921732928723077[34] = 0.0;
   out_8798921732928723077[35] = 0.0;
   out_8798921732928723077[36] = 0.0;
   out_8798921732928723077[37] = 0.0;
   out_8798921732928723077[38] = 0.0;
   out_8798921732928723077[39] = 0.0;
   out_8798921732928723077[40] = 1.0;
   out_8798921732928723077[41] = 0.0;
   out_8798921732928723077[42] = 0.0;
   out_8798921732928723077[43] = 0.0;
   out_8798921732928723077[44] = 0.0;
   out_8798921732928723077[45] = 0.0;
   out_8798921732928723077[46] = 0.0;
   out_8798921732928723077[47] = 0.0;
   out_8798921732928723077[48] = 0.0;
   out_8798921732928723077[49] = 0.0;
   out_8798921732928723077[50] = 1.0;
   out_8798921732928723077[51] = 0.0;
   out_8798921732928723077[52] = 0.0;
   out_8798921732928723077[53] = 0.0;
   out_8798921732928723077[54] = 0.0;
   out_8798921732928723077[55] = 0.0;
   out_8798921732928723077[56] = 0.0;
   out_8798921732928723077[57] = 0.0;
   out_8798921732928723077[58] = 0.0;
   out_8798921732928723077[59] = 0.0;
   out_8798921732928723077[60] = 1.0;
   out_8798921732928723077[61] = 0.0;
   out_8798921732928723077[62] = 0.0;
   out_8798921732928723077[63] = 0.0;
   out_8798921732928723077[64] = 0.0;
   out_8798921732928723077[65] = 0.0;
   out_8798921732928723077[66] = 0.0;
   out_8798921732928723077[67] = 0.0;
   out_8798921732928723077[68] = 0.0;
   out_8798921732928723077[69] = 0.0;
   out_8798921732928723077[70] = 1.0;
   out_8798921732928723077[71] = 0.0;
   out_8798921732928723077[72] = 0.0;
   out_8798921732928723077[73] = 0.0;
   out_8798921732928723077[74] = 0.0;
   out_8798921732928723077[75] = 0.0;
   out_8798921732928723077[76] = 0.0;
   out_8798921732928723077[77] = 0.0;
   out_8798921732928723077[78] = 0.0;
   out_8798921732928723077[79] = 0.0;
   out_8798921732928723077[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_5900768154802542162) {
   out_5900768154802542162[0] = state[0];
   out_5900768154802542162[1] = state[1];
   out_5900768154802542162[2] = state[2];
   out_5900768154802542162[3] = state[3];
   out_5900768154802542162[4] = state[4];
   out_5900768154802542162[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8100000000000005*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_5900768154802542162[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_5900768154802542162[7] = state[7];
   out_5900768154802542162[8] = state[8];
}
void F_fun(double *state, double dt, double *out_5224568521139140234) {
   out_5224568521139140234[0] = 1;
   out_5224568521139140234[1] = 0;
   out_5224568521139140234[2] = 0;
   out_5224568521139140234[3] = 0;
   out_5224568521139140234[4] = 0;
   out_5224568521139140234[5] = 0;
   out_5224568521139140234[6] = 0;
   out_5224568521139140234[7] = 0;
   out_5224568521139140234[8] = 0;
   out_5224568521139140234[9] = 0;
   out_5224568521139140234[10] = 1;
   out_5224568521139140234[11] = 0;
   out_5224568521139140234[12] = 0;
   out_5224568521139140234[13] = 0;
   out_5224568521139140234[14] = 0;
   out_5224568521139140234[15] = 0;
   out_5224568521139140234[16] = 0;
   out_5224568521139140234[17] = 0;
   out_5224568521139140234[18] = 0;
   out_5224568521139140234[19] = 0;
   out_5224568521139140234[20] = 1;
   out_5224568521139140234[21] = 0;
   out_5224568521139140234[22] = 0;
   out_5224568521139140234[23] = 0;
   out_5224568521139140234[24] = 0;
   out_5224568521139140234[25] = 0;
   out_5224568521139140234[26] = 0;
   out_5224568521139140234[27] = 0;
   out_5224568521139140234[28] = 0;
   out_5224568521139140234[29] = 0;
   out_5224568521139140234[30] = 1;
   out_5224568521139140234[31] = 0;
   out_5224568521139140234[32] = 0;
   out_5224568521139140234[33] = 0;
   out_5224568521139140234[34] = 0;
   out_5224568521139140234[35] = 0;
   out_5224568521139140234[36] = 0;
   out_5224568521139140234[37] = 0;
   out_5224568521139140234[38] = 0;
   out_5224568521139140234[39] = 0;
   out_5224568521139140234[40] = 1;
   out_5224568521139140234[41] = 0;
   out_5224568521139140234[42] = 0;
   out_5224568521139140234[43] = 0;
   out_5224568521139140234[44] = 0;
   out_5224568521139140234[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_5224568521139140234[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_5224568521139140234[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5224568521139140234[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_5224568521139140234[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_5224568521139140234[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_5224568521139140234[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_5224568521139140234[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_5224568521139140234[53] = -9.8100000000000005*dt;
   out_5224568521139140234[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_5224568521139140234[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_5224568521139140234[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5224568521139140234[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5224568521139140234[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_5224568521139140234[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_5224568521139140234[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_5224568521139140234[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_5224568521139140234[62] = 0;
   out_5224568521139140234[63] = 0;
   out_5224568521139140234[64] = 0;
   out_5224568521139140234[65] = 0;
   out_5224568521139140234[66] = 0;
   out_5224568521139140234[67] = 0;
   out_5224568521139140234[68] = 0;
   out_5224568521139140234[69] = 0;
   out_5224568521139140234[70] = 1;
   out_5224568521139140234[71] = 0;
   out_5224568521139140234[72] = 0;
   out_5224568521139140234[73] = 0;
   out_5224568521139140234[74] = 0;
   out_5224568521139140234[75] = 0;
   out_5224568521139140234[76] = 0;
   out_5224568521139140234[77] = 0;
   out_5224568521139140234[78] = 0;
   out_5224568521139140234[79] = 0;
   out_5224568521139140234[80] = 1;
}
void h_25(double *state, double *unused, double *out_341581022161831241) {
   out_341581022161831241[0] = state[6];
}
void H_25(double *state, double *unused, double *out_454634114868591302) {
   out_454634114868591302[0] = 0;
   out_454634114868591302[1] = 0;
   out_454634114868591302[2] = 0;
   out_454634114868591302[3] = 0;
   out_454634114868591302[4] = 0;
   out_454634114868591302[5] = 0;
   out_454634114868591302[6] = 1;
   out_454634114868591302[7] = 0;
   out_454634114868591302[8] = 0;
}
void h_24(double *state, double *unused, double *out_9195388967883110704) {
   out_9195388967883110704[0] = state[4];
   out_9195388967883110704[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1867662362907000139) {
   out_1867662362907000139[0] = 0;
   out_1867662362907000139[1] = 0;
   out_1867662362907000139[2] = 0;
   out_1867662362907000139[3] = 0;
   out_1867662362907000139[4] = 1;
   out_1867662362907000139[5] = 0;
   out_1867662362907000139[6] = 0;
   out_1867662362907000139[7] = 0;
   out_1867662362907000139[8] = 0;
   out_1867662362907000139[9] = 0;
   out_1867662362907000139[10] = 0;
   out_1867662362907000139[11] = 0;
   out_1867662362907000139[12] = 0;
   out_1867662362907000139[13] = 0;
   out_1867662362907000139[14] = 1;
   out_1867662362907000139[15] = 0;
   out_1867662362907000139[16] = 0;
   out_1867662362907000139[17] = 0;
}
void h_30(double *state, double *unused, double *out_7551358472722692118) {
   out_7551358472722692118[0] = state[4];
}
void H_30(double *state, double *unused, double *out_4073062215259016896) {
   out_4073062215259016896[0] = 0;
   out_4073062215259016896[1] = 0;
   out_4073062215259016896[2] = 0;
   out_4073062215259016896[3] = 0;
   out_4073062215259016896[4] = 1;
   out_4073062215259016896[5] = 0;
   out_4073062215259016896[6] = 0;
   out_4073062215259016896[7] = 0;
   out_4073062215259016896[8] = 0;
}
void h_26(double *state, double *unused, double *out_6191730941713322290) {
   out_6191730941713322290[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3286869204005464922) {
   out_3286869204005464922[0] = 0;
   out_3286869204005464922[1] = 0;
   out_3286869204005464922[2] = 0;
   out_3286869204005464922[3] = 0;
   out_3286869204005464922[4] = 0;
   out_3286869204005464922[5] = 0;
   out_3286869204005464922[6] = 0;
   out_3286869204005464922[7] = 1;
   out_3286869204005464922[8] = 0;
}
void h_27(double *state, double *unused, double *out_8929743703966672649) {
   out_8929743703966672649[0] = state[3];
}
void H_27(double *state, double *unused, double *out_1849468144075073679) {
   out_1849468144075073679[0] = 0;
   out_1849468144075073679[1] = 0;
   out_1849468144075073679[2] = 0;
   out_1849468144075073679[3] = 1;
   out_1849468144075073679[4] = 0;
   out_1849468144075073679[5] = 0;
   out_1849468144075073679[6] = 0;
   out_1849468144075073679[7] = 0;
   out_1849468144075073679[8] = 0;
}
void h_29(double *state, double *unused, double *out_9204937766251178538) {
   out_9204937766251178538[0] = state[1];
}
void H_29(double *state, double *unused, double *out_3562830870944624712) {
   out_3562830870944624712[0] = 0;
   out_3562830870944624712[1] = 1;
   out_3562830870944624712[2] = 0;
   out_3562830870944624712[3] = 0;
   out_3562830870944624712[4] = 0;
   out_3562830870944624712[5] = 0;
   out_3562830870944624712[6] = 0;
   out_3562830870944624712[7] = 0;
   out_3562830870944624712[8] = 0;
}
void h_28(double *state, double *unused, double *out_3638714882184163879) {
   out_3638714882184163879[0] = state[0];
}
void H_28(double *state, double *unused, double *out_1599200599379298461) {
   out_1599200599379298461[0] = 1;
   out_1599200599379298461[1] = 0;
   out_1599200599379298461[2] = 0;
   out_1599200599379298461[3] = 0;
   out_1599200599379298461[4] = 0;
   out_1599200599379298461[5] = 0;
   out_1599200599379298461[6] = 0;
   out_1599200599379298461[7] = 0;
   out_1599200599379298461[8] = 0;
}
void h_31(double *state, double *unused, double *out_290620908051804654) {
   out_290620908051804654[0] = state[8];
}
void H_31(double *state, double *unused, double *out_485280076745551730) {
   out_485280076745551730[0] = 0;
   out_485280076745551730[1] = 0;
   out_485280076745551730[2] = 0;
   out_485280076745551730[3] = 0;
   out_485280076745551730[4] = 0;
   out_485280076745551730[5] = 0;
   out_485280076745551730[6] = 0;
   out_485280076745551730[7] = 0;
   out_485280076745551730[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_8668144528362342596) {
  err_fun(nom_x, delta_x, out_8668144528362342596);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3996262106928164937) {
  inv_err_fun(nom_x, true_x, out_3996262106928164937);
}
void car_H_mod_fun(double *state, double *out_8798921732928723077) {
  H_mod_fun(state, out_8798921732928723077);
}
void car_f_fun(double *state, double dt, double *out_5900768154802542162) {
  f_fun(state,  dt, out_5900768154802542162);
}
void car_F_fun(double *state, double dt, double *out_5224568521139140234) {
  F_fun(state,  dt, out_5224568521139140234);
}
void car_h_25(double *state, double *unused, double *out_341581022161831241) {
  h_25(state, unused, out_341581022161831241);
}
void car_H_25(double *state, double *unused, double *out_454634114868591302) {
  H_25(state, unused, out_454634114868591302);
}
void car_h_24(double *state, double *unused, double *out_9195388967883110704) {
  h_24(state, unused, out_9195388967883110704);
}
void car_H_24(double *state, double *unused, double *out_1867662362907000139) {
  H_24(state, unused, out_1867662362907000139);
}
void car_h_30(double *state, double *unused, double *out_7551358472722692118) {
  h_30(state, unused, out_7551358472722692118);
}
void car_H_30(double *state, double *unused, double *out_4073062215259016896) {
  H_30(state, unused, out_4073062215259016896);
}
void car_h_26(double *state, double *unused, double *out_6191730941713322290) {
  h_26(state, unused, out_6191730941713322290);
}
void car_H_26(double *state, double *unused, double *out_3286869204005464922) {
  H_26(state, unused, out_3286869204005464922);
}
void car_h_27(double *state, double *unused, double *out_8929743703966672649) {
  h_27(state, unused, out_8929743703966672649);
}
void car_H_27(double *state, double *unused, double *out_1849468144075073679) {
  H_27(state, unused, out_1849468144075073679);
}
void car_h_29(double *state, double *unused, double *out_9204937766251178538) {
  h_29(state, unused, out_9204937766251178538);
}
void car_H_29(double *state, double *unused, double *out_3562830870944624712) {
  H_29(state, unused, out_3562830870944624712);
}
void car_h_28(double *state, double *unused, double *out_3638714882184163879) {
  h_28(state, unused, out_3638714882184163879);
}
void car_H_28(double *state, double *unused, double *out_1599200599379298461) {
  H_28(state, unused, out_1599200599379298461);
}
void car_h_31(double *state, double *unused, double *out_290620908051804654) {
  h_31(state, unused, out_290620908051804654);
}
void car_H_31(double *state, double *unused, double *out_485280076745551730) {
  H_31(state, unused, out_485280076745551730);
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
