Sistema de inventario en C
Proyecto académico · ISWZ1102 · Programación 1 · UDLA
Aplicación de consola para registrar hasta 10 productos y consultar sus nombres y precios. El proyecto aplica arreglos, ciclos, condicionales y comparación de cadenas para resolver un problema básico de inventario.
Contexto académico
Campo
Información
Universidad
Universidad de las Américas — UDLA
Asignatura
ISWZ1102 — Programación 1
Docente
Carlos Andrés Guaita Ayala
Lenguaje
C
Archivo principal
Inventario.c
Objetivo: reforzar el análisis de problemas para plantear una solución computacional y justificar la elección de una representación basada en arreglos.
Integrantes
Anthony López
Angie Cañizares
Leandro Macías
Natan Oña
Funcionalidades
Opción
Operación
1
Registrar un producto con su nombre y precio
2
Mostrar los productos registrados
3
Calcular el precio total del inventario
4
Identificar el producto más caro y el más barato
5
Calcular el precio promedio
6
Buscar un producto por su nombre y mostrar su precio
Después de cada operación, el programa solicita 1 para continuar o 2 para salir. En la implementación actual, cualquier entero distinto de 1 termina el ciclo.
Diseño de la solución
El programa utiliza arreglos paralelos:
#define N_PRODUCTOS 10

char nombres[N_PRODUCTOS][20];
float precios[N_PRODUCTOS] = {0};
int contP = 0;
​
El mismo índice relaciona el nombre y el precio de un producto. Por ejemplo, nombres[0] y precios[0] pertenecen al primer registro. La variable contP indica cuántos productos existen y cuál es la siguiente posición disponible.
Se conservan los productos en el orden de registro y se utiliza una búsqueda secuencial. Para un máximo de diez productos, esta alternativa evita la lógica adicional de ordenar y desplazar ambos arreglos. La búsqueda y los cálculos recorren como máximo los diez registros.
No se definen estructuras (struct) ni variables de tipo puntero. La entrada estándar con scanf utiliza el operador & para proporcionar las direcciones requeridas por esa función.
Requisitos
Un compilador de C compatible con C11, como GCC.
Una terminal para compilar y ejecutar el programa.
No se requieren bibliotecas externas.
Compilación y ejecución
Descarga Inventario.c o clona el repositorio. Abre una terminal en la carpeta que contiene el archivo.
Linux y macOS con GCC disponible
gcc -std=c11 -Wall -Wextra Inventario.c -o inventario
./inventario
​
Windows con GCC disponible
Compila desde PowerShell:
gcc -std=c11 -Wall -Wextra Inventario.c -o inventario.exe
.\inventario.exe
​
Ejemplo de uso
Registra los siguientes productos mediante la opción 1. Introduce 1 cuando el programa pregunte si deseas continuar.
Producto
Precio
Pan
1.50
Leche
2.25
Arroz
3.00
Las consultas deben producir estos resultados:
Precio total del inventario: 6.75
Producto mas caro: Arroz (3.00)
Producto mas barato: Pan (1.50)
Precio promedio: 2.25
Producto encontrado: Leche - Precio: 2.25
​
Cada línea corresponde a su respectiva opción del menú. Para obtener la última, selecciona la opción 6 e introduce Leche.
El total suma los precios registrados. El programa no administra cantidades, ventas ni ganancias.
Validaciones implementadas
Limita el inventario a diez productos.
Rechaza nombres con caracteres que no sean letras o espacios.
Rechaza precios negativos; el precio cero está permitido.
Impide consultar un inventario vacío.
Informa cuando un producto no existe o la opción numérica del menú es inválida.
Pruebas realizadas
El archivo se compiló con -std=c11 -Wall -Wextra sin advertencias. Se verificaron:
Registro y listado de los tres productos del ejemplo.
Total de 6.75 y promedio de 2.25.
Identificación del mayor y menor precio.
Búsqueda de un producto existente y uno inexistente.
Inventario vacío, nombre con números y precio negativo.
Rechazo de un undécimo producto y de una opción numérica inválida.
Búsqueda con distintas mayúsculas y empate de precios.
Comportamientos y limitaciones
Los datos se almacenan en memoria y se pierden al cerrar el programa.
Los nombres admiten hasta 19 bytes más el terminador nulo.
La búsqueda es exacta y distingue mayúsculas y minúsculas.
Se permiten nombres duplicados; la búsqueda muestra la primera coincidencia.
En un empate de precios, se conserva el primer producto como extremo.
La aceptación de letras con tilde depende de la configuración regional y la codificación.
No se comprueba el retorno de scanf; una entrada no numérica puede afectar las lecturas siguientes.
Un nombre demasiado largo puede dejar caracteres pendientes en la entrada.
float puede introducir aproximaciones en valores monetarios.
