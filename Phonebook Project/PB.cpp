#include <iostream>
#include<cstring>
#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

class dnode
{
    public:
        char number[100];
        char gmail[100];
        char name[100];
        dnode *prev,*next;
        
        dnode()
        {
//        	number = "";
//        	gmail = "";
//        	name ="";
        	next=NULL;
			prev=NULL;
		}
        dnode(char n[],char r[],char g[])
		{
			strcpy(name,n);
			strcpy(number,r);
			strcpy(gmail,g);
			next=NULL;
			prev=NULL;
		}
	friend class dlist;
};

class dlist
{
    dnode *head,*temp,*ptr;
    
    dnode *ptr1, *ptr2, *dup;
    
    public:
    dnode *prevn;
        
    void insert();
    void sort();
    int mailchck(char a[20]);
    void deletecontact(char n[20]);
    void deletesamenumber();
    void deletesamename();
    void deletesamegmail();
    void readContactsFromFile();
    void searchbyname(char p[20]);
    void searchbynumber(char no[30]);
    void searchbygmail(char g[20]);
	void writeContactsInFile();
	
        void accept();
        void display();
        void update(char ch[10]);
        dlist()
        {
            head=NULL;
            temp=NULL;
            ptr=NULL;
            ptr1=NULL;
            ptr2=NULL;
            dup=NULL;
        }
};

void dlist::accept()
{
//	dnode *temp = head;
//	int var;
	int k =0;
    char number[100];
    char gmail[100];
    char name[100];
    char ans;
	do
	{
	    cout<<"ENTER NAME      : ";
	    cin>>name;
	    // cin.getline (name,30);
	    cout<<"ENTER NUMBER    : ";
	    cin>>number;
		while(strlen(number)!=10)
		{
    		cout<<"ENTER VALID NUMBER  :";
    		cin>>number;
		}
	    do{cout<<"ENTER Email-ID: ";
        cin>>gmail;
        k=mailchck(gmail);
        }while(k!=1);
	    temp=new dnode(name,number,gmail);
	    if(head==NULL)
	    {
	        head=temp;
	    }
	    else
	    {
	       ptr=head;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;
			temp->prev=ptr;
	    }
		    cout<<"\nDO YOU WANT TO CONTINUE????????? (y/n) : ";
	    cin>>ans;
	}
	while(ans=='y');

}

int dlist::mailchck(char a[20])
{
    int j=0,i=0;
    while(a[i]!='\0')
    {
        if(a[i]=='@') 
		j++;
        i++;
    }
    if(j==1) 
	return 1;
    cout<<"Email id Invalid!!!\n";
    return 0;
}

void dlist::display()
{
    ptr=head;//start the node
	while(ptr!=NULL)//traverse till last
	{
			cout<<"\n\nNAME  ::\t"<<ptr->name<<endl;
			cout<<"NUMBER::\t+92-"<<ptr->number<<endl;
			cout<<"G-MAIL::\t"<<ptr->gmail<<endl;
			ptr=ptr->next;
	}
}

void dlist::insert()
{
    accept();
}

void dlist::sort()
{
    dnode *i,*j;
    int temp;
    char n[10];
    char n1[10];
    char n2[10];
    for(i=head;i->next!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            temp=strcmp(i->name,j->name);
            if(temp>0)
            {
               strcpy(n,i->name);
               strcpy(i->name,j->name);
               strcpy(j->name,n);

               strcpy(n2,i->number);
               strcpy(i->number,j->number);
               strcpy(j->number,n2);
               
			   strcpy(n1,i->gmail);
               strcpy(i->gmail,j->gmail);
               strcpy(j->gmail,n1);
            }
        }
    }
}

