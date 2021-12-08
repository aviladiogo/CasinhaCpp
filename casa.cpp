#include <windows.h>
#include <GL\freeglut.h>
#include <math.h>
#include <iostream>
# define PI 		3.14159265359
//mexe o telhado
GLfloat telha = 0;
//alterações das cores 
GLfloat colorR = 0; 
GLfloat colorG = 0;
GLfloat colorB = 0;
//responsavel pela escalação da porta
GLfloat GFPosx = 0;
GLfloat GFPosy = 0; 
//Move a casa
GLfloat Horizontal = 0; //move a casa pra esquerda direita
GLfloat Vertical = 0; //move a casa pra cima e para baixo
//gira o sol
int angulo = 40;

void Janela (void){
	// janela
    // vidro
    glBegin(GL_QUADS);
    glColor3f(0,255,255);
    glVertex2i(393+Horizontal,55+Vertical); // top left
    glVertex2i(440+Horizontal,55+Vertical); // top right
    glVertex2i(440+Horizontal,104+Vertical); // bot right
    glVertex2i(393+Horizontal,104+Vertical); // bot left
    glEnd();
    //moldura
    glBegin(GL_LINE_LOOP);
    glColor3f(255,0,255);
    glVertex2i(393+Horizontal,55+Vertical); // top left
    glVertex2i(440+Horizontal,55+Vertical); // top right
    glVertex2i(440+Horizontal,104+Vertical); // bot right
    glVertex2i(393+Horizontal,104+Vertical); // bot left
    glEnd();
    //moldura2
    glBegin(GL_LINE_LOOP);
    glColor3f(255,0,255);
    glVertex2i(417+Horizontal,55+Vertical); // top left
    glVertex2i(440+Horizontal,55+Vertical); // top right
    glVertex2i(440+Horizontal,79+Vertical); // bot right
    glVertex2i(417+Horizontal,79+Vertical); // bot left
    glEnd();
    //moldura3
    glBegin(GL_LINE_LOOP);
    glColor3f(255,0,255);
    glVertex2i(393+Horizontal, 79+Vertical); // top left
    glVertex2i(417+Horizontal, 79+Vertical); // bot left
    glVertex2i(417+Horizontal, 104+Vertical); // top right
    glVertex2i(393+Horizontal, 104+Vertical); // bot right
    glEnd();
}

void Telhado (void){
	//Telhado
    glBegin(GL_TRIANGLES);         // início triângulo
    glColor3f(0+colorR,0+colorG,255+colorB);//0, 0, 255);
    glVertex2i(383+Horizontal , 237 - telha+Vertical); // Topo
    glVertex2i(298+Horizontal,156+Vertical); // Esquerda embaixo
	glVertex2i(470+Horizontal,156+Vertical); // Direita embaixo
    glEnd(); 
}

