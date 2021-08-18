//
// Created by tim-l on 27.07.2021.
//

#include "accessingData.h"

extern int height;
extern int width;
extern int number_of_pictures;
extern ifstream image;
extern ifstream label;
extern float *data;

extern const string mnist_img = "C:/Users/tim-l/Documents/kleinesProjekt/Small-Neural-Network/resources/train-images.idx3-ubyte";
extern const string mnist_lab = "C:/Users/tim-l/Documents/kleinesProjekt/Small-Neural-Network/resources/train-labels.idx1-ubyte";


/*
 * Reads the metadata from the image and label sets and prints the metadata afterwards
 */
void readingMetaData() {
    image.open(mnist_img, ios::in | ios::binary);
    if (!image.good()) cerr << "Image file not found" << endl;
    int bytes[6];
    for (int i = 0; i < 4; i++) {
        image.read(reinterpret_cast<char *>(&bytes[i]), 4);
    }
    int magic_number = _byteswap_ulong(bytes[0]);
    number_of_pictures = _byteswap_ulong(bytes[1]);
    height = _byteswap_ulong(bytes[2]);
    width = _byteswap_ulong(bytes[3]);
    cout << "Filepath: " << mnist_img << endl << "Magic number: " << magic_number << endl << "Number of images: "
         << number_of_pictures << endl << "Number of rows: " << height << endl << "Number of columns " << width << endl;

    label.open(mnist_lab, ios::in | ios::binary);
    if (!label.good()) cerr << "Label ile not found" << endl;
    label.read(reinterpret_cast<char *>(&bytes[4]), 4);
    label.read(reinterpret_cast<char *>(&bytes[5]), 4);
    int lab_magic_number =  _byteswap_ulong(bytes[4]);
    int num_labels = _byteswap_ulong(bytes[5]);
    cout << "Filepath: " << mnist_lab << endl << "Magic number: " << lab_magic_number << endl << "Number of images: "
         << num_labels << endl;
}

void readData() {
    data = new float[height * width + 1];//stores the data temporarily
    uint8_t byte;
    label.read(reinterpret_cast<char *>(&byte), sizeof(byte));
    data[0] = byte;
    for (int i = 1; i < height * width + 1; i++) {//writes the data in the temporal variable
        image.read(reinterpret_cast<char *>(&byte), sizeof(byte));
        data[i] = sigmoid(byte);
    }
    // prints out the current image and label
//    cout << data[0] - '\0' << endl;
//    for (int j = 1; j < height*width + 1; ++j) {
//        cout << data[j] << " ";
//        if(j%28==0) cout << endl;
//    }

}

