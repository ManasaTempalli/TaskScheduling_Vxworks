#include<iostream.h>
#include "taskLib.h"
#include "taskHookLib.h"
#include "tickLib.h"
#include "string.h"
#include "vxWorks.h"
#include "stdio.h"
#include "text.h"
#include "kernelLib.h"
#include "timexLib.h"
#include<msgQLib.h>
#include<sysLib.h>
#define MAX_MSGS (20) 
#define MAX_MSG_LEN (sizeof(int))

//functions
void bubblesort();
void quicksort();
void shellsort();
void heapsort();



//global variables
int tidbubblesort,tidquicksort,tidheapsort,tidshellsort;
int bubblepreempt=0,quickpreempt=0,heappreempt=0,shellpreempt=0,bubblepre,quickpre,heappre,shellpre=0;
UINT32 bubble5=0,quick5=0,heap5=0,shell5=0,bubble1,bubble2,bubble3,bubble4,quick1,quick2,quick3,quick4,heap1,heap2,heap3,heap4,shell1,shell2,shell3,shell4;
MSG_Q_ID myMsgQId_BUBBLE,myMsgQId_QUICK,myMsgQId_HEAP,myMsgQId_SHELL,myMsgQId_Bubble,myMsgQId_Quick,myMsgQId_Heap,myMsgQId_Shell,myMsgQId_createHook,myMsgQId_switchHook;
UINT32 quickextime1=0,quickextime2=0,bubbleextime1=0,bubbleextime2=0,heapextime1=0,heapextime2=0,shellextime1=0,shellextime2=0,quickfinalextime=0,bubblefinalextime=0,heapfinalextime=0,shellfinalextime=0;
unsigned long bubbleextime,quickextime,heapextime,shellextime;
//create
void createHook(WIND_TCB *pNewTcb) { 
	if(strcmp(taskName(int(pNewTcb)),"task_quick")==0)
	{
	quickfinalextime=0;
	}
	else if(strcmp(taskName(int(pNewTcb)),"task_bubble")==0)
	{
		bubblefinalextime=0;
	}
	else if(strcmp(taskName(int(pNewTcb)),"task_heap")==0)
	{
		heapfinalextime=0;
	}
	else if(strcmp(taskName(int(pNewTcb)),"task_shell")==0)
	{
		shellfinalextime=0;
	}
}


 void switchHook ( WIND_TCB *pOldTcb, WIND_TCB *pNewTcb ) {
	 if(strcmp(taskName(int(pNewTcb)),"task_quick")==0)
	 	{ 	
	  quick1=sysTimestamp( );
      quick3=quick1;
	 	}
	 else if(strcmp(taskName(int(pNewTcb)),"task_bubble")==0)
	 	{ 	
	  bubble1=sysTimestamp( );
	  bubble3=bubble1;
	 	}
	 else if(strcmp(taskName(int(pNewTcb)),"task_heap")==0)
	 	{ 	
	  heap1=sysTimestamp( );
	  heap3=heap1;
	 	}
	 else if(strcmp(taskName(int(pNewTcb)),"task_shell")==0)
	 	{ 	
	  shell1=sysTimestamp( );
	  shell3=shell1;
	 	}
	 if(strcmp(taskName(int(pOldTcb)),"task_quick")==0)
	 	 	{ 	
	 	  quick2=sysTimestamp( );
	 	 quickfinalextime+= (quick2-quick3);
	 	 quickpreempt++;
	 	
	 	 	}
	 	 else if(strcmp(taskName(int(pOldTcb)),"task_bubble")==0)
	 	 	{ 	
	 	  bubble2=sysTimestamp( );
	 	 bubblefinalextime+= (bubble2-bubble3);
	 	 bubblepreempt++;
	 	
	 	 	}
	 	 else if(strcmp(taskName(int(pOldTcb)),"task_heap")==0)
	 	 	{ 	
	 	  heap2=sysTimestamp( );
	 	 heapfinalextime+= (heap2-heap3);
	 	 heappreempt++;
	 	
	 	 	}
	 	 else if(strcmp(taskName(int(pOldTcb)),"task_shell")==0)
	 	 	{ 	
	 	  shell2=sysTimestamp( );
	 	 shellfinalextime+=(shell2-shell3);
	 	 shellpreempt++;
	 	
	 	 	}
	}

 
