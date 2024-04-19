#include <iostream>
#include <vector>

using namespace std;

double function(double x){
    return x * x + 2;
}

double ternarySearch(double l, double r, double eps, double (*func)(double x)){

    while(r - l >= eps){
        double m1 = l + (r - l)/3;
        double m2 = r - (r - l)/3;
        if (func(m1) < func(m2)){
            l = m1;
        }
        else if (func(m1) > func(m2)){
            r = m2;
        }
        else{   // if (func(m1) == func(m2))
            l = m1;
            r = m2;
        }
    }

    return func(l);
}

int main(){
    cout << "ternarySearch(0, 2, 10e-3, x * x + 2): " << ternarySearch(0, 2, 10e-3, &function) << endl;

    return 0;
}