#include <iostream>
#include <fstream>
#include <iomanip>

double scaleNumber(double input) {
    double output = ((input-1)*3/4)-1;
    return output;
}

int main()
{
    std::string inputFile = "data.csv";
    std::string outputFile = "result.csv";
    int n = 0;

    std::ifstream ifstr;
    ifstr.open(inputFile);
    if(ifstr.fail()) {
        std::cerr << "Input file not found" << std::endl;
        return 1;
    }

    std::ofstream ofstr;
    ofstr.open(outputFile);
    if(ofstr.fail()) {
        std::cerr << "Output file not found" << std::endl;
        return 1;
    }

    ofstr << "# N Mean" << std::endl;
    double partialSum = 0;
    double inputVal;
    while(ifstr >> inputVal) {
        partialSum += scaleNumber(inputVal);
        n += 1;
        ofstr << std::scientific << std::setprecision(16) << n << " " << (partialSum)/n << std::endl;
    }

    ifstr.close();
    ofstr.close();
    return 0;
}
