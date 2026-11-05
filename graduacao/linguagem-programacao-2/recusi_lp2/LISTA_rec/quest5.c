int MDC(int x,int y){
    if(x>=y && x%y==0){
        return y;
    }
    else if(x<y){
        return MDC(y,x);
    }
    else{
        return MDC(y,x%y);
    }
}

int main(){
    printf(" %d ",MDC(8,12));
    return 0;
}