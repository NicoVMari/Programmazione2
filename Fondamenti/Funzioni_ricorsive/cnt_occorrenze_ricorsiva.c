int countx_rn(int A[], int n, int x) {
if (n<0) return 0;
else if (A[n]==x) return 1+countx_rn(A,n-1,x);
else return countx_rn(A,n-1,x);
}