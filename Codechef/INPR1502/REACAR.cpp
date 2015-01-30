// Rearranging Cartons

#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int inv_count = 0, N;

void merge(int A[], int L, int mid, int R){
    int C[N];
    int i = L, j = mid + 1, len = R - L + 1;
    for(int k = 0; k < len; k++){
       	if(i > mid){
            C[k] = A[j];
            j++;
        }
        else if(j > R){
            C[k] = A[i];
            i++;
        }
        else if(A[i] < A[j]){
            C[k] = A[i];
            i++;
        }
        else {
            C[k] = A[j];
            j++;
            inv_count += mid - i + 1;
        }
    }
    for(int i = 0; i < len; i++){
        A[L + i] = C[i];
    }
}

void mergesort(int A[], int L, int R){
    if(L >= R) return;

    int mid = L + (R - L)/2;

    mergesort(A, L, mid);
    mergesort(A, mid + 1, R);
    merge(A, L, mid, R);
}

int search(vector<pair<int, int> > Q, int val){
    int low = 0, high = N, mid;
    while(low <= high){
        mid = low + (high - low)/2;
        if(Q[mid].first < val){
            low = mid + 1;
        }
        else if(Q[mid].first > val){
            high = mid - 1;
        }
        else {
            return Q[mid].second;
        }
    }
    return -1;
}

bool sort_compare(pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main() {
    scanf("%d", &N);
    int A[N];
    vector<pair<int, int> > Q;

    for(int i = 0; i < N; i++) scanf("%d", &A[i]);
    for(int i = 0; i < N; i++) {
        int a; scanf("%d", &a);
        Q.push_back(make_pair(a, i));
    }

    sort(Q.begin(), Q.end(), sort_compare);
    for(int i = 0; i < N; i++){
        A[i] = search(Q, A[i]);
    }

    mergesort(A, 0, N - 1);
    printf("%d\n", inv_count);
}
