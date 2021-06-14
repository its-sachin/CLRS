#include <iostream>
// #include <limits>

using namespace std;

int** bruteForce(int** a, int** b, int n, int l, int m) {

    //O(n^3)

    //a should be n*l
    //b should be l*m

    int** c = new int*[n];
    for (int i=0; i<n; i++){
        c[i] = new int[m];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++){  

            c[i][j] = 0;

            for (int k=0; k<l ;k++){

                c[i][j] += a[i][k]*b[k][j];
            }
            
        }
    }

    return c;
    
}

void printMat(int** ans, pair<int,int> dimen){

    for (int i = 0; i<dimen.first; i++) {
        for (int j=0; j<dimen.second; j++){
            cout<<ans[i][j] << " ";
        }
        cout<<""<<endl;
    }

}

int** bruteForce(int** a, int** b, pair<int,int> ra, pair<int,int> ca, pair<int,int> rb, pair<int,int> cb){

    //O(n^3)

    //a should be n*l
    //b should be l*m


    int** c = new int*[ra.second - ra.first + 1];
    for (int i=ra.first; i<=ra.second; i++){
        c[i-ra.first] = new int[cb.second - cb.first + 1];
    }

    for (int i=ra.first; i<=ra.second; i++) {
        for (int j=cb.first; j<=cb.second; j++){  

            c[i-ra.first][j-cb.first] = 0;

            for (int k=ca.first; k<=ca.second ;k++){

                c[i-ra.first][j-cb.first] += a[i][k]*b[k-ca.first+rb.first][j];
            }
            
        }
    }


    return c;

}



int** add(int** a, int** b, int** c, pair<int,int> n, pair<int,int> m){

    //both a and b sould be n*m


    for (int i=n.first; i<=n.second; i++) {
        for (int j=m.first; j<=m.second; j++){  

            c[i][j] = a[i-n.first][j-m.first]+b[i-n.first][j-m.first];
            
        }
    }

}



int** recursive(int** a, int** b, pair<int,int> ra, pair<int,int> ca, pair<int,int> rb, pair<int,int> cb){

    //O(n^3)


    if (ra.first==ra.second || rb.first==rb.second || ca.first==ca.second || cb.first==cb.second){
        return bruteForce(a,b,ra,ca,rb,cb);
    }

    int** c = new int*[ra.second - ra.first + 1];
    for (int i=ra.first; i<=ra.second; i++){
        c[i-ra.first] = new int[cb.second - cb.first + 1];
    }

    int mid_ra = (ra.first+ra.second)/2;
    int mid_ca = (ca.first+ca.second)/2;
    int mid_rb = (rb.first+rb.second)/2;
    int mid_cb = (cb.first+cb.second)/2;
    
    add(recursive(a,b,{ra.first,mid_ra},{ca.first,mid_ca},{rb.first,mid_rb},{cb.first,mid_cb}),
        recursive(a,b,{ra.first,mid_ra},{mid_ca+1,ca.second},{mid_rb+1,rb.second},{cb.first,mid_cb}),
        c,{0,mid_ra-ra.first},{0,mid_cb-cb.first});

    add(recursive(a,b,{ra.first,mid_ra},{ca.first,mid_ca},{rb.first,mid_rb},{mid_cb+1,cb.second}),
        recursive(a,b,{ra.first,mid_ra},{mid_ca+1,ca.second},{mid_rb+1,rb.second},{mid_cb+1,cb.second}),
        c,{0,mid_ra-ra.first},{mid_cb-cb.first+1,cb.second-cb.first});

    add(recursive(a,b,{mid_ra+1,ra.second},{ca.first,mid_ca},{rb.first,mid_rb},{cb.first,mid_cb}),
        recursive(a,b,{mid_ra+1,ra.second},{mid_ca+1,ca.second},{mid_rb+1,rb.second},{cb.first,mid_cb}),
        c,{mid_ra-ra.first+1,ra.second-ra.first},{0,mid_cb-cb.first});

    add(recursive(a,b,{mid_ra+1,ra.second},{ca.first,mid_ca},{rb.first,mid_rb},{mid_cb+1,cb.second}),
        recursive(a,b,{mid_ra+1,ra.second},{mid_ca+1,ca.second},{mid_rb+1,rb.second},{mid_cb+1,cb.second}),
        c,{mid_ra-ra.first+1,ra.second-ra.first},{mid_cb-cb.first+1,cb.second-cb.first});


    return c;

}

int** addSub(int** a, int** b, int n, int cons){

    //both a and b sould be n*m

    int** c = new int*[n];
    for (int i=0; i<n; i++){
        c[i] = new int[n];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++){  

            c[i][j] = a[i][j]+ cons*b[i][j];
            
        }
    }

    return c;

}


