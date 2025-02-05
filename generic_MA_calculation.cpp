// lets use the concepts of moving average
// with the efficiency of templates

#include <iostream>
#include <vector>

template<typename T> // allows for parsing any data type
class MovingAverage{
    private:
        std::vector<T> data;    // we allow arrays of any data type and perform operations with any structure to return certain T type
        int timePeriod;
    public:
        MovingAverage(int p) : timePeriod(p){ }
        
        void addData(T value){
                // T must be the same type as the array
                // lets push data inside  with TA / TI i.e. time arrival or time interval
                data.push_back( value );
                if( data.size() > timePeriod ){
                    data.erase(data.begin()); // i keep only the elements from a certain period
                }
        }

        T calculate() const {
            // forcing static cast
            if( data.size() < timePeriod ){
                throw std::runtime_error("There s not enough data sets for your time period");
            }
            T sum = 0;
            // we use auto smart pointer to easily get whatever data type is on template T
            // then const means we have acquired a resource and its unchange until dropping it
            for( const auto& val : data ){
                sum += val;
            }
            return sum / timePeriod;    
        } 
};

int main(){
    MovingAverage<double> testMA(3);
    testMA.addData(100);
    testMA.addData(102);
    testMA.addData(104);
    std::cout << "Moving average for the given timeframe is: " << testMA.calculate() << std::endl;
    testMA.addData(106);
    std::cout << "Updating moving avg: " << testMA.calculate() << std::endl;

return 0;
}