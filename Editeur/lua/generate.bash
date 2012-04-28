#!/bin/bash

echo "Clearing old build folder..."
rm -rf ../build/*
echo "Generate LuaInterface ..."
tolua++ -H ../include/edt/LuaInterface.hpp -o ../src/edt/LuaInterface.cpp LuaInterface.pkg


#corriger ;
