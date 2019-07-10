#include <iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];


    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
      
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

   
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
int main()
{

    ifstream fileInput;
    srand(98563254);
    fileInput.open(" 10M.txt");
    int n=10000000;

    int *arr=new int[n];
    for(int i=0; i< n; i++)
    {
        fileInput >> arr[i];
    }
    
    fileInput.close();


    clock_t starTime=clock();
    mergeSort(arr, 0 , n-1);

    clock_t endTime=clock();

    
    double timeLapse=double(endTime-starTime)/CLOCKS_PER_SEC;
    cout <<"It takes :"<< timeLapse;

    ofstream fileOutput;

    fileOutput.open("10M_output.txt");

    for(int i=0; i<n; i++)
    {
        fileOutput << arr[i]<<endl;

    }
    fileOutput.close();

    delete[] arr;

    return 0;
}





