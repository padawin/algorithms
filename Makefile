all:
	gcc -Wall -g sort/quicksort.c -o quicksort
	gcc -Wall -g sort/insertsort.c -o insertsort
	gcc -Wall -g sort/selectsort.c -o selectsort
