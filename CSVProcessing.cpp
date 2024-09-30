#include "buffer.h"
#include "CSVProcessing.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;


map<string, vector<ZipCodeRecord>> CSVProcessing::sortBuffer() { // sort by state with the hashmap but how once it is sorted we can do the direction farthest zip
    float eastMost, westMost, northMost, southMost;
    Buffer CSVBuffer;
    map<string, vector<ZipCodeRecord>> state_zip_map = CSVBuffer.get_state_zip_codes();
    map<string, vector<ZipCodeRecord>> sorted_directions;
    for ( auto& state : state_zip_map ) {
        const string& stateID = state.first;
        const vector<ZipCodeRecord>& stateInfo = state.second;

        ZipCodeRecord easternmost = stateInfo[ 0 ];
        ZipCodeRecord westernmost = stateInfo[ 0 ];
        ZipCodeRecord northernmost = stateInfo[ 0 ];
        ZipCodeRecord southernmost = stateInfo[ 0 ];

        for ( const auto& record : stateInfo ) {
            if ( record.longitude < easternmost.longitude ) {
                easternmost = record;
            }
            if ( record.longitude > westernmost.longitude ) {
                westernmost = record;
            }
            if ( record.latitude > northernmost.latitude ) {
                northernmost = record;
            }
            if ( record.latitude < southernmost.latitude ) {
                southernmost = record;
            }
            sorted_directions[ stateID ] = { easternmost, westernmost, northernmost, southernmost };
        }
    }
    return sorted_directions;
}
    // we could also set up a const variable that will have the state ids based on their index/hasmap key and with that we can instantlly find where the zip should go
void CSVProcessing::addHeader( string& file_name ) { // state id, Easternmost (least longitude), Westernmost, Northernmost (greatest latitude), and Southernmost Zip Code
    
}

bool CSVProcessing::csvOutput( string& file_name ) { // fill from the sortered buffer? either output as we go from the buffer or create an array or vector to put all the sorting and then output to the csv
    
}