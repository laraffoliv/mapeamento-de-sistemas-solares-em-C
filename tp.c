#include<stdlib.h>  //bibliotecas que serão utilizadas ao longo do código
#include<stdio.h>
#include<stdbool.h> //biblioteca de booleanos, muito importante para a implementação da função de compração
#include<string.h>
typedef struct lua { //define uma estrutura de dados para a lua, dessa forma, cada lua possui um nome e um tamanho
    char *nome;       // o typedef é usado para definir a lua como um tipo, assim, fica mais fácil preencher os dados de cada lua na função main posteriormente
    int tamanho;
} lua;

typedef struct planeta { //define uma estrutura de dados para o planeta, dessa forma, cada planeta possui um nome, um tamanho e uma determinada quantidade de luas
    char *nome;          //novamente o typedef é utilizado para definir a estrutura de dados "planeta" como um tipo
    int tamanho;
    lua *luas;
    int qtdluas;
} planeta;

typedef struct sistema {  //estrutura de dados para o sistema, dessa forma, cada sistema possui um nome, um tamanho, um tempo de descoberta e uma determinada quantidade de planetas
    char *nome;            //novamente, o typedef é utilizado para definir a estrutura de dados planeta como um tipo
    int tamanho;
    int tempodescoberta;
    planeta *planetas;
    int qtdplanetas;
}sistema;

int maiorplaneta (sistema a){        //função para encontrar o maior planeta de um dado sistema
    int mt=0;                     //o "for" é usado para percorrer todos os planetas do sistema "a" e, por meio da variável auxiliar "mt", retorna o maior planeta ao fim da função
        for(int i =0;i<a.qtdplanetas;i++){                              //a variável auxiliar "mt" é inicializada como mt=0 para acabar com problemas de lixo eletrônico no valor da variável
                if(a.planetas[i].tamanho>mt){                             //à medida que o "for" percorre os planetas do sistema "a", ele compara cada elemento do vetor planetas com "mt" e, caso, este elemento seja maior do que "mt", ele se torna o novo maior tamanho (ou mt)
                     mt = a.planetas[i].tamanho;                 
        }
}
return mt; //com isso, ao fim da função, é retornado o maior tamanho
}

int maiorlua (sistema a){                            //essa função segue o mesmo princípio da função anterior, contudo, percorre todos os planetas do sistema "a" e todas as luas deste mesmo sistema, asism, seu objetivo é encontrar a maior lua do sistema "a"
    int ml = 0;  //da mesma forma da função anterior, a variável ml (ou maior lua) é inicializada como ml = 0 para solucionar problemas de lixo eletrônico no valor da variável
        for(int i=0;i<a.qtdplanetas;i++){  //"for" percorrendo todos os planetas do sistema a
            for(int j =0;j<a.planetas[i].qtdluas;j++){ //"for" percorrendo todas as luas do sistema a
                   if(a.planetas[i].luas[j].tamanho>ml){
                    ml = a.planetas[i].luas[j].tamanho; //assim como na função anterior, o if verifica se cada lua do sistema é maior do que ml e, quando, são encontradas luas maiores do que ml, tal lua se torna a nova maior lua
                   }
        }
}
return ml; //retorna a maior lua de um dado sistema
}
bool comparacao (sistema a, sistema b){  //função para comparar dois sistemas, para verificar se o sistema a é maior do que o sistema b. true se a for maior e false se b for maior
    if(a.tamanho > b.tamanho){ //aqui, utiliza-se as variáveis booleanas, dessa forma, se o sistema a for maior do que o sistema b, a função retornará true
        return true;

    }
     else if (b.tamanho>a.tamanho){  //da mesma forma, se o sistema b for maior do que o sistema a, a função retornará false

    return false;
    }
    if(a.qtdplanetas> b.qtdplanetas){ //se a quantidade de planetas de a for maior, retornará true
        return true;
    }
    else if(b.qtdplanetas>a.qtdplanetas){ //se a quantidade de planetas de b for maior, retornará false, pois o sistema b é maior do que a
        return false;
    }
    int x = maiorplaneta(a); //chama a função maior planeta para a e armazena seu resultado em uma nova variável x
    int y = maiorplaneta(b); //chama a função maior planeta para b e armazena seu resultado em uma nova variável y
    if(x>y){                  
                return true; //como a função maior planeta foi chamada anteriormente, se x for maior do que y, o sistema a é maior do que o sistema b e por isso a condição retornará true
    }
    if(y>x){ //da mesma forma, como a função maior planeta foi chamada anteriormente, se y for maior do que x, o sistema b é maior do que o sistema a e por isso a condição retornará flase
    return false;
    }
        int z;   //declarando novas variáveis para realizar a compração de sistemas, agora usando o critério da quantidade de luas e planetas
        int v;

        for(int j =0; j<a.qtdplanetas;j++){ //for percorrendo todos os planetas do sistema a
             
                z = z + a.planetas[j].qtdluas; //z recebe a quantidade de luas do sistema a
        }
        for(int i=0;i<b.qtdplanetas;i++){ //for percorrendo todos os planetas do sistema b
            v = v + b.planetas[i].qtdluas; //v recebendo a quantidade de luas do sistema b
        }
        if(z>v){  //se z (quantidade de luas do sistema a) for maior do que v (quantidade de luas do sistema b) retornará true, porque o sistema a é maior do que o sistema b
            return true;
        }
        if(v>z){   //se v (quantidade de luas do sistema b) for maior do que z (quantidade de luas do sistema a) retornará false, porque o sistema b é maior do que o sistema a
            return false;
        }
   int s = maiorlua(a);  //chama a função maior lua para o sistema a, quer achar a maior lua de a, armazena o valor em uma nova variável s
   int r = maiorlua(b);  //chama a função maior lua para o sistema b, quer achar a maior lua de b,armazena o valor em uma nova variável r
   if(s>r){    //se s for maior do que r, retornará true, porque o sistema a é maior
    return true;
   }
   if(r>s){  //se r for maior, retornará false, porque o sistema b é maior
    return false;
   }


    if(a.tempodescoberta<b.tempodescoberta){ //se o tempo de descoberta de a for menor do que o de b, retornará true, porque o sistema a será mais vantajoso
        return true;
    }
    if (b.tempodescoberta<a.tempodescoberta){  //se o tempo de descoberta de b for menor do que o de a, retornará false, porque o sistema b é mais vantajoso
        return false;
    }
    //até esse ponto já eliminamos todos os casos de empate entre os sistemas
}
void trocar(sistema *a, sistema*b){ //função para trocar os valores de a e b
    sistema temp = *a;
    *a = *b;
    *b = temp;
}

