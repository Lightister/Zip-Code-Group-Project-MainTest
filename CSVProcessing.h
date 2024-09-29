#ifndef CSVProcessingH
#define CSVProcessingH

#include "buffer.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class CSVProcessing {
public:
    bool sortBuffer(); // sort by state with the hashmap but how once it is sorted we can do the direction farthest zip
    // we could also set up a const variable that will have the state ids based on their index/hasmap key and with that we can instantlly find where the zip should go

    void addHeader( string& file_name );

    bool csvOutput( string& file_name );
};

#endif