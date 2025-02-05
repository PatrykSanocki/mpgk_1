#include "Header.h"
#include "Macierz.h"
#include "Przeksztalcenia.h"

GLuint ProgramMPGK::VAO;
GLuint ProgramMPGK::VBO;
GLuint ProgramMPGK::IBO;
GLuint ProgramMPGK::programZShaderami;
GLuint ProgramMPGK::vertexShaderId;
GLuint ProgramMPGK::fragmentShaderId;
GLint ProgramMPGK::zmiennaShader;
GLint ProgramMPGK::zmiennaShader1;

ProgramMPGK::ProgramMPGK(void)
{
	wysokoscOkna = 768;
	szerokoscOkna = 1024;
	polozenieOknaX = 100;
	polozenieOknaY = 100;
}

ProgramMPGK::ProgramMPGK(int wysokoscOkna, int szerokoscOkna, int polozenieOknaX, int polozenieOknaY)
{
	this->wysokoscOkna = wysokoscOkna;
	this->szerokoscOkna = szerokoscOkna;
	this->polozenieOknaX = polozenieOknaX;
	this->polozenieOknaY = polozenieOknaY;
}

ProgramMPGK::~ProgramMPGK()
{

}

void ProgramMPGK::stworzenieOkna(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(szerokoscOkna, wysokoscOkna);
	glutInitWindowPosition(polozenieOknaX, polozenieOknaY);
	glutInitContextVersion(3, 3);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow("Program");
}

void ProgramMPGK::inicjalizacjaGlew()
{
	GLenum wynik = glewInit();
	if (wynik != GLEW_OK)
	{
		std::cerr << "Nie udalo sie zainicjalizowac GLEW. Blad: " << glewGetErrorString(wynik) << std::endl;
		//system("pause");
		exit(1);
	}
}

void  ProgramMPGK::wyswietl()
{

	float c[4][4] = {
		{1.0f, 0.0f, 0.0f, 0.5f},
		{0.0f, 1.0f, 0.0f, 0.2f},
		{0.0f, 0.0f, 1.0f, 0.5f},
		{0.0f, 0.0f, 0.0f, 1.0f} };
	Macierz<4> mac1();
	Przeksztalcenia<4> mac4;
	mac4.rotate3D(45, 'z');

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	static GLfloat zmiana = 0.0f;
	zmiana += 0.0005f;
	//glUniform1f(zmiennaShader, abs(sinf(zmiana)));
	glUniformMatrix4fv(zmiennaShader1, 1, GL_TRUE, *mac4.macierz.getMacierz().M);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 8, 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 8, (GLvoid*)(sizeof(GLfloat) * 4));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	glutSwapBuffers();
}

void ProgramMPGK::usun()
{
	glDeleteShader(vertexShaderId);
	glDeleteShader(fragmentShaderId);
	glDeleteProgram(programZShaderami);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &IBO);
	glDeleteVertexArrays(1, &VAO);
}

void ProgramMPGK::stworzenieVAO()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
}

