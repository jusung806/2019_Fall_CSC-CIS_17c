/* 
 * File:   newmain.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Sept 3rd, 2019
 * Purpose:  Example of finding a minimum with least Squares
 */

//System Libraries
#include <cstdlib>  //Random Function
#include <iostream> //I/O
#include <iomanip>  //Formatting
#include <ctime>    //Set the seed
#include <cmath>    //Math Library
using namespace std;

//User Libraries

//Global Constants
//Math/Physics/Conversion/Higher Order Dimensions
const unsigned int MAXRND=pow(2,31)-1;

//Function Prototypes
float *fillAry(int);//Initialize an array
void tempDat(float *,float *,float,int);//Fill arrays with Temperature Data
void prntAry(float *,float *,int);
float error(float *);


//Execution Begins 
int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    float *xOrF,*yOrC;
    int size=181;
    float var=10;//Peak to Peak
    
    //Initialize/Input Data/Variables
    xOrF=fillAry(size);//Fahrenheit Data
    yOrC=fillAry(size);//Celsius Data
    tempDat(xOrF,yOrC,var,size);
    
    //Display output
    prntAry(xOrF,yOrC,size);
    
    //Clean up dynamic memory
    delete []xOrF;
    delete []yOrC;
    
    //Exit program
    return 0;
}

float error(float eMag){
    return eMag*(2.0f*rand()/MAXRND-1);
}

void tempDat(float *f,float *c,float e,int m){
    for(int i=0;i<m;i++){
        f[i]=32+i;
        c[i]=5.0f/9*(f[i]-32)+error(e);
    }
}

void prntAry(float *x,float *y,int n){
    cout<<fixed<<setprecision(4)<<showpoint;
    cout<<"XorF YorC "<<endl;
    for(int i=0;i<n;i++){
        cout<<setw(9)<<x[i]<<" ";
        cout<<setw(9)<<y[i]<<" "<<endl;
    }
    cout<<endl;
}

float *fillAry(int n){
    float *array=new float[n];
    for(int i=0;i<n;i++){
        array[i]=0;
    }
    return array;
}