void deleteHook(WIND_TCB *pTcb ) { 
	if(pTcb=taskTcb(tidbubblesort)){
		bubble4=sysTimestamp( );
		bubblefinalextime+=(bubble4-bubble3);
		bubbleextime=bubble4-bubble3-bubblefinalextime;
			STATUS err1;
		 	err1=msgQSend(myMsgQId_BUBBLE,(char *) &( bubbleextime ),sizeof (int),NO_WAIT, MSG_PRI_NORMAL);
		 	STATUS err5;
		 			 	err5=msgQSend(myMsgQId_BUBBLE,(char *) &( bubblepreempt ),sizeof (int),NO_WAIT, MSG_PRI_NORMAL);
			}
			if(pTcb=taskTcb(tidquicksort)){
				quick4=sysTimestamp( );
				quickfinalextime+=(quick4-quick3);
				quickextime=quick4-quick3-quickfinalextime;
				STATUS err2;
		 		err2=msgQSend(myMsgQId_QUICK,(char *) &( quickextime ),sizeof (int),NO_WAIT, MSG_PRI_NORMAL);
		 		STATUS err6;
		 				 		err6=msgQSend(myMsgQId_QUICK,(char *) &( quickpreempt ),sizeof (int),NO_WAIT, MSG_PRI_NORMAL);
				}
			if(pTcb=taskTcb(tidheapsort)){
				heap4=sysTimestamp( );
				heapfinalextime+=(heap4-heap3);
				heapextime=heap4-heap3-heapfinalextime;
				STATUS err3;
		 		err3=msgQSend(myMsgQId_HEAP,(char *) &( heapextime ),sizeof (int),NO_WAIT, MSG_PRI_NORMAL);
		 		STATUS err7;
		 				 		err7=msgQSend(myMsgQId_HEAP,(char *) &( heappreempt ),sizeof (int),NO_WAIT, MSG_PRI_NORMAL);
				}
			if(pTcb=taskTcb(tidshellsort)){
				shell4=sysTimestamp( );
				shellfinalextime+=(shell4-shell3);
				shellextime=shell4-shell3-shellfinalextime;
				STATUS err4;
		 		err4=msgQSend(myMsgQId_SHELL,(char *) &( shellextime ),sizeof (int),NO_WAIT, MSG_PRI_NORMAL);
				STATUS err8;
		 		err8=msgQSend(myMsgQId_SHELL,(char *) &( shellpreempt ),sizeof (int),NO_WAIT, MSG_PRI_NORMAL);

				}

     }


