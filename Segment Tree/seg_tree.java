/*
Implementation guide:

int[] treeMin = constructSTMin(arr, n);
int[] treeMax = constructSTMax(arr, n);
int[] treeSum = constructSTSum(arr, n);


updateValueMax(arr, treeMax, 0, n-1, b-1, newval, 0);
updateValueMin(arr, treeMin, 0, n-1, b-1, newval, 0);
updateValueSum(arr, treeSum, b-1, newval);

long max = getMax(treeMax, n, qs, qe);
long min = getMin(treeMin, n, qs, qe);
long sum = getSum(treeSum, n, qs, qe);

*/

static int getMid(int s, int e)
   {
       return s + (e - s) / 2;
   }

   static int getMax(int[] st, int n, int l, int r)
   {
       if (l < 0 || r > n - 1 || l > r) {
           return -1;
       }
       return MaxUtil(st, 0, n - 1, l, r, 0);
   }
   static int getMin(int[] st, int n, int l, int r)
   {
       if (l < 0 || r > n - 1 || l > r) {
           return -1;
       }
       return MinUtil(st, 0, n - 1, l, r, 0);
   }
   static int getSum(int[] st, int n, int l, int r)
   {
       if (l < 0 || r > n - 1 || l > r) {
           return -1;
       }
       return SumUtil(st, 0, n - 1, l, r, 0);
   }

   static int MaxUtil(int[] st, int ss, int se, int l, int r, int node)
   {
       if (l <= ss && r >= se)
           return st[node];

       if (se < l || ss > r)
           return Integer.MIN_VALUE;

       int mid = getMid(ss, se);

       return Math.max(MaxUtil(st, ss, mid, l, r, 2 * node + 1), MaxUtil(st, mid + 1, se, l, r, 2 * node + 2));
   }
   static int MinUtil(int[] st, int ss, int se, int l, int r, int node)
   {
       if (l <= ss && r >= se)
           return st[node];

       if (se < l || ss > r)
           return Integer.MAX_VALUE;

       int mid = getMid(ss, se);

       return Math.min(MinUtil(st, ss, mid, l, r, 2 * node + 1), MinUtil(st, mid + 1, se, l, r, 2 * node + 2));
   }
   static int SumUtil(int[] st, int ss, int se, int l, int r, int node)
   {
       if (l <= ss && r >= se)
           return st[node];

       if (se < l || ss > r)
           return 0;

       int mid = getMid(ss, se);

       return SumUtil(st, ss, mid, l, r, 2 * node + 1) + SumUtil(st, mid + 1, se, l, r, 2 * node + 2);
   }
   static void updateValueMax(int[] arr, int[] st, int ss, int se, int index, int value, int node)
   {
       if (index < ss || index > se) {
           return;
       }

       if (ss == se) {
           arr[index] = value;
           st[node] = value;
       }
       else {
           int mid = getMid(ss, se);
           if (index <= mid) updateValueMax(arr, st, ss, mid, index, value, 2 * node + 1);
           else
               updateValueMax(arr, st, mid + 1, se, index, value, 2 * node + 2);

           st[node] = Math.max(st[2 * node + 1], st[2 * node + 2]);
       }
   }
   static void updateValueMin(int[] arr, int[] st, int ss, int se, int index, int value, int node)
   {
       if (index < ss || index > se) {
           return;
       }

       if (ss == se) {
           arr[index] = value;
           st[node] = value;
       }
       else {
           int mid = getMid(ss, se);
           if (index <= mid) updateValueMin(arr, st, ss, mid, index, value, 2 * node + 1);
           else
               updateValueMin(arr, st, mid + 1, se, index, value, 2 * node + 2);

           st[node] = Math.min(st[2 * node + 1], st[2 * node + 2]);
       }
   }
   static void updateValueSum(int[] arr, int[] st, int i, int new_val)
   {
       int n = arr.length;
       if (i < 0 || i > n - 1) {
           return;
       }

       int diff = new_val - arr[i];

       arr[i] = new_val;

       updateValueUtilSum(0, n - 1, i, diff, 0, st);
   }
   static void updateValueUtilSum(int ss, int se, int i, int diff, int si, int[] st)
   {
       if (i < ss || i > se)
           return;

       st[si] = st[si] + diff;
       if (se != ss) {
           int mid = getMid(ss, se);
           updateValueUtilSum(ss, mid, i, diff, 2 * si + 1, st);
           updateValueUtilSum(mid + 1, se, i, diff, 2 * si + 2, st);
       }
   }
   static int constructSTMaxUtil(int[] arr, int ss, int se, int[] st, int si)
   {
       if (ss == se) {
           return st[si] = arr[ss];
       }

       int mid = getMid(ss, se);

       return st[si] = Math.max(constructSTMaxUtil(arr, ss, mid, st, si * 2 + 1), constructSTMaxUtil(arr, mid + 1, se, st, si * 2 + 2));
   }
   static int constructSTMinUtil(int[] arr, int ss, int se, int[] st, int si)
   {
       if (ss == se) {
           return st[si] = arr[ss];
       }

       int mid = getMid(ss, se);

       return st[si] = Math.min(constructSTMinUtil(arr, ss, mid, st, si * 2 + 1), constructSTMinUtil(arr, mid + 1, se, st, si * 2 + 2));
   }
   static int constructSTSumUtil(int[] arr, int ss, int se, int[] st, int si)
   {
       if (ss == se) {
           return st[si] = arr[ss];
       }

       int mid = getMid(ss, se);

       return st[si] = constructSTSumUtil(arr, ss, mid, st, si * 2 + 1) + constructSTSumUtil(arr, mid + 1, se, st, si * 2 + 2);
   }

   static int[] constructSTMax(int[] arr, int n)
   {
       int x = (int)Math.ceil(Math.log(n) / Math.log(2));

       int max_size = 2 * (int)Math.pow(2, x) - 1;

       int[] st = new int[max_size];

       constructSTMaxUtil(arr, 0, n - 1, st, 0);

       return st;
   }
   static int[] constructSTMin(int[] arr, int n)
   {
       int x = (int)Math.ceil(Math.log(n) / Math.log(2));

       int max_size = 2 * (int)Math.pow(2, x) - 1;

       int[] st = new int[max_size];

       constructSTMinUtil(arr, 0, n - 1, st, 0);

       return st;
   }
   static int[] constructSTSum(int[] arr, int n)
   {
       int x = (int)Math.ceil(Math.log(n) / Math.log(2));

       int max_size = 2 * (int)Math.pow(2, x) - 1;

       int[] st = new int[max_size];

       constructSTSumUtil(arr, 0, n - 1, st, 0);

       return st;
   }