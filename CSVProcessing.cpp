#include "buffer.h"
#include "CSVProcessing.h"
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
//using namespace std;


void CSVProcessing::printZipCodeRecord( const ZipCodeRecord& record ) {
    std::cout << "Zip Code: " << record.zip_code
        << ", State ID: " << record.state_id
        << ", Latitude: " << record.latitude
        << ", Longitude: " << record.longitude << std::endl;
}
std::map<string, std::vector<ZipCodeRecord>> CSVProcessing::sortBuffer() { 
    float eastMost, westMost, northMost, southMost;
    Buffer CSVBuffer;
    CSVBuffer.read_csv( );
    std::map<string, std::vector<ZipCodeRecord>> state_zip_map = CSVBuffer.get_state_zip_codes();
    std::map<string, std::vector<ZipCodeRecord>> sorted_directions;
    for ( auto& state : state_zip_map ) {
        const std::string& stateID = state.first;
        const std::vector<ZipCodeRecord>& stateInfo = state.second;
        // intial loading of directions
        ZipCodeRecord easternmost = stateInfo[ 0 ];
        ZipCodeRecord westernmost = stateInfo[ 0 ];
        ZipCodeRecord northernmost = stateInfo[ 0 ];
        ZipCodeRecord southernmost = stateInfo[ 0 ];
        // checks if the current records zip is one of the maxed directions
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
        }
        sorted_directions[ stateID ] = { easternmost, westernmost, northernmost, southernmost };
        // std::cout << "State: " << stateID << std::endl;
        // std::cout << "  Easternmost: ";
        // printZipCodeRecord( easternmost );
        // std::cout << "  Westernmost: ";
        // printZipCodeRecord( westernmost );
        // std::cout << "  Northernmost: ";
        // printZipCodeRecord( northernmost );
        // std::cout << "  Southernmost: ";
        // printZipCodeRecord( southernmost );
        // std::cout << std::endl;  // Add an extra line for readability
    }
    // sorted_directions looks like this
    // [stateID] : {
    //     { east most zip, stateID, directions },
    //     { west most zip, stateID, directions },
    //     { northern most zip, stateID, directions },
    //     { southern most zip, stateID, directions }
    // }
    
    return sorted_directions;
}   
void CSVProcessing::addHeader( std::string& file_name ) { // state id, Easternmost (least longitude), Westernmost, Northernmost (greatest latitude), and Southernmost Zip Code
    
}

bool CSVProcessing::csvOutput( std::string& file_name ) { // fill from the sortered buffer? either output as we go from the buffer or create an array or vector to put all the sorting and then output to the csv
    return true;
}