// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <math.h>

#include <iostream>

#include "Shader.h"
#include "Vertice.h"
#include <vector>

using namespace std;

//Cada elemento que queramos renderear necesita 
//Un vertex array y un buffer
vector<Vertice> triangulo;
GLuint vertexArrayTrianguloID;
GLuint bufferTrianguloID;

vector<Vertice> cuadrado;
GLuint vertexArrayCuadradoID;
GLuint bufferCuadradoID;

//Instancia del shader
Shader *shader;
//Identificadores para mapeo de atributos de entrada
//del vertex shader
GLuint posicionID;
GLuint colorID;

void ground()
{
	Vertice v1 =
	{
		vec3(-1.0f,-0.65f,0.0f), vec4(0.9f,1.0f,0.9f,1.0f)
	};
	Vertice v2 =
	{
		vec3(1.0f,-0.65f,0.0f), vec4(0.9f,1.0f,0.9f,1.0f)
	};
	Vertice v3 =
	{
		vec3(1.0f,-1.0f,0.0f), vec4(0.9f,1.0f,0.9f,1.0f)
	};
	Vertice v4 =
	{
		vec3(-1.0f,-1.0f,0.0f), vec4(0.9f,1.0f,0.9f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarCuadrado0()
{
	Vertice v1 =
	{
		vec3(-0.95f,-0.7f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.9f,-0.6f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.9f,-0.6f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v4 =
	{
		vec3(0.95f,-0.7f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarCuadrado()
{
	Vertice v1 =
	{
		vec3(-0.85f,-0.6f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.8f,-0.5f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.8f,-0.5f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v4 =
	{
		vec3(0.85f,-0.6f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarSombra0()
{
	Vertice v1 =
	{
		vec3(-0.9f,-0.6f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.84f,-0.58f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.84f,-0.58f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	Vertice v4 =
	{
		vec3(0.9f,-0.6f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarCuadrado2()
{
	Vertice v1 =
	{
		vec3(-0.75f,-0.5f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.7f,-0.4f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.7f,-0.4f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v4 =
	{
		vec3(0.75f,-0.5f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarSombra()
{
	Vertice v1 =
	{
		vec3(-0.8f,-0.5f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.74f,-0.48f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.74f,-0.48f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	Vertice v4 =
	{
		vec3(0.8f,-0.5f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarCuadrado3()
{
	Vertice v1 =
	{
		vec3(-0.65f,-0.4f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.6f,-0.3f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.6f,-0.3f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v4 =
	{
		vec3(0.65f,-0.4f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarSombra2()
{
	Vertice v1 =
	{
		vec3(-0.7f,-0.4f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.64f,-0.38f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.64f,-0.38f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	Vertice v4 =
	{
		vec3(0.7f,-0.4f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarCuadrado4()
{
	Vertice v1 =
	{
		vec3(-0.55f,-0.3f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.5f,-0.2f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.5f,-0.2f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v4 =
	{
		vec3(0.55f,-0.3f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarSombra3()
{
	Vertice v1 =
	{
		vec3(-0.6f,-0.3f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.54f,-0.29f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.54f,-0.29f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	Vertice v4 =
	{
		vec3(0.6f,-0.3f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarCuadrado5()
{
	Vertice v1 =
	{
		vec3(-0.45f,-0.2f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.4f,-0.1f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.4f,-0.1f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v4 =
	{
		vec3(0.45f,-0.2f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarSombra4()
{
	Vertice v1 =
	{
		vec3(-0.5f,-0.2f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.44f,-0.19f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.44f,-0.19f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	Vertice v4 =
	{
		vec3(0.5f,-0.2f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarCuadrado6()
{
	Vertice v1 =
	{
		vec3(-0.35f,-0.1f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.3f,-0.0f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.3f,-0.0f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	Vertice v4 =
	{
		vec3(0.35f,-0.1f,0.0f), vec4(0.9f,0.9f,0.6f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarSombra5()
{
	Vertice v1 =
	{
		vec3(-0.4f,-0.1f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.34f,-0.09f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.34f,-0.09f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	Vertice v4 =
	{
		vec3(0.4f,-0.1f,0.0f), vec4(0.9f,1.0f,0.7f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarCuadrado7()
{
	Vertice v1 =
	{
		vec3(-0.25f,-0.0f,0.0f), vec4(0.9f,0.9f,0.7f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.2f,0.1f,0.0f), vec4(0.9f,0.9f,0.7f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.2f,0.1f,0.0f), vec4(0.9f,0.9f,0.7f,1.0f)
	};
	Vertice v4 =
	{
		vec3(0.25f,-0.0f,0.0f), vec4(0.9f,0.9f,0.7f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarCuadrado8()
{
	Vertice v1 =
	{
		vec3(-0.15f,0.1f,0.0f), vec4(0.9f,0.8f,0.5f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.15f,0.2f,0.0f), vec4(0.9f,0.8f,0.5f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.15f,0.2f,0.0f), vec4(0.9f,0.8f,0.5f,1.0f)
	};
	Vertice v4 =
	{
		vec3(0.15f,0.1f,0.0f), vec4(0.9f,0.8f,0.5f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarCuadrado9()
{
	Vertice v1 =
	{
		vec3(-0.15f,0.2f,0.0f), vec4(0.9f,0.8f,0.6f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.15f,0.3f,0.0f), vec4(0.9f,0.8f,0.6f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.15f,0.3f,0.0f), vec4(0.9f,0.8f,0.6f,1.0f)
	};
	Vertice v4 =
	{
		vec3(0.15f,0.2f,0.0f), vec4(0.9f,0.8f,0.6f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarEscaleras()
{
	Vertice v1 =
	{
		vec3(-0.1f,0.1f,0.0f), vec4(0.9f,0.8f,0.6f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.17f,-0.7f,0.0f), vec4(0.9f,0.8f,0.6f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.17f,-0.7f,0.0f), vec4(0.9f,0.8f,0.6f,1.0f)
	};
	Vertice v4 =
	{
		vec3(0.1f,0.1f,0.0f), vec4(0.9f,0.8f,0.6f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void borde1()
{
	Vertice v1 =
	{
		vec3(-0.13f,0.1f,0.0f), vec4(0.9f,0.9f,0.8f,1.0f)
	};
	Vertice v2 =
	{
		vec3(-0.1f,0.1f,0.0f), vec4(0.9f,0.9f,0.8f,1.0f)
	};
	Vertice v3 =
	{
		vec3(-0.17f,-0.7f,0.0f), vec4(0.9f,0.9f,0.8f,1.0f)
	};
	Vertice v4 =
	{
		vec3(-0.23f,-0.7f,0.0f), vec4(0.9f,0.9f,0.8f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void borde2()
{
	Vertice v1 =
	{
		vec3(0.13f,0.1f,0.0f), vec4(0.9f,0.9f,0.8f,1.0f)
	};
	Vertice v2 =
	{
		vec3(0.1f,0.1f,0.0f), vec4(0.9f,0.9f,0.8f,1.0f)
	};
	Vertice v3 =
	{
		vec3(0.17f,-0.7f,0.0f), vec4(0.9f,0.9f,0.8f,1.0f)
	};
	Vertice v4 =
	{
		vec3(0.23f,-0.7f,0.0f), vec4(0.9f,0.9f,0.8f,1.0f)
	};
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);
}

void inicializarTriangulo() 
{
	
}

void dibujar() 
{
	//Elegir shader
	shader->enlazar();
	//Elegir el vertex array
	glBindVertexArray(vertexArrayTrianguloID);
	//Dibujar
	glDrawArrays(GL_TRIANGLES, 0, triangulo.size());

	//Proceso dibujo de Cuadrado
	glBindVertexArray(vertexArrayCuadradoID);
	glDrawArrays(GL_QUADS, 0, cuadrado.size());

	//Soltar vertex array
	glBindVertexArray(0);
	//Desenlazar shader
	shader->desenlazar();
}

int main()
{
    //Declarar una ventana
	GLFWwindow* window;

	//Si no se pudo iniciar GLFW
	//Terminamos ejecucion
	if (!glfwInit())
	{
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW
	//inicializamos la ventana
	window =
		glfwCreateWindow(600, 600, "Ventana", NULL, NULL);
	//Si no se pudo crear la venata
	//Terminamos ejecucion
	if (!window) 
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos la ventana como contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido el contexto
	//Se activan las funciones "modernas" (gpu)
	glewExperimental = true;

	GLenum errores = glewInit();
	if (errores != GLEW_OK)
	{
		glewGetErrorString(errores);
	}

	const GLubyte* versionGL =
		glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	ground();
	inicializarTriangulo();
	inicializarCuadrado0();
	inicializarCuadrado();
	inicializarSombra0();
	inicializarCuadrado2();
	inicializarSombra();
	inicializarCuadrado3();
	inicializarSombra2();
	inicializarCuadrado4();
	inicializarSombra3();
	inicializarCuadrado5();
	inicializarSombra4();
	inicializarCuadrado6();
	inicializarSombra5();
	inicializarCuadrado7();
	inicializarCuadrado8();
	inicializarCuadrado9();
	inicializarEscaleras();
	borde1();
	borde2();

	const char* rutaVertexShader = "VertexShader.shader";
	const char* rutaFragmentShader = "FragmentShader.shader";
	shader = new Shader(rutaVertexShader, rutaFragmentShader);

	//Mapeo de atributos
	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");

	shader->desenlazar();

	//Crear el vertex array del triangulo
	glGenVertexArrays(1, &vertexArrayTrianguloID);
	glBindVertexArray(vertexArrayTrianguloID);
	//Vertex buffer
	glGenBuffers(1, &bufferTrianguloID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferTrianguloID);
	//Asociar datos al buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * triangulo.size(), triangulo.data(), GL_STATIC_DRAW);
	//Habilitar atributos de shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	//Especificar a OpenGL como comunicarse
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

	//proceso de inicializar vertex array para el cuadrado
	glGenVertexArrays(1, &vertexArrayCuadradoID);
	glBindVertexArray(vertexArrayCuadradoID);
	glGenBuffers(1, &bufferCuadradoID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferCuadradoID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice)* cuadrado.size(), cuadrado.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

	//Soltar el vertex array y el buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window))
	{
		//Establecer region de dibujo
		glViewport(0, 0, 600, 600);
		//Establecemos el color de borrado
		//Valores RGBA
		glClearColor(0, 0.9, 1, 1);
		//Borrar!
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Actualizar valores y dibujar
		dibujar();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
	//Despúes del ciclo de dibujo
	//Eliminamos venta y procesos de glfw
	glfwDestroyWindow(window);
	glfwTerminate();
}
