#include "stats.h"
#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <cmath>
#include <math.h>

Stats Statistics::ComputeStatistics(const std::vector<float>& vari) {
    //Implement statistics here
//     float x = 0;
    Stats var ;
//     var.average = vari.at(0);
//     if (isnan(accumulate( vari.begin(), vari.end(), 0.0)/ vari.size()) == 0)
//     {
//         var.average = accumulate( vari.begin(), vari.end(), 0.0)/ vari.size();
//     }
    
    
    
    auto sum = accumulate( vari.begin(), vari.end(), 0.0);
    if (isnan(sum/vari.size()) == 0 )
    {
        var.average = sum/vari.size();
    }
    else {var.average = 0;}
    
    
    
    
//     var.average = isnan
//     if (isnan(accumulate( vari.begin(), vari.end(), 0.0)/ vari.size()) == 0)
//     {
//         var.average = accumulate( vari.begin(), vari.end(), 0.0)/ vari.size();
//     }
    
//     std::cout << "var.average = " << var.average << "\n";
//     std::vector<float>::iterator result;
    
    
    auto result = std::max_element(vari.begin(), vari.end());
    if (isnan(*result) == 0)
    {
       var.max = *result; 
    }
    var.max = *result;
//     std::cout << "var.max = " << var.max << "\n";
    
    
     auto result1 = std::min_element(vari.begin(), vari.end());
    if (isnan(*result1) == 0)
    {
       var.min = *result1;
    }
    
//     std::cout << "var.min = " << var.min << "\n";
    
//     var.min = std::min_element(vari.begin(), vari.end());
    return var;
}
