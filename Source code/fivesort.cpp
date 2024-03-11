#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
class mysort
{

private:
    static void tomerged(double *arr, int leftt, int mid, int rightt)
    {
        int subarrone = mid - leftt + 1;
        int subarrtwo = rightt - mid;
        auto *leftarr = new double[subarrone];
        auto *rightarr = new double[subarrtwo];
        for (auto i = 0; i < subarrone; ++i)
            leftarr[i] = arr[leftt + i];
        for (auto j = 0; j < subarrtwo; ++j)
            rightarr[j] = arr[mid + 1 + j];

        auto indexofsubarrone = 0, indexofsubarrtwo = 0;
        int indexofmergedarr = leftt;
        while(indexofsubarrone < subarrone && indexofsubarrtwo < subarrtwo)
        {
            if(leftarr[indexofsubarrone] <= rightarr[indexofsubarrtwo])
            {
                arr[indexofmergedarr] = leftarr[indexofsubarrone];
                indexofsubarrone ++;
            }
            else {
                arr[indexofmergedarr] = rightarr[indexofsubarrtwo];
                indexofsubarrtwo ++;
            }
            indexofmergedarr++;
        }
        while (indexofsubarrone < subarrone)
        {
            arr[indexofmergedarr] = leftarr[indexofsubarrone];
            indexofsubarrone ++;
            indexofmergedarr ++;
        }
        while (indexofsubarrtwo < subarrtwo)
        {
            arr[indexofmergedarr] = rightarr[indexofsubarrtwo];
            indexofsubarrtwo ++;
            indexofmergedarr ++;
        }
        delete[] leftarr;
        delete[] rightarr;
    }
    static void heapify(double *arr, int N, int i)
    {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        if (l < N && arr[l] > arr[largest])
            largest = l;
        if (r < N && arr[r] > arr[largest])
            largest = r;
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, N, largest);
        }

    }

public:

    static void quick_sort(double *arr,int low,int high)
    {
        int i = low, j = high;
        int tmp;
        auto pivot = arr[(i + j)/2];

        while(i <= j)
        {
            while(arr[i] < pivot)
                i++;
            while(arr[j] > pivot)
                j--;
            if(i <= j)
            {
                swap(arr[i], arr[j]);
                i ++;
                j --;
            }
        }

        if(low < j)
            quick_sort(arr, low, j);
        if(i < high)
            quick_sort(arr, i, high);
    }
    static void merge_sort(double *arr, int leftt, int rightt)
    {
       if(leftt >= rightt)
            return;
       int mid = leftt + (rightt - leftt)/2;
       merge_sort(arr, leftt, mid);
       merge_sort(arr, mid + 1, rightt);
       tomerged(arr, leftt, mid, rightt);
    }
    static void heap_sort(double *arr, int N)
    {
        for (int i=N / 2 - 1; i >= 0; i--)
            heapify(arr, N, i);
        for (int i=N - 1; i>=0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

bool check(double *arr, int numelement)
{
    for(int i=0; i<numelement-1; ++i)
    {
        if(arr[i] > arr[i + 1]) return false;
    }
    return true;
}

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    double start, endd;
    for(int testcase = 1; testcase <= 10; testcase ++)
    {
        string const filename = "Test" + to_string(testcase);
        freopen((filename + ".txt").c_str(), "r", stdin);
        cout<<"Test case: "<<testcase<<"\n";
        int n;
        cin>>n;
        double *a = new double[n];
        double *b = new double[n];
        for(int i=0; i<n; i++)
            cin>>a[i], b[i] = a[i];
        //if(testcase >= 3)
        //{
        start = clock();
        mysort::quick_sort(a, 0, n-1);
        endd = clock();
        if(check(a, n))
        cout<<"Time Quick Sort Runing: "<<double(endd - start)/CLOCKS_PER_SEC*1000<<"ms\n";
        else
        {
            cout<<"Sort error\n";
            for (int i=0; i<min(100, n); i++)
                cout<<a[i]<<" ";
            cout<<"\n";
        }
        //}
        for(int i=0; i<n; i++)
            a[i] = b[i];
        start = clock();
        mysort::merge_sort(a, 0, n-1);
        endd = clock();
        if(check(a, n))
        cout<<"Time Merge Sort Runing: "<<double(endd - start)/CLOCKS_PER_SEC*1000<<"ms\n";
        else cout<<"Sort error\n";

        for(int i=0; i<n; i++)
            a[i] = b[i];
        start = clock();
        mysort::heap_sort(a, n);
        endd = clock();
        if(check(a, n))
        cout<<"Time Heap Sort Runing: "<<double(endd - start)/CLOCKS_PER_SEC*1000<<"ms\n";
        else cout<<"Sort error\n";

        for(int i=0; i<n; i++)
            a[i] = b[i];
        start = clock();
        sort(a, a + n);
        endd = clock();
        if(check(a, n))
        cout<<"Time C Sort Runing: "<<double(endd - start)/CLOCKS_PER_SEC*1000<<"ms\n";
        else cout<<"Sort error\n";
        delete[] a;
        delete[] b;
    }
    return 0;

}
