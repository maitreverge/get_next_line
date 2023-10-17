## Ordre de compilation = Flag 0 / Flag negatif / Flag 1 / flag 42 / flag 100000

cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=0 main1_1.c ../get_next_line.c ../get_next_line_utils.c -o test1 && valgrind ./test1

sleep 1

#################

cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=-42 main1_2.c ../get_next_line.c ../get_next_line_utils.c -o test2 && valgrind ./test2

sleep 1

#################

cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=1 main1_3.c ../get_next_line.c ../get_next_line_utils.c -o test3 && valgrind ./test3

sleep 1

#################

cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 main1_4.c ../get_next_line.c ../get_next_line_utils.c -o test4 && valgrind ./test4

sleep 1

#################

cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=100000 main1_5.c ../get_next_line.c ../get_next_line_utils.c -o test5 && valgrind ./test5

sleep 1

#################

cc -Wall -Wextra -Werror -g main1_6.c ../get_next_line.c ../get_next_line_utils.c -o test6 && valgrind ./test6

sleep 1

#################################################### test2

rm test1
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=0 main2_1.c ../get_next_line.c ../get_next_line_utils.c -o test1 && valgrind ./test1

sleep 1

#################
rm test2

cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=-42 main2_2.c ../get_next_line.c ../get_next_line_utils.c -o test2 && valgrind ./test2

sleep 1

#################
rm test3
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=1 main2_3.c ../get_next_line.c ../get_next_line_utils.c -o test3 && valgrind ./test3

sleep 1

#################
rm test4
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 main2_4.c ../get_next_line.c ../get_next_line_utils.c -o test4 && valgrind ./test4

sleep 1

#################
rm test5
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=100000 main2_5.c ../get_next_line.c ../get_next_line_utils.c -o test5 && valgrind ./test5

sleep 1

#################
rm test6

cc -Wall -Wextra -Werror -g main2_6.c ../get_next_line.c ../get_next_line_utils.c -o test6 && valgrind ./test6

sleep 1




