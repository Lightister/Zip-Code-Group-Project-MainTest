#include "CSVProcessing.h"
#include "buffer.h"
#include <iostream>
using namespace std;

/**
 * @file main.cpp
 * @brief Implementation file that runs inherited functions.
 * 
 * Implemention of all the classes in this project especially CSVProcessing.h
 * 
 * @author 
 * Aidan Adams
 * @date 
 * 10/2/2024
 */
 
 /**
 * @brief Generates a header and puts the data into an output file
 * 
 * This Function uses the .addHeader() function to generate a premade header. 
 * The function then follow
 * 
 * @param origin the processor struct that is going to be used.
 * @param file the name to be given to the output file.
 */

void csvConvert_sort(CSVProcessing origin, string file)
{
	cout << "Generating header row." << endl;
    origin.addHeader(file);
	cout << "Checking for errors" << endl << "Errors: ";
	
	if (origin.csvOutput(file)) {
		cout << "No" << endl << "File made!";
	} else {
		cout << "Yes" << endl << "File not made.";
	}
	
};





int main() {
    CSVProcessing csvProcessor;

    std::string file_name = "output.csv";
	csvConvert_sort(csvProcessor, file_name);
    //csvProcessor.sortBuffer();

	
	


    return 0;
}