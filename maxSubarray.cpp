#include <iostream>
#include <limits>

using namespace std;

int print(int array[], int bound[3]){

    cout<<"Max sum: "<<bound[2]<<endl;
    

    for (int i = bound[0]; i<= bound[1]; i++) {

        cout<<array[i]<<" ";
    }
    cout<<"\n";

}

int* bruteForce(int array[], int size) {

    //O(n^2)

    int left = 0;
    int right = 0;

    int max = std::numeric_limits<int>::min();

    for (int i = 0; i < size; i++){
        int sum = 0;
        
        for (int j = i; j < size; j++){
            
            sum += array[j];
            if (sum > max){
                left = i;
                right = j;
                max = sum;
            }
        }
        
    }

    int* ans = new int[3];
    ans[0]=left;
    ans[1]=right;
    ans[2]=max;
    return ans;
    
    
}

int* crossing(int array[], int left, int mid, int right){

    int l,r;

    int leftSum = std::numeric_limits<int>::min();
    int sum=0;

    for (int i=mid; i>=left; i--){
        sum+=array[i];
        if (sum>leftSum){
            leftSum = sum;
            l = i;
        }
    }
    int rightSum = std::numeric_limits<int>::min();
    sum = 0;

    for (int i=mid+1; i<= right;i++){
        sum+=array[i];
        if (sum>rightSum){
            rightSum = sum;
            r = i;
        }
    }

    int* ans = new int[3];
    ans[0]=l;
    ans[1]=r;
    ans[2]=leftSum+rightSum;
    return ans;

}


int* recusrive(int array[], int left, int right){

    // O(nlogn)

    if(left==right){
        int* ans = new int[3];
        ans[0]=left;
        ans[1]=right;
        ans[2]=array[left];
        return ans;
    }

    else{
        int mid = (left+right)/2;

        int* l = recusrive(array,left,mid);
        int* r = recusrive(array,mid+1,right);
        int* m = crossing(array,left,mid,right);

        if (l[2]>=r[2] && l[2]>=m[2]){
            return l;
        }
        if (r[2]>=m[2]){
            return r;
        }
        return m;

    }


}

int* linear(int array[], int n) {

    //O(n)

    int max = std::numeric_limits<int>::min();
    int sum = std::numeric_limits<int>::min();

    int left=0;
    int right=0;
    int firstPos=0;

    for (int i=0;i<n;i++){

        sum += array[i];
        

        if (sum>max){
            max = sum;
            left = firstPos;
            right = i;
        }

        if (sum<0){
            sum=0;
            firstPos = i+1;
        }
    }

    int* ans = new int[3];
    ans[0]=left;
    ans[1]=right;
    ans[2]=max;
    return ans;

}

int main(int argc, char const *argv[])
{
    int size = 16;
    int array[size] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};

    bruteForce(array,size);

    size = 4;
    int array2[size] = {1,-4,3,-4};

    int* ans = bruteForce(array2,size);
    int* ans1 = recusrive(array2,0,size-1);
    int* ans2 = linear(array2,size);

    print(array2,ans);
    print(array2,ans1);
    print(array2,ans2);

    return 0;
}
