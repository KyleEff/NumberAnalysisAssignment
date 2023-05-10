/*
Kyle Free
COSC 1436 - Programming Fundamentals I
4/25/23
Number Analysis Program

DESCRIPTION
This program asks the user for a filename, then attempts to read and write the numbers of said file
    into an array. After the array is in memory, it is passed through several functions that
    return properties about the array.

One namespace that contains one class and four functions.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
//#include <vector>

using namespace std;

namespace WeekSevenAssignment {

    class NumberAnalysis {
        // Attributes
        ifstream inputFile; // Input file stream

        int
            capacity, // Capacity of the array
            numbers[]; // The array of numbers read from the file

        public:
        //Constructor
        NumberAnalysis() :
            capacity(0)
                { openFileName(); }

        /*
            openFileName() asks the user for a file name,
                then adds ".txt" to the end of the input string.
            It then checks how many numbers are in the file, sets the capacity,
                then assigns elements in the array to the numbers in the file. 
        */
        void openFileName() {

            string fileName;
            //vector<int> temp;
            int numTemp; // Temporary Number variable

            cout << "Enter the file name (Hint: numbers): ";
            cin >> fileName; // Save file name

            inputFile.open(fileName + ".txt");

            while (!inputFile) { // File name validation

                cout << "No file found!\nPlease try again!" << endl;
                cin >> fileName;

                inputFile.open(fileName + ".txt");
            }

            while (inputFile >> numTemp)
                //temp.push_back(numTemp);
                capacity++;
            
            //capacity = temp.size();
            numbers[capacity] = 0; // Assign 0 to the array for overwriting

            inputFile.clear(); // Clear the input buffer
            inputFile.seekg(0); // Seek the beginning of the file

            // This loop runs through the file from the beginning
            //  and assigns the element in the array to the number in the file
            for (auto i{0}; i < capacity; i++) {

                inputFile >> numTemp;
                numbers[i] = numTemp;

                //numbers[i] = temp[i];
                //cout << numbers[i] << endl; // Debug statement
            }

            inputFile.close(); // Close file
        }

        // printArray() prints the array of the numbers read from file
        void printArray() {

            cout << "[ ";

            for (int n{0}; n < capacity; n++) {

                cout << numbers[n];

                if (n != capacity - 1)
                    cout << ", ";
            }

            cout << " ]" << endl;
        }

        // getArray() returns a pointer to the array of the object
        int* getArray()
            { return numbers; }

        // getCapacity() returns the capacity of the array as an integer
        int getCapacity()
            { return capacity; }
    };

    // lowest(int[], int) returns the lowest number of the array parameter
    int lowest(int nums[], int capacity) {

        int lowest = nums[0];

        for (auto n{1}; n < capacity; n++)
            if (nums[n] < lowest)
                lowest = nums[n];
        
        return lowest;
    }

    // highest(int[], int) returns the highest number of the array parameter
    int highest(int nums[], int capacity) {

        int highest = 0;

        for (auto n{0}; n < capacity; n++)
            if (nums[n] > highest)
                highest = nums[n];

        return highest;
    }

    // total(int[], int) returns the total of the array parameter
    int total(int nums[], int capacity) {

        int total = 0;

        for (auto n{0}; n < capacity; n++)
            total += nums[n];

        return total;
    }

    // average(int[], int) returns the average of the array parameter
    double average(int nums[], int capacity)
        { return (double) total(nums, capacity) / capacity; }
}

using namespace WeekSevenAssignment;

// Driver Function
int main() {

    NumberAnalysis run;
    run.printArray();

    // This print statement causes a Stack Smashing Error, but the program still runs.
    // I'm thinking it could be solved by assigning variables, but I don't want to
    cout << fixed
        << "LOWEST: "
        << lowest(run.getArray(), run.getCapacity()) << endl
        << "HIGHEST: "
        << highest(run.getArray(), run.getCapacity()) << endl
        << "TOTAL: "
        << total(run.getArray(), run.getCapacity()) << endl
        << "AVERAGE: "
        << average(run.getArray(), run.getCapacity())
        << endl;

    return 0;
}