void ProgramMPGK::stworzenieVBO()
{
	//Macierz<3> m;
	//Macierz<3> m2(5.0f);
	float mat[3][3] = {
		1.0f, 2.0f, 0.0f,
		4.0f, 5.0f, 0.0f,
		0.0f, 0.0f, 1.0f };

	//float mate[5][5] = {
	//1.0f, 3.0f, 6.0f, 0.0f, 1.0f,
	//2.0f, 4.0f, 7.0f, 8.0f, 2.0f,
	//3.0f, 0.0f, 1.0f, 4.0f, 2.0f,
	//-2.0f, 1.0f, -4.0f, 5.0f, 4.0f,
	//2.0f, 1.0f, 1.0f, 0.0f, 4.0f, };

	//Macierz<5> original(mate);
	//Macierz<5> odwrot = original.invert();

	//std::cout << odwrot << std::endl;
	Macierz<3> m3(mat);

	//m = m2 * m3;
	//std::cout << m << std::endl;

	////std::cout << m2 << std::endl;
	////std::cout << m3 << std::endl;

	//m2 *= m3;
	//std::cout << m2 << std::endl;

	//Macierz<3> m4;
	//m4 = m3;
	//m4 * m3;
	//Macierz<3> m5;
	//m5 = m4 * m3;

	////std::cout << m5 << std::endl;
	////std::cout << m3 << std::endl;
	////std::cout << m4 << std::endl;

	////m4 + m2;

	////m4 -= m2;
	//float matr[3][3] = {
	//	10.0f, 6.0f, 7.0f,
	//	3.0f, 9.0f, 1.0f,
	//	5.0f, 5.0f, 5.0f };
	//Wektor<3> wek(9.0f, 5.0f, 5.0f);
	//Macierz<3> mac(matr);
	//Wektor<3> wek2 = mac * wek;
	////m4 * 5;
	//std::cout << wek2 << std::endl;

	//Macierz<3> ide;
	//ide = m4.identity();
	//std::cout << ide << std::endl;



	Przeksztalcenia<3> scale3_1;
	scale3_1.scale2D(1.0f);

	std::cout << scale3_1.macierz << std::endl;


	Przeksztalcenia<3> scale3_2;
	scale3_2.scale2D(2.0f, 4.0f);

	Przeksztalcenia<3> test;
	
	Wektor<3> t(1.0f, 2.0f, 1.0f);
	t = t.normalization();
	std::cout << t << std::endl;

	std::cout << scale3_2.macierz << std::endl;

	float table[2] = { 3.0f, 5.0f };

	Przeksztalcenia<3> scale3_3;
	scale3_3.scale2D(table);

	std::cout << scale3_3.macierz << std::endl;

	Przeksztalcenia<3> rotate3;
	rotate3.rotate2D(90.0f);
	std::cout << "rotate" << std::endl;
	std::cout << rotate3.macierz << std::endl;


	//////////////////////////////////

	Przeksztalcenia<3> translate3_1;
	translate3_1.translate2D(1.0f);

	std::cout << translate3_1.macierz << std::endl;

	std::cout << "tW" << std::endl;




	Wektor<3> tW(1.0f, 2.0f, 1.0f);

	tW = translate3_1.macierz * tW;

	std::cout << tW << std::endl;

	Przeksztalcenia<3> translate3_2;
	translate3_2.translate2D(2.0f, 4.0f);

	std::cout << translate3_2.macierz << std::endl;

	Przeksztalcenia<3> translate3_3;
	translate3_3.translate2D(table);

	std::cout << translate3_3.macierz << std::endl;


	//////////////////////////////////

	Przeksztalcenia<4> scale4_1;
	scale4_1.scale3D(1.0f);

	std::cout << scale4_1.macierz << std::endl;


	Przeksztalcenia<4> scale4_2;
	scale4_2.scale3D(2.0f, 4.0f, -5.0f);

	std::cout << scale4_2.macierz << std::endl;

	float table2[3] = { 3.0f, 5.0f, -1.0f };

	Przeksztalcenia<4> scale4_3;
	scale4_3.scale3D(table2);

	std::cout << scale4_3.macierz << std::endl;



	//////////////////////////////////


	Przeksztalcenia<4> translate4_1;
	translate4_1.translate3D(1.0f);

	std::cout << translate4_1.macierz << std::endl;


	Przeksztalcenia<4> translate4_2;
	translate4_2.translate3D(2.0f, 4.0f, -9.0f);

	std::cout << translate4_2.macierz << std::endl;




	Przeksztalcenia<4> translate4_3;
	translate4_3.translate3D(table2);

	std::cout << translate4_3.macierz << std::endl;

//// rotate wektor

	Wektor<3> RW(1.0f, 2.0f, -3.0f);
	Przeksztalcenia<4> rotateW;
	rotateW.rotate3D(45, RW);
	std::cout << rotateW.macierz << std::endl;


	Wektor<4> w0(-0.4f, -0.4f, 0.0f, 1.0f);
	Wektor<4> w1(1.0f, 0.0f, 0.0f, 1.0f);
	Wektor<4> w2(0.4f, -0.4f, 0.4f, 1.0f);
	Wektor<4> w3(0.0f, 1.0f, 0.0f, 1.0f);
	Wektor<4> w4(-0.4f, 0.4f, 0.0f, 1.0f);
	Wektor<4> w5(0.0f, 0.0f, 1.0f, 1.0f);
	Wektor<4> w6(0.4f, 0.4f, 0.0f, 1.0f);
	Wektor<4> w7(0.5f, 0.5f, 0.0f, 1.0f);

	GLfloat wierzcholki[] = {
		w0.getX(), w0.getY(), w0.getZ(), w0.getW(),
		w1.getX(), w1.getY(), w1.getZ(), w1.getW(),
		w2.getX(), w2.getY(), w2.getZ(), w2.getW(),
		w3.getX(), w3.getY(), w3.getZ(), w3.getW(),
		w4.getX(), w4.getY(), w4.getZ(), w4.getW(),
		w5.getX(), w5.getY(), w5.getZ(), w5.getW(),
		w6.getX(), w6.getY(), w6.getZ(), w6.getW(),
		w7.getX(), w7.getY(), w7.getZ(), w7.getW()
	};


	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(wierzcholki), wierzcholki, GL_STATIC_DRAW);
}

