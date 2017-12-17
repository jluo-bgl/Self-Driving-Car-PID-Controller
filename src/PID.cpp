#include <iostream>
#include "PID.h"

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;

  prev_cte = 0.0;

  i_error = 0.0;
  p_error = 0.0;
  d_error = 0.0;
}

void PID::UpdateError(double cte) {
//  std::cout << cte << std::endl;
  p_error = cte;
  i_error = i_error + cte;
  d_error = cte - prev_cte;
  prev_cte = cte;
}

double PID::TotalError() {
  double value = Kp * p_error + Kd * d_error + i_error * Ki;
//  std::cout << "i error \t" << i_error << ", \t i correction \t" << (i_error * Ki) << ", \t d error \t" << d_error << ", \t d correction \t" << (Kd * d_error) << ", \t p error " << p_error << ", \t p correct \t" << (Kp * p_error) << ", \t value \t" << value << std::endl;
  return value;
}

