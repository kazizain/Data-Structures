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
    
	//  else
	 // {
	         if (left<index-1)
       {
         	quicksort(brr,left,index-1);
	   }
      if (index<right)
       {
       	    quicksort(brr,index,right);
	   }	
	//  } 
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
  
        310,942,105,333,410,833,272,307,286,276,319,100,770,51,671,804,904,461,636,199,366,693,754,894,309,696,112,654,682,190,382,163,177,376,820,304,661,864,753,65,86
,458,669,37,757,644,758,595,694,717,909,185,482,525,964,533,355,400,118,217,45,387,270,69,334,447,811,587,242,80,125,279,760,683,228,298,884,155,39,392,459,348,
623,759,168,378,373,293,549,148,441,64,828,686,878,779,813,283,233,404,880,930,91,846,856,11,40,989,123,170,66,835,269,313,869,49,435,32,364,824,821,268,302,853
,915,580,489,547,803,736,247,897,213,128,56,526,829,903,838,210,589,719,877,470,
211,515,271,887,932,139,282,742,345,961,917,925,183,763,725,882,436,15,465,697,768,215,746,427,146,532,5,680,463,539,496,252,390,809,365,160,962,229,973,950,806
,687,330,726,873,556,4,397,692,385,782,193,396,776,175,469,480,343,637,886,926,403,881,25,137,153,296,351,320,346,698,162,613,422,994,584,171,491,704,44,860,810
,530,537,13,24,660,287,267,729,223,90,406,564,679,490,367,129,317,852,194,156,166,33,625,895,207,845,265,570,951,901,386,180,842,113,476,953,413,161,854,486,329
,548,819,774,246,439,506,579,109,789,611,517,666,681,910,528,655,512,232,358,399
,353,919,55,46,510,545,70,103,78,488,646,944,969,250,424,938,966,735,796,326,677
,26,785,598,444,850,664,711,900,18,462,231,563,277,540,331,560,568,285,921,347,196,667,773,923,481,603,201,50,273,927,981,395,172,859,212,619,604,402,902,586,767,990,449,565,772,495,430,727,216,889,898,588,978,672,85,318,891,582,606,947,288
,135,412,566,327,858,885,536,1,807,841,218,866,311,108,237,178,321,722,709,381,68,892,428,95,721,262,478,415,359,226,837,300,963,99,612,434,554,352,628,751,916,
101,416,253,750,425,543,117,743,342,940,766,119,836,79,315,788,360,295,980,52,158,775,786,472,872,699,138,227,426,497,817,340,144,154,165,924,224,839,518,555,507,234,787,865,336,323,202,110,21,73,659,16,239,718,825,793,814,519,316,970,976,41,730,157,975,541,762,928,121,291,398,523,188,740,259,89,918,794,991,700,407,182
,713,534,7,979,405,417,600,911,230,676,354,983,685,274,377,790,899,280,384,594,173,553,922,948,452,475,912,500,457,812,339,38,19,514,176,484,720,260,649,256,879
,6,581,551,843,181,391,592,28,134,752,111,771,221,471,454,516,341,456,241,601,931,957,993,389,473,744,732,593,710,401,883,630,63,715,440,17,662,97,124,633,142,92,429,363,728,236,275,9,831,448,76,84,857,477,8,971,301,278,29,106,243,328,943,167,72,756,195,150,871,31,145,254,695,738,712,995,3,571,204,818,614,703,552,597,437,764,43,847,257,140,941,896,967,987,629,249,244,393,116,222,372,688,203,380,82
,98,955,61,984,689,934,920,421,956,164,14,67,935,620,648,827,840,0,562,453,997,27,2,126,58,805,466,450,369,572,192,639,189,914,731,220,657,34,542,187,292,511,823,739,131,985,905,88,75,913,937,356,972,349,708,306,647,312,822,235,706,958,289,
658,513,198,583,133,102,93,609,527,388,370,876,504,945,888,104,455,569,521,332,115,791,494,761,338,263,509,208,861,684,933,127,464,362,136,780,557,907,627,747,608,77,214,615,590,673,716,143,769,337,149,632,529,344,152,499,936,538,952,361,531,834,575,690,114,281,954,508,219,968,982,621,832,634,305,651,851,132,745,691,418,616,520,42,81,929,468,578,74,801,10,197,874,797,574,57,596,438,502,498,314,724
,650,174,299,546,949,258,432,483,653,844,702,442,701,643,714,225,524,335,374,147
,414,640,96,375,30,561,996,800,492,645,939,54,205,408,303,577,781,607,467,602,266,130,802,591,255,641,707,446,734,35,599,792,631,20,383,169,986,665,826,870,960,
151,179,618,808,626,567,558,493,723,290,999,294,992,848,308,965,445,777,674,868,
48,23,906,248,368,959,893,783,159,251,849,733,867,379,668,890,576,908,635,120,284,778,544,22,638,141,245,264,460,62,798,559,765,433,741,815,784,663,350,83,830,652,325,200,863,87,240,855,487,184,642,122,474,485,324,522,36,371,816,451,12,535,
206,998,977,53,191,394,799,479,420,59,47,550,585,297,501,60,946,431,443,988,675,
737,107,670,622,610,875,617,749,678,238,209,423,656,573,862,322,357,419,94,748,505,409,795,503,755,411,974,705,261,605,624,186,71
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
