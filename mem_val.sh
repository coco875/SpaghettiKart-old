rm valgrind.report
valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all ./build/Spaghettify 2> valgrind.report