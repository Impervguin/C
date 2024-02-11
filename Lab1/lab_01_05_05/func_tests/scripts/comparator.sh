#!/bin/bash


function find_nums {
   while read -r line; do
       for str in $line; do
           if [[ "$str" =~ $3 ]]; then
               echo "$str" >> "$2"
           fi
       done
   done < "$1"
}


n=0
re_s="^[-]?[0-9]+$"
verbose=""
while [[ "$n" -lt 3 ]] && [[ -n $1 ]]; do
    if [[ $1 == "-v" ]]; then 
    	verbose=1
    else 
    	if [[ -z $file1 ]]; then
    	    file1=$1
    	else 
    	    file2=$1
    	fi
    fi
    shift
    n=$((n + 1))
done

if [[ -z $file1 ]] || [[ -z $file2 ]]; then
    if [[ -n $verbose ]]; then
        echo "Incorrect input"
    fi
    exit 2
fi

if [[ ! -f $file1 ]] || [[ ! -f $file2 ]]; then
    if [[ -n $verbose ]]; then
        echo "One of files is not a file or not exists"
    fi
    exit 3
fi

if [[ ! -r $file1 ]] || [[ ! -r $file2 ]]; then
    if [[ -n $verbose ]]; then
        echo "One of files are not available for reading"
    fi
    exit 4
fi

if [[ -n $verbose ]]; then
    echo "Correct input"
fi

nums_file1=$(mktemp)
nums_file2=$(mktemp)

find_nums "$file1" "$nums_file1" "$re_s"
find_nums "$file2" "$nums_file2" "$re_s"

exec 3<"$nums_file1"
exec 4<"$nums_file2"

end_f1=1
end_f2=1

while [[ $end_f1 -gt 0 ]] && [[ $end_f2 -gt 0 ]]; do
    if ! read -r num1 <&3; then
        end_f1=0
    fi
    if ! read -r num2 <&4; then
        end_f2=0
    fi
    if [[ -n $verbose ]]; then
        echo "Number from file 1: ""$num1"
        echo "Number from file 2: ""$num2"
    fi 
    if [[ "$num1" != "$num2" ]]; then
        break
    fi   
done

if [[ $end_f2 -eq 0 ]] && [[ $end_f1 -eq 0 ]]; then
    if [[ -n $verbose ]]; then
        echo "Files have the same content"
    fi
  exit 0
else
    if [[ -n $verbose ]]; then
        echo "Files does not have the same content"
    fi
  exit 1
fi


