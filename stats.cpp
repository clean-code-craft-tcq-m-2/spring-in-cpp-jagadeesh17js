#include "stats.h"
#include <iostream>
#include <numeric>

Stats Statistics::ComputeStatistics(const std::vector<float>& vari) {
    //Implement statistics here
    float x = 0;
    Stats var ;
//     var.average = vari.at(0);
    var.average = accumulate( vari.begin(), vari.end(), 0.0/ vari.size());
    var.max = x;
    var.min = x;
    return var;
}