int ritacao(sistema * meusSistemas, int baixo, int alto){  //função que realiza o processo de ritação descrito no tp, alto e baixo são variáveis para ajudar no processo
    sistema pivo = meusSistemas[alto];
    int i = (baixo - 1);
    for(int j = baixo; j<=alto-1;j++){
        if(!comparacao(meusSistemas[j],pivo)){ //aqui nega a função comparação, porque é preciso deixar a condição de forma que o valor indexado seja menor do que o pivo e afunção compração verifica se o sistema é maior
            i++;
            trocar(&meusSistemas[i],&meusSistemas[j]);

        }
    }
    trocar(&meusSistemas[i+1],&meusSistemas[alto]);
    return (i+1);
}
void bromerosort(sistema *meusSistemas,int baixo, int alto){ //implementação do algoritmo rápido para o bromerosort, utilizando as variáveis auxiliares auto, baixo e uma nova variável chamada pi
    if(baixo<alto){
        int pi; //pi é o pivo
         pi = ritacao(meusSistemas,baixo,alto);
         bromerosort(meusSistemas,baixo,pi-1);
         bromerosort(meusSistemas,pi+1,alto);
    }
}

int main(){
    int qtdsistemas;
    scanf("%d",&qtdsistemas);
    sistema *meusSistemas = malloc(qtdsistemas * sizeof(sistema)); //entrada para a quantidade de sistemas, juntamente com um malloc para estipular o máximo de memória alocada 

    for(int i=0;i<qtdsistemas;i++){
        int tamanho; int qtdplanetas; int tempodescoberta;
        meusSistemas[i].nome = malloc(200 *sizeof(char));
        scanf("%d %s %d %d",&tempodescoberta, meusSistemas[i].nome, &tamanho, &qtdplanetas);
        meusSistemas[i].tamanho = tamanho;
        meusSistemas[i].tempodescoberta = tempodescoberta; 
         meusSistemas[i].planetas = malloc(qtdplanetas * sizeof(planeta));
         meusSistemas[i].qtdplanetas = qtdplanetas;
//entrada para o nome do sistema, tempo de descoberta, tamanho e quantidade de planetas
//usa-se malloc para estipular o máximo de memória alocada para cada variável

        for (int j = 0; j<qtdplanetas;j++){ //entrada para a quantidade de planetas, usa-se malloc para estipular o máximo de memória alocada para essa variável
         int raio; int qtdluas;
         meusSistemas[i].planetas[j].nome = malloc(100*sizeof(char)); //malloc para estipular o tamanho máximo que um planeta pode ter, no caso, o tamanho de 100 char
            scanf("\t%s %d %d",meusSistemas[i].planetas[j].nome,&raio,&qtdluas); //entrada para o nome, raio e quantidade de luas do planeta
            meusSistemas[i].planetas[j].luas = malloc(qtdluas * sizeof(lua)); //malloc para estipular o tamanho máximo que a quantidade de luas pode ter
            meusSistemas[i].planetas[j].qtdluas = qtdluas;
            meusSistemas[i].planetas[j].tamanho = raio;

            for(int k=0; k<qtdluas; k++){ //entrada para a quantidade de luas
                int tamanholua;
                meusSistemas[i].planetas[j].luas[k].nome = malloc (100 *sizeof(char)); //malloc para estipular o tamanho máximo do nome de que cada lua pode ter
                scanf("\t\t%s %d",meusSistemas[i].planetas[j].luas[k].nome,&tamanholua); //inserindo o nome e tamanho da lua
                meusSistemas[i].planetas[j].luas[k].tamanho = tamanholua;
            }
        }
        }
        bromerosort(meusSistemas,0,qtdsistemas - 1); //bromerosort é chamado para ordenar os sistemas de acordo com os critérios e em ordem decrescente
        for(int i =qtdsistemas-1; i>=0;i--){
        fputs(meusSistemas[i].nome,stdout);
        putchar('\n');
        }

        for (int i = 0; i < qtdsistemas; i++) { //a partir daqui utiliza-se o free para liberar memória alocada
        free(meusSistemas[i].nome);

        for (int j = 0; j < meusSistemas[i].qtdplanetas; j++) {
            free(meusSistemas[i].planetas[j].nome);

            for (int k = 0; k < meusSistemas[i].planetas[j].qtdluas; k++) {
                free(meusSistemas[i].planetas[j].luas[k].nome);
            }

            free(meusSistemas[i].planetas[j].luas);
        }

        free(meusSistemas[i].planetas);
    }

    free(meusSistemas);

    return 0;
}
