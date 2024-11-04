#include <iostream>
#include "math.h"
using namespace std;
float funcao(float x){
    return pow(2.71828,2);
}

float baseCalc(float a,float b,int n){
    //n = quantidade de quadrados
    return (b-a)/n;
}

float calculoMedia(float xn,float xn1){
    return (xn + xn1)/2;
}

int retangulo(){
    float a,b,base,somatorioAltura,altura,media;
    int n,currentIteraction(0);

    cout << "Integracao numerica" << endl;
    cout << "Insira o intervalo a: ";
    cin >> a;
    cout << "Insira o intervalo b: ";
    cin >> b;
    cout << "Numero de particoes: ";
    cin >> n;
    base = baseCalc(a,b,n);
    cout << "Tamanho da base: " << base << endl;

    do{
        if(currentIteraction == 0){//Na primeira iteração vou partir do ponto a e nas demais utilizar o Xn-1
            media = calculoMedia(a,base);
        }else{
            media += base;//Pula da metade de um retangulo para o outro
        }
        altura = funcao(media);
        somatorioAltura +=altura;
        if(n <=100){//Limitar a quantidade de informação no console - deixar o programa mais rapido
            cout << "Iteracao: " << currentIteraction << endl;
            cout << "Media: " << media << endl;
            cout << "Funcao da media: " << altura << endl;
        }

        currentIteraction +=1;
    }while(currentIteraction < n);//Rodar até n-1
    cout << "Somatorio da altura das alturas: " << somatorioAltura << endl;
    cout << "Area de baixo da funcao e: " << base*somatorioAltura << endl;
}

int simpsom(){
    float a,b,base,somatorioFxConstante,fxConstante,mediaX;
    int n,currentIteraction(0);

    //A numero de baixo, B numero de cima
    cout << "Insira o valor de a: ";
    cin >> a;
    cout << "Insira o valor de b: ";
    cin >> b;
    cout << "Insira a quantidade de reparticoes: ";
    cin >> n;

    base = baseCalc(a,b,n);   
    mediaX = a;
    //Rodar loop de A até b utilizando o valor da base para pular de iteração;
    cout << "Tamanho da base: " << base <<endl;

    do{
        //Primeira e ultima iteração as constantes são 1
        //As demais iterações intercalam entre 4 e 2
        if(currentIteraction==0||currentIteraction == n){
            fxConstante += funcao(mediaX);
        }else{
            if(currentIteraction % 2 == 0){
                
                fxConstante += funcao(mediaX) *2;
            }else{
                fxConstante += funcao(mediaX)*4;
            }
        }
        
        cout << "Iteracao: " << currentIteraction <<endl;
        cout << "Media: " << mediaX <<endl;
        cout << "Funcao da media: " << fxConstante <<endl;

        mediaX += base;
        somatorioFxConstante +=fxConstante;
        fxConstante=0;
        currentIteraction +=1;
    }while(currentIteraction <= n);
    cout << "Somatorio: " << somatorioFxConstante <<endl;
    system("pause");
    return 0;
}

int trapezio(){

    //O loop nessa funcao irá rodar até n, porém o calculo será feito até n+1
    //O calculo utilizará constantes, na primeira e ultima iteração, o f(X) será multiplicado por 1, nas demais será multiplicado por 2
    int n,currentIteraction(0);
    float a,b,base,x,fx,somatorioFx;
    cout<< "Integracao numerica\nRegrados Trapezios\n";
    cout << "Insira o valor de a:" ;
    cin >> a;
    cout << "Insira o valor de b:";
    cin >> b;
    cout << "Insira o numero de trapezios:";
    cin >> n;
    base = baseCalc(a,b,n);
    cout << "Tamanho da base: " << base << endl;
    x = a;

    do{
        if(currentIteraction == 0 || currentIteraction == n){//Somatorio de F(x)
            //Constante 1
            fx = funcao(x);
            somatorioFx +=fx;
            fx=0;
        }else{
            //Constante 2
            fx = funcao(x);
            fx=fx*2;
            somatorioFx +=fx;
            fx=0;
        }
        cout << "Iteracao " << currentIteraction << endl;
        cout << x << endl;   
        x += base;
        currentIteraction += 1;
    }while(currentIteraction <= n);
    cout << "Somatorio da F(X): "  << somatorioFx << endl;
    cout << "T(hm): " << base/2 *somatorioFx <<endl;

}

int menu(){
    int op;
    cout << "1 - Retangulo"<<endl;
    cout << "2 - Trapezio"<<endl;
    cout << "3 - Simpsom"<<endl;
    cout << "0 - Sair"<<endl;
    cout << "Escolha: ";
    cin >> op;
    return op;
}

int main(){

    int op(0);
    do{
        op = menu();
        switch (op)
        {
        case 1://Ret
            retangulo();
            break;
        
        case 2://Tr
            trapezio();
            break;
        
        case 3://Simp
            simpsom();
            break;
        case 0:
            //Só para não aparecer o default quando sair do programa
            break;
        default:
            cout << "Insira uma opcao valida";
            break;
        }

    }while(op!=0);

    return 0;
}