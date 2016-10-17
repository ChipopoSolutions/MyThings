#! /bin/bash
echo "Your enviroment variables:"
echo "USER='${USER}'"
echo "HOME='${HOME}'"
echo "PATH='${PATH}'"
echo "DISPLAY='${DISPLAY}'"
printenv > env.list
