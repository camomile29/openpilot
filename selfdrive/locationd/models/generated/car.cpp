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
 *                       Code generated with sympy 1.9                        *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_199540798318950580) {
   out_199540798318950580[0] = delta_x[0] + nom_x[0];
   out_199540798318950580[1] = delta_x[1] + nom_x[1];
   out_199540798318950580[2] = delta_x[2] + nom_x[2];
   out_199540798318950580[3] = delta_x[3] + nom_x[3];
   out_199540798318950580[4] = delta_x[4] + nom_x[4];
   out_199540798318950580[5] = delta_x[5] + nom_x[5];
   out_199540798318950580[6] = delta_x[6] + nom_x[6];
   out_199540798318950580[7] = delta_x[7] + nom_x[7];
   out_199540798318950580[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_2420915044893639067) {
   out_2420915044893639067[0] = -nom_x[0] + true_x[0];
   out_2420915044893639067[1] = -nom_x[1] + true_x[1];
   out_2420915044893639067[2] = -nom_x[2] + true_x[2];
   out_2420915044893639067[3] = -nom_x[3] + true_x[3];
   out_2420915044893639067[4] = -nom_x[4] + true_x[4];
   out_2420915044893639067[5] = -nom_x[5] + true_x[5];
   out_2420915044893639067[6] = -nom_x[6] + true_x[6];
   out_2420915044893639067[7] = -nom_x[7] + true_x[7];
   out_2420915044893639067[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_4490157183911363619) {
   out_4490157183911363619[0] = 1.0;
   out_4490157183911363619[1] = 0;
   out_4490157183911363619[2] = 0;
   out_4490157183911363619[3] = 0;
   out_4490157183911363619[4] = 0;
   out_4490157183911363619[5] = 0;
   out_4490157183911363619[6] = 0;
   out_4490157183911363619[7] = 0;
   out_4490157183911363619[8] = 0;
   out_4490157183911363619[9] = 0;
   out_4490157183911363619[10] = 1.0;
   out_4490157183911363619[11] = 0;
   out_4490157183911363619[12] = 0;
   out_4490157183911363619[13] = 0;
   out_4490157183911363619[14] = 0;
   out_4490157183911363619[15] = 0;
   out_4490157183911363619[16] = 0;
   out_4490157183911363619[17] = 0;
   out_4490157183911363619[18] = 0;
   out_4490157183911363619[19] = 0;
   out_4490157183911363619[20] = 1.0;
   out_4490157183911363619[21] = 0;
   out_4490157183911363619[22] = 0;
   out_4490157183911363619[23] = 0;
   out_4490157183911363619[24] = 0;
   out_4490157183911363619[25] = 0;
   out_4490157183911363619[26] = 0;
   out_4490157183911363619[27] = 0;
   out_4490157183911363619[28] = 0;
   out_4490157183911363619[29] = 0;
   out_4490157183911363619[30] = 1.0;
   out_4490157183911363619[31] = 0;
   out_4490157183911363619[32] = 0;
   out_4490157183911363619[33] = 0;
   out_4490157183911363619[34] = 0;
   out_4490157183911363619[35] = 0;
   out_4490157183911363619[36] = 0;
   out_4490157183911363619[37] = 0;
   out_4490157183911363619[38] = 0;
   out_4490157183911363619[39] = 0;
   out_4490157183911363619[40] = 1.0;
   out_4490157183911363619[41] = 0;
   out_4490157183911363619[42] = 0;
   out_4490157183911363619[43] = 0;
   out_4490157183911363619[44] = 0;
   out_4490157183911363619[45] = 0;
   out_4490157183911363619[46] = 0;
   out_4490157183911363619[47] = 0;
   out_4490157183911363619[48] = 0;
   out_4490157183911363619[49] = 0;
   out_4490157183911363619[50] = 1.0;
   out_4490157183911363619[51] = 0;
   out_4490157183911363619[52] = 0;
   out_4490157183911363619[53] = 0;
   out_4490157183911363619[54] = 0;
   out_4490157183911363619[55] = 0;
   out_4490157183911363619[56] = 0;
   out_4490157183911363619[57] = 0;
   out_4490157183911363619[58] = 0;
   out_4490157183911363619[59] = 0;
   out_4490157183911363619[60] = 1.0;
   out_4490157183911363619[61] = 0;
   out_4490157183911363619[62] = 0;
   out_4490157183911363619[63] = 0;
   out_4490157183911363619[64] = 0;
   out_4490157183911363619[65] = 0;
   out_4490157183911363619[66] = 0;
   out_4490157183911363619[67] = 0;
   out_4490157183911363619[68] = 0;
   out_4490157183911363619[69] = 0;
   out_4490157183911363619[70] = 1.0;
   out_4490157183911363619[71] = 0;
   out_4490157183911363619[72] = 0;
   out_4490157183911363619[73] = 0;
   out_4490157183911363619[74] = 0;
   out_4490157183911363619[75] = 0;
   out_4490157183911363619[76] = 0;
   out_4490157183911363619[77] = 0;
   out_4490157183911363619[78] = 0;
   out_4490157183911363619[79] = 0;
   out_4490157183911363619[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_8239037477520625060) {
   out_8239037477520625060[0] = state[0];
   out_8239037477520625060[1] = state[1];
   out_8239037477520625060[2] = state[2];
   out_8239037477520625060[3] = state[3];
   out_8239037477520625060[4] = state[4];
   out_8239037477520625060[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_8239037477520625060[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_8239037477520625060[7] = state[7];
   out_8239037477520625060[8] = state[8];
}
void F_fun(double *state, double dt, double *out_7852320688245652381) {
   out_7852320688245652381[0] = 1;
   out_7852320688245652381[1] = 0;
   out_7852320688245652381[2] = 0;
   out_7852320688245652381[3] = 0;
   out_7852320688245652381[4] = 0;
   out_7852320688245652381[5] = 0;
   out_7852320688245652381[6] = 0;
   out_7852320688245652381[7] = 0;
   out_7852320688245652381[8] = 0;
   out_7852320688245652381[9] = 0;
   out_7852320688245652381[10] = 1;
   out_7852320688245652381[11] = 0;
   out_7852320688245652381[12] = 0;
   out_7852320688245652381[13] = 0;
   out_7852320688245652381[14] = 0;
   out_7852320688245652381[15] = 0;
   out_7852320688245652381[16] = 0;
   out_7852320688245652381[17] = 0;
   out_7852320688245652381[18] = 0;
   out_7852320688245652381[19] = 0;
   out_7852320688245652381[20] = 1;
   out_7852320688245652381[21] = 0;
   out_7852320688245652381[22] = 0;
   out_7852320688245652381[23] = 0;
   out_7852320688245652381[24] = 0;
   out_7852320688245652381[25] = 0;
   out_7852320688245652381[26] = 0;
   out_7852320688245652381[27] = 0;
   out_7852320688245652381[28] = 0;
   out_7852320688245652381[29] = 0;
   out_7852320688245652381[30] = 1;
   out_7852320688245652381[31] = 0;
   out_7852320688245652381[32] = 0;
   out_7852320688245652381[33] = 0;
   out_7852320688245652381[34] = 0;
   out_7852320688245652381[35] = 0;
   out_7852320688245652381[36] = 0;
   out_7852320688245652381[37] = 0;
   out_7852320688245652381[38] = 0;
   out_7852320688245652381[39] = 0;
   out_7852320688245652381[40] = 1;
   out_7852320688245652381[41] = 0;
   out_7852320688245652381[42] = 0;
   out_7852320688245652381[43] = 0;
   out_7852320688245652381[44] = 0;
   out_7852320688245652381[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_7852320688245652381[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_7852320688245652381[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7852320688245652381[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_7852320688245652381[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_7852320688245652381[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_7852320688245652381[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_7852320688245652381[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_7852320688245652381[53] = -9.8000000000000007*dt;
   out_7852320688245652381[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_7852320688245652381[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_7852320688245652381[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7852320688245652381[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7852320688245652381[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_7852320688245652381[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_7852320688245652381[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_7852320688245652381[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_7852320688245652381[62] = 0;
   out_7852320688245652381[63] = 0;
   out_7852320688245652381[64] = 0;
   out_7852320688245652381[65] = 0;
   out_7852320688245652381[66] = 0;
   out_7852320688245652381[67] = 0;
   out_7852320688245652381[68] = 0;
   out_7852320688245652381[69] = 0;
   out_7852320688245652381[70] = 1;
   out_7852320688245652381[71] = 0;
   out_7852320688245652381[72] = 0;
   out_7852320688245652381[73] = 0;
   out_7852320688245652381[74] = 0;
   out_7852320688245652381[75] = 0;
   out_7852320688245652381[76] = 0;
   out_7852320688245652381[77] = 0;
   out_7852320688245652381[78] = 0;
   out_7852320688245652381[79] = 0;
   out_7852320688245652381[80] = 1;
}
void h_25(double *state, double *unused, double *out_3415884930295058382) {
   out_3415884930295058382[0] = state[6];
}
void H_25(double *state, double *unused, double *out_6148378974632210115) {
   out_6148378974632210115[0] = 0;
   out_6148378974632210115[1] = 0;
   out_6148378974632210115[2] = 0;
   out_6148378974632210115[3] = 0;
   out_6148378974632210115[4] = 0;
   out_6148378974632210115[5] = 0;
   out_6148378974632210115[6] = 1;
   out_6148378974632210115[7] = 0;
   out_6148378974632210115[8] = 0;
}
void h_24(double *state, double *unused, double *out_7725754466959682857) {
   out_7725754466959682857[0] = state[4];
   out_7725754466959682857[1] = state[5];
}
void H_24(double *state, double *unused, double *out_8740439500275018365) {
   out_8740439500275018365[0] = 0;
   out_8740439500275018365[1] = 0;
   out_8740439500275018365[2] = 0;
   out_8740439500275018365[3] = 0;
   out_8740439500275018365[4] = 1;
   out_8740439500275018365[5] = 0;
   out_8740439500275018365[6] = 0;
   out_8740439500275018365[7] = 0;
   out_8740439500275018365[8] = 0;
   out_8740439500275018365[9] = 0;
   out_8740439500275018365[10] = 0;
   out_8740439500275018365[11] = 0;
   out_8740439500275018365[12] = 0;
   out_8740439500275018365[13] = 0;
   out_8740439500275018365[14] = 1;
   out_8740439500275018365[15] = 0;
   out_8740439500275018365[16] = 0;
   out_8740439500275018365[17] = 0;
}
void h_30(double *state, double *unused, double *out_8116807121609340406) {
   out_8116807121609340406[0] = state[4];
}
void H_30(double *state, double *unused, double *out_1620682644504601917) {
   out_1620682644504601917[0] = 0;
   out_1620682644504601917[1] = 0;
   out_1620682644504601917[2] = 0;
   out_1620682644504601917[3] = 0;
   out_1620682644504601917[4] = 1;
   out_1620682644504601917[5] = 0;
   out_1620682644504601917[6] = 0;
   out_1620682644504601917[7] = 0;
   out_1620682644504601917[8] = 0;
}
void h_26(double *state, double *unused, double *out_3115133853948494761) {
   out_3115133853948494761[0] = state[7];
}
void H_26(double *state, double *unused, double *out_2406875655758153891) {
   out_2406875655758153891[0] = 0;
   out_2406875655758153891[1] = 0;
   out_2406875655758153891[2] = 0;
   out_2406875655758153891[3] = 0;
   out_2406875655758153891[4] = 0;
   out_2406875655758153891[5] = 0;
   out_2406875655758153891[6] = 0;
   out_2406875655758153891[7] = 1;
   out_2406875655758153891[8] = 0;
}
void h_27(double *state, double *unused, double *out_8631817626000644088) {
   out_8631817626000644088[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3844276715688545134) {
   out_3844276715688545134[0] = 0;
   out_3844276715688545134[1] = 0;
   out_3844276715688545134[2] = 0;
   out_3844276715688545134[3] = 1;
   out_3844276715688545134[4] = 0;
   out_3844276715688545134[5] = 0;
   out_3844276715688545134[6] = 0;
   out_3844276715688545134[7] = 0;
   out_3844276715688545134[8] = 0;
}
void h_29(double *state, double *unused, double *out_865162050397500359) {
   out_865162050397500359[0] = state[1];
}
void H_29(double *state, double *unused, double *out_2130913988818994101) {
   out_2130913988818994101[0] = 0;
   out_2130913988818994101[1] = 1;
   out_2130913988818994101[2] = 0;
   out_2130913988818994101[3] = 0;
   out_2130913988818994101[4] = 0;
   out_2130913988818994101[5] = 0;
   out_2130913988818994101[6] = 0;
   out_2130913988818994101[7] = 0;
   out_2130913988818994101[8] = 0;
}
void h_28(double *state, double *unused, double *out_3899295693975045192) {
   out_3899295693975045192[0] = state[0];
}
void H_28(double *state, double *unused, double *out_2951485028250536473) {
   out_2951485028250536473[0] = 1;
   out_2951485028250536473[1] = 0;
   out_2951485028250536473[2] = 0;
   out_2951485028250536473[3] = 0;
   out_2951485028250536473[4] = 0;
   out_2951485028250536473[5] = 0;
   out_2951485028250536473[6] = 0;
   out_2951485028250536473[7] = 0;
   out_2951485028250536473[8] = 0;
}
void h_31(double *state, double *unused, double *out_5080775750968681610) {
   out_5080775750968681610[0] = state[8];
}
void H_31(double *state, double *unused, double *out_1780667553524802415) {
   out_1780667553524802415[0] = 0;
   out_1780667553524802415[1] = 0;
   out_1780667553524802415[2] = 0;
   out_1780667553524802415[3] = 0;
   out_1780667553524802415[4] = 0;
   out_1780667553524802415[5] = 0;
   out_1780667553524802415[6] = 0;
   out_1780667553524802415[7] = 0;
   out_1780667553524802415[8] = 1;
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
void car_err_fun(double *nom_x, double *delta_x, double *out_199540798318950580) {
  err_fun(nom_x, delta_x, out_199540798318950580);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_2420915044893639067) {
  inv_err_fun(nom_x, true_x, out_2420915044893639067);
}
void car_H_mod_fun(double *state, double *out_4490157183911363619) {
  H_mod_fun(state, out_4490157183911363619);
}
void car_f_fun(double *state, double dt, double *out_8239037477520625060) {
  f_fun(state,  dt, out_8239037477520625060);
}
void car_F_fun(double *state, double dt, double *out_7852320688245652381) {
  F_fun(state,  dt, out_7852320688245652381);
}
void car_h_25(double *state, double *unused, double *out_3415884930295058382) {
  h_25(state, unused, out_3415884930295058382);
}
void car_H_25(double *state, double *unused, double *out_6148378974632210115) {
  H_25(state, unused, out_6148378974632210115);
}
void car_h_24(double *state, double *unused, double *out_7725754466959682857) {
  h_24(state, unused, out_7725754466959682857);
}
void car_H_24(double *state, double *unused, double *out_8740439500275018365) {
  H_24(state, unused, out_8740439500275018365);
}
void car_h_30(double *state, double *unused, double *out_8116807121609340406) {
  h_30(state, unused, out_8116807121609340406);
}
void car_H_30(double *state, double *unused, double *out_1620682644504601917) {
  H_30(state, unused, out_1620682644504601917);
}
void car_h_26(double *state, double *unused, double *out_3115133853948494761) {
  h_26(state, unused, out_3115133853948494761);
}
void car_H_26(double *state, double *unused, double *out_2406875655758153891) {
  H_26(state, unused, out_2406875655758153891);
}
void car_h_27(double *state, double *unused, double *out_8631817626000644088) {
  h_27(state, unused, out_8631817626000644088);
}
void car_H_27(double *state, double *unused, double *out_3844276715688545134) {
  H_27(state, unused, out_3844276715688545134);
}
void car_h_29(double *state, double *unused, double *out_865162050397500359) {
  h_29(state, unused, out_865162050397500359);
}
void car_H_29(double *state, double *unused, double *out_2130913988818994101) {
  H_29(state, unused, out_2130913988818994101);
}
void car_h_28(double *state, double *unused, double *out_3899295693975045192) {
  h_28(state, unused, out_3899295693975045192);
}
void car_H_28(double *state, double *unused, double *out_2951485028250536473) {
  H_28(state, unused, out_2951485028250536473);
}
void car_h_31(double *state, double *unused, double *out_5080775750968681610) {
  h_31(state, unused, out_5080775750968681610);
}
void car_H_31(double *state, double *unused, double *out_1780667553524802415) {
  H_31(state, unused, out_1780667553524802415);
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

ekf_init(car);
