# Run this command in powershell to change the templates
# for ($i=1; $i -le 25; $i++) {
# 	mkdir -p Day$i
# 	cp .\Template\Template.py .\Day$i`\Day$i`Q1.py
# 	cp .\Template\Template.py .\Day$i`\Day$i`Q2.py
# }
# Note remove this comment before running the command
# This will replace existing files
inputFile = inputFile = open('input.txt', 'r')
data = inputFile.read().splitlines()

inputFile.close()
