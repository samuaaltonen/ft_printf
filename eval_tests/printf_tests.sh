TESTMAIN="tests_main_01"

make re -C ../
gcc -Wall -Wextra -Werror -o tests -I ../ -I ../libft/includes -L ../ -L ../libft -lftprintf -lft -x c $TESTMAIN.test

./tests