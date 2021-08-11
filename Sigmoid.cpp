//
// Created by tim-l on 11.08.2021.
//

#include "Sigmoid.h"
/*
 * Squishes any number in the space between 0 and 1
 */
float sigmoid(uint8_t number){
    float tmp = number;
    return 0.5f * (1 + tanh(tmp / 2));
}
float sigmoid(float number){
    return 0.5f * (1 + tanh(number / 2));
}
