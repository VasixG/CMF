#ifndef CORE_PRICING_H_INCLUDED
#define CORE_PRICING_H_INCLUDED

#include <vector>
#include <cmath>

typedef double (*discount)(std::vector<double> params);

class Futures{

public:
    Futures(double _maturity, double _market_price): maturity{_maturity}, market_price{_market_price}{}
    ~Futures(){}

    double get_maturity() const{
        return maturity;
    }

    double get_market_price() const{
        return market_price;
    }

    double asset_price(std::vector<double> params, discount DF) const{
        return market_price*DF(params);
    }

private:
    double maturity;//in years
    double market_price;//in domestic or dollars
};


double linear_discount(std::vector<double> params);//linear discount

double exponent_discount(std::vector<double> params);//exponent discount

#endif // CORE_PRICING_H_INCLUDED
