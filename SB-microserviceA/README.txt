Workout Reminder Microservice
------------

This microservice allows users to set, edit, and receive workout reminders on their desktop. 
The microservice logs reminders in a JSON file and triggers notifications at specified times.

Requirements
------------
- Python 3.9 or higher
- Packages to Install:
  - schedule: For scheduling reminders.
  - plyer: For cross-platform desktop notifications (not fully functional on macOS).
  - pyobjus: Needed for plyer on macOS (may not work reliably for notifications).

Installation
------------
1. Clone the Repository:
   ```bash
   git clone https://github.com/troydiaz/SB-microserviceA.git
   cd SB-microserviceA

2. Set Up a Virtual Environment
    python3 - m venv venv

3. Install Required Packages
    pip install schedule plyer pyobjus

4. Run microservice
    python3 microservice.py

Testing
------------
1. Request a new reminders
    setup_test_reminder()

UML Sequence Diagram
------------
***Refer to Seth Baker's UML Sequence Design for Microservice A.pdf ***