void ProgramMPGK::stworzenieIBO()
{
	GLuint indeksyTab[] = {
		0, 1, 2, 1, 2, 3,
	};

	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeksyTab), indeksyTab, GL_STATIC_DRAW);
}

void ProgramMPGK::stworzenieProgramu()
{
	programZShaderami = glCreateProgram();

	if (programZShaderami == 0)
	{
		std::cerr << "Blad podczas tworzenia programu shaderow." << std::endl;
		//system("pause");
		exit(1);
	}

	const char * vertexShader =
		"	#version 330 core \n																	\
			layout(location=0) in vec4 polozenie; \n												\
			layout(location=1) in vec4 kolorVS; \n													\
			out vec4 kolorFS; \n																	\
			//uniform float zmianaShader; \n															\
			uniform mat4x4 macierz;																	\
			void main()			 \n																	\
			{		 \n																				\
				//gl_Position = vec4(zmianaShader * polozenie.x, zmianaShader * polozenie.y, zmianaShader * polozenie.z, polozenie.w); \n		\
				gl_Position = macierz * polozenie;																					\
				kolorFS = kolorVS; \n																\
			}";

	const char * fragmentShader =
		"	#version 330 core \n						\
			out vec4 kolor;	\n							\
			in vec4 kolorFS; \n							\
			void main()	\n								\
			{			\n								\
				kolor = kolorFS;	\n					\
			}";

	vertexShaderId = dodanieDoProgramu(programZShaderami, vertexShader, GL_VERTEX_SHADER);
	fragmentShaderId = dodanieDoProgramu(programZShaderami, fragmentShader, GL_FRAGMENT_SHADER);

	GLint linkowanieOK = 0;
	glLinkProgram(programZShaderami);
	glGetProgramiv(programZShaderami, GL_LINK_STATUS, &linkowanieOK);
	if (linkowanieOK == GL_FALSE) {
		GLint dlugoscLoga = 0;
		glGetProgramiv(programZShaderami, GL_INFO_LOG_LENGTH, &dlugoscLoga);
		std::vector<GLchar> log(dlugoscLoga);
		glGetProgramInfoLog(programZShaderami, dlugoscLoga, NULL, &log[0]);
		std::cerr << "Blad podczas linkowania programu shaderow." << std::endl;
		for (std::vector<GLchar>::const_iterator i = log.begin(); i != log.end(); ++i)
			std::cerr << *i;
		std::cerr << std::endl;
		glDeleteProgram(programZShaderami);
		//system("pause");
		exit(1);
	}

	GLint walidacjaOK = 0;
	glValidateProgram(programZShaderami);
	glGetProgramiv(programZShaderami, GL_VALIDATE_STATUS, &walidacjaOK);
	if (walidacjaOK == GL_FALSE) {
		GLint dlugoscLoga = 0;
		glGetProgramiv(programZShaderami, GL_INFO_LOG_LENGTH, &dlugoscLoga);
		std::vector<GLchar> log(dlugoscLoga);
		glGetProgramInfoLog(programZShaderami, dlugoscLoga, NULL, &log[0]);
		std::cerr << "Blad podczas walidacji programu shaderow." << std::endl;
		for (std::vector<GLchar>::const_iterator i = log.begin(); i != log.end(); ++i)
			std::cerr << *i;
		std::cerr << std::endl;
		glDeleteProgram(programZShaderami);
		//system("pause");
		exit(1);
	}

	glUseProgram(programZShaderami);

	//zmiennaShader = glGetUniformLocation(programZShaderami, "zmianaShader");
	//if (zmiennaShader == -1)
	//{
	//	std::cerr << "Nie znalezion zmiennej uniform." << std::endl;
	//	//system("pause");
	//	exit(1);
	//}

	zmiennaShader1 = glGetUniformLocation(programZShaderami, "macierz");
	if (zmiennaShader1 == -1)
	{
		std::cerr << "Nie znalezion zmiennej uniform1." << std::endl;
		//system("pause");
		exit(1);
	}
}

