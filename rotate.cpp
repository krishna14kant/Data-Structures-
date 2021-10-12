int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    int temp=arr[n-1];
	    for(int i=n;i>0;i--)
	    {
	        arr[i]=arr[i-1];
	    }
	    arr[0]=temp;
	    for(int i=0;i<n;i++)
	    {
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	    
	}
	return 0;
}