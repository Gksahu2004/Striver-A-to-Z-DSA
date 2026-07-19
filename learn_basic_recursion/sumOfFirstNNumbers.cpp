#include<bits/stdc++.h>
using namespace std;

void sumoffirstNnumbers(int i, int sum){
    if (i<1){
        cout<< sum << endl;
        return;
    }

    return sumoffirstNnumbers(i-1, sum+i);
}

int main(){

    int n;
    cout<< "Enter a number: ";
    cin>> n;

    sumoffirstNnumbers(n, 0);

    return 0;
}


// #include<bits/stdc++.h>
// using namespace std;

// int sumoffirstNnumbers(int n){
//     if (n==1) return 1;

//     return n + sumoffirstNnumbers(n-1);
// }

// int main(){

//     int i = 1, n, sum = 0;
//     cout<< "Enter a number: ";
//     cin>> n;

//     int sumofnums = sumoffirstNnumbers(n);
//     cout<< sumofnums << endl;

//     return 0;
// }