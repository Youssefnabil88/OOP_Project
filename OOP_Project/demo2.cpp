/* FCAI   OOP Programming   2023 - Assignment 1
 Program Name:				OOP_PROJECT.cpp
 Last Modification Date:	xx/xx/xxxx
 Author1: and ID and Group:	Abdelrahman Hossam Abdelrahman Farag 20221095
 Author2: and ID and Group:	Youssef Nabil Ismail waer  20221205
 ِAuther3: Mohamed Ahmed Abdelsamad Sayed
 Teaching Assistant:		xxxxx xxxxx
 Purpose: Make filters for gray images
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
#include "bmplib.h"

using namespace std;
unsigned char image[SIZE][SIZE][3];
unsigned char image1[SIZE][SIZE][3];
unsigned char image2[SIZE][SIZE][3];


void loadImage();
void enlarge() ;
void detected_edges();
void Darken_Lighten();
void rotate();
void Blur();
void merge();
void flip();
void black_white();
void inverse();
void saveImage();
void Shrink();
void mirror();
void crop();
void skew_right();
void skew_up();

int main() {
    int  q = 1;
    while(q){
        char choice;
        cout << "Image Processing Menu:" << endl;
        cout << "1 - Black & White Filter" << endl;
        cout << "2 - Invert Filter" << endl;
        cout << "3 - Merge Filter" << endl;
        cout << "4 - Flip Image" << endl;
        cout << "5 - Rotate Image" << endl;
        cout << "6 - Darken and Lighten Image" << endl;
        cout << "7 - Detect Image Edges"<<endl;
        cout << "8 - Enlarge Image"<<endl;
        cout << "9 - Shrink "<<endl;
        cout << "a - mirror" <<endl;
        cout << "b - crop" <<endl;
        cout << "c - Blur Image"<<endl;
        cout << "d - Crop Image"<<endl;
        cout << "e - Skew image right "<<endl;
        cout << "f - Skew image up" << endl;
        cout << "0 - Exist "<<endl;
        cout << "Enter your choice (1-9)or(a-f): ";
        cin >> choice;

        switch (choice) {
            case '1':
                black_white();
                break;
            case '2':
                inverse();
                break;
            case '3':
                merge();
                break;
            case '4':
                flip ();
                break;
            case '5':
                rotate();
                break;
            case '6':
                Darken_Lighten ();
                break;
            case '7':
                detected_edges ();
                break;
            case '8':
                enlarge ();
                break;
            case '9':
                Shrink();
                break;
            case 'a':
                mirror();
                break;
            case 'c':
                Blur() ;
                break;
            case 's':
                saveImage();
                break;
            case 'd':
                crop();
                break;
            case 'e':
                skew_right();
                break;
            case 'f':
                skew_up();
                break;
            case '0':
                q = 0;
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
                return 1;
        }
    }

    return 0;
}

void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}

//_________________________________________
void saveImage () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);

}

//_________________________________________
void black_white() {
    loadImage();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

// /* Example code to convert to BW the image
//    A better version should NOt use 127 but the
//    average of the pixels

            if (image[i][j] > 127)
                image[i][j] = 255;
            else
                image[i][j] = 0;

// do something with the image
        }
    }
}
void inverse() {
    loadImage();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            image[i][j] = 255 - image[i][j] ;
        }
    }
}
void merge() {
    char imageFileName[100];
    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image1);


    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image2);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

            image[i][j] = (image1[i][j] + image2[i][j])/2;
        }
    }
}
void detected_edges(){
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image1);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            if (image1[i][j] > 127){
                image1[i][j] = 255;
            }
            else{
                image1[i][j] = 0;
            }
// do something with the image
        }
    }
    for(int i = 0;i < SIZE;i++){
        for(int j = 0;j < SIZE;j++){
            if(image1[i][j] == 0 && image1[i][j-1] == 0 && image1[i][j+1] == 0 && image1[i-1][j] == 0 && image1[i+1][j] == 0){
                image[i][j] = 255;
            }
            else image[i][j] = image1[i][j];
        }
    }
}
void Blur(){
    loadImage();
    for(int q = 0;q < 3;q++){
        for(int i = 0;i < SIZE; i++)
        {
            for(int j = 0;j < SIZE;j++)
            {
                image[i][j] =(image[i][j] + image[i][j+1] + image[i+1][j+1] + image[i+1][j] + image[i-1][j-1]+ image[i-1][j] + image[i][j-1] ) / 7;

            }
        }
    }
}
void flip(){
    char imageFileName[100];
    cout << "Enter 0 for Horizontal ,Enter 1 for Vertecal : " ;
    int n;
    cin >> n;
    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image1);



    if(n){
        for(int i = 0;i < SIZE;i++){
            for(int j = 0;j < SIZE;j++){
                image2[i][j] = image1[SIZE-i][SIZE-j];
            }
        }
        for(int i = 0;i < SIZE;i++){
            for(int j = 0;j < SIZE;j++){
                image[i][j] = image2[i][SIZE-j];
            }
        }
    }
    else{
        for(int i = 0;i < SIZE;i++){
            for(int j = 0;j < SIZE;j++){
                image[i][j] = image1[i][SIZE-j];
            }
        }
    }
}

void rotate (){
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image1);
    cout << "Enter the degree you want to rotate(90, 180, 270) : \n";
    int n;
    cin >> n;
    switch(n){
        case 90:{
            for(int i = 0;i < SIZE;i++){
                for(int j = 0;j < SIZE;j++){
                    image[i][SIZE-j] = image1[j][i];
                }
            }
            break;
        }
        case 180:{
            for(int i = 0;i < SIZE;i++){
                for(int j = 0;j < SIZE;j++){
                    image[i][j] = image1[SIZE-i][SIZE-j];
                }
            }
            break;
        }
        case 270: {
            for(int i = 0;i < SIZE;i++){
                for(int j = 0;j < SIZE;j++){
                    image2[SIZE-j][SIZE-i] = image1[i][j];
                }
            }
            for(int i = 0;i < SIZE;i++){
                for(int j = 0;j < SIZE;j++){
                    image[SIZE-i][j] = image2[SIZE-i][SIZE-j];
                }
            }
        }
    }
}
void Darken_Lighten (){
    loadImage();
    int n;
    cout << "For dark enter 0 for light enter 1 : ";
    cin >> n;
    if(!n) {
        for(int i = 0;i < SIZE;i++){
            for(int j = 0;j < SIZE;j++){
                image[i][j] *= 0.5;
            }
        }
    }
    else{
        for(int i = 0;i < SIZE;i++){
            for(int j = 0;j < SIZE;j++){
                image[i][j] = (image[i][j]+255) / 2;
            }
        }
    }
}
void enlarge() {
    int x = 0, y = 0;
    cout << "Enter 1 for first quarter or 2 for second or 3 for third or 4 for fourth: ";
    int quarter;
    cin >> quarter;
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image1);
    if(quarter == 1){
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = 0; j< SIZE/2; j++) {
                image[x][y] = image1[i][j];
                image[x+1][y] = image1[i][j];
                image[x][y+1] = image1[i][j];
                image[x+1][y+1] = image1[i][j];
                y+=2;
            }
            x++;
        }
    }
    if(quarter == 2){
        for (int i = 0; i < SIZE/2; i++) {
            for (int j = SIZE/2; j< SIZE; j++) {
                image[x][y] = image1[i][j];
                image[x+1][y] = image1[i][j];
                image[x][y+1] = image1[i][j];
                image[x+1][y+1] = image1[i][j];
                y+=2;
            }
            x++;
        }
    }
    if(quarter == 3){
        for (int i = SIZE/2; i < SIZE; i++) {
            for (int j = 0; j< SIZE/2; j++) {
                image[x][y] = image1[i][j];
                image[x+1][y] = image1[i][j];
                image[x][y+1] = image1[i][j];
                image[x+1][y+1] = image1[i][j];
                y+=2;
            }
            x++;
        }
    }
    if(quarter == 4){
        for (int i = SIZE/2; i < SIZE; i++) {
            for (int j = SIZE/2; j< SIZE; j++) {
                image[x][y] = image1[i][j];
                image[x+1][y] = image1[i][j];
                image[x][y+1] = image1[i][j];
                image[x+1][y+1] = image1[i][j];
                y+=2;
            }
            x++;
        }
    }
}

void Shrink()
{
    char imageFileName[100];
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image1);

    int num;
    cout << "Enter num (2,3,4): ";
    cin >> num;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
            if(i < SIZE/num && j < SIZE/num)
            {
                image[i][j] = image1[i*num][j*num];
            }
            else
            {
                image[i][j] = 255;
            }
        }
    }
}

void mirror()
{
    loadImage();
    int half;
    cout << "1 - first half";
    cout << "2 - second half";
    cout << "3 - third half";
    cout << "4 - fourth half";
    cout << "choose (1,2,3,4): ";
    cin >> half;
    if(half == 1){
        for(int i = 0 ; i < SIZE ; i++)
        {
            for(int j = 0 ; j < SIZE; j++)
            {
                image[i][j] = image[i][255-j];
            }
        }
    }
    if(half == 2){
        for(int i = 0 ; i < SIZE ; i++)
        {
            for(int j = 0 ; j < SIZE; j++)
            {
                image[i][j] = image[255-i][j];
            }
        }
    }
    if(half == 3)
    {
        for(int i = 0 ; i < SIZE/2 ; i++)
        {
            for(int j = 0 ; j < SIZE ; j++)
            {
                image[255 -i][j] = image[i][j];
            }
        }
    }
    if(half == 4)
    {
        for(int i = 0 ; i < SIZE ; i++)
        {
            for(int j = 0 ; j < SIZE ; j++)
            {
                image[i][255 - j] = image[i][j];
            }
        }
    }
}

void crop()
{
    int x , y , l, w;

    cout << "Enter x , y ,l , w (0:255): ";
    cin >> x >> y >> l >> w;

    for(int i = 0; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            if(!(i >= x && i <= x + l && j >= y && j <= y + w))
            {
                image[i][j] = 255;
            }
        }
    }
}

void skew_right() {
    loadImage();
    cout << "Enter deg: ";
    int deg;
    cin >> deg;
    double rad = deg * (M_PI / 180.0);
    double mov = tan(rad) * 256;
    double step = mov / SIZE; // Number of steps
    unsigned char img_in[SIZE][SIZE + (int)mov];

    // Shrink the image
    int x = SIZE / (1 + tan(rad));
    double scalingFactor = static_cast<double>(SIZE) / x;
    int newWidth = x;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < newWidth; ++j) {
            int nearestPixel = image[i][static_cast<int>(j * scalingFactor)];
            image[i][j] = nearestPixel;
        }
        // Fill the remaining part with white pixels
        for (int j = newWidth; j < SIZE; ++j) {
            image[i][j] = 255; // Assuming 255 represents white
        }
    }

    //   Initialize the image with white pixels
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE + mov; j++) {
            img_in[i][j] = 255;
        }
    }

    // Shift the image data to the right
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            img_in[i][j + static_cast<int>(mov)] = image[i][j];
        }
        mov -= step; // Adjust the movement for the skew effect
    }

    //  Copy the adjusted image data back to the original image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = img_in[i][j];
        }
    }
}











void skew_up()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image1);

    double deg;
    cout << "Enter deg : ";
    cin >> deg;
    double left = tan(deg * 3.14159 / 180.0) * SIZE;
    double step_for_original = (double) SIZE / (SIZE - left);
    double step_for_new = (double) left / SIZE;
    double here = 0;
    double curr = 0;

    for(int j = 0;j < SIZE;j++)
    {
        curr = 0;
        for(int i = left - here;i < SIZE - here;i++)
        {


            int old_curr = max(0, (int) ceil(curr - step_for_original));
            int new_curr = min(SIZE, (int) ceil(curr + step_for_original));
            int sum = 0;
            int pixles = new_curr - old_curr;

            for(int c = old_curr;c < new_curr;c++)
            {
                sum += image1[c][j];
            }
            image[i][j] = sum / max(1, pixles);
            curr += step_for_original;
        }
        here += step_for_new;
    }
}