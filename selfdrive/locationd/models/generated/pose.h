#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void pose_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void pose_err_fun(double *nom_x, double *delta_x, double *out_8209796417683535985);
void pose_inv_err_fun(double *nom_x, double *true_x, double *out_6976163533526622915);
void pose_H_mod_fun(double *state, double *out_6041543424531509265);
void pose_f_fun(double *state, double dt, double *out_5172544763827630996);
void pose_F_fun(double *state, double dt, double *out_1597941670573176708);
void pose_h_4(double *state, double *unused, double *out_7358615542883756797);
void pose_H_4(double *state, double *unused, double *out_8247164004478167319);
void pose_h_10(double *state, double *unused, double *out_897342477259466820);
void pose_H_10(double *state, double *unused, double *out_7119477149316586896);
void pose_h_13(double *state, double *unused, double *out_9114003749945995778);
void pose_H_13(double *state, double *unused, double *out_5034890179145834518);
void pose_h_14(double *state, double *unused, double *out_5800236474318007471);
void pose_H_14(double *state, double *unused, double *out_4283923148138682790);
void pose_predict(double *in_x, double *in_P, double *in_Q, double dt);
}