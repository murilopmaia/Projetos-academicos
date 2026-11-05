float multi(float x,int n){
    if(n == 0){
        return 0;
    }
    else{
        return x + multi(x,n-1);
    }
}

int main(){
    printf(" %.2f ",multi(2.5,3));
    return 0;
}