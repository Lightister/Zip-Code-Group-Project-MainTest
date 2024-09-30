#ifndef CSVProcessingH
#define CSVProcessingH

#include "buffer.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class CSVProcessing {
public:
    map<string, vector<ZipCodeRecord>> sortBuffer(); // sort by state with the hashmap but how once it is sorted we can do the direction farthest zip
    // we could also set up a const variable that will have the state ids based on their index/hasmap key and with that we can instantlly find where the zip should go

    void addHeader( string& file_name ); // state id, Easternmost (least longitude), Westernmost, Northernmost (greatest latitude), and Southernmost Zip Code

    bool csvOutput( string& file_name ); // fill from the sortered buffer? either output as we go from the buffer or create an array or vector to put all the sorting and then output to the csv
};

#endif