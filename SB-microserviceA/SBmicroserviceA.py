import json
import schedule
import time
from datetime import datetime, timedelta
import os

REMINDER_FILE = "reminders.json"

# Function to log reminders to JSON
def log_reminder(message, time):
    reminder = {"message": message, "time": time}
    reminders = get_reminders()
    reminders.append(reminder)
    with open(REMINDER_FILE, "w") as file:
        json.dump(reminders, file)

# Function to retrieve reminders from JSON
def get_reminders():
    try:
        with open(REMINDER_FILE, "r") as file:
            return json.load(file)
    except FileNotFoundError:
        return []

# Function to show reminder notification (updated for macOS compatibility)
def show_reminder(message):
    os.system(f"""
              osascript -e 'display notification "{message}" with title "Workout Reminder"'
              """)
    print(f"Notification sent: {message}")

# Function to set up a test reminder (set to 10 seconds in the future for testing)
def setup_test_reminder():
    test_message = "Time for your workout!"
    reminder_time = (datetime.now() + timedelta(seconds=10)).strftime("%H:%M:%S")  # Set for 10 seconds later
    log_reminder(test_message, reminder_time)
    schedule.every().day.at(reminder_time).do(show_reminder, message=test_message)
    print(f"Test reminder set for {reminder_time}")

# Run the test function with added debug statements in the loop
def run_test():
    setup_test_reminder()
    print("Running test. Check for notifications at the scheduled time.")
    while True:
        schedule.run_pending()
        time.sleep(1)

if __name__ == "__main__":
    run_test()
