#include<stdio.h> 
#include<conio.h>
typedef struct 
{ 
      int ProcessId, ArrivalTime, BurstTime, Priority;
      int A, R; 
}Process_Structure; 
int Queue(int t) 
{ 
      if(t == 0 || t == 1 || t == 2 || t == 3) 
      { 
            return 1; 
      } 
      else
      {
            return 2; 
      }
} 
int main() 
{ 
      int Limit, Count, TempProcess, Time, M, N; 
      Process_Structure Temp; 
      printf("Enter Total Number of Processes:\t"); 
      scanf("%d", &Limit);  
      Process_Structure Process[Limit]; 
      for(Count = 0; Count < Limit; Count++) 
      { 
            printf("\nProcess ID:\t"); 
            scanf("%d", &Process[Count].ProcessId); 
            printf("Arrival Time:\t"); 
            scanf("%d", &Process[Count].ArrivalTime); 
            printf("Burst Time:\t"); 
            scanf("%d", &Process[Count].BurstTime); 
            printf("Process Priority:\t"); 
            scanf("%d", &Process[Count].Priority); 
            TempProcess = Process[Count].Priority; 
            Process[Count].A = Queue(TempProcess);
            Process[Count].R = 0; 
      }
      Time = Process[0].BurstTime; 
      for(N = 0; N < Limit; N++) 
      { 
            for(Count = N; Count < Limit; Count++) 
            { 
                  if(Process[Count].ArrivalTime < Time) 
                  {
                        Process[Count].R = 1; 
                  } 
            } 
            for(Count = N; Count < Limit - 1; Count++) 
            {
                  for(M = Count + 1; M < Limit; M++) 
                  { 
                        if(Process[Count].R == 1 && Process[M].R == 1) 
                        { 
                              if(Process[Count].A == 2 && Process[M].A == 1) 
                              { 
                                    Temp = Process[Count]; 
                                    Process[Count] = Process[M]; 
                                    Process[M] = Temp; 
                              } 
                        } 
                  } 
            } 
            for(Count = N; Count < Limit - 1; Count++) 
            { 
                  for(M = Count + 1; M < Limit; M++) 
                  {
                        if(Process[Count].R == 1 && Process[M].R == 1) 
                        { 
                              if(Process[Count].A == 1 && Process[M].A == 1) 
                              { 
                                    if(Process[Count].BurstTime > Process[M].BurstTime) 
                                    { 
                                          Temp = Process[Count]; 
                                          Process[Count] = Process[M]; 
                                          Process[M] = Temp; 
                                    } 
                                    else 
                                    { 
                                          break; 
                                    } 
                              } 
                        } 
                  } 
            } 
            printf("\nProcess[%d]:\tTime:\t%d To %d\n", Process[N].ProcessId, Time, Time + Process[N].BurstTime); 
            Time = Time + Process[N].BurstTime; 
            for(Count = N; Count < Limit; Count++) 
            { 
                  if(Process[Count].R == 1) 
                  { 
                        Process[Count].R = 0; 
                  } 
            } 
      } 
 return 0; 
}
