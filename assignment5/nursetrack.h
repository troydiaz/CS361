#ifndef NURSE_TRACK_H
#define NURSE_TRACK_H

#include <iostream>
#include <string>
#include <map>

/********************************************************************* 
** Function: login
** Description: Prompts the user for a username and password and checks 
**              if the credentials match the expected values.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns true if the login is successful, otherwise false.
*********************************************************************/
bool login();

/********************************************************************* 
** Function: viewSchedule
** Description: Displays the user's schedule with predefined shifts.
** Parameters: None
** Pre-Conditions: User is logged in.
** Post-Conditions: Prints the schedule to the console.
*********************************************************************/
void viewSchedule();

/********************************************************************* 
** Function: viewCertificationStatus
** Description: Displays the user's certifications and their expiration dates.
**              Alerts the user if a certification is expiring soon.
** Parameters: None
** Pre-Conditions: User is logged in.
** Post-Conditions: Prints certification information to the console.
*********************************************************************/
void viewCertificationStatus();

/********************************************************************* 
** Function: displayTrainingModel
** Description: Displays the training model with its title and estimated duration.
** Parameters: None
** Pre-Conditions: User selects the training model option.
** Post-Conditions: Prints the training information to the console.
*********************************************************************/
void displayTrainingModel();


/********************************************************************* 
** Function: navigateBack
** Description: Allows users to go back to the previous menu.
** Parameters: None
** Pre-Conditions: User is in a submenu.
** Post-Conditions: Returns user to main menu or previous state.
*********************************************************************/
void navigateBack();

/********************************************************************* 
** Function: displayToolTip
** Description: Displays a tooltip message on the homepage to explain
**              the purpose of each feature.
** Parameters: None
** Pre-Conditions: User is on the homepage.
** Post-Conditions: Displays tooltips for each feature.
*********************************************************************/
void displayToolTip();

/********************************************************************* 
** Function: displayTrainingResources
** Description: Displays available training resources with estimated
**              time commitments for each.
** Parameters: None
** Pre-Conditions: User accesses training resources.
** Post-Conditions: Prints the resources and time estimates.
*********************************************************************/
void displayTrainingResources();

/********************************************************************* 
** Function: displayDetailedSchedule
** Description: Displays a more detailed view of a shift, including
**              supervisor notes if any.
** Parameters: int day - the day of the week selected by the user.
** Pre-Conditions: User views schedule and selects a day.
** Post-Conditions: Prints detailed shift information.
*********************************************************************/
void displayDetailedSchedule(int day);

/********************************************************************* 
** Function: displayDailyTasks
** Description: Displays a list of tasks for the day with a timeline
**              and allows marking tasks as done or not done.
** Parameters: None
** Pre-Conditions: User is logged in.
** Post-Conditions: Prints tasks and allows marking as done/not done.
*********************************************************************/
void displayDailyTasks();

/********************************************************************* 
** Function: modifySchedule
** Description: Allows users to experiment with adjusting their schedule.
** Parameters: int day - the day to modify.
** Pre-Conditions: User is viewing schedule.
** Post-Conditions: Shows modified schedule for confirmation.
*********************************************************************/
void modifySchedule(const std::string& day);

/********************************************************************* 
** Function: confirmTaskAddition
** Description: Displays a confirmation prompt before adding a new task.
** Parameters: const std::string& task - task description.
** Pre-Conditions: User attempts to add a task.
** Post-Conditions: Adds the task if confirmed.
*********************************************************************/
void confirmTaskAddition(const std::string& task);

/********************************************************************* 
** Function: confirmViewDailyTasks
** Description: Asks the user to confirm before displaying daily tasks.
** Parameters: None
** Pre-Conditions: User selects the option to view daily tasks.
** Post-Conditions: Displays daily tasks if confirmed.
*********************************************************************/
void confirmViewDailyTasks();

#endif 
