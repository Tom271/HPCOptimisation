#include "HPC_Opt.hpp"

int main(){
  GDSettings settings;
  settings.gamma = 0.1;
  settings.max_iter = 100000;
  settings.grad_norm_tol = pow(10,-7);
  settings.rel_sol_change_tol = pow(10,-10);
  settings.save = false;
  settings.min_bound = -512;
  settings.max_bound = 512;
  settings.method = 2;
  settings.par_momentum = 0.1;
  settings.num_particles = 1000;

  //std::cout << settings <<  std::endl;
  // Initialise vectors to hold the intial values (which need to be inputted)
  const int d = {2};
  Eggholder f(d);
  
  // Use the gradient descent algorithm to calculate the minimum.
  GradientDescent gd;
  Eigen::VectorXd res = gd.parallel_minimise(f, settings);
  
  //std::cout << res  << std::endl;
  
  return 0;
}