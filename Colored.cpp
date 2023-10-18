// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0

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
void shuffle();

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
        cout << "b - shuffle" <<endl;
        cout << "c - Blur Image"<<endl;
        cout << "d - Crop Image"<<endl;
        cout << "e - Skew image right "<<endl;
        cout << "f - Skew image up" << endl;
        cout << "s - To Save image "<<endl;
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
            case 'b':
                shuffle();
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

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image1);
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
    for(int i = 0;i < SIZE;i++){
        for(int j = 0;j < SIZE;j++){
              if((image1[i][j][0] + image1[i][j][1] + image1[i][j][2])/3> 127)
              {
                    image[i][j][0] = 255;
                    image[i][j][1] = 255;
                    image[i][j][2] = 255;
              }
              else
              {
                    image[i][j][0] = 0;
                    image[i][j][1] = 0;
                    image[i][j][2] = 0;
              }
            // int black_white = (image1[i][j][0] + image1[i][j][1] + image1[i][j][2])/3;
            // image[i][j][0] = black_white;
            // image[i][j][1] = black_white;
            // image[i][j][2] = black_white;

        }
    }
}
void detected_edges() {
    loadImage();

    for(int i = 0;i < SIZE;i++){
        for(int j = 0;j < SIZE;j++){

           // int black_white = (image1[i][j][0] + image1[i][j][1] + image1[i][j][2])/3;
            //image[i][j][0] = black_white;
            //image[i][j][1] = black_white;
            //image[i][j][2] = black_white;
              if((image1[i][j][0] + image1[i][j][1] + image1[i][j][2])/3> 127)
              {
                    image2[i][j][0] = 255;
                    image2[i][j][1] = 255;
                    image2[i][j][2] = 255;
              }
              else
              {
                    image2[i][j][0] = 0;
                    image2[i][j][1] = 0;
                    image2[i][j][2] = 0;
              }

        }
    }
    for(int i = 0;i < SIZE;i++)
    {
        for(int j = 0;j < SIZE;j++)
        {
            if(image2[i][j][0] == 0 && image2[i][j-1][0] == 0 && image2[i][j+1][0] == 0 && image2[i-1][j][0] == 0 && image2[i+1][j][0] == 0)
            {
                image[i][j][0] = 255;
                image[i][j][1] = 255;
                image[i][j][2] = 255;

            }
            else
            {
                image[i][j][0] = image2[i][j][0];
                image[i][j][1] = image2[i][j][1];
                image[i][j][2] = image2[i][j][2];
            }
        }
    }
}
void inverse()
{
        loadImage();

    for(int i = 0;i < SIZE;i++)
    {
        for(int j = 0;j < SIZE;j++){
            image[i][j][0] = 255-image1[i][j][0];
            image[i][j][1] = 255-image1[i][j][1];
            image[i][j][2] = 255-image1[i][j][2];

        }
    }
}
void merge() {
    loadImage();
    char imageFileName[100];
    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image2);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {

            image[i][j][0] = (image1[i][j][0] + image2[i][j][0])/2;
            image[i][j][1] = (image1[i][j][1] + image2[i][j][1])/2;
            image[i][j][2] = (image1[i][j][2] + image2[i][j][2])/2;
        }
    }
}
void flip(){
    loadImage();
    cout << "Flip (h)orizontally or (v)ertically ? " ;
    char n;
    cin >> n;
    if(n == 'v'){
        for(int i = 0;i < SIZE;i++){
            for(int j = 0;j < SIZE;j++){
                image2[i][j][0] = image1[SIZE-i][SIZE-j][0];
                image2[i][j][1] = image1[SIZE-i][SIZE-j][1];
                image2[i][j][2] = image1[SIZE-i][SIZE-j][2];
            }
        }
        for(int i = 0;i < SIZE;i++){
            for(int j = 0;j < SIZE;j++){
                image[i][j][0] = image2[i][SIZE-j][0];
                image[i][j][1] = image2[i][SIZE-j][1];
                image[i][j][2] = image2[i][SIZE-j][2];

            }
        }
        }
      else{
        for(int i = 0;i < SIZE;i++){
            for(int j = 0;j < SIZE;j++){
                image[i][j][0] = image1[i][SIZE-j][0];
                image[i][j][1] = image1[i][SIZE-j][1];
                image[i][j][2] = image1[i][SIZE-j][2];

            }
        }
    }
}
void rotate (){
    loadImage();
    cout << "Rotate (90), (180) or (270) degrees?";
    int n;
    cin >> n;
    switch(n){
        case 90:{
            for(int i = 0;i < SIZE;i++){
                for(int j = 0;j < SIZE;j++){
                    image[i][SIZE-j][0] = image1[j][i][0];
                    image[i][SIZE-j][1] = image1[j][i][1];
                    image[i][SIZE-j][2] = image1[j][i][2];

                }
            }
            break;
        }
        case 180:{
            for(int i = 0;i < SIZE;i++){
                for(int j = 0;j < SIZE;j++){
                    image[i][j][0] = image1[SIZE-i][SIZE-j][0];
                    image[i][j][1] = image1[SIZE-i][SIZE-j][1];
                    image[i][j][2] = image1[SIZE-i][SIZE-j][2];

                }
            }
            break;
        }
        case 270: {
            for(int i = 0;i < SIZE;i++){
                for(int j = 0;j < SIZE;j++){
                    image2[SIZE-j][SIZE-i][0] = image1[i][j][0];
                    image2[SIZE-j][SIZE-i][1] = image1[i][j][1];
                    image2[SIZE-j][SIZE-i][2] = image1[i][j][2];

                }
            }
            for(int i = 0;i < SIZE;i++){
                for(int j = 0;j < SIZE;j++){
                    image[SIZE-i][j][0] = image2[SIZE-i][SIZE-j][0];
                    image[SIZE-i][j][1] = image2[SIZE-i][SIZE-j][1];
                    image[SIZE-i][j][2] = image2[SIZE-i][SIZE-j][2];

                }
            }
        }
    }
}

