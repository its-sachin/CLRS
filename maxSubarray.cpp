#include <iostream>
#include <limits>

using namespace std;

int bruteForce(int array[], int size) {
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

    cout<<"Max sum: "<<max<<endl;
    

    for (int i = left; i<= right; i++) {

        cout<<array[i]<<" ";
    }
    cout<<"\n";
    
}


int main(int argc, char const *argv[])
{
    int size = 16;
    int array[size] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};

    bruteForce(array,size);

    size = 4;
    int array2[size] = {1,-4,3,-4};
    bruteForce(array2,size);
    return 0;
}
