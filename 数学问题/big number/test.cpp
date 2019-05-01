class Solution {
public:
    void merge(int nums1[], int m, int nums2[], int n) {
        int index=m+n-1;
        if(m==0) nums1=nums2;
        else{
            m--;
            n--;
            while(n>=0&&m>=0){
                if(nums1[m]>nums2[n]){
                    nums1[index--]=nums1[m];
                }
                else{
                    nums1[index--]=nums2[n];
                }
            }
            
            if(n>=0){
                for(int i=0;i<=n;i++){
                    nums1[i]=nums2[i];
                }
            }  
            
        }
        
        
        
    }
};

int main(){
	
	
	return 0;
}
