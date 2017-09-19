for filename in ./maps/*.map; do
	echo "$filename"
    valgrind --leak-check=full ./lem_in < "$filename" 2>&1 | grep -e "definitely lost" -e "indirectly lost"
done
