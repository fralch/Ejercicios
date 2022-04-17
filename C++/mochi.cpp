
#include <iostream>

using namespace std;

class Producto {
 public:
    int stock=0,
        clientes_atendidos =0,
        cantidad_pedidos = 0,
        total_unidades_vendidas,
        total_unidades_descontadas=0,
        pedido_actual;
    
    std::string nombre;

    float   precio, 
            porcentaje_descuento,
            monto_bruto,
            monto_descuento,
            monto_neto, 
            monto_total_vendido=0;
  
    Producto(){
        std::cout << "Iniciando venta\n";
    }
    Producto(std::string nombre, int stock, float precio) {
        this->nombre = nombre;
        this->stock = stock;
        this->precio = precio;
    }
    void set_pedido_actual( int pedido_actual) {
      this->pedido_actual = pedido_actual;
      }

    std::string  get_producto(){
      return this->nombre; 
    }

    void calculos(){
      if(this->stock > this->pedido_actual){
        this->stock = this->stock - this->pedido_actual;
        this->monto_bruto = this->precio * this->pedido_actual;
        this->monto_descuento = this->monto_bruto * this->porcentaje_descuento;
        this->monto_neto = this->monto_bruto - this->monto_descuento;
        this->total_unidades_vendidas = this->stock - this->pedido_actual;
        this->total_unidades_descontadas ++;
        this->clientes_atendidos = this->clientes_atendidos + 1;
        this->cantidad_pedidos = this->cantidad_pedidos + 1;
        this->monto_total_vendido = this->monto_total_vendido + this->monto_neto;
        }else{
          std::cout << "No hay stock suficiente\n";
        }
    }
    void mostrar_datos(){
      std::cout << "Producto: " << this->nombre << "\n";
      std::cout << "Stock: " << this->stock << "\n";
      std::cout << "Precio: " << this->precio << "\n";
      std::cout << "Pedido actual: " << this->pedido_actual << "\n";
      std::cout << "Monto bruto: " << this->monto_bruto << "\n";
      std::cout << "Monto descuento: " << this->monto_descuento << "\n";
      std::cout << "Monto neto: " << this->monto_neto << "\n";
      std::cout << "Total unidades vendidas: " << this->total_unidades_vendidas << "\n";
      std::cout << "Total unidades descontadas: " << this->total_unidades_descontadas << "\n";
      std::cout << "Clientes atendidos: " << this->clientes_atendidos << "\n";
      std::cout << "Cantidad de pedidos: " << this->cantidad_pedidos << "\n";
    }
  void resultados() {
    std::cout << "Cantidad de pedidos " << this->cantidad_pedidos << "\n";
    std::cout << "Clientes atendidos " << this->clientes_atendidos << "\n";
    std::cout << "Cantidad de descuentos otorgados " << this->total_unidades_descontadas << "\n";
    std::cout << "Total unidades vendidas " << this->total_unidades_vendidas << "\n";
    std::cout << "Stock" << this->stock << "\n";
    std::cout << "Monto total vendido " << this->monto_total_vendido << "\n";
  }
};
int main() {

  std::string nombre_ingresado;
  std::string continuar = "si";
  int pedido_ingresado; 


  Producto tv("Tv", 200, 3500);
  Producto celular("Celulares", 1500, 2500);
  Producto equipo("Equipos", 150, 1600);
  
  std::string nombre_tv = tv.get_producto();
  std::string nombre_celular =celular.get_producto();
  std::string nombre_equipo = equipo.get_producto();

  
  while (continuar == "si") {
    std::cout << "Ingrese el nombre del producto: ";
    std::cin >> nombre_ingresado;
    std::cout << "Ingrese la cantidad a comprar: ";
    std::cin >> pedido_ingresado;
    if(nombre_ingresado == nombre_tv){
      tv.set_pedido_actual(pedido_ingresado);
      tv.calculos();
      tv.resultados();
    }else if(nombre_ingresado == nombre_celular){
      celular.set_pedido_actual(pedido_ingresado);
      celular.calculos();
      celular.resultados();
    }else if(nombre_ingresado == nombre_equipo){
      equipo.set_pedido_actual(pedido_ingresado);
      equipo.calculos();
      equipo.resultados();
    }else{
      std::cout << "Producto no encontrado\n";
    }
    std::cout << "Desea continuar? si/no: ";
    std::cin >> continuar;
  }
}
