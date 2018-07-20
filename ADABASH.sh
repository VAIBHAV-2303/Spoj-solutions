    declare -A arr
    declare -a vis
    declare -a adj
    read n m
    n=$(($n-1))
    function dfs(){
    	if [ ${vis[$1]} -eq 1 ]
    	then
    		return
    	fi
    	vis[$1]=1
    	cur=$((${adj[$1]}-1))
    	for j in `seq 0 $cur`
    	do
    		if [ ${arr[$1, $j]} -ne $2 ]
    		then
    			dfs ${arr[$1, $j]} $1
    		fi 
    	done
    }
    for i in `seq 0 $n` 
    do
    	adj[$i]=0
    	vis[$i]=0
    done
    for i in `seq 1 $m`
    do
    	read u v
    	arr[$u, ${adj[$u]}]=$v
    	adj[$u]=$((${adj[$u]}+1))
    	arr[$v, ${adj[$v]}]=$u
    	adj[$v]=$((${adj[$v]}+1))
    done
    ans=0
    for i in `seq 0 $n`
    do
    	if [ ${vis[$i]} -eq 0 ]
    	then
    		ans=$(($ans+1))
    		dfs $i -1
    	fi 
    done
    printf "%d\n" "$ans" 