void Casa (void){
	// Fundação
    glBegin(GL_QUADS);
    glColor3f(0.5f + colorR,0+ colorG,0+colorB);
    glVertex2i(298+Horizontal,1+Vertical); // bot left
    glVertex2i(470+ Horizontal,1+Vertical); // bot right
    glVertex2i(470+Horizontal,156+Vertical); // top right
    glVertex2i(298+ Horizontal,156+Vertical); // top left
    glEnd();
    
    // Porta
    glBegin(GL_QUADS);
    glColor3f(255+colorR,0+colorG,255+colorB);
    glVertex2i(318+Horizontal,1+Vertical); // bot left
    glVertex2i(370+Horizontal+GFPosx,1+Vertical); // bot right GFPosx
    glVertex2i(370+Horizontal + GFPosx,104 + GFPosy+Vertical); // top right
    glVertex2i(318+Horizontal,104+ GFPosy+Vertical); // top left
    glEnd();
    
    Janela();
    
    Telhado();
    
}
void Sol (void){
	//Sol
    int i;
    GLfloat x = 90; GLfloat y=400; GLfloat radius = 50;
    int trianguleAmount = 40;
    GLfloat twicePi = 2.0f* PI;
    GLfloat theta;
    
    //glRotatef(90.0f,0.0f,0.0f,1.0f);
    //glTranslatef(-45,-355,0.0f);
    //glBegin(GL_POLYGON);
    //for(int i=0; i<360; i++){
    //	if(i <181){
    //		glColor3f(255, 255, 0);
	//	}else{
	//		glColor3f(255, 0, 0);
	//	}
    //	theta = i*3.142/180;
    //	glVertex2f(x+ radius*cos(theta),y+ radius*sin(theta));
//	}
	
    glBegin(GL_TRIANGLE_FAN);
    
    glColor3f(255, 0, 0);
    	glVertex2f(x,y);
    	for(i=0; i <= trianguleAmount; i++){
    		glVertex2f(
    		x +(radius*cos(i * twicePi/trianguleAmount)),
    		y +(radius*sin(i * twicePi/trianguleAmount))
    		);
		}
		
		
	
	glColor3f(255, 255, 0);
		glVertex2f(x,y);
    	for(i=0; i <= angulo; i++){
    		glVertex2f(
    		x +(radius*cos(i * twicePi/trianguleAmount)),
    		y +(radius*sin(i * twicePi/trianguleAmount))
    		//x +(radius*cos(i * twicePi/angulo)),
    		//y +(radius*sin(i * twicePi/angulo))
    		);
		}
    glEnd();
}
void Estrela (void){
	//Estrela
    glBegin(GL_POLYGON);         // início triângulo
    glColor3f(255, 255, 0);
    glVertex2i(383 , 442); // Topo
    glVertex2i(422 , 283); // Esquerda embaixo
    glVertex2i(378 , 315);
    glVertex2i(335 , 283); // Direita embaixo
    
    glEnd();  
	
	glBegin(GL_TRIANGLES);         // início triângulo
    glColor3f(255, 255, 0);
    glVertex2i(378 , 315); // Topo
    glVertex2i(459,375); // Esquerda embaixo
	glVertex2i( 299,375); // Direita embaixo
    glEnd(); 
}

void display1(void) {
    glClearColor(0.0f, 0.5f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPushMatrix();
    
    
    Casa();
    
    glPushMatrix();
	Sol();
	glPopMatrix();
	
	glScalef(0.5, 0.5, 0); // A Estela esta com um tamnho desproporcional entao alteramos para um mais bonito
	glTranslatef(400,400,0); // ao alterar a escala ela sai do local desejado, entao iremos movela ate o desejado
	Estrela();

    glPopMatrix();
    glutSwapBuffers();
    Sleep(1);
}
void Teclado(unsigned char tecla, int x, int y){
	if(tecla == 'd'){
		std::cout << telha;
		telha = telha + 5.0;
	}else if(tecla == 'a'){
		GFPosx = GFPosx + 1;
		GFPosy = GFPosy + 1;
	}else if(tecla == 'r'){
		if(angulo == 40 ){
			angulo = 0;
		}
		std::cout << "RODA";
		angulo = angulo + 1;
	}
	glutPostRedisplay();		
}

void SpecialInput(int key, int x, int y){
	switch(key){
	case GLUT_KEY_UP:
		Vertical = Vertical + 5;
	break;
	case GLUT_KEY_DOWN:
		Vertical = Vertical - 5;
	break;
	case GLUT_KEY_LEFT:
		Horizontal = Horizontal - 5;
	break;
	case GLUT_KEY_RIGHT:
		Horizontal = Horizontal + 5;
	break;
	}

	glutPostRedisplay();
}
void mouse(int botao, int estadoB, int x, int y)
{
    //botao <- qual botão foi selecionado: esquerda, meio ou direita
    //estadoB <- o o botão foi pressionado ou não
    //x e y <- são as posições do mouse quando o botão foi pressionado
    if (botao == GLUT_LEFT_BUTTON){
        if (estadoB == GLUT_DOWN){
        	std::cout << "botão esquerda";
        	// Mexer na limitação das cores
        	colorR += 0.5f;
            colorG += 0.5f;
            colorB += 0.5f;
            if(colorR > 1.0f){
            	colorR = 0.0;
			}else if(colorG > 1.0f){
            	colorG = 0.0;
			}else if(colorB > 1.0f){
            	colorB = 0.0;
			}
		} 
        }

    //Renderiza a tela
    glutPostRedisplay();
}
void myInit(void){
	glClearColor(0,0,1,0);
	glColor3f(0,0,0);
	glPointSize(4);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Test");
    glutDisplayFunc(display1);
    
    glutKeyboardFunc(Teclado);
    glutMouseFunc(mouse);
    glutSpecialFunc(SpecialInput);
    
    myInit();
    glutMainLoop();

    return 0;
}