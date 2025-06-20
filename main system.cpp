#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

// Function declarations
void displayMenu();
void inputTemperatureForDay(double dayTemps[], double nightTemps[], int& currentDay);
void calculateFluctuation(const double dayTemps[], const double nightTemps[], int days);
double celsiusToFahrenheit(double celsius);
void analyzeSuitability(const double dayTemps[], const double nightTemps[], int days);
void findMaxMinTemperatures(const double dayTemps[], const double nightTemps[], int days);
void login();
void registration();
void forgot();

// Constants
const int DAYS_IN_MONTH = 30;
const double OPTIMAL_DAY_TEMP_LOW = 70.0;
const double OPTIMAL_DAY_TEMP_HIGH = 80.0;
const double OPTIMAL_NIGHT_TEMP_LOW = 55.0;
const double OPTIMAL_NIGHT_TEMP_HIGH = 62.0;

int main() {
	
	int c;
    cout << "\t\t\t_______________________________________\n\n\n";
    cout << "\t\t\t       WELCOME TO THE LOGIN PAGE        \n\n\n";
    cout << "\t\t\t________________  MENU     ______________\n\n\n";
    cout << "                                                \n\n\n";
    cout << "\t| Press 1 to LOGIN                            |" << endl;
    cout << "\t| Press 2 to REGISTER                         |" << endl;
    cout << "\t| Press 3 if you forgot your PASSWORD         |" << endl;
    cout << "\t| Press 4 to EXIT                             |" << endl;
    cout << "\n\t\t\t Please enter your choice  :  ";
    cin >> c;
    cout << endl;

    switch (c) {
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout << "\t\t\t Thank you! \n\n";
            break;
        default:
            system("cls");
            cout << "\t\t\t Please select a valid option from the menu above.\n" << endl;
            main();
    }
	
    double dayTemps[DAYS_IN_MONTH] = {0};
    double nightTemps[DAYS_IN_MONTH] = {0};
    int currentDay = 0;
    int choice;

    do {
        
	
		displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                inputTemperatureForDay(dayTemps, nightTemps, currentDay);
                break;
            case 2:
                calculateFluctuation(dayTemps, nightTemps, currentDay);
                break;
            case 3: {
                double celsius;
                std::cout << "Enter temperature in Celsius: ";
                std::cin >> celsius;
                std::cout << "Temperature in Fahrenheit: " << celsiusToFahrenheit(celsius) << "°F\n";
                break;
            }
            case 4:
                analyzeSuitability(dayTemps, nightTemps, currentDay);
                break;
            case 5:
                findMaxMinTemperatures(dayTemps, nightTemps, currentDay);
                break;
            case 6:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}

// Function to display the main menu
void displayMenu() {
    std::cout << "\nOrchi-Flora Temperature Analysis System\n";
    std::cout << "1. Input Day and Night Temperature for a Day\n";
    std::cout << "2. Calculate Daily and Monthly Temperature Fluctuation\n";
    std::cout << "3. Convert Celsius to Fahrenheit\n";
    std::cout << "4. Analyze Temperature Suitability\n";
    std::cout << "5. Find Maximum and Minimum Temperatures\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

// Function to input temperatures for one day
void inputTemperatureForDay(double dayTemps[], double nightTemps[], int& currentDay) {
    if (currentDay >= DAYS_IN_MONTH) {
        std::cout << "All 30 days of temperature data have already been entered.\n";
        return;
    }

    std::cout << "Enter daytime temperature for day " << (currentDay + 1) << ": ";
    std::cin >> dayTemps[currentDay];
    std::cout << "Enter nighttime temperature for day " << (currentDay + 1) << ": ";
    std::cin >> nightTemps[currentDay];
    currentDay++;

    std::cout << "Temperature data for day " << currentDay << " has been recorded.\n";
}

// Function to calculate daily and monthly temperatfluctuation
void calculateFluctuation(const double dayTemps[], const double nightTemps[], int days) {
    double totalFluctuation = 0.0;
    std::cout << "\nDay\tDaytime Temp\tNighttime Temp\tFluctuation\n";
    for (int i = 0; i < days; ++i) {
        double fluctuation = dayTemps[i] - nightTemps[i];
        totalFluctuation += fluctuation;
        std::cout << (i + 1) << "\t" << dayTemps[i] << "\t\t" << nightTemps[i] << "\t\t" << fluctuation << "\n";
    }
    if (days > 0) {
        std::cout << "Average Monthly Temperature Fluctuation: " << (totalFluctuation / days) << "\n";
    } else {
        std::cout << "No temperature data available to calculate fluctuation.\n";
    }
}

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

// Function to analyze temperature suitability
void analyzeSuitability(const double dayTemps[], const double nightTemps[], int days) {
    int suitableDays = 0;
    for (int i = 0; i < days; ++i) {
        if (dayTemps[i] >= OPTIMAL_DAY_TEMP_LOW && dayTemps[i] <= OPTIMAL_DAY_TEMP_HIGH &&
            nightTemps[i] >= OPTIMAL_NIGHT_TEMP_LOW && nightTemps[i] <= OPTIMAL_NIGHT_TEMP_HIGH) {
            suitableDays++;
        }
    }
    std::cout << "Number of suitable days for orchid growth: " << suitableDays << " out of " << days << "\n";
}

// Function to find maximum and minimum temperatures
void findMaxMinTemperatures(const double dayTemps[], const double nightTemps[], int days) {
    if (days == 0) {
        std::cout << "No temperature data available to find maximum or minimum temperatures.\n";
        return;
    }

    double maxDayTemp = dayTemps[0], minDayTemp = dayTemps[0];
    double maxNightTemp = nightTemps[0], minNightTemp = nightTemps[0];

    for (int i = 1; i < days; ++i) {
        if (dayTemps[i] > maxDayTemp) maxDayTemp = dayTemps[i];
        if (dayTemps[i] < minDayTemp) minDayTemp = dayTemps[i];
        if (nightTemps[i] > maxNightTemp) maxNightTemp = nightTemps[i];
        if (nightTemps[i] < minNightTemp) minNightTemp = nightTemps[i];
    }

    std::cout << "Max Daytime Temperature: " << maxDayTemp << "\n";
    std::cout << "Min Daytime Temperature: " << minDayTemp << "\n";
    std::cout << "Max Nighttime Temperature: " << maxNightTemp << "\n";
    std::cout << "Min Nighttime Temperature: " << minNightTemp << "\n";
}

void login() {
    int count = 0;
    string userId, password, id, pass;
    system("cls");
    cout << "\t\t\t Please enter the username and password:\n";
    cout << "\t\t\t USERNAME: ";
    cin >> userId;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;

    ifstream input("records.txt");
    while (input >> id >> pass) {
        if (id == userId && pass == password) {
            count = 1;
            system("cls");
            break;
        }
    }
    input.close();

    if (count == 1) {
        cout << userId << "\n Your LOGIN is successful! \n Thanks for logging in!\n";
        
    } else {
        cout << "\n LOGIN ERROR \n Please check your username and password.\n";
        main();
    }
}

void registration() {  // Corrected the function name from 'redistration' to 'registration'
    string ruserId, rpassword;
    system("cls");
    cout << "\t\t\t Enter the username: ";
    cin >> ruserId;
    cout << "\t\t\t Enter the password: ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;
    f1.close();

    system("cls");
    cout << "\n\t\t\t Registration is successful!\n";
    main();
}

void forgot() {
    int option;
    system("cls");
    cout << "\t\t\t You forgot the password? No worries.\n";
    cout << " Press 1 to search your id by username\n";
    cout << " Press 2 to go back to the main menu\n";
    cout << "\t\t\t Enter your choice: ";
    cin >> option;

    switch (option) {
        case 1: {
            int count = 0;
            string suserId, sId, spass;
            cout << "\n\t\t\tEnter the username that you remember: ";
            cin >> suserId;

            ifstream f2("records.txt");
            while (f2 >> sId >> spass) {
                if (sId == suserId) {
                    count = 1;
                    break;
                }
            }
            f2.close();

            if (count == 1) {
                cout << "\n\n Your account is found!\n";
                cout << "\n\n Your password is: " << spass << "\n";
                main();
            } else {
                cout << "\n\t Sorry! Your account is not found!\n";
                main();
            }
            break;
        }
        case 2:
            main();
            break;
        default:
            cout << "\t\t Wrong choice! Please try again.\n";
            forgot();
    }
}

