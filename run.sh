#!/bin/bash

root -l -n -q 'analyzeTrees.cpp("thesis_1gev.edm4eic.root")'
root -l -n -q 'analyzeTrees.cpp("thesis_3gev.edm4eic.root")'
root -l -n -q 'analyzeTrees.cpp("thesis_5gev.edm4eic.root")'
root -l -n -q 'analyzeTrees.cpp("thesis_10gev.edm4eic.root")'

root -l -n -q plotHists.cpp

