#!/bin/bash

# Loop through all files in the current directory
for file in *; do
    # Check if it's a regular file
    if [ -f "$file" ]; then
        # Separate the file extension
        extension="${file##*.}"
        filename="${file%.*}"

        # Replace first dot with underscore and remove other spaces
        new_name="${filename/./_}"
        new_name="${new_name// /}.${extension}"

        # Rename the file
        mv "$file" "$new_name"
        # echo "Renamed: $file -> $new_name"
    fi
done