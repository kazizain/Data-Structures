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

	
	int arr[]={
  
     116,181,247,18,337,143,114,24,370,298,132,317,194,184,17,351,35,90,130,217,158,129,208,2,325,66,166,225,10,280,76,245,102,359,120,112,318,257,355,91,269,128,314
,374,279,49,47,189,136,220,74,55,392,282,163,175,273,78,99,345,300,135,122,68,192,82,52,111,75,180,80,331,41,378,308,152,142,385,272,346,232,213,357,299,150,302
,42,286,73,193,277,329,332,205,330,9,190,342,233,12,182,53,319,168,124,227,307,249,34,50,360,198,294,255,218,350,248,219,138,11,13,306,373,45,304,43,79,173,117,
27,105,59,86,210,104,119,344,278,72,391,275,239,264,77,281,284,237,93,296,251,231,358,379,26,214,46,8,262,347,202,333,191,109,199,131,170,187,101,160,56,263,289
,268,174,356,5,375,324,361,98,110,157,81,113,256,354,155,236,137,0,88,169,327,156,186,293,16,244,206,139,222,36,384,60,63,30,62,301,274,107,204,349,69,201,367,315,343,95,185,147,339,64,200,316,37,7,28,83,224,149,252,121,258,97,398,365,323,154,171,67,305,176,241,70,92,259,297,242,172,133,161,240,106,148,338,84,303,4,33,
14,341,65,15,309,54,353,159,377,230,23,334,134,340,254,238,162,115,96,312,6,362,
108,291,188,369,196,376,243,395,103,22,21,387,146,276,203,179,383,207,38,151,253
,123,140,165,126,335,372,267,348,394,85,57,266,287,221,48,1,3,336,390,396,311,228,58,144,44,94,89,313,71,364,164,366,125,371,285,19,271,363,261,178,100,290,25,328,246,388,283,31,61,288,389,145,153,211,223,250,167,118,216,141,39,29,40,352,382,183,270,295,20,321,397,310,393,322,265,209,195,197,368,127,380,212,87,51,177,260,386,215,326,234,399,320,226,235,292,229,381,32
	};
	
	
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
