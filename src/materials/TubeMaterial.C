
#include "TubeMaterial.h"

registerMooseObject("PandaApp", TubeMaterial);

template<>
InputParameters validParams<TubeMaterial>()
{
  InputParameters params = validParams<Material>();

  params.addCoupledVar("v_tf", "The gradient of this variable will be used to compute a velocity vector property.");
  params.addCoupledVar("v_ts", "The gradient of this variable will be used to compute a velocity vector property.");
  params.addCoupledVar("v_p", "The gradient of this variable will be used to compute a velocity vector property.");

  return params;
}

TubeMaterial::TubeMaterial(const InputParameters & parameters) :
    Material(parameters),

    _v_tf(isCoupled("v_tf") ? coupledValue("v_tf") : _zero),

    _v_ts(isCoupled("v_ts") ? coupledValue("v_ts") : _zero),

    _v_p(isCoupled("v_p") ? coupledValue("v_p") : _zero),


    _gas_constant(declareProperty<Real>("gas_constant")),

    _porosity(declareProperty<Real>("porosity")),

    _friction_factor(declareProperty<Real>("friction_factor")),

    _gravity(declareProperty<RealVectorValue>("gravity")),

    _cpf(declareProperty<Real>("cpf")),

    _kf(declareProperty<Real>("kf")),

    _alpha(declareProperty<Real>("alpha")),

    _solid_density(declareProperty<Real>("solid_density")),

    _cps(declareProperty<Real>("cps")),

    _ks(declareProperty<Real>("ks")),

    _source_rate(declareProperty<Real>("source_rate")),

    _inlet_mass_rate(declareProperty<Real>("inlet_mass_rate")),

//calculate _friction_factor
    _miu_f(declareProperty<Real>("miu_f")),
    _m(declareProperty<Real>("m")),
    _D(declareProperty<Real>("D")),
    _d(declareProperty<Real>("d")),
    _Re(declareProperty<Real>("Re")),
    _psi(declareProperty<Real>("psi")),

//calculate _alpha
    _Pr(declareProperty<Real>("Pr")),
    _Nu(declareProperty<Real>("Nu"))
{}

void
TubeMaterial::computeQpProperties()
{
  
  _gas_constant[_qp] =2078.6;

  _porosity[_qp] =0.332;


//calculate Re
  _miu_f[_qp]=3.674*pow(10.0,-7.0)*pow(_v_tf[_qp]+273.15,0.7);
  _m[_qp]=85.4;
  _D[_qp]=0.2;
  _d[_qp]=0.2;
  _Re[_qp]=_m[_qp]*4.0*_d[_qp]/(3.1416*_d[_qp]*_d[_qp]*_miu_f[_qp]);


//  _gravity[_qp] =RealVectorValue(0,-9.80665);
  _gravity[_qp] =RealVectorValue(0.0,0.0,-9.80665);

  _cpf[_qp] =5195.0;


  _kf[_qp]=2.682*0.001*(1.0+1.123*0.001*0.00001*_v_p[_qp])*pow(_v_tf[_qp]+273.15,0.71*(1.0-2.0*0.0001*0.00001*_v_p[_qp]));
//  _kf[_qp]=0.312;


//calculate _alpha
  _Pr[_qp]=_cpf[_qp]*_miu_f[_qp]/_kf[_qp];
  _Nu[_qp]=1.27*pow(_Re[_qp],0.36)*pow(_Pr[_qp],1.0/3.0)/pow(_porosity[_qp],1.18)+0.033*pow(_Re[_qp],0.86)*pow(_Pr[_qp],1.0/2.0)/pow(_porosity[_qp],1.07);
//  _alpha[_qp]=_Nu[_qp]*_kf[_qp]/_d[_qp] * 6.0*(1.0- _porosity[_qp])/_d[_qp];
//  _alpha[_qp]=500.0;
  _alpha[_qp]=0.0;



//  _solid_density[_qp] =10960.0;
  _solid_density[_qp] =1856.81;


  _cps[_qp] =1.75*(0.645+3.14*pow(10.0,-3.0)*_v_ts[_qp]-2.809*pow(10.0,-6.0)*_v_ts[_qp]*_v_ts[_qp]+0.959*pow(10.0,-9.0)*_v_ts[_qp]*_v_ts[_qp]*_v_ts[_qp])*pow(10.0,6.0);

//t centigrade
  _ks[_qp]=1.1538*pow(10.0,-4.0)*pow(_v_ts[_qp]+100.0,1.6622);

  _source_rate[_qp] =0.0;
//  _source_rate[_qp] =2.853*pow(10.0,6.0);

  _inlet_mass_rate[_qp] =-12.08;
}