GLuint ProgramMPGK::dodanieDoProgramu(GLuint programZShaderami, const GLchar * tekstShadera, GLenum typShadera)
{
	GLuint shader = glCreateShader(typShadera);

	// 35633 -> vertex shader, 35632 -> fragment shader
	const GLchar * typShaderaTekst = typShadera == 35633 ? "vertex" : "fragment";

	if (shader == 0) {
		std::cerr << "Blad podczas tworzenia " << typShaderaTekst << " shadera." << std::endl;
		//system("pause");
		exit(0);
	}

	const GLchar * tekstShaderaTab[1];
	tekstShaderaTab[0] = tekstShadera;
	GLint dlugoscShadera[1];
	dlugoscShadera[0] = strlen(tekstShadera);
	glShaderSource(shader, 1, tekstShaderaTab, dlugoscShadera);

	glCompileShader(shader);
	GLint kompilacjaOK = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &kompilacjaOK);
	if (kompilacjaOK == GL_FALSE)
	{
		GLint dlugoscLoga = 0;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &dlugoscLoga);
		std::vector<GLchar> log(dlugoscLoga);
		glGetShaderInfoLog(shader, dlugoscLoga, NULL, &log[0]);
		std::cerr << std::endl;
		std::cerr << "Blad podczas kompilacji " << typShaderaTekst << " shadera." << std::endl;
		std::cerr << std::endl;
		std::cerr << "log: ";
		for (std::vector<GLchar>::const_iterator i = log.begin(); i != log.end(); ++i)
			std::cerr << *i;
		std::cerr << std::endl;
		glDeleteShader(shader);
		//system("pause");
		exit(1);
	}

	glAttachShader(programZShaderami, shader);
	return shader;
}
void ProgramMPGK::sprawdzenieWersji()
{
	std::cout << "Wersja GLEW: " << glewGetString(GLEW_VERSION) << std::endl;
	std::cout << "Wersja VENDOR: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Wersja REDERER: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Wersja GL: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "Wersja GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

int main(int argc, char** argv)
{
	ProgramMPGK obiektMPGK(786, 786, 100, 100);

	obiektMPGK.stworzenieOkna(argc, argv);
	obiektMPGK.inicjalizacjaGlew();
	obiektMPGK.sprawdzenieWersji();
	obiektMPGK.stworzenieVAO();
	obiektMPGK.stworzenieVBO();
	obiektMPGK.stworzenieIBO();
	obiektMPGK.stworzenieProgramu();
	glutDisplayFunc(obiektMPGK.wyswietl);
	glutIdleFunc(obiektMPGK.wyswietl);
	glutCloseFunc(obiektMPGK.usun);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glutMainLoop();

	//system("pause");
	return 0;
}