#ifndef ARCHITECTURE_H_INCLUDED
#define ARCHITECTURE_H_INCLUDED
#include <vector>
#include <string>

std::vector<std::string> load_col_names(std::string path){
    std::vector<std::string> cols{};
    return cols;
}

std::vector<std::vector<double>> load_data(std::string path){
    std::vector<std::vector<double>> data{};
    return data;
}

class Option{
public:

    Option(double _market_price = -1 , double _strike = -1 ,double _maturity = -1): market_price{_market_price}, strike{_strike},maturity{_maturity}{}

    virtual ~Option(){}

    void set_market_price(double _market_price){
        market_price = _market_price;
    }

    void set_maturity(double _maturity){
        maturity = _maturity;
    }

    void set_strike(double _strike){
        strike = _strike;
    }

    double get_market_price() const{
        return market_price;
    }

    double get_maturity() const{
        return maturity ;
    }

    double get_strike() const{
        return strike ;
    }

private:
    double market_price;
    double strike;
    double maturity;
};


class EuropeanOption: public Option{
public:

    EuropeanOption(double _market_price = -1 , double _strike = -1 ,double _maturity = -1, double _implied_volatility = -1, double _asset_price = -1, bool _type = 0): Option(_market_price, _strike, _maturity), type{_type}, implied_volatility{_implied_volatility}, asset_price{_asset_price}{}

    virtual ~EuropeanOption(){}

    double get_delta(double risk_rate, double time_from_start) const;

    double get_gamma(double risk_rate, double time_from_start) const;

    double get_theta(double risk_rate, double time_from_start) const;

    double get_vega(double risk_rate, double time_from_start) const;

    double get_rho(double risk_rate, double time_from_start) const;

private:
    bool type;//1 if call 0 if put
    double implied_volatility;
    double asset_price;
};


class AmericanOption: public Option{
public:

    AmericanOption(double _market_price = -1 , double _strike = -1 ,double _maturity = -1, double _implied_volatility=-1, double _asset_price=-1, bool _type=0): Option(_market_price, _strike, _maturity), type{_type}, implied_volatility{_implied_volatility}, asset_price{_asset_price}{}

    virtual ~AmericanOption(){}

    double get_delta(double risk_rate, double time_from_start) const;

    double get_gamma(double risk_rate, double time_from_start) const;

    double get_theta(double risk_rate, double time_from_start) const;

    double get_vega(double risk_rate, double time_from_start) const;

    double get_rho(double risk_rate, double time_from_start) const;

private:
    bool type;//1 if call 0 if put
    double implied_volatility;
    double asset_price;
};


class MarketData{
public:
    MarketData(std::string path):col_names{load_col_names(path)}, data{load_data(path)}{}

    ~MarketData(){
        delete &col_names;
        delete &data;
    }

    std::vector<std::string> get_cols() const{
        return col_names;
    }

    std::vector<std::vector<double>> get_data() const{
        return data;
    }

    std::vector<double> get_best_prices() const{
        std::vector<double> bbo{};
        return bbo;
    }

    double get_midprice() const{
        return 0;
    }

    double get_VWAP() const{
        return 0;
    }

    double get_orderbook_level(int level){
        return 0;
    }

private:
    std::vector<std::string> col_names;
    std::vector<std::vector<double>> data;
};

#endif // ARCHITECTURE_H_INCLUDED
