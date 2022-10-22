#include "stats.h"
#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cmath>

Stats Statistics::ComputeStatistics(const std::vector<float>& vari) {
    //Implement statistics here
    float x = 0;
    Stats var ;
//     var.average = vari.at(0);
    var.average = accumulate( vari.begin(), vari.end(), 0.0/ vari.size());
    std::vector<float>::iterator result;
    result = std::max_element(&vari.begin(), &vari.end());
    var.max = *result;
    
    
//     var.min = std::min_element(vari.begin(), vari.end());
    return var;
}
