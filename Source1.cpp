#include <iostream>
#include <fstream>
#include <iomanip>

const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;

// Function to read and store the data from the file
void readData(std::string runners[], int miles[][NUM_DAYS]) {
    std::ifstream inputFile("marathon_data.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        exit(1);
    }

    for (int i = 0; i < NUM_RUNNERS; ++i) {
        inputFile >> runners[i];
        for (int j = 0; j < NUM_DAYS; ++j) {
            inputFile >> miles[i][j];
        }
    }

    inputFile.close();
}

// Function to calculate total miles and average miles per day
void calculateStats(const std::string runners[], const int miles[][NUM_DAYS], int totalMiles[], double avgMiles[]) {
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        totalMiles[i] = 0;
        for (int j = 0; j < NUM_DAYS; ++j) {
            totalMiles[i] += miles[i][j];
        }
        avgMiles[i] = static_cast<double>(totalMiles[i]) / NUM_DAYS;
    }
}

// Function to output the results
void outputResults(const std::string runners[], const int miles[][NUM_DAYS], const int totalMiles[], const double avgMiles[]) {
    std::cout << std::left << std::setw(10) << "Runner";
    std::cout << std::left << std::setw(8) << "Day 1";
    std::cout << std::left << std::setw(8) << "Day 2";
    std::cout << std::left << std::setw(8) << "Day 3";
    std::cout << std::left << std::setw(8) << "Day 4";
    std::cout << std::left << std::setw(8) << "Day 5";
    std::cout << std::left << std::setw(8) << "Day 6";
    std::cout << std::left << std::setw(8) << "Day 7";
    std::cout << std::left << std::setw(10) << "Total";
    std::cout << std::left << std::setw(10) << "Avg" << std::endl;

    for (int i = 0; i < NUM_RUNNERS; ++i) {
        std::cout << std::left << std::setw(10) << runners[i];
        for (int j = 0; j < NUM_DAYS; ++j) {
            std::cout << std::left << std::setw(8) << miles[i][j];
        }
        std::cout << std::left << std::setw(10) << totalMiles[i];
        std::cout << std::left << std::setw(10) << std::fixed << std::setprecision(2) << avgMiles[i] << std::endl;
    }
}

int main() {
    std::string runners[NUM_RUNNERS];
    int miles[NUM_RUNNERS][NUM_DAYS];
    int totalMiles[NUM_RUNNERS];
    double avgMiles[NUM_RUNNERS];

    readData(runners, miles);
    calculateStats(runners, miles, totalMiles, avgMiles);
    outputResults(runners, miles, totalMiles, avgMiles);

    return 0;
}