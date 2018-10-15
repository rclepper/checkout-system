set -x
#
# Download googletest and install
#
rm -r googletest
git clone https://github.com/google/googletest.git
cd make
make clean
make gtest_main.a