void dlist::deletecontact(char s[20])
{
    int c=0;
    ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(s,ptr->name)==0)
        {
            c=1;
            break;
        }
        else
        {
            c=2;
        }
        ptr=ptr->next;
    }
    
    if(c==1 && ptr!=head && ptr->next!=NULL)
    {
        ptr->prev->next=ptr->next;
       ptr->next->prev=ptr->prev;
       delete(ptr);
       cout<<"\nYOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }
    
    if(ptr==head)
    {
        head=head->next;
        head->prev=NULL;
        delete(ptr);
       cout<<"\nYOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }
    
    if(ptr->next==NULL)
    {
        ptr->prev->next=NULL;
        ptr->prev=NULL;
        delete(ptr);
       cout<<"\nYOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }
    
    if(c==2)
    {
        cout<<"\nYOUR ENTERED NAME IS NOT IN THE LIST...\n";
    }
}

void dlist::deletesamename()
{
    ptr1=head;
    while (ptr1 != NULL && ptr1->next != NULL) 
	{ 
	    ptr2 = ptr1; 
	    while (ptr2->next != NULL) 
	    { 
	        if (strcmp(ptr1->name,ptr2->next->name)==0)
	        { 
	            dup = ptr2->next; 
	            ptr2->next = ptr2->next->next; 
	            delete(dup); 
	        } 
	        else
	        {
	            ptr2 = ptr2->next; 
	    	}
	    }
	    ptr1 = ptr1->next; 
	} 
}

void dlist::deletesamegmail()
{
    ptr1=head;
    while (ptr1 != NULL && ptr1->next != NULL) 
	{ 
	    ptr2 = ptr1; 
	    while (ptr2->next != NULL) 
	    { 
	        if (strcmp(ptr1->gmail,ptr2->next->gmail)==0)
	        { 
	            dup = ptr2->next; 
	            ptr2->next = ptr2->next->next; 
	            delete(dup); 
	        } 
	        else
	        {
	            ptr2 = ptr2->next; 
	    	}
	    }
	    ptr1 = ptr1->next; 
	} 
}

void dlist::deletesamenumber()
{
	ptr1=head;
    while (ptr1 != NULL && ptr1->next != NULL) 
	{ 
	    ptr2 = ptr1; 
	    while (ptr2->next != NULL) 
	    { 
	        if (strcmp(ptr1->number,ptr2->number)==0)
	        { 
	            dup = ptr2->next; 
	            ptr2->next = ptr2->next->next; 
	            delete(dup); 
	        } 
	        else
	        {
	            ptr2 = ptr2->next; 
	    	}
	    }
	    ptr1 = ptr1->next; 
	}    
}

void dlist::readContactsFromFile()
{
	char aux[100];
	dnode *iterator = head;
	ifstream input("contacts.txt",ios::in);

	while (input.getline(aux, 100, '|'))
	{
		dnode *newContact = new dnode();
		
		for(int i =0; i<100;i++)
		{
			newContact->name[i] = aux[i];
		}
		
		input.getline(aux, 100, '|');
		for(int i =0; i<100;i++)
		{
			newContact->number[i] = aux[i];
		}

		input.getline(aux, 100, '|');
		for(int i =0; i<100;i++)
		{
			newContact->gmail[i] = aux[i];
		}

		if (head == NULL)
		{
			head = newContact;
			newContact->prev = NULL;
			newContact->next = NULL;
			iterator = head;
		}
		else 
		{
			iterator->next = newContact;
			newContact->prev = iterator;
			newContact->next = NULL;
			iterator = iterator->next;
		}
	}
	input.close();
}

void dlist::searchbyname(char na[10])
{
    ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(na,ptr->name)==0)
        {
            cout<<"NAME FOUND\n"<<endl;
            cout<<"CONTACT DETAILS ARE BELOW:\n"<<endl;
    	cout<<"\n\nNAME  ::\t"<<ptr->name;
		cout<<"\nNUMBER::\t+92-"<<ptr->number;
		cout<<"\nG-MAIL::\t"<<ptr->gmail;
        }
        ptr=ptr->next;
    }
}

void dlist::searchbynumber(char num[20])
{
	ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(num,ptr->number)==0)
        {
            cout<<"NUMBER FOUND\n"<<endl;
            cout<<"CONTACT DETAILS ARE BELOW:\n"<<endl;
    	cout<<"\n\nNAME  ::\t"<<ptr->name;
		cout<<"\nNUMBER::\t+92-"<<ptr->number;
		cout<<"\nG-MAIL::\t"<<ptr->gmail;  
        }
        ptr=ptr->next;
    }   
}

