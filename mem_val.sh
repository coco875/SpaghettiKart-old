rm valgrind.report
valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --suppressions=valgrind_ignore ./build/Spaghettify 2> valgrind.report