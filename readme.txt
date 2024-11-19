/mnt/c/Users/user/Desktop/TTECH/my_project$ cmake --build build
/mnt/c/Users/user/Desktop/TTECH/my_project/build$ ctest
/mnt/c/Users/user/Desktop/TTECH/my_project/build$ lcov --capture --directory . --output-file coverage.info
/mnt/c/Users/user/Desktop/TTECH/my_project/build$ genhtml coverage.info --output-directory out