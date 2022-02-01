TESTMAIN="tests_main_01"

make re -C ../
gcc -Wall -Wextra -Werror -g -o $TESTMAIN -I ../ -I ../libft/includes -L ../ -L ../libft -lftprintf -lft -x c $TESTMAIN.test

./$TESTMAIN