int** strassen(int** a, int** b, int n){

    //O(n^log(7))


    if (n==1){
        return bruteForce(a,b,{0,0},{0,0},{0,0},{0,0});
    }

    int** c = new int*[n];
    for (int i=0; i<n; i++){
        c[i] = new int[n];
    }


    int** a11 = new int*[n/2];
    int** a12 = new int*[n/2];
    int** a21 = new int*[n/2];
    int** a22 = new int*[n/2];

    int** b11 = new int*[n/2];
    int** b12 = new int*[n/2];
    int** b21 = new int*[n/2];
    int** b22 = new int*[n/2];

    for (int i=0;i<n/2;i++){

        a11[i] = new int[n/2];
        b11[i] = new int[n/2];
        a12[i] = new int[n/2];
        b12[i] = new int[n/2];
        a21[i] = new int[n/2];
        b21[i] = new int[n/2];
        a22[i] = new int[n/2];
        b22[i] = new int[n/2];
    }

    for (int i=0; i<n; i++){
        
        for(int j=0; j<n; j++){
            // cout<<i<<j<<endl;

            if (i<n/2){
                if (j<n/2){
                    a11[i][j] = a[i][j];
                    b11[i][j] = b[i][j];
                }

                else{

                    a12[i][j-(n/2)] = a[i][j];
                    b12[i][j-(n/2)] = b[i][j];

                }
            }
            else{

                if (j<n/2){

                    a21[i-(n/2)][j] = a[i][j];
                    b21[i-(n/2)][j] = b[i][j];

                }

                else {
                    a22[i-(n/2)][j-(n/2)] = a[i][j];
                    b22[i-(n/2)][j-(n/2)] = b[i][j];
                }
            }
        }
    }

    

    int** s1 = addSub(b12,b22,n/2,-1);
    int** s2 = addSub(a11,a12,n/2,1);
    int** s3 = addSub(a21,a22,n/2,1);
    int** s4 = addSub(b21,b11,n/2,-1);
    int** s5 = addSub(a11,a22,n/2,1);
    int** s6 = addSub(b11,b22,n/2,1);
    int** s7 = addSub(a12,a22,n/2,-1);
    int** s8 = addSub(b21,b22,n/2,1);
    int** s9 = addSub(a11,a21,n/2,-1);
    int** s10 = addSub(b11,b12,n/2,1);

    int** p1 = strassen(a11,s1,n/2); 
    int** p2 = strassen(s2,b22,n/2); 
    int** p3 = strassen(s3,b11,n/2); 
    int** p4 = strassen(a22,s4,n/2); 
    int** p5 = strassen(s5,s6,n/2); 
    int** p6 = strassen(s7,s8,n/2); 
    int** p7 = strassen(s9,s10,n/2); 

    int** c11 = addSub(p6,addSub(p5,addSub(p4,p2,n/2,-1),n/2,1),n/2,1);
    int** c12 = addSub(p1,p2,n/2,1);
    int** c21 = addSub(p3,p4,n/2,1);
    int** c22 = addSub(addSub(p5,p1,n/2,1),addSub(p3,p7,n/2,1),n/2,-1);

    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            if (i<n/2){
                if (j<n/2){
                    c[i][j] = c11[i][j];
                }

                else{

                    c[i][j] = c12[i][j-(n/2)];

                }
            }
            else{

                if (j<n/2){

                    c[i][j] = c21[i-(n/2)][j];
                }

                else {
                    c[i][j] = c22[i-(n/2)][j-(n/2)];
                }
            }
        }
    }


    return c;
}




int main(int argc, char const *argv[])
{
    int** matA = new int*[8];
    for (int i = 0; i < 8; i++){
        matA[i] = new int[8];
        for (int j=0;j<8;j++){
            matA[i][j] = i+j;
        }
    }
    
  
    int** matB;
    matB = new int*[8];
    for (int i = 0; i < 8; i++){
        matB[i] = new int[8];
        for (int j=0;j<8;j++){
            matB[i][j] = i-j;
        }
    }

    int** ans = recursive(matA,matB,{0,7},{0,7},{0,7},{0,7});
    int** ans2 = bruteForce(matA,matB,{0,7},{0,7},{0,7},{0,7});
    int** ans3 = strassen(matA,matB,8);


    printMat(ans,{8,8}); 
    cout<<" "<<endl;
    printMat(ans2,{8,8});  
    cout<<" "<<endl;
    printMat(ans3,{8,8});   

}