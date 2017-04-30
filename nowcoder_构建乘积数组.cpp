class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    	vector<int> a(A.size()+1, 1),b(A.size()+1, 1),c(A.size(), 0);
        for(int i=0;i<A.size();i++){
            a[i+1]=a[i]*A[i];
            b[i+1]=b[i]*A[A.size()-1-i];
        }
        for(int i=0;i<A.size();i++){
            c[i]=a[i]*b[A.size()-i-1];
        }
        return c;
    }
};