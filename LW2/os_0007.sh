if [ "$1" = "" ]; then
	echo "parameters not found"
else

	if ! [[ "$1" =~ ^[0-9]+$ ]]; then
		echo "not a number"; exit 1
	fi
	if ps -p $1 > /dev/null
	then
		echo -n Name:; ps -p $1 -o comm=
		echo Pid:$1
		echo -n PPid:; ps -p $1 -o ppid=
		if [ "$2" = "fd" ]; then
			FDS=$(ls -1 /proc/$1/fd)
			for i in $FDS
			do
				echo fd = $i
			done
		fi
	else
		echo pid=$1 process not found; exit
	fi
fi