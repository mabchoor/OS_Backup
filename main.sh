#!/bin/bash

# Load the configuration file
source backupd.conf
status="inactive"

# Check the command line arguments
if [ "$1" = "start" ]; then
    echo "Starting backup..."
    # Add your code to start the backup process here
    status="active"
    echo "Backup is now active"
    
elif [ "$1" = "status" ]; then
    echo "Checking backup status..."
    # Add your code to check the backup status here
    echo "Backup is $status"

   
elif [ "$1" = "stop" ]; then
    echo "Stopping backup..."
    # Add your code to stop the backup process here
    status="inactive"
    echo "Backup is now inactive"   
   
    
else
    echo "Invalid option. Usage: $0 [start start | status | stop]"
    exit 1
fi

# Check if the backup directory exists
if [ ! -d "$BACKUP_DIR" ]; then
  echo "Backup directory $BACKUP_DIR does not exist. Creating..."
  mkdir -p "$BACKUP_DIR"
fi

# Create a timestamp for the backup
TIMESTAMP=$(date +%Y%m%d%H%M%S)

# Create a log file
LOG_FILE="/var/log/backup_$TIMESTAMP.log"

# Perform the backup using rsync
rsync -avz --delete $SOURCE_DIR $BACKUP_DIR > $LOG_FILE

# Check if the rsync command was successful
if [ $? -eq 0 ]; then
  echo "Backup successful! Log file is located at $LOG_FILE"
else
  echo "Backup failed! Check log file at $LOG_FILE for more details"
fi