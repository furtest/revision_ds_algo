source_files := ${wildcard source/*.c}

compile : main.c ${source_files} 
	gcc -Wall $^ -o $@

run : compile
	./$^

clean : 
	rm -rf compile 