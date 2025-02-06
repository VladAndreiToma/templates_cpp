// building a black scholes price prediction using templates
// benefit from reusable code

#include <iostream>
#include <cmath>

template <typename T>
T normalDistribution( T x ){
    // classic gauss
    return 0.5*(1.0 + erf(x/std::sqrt(2.0)));
}

template <typename T>
T blackScholes( T S , T K , T r , T sigma , T t_expiry ){
    // calculating coeff
    T d1 = ( std::log(S/K) + 
        (r + 0.5 * pow(sigma,2)) * t_expiry ) / 
        (sigma*std::sqrt(t_expiry));
    T d2 = d1 - std::sqrt(t_expiry)*sigma;
    T callPrice = S * normalDistribution(d1) - 
        K*exp(-r*t_expiry)*normalDistribution(d2);
    return callPrice;
    // returning the prediction
}

int main(){
    double fStockPrice = 100;
    double fStrikePrice = 110;
    double fRiskFreeRate = 0.05;
    double fVolatility = 0.2;
    double t_expiry = 1;

    std::cout << "Option price: " << blackScholes( fStockPrice , 
        fStrikePrice , fRiskFreeRate , fVolatility , t_expiry ) << std::endl;
return 0;
}

// usage in: RISK ASSESSMENT & DERIVATIVE PRICING