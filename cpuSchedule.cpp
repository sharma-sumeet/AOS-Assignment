#include<iostream>
#include<conio.h>
using namespace std;
class cpuschedule
{
int n,bu[10],p[10],weight[10];
float twt,awt,wt[10];
public:
void Getdata(); //Getting the No of processes & burst time
void Fcfs(); //First come First served Algorithm
void Sjf(); //Shortest job First Algorithm
void Priority(); //Priority Algorithm
void Wrr(); //weighted round robin algorithm
void RoundRobin(); //Round Robin Algorithm
};
void cpuschedule::Getdata()
{
    int i;
    cout<<"enter the number of process";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<" Enter The BurstTime for Process p"<<i<<"= ";
        cin>>bu[i];
    }
}
void cpuschedule::Fcfs()
{
    int i;
    wt[0]=0;
    for(i=1;i<n;i++)
    {
      wt[i]=bu[i-1]+wt[i-1] ; //each process waiting time is the sum of burst time and wait time of earlier process
    }
    twt=0;
    cout<<"\n process \t\t waiting time";
    for(i=0;i<n;i++)
    {cout<<"\nP"<<i<<"\t\t"<<wt[i];
       twt=twt+wt[i];
    }
    awt=twt/n;
    cout<<"\ntotal waiting time="<<twt;
    cout<<"\naverage waiting time="<<awt;
}
void cpuschedule::Sjf()
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)//we sort process according to their burst time
        {
            if(bu[j]>bu[j+1])
            {
                temp=bu[j+1];
                bu[j+1]=bu[j];
                bu[j]=temp;
            }
        }
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bu[i-1];
    }
    cout<<"\n process \t\t waiting time";
    for(i=0;i<n;i++)
    {cout<<"\nP"<<i<<"\t\t"<<wt[i];
       twt=twt+wt[i];
    }
    awt=twt/n;
    cout<<"\ntotal waiting time="<<twt;
    cout<<"\naverage waiting time="<<awt;
}
void cpuschedule::Priority()
{
    int i,j,temp1,temp2;
    for(i=0;i<n;i++)
    {
        cout<<" Enter The priority for Process p"<<i<<"= ";
        cin>>p[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)//we sort process according to their priority
        {
            if(p[j]>p[j+1])
            {
                temp1=bu[j+1];
                temp2=p[j+1];
                bu[j+1]=bu[j];
                p[j+1]=p[j];
                bu[j]=temp1;
                p[j]=temp2;
            }
        }
    }
    //for(i=0;i<n;i++)
    //   cout<<bu[i];
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bu[i-1];
    }
    cout<<"\n process \t\t waiting time";
    for(i=0;i<n;i++)
    {cout<<"\nP"<<i<<"\t\t"<<wt[i];
       twt=twt+wt[i];
    }
    awt=twt/n;
    cout<<"\ntotal waiting time="<<twt;
    cout<<"\naverage waiting time="<<awt;
}
void cpuschedule::RoundRobin()
{
    int i,j,ts,flag;
    for(i=0;i<n;i++)
        wt[i]=0;
    while(1)
    {
        for(i=0;i<n;i++) //we serve each process for time slice of 3
        {
            if(bu[i]<3)     // if burst time is less than 2 time slice will be burst time
            {
                ts=bu[i];
            }
            else
            {
                ts=3;
            }
            bu[i]=bu[i]-ts;

            for(j=0;j<n;j++) //update the weights of remaining process
            {
                if (bu[j]==0) continue;
                if (i!=j)
                {
                    wt[j]=wt[j]+ts;

                }
            }
            cout<<wt[0];
        }
        for(i=0,flag=1;i<n;i++)
        {
            if (bu[i]!=0) flag=0;
        }
        if (flag==1) break;
    }
    cout<<"\n process \t\t waiting time";
    for(i=0;i<n;i++)
    { cout<<"\nP"<<i<<"\t\t"<<wt[i];
       twt=twt+wt[i];
    }
    awt=twt/n;
    cout<<"\ntotal waiting time="<<twt;
    cout<<"\naverage waiting time="<<awt;
}
void cpuschedule::Wrr()
{
    int i,j,ts,flag,x;
    for(i=0;i<n;i++)
    {
        cout<<" Enter The weight for Process p"<<i<<"= ";
        cin>>weight[i];
    }

    for(i=0;i<n;i++)
        wt[i]=0;
    while(1)
    {
        for(i=0;i<n;i++) //we serve each process for time slice of 2
        {
            if(bu[i]<3)     // if burst time is less than 2 time slice will be burst time
            {
                ts=bu[i];
            }
            else
            {
                ts=3;
            }
            bu[i]=bu[i]-ts;
            weight[i]--;
            for(j=0;j<n;j++) //update the weights of remaining process
            {
                if(bu[j]==0) continue;
                if (i==j)continue;
                wt[j]=wt[j]+ts;
            }
            x=(i+1)%n;
            if (weight[i]>=weight[x]) i--;
        }
        for(i=0,flag=1;i<n;i++)
        {
            if (bu[i]!=0) flag=0;
        }
        if (flag==1) break;
    }
    cout<<"\n process \t\t waiting time";
    for(i=0;i<n;i++)
    {cout<<"\nP"<<i<<"\t\t"<<wt[i];
       twt=twt+wt[i];
    }
    awt=twt/n;
    cout<<"\ntotal waiting time="<<twt;
    cout<<"\naverage waiting time="<<awt;
}
int main()
{   int c;
    cout<<"enter your choice\n";
    cout<<"1. first come first serve\n";
    cout<<"2. Shortest job first\n";
    cout<<"3. priority scheduling\n";
    cout<<"4. round robin\n";
    cout<<"5. weighted round robin\n";
    cout<<"Enter your choice";
    cin>>c;
    cpuschedule cp;
    switch(c)
    {
        case 1:
            cp.Getdata();
            cp.Fcfs();
            break;
        case 2:
            cp.Getdata();
            cp.Sjf();
            break;
        case 3:
            cp.Getdata();
            cp.Priority();
            break;
        case 4:
            cp.Getdata();
            cp.RoundRobin();
            break;
        case 5:
            cp.Getdata();
            cp.Wrr();
            break;
        default:
            cout<<"wrong entry";
    }
    getch();
    return 0;
}
