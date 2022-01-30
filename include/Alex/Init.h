#ifndef INNIT_H
#define INNIT_H

#include <Angel.h>

class Init
{
 public:
   /**
   *  Default Constructor
   *  @details sets basic information about the window
   *  @param windowName, the name of the generated window
   *  @param s, the size of the window in both m & n directions
   */
   Init(const char *_windowName, int s);

   /**
   *  Default Constructor
   *  @details sets basic infromation about the window
   *  @param windowName, the name of the generated window
   *  @param m, the width of the window
   *  @param n, the height of the window
   */
   Init(const char *_windowName, int m, int n);

   /**
   *  Starts the process of initializing opengl using glut and glew
   *  @param argc, the same as main
   *  @param argv, the same as main
   */
   void StartInitialization(int argc, char **argv);
 private:
   /**
   *  Initialzes glut and glew
   *  @details callled from all constructors
   */
   void InitGlewGlut(int argc, char **argv);

   /**
   *  initializes the window based on specifications implicit in constructor
   */
   void InitWindow();

   int x; int y;
   const char *windowName;
};

#endif
