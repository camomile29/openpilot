#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_199540798318950580);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2420915044893639067);
void car_H_mod_fun(double *state, double *out_4490157183911363619);
void car_f_fun(double *state, double dt, double *out_8239037477520625060);
void car_F_fun(double *state, double dt, double *out_7852320688245652381);
void car_h_25(double *state, double *unused, double *out_3415884930295058382);
void car_H_25(double *state, double *unused, double *out_6148378974632210115);
void car_h_24(double *state, double *unused, double *out_7725754466959682857);
void car_H_24(double *state, double *unused, double *out_8740439500275018365);
void car_h_30(double *state, double *unused, double *out_8116807121609340406);
void car_H_30(double *state, double *unused, double *out_1620682644504601917);
void car_h_26(double *state, double *unused, double *out_3115133853948494761);
void car_H_26(double *state, double *unused, double *out_2406875655758153891);
void car_h_27(double *state, double *unused, double *out_8631817626000644088);
void car_H_27(double *state, double *unused, double *out_3844276715688545134);
void car_h_29(double *state, double *unused, double *out_865162050397500359);
void car_H_29(double *state, double *unused, double *out_2130913988818994101);
void car_h_28(double *state, double *unused, double *out_3899295693975045192);
void car_H_28(double *state, double *unused, double *out_2951485028250536473);
void car_h_31(double *state, double *unused, double *out_5080775750968681610);
void car_H_31(double *state, double *unused, double *out_1780667553524802415);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}