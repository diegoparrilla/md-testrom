#!/bin/bash

# Ensure an argument is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <working_folder> all|release"
    exit 1
fi

working_folder=$1
target_firmware="target_firmware.h"

ST_WORKING_FOLDER=$working_folder stcmd make $build_type

# Create the dist directory if it doesn't exist
mkdir -p ./dist

filename="./dist/FIRMWARE.IMG"

# Copy the TESTROM.BIN file to a ROM size file for testing
ST_WORKING_FOLDER=$working_folder stcmd cp TESTROM.BIN $filename

# Size for 128Kbytes in bytes
targetsize=$((128 * 1024))

# Resize the file to 64Kbytes
ST_WORKING_FOLDER=$working_folder stcmd truncate -s $targetsize $filename

if [ $? -ne 0 ]; then
    echo "Failed to resize the file."
    exit 3
fi

echo "File has been resized."

echo "Creating the firmware.h file."
python firmware.py --input=dist/FIRMWARE.IMG --output=$target_firmware --array_name=target_firmware

cp $target_firmware ../../rp/src/include/$target_firmware
echo "Copied $target_firmware to rp/src/include/$target_firmware"

rm $target_firmware
echo "Removed $target_firmware"
