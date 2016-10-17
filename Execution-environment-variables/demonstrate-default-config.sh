#!/bin/bash

echo "clean-up before demo ..."
rm -rvf default-config-demo

echo "compile the demo ..."
./compile-default-config.sh


echo "unset env variable MY_ARG"
unset MY_ARG

echo "executing without env variable MY_ARG"
./default-config-demo


echo "setting env variable MY_ARG to 'XX-YY-ZZ'"
MY_ARG="XX-YY-ZZ"
export MY_ARG

echo "executing with env variable MY_ARG = 'XX-YY-ZZ'"
./default-config-demo

