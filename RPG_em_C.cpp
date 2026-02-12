#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int roll(int x,int y){
    int random_number = 1 + (rand() % (x - y + 1));

    return random_number;
}    

struct Entidade {
    string name;
    int vida;
    int dt;
    int dano_min;
    int dano_max;
};

struct Zumbi : Entidade {
    Zumbi() {
        name = "Zumbi";
        vida = 30;
        dt = 15;
        dano_min = 1;
        dano_max = 6;
    }
};

struct Player : Entidade {
    Player() {
        name = "Player";
        vida = 60;
        dt = 10;
        dano_min = 1;
        dano_max = 12;
    }
};

struct DT{
    int t_min = 1;
    int t_max = 20;
};

int teste(DT dificuldade){
    return roll(dificuldade.t_min,dificuldade.t_max);
}

int ataque(Entidade* ptr, int dt){
    DT dificuldade;
    int dt_teste = teste(dificuldade);
    int dano = 0;
    if (dt_teste >= dt){
        dano = roll(ptr->dano_min,ptr->dano_max);
        cout << ptr->name << " - Causa " << dano << " de dano \n";
    }
    else{
        cout << ptr->name << " - Errou \n";
    }
    return dano;
}

void esquiva(Entidade* ptr){
    cout << ptr->name << " - Tenta Esquivar \n";
    ptr->dt += 5;
}

void config(Entidade* ptr){
    int menu;
    
    system("cls");
    cout << "Vc esta modificando o " << ptr->name;
    cout << "\n1 para mudar a vida \n2 para mudar a dt \n3 para mudar o dano max da arma \n";
    cin >> menu;
    if(menu == 1){
        cout << "A nova vida sera: ";
        cin >> ptr->vida;
    }
    if(menu == 2){
        cout << "A nova dt sera: ";
        cin >> ptr->dt;
    }
    if(menu == 3){
        cout << "O dano max da arma sera: ";
        cin >> ptr->dano_max;
    }          
}

int main(){
    Zumbi z1;
    Player p1;
    DT dificuldade;
    bool game = true;
    int dano;
    int teste;

    int* ptr;

    while(game){
        int op;
        int decisao;
        int menu;

        system("cls");
        // opções do menu
        cout << "1 Start \n2 Configurar \n3 Creditos \n4 Sair \n";
        cin >> op;
        // switch define a opção selecionada, menu do jogo
        switch (op){
            case 1:
                system("cls");
                cout << "Insira seu Nick: ";
                cin.ignore();
                getline(cin,p1.name);

                cout << "Que começe os jogos\n";
                cout << "Voce esta contra 1 zumbi\n";
                
                while(z1.vida > 0 || p1.vida > 0){
                    
                    cout << "1 Atacar \n2 Desviar \n";
                    cin >> decisao;

                    if(decisao == 1){
                        system("cls");
                        dano = ataque(&p1,z1.dt);
                        z1.vida -= dano;
                    }
                    else if(decisao == 2){
                        system("cls");
                        esquiva(&p1);
                    }
                    else{
                        system("cls");
                        continue;
                    }

                    if(z1.vida <= 0){
                        cout << "Win \nParabens " << p1.name;
                        cin >> menu;
                        break;
                    }

                    if (z1.vida > 0 && p1.vida > 0){
                        dano = ataque(&z1,p1.dt);
                        p1.vida -= dano;
                        if(decisao == 2){
                            p1.dt -= 5;
                        }
                    }
                    
                    if(p1.vida <= 0){
                        cout << "Lose \nNao foi dessa fez " << p1.name;
                        cin >> menu;
                        break;
                    }
                }
                break;
                
            case 2:
                system("cls");
                cout << "Aqui vc pode aumentar a dificuldade \n";
                cout << "1 para modificar o player \n2 para modificar o zumbi \n3 para mudar o teste de DT";
                cin >> menu;
                switch (menu){
                    case 1:
                        config(&p1);
                        menu = 0;
                        break;
                    case 2:
                        config(&z1);
                        menu = 0;
                        break;
                    case 3:
                        cout << "Informe valor minimo e valor maximo para a nova DT";
                        cin >> dificuldade.t_min >> dificuldade.t_max;
                    default:
                        break;
                }

            case 3:
                system("cls");
                cout << "Created by Carlos Eduardo \n\n";
                cout << "digite 0 para voltar ao menu";
                cin >> menu;
                break;

            case 4:
                cout << "Sair";
                game = false;
                break;
        }
    }

    return 0;
}