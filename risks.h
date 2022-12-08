#ifndef RISKS_H_INCLUDED
#define RISKS_H_INCLUDED

#include "core_pricing.h"

typedef double (*dF_dr)(std::vector<double> params);//partial derivative of the futures price from the rate

typedef double (*dF_ds)(std::vector<double> params);//partial derivative of the futures price from the spot price

double futures_price_from_rates(double spot_price, double domestic_rate, double foreign_rate);//future price from domestic and foreign rate

double DV01(Futures& futures, std::vector<double> params, discount DF, dF_dr DF_rate);//changes of future price by 1 base point

double delta(std::vector<double> params, dF_ds DF_spot);//delta of futures

double d_exponent_discount_dr(std::vector<double> params);//partial derivative of the futures price with exponent discount from the rate

double d_linear_discount_dr(std::vector<double> params);//partial derivative of the futures price with linear discount from the rate

double d_exponent_discount_ds(std::vector<double> params);//partial derivative of the futures price with exponent discount from the spot price

double d_linear_discount_ds(std::vector<double> params);//partial derivative of the futures price with linear discount from the spot price

#endif // RISKS_H_INCLUDED
