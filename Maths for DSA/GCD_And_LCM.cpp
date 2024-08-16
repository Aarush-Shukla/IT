int gcd(int a,int b){
    // a%b
    if(a%b==0){
        return b;
    }
    return gcd(b,a%b);
}

a*b=gcd(a,b)*lcm(a,b);