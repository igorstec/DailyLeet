#!/bin/bash

# LC_ALL=C wymusza standardowe (angielskie) formatowanie daty
DATE=$(date +"%-d %B")

echo "Ustalona data dla commita: Day $DATE"

git add *
git commit -m "Day $DATE"
git push