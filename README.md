# FDF
Proyecto FDF de Telefónica 42 Málaga

ESTRUCTURA DEL PROYECTO

** ------------------------------------------- Cómo hacer -------------------------------------------
** 1. leer archivo
**      - obtener altura (cuántas líneas tiene el texto)
**      - obtener ancho (cuántos números hay en una línea)
**      - asignar memoria para **int utilizando el ancho y la altura (mira tu ft_strsplit())
**      - leer archivo y escribir números en la matriz **int
**          utilizando ft_strsplit() y atoi()
**	--------------
** 2. función de dibujo de líneas (buscar algoritmo de Bresenham en Google)
**       - determinar cuánto necesitamos aumentar x y cuánto necesitamos aumentar y
**          utilizando flotantes. Ejemplo:
**              x = 2; x1 = 4;
**              y = 2; y1 = 6;
**              pasos para x: 2
**              pasos para y: 4
**              eso significa que y debería crecer dos veces más rápido que x
**              en cada paso del bucle: y += 1 y x += 0.5
**              después de 4 pasos, x e y serán iguales a x1, y1
**
**                  real x:y        x:y     píxeles
**      inicio:     2.0 : 2.0       2:2     .
**      paso1:      2.5 : 3.0       2:3     .
**      paso2:      3.0 : 4.0       3:4      .
**      paso3:      3.5 : 5.0       3:5      .
**      paso4:      4.0 : 6.0       4:6       .
**
**              esto funciona porque (float)2.5 se convierte en (int)2 en la función mlx_pixel_put()
** --------------                                                                  |
** 3. función que dibuja líneas entre cada punto
**      - ejemplo:
**              0->     0->     0->     0
**              |       |       |       |
**
**              0->     10->    10->    0
**              |       |       |       |
**
**              0->     10->    10->    0
**              |       |       |       |
**
**              0->     0->     0->     0
**          '->' y '|' son líneas entre puntos
**          cada punto tiene dos líneas (derecha y abajo): 0->
** ----------------
** 4. añadiendo 3D
**      - cambiar coordenadas utilizando fórmulas isométricas:
**          x' = (x - y) * cos(ángulo) 
            y' = (x + y) * sin(ángulo) - z
**      - x' e y'` son coordenadas en formato 3D (ángulo predeterminado 0.8)
**	----------------
**  5. añadiendo bonificaciones (movimiento, rotación, zoom)
**      - cuando presionas un botón en el teclado, la función mlx_key_hook(win_ptr, deal_key, NULL);
**          llama a la función deal_key.
**      - En la función deal_key, debes cambiar algunos parámetros, borrar la ventana con
**          mlx_clear_window(mlx_ptr, win_ptr); y redibujar la imagen
** ----------------
**  6. manejo de errores
**      - verificar si argc == 2
**      - verificar si el archivo existe: if ((fd = open(file_name, O_RDONLY) > 0))
** ----------------
**  7. corregir fugas de memoria
**      - escribe leaks a.out o leaks fdf en tu terminal



**  ------------------------------- resourses --------------------------------
**	--------------- 3D ------------------------------------------
**		x` = (x - y) * cos(angle);
**		y` = (x + y) * sin(angle) - z;
**	-------------------------------------------------------------
** 	------- mlx_function ----------------------------------------
**		void *mlx_ptr;
**		void *win_prt;
**
**		mlx_ptr = mlx_init();
**		win_prt = mlx_new_window(mlx_ptr, 1000, 1000, "FDF");
**
**		mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, #color);
**
**		mlx_key_hook(win_ptr, deal_key, NULL);
**		mlx_loop(mlx_ptr);
**	--------------------------------------------------------------
**	------- deal_key prototype -----------------------------------
**		int		deal_key(int key, void *data);
**	--------------------------------------------------------------
**	colors:
**		white = 0xffffff
**		red = 0xe80c0c
**	----------------------------
**	frameworks:
**		-framework OpenGL -framework AppKit