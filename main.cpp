#include <iostream>
#include "core_pricing.h"
#include "risks.h"
#include "architecture.h"

int main()
{
    Futures fut1(1, 100);

    double time = 0.9, d_rate = 10, f_rate = 1;//time in years, rate in percent

    std::vector<double> params = {(d_rate - f_rate)/100 , time, fut1.get_maturity()};
    std::cout<<"Spot price(with exponent discount) at time = "<<time<<" is "<<fut1.asset_price(params, exponent_discount)<<"\n";
    std::cout<<"Spot price (with linear discount) at time = "<<time<<" is "<<fut1.asset_price(params, linear_discount)<<"\n";

    std::cout<<"DV01 (with exponent discount) at time = "<<time<<" and delta rate = "<<params[0]<<" is "<<DV01(fut1, params, exponent_discount, d_exponent_discount_dr)<<"\n";
    std::cout<<"DV01 (with linear discount) at time = "<<time<<" and delta rate = "<<params[0]<<" is "<<DV01(fut1, params, linear_discount, d_linear_discount_dr)<<"\n";

    std::cout<<"Delta (with linear discount) at time = "<<time<<" and delta rate = "<<params[0]<<" is "<<delta(params, d_linear_discount_ds)<<"\n";
    std::cout<<"Delta (with exponent discount) at time = "<<time<<" and delta rate = "<<params[0]<<" is "<<delta(params, d_exponent_discount_ds)<<"\n";

    return 0;
}
