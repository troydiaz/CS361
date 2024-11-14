# test_microservice.py
import time
from SBmicroserviceA import setup_test_reminder, get_reminders

# Set up a test reminder
print("Setting a test reminder one minute from now.")
setup_test_reminder()

# Check the reminders JSON data after setting it up
reminders = get_reminders()
print("Current reminders logged in reminders.json:")
print(reminders)

# Keep the program running to allow time for notification
print("Waiting for notification...")
time.sleep(120)  # Wait for 2 minutes to allow notification to appear
