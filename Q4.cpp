#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number of points"<<endl;
    cin>>n;

    int * x = new int[n];
    int * y = new int[n];

    //random point generation
    int x_seed = 3;
    int y_seed = 2;
    
    cout<<"Generated Points"<<endl;
    for(int i = 0; i < n; i++)
    {
        x_seed = (2*x_seed + 2)%50;
        x[i] = x_seed;
        y_seed = (3*y_seed + 2)%50;
        y[i] = y_seed;

        cout<<"("<<x[i]<<","<<y[i]<<")"<<endl;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            
            int a = y[j] - y[i];
            int b = x[i] - x[j];
            int c = (x[i]*y[j]) - (x[j]*y[i]);
            
            int count_up = 0;
            int count_down = 0;
            bool show = true;
            for(int k = 0; k < n ; k++)
            {
                if( k != i && k != j){
                if (((a*x[k]) + (b*y[k]) - c ) > 0)
                count_up++;
                else if (((a*x[k]) + (b*y[k]) - c ) < 0) 
                count_down++;
                else {
                    int dist_K = abs(x[i] - x[k]) + abs(y[i] - y[k]);
                    int dist_J = abs(x[i] - x[j]) + abs(y[i] - y[j]);

                    if( dist_J <= dist_K)
                    {
                        show = false ;
                        break;
                    }
                }
                }
            }


            //add point to hull
            if(( count_up == 0 || count_down == 0) && show )
            {
                cout<<"("<<x[i]<<","<<y[i]<<")"<<"  &&  ";
                cout<<"("<<x[j]<<","<<y[j]<<")"<<endl;
            }





        }
    }






};
