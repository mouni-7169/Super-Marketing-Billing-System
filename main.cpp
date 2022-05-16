#include<iostream>
#include<fstream>
using namespace std;
class shopping
{
    private:
    int pcode;
    float price;float dis;
    string pname;
    public:
    void menu();
    void admin();void  buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};
void shopping ::menu()
{
    m:
    int choice;
    string email;
    string password;
    
    cout<<"\t\t\t____________________________\n";
    cout<<"\t\t\t     Supermarket Main Menu  \n";
    cout<<"\t\t\t                            \n";
    cout<<"\t\t\t____________________________\n";
    cout<<"\t\t\t|  1) Administrator         |\n";
    cout<<"\t\t\t|                           |\n";
    cout<<"\t\t\t|  2) Buyer                 |\n";
    cout<<"\t\t\t|                           |\n";
    cout<<"\t\t\t|  3) Exit                  |\n";
    cout<<"\t\t\t Please select!";
    cin>>choice;
    switch(choice)
    {
        case 1:
        {
        cout<<"\t\t\t please login   \n";
        cout<<"\t\t\t Enter email    \n";
        cin>>email;
        cout<<"\t\t\tPassword  \n";
        cin>>password;

        if(email=="mounikareddy@email.com" && password=="mouni@123")
          {
              admin();
          }
        else
          {
              cout<<" Invalid email/password";
          }
          break;
          }
          case 2:
          {
              buyer();
          }
          case 3:
           {
               exit(0);
           }
           default:
           {
               cout<<"please select from the given options";
           }
          

    }
    goto m;


}
void shopping :: admin()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator memu";
    cout<<"\n\n\t\t\t|_______1)Add product_________|";
    cout<<"\n\n\t\t\t|                             |";
    cout<<"\n\n\t\t\t|____2)Modify the product_____|";
    cout<<"\n\n\t\t\t|                             |";
    cout<<"\n\n\t\t\t|_______3)Delete product______|";
    cout<<"\n\n\t\t\t|                              |";
    cout<<"\n\n\t\t\t|____4)Back to maian menu_____|";
    cout<<"\n\n\n\t\t  Pleas enter your choice";
    cin>>choice;
    switch (choice)
    {
      case 1:
         add();
         break;
      case 2:
         edit();
         break;
     case 3:
         rem();
         break;
     case 4:
         menu();
         break;
     default:
     cout<<"invalid choice";
    }
    goto m;

}
void shopping :: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t Buyer   \n";
    cout<<"\t\t\t__________\n";
    cout<<"                 \n";
    cout<<"\t\t\t\t 1)Buy product\n";
    cout<<"                       \n";
    cout<<" \t\t\t2)Go back      \n";
    cout<<"\t\t\tEnter your choice\n";
    cin>>choice;
    switch(choice)
    {
       case 1:
       receipt();
       break;
       case 2:
       menu();
       default:
       cout<<"Invaalid choice"; 
    }
    goto m;
}
void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;
    cout<<" \n\n\n\t\t\t Add new product";
    cout<<" \n\n\t Product code";
    cin>>pcode;
    cout<<"\n\n\n\t\t Name of the product ";
    cin>>pname;
    cout<<"\n\n\t\t  Price of the product";
    cin>>price;
    cout<<"n\n\t Discount on product";
    cin>>dis;
    data.open("database.txt",ios::in);
    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
      data>>c>>n>>p>>d;
      while(!data.eof())
      {
          if(c==pcode)
          {
              token++;
          }
          data>>c>>n>>p>>d;
      }
      data.close();
    }
    if(token==1)
    goto m;
    else
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    cout<<"\n\n\t\t Record inserted!";

}
void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int token;
    int c;
    float p;
    float d;
    string n;
    cout<<" \n\nt Modify the record";
    cout<<" \n\n\t Enter product code";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n File dpesn't exit!";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\n\t Enter product newcode:";
                cin>>c;
                cout<<"\n\n\t Name of the product";
                cin>>n;
                cout<<"\n\n\t price";
                cin>>p;
                cout<<" \n\n\t Discount";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\nt Record edited";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        {
            cout<<"\n\n Record not found sorry!";
        }

    }
    
}
void shopping:: rem()
{
fstream data, datal;
int pkey;
int token=0;
cout<<"\n\t Delete product";
cout<<"\n\t Product code :";
cin>>pkey;
data.open("database.txt", ios::in);
if (!data)
cout<<"File doesnt exist";
else
{
  datal.open("databasel.txt", ios::app|ios::out);
   data>>pcode>>pname>>price>>dis;
     while(!data.eof())
     {
       if (pcode==pkey)
        {
          cout<<"\n\t Product deleted succesfully";
          token++;
        }
       else
        {
         datal<<" "<<pcode<<""<<pname<<""<<price<<" "<<dis<<"";
        }
      data>>pcode>>pname>>price>>dis;
     }
     datal.close();
     remove("database.txt");
     rename ("databasel.txt", "database. txt") ;
   if (token==0)
   {
   cout<<"\n Record not found";
   }
}
}
void shopping:: list()
{
    fstream data;
    data.open ("database.txt", ios::in);
    cout<<"\n\n|_________________\n";
    cout<<"ProNo\t\tName\t\tPric\n";
    cout<<"\n\n_________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"  "<<pname<<"  "<<price<<" ";
    
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
    
}

void shopping:: receipt()
{
    m:
    fstream data;    
    
    int arrc[100];
    int arrq[100];
    char choice;
     int c=0;
    float amount=0;
    float dis=0;
    float total=0;
    
    cout<<"\n\n\t\t\t\t RECEIPT ";
    data.open ("database.txt", ios::in);
    if (!data)
    {
        cout<<"\n Empty database";
    }
    
    else{
        data.close();
        
        list();
        cout<<"\n________________\n";
        cout<<"\n                                            \n";
        cout<<"\n  ___________Please place the order _________\n";
        cout<<"\n                                            \n";
        cout<<"\n________________\n";
        do
        {
            
            cout<<"\n\nEnter Product code :";
            cin>>arrc[c];
            cout<<"\n\nEnter the product quantity :";
            cin>>arrq[c];
            for (int i=0;i<c;i++)
            {
                if (arrc[c]==arrc[i])
                {
                    cout<<" \n\n Duplicate product code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout<<" \n\n Do you want to buy another product? if yes then press y else no";
            cin>>choice;
        }
        while(choice=='y');
        
        cout<<"\n\n\t\t\t_________RECEIPT_________\n";
        cout<<"\nProduct No\t Product Name\t Product quantity\tprice\tAmount\tAmount with discount\n";
        
        for (int i=0;i<c;i++)
        {
            data.open ("database. txt", ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if (pcode==arrc[i])
                {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100) ;
                    total=total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
        
    }
          
    cout<<"\n\n________________";
    cout<<"\n Total Amount :"<<total;
    
}
int main()
{
    shopping s;
    s. menu();
}

