#include <iostream>
using namespace std;

class CuentaBancaria {
     private:
     int id;
     string nroCuenta;
     double saldo;

     public:
     string propietario;

     CuentaBancaria(int _id, string _nroCuenta, string _propietario) {
          id = _id; 
          nroCuenta = _nroCuenta;
          propietario = _propietario;
          saldo = 0.0;
     }

     void depositar(double monto) {
          if(monto <= 0) {
               cout << "Error no se permiten montos negativos o cero" << endl;
               return;
          }

          saldo += monto;
     }

     bool retirar(double monto) {
          if(monto <= 0) {
               cout << "Error monto invalido" << endl;
               return false;
          }

          if(monto > saldo) {
               cout << "Error fondos insuficientes" << endl;
               return false;
          }

          saldo -= monto;
          cout << "Retiro de cuenta " << propietario << ": confirmado" << endl;
          return true;
     }

     void transferir(CuentaBancaria &destino, double monto) {
          if(this == &destino) {
               cout << "Error no se puede transferir a la misma cuenta" << endl;
               return;
          }
          cout << "ejecutando tranferencia"<< endl;
          cout << "Monto solicitado: $" << monto << endl;
          if(retirar(monto)) {
               destino.depositar(monto);
               cout << "Deposito en cuenta " << destino.propietario << ": confirmado" << endl;
               cout << "Resultado: Operacion completada con exito." << endl;
          } else {
               cout << "Transferencia fallida" << endl;
          }
     }

     void verEstado() {
          cout << "Cuenta " << nroCuenta << " | titular: " << propietario << " | saldo actual: $" << saldo << endl;
     }
};
int main() {
     CuentaBancaria cuentaA(1, "001", "Diogo Mamani");
     CuentaBancaria cuentaB(2, "002", "Xavier Condori");
     cuentaA.depositar(1000);
     cout << "estado Inicial" << endl;
     cuentaA.verEstado();
     cuentaB.verEstado();
     cout << "Intentando retirar 2000..." << endl;
     cuentaA.retirar(2000);
     cuentaA.transferir(cuentaB, 450);
     cout << "Estado Final" << endl;
     cuentaA.verEstado();
     cuentaB.verEstado();
     return 0;
}
