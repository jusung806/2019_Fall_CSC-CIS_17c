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
void tempDat(float *,float *,float,float,float,float,float,int);//Temperature Data
void prntAry(float *,float *,int);//Print the table
float error(float *);//Error in measuring uniform peak to peak
float lstSqrs(float *,float *,float &,float &,float,float,float,float,
        float,int);//Find least squares by Range search
float lstSqrs(float *,float *,float &,float &,int);//By derived formula


//Execution Begins 
int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables related to temperature example
    float *xOrF,*yOrC;
    int size=181;
    float tmpStrt=32,slope=5.0f/9,intrcpt=-slope*tmpStrt,delTemp=1;
    float errVar=0.0f;//Peak to Peak errors
    
    //Initialize/Input Data/Variables
    xOrF=fillAry(size);//Fahrenheit Data
    yOrC=fillAry(size);//Celsius Data
    
    //Generate the temperature data using a linear 1st order polynomial
    //y=mx+b or c=mf+b, same thing.
    tempDat(xOrF,yOrC,tmpStrt,delTemp,slope,intrcpt,errVar,size);
    
    //Display output
    prntAry(xOrF,yOrC,size);
    
    //Calculate the least square error using a search range
    float minM,minB,mStrt=0,mEnd=1,bStrt=-20,bEnd=-15,delt=0.0005;
    int begTime=time(0);
    float e2=lstSqrs(xOrF,yOrC,minM,minB,mStrt,mEnd,bStrt,bEnd,delt,size);
    int endTime=time(0);
    cout<<"Least Squares using a directed search."<<endl;
    cout<<"Slope = "<<minM<<", Intercept = "<<minB<<", Error^2 = "<<e2<<endl;
    cout<<"Total Time = "<<endTime-begTime<<" secs"<<endl<<endl;
    
    //Calculate the least square error using class derived formula
    begTime=time(0);
    lstSqrs(xOrF,yOrC,minM,minB,size);
    endTime=time(0);
    cout<<"Least Squares using a formula calculation."<<endl;
    cout<<"Slope = "<<minM<<", Intercept = "<<minB<<endl;
    cout<<"Total Time = "<<endTime-begTime<<" secs"<<endl<<endl;
    
    //Clean up dynamic memory
    delete []xOrF;
    delete []yOrC;
    
    //Exit program
    return 0;
}

//Find least squares by derived formula from class
float lstSqrs(float *x,float *y,float &m,float &b,int mDat){
    float sumY=0,sumX=0,sumXY=0,sumX2=0;
    for(int i=0;i<mDat;i++){
        sumY+=y[i];
        sumX+=x[i];
        sumXY+=x[i]*y[i];
        sumX2+=x[i]*x[i];
    }
    m=(mDat*sumXY-sumX*sumY)/(mDat*sumX2-sumX*sumX);
    b=(sumY-m*sumX)/mDat;
}

//Search for the slope and intercept that minimizes the square of the error
//This is to find the closest match to the linear first order polynomial
//y=mx+b and will use the temperature 
float lstSqrs(float *x,float *y,float &m,float &b,float mb,float me,
        float bb,float be,float delt,int mDat){
    //Declare search conditions
    float minM=mb, minB=bb,e2min=0;
    for(float im=mb;im<me;im+=delt){
        for(float ib=bb;ib<be;ib+=delt){
            float e2=0;
            for(int i=0;i<mDat;i++){
                e2+=(y[i]-im*x[i]-ib)*(y[i]-im*x[i]-ib);
            }
            if(e2min==0||e2min>e2){
                e2min=e2;
                minM=im;
                minB=ib;
            }
        }
    }
    m=minM;
    b=minB;
    return e2min;
}

//Generate random +-errors with peak to peak magnitude
float error(float eMag){
    return eMag*(2.0f*rand()/MAXRND-1);
}

//Generate temperature data with random errors
void tempDat(float *f,float *c,float xstart,float delt,
        float slope,float intrcpt,float e,int m){
    for(int i=0;i<m;i++){
        f[i]=xstart+i*delt;
        c[i]=slope*f[i]+intrcpt+error(e);
    }
}

//Print the table of simulated data
void prntAry(float *x,float *y,int n){
    cout<<fixed<<setprecision(4)<<showpoint;
    cout<<"     XorF      YorC "<<endl;
    for(int i=0;i<n;i++){
        cout<<setw(9)<<x[i]<<" ";
        cout<<setw(9)<<y[i]<<" "<<endl;
    }
    cout<<endl;
}

//Just initialize a dynamic array
float *fillAry(int n){
    float *array=new float[n];
    for(int i=0;i<n;i++){
        array[i]=0;
    }
    return array;
}