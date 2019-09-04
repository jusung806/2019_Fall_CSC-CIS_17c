/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on Aug 27th, 2019, 12:15 pM
 * Purpose:  Triangular array in Order
 */

//System Libraries Here
#include <iostream>  //I/O Library
#include <cstdlib>   //Random function Library
#include <ctime>     //Time Library
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int**fillAry(int *,int);       //Randomly fill a triangular array
int *fillAry(int);             //Randomly fill a 1-D column array
void prntAry(int *,int);       //Print a 1-D array
void prntAry(int **,int *,int);//Print a triangular array
//Mod the original with the following indexed array using a database sort idea
void destroy(int **,int *,int *,int);//Deallocate memory
int *filIndx(int);                   //Fill the index
//You code these functions using concepts and programs already discussed
void markSrt(int *,int *,int);       //Sort the columns using the index
void prntAry(int **,int *,int *,int);//Print a triangular array col size order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    //srand(static_cast<unsigned int>(time(0)));
    cout<<"Triangular Matrix Program"<<endl;
    cout<<"Input a positive signed integer for the seed"<<endl;
    cout<<"to the random number generator"<<endl;
    cout<<"This allows for repeatability"<<endl;
    int seed;
    cin>>seed;
    srand(seed);
    
    //Declare all Variables Here
    int *col;      //Pointer to column array
    int **trangl;  //Pointer to triangular array
    int *indx;     //Pointer to the indexed array
    
    //Input or initialize values Here
    int colSize=10;             //Literal column array size
    col=fillAry(colSize);       //Dynamic 1-D array
    indx=filIndx(colSize);      //Fill the index
    trangl=fillAry(col,colSize);//Dynamic triangular array

    //Sort the columns
    markSrt(col,indx,colSize);  //Sort with the index
    
    //Output Located Here
    cout<<"The original Column Matrix"<<endl;
    prntAry(col,colSize);       //Print the original col size for each row
    cout<<endl<<"The sorted Index Array"<<endl;
    prntAry(indx,colSize);      //Print the sorted index of column sizes
    cout<<endl<<"The unsorted Triangular Matrx"<<endl;
    prntAry(trangl,col,colSize);//Print the Triangular matrix unsorted
    cout<<endl<<"The Triangular Matrix printed by smallest column to largest"<<endl;
    prntAry(trangl,col,indx,colSize);//Print the Triangular matrix sorted by col

    //Deallocate the array
    destroy(trangl,col,indx,colSize);//Clean up the results
    
    //Exit
    return 0;
}



//Implement a database sort using an index.  Sort the index not the data.
void markSrt(int *a,int *indx,int n){
    //Your Code Here
}


//Print the sorted Triangular matrix using the index!
void prntAry(int **array,int *col,int *indx,int n){
    //Your Code Here
}



int *filIndx(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=i;
    }
    return array;
}

//Destroy all dynamically created arrays
void destroy(int **a,int *c,int *indx,int n){
    //Delete every row of the triangular array
    for(int i=0;i<n;i++){
        delete a[i];
    }
    //Delete the pointers
    delete []a;
    delete []c;
    delete []indx;
}

//Fill a triangular matrix
int **fillAry(int *col,int n){
    int **array=new int*[n];
    for(int i=0;i<n;i++){
        array[i]=new int[col[i]];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<col[i];j++){
            array[i][j]=rand()%9+1;//1 Digit numbers [1-9]
        }
    }
    return array;
}

//Print the triangular matrix
void prntAry(int **array,int *col,int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<col[i];j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//Print the array
void prntAry(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

//Randomly fill the column size with 1 digit numbers
int *fillAry(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand()%9+1;//1 Digit numbers [1-9]
    }
    return array;
}