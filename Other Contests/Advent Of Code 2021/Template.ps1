# Run this script in powershell to change the templates
# Note remove this comment before running the command
# This will replace existing files

$template = @'
from aocd import get_data, submit
data = get_data(day = ${day}, year = ${year}).splitlines()

print(res)
# submit(res, part = '${part}', day = ${day}, year = ${year})
'@

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
		$day = "$i"
		$year = "$PSScriptRoot".Split("/")[-1].Split(" ")[-1]
		$part = [char](96 + $j)
		New-Item -Type File -Path $file | Out-Null

		# Day i, Part j
		$FileContent = $ExecutionContext.InvokeCommand.ExpandString($template)
		$Utf8NoBomEncoding = New-Object System.Text.UTF8Encoding $False
		[System.IO.File]::WriteAllLines($file, $FileContent, $Utf8NoBomEncoding)
	}
}
