#include <vector>

namespace Statistics {
    
    class Stats {
        public:
        float average;
        float max;
        float min;
                };
    class EmailAlert {
        public:
        void emailSent();
                    };
    Stats ComputeStatistics(const std::vector<float>& );
}
