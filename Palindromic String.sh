#!/bin/bash
 read s
 echo $s > temp
 rvs=`rev temp`
 #echo $rvs
 
 if [ $s = $rvs ]
 then
  echo "YES"
 else
  echo "NO"
  fi
 
 
