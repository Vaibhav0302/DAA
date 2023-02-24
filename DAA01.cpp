//Vaibhav Ajit Deshmukh   TI74

//0/1 knapsack or Dynamic

# include<iostream>
using namespace std;

void knapsack(int n, float weight[], float profit[], float capacity)
{
	int i,j;
	float tp,u;
	u=capacity;
	float xi[10];
	
	for(i=0;i<n;i++)
	{
		xi[i]=0.0;
	}
	
	for(i=0;i<n;i++)
	{
		if(weight[i]>u)
		{
			break;
		}
		else
		{
			xi[i]=1.0;
			tp=tp+profit[i];
			u=u-weight[i];
		}
	}
	
	if(i<n)
	{
		xi[i]=u/weight[i];
	}
	
	tp=tp+(xi[i] * profit[i]);
	
	cout<<"\nThe vector is: ";
	for(i=0;i<n;i++)
	{
		cout<<xi[i]<<" ";
	}
	
	cout<<"\nTotal profit is: "<<tp;
}

int main()
{
	float weight[20],profit[20],ratio[20];
	int i,n,j,temp,capacity;
	
	cout<<"\nEnter the number of elements: ";
	cin>>n;
	
	cout<<"\nEnter the weights of elements: ";
	for(i=0;i<n;i++)
	{
		cin>>weight[i];
	}
	
	cout<<"\nEnter the profits of elements: ";
	for(i=0;i<n;i++)
	{
		cin>>profit[i];
	}
	
	cout<<"\nEnter the capacity of sack: ";
	cin>>capacity;
	
	for(i=0;i<n;i++)
	{
		ratio[i]=profit[i]/weight[i];
	}
	
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(ratio[j]>ratio[j+1])
			{
				swap(ratio[j],ratio[j+1]);
				swap(weight[j],weight[j+1]);
				swap(profit[j],profit[j+1]);
			}
		}
	}
	cout<<"\n P/W ratio is: ";
	for(i=0;i<n;i++)
	{
		cout<<ratio[i]<<" ";
	}
	
	knapsack(n,weight,profit,capacity);	
	
}
