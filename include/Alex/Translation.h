#ifndef TRANSLATE_H
#define TRANSLATE_H

#include <Angel.h>
namespace Al {
  /**
  * @class Translation Translation.h "Translation.h"
  * @details Creates a translation matrix from scalars
  */
  class Translation {
   public:
     /**
     *  Constructor,
     *  Creates a translation matrix from scalars
     */
     Translation(GLfloat _posX, GLfloat _posY, GLfloat _posZ);
   private:
     GLfloat posX;
     GLfloat posY;
     GLfloat posZ;
     mat4 transMatrix;
   };
 }

#endif
