#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
class List
{
    private:
        struct node *head;
    public:
        List()
        {
            head=NULL;
        }
        node* c_node(int num)
        {
            struct node *temp;
            temp=new (struct node);
            temp->data=num;
            temp->next=NULL;
            return temp;
        }
        void infirst(int num)
        {
            struct node *temp;
            temp=c_node(num);
            if(head==NULL)
                head=temp;
            else
            {
                temp->next=head;
                head=temp;
            }
        }
        void inend(int num)
        {
            struct node *temp,*monk;
            temp=c_node(num);
            monk=head;
            if(head==NULL)
                head=temp;
            else
            {
                while(monk->next!=NULL)
                {
                    monk=monk->next;
                }
                monk->next=temp;
            }
        }
        void inmid(int num,int pos)
        {
            struct node *temp, *monk, *b;
            temp=c_node(num);
            monk=head;
            int c=1;
            if (pos==1)
            {
                if(head==NULL)
                    head=temp;
                else
                {
                    temp->next=head;
                    head=temp;
                }
            }
            else
            {
                while(c!=pos-1)
                {
                    monk=monk->next;
                    c++;
                }
                temp->next=monk->next;
                monk->next=temp;
            }
        }
        void Delete()
        {
            int num;
        	struct node *monk, *b;
  			monk=head;
  			if(head==NULL)
            {

                cout<<"The list is Empty\n";
            }
            else{
                    cout<<"Enter the element to delete\n";
            cin>>num;
                if(head->data==num)
  			{
  				head=head->next;
  			}
  			else
  			{
  				while(monk->next!=NULL && monk->data!=num)
  				{
  					b=monk;
  					monk=monk->next;
  				}
  				if(monk->next==NULL&&monk->data!=num)
                {

                    cout<<"Element not found";
                }
                else{
                    b->next=monk->next;
                }

  			}
            }


        }
        void rev()
        {
            struct node *monk, *b, *c;
            monk=head;
            while(monk!=NULL)
            {
                b=monk->next;
                monk->next=c;
                c=monk;
                monk=b;
            }
            head->next=NULL;
            head=c;
        }
        void display()
        {
            struct node *temp;
            temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
};
int main()
{
    List l;
    int ch,a;
    while(1)
    {
    cout<<"Enter the choice \n 1. INSERT IN START\n 2. INSERT IN END\n 3. INSERT IN POSITION\n 4. DELETE\n 5. REVERSE\n 6. DISPLAY \n";
    cin>>ch;
    switch(ch)
    {
    	case 1:
    	cout<<"Enter the element to insert \n";
    	cin>>a;
    	l.infirst(a);
    	break;
    	case 2:
    	cout<<"Enter the element to insert \n";
    	cin>>a;
    	l.inend(a);
    	break;
    	case 3:
    	cout<<"Enter the element to insert \n";
    	cin>>a;
    	cout<<"enter the position \n";
    	int p;
    	cin>>p;
    	l.inmid(a,p);
    	break;
    	case 4:


    	l.Delete();
    	break;
    	case 5:
    	l.rev();
    	break;
    	case 6:
    	l.display();
    	break;
    	default:
    	return 0;
    }
	}
}
