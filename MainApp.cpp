//
// Created by tim-l on 27.07.2021.
//
#include <iostream>
#include <fstream>
#include <string>
#include "accessingData.h"
using namespace std;


const string mnist_img = "ressources/train-images.idx3-ubyte";
const string mnist_lab = "ressources/train-labels.idx1-ubyte";
const int height = 28;
const int width = 28;
int d[width + 1][height + 1];
ifstream image;
ifstream label;


int main(){
    if(firstRead()) cout << "no errors" << endl;
    readData();
    return 0;
}