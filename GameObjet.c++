#include <iostream>
using namespace std;

class GameObject {
     public:
     float x;
     float y;

     GameObject(){
          x = 0;
          y = 0;
     }

     GameObject(float _x, float _y){
          x = _x;
          y = _y;
     }

     void Imprimir(){
          cout << "[" << x << " , " << y << " ]" << endl;
     }

     void ResetTo(char dir){
          if(dir == 'N'){
               y = 5;
          }else if(dir == 'S'){
               y = -5;
          }else if(dir == 'E') {
               x = 10;
          }else if(dir == 'O'){
               x = -10;
          }
     }

void MoverA(char dir, int unidades) {
     if (dir == 'N') {
          y += unidades;
          if (y > 5) y = 5;
     } else if (dir == 'S') {
          y -= unidades;
          if (y < -5) y = -5;
     } else if (dir == 'E') {
          x += unidades;
          if (x > 10) x = 10;
     } else if (dir == 'O') {
          x -= unidades;
          if (x < -10) x = -10;
     }
}
};

int main() {
     GameObject ob1(3, 4);
     GameObject ob2;
     GameObject *pob1;
     GameObject *pob2;
     pob1 = new GameObject(3, 4);
     pob2 = &ob2;
     cout << "Estado inicial" << endl;
     cout << "ob1: ";
     ob1.Imprimir();
     cout << "ob2: ";
     ob2.Imprimir();

     cout << "\npob1 rotando en sentido horario" << endl;
     char reloj[] = {'N', 'E', 'S', 'O'};

     for (int i = 0; i < 4; i++) {
          pob1->ResetTo(reloj[i]);
          cout << "Sentido " << reloj[i] << ": ";
          pob1->Imprimir();
     }

     cout << "\npob2 rotando en sentido antihorario" << endl;
     char contraReloj[] = {'N', 'O', 'S', 'E'};

     for (int i = 0; i < 4; i++) {
          pob2->ResetTo(contraReloj[i]);
          cout << "Sentido " << contraReloj[i] << ": ";
          pob2->Imprimir();
     }

     cout << "\nMovimiento hacia el norte" << endl;
     for (int i = 1; i <= 100; i++) {
          ob1.MoverA('N', 1);
          cout << "Paso " << i << ": ";
          ob1.Imprimir();
     }

     return 0;
}
