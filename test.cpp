#include "CSVProcessing.h"
#include "buffer.h"
#include <iostream>
using namespace std;
int main() {
    CSVProcessing csvProcessor;

    std::string file_name = "output.csv";

    //csvProcessor.sortBuffer();

    csvProcessor.addHeader(file_name);
    if (csvProcessor.csvOutput(file_name)) {
        std::cout << "CSV processing completed successfully." << std::endl;
    } else {
        std::cerr << "Error occurred during CSV processing." << std::endl;
    }

    return 0;
}