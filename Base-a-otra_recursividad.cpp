#include<math.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<fstream>

using namespace std;
string Hexa(int N){
    string n;
    switch (N){
        case 10: n="A"; break;
        case 11: n="B"; break;
        case 12: n="C"; break;
        case 13: n="D"; break;
        case 14: n="E"; break;
        case 15: n="F"; break;
        default: n=to_string(N);
        }
    return n;
}

string DecHexa(int N){
    string result=Hexa(N%16), result2=Hexa(N/16), n=Hexa(N);
        
    if(N<16){
        return n;
    }else{ if(N/16<16){
        return result2 + result;
    }else{
        return DecHexa(N/16) + result;
    }}
}

int DecOctal(int N){
    int result=N%8;
    if(N<8){
        return N;
    }else{ if(N/8<8){
        return (N/8)*10 + N%8;
    }else{
        return DecOctal(N/8)*10 + result;
    }}
}

int DecBin(int N){
    int result=N%2;
    if(N<2){
        return N;
    }else{ if(N/2<2){
        return (N/2)*10 + N%2;
    }else{
        return DecBin(N/2)*10 + result;
    }}
}

int HexDec(int N){
    
}

int OctalDec(int N){
    
}

int BinDec(int N){
    int indice=0, n=N, result=0;
    while(n!=0){
        indice++;
        n=n/10;
    }
    if(N/10==0){
        result=N*pow(2,indice);
        return result;
    }else{
        result=BinDec(N/10)+N%(10*(indice-1))*pow(2,10*(indice-1));
        return result;
    }
}

int main() {

	int N,B, result;
	string Result="";

	cout<<"Ingrese el numero: ";
	cin>>N;
	cout<<endl;

	while (N<=0) {
		cout<<"Ingrese un numero valido: ";
		cin>>N;
		cout<<endl;
	}


	cout<<"Ingrese la base: ";
	cin>>B;

	if(B==10) {
		Result = DecHexa(N);
		cout<<endl<<"El numero "<<N<<" en hexadecimal es #"<<Result<<endl;
		result = DecOctal(N);
		cout<<"El numero "<<N<<" en octal es "<<result<<endl;
		result = DecBin(N);
		cout<<"El numero "<<N<<" en binario es "<<result<<endl;
	}else{ if(B==16){
	    result = HexDec(N);
		cout<<"El numero "<<N<<" en decimal es "<<result<<endl;
	}else{if(B==8){
	    result = OctalDec(N);
		cout<<"El numero "<<N<<" en decimal es "<<result<<endl;
	}else{if(B==2){
	    result = BinDec(N);
		cout<<"El numero "<<N<<" en decimal es "<<result<<endl;
	}else{
	    cout<<"Base invalida"<<endl;
	}
	}}}

	return 0;
}