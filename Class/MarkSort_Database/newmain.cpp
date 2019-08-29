/* 
 * File:   newmain.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 11, 2011, 9:26 AM
 * Purpose:  Mark Sort Database 
 */

//System Libraries
#include <cstdlib>  //Random Function
#include <iostream> //I/O
#include <ctime>    //Set the seed
using namespace std;

//User Libraries

//Global Constants
//Math/Physics/Conversion/Higher Order Dimensions

//Function Prototypes
int *fillAry(int);
int *filIndx(int);
void prntAry(int *,int,int);
void prntAry(int *,int *,int,int);
void markSrt(int *,int *,int);

//Execution Begins 
int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int *array,*indx;
    int size=100;
    
    //Initialize/Input Data/Variables
    array=fillAry(size);
    indx=filIndx(size);

    //Display output
    prntAry(array,size,10);
    prntAry(indx,size,10);
    
    //Sort
    markSrt(array,indx,size);
    
    //Display output
    prntAry(array,size,10);
    prntAry(indx,size,10);
    prntAry(array,indx,size,10);
    
    //Clean up dynamic memory
    delete []array;
    
    //Exit program
    return 0;
}

void markSrt(int *a,int *indx,int n){
    for(int i=0;i<n-1;i++){//Find Smallest for each list
        for(int j=i+1;j<n;j++){//Examine each element below top of list
            //Swap
            if(a[indx[i]]>a[indx[j]]){
                indx[i]=indx[i]^indx[j];
                indx[j]=indx[i]^indx[j];
                indx[i]=indx[i]^indx[j];
            }
        }
    }
}

void prntAry(int *a,int *indx,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[indx[i]]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *filIndx(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=i;
    }
    return array;
}

int *fillAry(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand()%90+10;//[10-99]
    }
    return array;
}