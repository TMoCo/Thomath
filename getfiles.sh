SOURCE_FILE='src.txt'
INCLUDE_FILE='include.txt'

SOURCE=$(
    ls ./src/**/*.cpp
    ls ./src/**/*.c
)
INCLUDE=$(
    ls ./include/**/*.hpp
    ls ./include/**/*.h
)

# write to files
touch $SOURCE_FILE && (echo ${SOURCE//'.\/'/''} >$SOURCE_FILE)
touch $INCLUDE_FILE && (echo ${INCLUDE//'.\/'/''} >$INCLUDE_FILE)
