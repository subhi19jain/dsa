#include <iostream>
using namespace std;
 int h[10];

void  insert(int h[10],int val)
{  // int loc;
    int loc=val%10;
    int x =loc;

    while(h[loc]!=-1){
        loc=(loc+1)%10;
        if(loc==x){
            cout<<"table is full "<<endl;
            return;
        }
    }
    h[loc]= val;
}

//     if(hashtable[loc]==-1)
//     {
//         hashtable[loc]=val;
//     }
//     else{

//         while((loc++)%10!=x)
//         {
//             if (hashtable[loc%10]==-1)
//             {
//                 hashtable[loc]=val;
//                 break;
//             }
//         }
//     return ;
//     }
// }



void display(int h[10])
 { //  int n= 10;
    for (int i =0;i<10;i++)
    {
        if (h[i]!=-1){
             cout<<h[i]<<endl;
        }
       else{
        cout<<"-1"<<endl;
       }
    }
    //cout<<endl;
   return ;
}

void del(int h[10],int val)
{
    int loc=val%10;
    int x =loc;

     while(h[loc]!=-1){
        if (h[loc]==val){
            h[loc]=-2;
            return ;
        }
        loc=(loc+1)%10;
        if(loc==x){
            break;
        }
     }
     cout<<"value not found "<<endl;

}

int main()
{
    int h[10];
    for(int i=0;i<10;i++){
        h[i]=-1;
    }
    int ch,key;
    do{

        cout<<"1.insert"<<endl;
        cout<<"2.display"<<endl;
        cout<<"3.delete"<<endl;
        cout<<"4.exit"<<endl;
        cout<<"enter choice"<<endl;
        cin>>ch;

        switch(ch)
        {

            case 1:
            cout<<"enter the value to be inserted "<<endl;
            cin>>key;
            insert(h,key);
            break;

            case 2:
            cout<<"hastable"<<endl;
            display(h);
            break;

            case 3:
            cout<<"enter the value to be deleted "<<endl;
            cin>>key;
            del(h,key);
            break;

            case 4:
           break;
        }

}while(ch!=4);
    //  cout <<"the value to be inserted. "<<endl;
    //  cin>>val;
    // insert(hashtable,val);
    // display(hashtable);

return 0;
}