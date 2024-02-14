<br/>
<h1 align="center">FDF</h1>
<p align="center">
 <img tyle="display: block;-webkit-user-select: none;margin: auto;background-color: hsl(0, 0%, 90%);transition: background-color 300ms;" src="" height=50% width=50%>
</p>

 <p align="center">
    Este es el Readme para el proyecto FDF desarrollado por el equipo de Telefónica 42 en Málaga. Aquí encontrarás una guía detallada sobre la estructura del proyecto, cómo utilizarlo y recursos adicionales para su desarrollo y comprensión.
    <br/>
    <br/>
  </p>
</p>


## Estructura del Proyecto

El proyecto se estructura en varias etapas claves:

1. **Leer Archivo**: Selecciona un archivo de texto que contenga datos para crear un mapa en 3D. Este proceso implica obtener la altura y el ancho del mapa, asignar memoria y leer los números del archivo en una matriz.

2. **Función de Dibujo de Líneas**: Utiliza el algoritmo de Bresenham para dibujar líneas en la pantalla. Este algoritmo calcula los pasos necesarios para aumentar tanto en la coordenada x como en la coordenada y de manera proporcional para obtener líneas diagonales precisas.

3. **Función que Dibuja Líneas entre Cada Punto**: Esta función crea líneas entre cada punto en el mapa, formando una malla o cuadrícula.

4. **Añadiendo 3D**: Se introduce la perspectiva 3D utilizando fórmulas isométricas para cambiar las coordenadas de los puntos en el plano 2D a un espacio tridimensional.

5. **Añadiendo Bonificaciones**: Se implementan mejoras como movimiento, rotación y zoom controlados mediante interacción del teclado.

6. **Manejo de Errores**: Se manejan errores comunes como la falta de argumentos en la línea de comandos o la inexistencia del archivo especificado.

7. **Corrección de Fugas de Memoria**: Se verifica y corrige cualquier fuga de memoria que pueda ocurrir durante la ejecución del programa.

## Recursos

- **Funciones Matemáticas 3D**: Se proporcionan las fórmulas necesarias para convertir las coordenadas a un espacio 3D.
  
- **Funciones mlx**: Se detallan las funciones proporcionadas por la biblioteca mlx utilizada para la manipulación de ventanas y gráficos.

- **Prototipo deal_key**: Se muestra el prototipo de la función utilizada para manejar la interacción del teclado.

- **Colores y Frameworks**: Se especifican los colores disponibles y los frameworks necesarios para compilar el proyecto.

## Uso

Para ejecutar el proyecto, sigue los siguientes pasos:

1. Compila el proyecto utilizando los frameworks especificados.
   
2. Ejecuta el programa proporcionando como argumento el archivo de datos del mapa.
   
3. Utiliza las teclas del teclado según las bonificaciones implementadas para interactuar con el mapa.

Recuerda corregir cualquier fuga de memoria utilizando las herramientas mencionadas.

¡Disfruta explorando el proyecto FDF!

---

*Nota: Este Readme proporciona una visión general del proyecto FDF y no pretende ser una guía exhaustiva. Consulta la documentación y código fuente para obtener detalles específicos de implementación.*
