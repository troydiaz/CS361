import time
from SBmicroserviceA import setup_test_reminder, get_reminders, schedule

# Set up a test reminder
print("Setting a test reminder 10 seconds from now.")
setup_test_reminder()

# Retrieve and display the reminders logged in reminders.json
reminders = get_reminders()
print("Current reminders logged in reminders.json:")
print(reminders)

# Run the scheduler loop to check for pending jobs
print("Waiting for notification...")

while True:
    schedule.run_pending()  # Continuously checks for pending reminders
    time.sleep(1)
