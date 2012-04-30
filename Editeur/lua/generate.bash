#!/bin/bash

echo "Clearing old build folder..."
rm -rf ../build/*
echo "Generate LuaInterface ..."
tolua++ -H ../include/edt/LuaInterface.hpp -o ../src/edt/LuaInterface.cpp LuaInterface.pkg


#corriger le dernier ; de trop
tmp=`mktemp`
cat ../src/edt/LuaInterface.cpp | sed -e '/};$/,/#endif$/s/};/}/g' > $tmp
mv $tmp ../src/edt/LuaInterface.cpp

