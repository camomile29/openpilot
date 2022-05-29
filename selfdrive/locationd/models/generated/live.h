#pragma once
#include "rednose/helpers/common_ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_7055742124100931411);
void live_err_fun(double *nom_x, double *delta_x, double *out_4236202907969071612);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_3472803829858283924);
void live_H_mod_fun(double *state, double *out_7809596661238633716);
void live_f_fun(double *state, double dt, double *out_2747518495708528538);
void live_F_fun(double *state, double dt, double *out_6633076029712775316);
void live_h_4(double *state, double *unused, double *out_7450849656415594550);
void live_H_4(double *state, double *unused, double *out_2188482437517857478);
void live_h_9(double *state, double *unused, double *out_5729835913013075368);
void live_H_9(double *state, double *unused, double *out_5098736497746589992);
void live_h_10(double *state, double *unused, double *out_3794268530949114176);
void live_H_10(double *state, double *unused, double *out_2838158283277705284);
void live_h_12(double *state, double *unused, double *out_1039917342867885396);
void live_H_12(double *state, double *unused, double *out_8569740814560590474);
void live_h_31(double *state, double *unused, double *out_3602109393995571382);
void live_H_31(double *state, double *unused, double *out_5576537002839118026);
void live_h_32(double *state, double *unused, double *out_5818812930657975874);
void live_H_32(double *state, double *unused, double *out_466659889856149704);
void live_h_13(double *state, double *unused, double *out_3839398077795054718);
void live_H_13(double *state, double *unused, double *out_447147904656159399);
void live_h_14(double *state, double *unused, double *out_5729835913013075368);
void live_H_14(double *state, double *unused, double *out_5098736497746589992);
void live_h_33(double *state, double *unused, double *out_841378325205049472);
void live_H_33(double *state, double *unused, double *out_7071978160581087289);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}