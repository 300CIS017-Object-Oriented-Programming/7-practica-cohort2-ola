# Sistema de Gestión de Propiedades

## Descripción
Este proyecto es un sistema de administración para el conjunto residencial "Bosques de Niza". Su objetivo es gestionar el cobro de administración a los propietarios de apartamentos, teniendo en cuenta distintos factores como el uso de ascensores, área del apartamento, parqueadero y la existencia de cuartos útiles.

## Clases Principales
El sistema se basa en cuatro clases principales:

### 1. **CuartoUtil**
   - Representa un cuarto útil asociado a una propiedad.
   - Atributos:
     - `numeracion`: Identificador del cuarto útil.
     - `piso`: Piso donde se encuentra.
     - `estaTerminado`: Indica si el cuarto útil está terminado.
   - Métodos:
     - `imprimirInfoEstadoCuarto()`
     - `mostrarDatos()`

### 2. **Propiedad**
   - Representa un apartamento dentro del conjunto residencial.
   - Atributos:
     - `numIdentificacion`: Número identificador del apartamento.
     - `piso`: Piso donde se ubica.
     - `areaPropiedad`: Área en metros cuadrados.
     - `hayParqueadero`: Indica si tiene parqueadero.
     - `cuartoUtil`: Puntero a un objeto `CuartoUtil`.
   - Métodos:
     - `calcularRecargo(float cobroAscensor, float costoBase, float recargo)`
     - `mostrarDatos()`

### 3. **Propietario**
   - Representa a un propietario dentro del sistema.
   - Atributos:
     - `identificacion`: Número de identificación del propietario.
     - `nombre`: Nombre del propietario.
     - `propiedad`: Puntero a la propiedad que posee.
   - Métodos:
     - `mostrarDatos()`

### 4. **Administracion**
   - Maneja el sistema y administra los cobros de los apartamentos.
   - Atributos:
     - `cobroAscensor`: Costo del uso del ascensor por piso.
     - `costoBase`: Costo mensual base de administración.
     - `recargo`: Recargo aplicado a propiedades mayores de 150 m².
     - `contIdls`: Contador de identificaciones.
     - `propietarios`: Vector de objetos `Propietario`.
     - `propiedades`: Vector de objetos `Propiedad`.
   - Métodos:
     - `imprimirUnPropietario(double id)`
     - `imprimirPropietariosConParqueadero()`
     - `imprimirPropietarios()`
     - `recaudarAdministracion()`
     - `agregarPropiedad()`
     - `agregarPropietario()`
     - `relacionarPropietarioPropiedad()`

## Nota Importante
La implementación actual **no incluye todos los detalles de la imagen del diagrama de clases**, por lo que algunas funcionalidades pueden estar ausentes o ser diferentes.
