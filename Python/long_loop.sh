 #!/bin/bash
 COUNTER=5
 until [  $COUNTER -lt 0 ]; do
     echo COUNTER=$COUNTER
     let COUNTER-=1
     sleep 1
 done