void Darken_Lighten (){
    loadImage();
    char n;
    cout << "Do you want to (d)arken or (l)ighten? ";
    cin >> n;
    if(n == 'd') {
        for(int i = 0;i < SIZE;i++){
            for(int j = 0;j < SIZE;j++){
                image[i][j][0] = image1[i][j][0]*0.5;
                image[i][j][1] = image1[i][j][1]*0.5;
                image[i][j][2] = image1[i][j][2]*0.5;


            }
        }
    }
    else{
        for(int i = 0;i < SIZE;i++){
            for(int j = 0;j < SIZE;j++){
                image[i][j][0] = (image1[i][j][0]+255) / 2;
                image[i][j][1] = (image1[i][j][1]+255) / 2;
                image[i][j][2] = (image1[i][j][2]+255) / 2;

            }
        }
    }
}

void enlarge() {
    loadImage();
  int x = 0, y = 0;
  cout << "Which quarter to enlarge 1, 2, 3 or 4?";
  int quarter;
  cin >> quarter;
  if(quarter == 1){
    for (int i = 0; i < SIZE/2; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        for(int k = 0;k < 3;k++){
            image[x][y][k] = image1[i][j][k];
            image[x+1][y][k] = image1[i][j][k];
            image[x][y+1][k] = image1[i][j][k];
            image[x+1][y+1][k] = image1[i][j][k];
        }
        y+=2;
      }
      x++;
    }
  }
  if(quarter == 2){
    for (int i = 0; i < SIZE/2; i++) {
      for (int j = SIZE/2; j< SIZE; j++) {
        for(int k = 0;k < 3;k++){
        image[x][y][k] = image1[i][j][k];
        image[x+1][y][k] = image1[i][j][k];
        image[x][y+1][k] = image1[i][j][k];
        image[x+1][y+1][k] = image1[i][j][k];
        }

        y+=2;
      }
      x++;
    }
  }
  if(quarter == 3){
    for (int i = SIZE/2; i < SIZE; i++) {
      for (int j = 0; j< SIZE/2; j++) {
        for(int k = 0;k < 3;k++){
            image[x][y][k] = image1[i][j][k];
            image[x+1][y][k] = image1[i][j][k];
            image[x][y+1][k] = image1[i][j][k];
            image[x+1][y+1][k] = image1[i][j][k];
        }
        y+=2;
      }
      x++;
    }
  }
  if(quarter == 4){
    for (int i = SIZE/2; i < SIZE; i++) {
      for (int j = SIZE/2; j< SIZE; j++) {
        for(int k = 0;k < 3;k++){
            image[x][y][k] = image1[i][j][k];
            image[x+1][y][k] = image1[i][j][k];
            image[x][y+1][k] = image1[i][j][k];
            image[x+1][y+1][k] = image1[i][j][k];
        }
        y+=2;
      }
      x++;
    }
  }
}

void Shrink()
{
    loadImage();
    int num;
    cout << "Enter num (2,3,4): ";
    cin >> num;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j< SIZE; j++) {
        if(i < SIZE/num && j < SIZE/num)
        {
            image[i][j][0] = image1[i*num][j*num][0];
            image[i][j][1] = image1[i*num][j*num][1];
            image[i][j][2] = image1[i*num][j*num][2];
        }
        else
        {
            image[i][j][0] = 255;
            image[i][j][1] = 255;
            image[i][j][2] = 255;
        }
    }
    }
}

