#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_8548163524830503035);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_849499763456993611);
void car_H_mod_fun(double *state, double *out_676289759090364752);
void car_f_fun(double *state, double dt, double *out_7161712672522226435);
void car_F_fun(double *state, double dt, double *out_4848459659569724868);
void car_h_25(double *state, double *unused, double *out_1992277201445650583);
void car_H_25(double *state, double *unused, double *out_8516898466821872485);
void car_h_24(double *state, double *unused, double *out_6265279802125261131);
void car_H_24(double *state, double *unused, double *out_1154953199075508237);
void car_h_30(double *state, double *unused, double *out_1717083139161144694);
void car_H_30(double *state, double *unused, double *out_1600208125330255730);
void car_h_26(double *state, double *unused, double *out_3624784096724885869);
void car_H_26(double *state, double *unused, double *out_6188342288013622907);
void car_h_27(double *state, double *unused, double *out_3009396066215195062);
void car_H_27(double *state, double *unused, double *out_7625743347944014150);
void car_h_29(double *state, double *unused, double *out_4753869190605477379);
void car_H_29(double *state, double *unused, double *out_5912380621074463117);
void car_h_28(double *state, double *unused, double *out_404990745406497411);
void car_H_28(double *state, double *unused, double *out_7876010892639789368);
void car_h_31(double *state, double *unused, double *out_6504383479818089409);
void car_H_31(double *state, double *unused, double *out_8486252504944912057);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}