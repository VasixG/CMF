#include <iostream>
#include "risks.h"

//future price from domestic and foreign rate
double futures_price_from_rates(double spot_price, double domestic_rate, double foreign_rate){
    return 0;
}

//changes of future price by 1 base point
double DV01(Futures& futures, std::vector<double> params, discount DF, dF_dr DF_rate){
    return (-futures.get_market_price())/DF(params) * DF_rate(params)*0.001;
}

//delta of futures
double delta(std::vector<double> params, dF_ds DF_spot){
    return DF_spot(params);
}

//partial derivative of the futures price with exponent discount from the rate
double d_exponent_discount_dr(std::vector<double> params){
    return -std::exp(-params[0]*(params[2] - params[1]))*(params[2] - params[1]);
}

//partial derivative of the futures price with linear discount from the rate
double d_linear_discount_dr(std::vector<double> params){
    return -std::pow(1+params[0],-(params[2] - params[1])-1)*(params[2] - params[1]);
}

//partial derivative of the futures price with exponent discount from the spot price
double d_exponent_discount_ds(std::vector<double> params){
    return std::exp(params[0]*(params[2] - params[1]));
}

//partial derivative of the futures price with linear discount from the spot price
double d_linear_discount_ds(std::vector<double> params){
    return std::pow(1+params[0],params[2] - params[1]);
}

