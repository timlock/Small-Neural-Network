//
// Created by tim-l on 27.07.2021.
//

#include "accessingData.h"

extern int height;
extern int width;
extern int numerOfPictures;
extern ifstream image;
extern ifstream label;
extern char ***list;

extern const string mnist_img = "C:/Users/tim-l/Documents/kleinesProjekt/Small-Neural-Network/resources/train-images.idx3-ubyte";
extern const string mnist_lab = "C:/Users/tim-l/Documents/kleinesProjekt/Small-Neural-Network/resources/train-labels.idx1-ubyte";



/*
 * Reads the metadata from the image and label set and prints the results afterwards
 */
void readingMetaData() {
    image.open(mnist_img, ios::in | ios::binary);
    if(!image.good()) cerr << "Image file not found" << endl;
    int bytes[6];
    for(int i = 0; i < 4; i++){
        image.read(reinterpret_cast<char *>(&bytes[i]), 4);
    }
    int magic_number = _byteswap_ulong(bytes[0]);
    int num_images = _byteswap_ulong(bytes[1]);
    int num_rows = _byteswap_ulong(bytes[2]);
    int num_cols = _byteswap_ulong(bytes[3]);
    cout << "Filepath: " << mnist_img << endl << "Magic number: " << magic_number << endl << "Number of images: " << num_images << endl << "Number of rows: " << num_rows << endl <<"Number of columns " << num_cols << endl;

    label.open(mnist_lab, ios::in | ios::binary);
    if(!label.good()) cerr << "Label ile not found" << endl;
    label.read(reinterpret_cast<char *>(&bytes[4]), 4);
    label.read(reinterpret_cast<char *>(&bytes[5]), 4);
    int lab_magic_number = magic_number = _byteswap_ulong(bytes[4]);
    int num_labels = magic_number = _byteswap_ulong(bytes[5]);
    cout << "Filepath: " << mnist_lab << endl << "Magic number: " << lab_magic_number << endl << "Number of images: " << num_labels << endl;
}

void readData() {

}