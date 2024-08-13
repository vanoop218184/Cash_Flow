#include <bits/stdc++.h>
using namespace std;

class Bank{
    public:
    string name;
    int totalAmount;
};


int getMin(int numBank,Bank array[])
{
    int index = 0;
    for (int i = 1; i < numBank; i++)
        if (array[i].totalAmount < array[index].totalAmount)
            index = i;
    return index;
}

int getMax(int numBank,Bank array[])
{
    int index = 0;
    for (int i = 1; i < numBank; i++)
        if (array[i].totalAmount > array[index].totalAmount)
            index = i;
    return index;
}


void minimizeFlow(int numBank,Bank array[]){
     int miniAmount = getMin(numBank,array);
     int maxiAmount = getMax(numBank,array);
     
     if(array[miniAmount].totalAmount==0&&array[maxiAmount].totalAmount==0) return;
     
     int mini = min(-array[miniAmount].totalAmount,array[maxiAmount].totalAmount);
     
     array[miniAmount].totalAmount += mini;
     array[maxiAmount].totalAmount -= mini;
     
     cout<<array[maxiAmount].name <<" Pays Rs."<<mini<<" to "<<array[miniAmount].name<<endl;
     
     minimizeFlow(numBank,array);
}

int main() {
	// your code goes here
	
	int numBank;
	cin>>numBank;
	cout<<"Enter the number of Person involve in Transactions: "<<numBank<<endl;
	Bank array[numBank];
	
	unordered_map<string,int>mp;  //map--> name with index
	
	for(int i=0;i<numBank;i++){
	    string s1;
	    cin>>s1;
	    cout<<"Enter the name of "<<(i+1)<<"th Person: "<<s1<<endl;
	    array[i].name = s1;
	    mp[s1] = i;
	}
	
	vector<vector<int>>transactions(numBank,vector<int>(numBank,0));
	int numberOfTransactions;
	cin>>numberOfTransactions;
	cout<<endl<<"Enter the number of Transactions: "<<numberOfTransactions<<endl;
	
	for(int i=0;i<numberOfTransactions;i++){
	     
	    string from,to;
	    int amount;
	    cin>>from>>to>>amount;
	    cout<<(i+1)<<"th Transaction --> "<<from<<" Pays Rs."<<amount<<" to "<<to<<endl;
	    
	    transactions[mp[from]][mp[to]] = amount;
	}
	
	for(int i=0;i<numBank;i++){
	     int value = 0;
	     for(int j=0;j<numBank;j++){
	          value = value + transactions[j][i] - transactions[i][j];
	     }
	     array[i].totalAmount = value;
	}
	
	cout<<endl<<"Minimum Required transactions:"<<endl;
	minimizeFlow(numBank,array);
	return 0;

}

/* Input Format
5
Bank_1
Bank_2
Bank_3
Bank_4
Bank_5
7
Bank_1 Bank_3 1000
Bank_1 Bank_5 2000
Bank_2 Bank_4 3000
Bank_3 Bank_5 4000
Bank_4 Bank_1 5000
Bank_5 Bank_2 6000
Bank_3 Bank_2 7000
*/