void dlist::searchbygmail(char gm[20])
{
    ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(gm,ptr->gmail)==0)
        {
            cout<<"G-MAIL FOUND\n"<<endl;
            cout<<"CONTACT DETAILS ARE BELOW:\n"<<endl;
    		cout<<"\n\nNAME  ::\t"<<ptr->name;
			cout<<"\nNUMBER::\t+92-"<<ptr->number;
			cout<<"\nG-MAIL::\t"<<ptr->gmail;  
        }
        ptr=ptr->next;
    }
}

void dlist::update(char n[20])
{
    char ans;
    int c,k;
    ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(n,ptr->name)==0)
        {
            
            do
            {
                cout<<"\nWHAT DO YOU WANT TO UPDATE?\n1.NAME\n2.PHONE NUMBER\n3.G-MAIL\n";
				cin>>c;
				switch(c)
            	{
	                case 1:
	                	cout<<"ENTER NEW-NAME : ";
	                	cin>>ptr->name;
	                	break;
	                case 2:
	                	cout<<"ENTER NEW PHONE-NUMBER : ";
	                	cin>>ptr->number;
	                	while(strlen(ptr->number)!=10)
						{
							cout<<"ENTER VALID NUMBER  : ";
							cin>>ptr->number;
						}
	               		break;
	                case 3:
	                	do{	                		
							cout<<"ENTER NEW G-MAIL : ";
				    	    cin>>ptr->gmail;
				        	k=mailchck(ptr->gmail);
				        }
						while(k!=1);
	                	break;
            	}
	            cout<<"\nDO YOU WANT TO CONTINUE UPDATING? (y/n) : ";
	            cin>>ans;
            }
			while(ans=='y' || ans=='Y');
        }
        ptr=ptr->next;
    }
}

