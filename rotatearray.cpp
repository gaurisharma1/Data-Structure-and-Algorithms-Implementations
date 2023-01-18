
#include <iostream>

using namespace std;

int* rotate1(int a[], int n, int k) {
    for(int i = 0; i < k; i++) {
        int temp = a[n-1];
        for(int i = n-1; i >= 1; i--) {
            a[i] = a[i-1];
        }
        a[0] = temp;
    }
    return a;
}

int* rotate2(int a[], int n, int k) {
    int temp[n], index = 0; // 1 2 3 4 5 6 7 8 9 10  //indx=0 n=10 k=3  
    for(int i = n-k; i < n; i++) {//i=7  temp[3]=10 8 9 10
        temp[index++] = a[i];
    }
    for (int i = 0; i < n-k; i++) { // 0 -> 7
        temp[index] = a[i];// 8 9 10 1 2 3 4 5 6 7
        index++;
    }
    for (int i = 0; i < n; i++) {//temp copy to a
        a[i] = temp[i];
    }
    return a;
}
void reverse(int arr[], int l, int r)
{
    while (l < r) {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
}
int* rotate3(int a[], int n, int k) {
    reverse(a, n-k, n-1); // 7-9
    reverse(a, 0, n-k-1);//0-6
    reverse(a, 0, n-1);//0-9
    return a;
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(a)/sizeof(a[0]);
    int k = 3;
    k = k % n;
    // rotate1(a,n,k);
    rotate3(a,n,k);
    //rotate2(a,n,k);
    for(int i = 0; i < n; i++) {
        cout<<a[i]<<endl;
    }
    return 0;
}
