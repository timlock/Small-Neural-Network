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
const int n = 60000;
ifstream image;
ifstream label;
char list[n][width][height];


int main(){
    if(firstRead()) cout << "no errors" << endl;
    readData();
    return 0;
}