void dlist::writeContactsInFile()
{
	dnode *iterator = this->head;
	ofstream output("contacts.txt",ios::out);

	while (iterator != NULL)
	{
		output << iterator->name << "|"; 
		output << iterator->number << "|"; 
		output << iterator->gmail;
		if (iterator->next != NULL)
		{
			output << "\n";
		}
		iterator = iterator->next;
	}

	output.close();
}
int main()
{
	char n[20];
	char name[10];
    char number[10];
    char gmail[20];
    
    dlist d1;
	d1.readContactsFromFile();
    
    char ans;
    int ch,a;
    
    cout<<"\n\n\t\t\t\t\t\t********************************\n";
    cout<<"\t\t\t\t\t\t********************************\n";
    cout<<"\t\t\t\t\t\t***                          ***\n";
    cout<<"\t\t\t\t\t\t***                          ***\n";
    cout<<"\t\t\t\t\t\t***                          ***\n";
    cout<<"\t\t\t\t\t\t***                          ***\n";
    cout<<"\t\t\t\t\t\t***                          ***\n";
    cout<<"\t\t\t\t\t\t***        PHONE BOOK        ***\n";
    cout<<"\t\t\t\t\t\t***        PHONE BOOK        ***\n";
    cout<<"\t\t\t\t\t\t***        PHONE BOOK        ***\n";
    cout<<"\t\t\t\t\t\t***        PHONE BOOK        ***\n";
    cout<<"\t\t\t\t\t\t***                          ***\n";
    cout<<"\t\t\t\t\t\t***                          ***\n";
    cout<<"\t\t\t\t\t\t***                          ***\n";
    cout<<"\t\t\t\t\t\t***                          ***\n";
    cout<<"\t\t\t\t\t\t***                          ***\n";
    cout<<"\t\t\t\t\t\t***                          ***\n";
    cout<<"\t\t\t\t\t\t***                          ***\n";
    cout<<"\t\t\t\t\t\t***                          ***\n";
    cout<<"\t\t\t\t\t\t********************************\n";
    cout<<"\t\t\t\t\t\t***************  ***************\n";
    cout<<"\t\t\t\t\t\t**************    **************\n";
    cout<<"\t\t\t\t\t\t***************  ***************\n";
    cout<<"\t\t\t\t\t\t********************************\n";
    cout<<"\n\n\t\tWHAT IS YOUR NAME?\n";
    cin.getline(name,20);
    cout<<"\n\n\t\t!!!!!!!!!!!!!!!!!!!!!!!   WELCOME "<<name<<"   !!!!!!!!!!!!!!!!!!!!!";
    cout<<"\n\n\n\t\tLET'S CREATE OUR PHONEBOOK "<<name<<"  \n\n";
    
    d1.accept();
    d1.sort();
    do
    {
	    cout<<"\n";
		cout<<"\t\t\t\t------------------------------------------------\n";
		cout<<"\t\t\t\t------------------------------------------------\n";
		cout<<"\t\t\t\t|          PHONE BOOK APPLICATION              |\n";
		cout<<"\t\t\t\t------------------------------------------------\n";
		cout<<"\t\t\t\t|                                              |\n";
		cout<<"\t\t\t\t|       [1]  DISPLAY YOUR PHONE BOOK           |\n";
		cout<<"\t\t\t\t|       [2]  INSERT NEW CONTACT                |\n";
		cout<<"\t\t\t\t|       [3]  UPDATE DETAILS ON EXISTING CONTACT|\n";
		cout<<"\t\t\t\t|       [4]  DELETE CONTACT                    |\n";
		cout<<"\t\t\t\t|       [5]  DELETE SAME NAME IN PHONEBOOK     |\n";
		cout<<"\t\t\t\t|       [6]  DELETE SAME NUMBER IN PHONEBOOK   |\n";
		cout<<"\t\t\t\t|       [7]  SEARCH                            |\n";
		cout<<"\t\t\t\t|                                              |\n";
		cout<<"\t\t\t\t------------------------------------------------\n";
		cout<<"\t\t\t\t|            [8]    Exit                       |\n";
		cout<<"\t\t\t\t------------------------------------------------\n";
	    cin>>ch;
	    
	    system("cls");
	    switch(ch)
	    {
		    case 2:
		    	d1.insert();
		    	d1.sort();
		    	break;
		    case 1:
		    // d1.sort();
		    	d1.display();
		    	break;
		    case 3:
		        cout<<"\n\nENTER THE NAME OF PERSON WHOSE DETAILS YOU WANT TO UPDATE...\n";
		        cin>>n;
		    	d1.update(n);
		    	d1.sort();
		    	break;
		    case 4:
		    	cout<<"\nENTER THE NAME YOU WANT TO DELETE FROM PHONEBOOK\n";
		    	cin>>name;
		    	d1.deletecontact(name);
		    	break;
		    case 5:
		    	d1.deletesamename();
		    	d1.display();
		    	break;
		    case 6:
		    	d1.deletesamenumber();
		    	d1.display();
		    	break;
		    case 7:
		    do
		    {
		    	cout<<"1.SEARCH BY NAME\n2.SEARCH BY NUMBER\n3.SEARCH BY GMAIL\n";
		    	cout<<"option : ";cin>>a;
			    switch(a)
			    {
			        case 1:
			        	cout<<"ENTER THE NAME TO BE SEARCHED\n";
			        	cin>>name;
			        	cout<<"\n";
			        	d1.searchbyname(name);
			        	break;
			        case 2:
			        	cout<<"ENTER NUMBER NAME TO BE SEARCHED\n";
			        	cin>>number;
			       		cout<<"\n";
			        	d1.searchbynumber(number);
			        	break;
			        case 3:
			        	cout<<"ENTER GMAIL TO BE SEARCHED\n";
			        	cin>>gmail;
			        	cout<<"\n";
			        	d1.searchbygmail(gmail);
			        	break;
			        default:
						cout<<"\nNO PROPER INPUT GIVEN.....\n";
			    }
			    cout<<"\nDO YOU WANT TO CONTINUE SEARCHING????????? (y/n) : ";
			    cin>>ans;
			}	
			while(ans=='y' || ans=='Y');
		
		    break;
		    case 8:
				d1.deletesamegmail();
		    	d1.display();
		    	break;
		    	
		    default:
				cout<<"\nNO PROPER INPUT GIVEN..\n";
	    }
	    cout<<"\n\nDO YOU WANT TO CONTINUE OPERATIONS????????? (y/n) : ";
	    cin>>ans;
	}
	while(ans=='y' || ans=='Y');
	d1.writeContactsInFile();
	
	return 0;
}