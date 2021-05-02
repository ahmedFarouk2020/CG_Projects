
#include <stdlib.h>
#include <GL/glut.h>

static int shoulder1_y = 0, elbow1_y = 0, shoulder2_y = 0, elbow2_y = 0
, shoulder1_x = 0, shoulder2_x = 0, leg1_y=0, leg2_y=0 , leg1_z = 0, leg2_z = 0
,knee1_z=0, knee2_z=0;
int moving, startx, starty;


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    //shoulder & elbow
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glTranslatef(1.5, 2.0, 0.0);
    glRotatef((GLfloat)shoulder1_y, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)shoulder1_x, 0.0, 1.0, 0.0);
    glScalef(0.3, 1.0, 0.2);
    glutWireCube(1.0);

    glTranslatef(0.0, -1.0, 0.0);
    glRotatef((GLfloat)elbow1_y, 0.0, 0.0, 1.0);
    glutWireCube(1.0);

    glPopMatrix();



    //Draw body
    glPushMatrix();

    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glScalef(1.8, 2.8, 0.4);
    glTranslatef(0.0, 0.5, 0.0);
    glutWireCube(1);

    glPopMatrix();

    //Draw second Arm
    glPushMatrix();

    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glTranslatef(-1.5, 2.0, 0.0);
    glRotatef((GLfloat)shoulder2_y, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)shoulder1_x, 0.0, 1.0, 0.0);
    glScalef(0.3, 1.0, 0.2);
    glutWireCube(1);

    glTranslatef(0.0, -1.0, 0.0);
    glRotatef((GLfloat)elbow2_y, 0.0, 0.0, 1.0);
    glutWireCube(1);

    glPopMatrix();



    //Draw the head
    glPushMatrix();

    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glTranslatef(0.0, 3.5, 0.0);
    glScalef(0.5, 0.5, 0.5);
    glutWireSphere(1, 12, 18);

    glPopMatrix();

    //Draw first leg
    glPushMatrix();

    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glTranslatef(-0.65, -0.74, 0.0);
    glRotatef((GLfloat)leg1_y, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)leg1_z, 1.0, 0.0, 0.0);
    glScalef(0.5, 1.5, 0.4);
    glutWireCube(1);

    glTranslatef(0.0, -1.0, 0.0);
    glRotatef((GLfloat)knee1_z, 1.0, 0.0, 0.0);
    glutWireCube(1);

    glTranslatef(0.0, -0.5, 0.0);
    glScalef(1.0, 0.3, 2.5);
    glutSolidCube(1);

    glPopMatrix();



    //Draw second leg
    glPushMatrix();

    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glTranslatef(0.65, -0.74, 0.0);
    glRotatef((GLfloat)leg2_y, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)leg2_z, 1.0, 0.0, 0.0);
    glScalef(0.5, 1.5, 0.4);
    glutWireCube(1);

    glTranslatef(0.0, -1.0, 0.0);
    glRotatef((GLfloat)knee2_z, 1.0, 0.0, 0.0);
    glutWireCube(1);

    glTranslatef(0.0, -0.5, 0.0);
    glScalef(1.0, 0.3, 2.5);
    glutSolidCube(1);

    glPopMatrix();




    glPopMatrix();
    glutSwapBuffers();
    
}


void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}


void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        shoulder1_y = (shoulder1_y + 5) % 90;
        shoulder2_y = (shoulder2_y - 5) % 90;
        glutPostRedisplay();
        break;
    case 'S':
        shoulder1_y = (shoulder1_y - 5) % 30;
        shoulder2_y = (shoulder2_y + 5) % 30;
        glutPostRedisplay();
        break;
    case 'a':
        shoulder1_x = (shoulder1_x - 5) % 45;
        shoulder2_x = (shoulder2_x + 5) % 45;
        glutPostRedisplay();
        break;
    case 'A':
        shoulder1_x = (shoulder1_x - 5) % 90;
        shoulder2_x = (shoulder2_x - 5) % 90;
        glutPostRedisplay();
        break;
    case 'e':
        elbow1_y = (elbow1_y + 5) % 90;
        elbow2_y = (elbow2_y - 5) % 90;
        glutPostRedisplay();
        break;
    case 'l':
        leg1_y = (leg1_y - 5) % 60;
        glutPostRedisplay();
        break;
    case 'L':
        leg2_y = (leg2_y + 5) % 60;
        glutPostRedisplay();
        break;
    case 'p':
        leg1_z = (leg1_z - 5) % 60;
        glutPostRedisplay();
        break;
    case 'P':
        leg1_z = (leg1_z + 5) % 60;
        glutPostRedisplay();
        break;
    case 'o':
        leg2_z = (leg2_z - 5) % 60;
        glutPostRedisplay();
        break;
    case 'O':
        leg2_z = (leg2_z + 5) % 60;
        glutPostRedisplay();
        break;
    case 'k':
        knee1_z = (knee1_z + 5) % 60;
        glutPostRedisplay();
        break;
    case 'K':
        knee1_z = (knee1_z - 5) % 60;
        glutPostRedisplay();
        break;

    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

static void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP) {
            moving = 0;
        }
    }
}


static void motion(int x, int y)
{
    if (moving) {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
