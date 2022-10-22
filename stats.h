#include <vector>

namespace Statistics {
    struct {
        float average;
        float max;
        float min;}
    Stats;
    Stats ComputeStatistics(const std::vector<float>& );
}
