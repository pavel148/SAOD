

#include <iostream>
#include "utils.h";
using namespace std;
void rotate(int a[], int n,bool clockwise);
int a[5]{ 1,2,3,4,5 };
int main()
{
   
  
    cout << "Hi" << endl;
    cout << "////////////" << endl;
    for (int* p = a; p - a < 5; p++){
        cout << *p <<' ';
        
    }
    cout << "Hi" << endl;
    cout << endl;
 


    cout << "////////////" << endl;
    cout << "!!!!!!!" << endl;
    for (int* p = a; p - a < 5; p++)
    cout << *p << ' ';
    cout << endl;

}
void rotate(int a[], int n,bool clockwise) 
{
    
    if (clockwise == false) {
        int x = a[0];
        for (int i = 1; i < n; i++)
            a[i - 1] = a[i];
        a[n - 1] = x;
    }
    if (clockwise == true) {
        int x = a[n-1];
        for (int i = 0; i < n-1; i++)
            a[i+1] = a[i];
        a[0] = x;
    }
   
}


