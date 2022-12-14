#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"

#include <cmath>
#include <math.h>

TEST_CASE("reports average, minimum and maximum") {
    auto computedStats = Statistics::ComputeStatistics({1.5, 8.9, 3.2, 4.5});
    float epsilon = 0.001;
    REQUIRE(std::abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(std::abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(std::abs(computedStats.min - 1.5) < epsilon);
}

TEST_CASE("average is NaN for empty array") {
    auto computedStats = Statistics::ComputeStatistics({});
    //All fields of computedStats (average, max, min) must be
    //NAN (not-a-number), as defined in math.h
    
    std::cout << "computedStats.average = " << computedStats.average << std::endl;
    std::cout << "computedStats.max = " << computedStats.max << std::endl;
    std::cout << "computedStats.min = " << computedStats.min << std::endl;
    
    REQUIRE(std::isnan(computedStats.average));
    REQUIRE(std::isnan(computedStats.max));
    REQUIRE(std::isnan(computedStats.min));
    
//     isnan(computedStats.average);
//     isnan(computedStats.max);
//     isnan(computedStats.min);
    //Design the REQUIRE statement here.
    //Use http://www.cplusplus.com/reference/cmath/isnan/
}

class IAlerter {
    public:
//     StatsAlerter(
//     bool ledGlows;
    virtual void alert() {}
};


class EmailAlert : public IAlerter{
    public:
    bool emailSent;
    
    EmailAlert()
        {
            emailSent = false;
        }

        void alert(){
            emailSent= true;
        }
};

class LEDAlert : public IAlerter {
    public:
    bool ledGlows;
    
    LEDAlert()
        {
            ledGlows = false;
        }

        void alert(){
            ledGlows= true;
        }
    
};

// class LEDAlert : public IAlerter {
//     public:
//     bool ledGlows;
// };


class StatsAlerter {
    public:
    float maxT;
//     float maxe;
    std::vector<IAlerter*> m_alert;
    
    // constructor
    StatsAlerter(const float maxThreshold, std::vector<IAlerter*> alerter) 
    {maxT = maxThreshold; 
      m_alert = alerter;}
    
    void checkAndAlert(std::vector<float> vals ) 
    {
        auto comStat = Statistics::ComputeStatistics(vals);
        if (comStat.max > maxT)
        {
            for (size_t i = 0; i < m_alert.size(); i++)
        {
            m_alert.at(i)->alert();
        }
        }
//         maxe = vals.at(0);
    }
};

TEST_CASE("raises alerts when max is greater than threshold") {
    EmailAlert emailAlert;
    LEDAlert ledAlert;
    std::vector<IAlerter*> alerters = {&emailAlert, &ledAlert};
    
    const float maxThreshold = 10.2;
    StatsAlerter statsAlerter(maxThreshold, alerters);
    statsAlerter.checkAndAlert({99.8, 34.2, 4.5, 6.7});

    REQUIRE(emailAlert.emailSent);
    REQUIRE(ledAlert.ledGlows);
}