//bubblesort
void bubble_sort(char a[],int n)
	    {
	     
	    	for (int i = 0; i < n; ++i){
	    	    for (int j = 0; j < n - i - 1; ++j)
	    	      if (a[j] > a[j + 1])
	    	     {
	    	        char temp = a[j];
	    	        a[j] = a[j + 1];
	    	        a[j + 1] = temp;
	    	      }
	    	}
	    	
	    	for(int k = 0;k<n;k++){
	    		cout <<a[k];
	    	}
	    	taskPrioritySet(tidbubblesort,121);
	    	
	    }
	    void bubblesort()
	    {
	    	
	    	bubble_sort(srcString,srcLength);
	    	cout<<"\nBubblesort done:";
	    	
        }
	    //bubblends
	    //quickbegin
	    void quick_Sort(char arr[],int left,int right) {
	    	    	
	    	          int i = left, j = right;
	    	          char tmp;
	    	          char pivot = arr[(left + right) / 2];
	    	     
	    	          /* partition */
	    	          while (i <= j) {
	    	                while (arr[i] < pivot){
	    	                      i++;}
	    	                while (arr[j] > pivot){
	    	                      j--;}
	    	                if (i <= j) {
	    	                      tmp = arr[i];
	    	                      arr[i] = arr[j];
	    	                      arr[j] = tmp;
	    	                      i++;
	    	                      j--;
	    	                }
	    	          };
	    	     
	    	          /* recursion */
	    	          if (left < j){
	    	                quick_Sort(arr, left, j);}
	    	          if (i < right){
	    	                quick_Sort(arr, i, right);}
	    	          cout<<arr[i];
	    	          taskPrioritySet(tidquicksort,121);
	    	    }
	    	    void quicksort()
	    	    {
	    	    	
	    	    	int l=srcLength;
	    	    	quick_Sort(srcString,0,l);
	    	    	cout<<"\nQuicksortdone:";
	    	    	
	    	    }
	    	    //quickend
	    	    /**************************************************************************************************/
	    	    	    void shell_sort (char ar[], int size)
	    	    	    {
	    	    	      int j;
	    	    	     
	    	    	      //Narrow the array by 2 everytime
	    	    	      for (int gap = size / 2; gap > 0; gap /= 2)
	    	    	      {
	    	    	        for (int i = gap; i < size; ++i)
	    	    	        {
	    	    	          char temp = ar[i];
	    	    	          for (j = i; (j >= gap && temp < ar[j - gap]); j -= gap)
	    	    	          {
	    	    	            ar[j] = ar[j - gap];
	    	    	          }
	    	    	          ar[j] = temp;
	    	    	        } 
	    	    	      }
	    	    	      cout<<ar[j];
	    	    	    }
	    	    	    void shellsort()
	    	    	    {
	    	    	    	
	    	    	    	shell_sort(srcString,srcLength);
	    	    	    	taskPrioritySet(tidshellsort,121 );
	    	    	    	cout<<"Shell sort done:";
	    	    	    	
		
	    	    	    }
	    	    	    /**************************************************************************************************/
	    //heap
	    	    	    void MAX_HEAPIFY(char a[], int i, int n)
	    	    	    	    {
	    	    	    	        int l,r,largest;
	    	    	    	        char loc;
	    	    	    	        l=2*i;
	    	    	    	        r=(2*i+1);
	    	    	    	        if((l<=n)&&a[l]>a[i])
	    	    	    	           largest=l;
	    	    	    	        else
	    	    	    	           largest=i;
	    	    	    	        if((r<=n)&&(a[r]>a[largest]))
	    	    	    	           largest=r;
	    	    	    	        if(largest!=i)
	    	    	    	        {
	    	    	    	             loc=a[i];
	    	    	    	             a[i]=a[largest];
	    	    	    	             a[largest]=loc;
	    	    	    	             MAX_HEAPIFY(a, largest,n);
	    	    	    	        }
	    	    	    	    }
	    	    	    	    void BUILD_MAX_HEAP(char a[], int n)
	    	    	    	    {
	    	    	    	        for(int k = n/2; k >= 1; k--)
	    	    	    	        {
	    	    	    	            MAX_HEAPIFY(a, k, n);
	    	    	    	        }
	    	    	    	    }
	    	    	    	    void HEAPSORT(char a[],int n)
	    	    	    	    {
	    	    	    	     
	    	    	    	        BUILD_MAX_HEAP(a,n);
	    	    	    	        int i;
	    	    	    	        char temp;
	    	    	    	        for (i = n; i >= 2; i--)
	    	    	    	        {
	    	    	    	            temp = a[i];
	    	    	    	            a[i] = a[1];
	    	    	    	            a[1] = temp;
	    	    	    	            MAX_HEAPIFY(a, 1, i - 1);
	    	    	    	            cout<<a[1];
	    	    	    	        }
	    	    	    	        
	    	    	    	    }
	    	    	    	    void heapsort()
	    	    	    	    {
	    	    	    	    	
	    	    	    	    	HEAPSORT(srcString,srcLength);	
	    	    	    	    	taskPrioritySet(tidheapsort,101 );
	    	    	    	    	cout<<"\nHeap sort done:";
	    	    	    	    	
	    	    	    	    }
