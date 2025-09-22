# 🐧 Linux Bash Commands Cheat Sheet

A quick reference for essential Linux commands, loops, conditionals, and text processing — useful for Operating Systems practical exams.

---

## 1. Basic Commands

```bash
echo "Hello World"        # print text
ls -l                     # list files (long format)
pwd                       # print working directory
cd /home/user             # change directory
clear                     # clear terminal

touch file.txt            # create empty file
cat file.txt              # display file contents
less file.txt             # view file with scrolling
head -n 5 file.txt        # first 5 lines
tail -n 10 file.txt       # last 10 lines
cp file.txt backup.txt    # copy file
mv old.txt new.txt        # rename/move file
rm file.txt               # remove file
mkdir mydir               # create directory
rmdir mydir               # remove empty directory

read name
echo "Hello $name"        # take input from user

echo "data" > file.txt    # redirect output
echo "append" >> file.txt # append to file
ls -l | grep ".txt"       # pipe: list only .txt files

[ -e file.txt ] && echo "File exists"
[ -f file.txt ] && echo "Regular file"
[ -d mydir ] && echo "Directory exists"
[ -r file.txt ] && echo "Readable"
[ -w file.txt ] && echo "Writable"
[ -x script.sh ] && echo "Executable"

[ -e file.txt ] && echo "File exists"
[ -f file.txt ] && echo "Regular file"
[ -d mydir ] && echo "Directory exists"
[ -r file.txt ] && echo "Readable"
[ -w file.txt ] && echo "Writable"
[ -x script.sh ] && echo "Executable"

a=10
b=3

echo $((a+b))   # 13
echo $((a-b))   # 7
echo $((a*b))   # 30
echo $((a/b))   # 3
echo $((a%b))   # 1

# Using expr
expr 5 + 2
expr 10 \* 3

if [ $a -gt $b ]; then
  echo "$a is greater"
fi

if [ "$name" = "Alice" ]; then
  echo "Hello Alice"
fi

for i in 1 2 3 4 5
do
  echo "Number: $i"
done

count=1
while [ $count -le 5 ]
do
  echo "Count: $count"
  count=$((count+1))
done

n=1
until [ $n -gt 5 ]
do
  echo "n = $n"
  n=$((n+1))
done

if [ $a -gt $b ]; then
  echo "a > b"
elif [ $a -eq $b ]; then
  echo "a = b"
else
  echo "a < b"
fi

grep "error" logfile.txt     # search "error"
grep -i "linux" file.txt     # case-insensitive
grep -n "main" file.c        # show line numbers
grep -r "TODO" ./src         # recursive search

sed 's/foo/bar/' file.txt     # replace first foo → bar
sed 's/foo/bar/g' file.txt    # replace all foo → bar
sed -n '2,5p' file.txt        # print lines 2–5
sed '/pattern/d' file.txt     # delete lines with pattern

whoami        # current user
date          # system date/time
cal           # calendar
wc -l file    # count lines
sort file.txt # sort lines
uniq file.txt # remove duplicates
chmod +x s.sh # make script executable
man ls        # manual for ls

# factorial
#!/bin/bash
read -p "Enter number: " n
fact=1
for ((i=1; i<=n; i++))
do
  fact=$((fact*i))
done
echo "Factorial of $n = $fact"

#fibonacci
#!/bin/bash
read -p "Enter terms: " n
a=0
b=1
echo "Fibonacci sequence:"
for ((i=0; i<n; i++))
do
  echo -n "$a "
  fn=$((a+b))
  a=$b
  b=$fn
done
echo

#palindrome
#!/bin/bash
read -p "Enter string: " str
rev=$(echo "$str" | rev)
if [ "$str" = "$rev" ]; then
  echo "$str is a palindrome"
else
  echo "$str is not a palindrome"
fi

#file exists?
#!/bin/bash
read -p "Enter filename: " fname
if [ -e "$fname" ]; then
  echo "File $fname exists."
else
  echo "File $fname does not exist."
fi
