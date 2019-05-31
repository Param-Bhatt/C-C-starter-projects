//Assumed that at a time , maximum number of books is 25
#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
 using namespace std;
 class Book
 {
	float price;
    static int trans;
    int stock;
    int book_id;
    char author[30];
    char title[30];
    char publ[30];
	
	public:
		static void add(Book b[])
        {
        int n;
		A: //branch 
		cout<<"\n\tHow many books do you want to add (atmost 25)?";
		cin>>n;
		if(n>25){
			cout<<"\n\t Maximum number of books allowed exceeded";
			goto A;
		}
		static int i=0;
		do{
			cout<<"\nEnter the details of the book\n";
			cout<<" Title of book:\t"; //key
			cin>>b[i].title;
			cout<<"Author :\t";
			cin>>b[i].author;
			cout<<"Publication :\t";
			cin>>b[i].publ;
			cout<<"Price :\t";
			//pay:
			cin>>b[i].price;
			//if(!isdigit(b[i].price)) goto pay;
			//stay:
			cout<<"Stock:\t";
			cin>>b[i].stock;
			//if(!isdigit(b[i].stock)) goto stay;
			i++;
		}while(i<n);
        }
        void view(){
        	cout<<"BOOK :\t"<<title;
			cout<<"\nAuthored by\t"<<author;
			cout<<"\nPublished by\t"<<publ;
			cout<<"\nhaving cost:\t"<<price;
        	cout<<"Stock:\t"<<stock;
		}
        void display(Book b[]) // function only for seeing a record
        {
        	int flag,i,n=25;
        	char name[30];
        	cout<<"Enter the book name that you want to view";
        	cin>>name;
        	for(i=0;i<n;i++){
            	if(strcmp(name,b[i].title)==0){
            		cout<<"BOOK :\t"<<b[i].title;
					cout<<"\nAuthored by\t"<<b[i].author;
					cout<<"\nPublished by\t"<<b[i].publ;
					cout<<"\nhaving cost:\t"<<b[i].price;
        			cout<<"Stock:\t"<<b[i].stock;
        			flag=0;
        		}
        		else{
        			flag=1;
				}
				
			}
			if(flag==1){
				cout<<"\nBook not found\n";
			}
        	
        }
        void update(Book b[])
        {
        int i,flag=0;
        int price;
        char name[30];
        int n=25; // where n is total number of books avialable
        cout<<"Enter the book name that you want to update";
        cin>>name;
        for(i=0;i<n;i++){
            if(strcmp(name,b[i].title)==0)
            {
                cout<<"Book Found\n";
                cout<<"Add the new cost\n";
                cin>>price;
                cout<<"Reocord updated successfully\n";
                flag=0;
            }
            else
                flag=1;
            }
            if(flag=1)
            {
                cout<<"Book not found\n";
            }
        }
        void search(Book b[])
        {
        int i,flag=0;
        char name[30];
    	int n=25;
        cout<<"Enter the book name to b searched\n";
        cin>>name;
            for(i=0;i<n;i++)
            {
                if(strcmp(name,b[i].title)==0)
                {
                    cout<<"Book found\n";
                    b[i].view();
                    flag=0;
                }
                else{
                	flag=1;
                }
                    
                if(flag=1)
                {
                	cout<<"Book not found\n";
                }
            }     
    	}
        void purchase(Book b[])
        {
            int i,flag=0;
            int n=25;
        	char name[30];
			char ans;
            int trans;
            cout<<"Enter the book name:\t";
            cin>>name;
            for(i=0;i<n;i++)
            {
                if(strcmp(name,b[i].title)==0)
                {
                    cout<<"Book is available\n";
                    cout<<"Would you like to purchase it\n";
                    cin>>ans;
                    if(ans =='y' || ans == 'Y')
                    {
                        cout<<"Book price :\t"<<b[i].price;
                        trans++;
                        stock--;
                        cout<<"\n\tPurchase successful\n";
                        flag=0;
                    }
                    else
                    {
                        cout<<"better luck next time\n";
                     
                    }
                }         
                else
                {
                    flag=1;
            	}
            }
            if(flag=1)
            {
                cout<<"book not available \n";
            }
                
        }
                          
        
        static void transactions()
            {
		        int trans;
                cout<<"\n Successful transactions are = "<<trans;
	    	}
    };
    
    //******************************************************
    
    int main() {
	Book B[25];
	int i ;
	char ch;
	char a;
	i = 0;
	do {

		cout<<"\n1.Add a book";
		cout<<"\n2.To display a book record";
		cout<<"\n3.Update a book a record";
		cout<<"\n4.To search for a record";
		cout<<"\n5.To purchase a book";
		cout<<"\n6.Diplay transactions";
		cout<<"\nEnter what do you want to do?\t";
		take: //branch to take the task again
		cin>>ch;
		cout<<ch;
		if(ch<49||ch>54){
			cout<<"Please enter a number from 1-6";
			goto take;
		}
		switch(ch) {
			case '1': //to add a record
				B[i].add(B);
				i++;
				break;
      		case '2': //to display a record
        		B[i].display(B);
        		i++;
        		break;
			case '3': //to update the price of a book
				B[i].update(B);
				break;
			case '4': //to search for a particular record
				B[i].search(B);
				break;
			case '5': //to purchase a book
				B[i].purchase(B);
				break;
			case '6': //to show the transactions
				B[i].transactions();
				break;
		
			default:
				cout<<"\nSorry, you entered wrong choice \n Please try again";
		}
		
		cout<<"\n Do you want to continue?\n1.Y for Yes\n 2.Any other key to quit";
		cin>>a;
	

	} while(a=='Y');

	return 0;
}
