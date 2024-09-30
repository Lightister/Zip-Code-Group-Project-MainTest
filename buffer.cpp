// Buffer.cpp
#include "buffer.h"
#include <sstream>
#include <iostream>

/**
 * @file Buffer.cpp
 * @brief Implementation of the Buffer class and ZipCodeRecord struct.
 * 
 * Implemention of the Buffer class for handling Zip Code data read 
 * from the CSV file us_postal_codes.csv. 
 * 
 * @author 
 * Daniel Eze
 * @date 
 * 9/29/2024
 */

/**
 * @brief Reads the CSV file and stores the zip code records.
 * 
 * This function opens the CSV file, reads its contents, and 
 * parses each line into a ZipCodeRecord, which is stored in a vector.
 * 
 * @param file_name The path to the CSV file (us_postal_codes.csv).
 * @return True if the file is read successfully, false otherwise.
 */
bool Buffer::read_csv() {
    std::ifstream file("us_postal_codes.csv"); // Open the file
    if (!file.is_open()) {
        std::cerr << "Error opening file: us_postal_codes.csv" << std::endl;
        return false;
    }

    std::string line;
    std::getline(file, line); // Skip the header line

    // Read each line of the file
    while (std::getline(file, line)) {
        records.push_back(parse_csv_line(line)); // Parse and store the line
    }

    file.close(); // Close the file
    return true; // Return true if reading was successful
}


/**
 * @brief Groups the Zip Code records by state.
 * 
 * This function organizes the Zip Code records into a map where each 
 * state ID is a key, and the value is a vector of ZipCodeRecord 
 * structures associated with that state.
 * 
 * @return A map with state IDs as keys and vectors of ZipCodeRecord 
 *         structures as values.
 */
std::map<std::string, std::vector<ZipCodeRecord>> Buffer::get_state_zip_codes() const {
    std::map<std::string, std::vector<ZipCodeRecord>> state_zip_map; // Create a map to hold state records
    
    // Loop through all records
    for (const auto& record : records) {
        state_zip_map[record.state_id].push_back(record); // Add record to the correct state
    }

    return state_zip_map; // Return the grouped records
}

/**
 * @brief Parses a line from the CSV into a ZipCodeRecord.
 * 
 * This function takes a single line of CSV data and extracts the 
 * Zip Code, state ID, latitude, and longitude to populate a 
 * ZipCodeRecord structure.
 * 
 * @param line A string representing a single line from the CSV file.
 * @return A ZipCodeRecord structure containing the parsed data.
 */
ZipCodeRecord Buffer::parse_csv_line(const std::string& line) const {
    std::stringstream ss(line); // Use stringstream to parse the line
    ZipCodeRecord record; // Create a ZipCodeRecord to hold the data

    // Extract and store each field
    std::getline(ss, record.zip_code, ','); // Get Zip Code
    std::getline(ss, record.state_id, ','); // Get State ID
    std::string latitude_str, longitude_str;
    std::getline(ss, latitude_str, ','); // Get Latitude as string
    std::getline(ss, longitude_str, ','); // Get Longitude as string
    record.latitude = std::stod(latitude_str); // Convert to double
    record.longitude = std::stod(longitude_str); // Convert to double
    return record; // Return the populated record
}