void mirror()
{
        
    char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
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
                image[i][j][0] = image[i][255-j][0];
                image[i][j][1] = image[i][255-j][1];
                image[i][j][2] = image[i][255-j][2];
            }
        }
    }
    if(half == 2){
        for(int i = 0 ; i < SIZE ; i++)
        {
            for(int j = 0 ; j < SIZE; j++)
            {
                image[i][j][0] = image[255-i][j][0];
                image[i][j][1] = image[255-i][j][1];
                image[i][j][2] = image[255-i][j][2];
            }
        }
    }
    if(half == 3)
    {
        for(int i = 0 ; i < SIZE/2 ; i++)
        {
            for(int j = 0 ; j < SIZE ; j++)
            {
                image[255 -i][j][0] = image[i][j][0];
                image[255 -i][j][1] = image[i][j][1];
                image[255 -i][j][2] = image[i][j][2];
            }
        }
    }
    if(half == 4)
    {
        for(int i = 0 ; i < SIZE ; i++)
        {
            for(int j = 0 ; j < SIZE ; j++)
            {
                image[i][255 - j][0] = image[i][j][0];
                image[i][255 - j][1] = image[i][j][1];
                image[i][255 - j][2] = image[i][j][2];
            }
        }
    }
}

void Blur(){
    loadImage();
    
    for(int q = 0;q < 12;q++){
        for(int i = 0;i < SIZE; i++)
        {
            for(int j = 0;j < SIZE;j++)
            {
                image[i][j][1] =(image1[i][j][1] + image1[i][j+1][1] + image1[i+1][j+1][1] + image1[i+1][j][1] + image1[i-1][j-1][1]+ image1[i-1][j][1] + image1[i][j-1][1] + image1[i+1][j-1][1] + image1[i-1][j+1][1] ) / 9;
                image[i][j][0] =(image1[i][j][0] + image1[i][j+1][0] + image1[i+1][j+1][0] + image1[i+1][j][0] + image1[i-1][j-1][0]+ image1[i-1][j][0] + image1[i][j-1][0]+ image1[i+1][j-1][0] + image1[i-1][j+1][0]  ) / 9;
                image[i][j][2] =(image1[i][j][2] + image1[i][j+1][2] + image1[i+1][j+1][2] + image1[i+1][j][2] + image1[i-1][j-1][2]+ image1[i-1][j][2] + image1[i][j-1][2] + image1[i+1][j-1][2] + image1[i-1][j+1][2] ) / 9;

            }
        }
    }
}

void crop()
{
    loadImage();
    int x , y , l, w;

    cout << "Enter x , y ,l , w (0:255): ";
    cin >> x >> y >> l >> w;

    for(int i = 0; i < SIZE ; i++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            if(!(i >= x && i <= x + l && j >= y && j <= y + w))
            {
                image[i][j][0] = 255;
                image[i][j][1] = 255;
                image[i][j][2] = 255;
            }
            else
            {
                image[i][j][0] = image1[i][j][0];
                image[i][j][1] = image1[i][j][1];
                image[i][j][2] = image1[i][j][2];
            }
        }
    }
}

void skew() {
    loadImage();    
    cout << "Enter deg: ";
    int deg;
    cin >> deg;
    double rad = deg * (M_PI / 180.0);
    double mov = tan(rad) * 256;
    double step = mov / SIZE; // Number of steps
    unsigned char img_in[SIZE][SIZE + (int)mov][3];

    // Shrink the image
    int x = SIZE / (1 + tan(rad));
    double scalingFactor = static_cast<double>(SIZE) / x;
    int newWidth = x;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < newWidth; ++j) {
            int nearestPixel = (image[i][static_cast<int>(j * scalingFactor)][0]+image[i][static_cast<int>(j * scalingFactor)][0]+image[i][static_cast<int>(j * scalingFactor)][0])/3;
            image[i][j][0] = nearestPixel;
            image[i][j][1] = nearestPixel;
            image[i][j][2] = nearestPixel;
        }
        // Fill the remaining part with white pixels
        for (int j = newWidth; j < SIZE; ++j) {
            image[i][j][0] = 255; // Assuming 255 represents white
            image[i][j][1] = 255; // Assuming 255 represents white
            image[i][j][2] = 255; // Assuming 255 represents white
        }
    }

  //   Initialize the image with white pixels
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE + mov; j++) {
            img_in[i][j][0] = 255;
            img_in[i][j][1] = 255;
            img_in[i][j][2] = 255;
        }
    }

    // Shift the image data to the right
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            img_in[i][j + static_cast<int>(mov)][0] = image[i][j][0];
            img_in[i][j + static_cast<int>(mov)][1] = image[i][j][1];
            img_in[i][j + static_cast<int>(mov)][2] = image[i][j][2];
        }
        mov -= step; // Adjust the movement for the skew effect
    }

   //  Copy the adjusted image data back to the original image
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j][0] = img_in[i][j][0];
            image[i][j][1] = img_in[i][j][1];
            image[i][j][2] = img_in[i][j][2];
        }
    }
}

