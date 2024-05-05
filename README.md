# Task Manager for Linux

This is a simple task manager program written in C for Linux systems. It allows users to view running processes and terminate them if needed.

## Features

- View a list of running processes with their process IDs (PIDs) and names.
- Terminate a process by entering its PID.

## Usage

1. Compile the program using a C compiler (e.g., gcc):  
   ```bash
   gcc task_manager.c -o task_manager
   ```

2. Run the compiled executable:  
   ```bash
   ./task_manager
   ```

3. How to use:
  -  After running the program, you'll see a list of running processes. The list will automatically update every 2 seconds. While the list is being displayed, you can perform the following actions:
  -  Kill a Process: To terminate a process, Press enter then enter its PID when prompted.
  -  Exit: To quit the task manager, enter 2 and press Enter.
