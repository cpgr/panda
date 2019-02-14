

#ifndef SOLIDTEMPERATUREDIFFUSION_H
#define SOLIDTEMPERATUREDIFFUSION_H

#include "Diffusion.h"

//Forward Declarations
class SolidTemperatureDiffusion;

/**
 * validParams returns the parameters that this Kernel accepts / needs
 * The actual body of the function MUST be in the .C file.
 */
template<>
InputParameters validParams<SolidTemperatureDiffusion>();

class SolidTemperatureDiffusion : public Diffusion
{
public:

  SolidTemperatureDiffusion(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;
  virtual Real computeQpJacobian() override;

  

  /**
   * This MooseArray will hold the reference we need to our
   * material property from the Material class
   */

   const  MaterialProperty<Real> & _ks;

};
#endif //SOLIDTEMPERATUREDIFFUSION_H
