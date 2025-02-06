#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

template <typename T>

//lets asume our viable data are inside a CSV
class CSVLoader{
    public:
        static std::vector<T> loadBankingData(
            const std::string& filename ){
                std::vector<T> fData;
                std::ifstream kReadFromFile( filename );
                std::string fLine;
                while( std::getline( kReadFromFile , fLine ) ){
                    // while i can read some like with input stream flusher
                    std::stringstream ss( fLine ); // i make a string stream object
                    T value;
                    while( ss >> value ){
                        // i break it into contents
                        fData.push_back( value );
                        if( ss.peek() == ',' ) ss.ignore(); // we dont account for separators
                    }
                }
                return fData;
        }
};

int main(){
    auto data = CSVLoader<double>::loadData( 'stock_prices.csv' ); // lets presume that this folder exists
    std::cout << "Loaded data: ";
    for( const auto& val : data ){
        std::cout << val << " ";
    }
    std::cout << std::endl;
return 0;
}

// in this code we use smart the idea of templates since we dont know exactly what data type we might encounter
// thus it comes in handy to define a generic structure as datatype for our queues to store the data
