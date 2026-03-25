#include <iostream>
using namespace std;

class AutoBus {
private:
    double combustible;
    int asientos;
    double tarifa;
    int pasajeros;

    const double MAX_COMBUSTIBLE = 100.0;

public:
    AutoBus() {
        combustible = 0;
        asientos = 50;
        tarifa = 1.0;
        pasajeros = 0;
    }

    AutoBus(double comb) {
        if (comb >= 0 && comb <= MAX_COMBUSTIBLE)
            combustible = comb;
        else
            combustible = 0;

        asientos = 50;
        tarifa = 1.0;
        pasajeros = 0;
    }

    AutoBus(double comb, int asi, double tar) {
        combustible = (comb >= 0 && comb <= MAX_COMBUSTIBLE) ? comb : 0;
        asientos = (asi > 0) ? asi : 50;
        tarifa = (tar >= 0) ? tar : 1.0;
        pasajeros = 0;
    }

    void recogerPasajeros(int nroPasajeros) {
        if (nroPasajeros < 0) {
            cout << "Error: pasajeros negativos no permitidos\n";
            return;
        }

        if (pasajeros + nroPasajeros <= asientos) {
            pasajeros += nroPasajeros;
        } else {
            cout << "Error: no hay suficientes asientos\n";
        }
    }

    void recargarGasolina(double cantidad) {
        if (cantidad < 0) {
            cout << "Error: cantidad negativa no permitida\n";
            return;
        }

        if (combustible + cantidad <= MAX_COMBUSTIBLE) {
            combustible += cantidad;
        } else {
            combustible = MAX_COMBUSTIBLE;
            cout << "Se llenó el tanque al máximo (100)\n";
        }
    }

    int calcularCantidadAsientosDisponibles() const {
        return asientos - pasajeros;
    }

    bool hayEspacio() const {
        return pasajeros < asientos;
    }

    bool estaVacio() const {
        return pasajeros == 0;
    }

    double calcularMontoRecaudado() const {
        return pasajeros * tarifa;
    }

    double getCombustible() const {
        return combustible;
    }
};

int main() {
    AutoBus bus(50, 40, 2.50);

    bus.recogerPasajeros(15);

    cout << "Asientos disponibles: "
         << bus.calcularCantidadAsientosDisponibles() << endl;

    cout << "¿Hay espacio?: "
         << (bus.hayEspacio() ? "Si" : "No") << endl;

    bus.recargarGasolina(20);

    cout << "Combustible actual: "
         << bus.getCombustible() << endl;

    cout << "Monto recaudado: "
         << bus.calcularMontoRecaudado() << endl;

    return 0;
}
