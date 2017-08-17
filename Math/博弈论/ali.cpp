/*************************************************************************
    > File Name: ali.cpp
    > Author: Rylynnn
    > Mail: jingry0321@gmail.com
    > Created Time: 2017年08月08日 星期二 19时51分32秒
 ************************************************************************/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100
using namespace std;
struct node{
    int start, end;
    node(int s = 0, int e = 0){
        start = s;
        end = e;
    }
};
int arr[N];
void quick_sort(const int len){
    if(len <= 0){
        return;
    }
    node b[len];
    int p = 0;
    b[p] = node(0, len - 1);
    p++;
    while(p){
        node now = b[--p];
        if(now.start >= now.end){
            continue;
        }
        int mid = arr[now.end];
        int l = now.start, r = now.end - 1;
        while(l < r){
            while(arr[l] < mid && l < r){
                l++;
            }
            while(arr[r] >= mid && l < r){
                r--;
            }
            swap(arr[l], arr[r]);
        }
        if(arr[l] >= arr[now.end]){
            swap(arr[l], arr[now.end]);
        }
        else{
            l++;
        }
        b[p] = node(now.start, l - 1);
        p++;
        b[p] = node(l + 1, now.end);
        p++;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    quick_sort(n);
    for(int i=0; i<n; i++){
            printf("%d ", arr[i]);
    }
    return 0;
}
