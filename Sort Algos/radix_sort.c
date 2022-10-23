#include<stdio.h>
int gt_Max_vl(int arr_0[], int n_1) {
int mx_vl = arr_0[0];
int k_2;
for (k_2 = 1; k_2 < n_1; k_2++)
if (arr_0[k_2] > mx_vl)
mx_vl = arr_0[k_2];
return mx_vl;
}
void count_Sort_0(int arr_0[], int n_1, int exp) {
int output[n_1];
int k_2, count_val[8] = { 0 };
for (k_2 = 0; k_2 < n_1; k_2++)
count_val[(arr_0[k_2] / exp) % 8]++;
for (k_2 = 1; k_2 < 8; k_2++)
count_val[k_2] += count_val[k_2 - 1];
for (k_2 = n_1 - 1; k_2 >= 0; k_2--) {
output[count_val[(arr_0[k_2] / exp) % 8] - 1] = arr_0[k_2];
count_val[(arr_0[k_2] / exp) % 8]--;
}
for (k_2 = 0; k_2 < n_1; k_2++)
arr_0[k_2] = output[k_2];
}
void radix_sort_0(int arr_0[], int n_1) {
int m_0 = gt_Max_vl(arr_0, n_1);
int exp;
for (exp = 1; m_0 / exp > 0; exp *= 8)
count_Sort_0(arr_0, n_1, exp);
}
void print(int arr_0[], int n_1) {
int k_2;
for (k_2 = 0; k_2 < n_1; k_2++)
printf("%d ", arr_0[k_2]);
}
int main() {
int arr_0[] = { 10, 115, 65, 70, 567, 112, 20, 668 };
int n_1 = sizeof(arr_0) / sizeof(arr_0[0]);
radix_sort_0(arr_0, n_1);
print(arr_0, n_1);
return 0;
}