// Count subarrays with given sum


#include<bits/stdc++.h>
using namespace std;

class solution{
public:

    // TC = O(N^3)
    int brute(vector<int> vec, int givensum){
        int n = vec.size();
        // cout<< "size : " << n << endl;
        int count = 0;
        for(int i = 0; i<n; i++){
            for (int j = i; j<n; j++){
                int sum = 0;
                for(int k = i; k<=j; k++){
                    sum += vec[k];
                }
                if(sum == givensum) count++;
            }
        }
        return count;
    }

    // TC = O(N^2)
    int better(vector<int> vec, int givensum){
        int n = vec.size();
        int count = 0;
        for(int i = 0; i<n; i++){
            int sum = 0;
            for (int j = i; j<n; j++){
                sum += vec[j];
                if(sum == givensum) count++;
            }
        }
        return count;
    }


    // TC = O(N x logN)
    // SC = O(N)
    int optimal(vector<int> vec, int givensum){
        int n = vec.size();
        int count = 0;
        int sum = 0;
        int prevsum = 0;
        unordered_map <int, int> mpp;
        mpp[0] = 1;
        for(int i = 0; i<n; i++){
            sum += vec[i];
            prevsum = sum-givensum;
            count += mpp[prevsum];
            mpp[sum] += 1;

        }
        return count;
    }


};

int main(){
    solution obj;

    vector<int> vec;
    int n;
    cout<< "Enter the size of vector: ";
    cin>> n;

    cout<< "Now enter all the values of vector:" << endl;
    for(int i = 0; i<n; i++){
        int input;
        cin>> input;
        vec.push_back(input);
    }

    int givensum;
    cout<< "Enter the given sum: ";
    cin>> givensum ;

    // int num = obj.brute(vec, givensum);
    // int num = obj.better(vec, givensum);
    int num = obj.optimal(vec, givensum);


    cout<< "Total numbers of subarrays with given sum = " << num << endl;

    return 0;
}