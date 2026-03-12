#include &lt;stdio.h&gt;
void swap(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}

void heapify(int arr[], int n, int i) {
int largest = i;
int left = 2*i + 1;
int right = 2*i + 2;

if (left &lt; n &amp;&amp; arr[left] &gt; arr[largest])
largest = left;

if (right &lt; n &amp;&amp; arr[right] &gt; arr[largest])
largest = right;

if (largest != i) {
swap(&amp;arr[i], &amp;arr[largest]);
heapify(arr, n, largest);
}
}

void heapSort(int arr[], int n) {

for (int i = n/2 - 1; i &gt;= 0; i--)
heapify(arr, n, i);

for (int i = n - 1; i &gt; 0; i--) {
swap(&amp;arr[0], &amp;arr[i]);
heapify(arr, i, 0);
}
}

void printArray(int arr[], int n) {
for (int i = 0; i &lt; n; i++)
printf(&quot;%d &quot;, arr[i]);
}

int main() {
int arr[] = {15,20,7,9,30,50,2};
int n = 5;

printf(&quot;Original Array:\n&quot;);
printArray(arr, n);

heapSort(arr, n);

printf(&quot;\nSorted Array (Ascending Order):\n&quot;);
printArray(arr, n);

return 0;

}