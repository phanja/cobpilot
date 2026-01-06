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
void car_err_fun(double *nom_x, double *delta_x, double *out_8668144528362342596);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_3996262106928164937);
void car_H_mod_fun(double *state, double *out_8798921732928723077);
void car_f_fun(double *state, double dt, double *out_5900768154802542162);
void car_F_fun(double *state, double dt, double *out_5224568521139140234);
void car_h_25(double *state, double *unused, double *out_341581022161831241);
void car_H_25(double *state, double *unused, double *out_454634114868591302);
void car_h_24(double *state, double *unused, double *out_9195388967883110704);
void car_H_24(double *state, double *unused, double *out_1867662362907000139);
void car_h_30(double *state, double *unused, double *out_7551358472722692118);
void car_H_30(double *state, double *unused, double *out_4073062215259016896);
void car_h_26(double *state, double *unused, double *out_6191730941713322290);
void car_H_26(double *state, double *unused, double *out_3286869204005464922);
void car_h_27(double *state, double *unused, double *out_8929743703966672649);
void car_H_27(double *state, double *unused, double *out_1849468144075073679);
void car_h_29(double *state, double *unused, double *out_9204937766251178538);
void car_H_29(double *state, double *unused, double *out_3562830870944624712);
void car_h_28(double *state, double *unused, double *out_3638714882184163879);
void car_H_28(double *state, double *unused, double *out_1599200599379298461);
void car_h_31(double *state, double *unused, double *out_290620908051804654);
void car_H_31(double *state, double *unused, double *out_485280076745551730);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}