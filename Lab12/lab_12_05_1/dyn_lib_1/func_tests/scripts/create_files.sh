n_pos=$1
n_neg=$2
n=1

while [[ $n -le $n_pos ]]
do
  if [[ $n -lt 10 ]];
  then
    num="0$n"
  else
    num="$n"
  fi;
  touch ./func_tests/data/pos_"$num"_args.txt
  touch ./func_tests/data/pos_"$num"_in.txt
  touch ./func_tests/data/pos_"$num"_out.txt
  n=$((n + 1))
done;

n=1

while [[ $n -le $n_neg ]]
do
  if [[ $n -lt 10 ]];
  then
    num="0$n"
  else
    num="$n"
  fi;
  touch ./func_tests/data/neg_"$num"_args.txt
  touch ./func_tests/data/neg_"$num"_in.txt
  touch ./func_tests/data/neg_"$num"_out.txt
  n=$((n + 1))
done;
