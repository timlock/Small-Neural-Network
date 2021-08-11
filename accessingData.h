//
// Created by tim-l on 27.07.2021.
//
#include <iostream>
#include <fstream>
#include <string>
#include <stdint.h>
#include <stdio.h>
#include <cmath>
#include <vector>
#include "Sigmoid.h"

using namespace std;

#ifndef SMALL_NEURAL_NETWORK_ACCESSINGDATA_H
#define SMALL_NEURAL_NETWORK_ACCESSINGDATA_H

int convert_to_little_endian(int big_endian);
void readingMetaData();
void readData();


#endif //SMALL_NEURAL_NETWORK_ACCESSINGDATA_H
