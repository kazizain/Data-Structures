#include<iostream>
#include<stdlib.h>
#include <algorithm>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void display(int brr[], int s)
{
	for(int i=0;i<s;i++)
	{
		cout<<"arr["<<i<<"] = "<<brr[i]<<endl;
	}
}
//---------------------------------------->insertion sort

void insertionsort(int brr[],int s)
{
	for(int i=0;i<s;i++)
	{
		int temp= brr[i];
		int j=i-1;
		while(j>=0 && temp<brr[j] )
		{
			brr[j+1]=brr[j];
			j=j-1;
		}
		brr[j+1]=temp;
	}
}

//------------------------------------->merge 

void merge(int brr[],int lowindex,int midindex,int highindex)
{
	int i=lowindex,j=midindex+1,k=lowindex;
	int b[1000];
	while(i<=midindex && j<=highindex)
	{
		if(brr[i]<brr[j])
		{
			b[k++]=brr[i++];
		}
		
		else
		{
			b[k++]=brr[j++];
		}
	}
	
	for(;i<=midindex;i++)
	{
		b[k++]=brr[i]; // for storing value of left side in auxilary array.
	}
	
	for(;j<=highindex;j++)
	{
		b[k++]=brr[j]; // for storing value of right side in auxilary array.
	}
	
	// for complete copy of the value of auxilary arsy in orignal onces;
	for(int i=lowindex;i<=highindex;i++)
	{
		brr[i]=b[i];
	}
}

//--------------->recursive mere sort

void mergesort(int brr[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(brr,low,mid);
		mergesort(brr,mid+1,high);
		merge(brr,low,mid,high);
	}
}


//------------------------------>partition to select pivot as middle.
 
int partition(int brr[],int left,int right)
{
      int i=left,j=right;
      int temp=0;
      int pivot=brr[(left + right)/2];
      while (i<=j)
	   {
            while(brr[i]<pivot)
            {
            	i++;
			}

            while (brr[j]>pivot)
			{
				j--;
			}

            if(i<=j) 
			{
                  temp=brr[i];
                  brr[i]=brr[j];
                  brr[j]=temp;
                  i++;
                  j--;
            }
      }
      return i;
}

//----------------------> quick sort()

void quicksort(int brr[],int left,int right)
{
      int index=partition(brr,left, right);
      if (left<index-1)
       {
         	quicksort(brr,left,index-1);
	   }
      if (index<right)
       {
       	    quicksort(brr,index,right);
	   }        
}


//-------------------------------------> quick sort by median

int partitions(int arr[], int left, int right)
{
    int i=left,j=right;
    int temp;
    int medium = (left + right) / 2;
    int s,t,r;
    if (i>medium)
	{   
      s=i;    																		//sto = s, lo=r, hi=t;
      r=medium;   
   }
    else
	 {
      s=medium;  
      r=i;  
     } 
   if(s>j)
   { 
      t=s;    
      if(r>j)
	  {         
         s=r;                
         r=j;
      }
	  else 
	  {
         s=j;      
      }         
   }
    else
   {
   	t=j;
	}
	 
	int median=s;
	int pivot = median;
    while (i <= j) 
	{ 
            while (arr[i] < pivot)
			{
			 i++;
		    }                 
            while (arr[j] > pivot)
			{
			  j--;
			}
                
            if (i<=j)
			 {
                  temp=arr[i];
                  arr[i]=arr[j];
                  arr[j]=temp;
                  i++;
                  j--;
             }
      }
      return i;
	}

//----------------------> quick sort()

void quicksorts(int brr[],int left,int right)
{
      int index=partitions(brr,left, right);
      if (left<index-1)
       {
         	quicksorts(brr,left,index-1);
	   }
      if (index<right)
       {
       	    quicksorts(brr,index,right);
	   }        
}



//------------------------------>partition to select pivot as random.
 
int partitionr(int brr[],int left,int right,int pivot)
{
      int i=left,j=right;
      int temp=0;
      
      while (i<=j)
	   {
            while(brr[i]<pivot)
            {
            	i++;
			}

            while (brr[j]>pivot)
			{
				j--;
			}

            if(i<=j) 
			{
                  temp=brr[i];
                  brr[i]=brr[j];
                  brr[j]=temp;
                  i++;
                  j--;
            }
      }
      return i;
}

//----------------------> quick sort()

void quicksortr(int brr[],int left,int right)
{
	   int pivot=brr[left+rand()%(right-left)];
      int index=partitionr(brr,left, right,pivot);
      if (left<index-1)
       {
         	quicksortr(brr,left,index-1);
	   }
      if (index<right)
       {
       	    quicksortr(brr,index,right);
	   }        
}

int main()
{
	int size;

	clock_t start, end;
	
	int arr[]={22,54,9,85,46,33,24,52,92,43,29,93,16,79,60,71,83,70,48,8,49,61,89,96,2,5,44,26,
41,76,4,87,88,47,55,18,64,30,39,38,94,98,23,82,11,67,73,77,25,13,37,35,7,95,3,6,
72,31,86,12,99,63,45,81,1,15,65,10,53,69,56,28,20,90,66,42,91,75,32,0,17,62,36,80,97,19,50,51,74,78,58,21,14,68,34,40,84,59,27,57};
	
	size=sizeof(arr)/sizeof(arr[0]);	
	cout<<"Before Sort:\n";	
	display(arr,size);
	int choice;
	cout<<"\n\nEnter choice:";
	cin>>choice;
switch(choice)
	{
		case 1:{
			
	    cout<<"\nAfter insertion Sort:\n";	
	    auto start = high_resolution_clock::now();
	 	insertionsort(arr,size);
	 	auto stop = high_resolution_clock::now();		
		display(arr,size);

	
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;

			break;
		}
		case 2:{
		cout<<"\nAfter merge Sort:\n";    	
	    auto start = high_resolution_clock::now();
		mergesort(arr,0,size-1);
        auto stop = high_resolution_clock::now();		
		display(arr,size);

	
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;
          break;
		}
		
		case 3:{
			cout<<"\nAfter Quick Sort from middle:\n";
		auto start = high_resolution_clock::now();
		quicksort(arr,0,size-1);
		auto stop = high_resolution_clock::now();		
		display(arr,size);

	
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;
          break;
		}
		
		case 4:{
			cout<<"\nAfter Quick Sort from meadian:\n";
		auto start = high_resolution_clock::now();
		quicksorts(arr,0,size-1);
		auto stop = high_resolution_clock::now();		
		display(arr,size);

	
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;
          break;
		
		}
		
		case 5:{
			cout<<"\nAfter Quick Sort from random value taken:\n";
			auto start = high_resolution_clock::now();
		quicksortr(arr,0,size-1);
		auto stop = high_resolution_clock::now();		
		display(arr,size);

	
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: "
		<< duration.count() << " microseconds" << endl;
          break;
		}
	}
	
	
	
			
	
			
}
