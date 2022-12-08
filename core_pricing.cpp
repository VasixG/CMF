#include <iostream>
#include "core_pricing.h"


double linear_discount(std::vector<double> params){
    return std::pow(1+params[0],-(params[2] - params[1]));
}


double exponent_discount(std::vector<double> params){
    return std::exp(-params[0]*(params[2] - params[1]));
}
