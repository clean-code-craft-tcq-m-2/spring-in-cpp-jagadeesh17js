#include "stats.h"
#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cmath>
#include <math.h>

Stats Statistics::ComputeStatistics(const std::vector<float>& vari) {
    //Implement statistics here
    Stats var ;
    
    if (vari.size() == 0)
    {
        var.average = std::nanf("0");
        var.min = std::nanf("0");
        var.max = std::nanf("0");
    }
    else
    {
        auto sum = accumulate( vari.begin(), vari.end(), 0.0);
        var.average = sum/vari.size();
        
        auto result = std::max_element(vari.begin(), vari.end());
        var.max = *result;
        
        auto result1 = std::min_element(vari.begin(), vari.end());
        var.min = *result1;
        
    }
    
    return var;
}
