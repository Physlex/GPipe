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

     /**
     * Mutator,
     * @details Updates the x component of translation
     * @param the newX
     */
     void UpdateTranslationX(GLfloat newX);

     /**
     * Mutator,
     * @details Updates the y component of translation
     * @param the newY
     */
     void UpdateTranslationY(GLfloat newY);

     /**
     * Mutator,
     * @details Updates the z component of translation
     * @param the newZ
     */
     void UpdateTranslationZ(GLfloat newZ);

     /**
     * Extractor,
     * @details returns the current value of posX
     * @retunr posX
     */
     GLfloat X();

     /**
     * Extractor,
     * @details returns the current value of posY
     * @retunr posY
     */
     GLfloat Y();

     /**
     * Extractor,
     * @details returns the current value of posZ
     * @retunr posZ
     */
     GLfloat Z();

     /**
     * Methods,
     * @details constructs a new matrix via the operator type
     * @param factor, the factor you scale by
     */
     Translation operator-(GLfloat factor);
     Translation operator-=(GLfloat factor);
     Translation operator+(GLfloat factor);
     Translation operator+=(GLfloat factor);

     Translation operator*(GLfloat factor);
     Translation operator*=(GLfloat factor);
     Translation operator/(GLfloat factor);
     Translation operator/=(GLfloat factor);

     /**
     * Extractor,
     * @return transMatrix
     */
     mat4 GetTransMatrix();

   private:
     /**
     * Mutator,
     * Updates the transMatrix via scalars
     */
     void UpdateTranslationMat();

     GLfloat posX;
     GLfloat posY;
     GLfloat posZ;
     mat4 transMatrix;
   };
 }

#endif
