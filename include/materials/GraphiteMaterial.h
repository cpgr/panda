#ifndef GRAPHITEMATERIAL_H_
#define GRAPHITEMATERIAL_H_

#include "Material.h"


class GraphiteMaterial;

template<>
InputParameters validParams<GraphiteMaterial>();

/**
 * Material-derived objects override the computeQpProperties()
 * function.  They must declare and compute material properties for
 * use by other objects in the calculation such as Kernels and
 * BoundaryConditions.
 */
class GraphiteMaterial : public Material
{
public:
  GraphiteMaterial(const InputParameters & parameters);

protected:
  /**
   * Necessary override.  This is where the values of the properties
   * are computed.
   */
  virtual void computeQpProperties();


  const VariableValue & _v_tf;
  const VariableValue & _v_ts;
  const VariableValue & _v_p;



  /// The permeability (K)
  MaterialProperty<Real> & _gas_constant;

  /// The porosity (eps)
  MaterialProperty<Real> & _porosity;


  MaterialProperty<Real> & _friction_factor;


  MaterialProperty<RealVectorValue> & _gravity;


  MaterialProperty<Real> & _cpf;


  MaterialProperty<Real> & _kf;


  MaterialProperty<Real> & _alpha;


  MaterialProperty<Real> & _solid_density;


  MaterialProperty<Real> & _cps;


  MaterialProperty<Real> & _ks;


  MaterialProperty<Real> & _source_rate;

  MaterialProperty<Real> & _inlet_mass_rate;

private:
//calculate _friction_factor
  MaterialProperty<Real> & _miu_f;
  MaterialProperty<Real> & _m;
  MaterialProperty<Real> & _D;
  MaterialProperty<Real> & _d;
  MaterialProperty<Real> & _Re;
  MaterialProperty<Real> & _psi;

//calculate _alpha
  MaterialProperty<Real> & _Pr;
  MaterialProperty<Real> & _Nu;

};

#endif //GRAPHITEMATERIAL_H
