import json
import schedule
import time
from datetime import datetime, timedelta
import os

REMINDER_FILE = "reminders.json"

def log_reminder(message, time):
    reminder = {"message": message, "time": time}
    reminders = get_reminders()
    reminders.append(reminder)
    with open(REMINDER_FILE, "w") as file:
        json.dump(reminders, file)

def get_reminders():
    try:
        with open(REMINDER_FILE, "r") as file:
            return json.load(file)
    except FileNotFoundError:
        return []

def show_reminder(message):
    os.system(f"""
              osascript -e 'display notification "{message}" with title "Workout Reminder"'
              """)
    print(f"Notification sent: {message}")

def setup_test_reminder():
    test_message = "Time for your workout!"
    reminder_time = (datetime.now() + timedelta(minutes=1)).strftime("%H:%M")
    log_reminder(test_message, reminder_time)
    schedule.every().day.at(reminder_time).do(show_reminder, message=test_message)
    print(f"Test reminder set for {reminder_time}")

def run_test():
    setup_test_reminder()
    print("Running test. Check for notifications at the scheduled time.")
    while True:
        schedule.run_pending()
        time.sleep(1)

if __name__ == "__main__":
    run_test()
