if [ $1 = 'clean' ]; then
	/bin/rm	-f *.o
	/bin/rm -f tests tests_memory
	exit 1
fi

if [ $1 = 'make' ]; then
	make re -C ../
	exit 1
fi

if [ $1 = 'comp' ]; then
	make comp_dev -C ../
	exit 1
fi

if [ $1 = 'all' ]; then
	./printf_tests.sh 1
	./printf_tests.sh 2
	./printf_tests.sh 3
	./printf_tests.sh 4
	./printf_tests.sh 5
	./printf_tests.sh 6
	./printf_tests.sh 7
	./printf_tests.sh 8
	exit 1
fi

TESTMAIN="tests_main_0$1"
gcc -Wall -Wextra -Werror -Wformat=0 -g -I ../includes/ -c -x c $TESTMAIN.test test_utils.test
gcc -g -o tests_printf $TESTMAIN.o test_utils.o -I ../includes/ -L ../ -lftprintf

if [ $1 -eq 1 ]; then

printf "\n\033[0;35m======================= 01 STRINGS, WIDTH AND ALIGNMENT =======================\033[0m\n\n"

./tests_printf

fi

if [ $1 -eq 2 ]; then

printf "\n\033[0;35m======================= 02 SIMPLE DATA TYPES AND LENGTHS =======================\033[0m\n\n"

./tests_printf

fi

if [ $1 -eq 3 ]; then

printf "\n\033[0;35m======================= 03 ADVANCED DATA TYPES =======================\033[0m\n\n"

./tests_printf

fi

if [ $1 -eq 4 ]; then

printf "\n\033[0;35m======================= 04 POINTERS, CHAR WITH WIDTH AND % =======================\033[0m\n\n"

./tests_printf

fi

if [ $1 -eq 5 ]; then

printf "\n\033[0;35m======================= 05 NUMBERS WITH WIDTH AND PRECISION =======================\033[0m\n\n"

./tests_printf

fi

if [ $1 -eq 6 ]; then

printf "\n\033[0;35m======================= 06 OTHER FLAGS =======================\033[0m\n\n"

./tests_printf

fi

if [ $1 -eq 7 ]; then

printf "\n\033[0;35m======================== 07 MEMORY USAGE ========================\033[0m\n\n"

./tests_printf

fi

if [ $1 -eq 8 ]; then

printf "\n\033[0;35m======================== 08 FUN TESTS ========================\033[0m\n\n"

./tests_printf

fi

if [ $1 -eq 9 ]; then

printf "\n\033[0;35m======================== 09 BONUS ========================\033[0m\n\n"

./tests_printf

fi
