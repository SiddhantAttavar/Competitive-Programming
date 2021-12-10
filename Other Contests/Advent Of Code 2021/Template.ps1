# Run this script in powershell to change the templates
# Note remove this comment before running the command
# This will replace existing files

for ($i = 1; $i -le 25; $i++) {
	# If the folder exists, continue
	if (Test-Path -Path $PSScriptRoot\Day$i) {
		echo "Day $i files already exist. Skipping"
		continue
	}

	# Create folder
	echo "Creating Day $i files"
	mkdir $PSScriptRoot\Day$i | Out-Null

	for ($j = 1; $j -le 2; $j++) {
		# Create file
		$file = "$PSScriptRoot\Day$i\Day$i`Q$j`.py"
		$alpha = [char](96 + $j)
		New-Item -Type File -Path $file | Out-Null

		# Day i, Part 1
		echo "from aocd import get_data, submit" >> $file
		echo "data = get_data(day = $i, year = 2021).splitlines()" >> $file
		echo "" >> $file
		echo "print(res)" >> $file
		echo "#submit(res, part = '$alpha', day = $i, year = 2021)" >> $file
	}
}
