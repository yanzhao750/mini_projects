"""
Textfile Bulk Creator
Yanzhao Yang

Loops through a CSV file, reads specific values, then finds and edits corresponding strings in a text file. Useful for the bulk creation of unit-specific router config files, etc.
Adapted from code written for a job, with the variables and fields changed (but is functionally identical).
"""

import sys
import csv
import io

# Ensure correct usage
if len(sys.argv) != 4:
    sys.exit("Usage: py textfileBulkCreator.py fileTemplate1 fileTemplate2 csvFile")

# Read unitData into memory from file
unitData = []
with open(sys.argv[1]) as csvFile:
    # Create csv.DictReader reader
    reader = csv.DictReader(ipFile)
    for unit in reader:
        unitData.append(unit)

# Loop through all units in unitData
for i in range(len(unitData)):
    unit = unitData[i]

    # Open fileTemplate1
    with open(sys.argv[2], 'r') as fileTemplate1:
        # Read every line
        fileTemplate1Temp = fileTemplate1.read()

        # Replace unitID
        unitID = unit["Unit ID Column"]
        fileTemplate1Temp = fileTemplate1Temp.replace("xxxx", unitID)

        # Replace IP
        ip = unit["Unit IP Column"].lstrip("10.128.")
        fileTemplate1Temp = fileTemplate1Temp.replace("yy.zz", ip)

        # Replace S/N
        unitNumber = unit["Unit Number Column"]
        snL = unitNumber[0:2]
        snR = unitNumber[2:]
        sn = f"{snL}.{snR}"
        fileTemplate1Temp = fileTemplate1Temp.replace("vv.vv", sn)

    # Write fileTemplate1Temp to fileTemplate1Out
    with open(f"{unitNumber}_router.txt", "w") as fileTemplate1Out:
        fileTemplate1Out.write(fileTemplate1Temp)

    # Open fileTemplate2
    with open(sys.argv[3], 'r') as fileTemplate2:
        # Read every line
        fileTemplate2Temp = fileTemplate2.read()

        # Replace unitID
        unitID = unit["Unit ID Column"]
        fileTemplate2Temp = fileTemplate2Temp.replace("xxxx", unitID)

        # Replace IP
        ip = unit["Unit IP Column"].lstrip("10.128.")
        fileTemplate2Temp = fileTemplate2Temp.replace("yy.zz", ip)

    # Write fileTemplate2Temp to fileTemplate2Out
    with open(f"{unitNumber}_wifi.txt", "w") as fileTemplate2Out:
        fileTemplate2Out.write(fileTemplate2Temp)
