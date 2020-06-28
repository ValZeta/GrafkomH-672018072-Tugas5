#include <stdlib.h>
#include <GL/glut.h>

//Press D to start

int w = 500, h = 500, z = 0;
int x1 = 0, y1 = 0, sudut = 0, z1 = 0;
float skalaX = 1, skalaY = 1, skalaZ = 1;

void myKeyboard(unsigned char key, int x, int y) {
    if (key == 'a') z += 5;
    else if (key == 'd') z -= 5;
    else if (key == 'x') {
        x1 = 1;
        y1 = 0;
        z1 = 0;
        sudut += 10;
    }
    else if (key == 'y') {
        y1 = 1;
        x1 = 0;
        z1 = 0;
        sudut += -10;
    }
    else if (key == 'z') {
        y1 = 0;
        x1 = 0;
        z1 = 1;
        sudut += -10;
    }
}

void init() {
    GLfloat LightSpecular[] = { 0.1f, 0.1f, 0.1f, 2.0f };
    GLfloat Shine[] = { 90 };

    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glMaterialfv(GL_FRONT, GL_SPECULAR, LightSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, Shine);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    return;
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1, 1, 1, 1);

    glLoadIdentity();
    glTranslatef(0, 0, z);
    glRotatef(sudut, x1, y1, z1);
    glScalef(skalaX, skalaY, skalaZ);

    //tembok
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.5, 0.6, 0.3);
    glRotatef(50, 0, 1, 0); 
    glScalef(1, 0.5, 1);
    glutSolidCube(3);
    glDisable(GL_COLOR_MATERIAL);

    //pintu depan
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.2, 0.1, 0);
    glTranslatef(0.4, -0.75, 1.46);
    glScalef(5, 15, 1);
    glutSolidCube(0.1);
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();

    //jendela depan
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1, 1, 1);
    glTranslatef(1.25, -0.6, 1.46);
    glScalef(3, 12, 1);
    glutSolidCube(0.1);
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1, 1, 1);
    glTranslatef(0.87, -0.6, 1.46);
    glScalef(3, 12, 1);
    glutSolidCube(0.1);
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1, 1, 1);
    glTranslatef(-0.08, -0.45, 1.46);
    glScalef(3, 7, 1);
    glutSolidCube(0.1);
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();

    //jendela samping
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1, 1, 1);
    glTranslatef(-1.46, -0.45, 0.8);
    glScalef(1, 7, 3);
    glutSolidCube(0.1);
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();

    //jendela belakang
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1, 1, 1);
    glTranslatef(0.7, -0.6, -1.46);
    glScalef(3, 12, 1);
    glutSolidCube(0.1);
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1, 1, 1);
    glTranslatef(0.35, -0.6, -1.46);
    glScalef(3, 12, 1);
    glutSolidCube(0.1);
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(1, 1, 1);
    glTranslatef(0, -0.6, -1.46);
    glScalef(3, 12, 1);
    glutSolidCube(0.1);
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();

    //pintu belakang
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.2, 0.1, 0);
    glTranslatef(-0.5, -0.75, -1.46);
    glScalef(5, 15, 1);
    glutSolidCube(0.1);
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();

    //atap teras
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.9, 0.9, 0.9);
    glTranslatef(0.5, 0.5, 1.7);
    glScalef(18, 1, 12);
    glutSolidCube(0.1);
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();

    //lantai teras
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.9, 0.9, 0.9);
    glTranslatef(0.54, -1.45, 1.7);
    glScalef(16, 1, 12);
    glutSolidCube(0.1);
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();

    //tiang teras
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.6, 0.6, 0.6);
    glTranslatef(1.2, -0.5, 2.1);
    glScalef(1, 20, 1);
    glutSolidCube(0.1);
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();

    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.6, 0.6, 0.6);
    glTranslatef(-0.1, -0.5, 2.1);
    glScalef(1, 20, 1);
    glutSolidCube(0.1);
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();

    //dinding kamar mandi
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.5, 0.6, 0.3);
    glTranslatef(-0.7, -0.6, 1.7);
    glScalef(8, 18, 4);
    glutSolidCube(0.1);
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();

    glPopMatrix();

    //atap
    glPushMatrix();
    glEnable(GL_COLOR_MATERIAL);
    glColor3f(0.4, 0, 0);
    glRotatef(5, 0, 1, 0);
    glTranslatef(0, 0.599, 0);
    glScalef(2.5, 1, 2.5);
    glutSolidOctahedron();
    glDisable(GL_COLOR_MATERIAL);
    glPopMatrix();
    glutSwapBuffers();
}

void resize(int w1, int h1) {
    glViewport(0, 0, w1, h1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w1 / (float)h1, 1.0, 300.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(50, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(w, h);
    glutCreateWindow("Valen Brata Pranaya - 672018072");
    glutDisplayFunc(renderScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(myKeyboard);
    glutTimerFunc(1, timer, 0);
    init();
    glutMainLoop();
}