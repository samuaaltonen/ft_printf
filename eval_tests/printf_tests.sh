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
	make comp -C ../
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
gcc -Wall -Wextra -Werror -g -o $TESTMAIN.o -I ../includes/ -c -x c $TESTMAIN.test
gcc -g -o tests_printf $TESTMAIN.o -I ../includes/ -L ../ -lftprintf

if [ $1 -eq 1 ]; then

printf "\n\033[0;35m======================= 01 STRINGS, WIDTH AND ALIGNMENT =======================\033[0m\n"
printf "Output of libc printf will be cyan and ft_printf purple.\n\n"

./tests_printf

fi

if [ $1 -eq 2 ]; then

printf "\n\033[0;35m======================= 02 SIMPLE DATA TYPES AND FLAGS =======================\033[0m\n"
printf "Output of libc printf will be cyan and ft_printf purple.\n\n"

./tests_printf

fi

if [ $1 -eq 3 ]; then

printf "\n\033[0;35m======================= 03 ADVANCED DATA TYPES =======================\033[0m\n"
printf "Output of libc printf will be cyan and ft_printf purple.\n\n"

./tests_printf

fi

if [ $1 -eq 4 ]; then

printf "\n\033[0;35m======================= 04 OTHER STUFF =======================\033[0m\n"
printf "Output of libc printf will be cyan and ft_printf purple.\n\n"

./tests_printf

fi

if [ $1 -eq 5 ]; then

printf "\n\033[0;35m======================= 05 NUMBERS WITH WIDTH AND PRECISION =======================\033[0m\n"
printf "Output of libc printf will be cyan and ft_printf purple.\n\n"

./tests_printf

fi

if [ $1 -eq 6 ]; then

printf "\n\033[0;35m======================= 06 OTHER FLAGS =======================\033[0m\n"
printf "Output of libc printf will be cyan and ft_printf purple.\n\n"

./tests_printf

fi

if [ $1 -eq 7 ]; then

printf "\n\033[0;35m======================== 07 MEMORY USAGE ========================\033[0m\n"
printf "Calling ft_printf in infinite loop for 20 seconds. Monitor memory \nusage with \033[0;36mleaks tests_printf\033[0m and \033[0;36mtop | grep tests_printf\033[0m\n\n"

./tests_printf

fi

if [ $1 -eq 8 ]; then

printf "\n\033[0;35m======================== 08 FUN TESTS ========================\033[0m\n"

./tests_printf

fi

if [ $1 -eq 9 ]; then

printf "\n\033[0;35m======================== 09 TEMP ========================\033[0m\n"

./tests_printf

fi
