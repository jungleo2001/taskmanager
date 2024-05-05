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

3. Choose the desired option from the menu:
   - Display Processes: Shows a list of running processes.
   - Kill a Process: Allows you to terminate a process by entering its PID.
   - Exit: Quits the task manager.
