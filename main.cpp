#include <graphics.h>
#include <iostream>

using namespace std;

#define BARWIDTH 2
#define BARMINHEIGHT 100

class Graphic {
public:
    int h, left, right, bottom, top, n = 325;
    Graphic() {
        int gd = DETECT, gm;
        initgraph( & gd, & gm, NULL);
    }

    void pre_iter(int i, int * a) {
        int h;
        cleardevice();
        setcolor(WHITE);
        h = i * 2;
        bar(left = h, top = BARMINHEIGHT + a[i], right = h + BARWIDTH, bottom = 600);
    }

    void post_iter(int * a) {
        int h;
        setcolor(RED);
        for (int i = 1; i <= n; i++) {
          h = i * 2;
          bar(left = h, top = BARMINHEIGHT + a[i], right = h + 2, bottom = 600);
      }
  }

};

class Sorting_Alogrithms: public Graphic {
  public: int i,j,n = 399,temp,min,l,loc;
  int a[600];

  void generate_random_numbers() {
    for (int i = 0; i < n; i++) {
      a[i] = rand() % 500+5;
  }
}
void selection_sort() {
    generate_random_numbers();
    //Selection Sort
    for (i = 0; i < n - 1; i++) {
      min = a[i];
      loc = i;
      pre_iter(i, a);
      for (j = i + 1; j < n; j++) {
        if (min > a[j]) {
          min = a[j];
          loc = j;
      }
  }

  temp = a[i];
  a[i] = a[loc];
  a[loc] = temp;
  post_iter(a);
}
}
void insertion_sort() {
    generate_random_numbers();
    for (i = 1; i <= n - 1; i++) {
        pre_iter(i, a);
        temp = a[i];
        j = i - 1;

        while ((temp < a[j]) && (j >= 0)) {
            a[j + 1] = a[j];
            j = j - 1;
        }

        a[j + 1] = temp;
        post_iter(a);
    }
}
void quick_sort(){
    generate_random_numbers();
    quick_sort(a,0,n-1);
}

void quick_sort(int a[],int l,int u)
{
    int j;
    if(l<u)
    {
        pre_iter(u,a);
        j=partition(a,l,u);
        post_iter(a);
        quick_sort(a,l,j-1);
        pre_iter(u,a);
        post_iter(a);
        quick_sort(a,j+1,u);
        pre_iter(u,a);
        post_iter(a);
    }
}

int partition(int a[],int l,int u)
{
    int v,i,j,temp;
    v=a[l];
    i=l;
    j=u+1;
    do
    {
        do
        i++;
        while(a[i]<v&&i<=u);

        do
        j--;
        while(v<a[j]);

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);

    a[l]=a[j];
    a[j]=v;

    return(j);
}
void merge_sort(){
    generate_random_numbers();
    mergesort(a,0,n-1);
}

void mergesort(int a[],int i,int j)
{
    int mid;
    if(i<j)
    {
        pre_iter(i,a);
        post_iter(a);
        mid=(i+j)/2;
        mergesort(a,i,mid);
        pre_iter(i,a);
        post_iter(a);
        mergesort(a,mid+1,j);
        pre_iter(j,a);
        post_iter(a);
        merge(a,i,mid,mid+1,j);
    }
}

void merge(int a[],int i1,int j1,int i2,int j2)
{
    int temp[599];
    int i,j,k;
    i=i1;
    j=i2;
    k=0;

    while(i<=j1 && j<=j2)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }

    while(i<=j1)
        temp[k++]=a[i++];

    while(j<=j2)
        temp[k++]=a[j++];


    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j];
}
void radix_sort(){
    generate_random_numbers();
    RadixSort(a,n);
}

int largest(int a[], int n)
{
    int large = a[0], i;
    for(i = 1; i < n; i++)
    {
        if(large < a[i])
            large = a[i];
    }
    return large;
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;


    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i) {
        swapped(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void heapSort(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) {
        pre_iter(i,a);
        heapify(a, n, i);
        post_iter(a);
    }
    for (int i = n - 1; i >= 0; i--) {
        pre_iter(i,a);
        swapped(a[0], a[i]);
        heapify(a, i, 0);
        post_iter(a);
    }
}

void heap_sort(){
    generate_random_numbers();
    heapSort(a, n);
}
void RadixSort(int a[], int n)
{
    int bucket[n][n], bucket_count[n];
    int i=0, j, k, remainder, NOP=0, divisor=1, large, pass;
    pre_iter(i,a);
    large = largest(a, n);
    while(large > 0)
    {
        NOP++;
        large/=10;
    }

    for(pass = 0; pass < NOP; pass++)
    {

        for(i = 0; i < 500; i++)
        {

            bucket_count[i] = 0;

        }
        for(i = 0; i < n; i++)
        {
            remainder = (a[i] / divisor) % 10;
            bucket[remainder][bucket_count[remainder]] = a[i];
            bucket_count[remainder] += 1;
        }

        i = 0;
        for(k = 0; k < 10; k++)
        {

            for(j = 0; j < bucket_count[k]; j++)
            {
                pre_iter(j,a);
                a[i] = bucket[k][j];
                i++;
                post_iter(a);
            }
        }
        divisor *= 10;

    }
}
void bubble_sort() {
    generate_random_numbers();
    for (i = 1; i < n; ++i) {
        pre_iter(i, a);
        for (j = 0; j < (n - i); ++j) {
            if (a[j] > a[j + 1]) {
              temp = a[j];
              a[j] = a[j + 1];
              a[j + 1] = temp;
          }
      }
      post_iter(a);
  }
}
};


int main() {
  Graphic g;
  Sorting_Alogrithms al;

  outtextxy(0, 0, "Selection Sort");
  delay(1000);
  al.selection_sort();
  outtextxy(0, 0, "Insertion Sort");
  delay(1000);
  al.insertion_sort();
  outtextxy(0, 0, "Quick Sort");
  delay(1000);
  al.quick_sort();
  outtextxy(0, 0, "Merge Sort");
  delay(1000);
  al.merge_sort();
  outtextxy(0, 0, "Heap Sort");
  delay(1000);
  al.heap_sort();
  outtextxy(0, 0, "Radix(LSD) Sort");
  delay(1000);
  al.radix_sort();
  outtextxy(0, 0, "Bubble Sort");
  delay(1000);
  al.bubble_sort();

  getch();

  closegraph();

  return 0;
}
