/*********************************************************************** 
** Program Filename: main.c
** Author: Troy Diaz
** Date: 10/28/2024
** Description: This is a simple C++ console-based program that simulates a Nursing Management System.
** The program provides basic functionality for user login, viewing schedules, and checking
** certification statuses.
** Input and Output: 
**      1 - View Schedule
**      2 - View Certification Status
**      3 - Acess Training Model
**      4 - View Daily tasks
**      5 - Logout
**      6 - Exit
*********************************************************************/

#include <iostream>
#include <string>
#include <map>
#include "nursetrack.h"

// User credentials, certifications, task completion, scheduling
const std::string USERNAME = "diaztr";
const std::string PASSWORD = "CS361";
std::map<std::string, std::string> certifications = {{"CPR", "2024-11-30"}, {"BLS", "2025-01-15"}};
bool taskStatus[3] = {false, false, false};
std::map<std::string, std::string> schedule = {
    {"Monday", "9 AM - 5 PM"},
    {"Wednesday", "9 AM - 5 PM"},
    {"Friday", "9 AM - 5 PM"}
};

int main() {
    int choice;
    bool loggedIn = false;

    std::cout << "Welcome to NurseTrack!\n";
    displayToolTip();

    // Main menu loop
    while (true) {
        // Ensure the user is logged in before showing the menu
        if (!loggedIn) {
            loggedIn = login();
            if (!loggedIn) {
                std::cout << "Invalid login. Try again.\n";
                continue; 
            }
        }

        // Display the menu options
        std::cout << "\nPlease choose an option:\n";
        std::cout << "1. View Schedule\n";
        std::cout << "2. View Certification Status\n";
        std::cout << "3. Access Training Model\n";
        std::cout << "4. View Daily Tasks\n";
        std::cout << "5. Log Out\n";
        std::cout << "6. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;



        // Handle user’s choice
        switch (choice) {
            case 1:
                viewSchedule();
                std::cout << "Would you like to modify a specific day’s schedule? (y/n): ";
                char modifyChoice;
                std::cin >> modifyChoice;
                if (modifyChoice == 'y' || modifyChoice == 'Y') {
                    std::cout << "Enter the day (e.g., Monday): ";
                    std::string day;
                    std::cin >> day;
                    modifySchedule(day);
                }
                navigateBack();
                break;
            case 2:
                viewCertificationStatus();
                navigateBack();
                break;
            case 3:
                displayTrainingModel();
                navigateBack();
                break;
            case 4:
                confirmViewDailyTasks();
                navigateBack();
                break;
            case 5:
                loggedIn = false;
                std::cout << "Logged out successfully.\n";
                navigateBack();
                break;
            case 6:
                std::cout << "Exiting the program. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid option. Please try again.\n";
                navigateBack();
                break;
        }
    }
}

bool login() {
    std::string username, password;
    std::cout << "\n--Login--\n";
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    // Check if entered credentials match the expected values
    if (username == USERNAME && password == PASSWORD) {
        std::cout << "Login successful!\n";
        return true;
    } else {
        std::cout << "Login failed. Incorrect username or password.\n";
        return false;
    }
}

void navigateBack() {
    std::cout << "\nReturning to the previous menu...\n";
}

void displayTrainingModel() {
    std::cout << "\nTraining Model:\n";
    std::cout << "Title: Learn How To Do CPR\n";
    std::cout << "Estimated Duration: 4 mins, 2 secs\n";
    std::cout << "Link: https://www.youtube.com/watch?v=hizBdM1Ob68 \n";
}


void viewSchedule() {
    std::cout << "\nYour Schedule:\n";
    for (const auto& day : schedule) {
        std::cout << day.first << ": " << day.second << "\n";
    }
    std::cout << "(No upcoming shifts beyond these.)\n";
}

void viewCertificationStatus() {
    std::cout << "\nCertification Status:\n";
    for (const auto& cert : certifications) {
        std::cout << cert.first << " - Expires on: " << cert.second;
        // Alert if the certification expires soon
        if (cert.second < "2024-12-31") {
            std::cout << " [ALERT: Certification is expiring soon!]";
        }
        std::cout << "\n";
    }
}

void displayToolTip() {
    std::cout << "\nTips for Using NurseTrack:\n";
    std::cout << "- 'View Schedule' helps you stay on top of your shifts.\n";
    std::cout << "- 'View Certification Status' ensures your certifications are up-to-date.\n";
    std::cout << "Explore each feature to better manage your tasks!\n";
}

void displayTrainingResources() {
    std::cout << "\nAvailable Training Resources:\n";
    std::cout << "1. CPR Refresher - Estimated time: 2 hours\n";
    std::cout << "2. Patient Safety Training - Estimated time: 3 hours\n";
    std::cout << "3. Advanced Care Techniques - Estimated time: 4 hours\n";
}

void displayDetailedSchedule(int day) {
    std::cout << "\nDetailed Schedule for Day " << day << ":\n";
    std::cout << "- Shift: 9 AM to 5 PM\n";
    std::cout << "- Supervisor's Note: Please prepare for patient rounds at 10 AM.\n";
}

void displayDailyTasks() {
    int taskChoice;

    while (true) {
        // Display the list of tasks with their status
        std::cout << "\nToday's Tasks:\n";
        std::cout << "1. Patient Check-in (9:00 AM) - [" << (taskStatus[0] ? "Done" : "Not Done") << "]\n";
        std::cout << "2. Medication Distribution (11:00 AM) - [" << (taskStatus[1] ? "Done" : "Not Done") << "]\n";
        std::cout << "3. Patient Rounds (2:00 PM) - [" << (taskStatus[2] ? "Done" : "Not Done") << "]\n";
        std::cout << "Enter the task number to mark as done, or 0 to return to the previous menu: ";
        std::cin >> taskChoice;

        // Check if the user wants to exit
        if (taskChoice == 0) {
            break;
        }

        // Validate the task number
        if (taskChoice >= 1 && taskChoice <= 3) {
            taskStatus[taskChoice - 1] = true;
            std::cout << "Task " << taskChoice << " marked as Done.\n";
        } else {
            std::cout << "Invalid task number. Please try again.\n";
        }
    }
}


void confirmTaskAddition(const std::string& task) {
    char choice;
    std::cout << "Are you sure you want to add the task: \"" << task << "\"? (y/n): ";
    std::cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        std::cout << "Task added successfully!\n";
    } else {
        std::cout << "Task addition canceled.\n";
    }
}

void modifySchedule(const std::string& day) {
    if (schedule.find(day) == schedule.end()) {
        std::cout << "Invalid day. Please choose Monday, Wednesday, or Friday.\n";
        return;
    }

    std::cout << "\nCurrent shift for " << day << ": " << schedule[day] << "\n";
    std::cout << "Enter new start time (e.g., 8 AM): ";
    std::string newShiftStart;
    std::cin.ignore();
    std::getline(std::cin, newShiftStart);

    std::cout << "Enter new end time (e.g., 4 PM): ";
    std::string newShiftEnd;
    std::getline(std::cin, newShiftEnd);

    schedule[day] = newShiftStart + " - " + newShiftEnd;
    std::cout << "Updated shift for " << day << ": " << schedule[day] << "\n";
}


void confirmViewDailyTasks() {
    std::cout << "\nAre you sure you want to view today's tasks? (y/n): ";
    char choice;
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        displayDailyTasks();
    } else {
        std::cout << "Returning to the previous menu without viewing tasks.\n";
    }
}
