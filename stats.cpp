#include "stats.h"

Stats Statistics::ComputeStatistics(const std::vector<float>& vari) {
    //Implement statistics here
    float x = 0;
    Stats var ;
    var.average = vari.at(0);
    var.max = x;
    var.min = x;
    return var;
}
