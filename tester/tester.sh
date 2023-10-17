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

#################################################### test3

rm test1
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=0 main3_1.c ../get_next_line.c ../get_next_line_utils.c -o test1 && valgrind ./test1

sleep 1

#################
rm test2

cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=-42 main3_2.c ../get_next_line.c ../get_next_line_utils.c -o test2 && valgrind ./test2

sleep 1

#################
rm test3
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=1 main3_3.c ../get_next_line.c ../get_next_line_utils.c -o test3 && valgrind ./test3

sleep 1

#################
rm test4
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 main3_4.c ../get_next_line.c ../get_next_line_utils.c -o test4 && valgrind ./test4

sleep 1

#################
rm test5
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=100000 main3_5.c ../get_next_line.c ../get_next_line_utils.c -o test5 && valgrind ./test5

sleep 1

#################
rm test6

cc -Wall -Wextra -Werror -g main3_6.c ../get_next_line.c ../get_next_line_utils.c -o test6 && valgrind ./test6

sleep 1

#################################################### test4

rm test1
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=0 main4_1.c ../get_next_line.c ../get_next_line_utils.c -o test1 && valgrind ./test1

sleep 1

#################
rm test2

cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=-42 main4_2.c ../get_next_line.c ../get_next_line_utils.c -o test2 && valgrind ./test2

sleep 1

#################
rm test3
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=1 main4_3.c ../get_next_line.c ../get_next_line_utils.c -o test3 && valgrind ./test3

sleep 1

#################
rm test4
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 main4_4.c ../get_next_line.c ../get_next_line_utils.c -o test4 && valgrind ./test4

sleep 1

#################
rm test5
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=100000 main4_5.c ../get_next_line.c ../get_next_line_utils.c -o test5 && valgrind ./test5

sleep 1

#################
rm test6

cc -Wall -Wextra -Werror -g main4_6.c ../get_next_line.c ../get_next_line_utils.c -o test6 && valgrind ./test6

sleep 1


#################################################### test5

rm test1
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=0 main5_1.c ../get_next_line.c ../get_next_line_utils.c -o test1 && valgrind ./test1

sleep 1

#################
rm test2

cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=-42 main5_2.c ../get_next_line.c ../get_next_line_utils.c -o test2 && valgrind ./test2

sleep 1

#################
rm test3
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=1 main5_3.c ../get_next_line.c ../get_next_line_utils.c -o test3 && valgrind ./test3

sleep 1

#################
rm test4
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 main5_4.c ../get_next_line.c ../get_next_line_utils.c -o test4 && valgrind ./test4

sleep 1

#################
rm test5
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=100000 main5_5.c ../get_next_line.c ../get_next_line_utils.c -o test5 && valgrind ./test5

sleep 1

#################
rm test6

cc -Wall -Wextra -Werror -g main5_6.c ../get_next_line.c ../get_next_line_utils.c -o test6 && valgrind ./test6

sleep 1

#################################################### test6

rm test1
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=0 main6_1.c ../get_next_line.c ../get_next_line_utils.c -o test1 && valgrind ./test1

sleep 1

#################
rm test2

cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=-42 main6_2.c ../get_next_line.c ../get_next_line_utils.c -o test2 && valgrind ./test2

sleep 1

#################
rm test3
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=1 main6_3.c ../get_next_line.c ../get_next_line_utils.c -o test3 && valgrind ./test3

sleep 1

#################
rm test4
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 main6_4.c ../get_next_line.c ../get_next_line_utils.c -o test4 && valgrind ./test4

sleep 1

#################
rm test5
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=100000 main6_5.c ../get_next_line.c ../get_next_line_utils.c -o test5 && valgrind ./test5

sleep 1

#################
rm test6

cc -Wall -Wextra -Werror -g main6_6.c ../get_next_line.c ../get_next_line_utils.c -o test6 && valgrind ./test6

sleep 1

#################################################### test7

rm test1
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=0 main7_1.c ../get_next_line.c ../get_next_line_utils.c -o test1 && valgrind ./test1

sleep 1

#################
rm test2

cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=-42 main7_2.c ../get_next_line.c ../get_next_line_utils.c -o test2 && valgrind ./test2

sleep 1

#################
rm test3
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=1 main7_3.c ../get_next_line.c ../get_next_line_utils.c -o test3 && valgrind ./test3

sleep 1

#################
rm test4
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 main7_4.c ../get_next_line.c ../get_next_line_utils.c -o test4 && valgrind ./test4

sleep 1

#################
rm test5
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=100000 main7_5.c ../get_next_line.c ../get_next_line_utils.c -o test5 && valgrind ./test5

sleep 1

#################
rm test6

cc -Wall -Wextra -Werror -g main7_6.c ../get_next_line.c ../get_next_line_utils.c -o test6 && valgrind ./test6

sleep 1

#################################################### test8

rm test1
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=0 main8_1.c ../get_next_line.c ../get_next_line_utils.c -o test1 && valgrind ./test1

sleep 1

#################
rm test2

cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=-42 main8_2.c ../get_next_line.c ../get_next_line_utils.c -o test2 && valgrind ./test2

sleep 1

#################
rm test3
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=1 main8_3.c ../get_next_line.c ../get_next_line_utils.c -o test3 && valgrind ./test3

sleep 1

#################
rm test4
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=42 main8_4.c ../get_next_line.c ../get_next_line_utils.c -o test4 && valgrind ./test4

sleep 1

#################
rm test5
cc -Wall -Wextra -Werror -g -D BUFFER_SIZE=100000 main8_5.c ../get_next_line.c ../get_next_line_utils.c -o test5 && valgrind ./test5

sleep 1

#################
rm test6

cc -Wall -Wextra -Werror -g main8_6.c ../get_next_line.c ../get_next_line_utils.c -o test6 && valgrind ./test6

sleep 1

########################### 		END SCRIPT		#################################################