int main()
{
	sysTimestampEnable();
	if((myMsgQId_BUBBLE=msgQCreate(MAX_MSGS, MAX_MSG_LEN, MSG_Q_PRIORITY))==NULL)
	return ERROR;
	
	if((myMsgQId_QUICK=msgQCreate(MAX_MSGS, MAX_MSG_LEN,  MSG_Q_PRIORITY))==NULL)
	return ERROR;
	
	if((myMsgQId_HEAP=msgQCreate(MAX_MSGS, MAX_MSG_LEN, MSG_Q_PRIORITY))==NULL)
	return ERROR;
	
	if((myMsgQId_SHELL=msgQCreate(MAX_MSGS, MAX_MSG_LEN,  MSG_Q_PRIORITY))==NULL)
	return ERROR;
	
	taskCreateHookAdd((FUNCPTR)createHook);
	taskSwitchHookAdd((FUNCPTR)switchHook);
	taskDeleteHookAdd((FUNCPTR)deleteHook);
	
	
	
 tidquicksort= taskSpawn ("task_quick",99,0,4000,(FUNCPTR)quicksort,0,0,0,0,0,0,0,0,0,0);
 tidbubblesort= taskSpawn ("task_bubble",98,0,4000,(FUNCPTR)bubblesort,0,0,0,0,0,0,0,0,0,0);
 tidshellsort= taskSpawn ("task_shell",96,0,4000,(FUNCPTR)shellsort,0,0,0,0,0,0,0,0,0,0);
 tidheapsort= taskSpawn ("task_heap",97,0,4000,(FUNCPTR)heapsort,0,0,0,0,0,0,0,0,0,0);
 
 
 int bubbletime,quicktime,heaptime,shelltime;
 
  	STATUS ERR1;
  	ERR1 = msgQReceive( myMsgQId_BUBBLE,(char *) & bubbletime, sizeof(int), 1000);

  	STATUS ERR2;
  	ERR2 = msgQReceive( myMsgQId_QUICK,(char *) & quicktime, sizeof(int), 1000);

  	STATUS ERR3;
  	ERR3 = msgQReceive( myMsgQId_HEAP,(char *) & heaptime, sizeof(int), 1000);

  	STATUS ERR4;
  	ERR4= msgQReceive( myMsgQId_SHELL,(char *) & shelltime, sizeof(int), 1000);
  	STATUS ERR5;
  	  	ERR5 = msgQReceive( myMsgQId_BUBBLE,(char *) & bubblepre, sizeof(int), 1000);

  	  	STATUS ERR6;
  	  	ERR6 = msgQReceive( myMsgQId_QUICK,(char *) & quickpre, sizeof(int), 1000);

  	  	STATUS ERR7;
  	  	ERR7 = msgQReceive( myMsgQId_HEAP,(char *) & heappre, sizeof(int), 1000);

  	  	STATUS ERR8;
  	  	ERR8= msgQReceive( myMsgQId_SHELL,(char *) & shellpre, sizeof(int), 1000);


  	taskDelay(100);


 
 cout<<"\nQuick Ex Time:"<<std::abs((double)(quicktime)/sysTimestampFreq())<<" sec";

 cout<<"\nBubble Ex Time:"<<std::abs((double)(bubbletime)/sysTimestampFreq())<<" sec";

 cout<<"\nHeap Ex Time:"<<std::abs((double)(heaptime)/sysTimestampFreq())<<" sec";

 cout<<"\nSHell Ex Time:"<<std::abs((double)(shelltime)/sysTimestampFreq())<<" sec";
 
 cout<<"\nQuick preemptions:"<<quickpre;
 cout<<"\nBubble preemptions:"<<bubblepre;
 cout<<"\nHeap preemptions:"<<heappre;
 cout<<"\nShell preemptions:"<<shellpre;

 taskDelay(10000);
 taskCreateHookDelete((FUNCPTR)createHook);
 taskSwitchHookDelete((FUNCPTR)switchHook);
 taskDeleteHookDelete((FUNCPTR)deleteHook);
  
}
