#!/bin/bash

# Root Configuration
export ROOT_DIR=$(pwd)

# Compiler Configuration
export CC="gcc"
export CFLAGS="-Wall -Wextra -Werror -g -fsanitize=address -DUNITY_OUTPUT_COLOR"

# File Configuration
export SRC_DIR="${ROOT_DIR}/src"
export SRC_FILES=$(find ${SRC_DIR} -name "*.c")
export SRC_INCLUDES="-I${SRC_DIR}"

export TEST_WILDCARD="*$1*"
export TEST_DIR="${ROOT_DIR}/test"
export TEST_FILES=$(find ${TEST_DIR} -name "$TEST_WILDCARD.c")

export UNITY_DIR="${ROOT_DIR}/unity"
export UNITY_FILES=$(find ${UNITY_DIR} -name "*.c")
export UNITY_INCLUDES="-I${UNITY_DIR}"

# Run Tests
export NAME="test-runner.out"
for FILE in ${TEST_FILES};
do
    ${CC} ${CFLAGS} ${SRC_FILES} ${UNITY_FILES} ${FILE} ${SRC_INCLUDES} ${UNITY_INCLUDES} -o ${NAME}
    ./${NAME}
    rm ${NAME}
done