#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_6780222169695424143);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_8876249299301829416);
void pose_H_mod_fun(double *state, double *out_3838064112468561781);
void pose_f_fun(double *state, double dt, double *out_3082222889402326840);
void pose_F_fun(double *state, double dt, double *out_574273013645914746);
void pose_h_4(double *state, double *unused, double *out_1822046223765446894);
void pose_H_4(double *state, double *unused, double *out_8760598154489031114);
void pose_h_10(double *state, double *unused, double *out_714441176925206643);
void pose_H_10(double *state, double *unused, double *out_6206202842202479986);
void pose_h_13(double *state, double *unused, double *out_1455872266858412491);
void pose_H_13(double *state, double *unused, double *out_6473872093888187701);
void pose_h_14(double *state, double *unused, double *out_1008373994480511149);
void pose_H_14(double *state, double *unused, double *out_5722905062881035973);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}