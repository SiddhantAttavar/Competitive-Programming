#!/bin/sh
year=2023
mkdir -p $year
for day in $(seq 1 25); do
	mkdir -p "$year/Day$day"
	echo "Created $year/Day$day/Day${day}Q1.py"
	sed "s/\$year/$year/g;s/\$day/$day/g;s/\$part/'a'/g" AOCTemplate.py > "$year/Day$day/Day${day}Q1.py"
	sed "s/\$year/$year/g;s/\$day/$day/g;s/\$part/'b'/g" AOCTemplate.py > "$year/Day$day/Day${day}Q2.py"
done