void skew_right()
{
    for(int i= 0;i < SIZE;i++){
        for(int j = 0;j < SIZE;j++)
        {
            for(int k = 0;k < 3;k++)
            {
                image[i][j][k] = 255;
            }
        }
    }
    loadImage();
    double deg;
    cout << "Enter deg : ";
    cin >> deg;
    double left = tan(deg * 3.14159 / 180.0) * SIZE;
    double step_for_original = (double) SIZE / (SIZE - left);
    double step_for_new = (double) left / SIZE;
    double here = 0;
    double curr = 0;
    for(int i = 0;i < SIZE;i++)
    {
        curr = 0;
        for(int j = left - here;j < SIZE - here;j++)
        {
            for(int k = 0;k < 3;k++)
            {
                int old_curr = max(0, (int) ceil(curr - step_for_original));
                int new_curr = min(SIZE, (int) ceil(curr + step_for_original));
                int sum = 0;
                int pixels = new_curr - old_curr;
                for(int c = old_curr;c < new_curr;c++)
                {
                    sum += image1[i][c][k];
                }
                image[i][j][k] = sum / max(1, pixels);
            }
            curr += step_for_original;
        }
        here += step_for_new;
    } 
}
void skew_up()
{
    loadImage();
    for(int i= 0;i < SIZE;i++){
        for(int j = 0;j < SIZE;j++)
        {
            for(int k = 0;k < 3;k++)
            {
                image[i][j][k] = 255;
            }
        }
    }
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
            for(int k = 0;k < 3;k++)
            {
                int old_curr = max(0, (int) ceil(curr - step_for_original));
                int new_curr = min(SIZE, (int) ceil(curr + step_for_original));
                int sum = 0;
                int pixles = new_curr - old_curr;

                for(int c = old_curr;c < new_curr;c++)
                {
                    sum += image1[c][j][k];
                }
                image[i][j][k] = sum / max(1, pixles);
            }
            curr += step_for_original;
        }
        here += step_for_new;
    }
}

void shuffle()
{
    loadImage();
    int start_i[4] = {0, 0, 127, 127};
    // int end_i[4] = {127, 127, SIZE, SIZE};
    int start_j[4] = {0, 127, 0, 127};
    // int end_j[4] = {127, SIZE, 127, SIZE};

    int arr[4];

    cout << "enter quarters : ";
    for(int i = 0;i < 4;i++)
    {
        cin >> arr[i];
    }

    for(int i = 0;i < 127;i++)
    {
        for(int j = 0;j < 127;j++)
        {
            int a = start_i[arr[0] - 1];
            int b = start_j[arr[0] - 1];
            image[i][j][0] = image1[a+i][b+j][0];
            image[i][j][1] = image1[a+i][b+j][1];
            image[i][j][2] = image1[a+i][b+j][2];
        }
    }
    int a = start_i[arr[1]-1], b = 0;
    if(start_j[arr[1] - 1] == 0){
        b = -127;
    }

    for(int i = 0;i < 127;i++)
    {
        for(int j = 127;j < SIZE;j++)
        {
            image[i][j][0] = image1[i+a][j+b][0];
            image[i][j][1] = image1[i+a][j+b][1];
            image[i][j][2] = image1[i+a][j+b][2];
        }
    }
    a = 0;
    b = start_j[arr[2]-1];
    if(start_i[arr[2] - 1] == 0){
        a = -127;
    }
    for(int i = 127;i < SIZE;i++)
    {
        for(int j = 0;j < 127;j++)
        {
            image[i][j][0] = image1[a+i][b+j][0];
            image[i][j][1] = image1[a+i][b+j][1];
            image[i][j][2] = image1[a+i][b+j][2];
        }
    }
    a = 0;
    b = 0;
    if(start_i[arr[3]-1] == 0)
    {
        a = -127;
    }
    if(start_j[arr[3]-1] == 0)
    {
        b = -127;
    }
    for(int i = 127;i < SIZE;i++)
    {
        for(int j = 127;j < SIZE;j++)
        {
            image[i][j][0] = image1[a+i][b+j][0];
            image[i][j][1] = image1[a+i][b+j][1];
            image[i][j][2] = image1[a+i][b+j][2];
        }
    }
}   
