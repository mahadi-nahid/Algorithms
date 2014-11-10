/*--------------------------
/
/   Vul Ase Kaj kore Na..
/
/----------------------------------------------------*/

#include <cstdlib> // Provides size_t and NULL
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct listnode
{
    struct listnode * next;
    unsigned long     value;
} ;

struct listnode *radixsort (struct listnode *data, int a, int k)
{
    struct listnode *front [a], *rear [a], *cursor;
    int i=0 , j = 0, leastSigDig,base10num;
    if (data == NULL)
    {
        return data;
    }

    for (i; i<k; i++)
    {
        base10num= pow(a,i);
        cursor = data;
        for (j=0; j<a; j++)
        {
            front [j] = NULL;
            rear [j] = NULL;
        }
        while (cursor != NULL)
        {
            leastSigDig = ((cursor->value)/base10num)%a;
            if (rear [leastSigDig]!= NULL)
            {
                rear[leastSigDig]->next= cursor;
                rear [leastSigDig]= cursor;
            }
            else if (cursor == NULL)
            {
                rear [leastSigDig] = cursor;
            }
            cursor = cursor->next;
        }

        //Linking
        cursor = NULL;
        for (int y=0; y< a-1; y++)
        {
            int z= y+1;
            if (front [y] == NULL)
                continue;
            else if (cursor == NULL)
            {
                cursor = front [y];
                rear [y]->next = front [z];
            }
            else if (cursor != NULL)
                rear [y]->next = front [z];


            data = cursor;
        }
    }

  return data;

}


int main(void)
{
    long i, length=10;
    long a = 10; // working with base 10
    long k = log10(length*a);
    struct listnode *node, *space;
    space =  (struct listnode *) malloc(length*sizeof(struct listnode));
    for( i=0; i< length; i++ )
    {
        (space + i)->value = 2*((17*i)%length);
        (space + i)->next = space + (i+1);
    }
    (space+(length-1))->next = NULL;
    node = space;
    struct listnode * temp =node;
    cout<<endl<<"List before radixsort\n" <<endl ;
    while(temp!=NULL)
    {
        cout << temp->value << "\t";
        temp = temp->next;
    }

    node = radixsort(node,a,k);

    listnode *check = node;
    cout << "\n\nList after radixsort \n\n";
    while (check)
    {
        cout << check->value << "\t";
        check = check->next;
    }
    cout << "\n\n";
    exit(0);
}
