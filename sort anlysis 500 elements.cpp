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
  
      150,49,246,254,377,459,311,218,220,181,368,478,159,55,39,337,230,157,286,425,332
,356,51,224,376,493,453,446,462,289,44,236,245,28,300,476,470,447,60,475,200,233
,70,184,239,427,326,303,171,64,120,1,429,71,78,121,203,163,96,280,19,138,228,479
,334,130,195,109,48,456,491,417,341,16,443,448,430,387,431,284,166,492,47,20,362
,112,213,128,176,378,30,333,468,242,363,390,408,116,113,114,329,301,165,148,173,
399,400,161,302,80,403,299,73,198,411,91,250,234,305,321,37,66,330,498,42,139,276,82,153,292,344,379,318,214,40,62,103,84,110,237,140,320,269,467,424,253,270,404,144,263,208,497,471,104,454,259,306,202,57,216,45,394,17,391,258,4,355,152,309
,375,2,264,374,155,15,111,192,297,31,382,353,409,439,275,93,178,11,469,307,381,27,215,315,105,142,351,426,101,160,7,415,463,8,484,283,14,25,442,384,135,370,396,
50,241,75,366,189,186,435,490,89,94,244,52,364,445,81,338,359,499,3,481,350,97,67,69,172,123,137,22,279,386,18,143,367,126,365,271,156,132,455,361,232,461,35,257,167,266,428,180,134,322,452,274,100,21,59,122,412,277,147,393,392,405,168,68,288,0,124,421,191,432,483,295,485,76,221,226,194,466,65,290,314,201,197,227,188,414,231,24,158,196,33,88,449,175,6,95,444,477,385,335,401,291,185,169,217,339,389
,141,373,238,205,38,77,106,261,177,460,79,407,343,294,397,323,496,206,133,262,487,86,87,465,293,72,179,304,223,308,247,63,256,212,108,127,145,438,149,249,402,441,340,265,170,32,494,383,225,54,480,119,495,58,252,162,23,282,248,12,472,273,136
,222,420,488,437,312,56,451,118,296,418,357,187,74,29,61,398,46,346,316,349,90,328,358,229,151,324,319,102,486,354,310,5,240,298,395,406,440,219,183,348,53,327,
489,26,419,450,99,174,251,36,416,131,422,115,146,413,457,190,278,211,107,10,235,
345,388,436,13,285,207,199,473,209,83,260,474,369,287,434,255,372,352,125,325,210,182,164,313,43,34,464,117,458,371,281,85,347,272,268,410,129,9,342,317,331,267
,423,154,243,360,193,98,92,41,336,433,204,482,380
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
