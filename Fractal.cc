//COMPUTAÇÃO GRÁFICA

#include <GL/glut.h>

//BOX FRACTAL

GLfloat v[4][2]={{20.0,20.0},{60.0,20.0},{60.0,60.0},{20.0,60.0}};

int n;

void box(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d)

/* specify one box */
{
      glVertex2fv(a);
      glVertex2fv(b);
      glVertex2fv(c);
      glVertex2fv(d);


}

void divide_box(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int m)
{

/* box subdivision using vertex numbers */

   GLfloat v1[2], v2[2], v3[2], v4[2], v5[2], v6[2], v7[2], v8[2], 
           v9[2], v10[2], v11[2], v12[2], v13[2], v14[2], v15[2], v16[2];

   if(m > 0) {

//calculado os pontos dos lados
       
      
       v1[0]=a[0];
       v1[1]=a[1];
       
       v2[0]=(b[0]-a[0])/3 + a[0];
       v2[1]=a[1];
       
       v3[0]=(b[0]-a[0])/3 + a[0];
       v3[1]=(d[1]-a[1])/3 + a[1];
       
       v4[0]=a[0];
       v4[1]=(d[1]-a[1])/3 + a[1];
       
       v5[0]=a[0];
       v5[1]=2*(d[1]-a[1])/3 + a[1];
      
       v6[0]=(b[0]-a[0])/3 + a[0];
       v6[1]=2*(d[1]-a[1])/3 + a[1];
       
       v7[0]=(b[0]-a[0])/3 + a[0];
       v7[1]=d[1];
       
       v8[0]=d[0];
       v8[1]=d[1];
      
       v9[0]=2*(b[0]-a[0])/3 + a[0];
       v9[1]=d[1];    
            
       v10[0]=c[0];
       v10[1]=c[1];   
       
       v11[0]=b[0];
       v11[1]=2*(d[1]-a[1])/3 + a[1];   
       
       v12[0]=2*(b[0]-a[0])/3 + a[0];
       v12[1]=2*(d[1]-a[1])/3 + a[1];      
       
       v13[0]=2*(b[0]-a[0])/3 + a[0];
       v13[1]=(d[1]-a[1])/3 + a[1];     
       
       v14[0]=2*(b[0]-a[0])/3 + a[0];
       v14[1]=a[1]; 
       
       v15[0]=b[0];
       v15[1]=b[1];  
       
       v16[0]=b[0];
       v16[1]=(d[1]-a[1])/3 + a[1]; 
       
       
      
       divide_box(v1, v2, v3, v4, m-1);
       divide_box(v14, v15, v16, v13, m-1);
       divide_box(v12, v11, v10, v9, m-1);
       divide_box(v5, v6, v7, v8, m-1);
       divide_box(v3, v13, v12, v6, m-1);
   }

    else
       box(a,b,c,d); /* draw box at end of recursion */
}


void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glBegin(GL_QUADS);
   divide_box(v[0], v[1], v[2], v[3], n);
   glEnd();
   glFlush();
}

void myinit()
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-150.0, 150.0, -150.0, 150.0);
   glMatrixMode(GL_MODELVIEW);
   glClearColor (1.0, 0.4, 0.5, 0.1);
   glColor3f(0.8,0.8,0.3);
}

int main(int argc, char **argv)
{
   n=2; /* set number of subdivision steps here */
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutCreateWindow("Sierpinski Gasket");
   glutDisplayFunc(display);
   myinit();
   glutMainLoop();
}

