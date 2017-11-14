#1/bin/bash
# Claire Veasey cev4gx 3/15/17 averagetime.sh
# read in dictionary filename
read -p "Enter the dictionary filename: " dictionary
#read in grid filename
read -p "Enter the grid filename: " grid
# first run with inputted dictionary and grid
running_time1=`./a.out ${dictionary} ${grid} | tail -1`
# second run
running_time2=`./a.out ${dictionary} ${grid} | tail -1`
# third run
running_time3=`./a.out ${dictionary} ${grid} | tail -1`
# fourth run
running_time4=`./a.out ${dictionary} ${grid} | tail -1`
# fifth (and final) run
running_time5=`./a.out ${dictionary} ${grid} | tail -1`
# arithmetic expansion for average and echo to command line
echo $(( (${running_time1} + ${running_time2} + ${running_time3} + ${running_time4} + ${running_time5}) / 5 ))

