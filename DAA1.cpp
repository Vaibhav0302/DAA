// Greedy or Fractional

#include<iostream>
using namespace std;

void sort(double ratio[],double profit[],double weight[],int n){
	
	int counter=1;
	while(counter<n){
		for(int i=0;i<n-counter;i++){
			if(ratio[i]<ratio[i+1]){
				int temp=ratio[i+1];
				ratio[i+1]=ratio[i];
				ratio[i]=temp;
				
				int temp2=profit[i+1];
				profit[i+1]=profit[i];
				profit[i]=temp2;
				
				int temp3=weight[i+1];
				weight[i+1]=weight[i];
				weight[i]=temp3;
			}
		}
		counter++;
	}
}

void ratiopw(double profit[],double weight[],double ratio[],int n)
{
	for (int i=0;i<n;i++){
		ratio[i]=(profit[i]/weight[i]);
	}
	
}



int main()
{
	int n;
	double tw;
	double weight[n];
	double profit[n];
	                           //take input of n from user
	n=3;
	/*cout<<"Enter no of elements:"<<endl;
        cin>>n;

        
		//enter their weights
        cout<<"Enter Weights of the elemnts:"<<endl;
        for(int i=0; i<n; i++)
        {
            cin>>weight[i];          
        }
		//enter their profits
        cout<<"Enter profits of the elemnts:"<<endl;
        for(int i=0; i<n; i++)
        {
            cin>>profit[i];
        }
        
        cout<<"Enter total capacity of sack:"<<endl;
        cin>>tw;*/
	
	double profit[n]={60,100,120};
	double weight[n]={10,20,30};
	double ratio[n]={0,0,0};
	int xi[n];
	ratiopw(profit,weight,ratio,n);
	sort(ratio,profit,weight,n);
	
	/*for(int i=0;i<n;i++){
		cout<<ratio[i]<<endl;
		cout<<profit[i]<<endl;
		cout<<weight[i]<<endl;
	}*/
	
	double profitf=0;
	
	for(int i=0;i<n;i++){
		if(weight[i]<tw){
			tw=tw-weight[i];
			xi[i]=1;
			profitf=profitf+profit[i];
		}
		else{
			
			xi[i]=tw/weight[i];
			profitf=profitf+ ((tw/weight[i])*profit[i]);
			tw=tw-(tw/weight[i]);
		}
	}
	
	cout<<profitf;

}
