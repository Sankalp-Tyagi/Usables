//FENWICK TREE

int getSum(int BITree[], int index) 
{
	int sum = 0; 

	 
	index = index + 1; 

	 
	while (index>0) 
	{ 
		
		sum += BITree[index]; 

		
		index -= index & (-index); 
	} 
	return sum; 
} 

void updateBIT(int BITree[], int n, int index, int val) 
{ 
    
    index = index + 1; 
  
     
    while (index <= n) 
    { 
   
    BITree[index] += val; 
  
   
    index += index & (-index); 
    } 
}
 
int *constructBITree(int arr[], int n) 
{ 
	
	int *BITree = new int[n+1]; 
	for (int i=1; i<=n; i++) 
		BITree[i] = 0; 

	 
	for (int i=0; i<n; i++) 
		updateBIT(BITree, n, i, arr[i]); 

	

	return BITree; 
}
int main() 
{ 
	int freq[] = {10, 20, 30, 40, 50, 60, 70, 80, 90}; 
	int n = sizeof(freq)/sizeof(freq[0]); 
	int *BITree = constructBITree(freq, n); 
	cout << "Sum of elements in arr[0..5] is "
		<< getSum(BITree, 5); 

	return 0;
}


//SEGMENT TREE


int CST(int ss, int se, int si, int arr[], int tree[])
{
	if(ss == se)
	{
		tree[si] = arr[ss];
		return arr[ss];
	}

	int mid = (ss + se) / 2;

	tree[si] = CST(ss, mid, 2 * si + 1, arr, tree)
		       +CST(mid + 1, se, 2 * si + 2, arr, tree);

	return tree[si];
}

void updateRec(int ss, int se, int i, int si, int diff, int tree[])
{
    if(i < ss || i > se) 
        return;
        
    tree[si] = tree[si] + diff;
    
    if(se > ss)
    {
        int mid = (ss + se) / 2;
        
        updateRec(ss, mid, i, 2 * si + 1, diff, tree);
        updateRec(mid + 1, se, i, 2 * si + 2, diff, tree);
        
    }
}

int getSumRec(int qs, int qe, int ss, int se, int si, int tree[])
{
	if(se < qs || ss > qe)
		return 0;
	if(qs <= ss &&  qe >= se)
		return tree[si];

	int mid = (ss + se) / 2;

	return getSumRec(qs, qe, ss, mid, 2 * si + 1, tree)
		   + getSumRec(qs, qe, mid + 1, se, 2 * si + 2, tree);
}

int main() {
	int arr[] = {10, 20, 30, 40}, n= 4;

    int tree[4 * n];
    CST(0, n - 1, 0, arr, tree);
     
    updateRec(0, 3, 1, 0, 5, tree);
		
	return 0;
}
