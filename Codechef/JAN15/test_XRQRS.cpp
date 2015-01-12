#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

struct Query {
    //A a b c  add c in [a, b] of arr
    //Q a b c  Query number of i in [a, b] which arr[i] <= c
    char ty;
    int a, b, c;
    Query(char _ty, int _a, int _b, int _c):ty(_ty), a(_a), b(_b), c(_c){}
};

int n, m;
vector<int> arr;
vector<Query> queries;

vector<int> bruteforce() {
    vector<int> ret;
    vector<int> numbers = arr;
    for (int i = 0; i < m; i++) {
        Query q = queries[i];
        if (q.ty == 'A') {
            for (int i = q.a; i <= q.b; i++) {
                numbers[i] += q.c;
            }
            ret.push_back(-1);
        } else {
            int tmp = 0;
            for(int i = q.a; i <= q.b; i++) {
                tmp += numbers[i] <= q.c;
            }
            ret.push_back(tmp);
        }
    }
    return ret;
}

struct Bucket {
    vector<int> numbers;
    vector<int> numbers_sorted;
    int add;
    Bucket() {
        add = 0;
        numbers_sorted.clear();
        numbers.clear();
    }
    int query(int pos) {
        return numbers[pos] + add;
    }
    void add_pos(int pos, int val) {
        numbers[pos] += val;
    }
    void build() {
        numbers_sorted = numbers;
        sort(numbers_sorted.begin(), numbers_sorted.end());
    }
};

vector<int> bucket_count(int bucket_size) {
    vector<int> ret;

    vector<Bucket> buckets;
    buckets.resize(int(n / bucket_size) + 5);
    for (int i = 0; i < n; i++) {
        buckets[i / bucket_size].numbers.push_back(arr[i]);
    }

    for (int i = 0; i <= n / bucket_size; i++) {
        buckets[i].build();
    }

    for (int i = 0; i < m; i++) {
        Query q = queries[i];
        char ty = q.ty;
        int a, b, c;
        a = q.a, b = q.b, c = q.c;
        if (ty == 'A') {
            set<int> affect_buckets;
            while (a < b && a % bucket_size != 0) buckets[a/ bucket_size].add_pos(a % bucket_size, c), affect_buckets.insert(a/bucket_size), a++;
            while (a < b && b % bucket_size != 0) buckets[b/ bucket_size].add_pos(b % bucket_size, c), affect_buckets.insert(b/bucket_size), b--;
            while (a < b) {
                buckets[a/bucket_size].add += c;
                a += bucket_size;
            }
            buckets[a/bucket_size].add_pos(a % bucket_size, c), affect_buckets.insert(a / bucket_size);
            for (set<int>::iterator it = affect_buckets.begin(); it != affect_buckets.end(); it++) {
                int id = *it;
                buckets[id].build();
            }
            ret.push_back(-1);
        } else {
            int tmp = 0;
            while (a < b && a % bucket_size != 0) tmp += (buckets[a/ bucket_size].query(a % bucket_size) <=c), a++;
            while (a < b && b % bucket_size != 0) tmp += (buckets[b/ bucket_size].query(b % bucket_size) <=c), b--;
            while (a < b) {
                int pos = a / bucket_size;
                tmp += upper_bound(buckets[pos].numbers_sorted.begin(), buckets[pos].numbers_sorted.end(), c - buckets[pos].add) - buckets[pos].numbers_sorted.begin();
                a += bucket_size;
            }
            tmp += (buckets[a / bucket_size].query(a % bucket_size) <= c);
            ret.push_back(tmp);
        }
    }

    return ret;
}

void process(int cas) {

    clock_t begin_t=clock();

    vector<int> bf_ans = bruteforce();
    clock_t  bf_end_t =clock();
    double bf_sec = ((1.0 * bf_end_t - begin_t)) / CLOCKS_PER_SEC;

    //bucket_size is important
    int bucket_size = 200;
    vector<int> ans = bucket_count(bucket_size);

    clock_t  bucket_end_t =clock();
    double bucket_sec = ((1.0 * bucket_end_t - bf_end_t)) / CLOCKS_PER_SEC;

    bool correct = true;
    for (int i = 0; i < ans.size(); i++) {
        if (ans[i] != bf_ans[i]) {
            cout << "query " << i + 1 << " bf = " << bf_ans[i] << " bucket  = " << ans[i] << "  bucket size = " <<  bucket_size << " " << n << " " << m <<  endl;
            correct = false;
        }
    }
    printf("Case #%d:%s bf_sec = %.9lf, bucket_sec = %.9lf\n", cas, correct ? "YES":"NO", bf_sec, bucket_sec);
}

void read() {
    cin >> n >> m;
    arr.clear();
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    queries.clear();
    for (int i = 0; i < m; i++) {
        char ty;
        int a, b, c;
        // a, b, c in [0, n - 1], a <= b
        cin >> ty >> a >> b >> c;
        queries.push_back(Query(ty, a, b, c));
    }
}

void run(int cas) {
    read();
    process(cas);
}

int main() {
    freopen("bucket.in", "r", stdin);
    //freopen("bucket.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas  = 1; cas <= T; cas++) {
        run(cas);
    }
    return 0;
}
