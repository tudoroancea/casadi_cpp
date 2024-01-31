#include <casadi/casadi.hpp>
#include <iomanip>
using namespace casadi;

// int main() {
//   // Declare variable
//   SX x = SX::sym("x");
//   std::cout << x << std::endl;
//   return 0;
// }

int main(int argc, char **argv) {
  // Get the problem
  std::string problem = "hs107.nl";

  // Parse an NL-file
  NlpBuilder nl;
  nl.import_nl(problem);

  // Set options
  Dict opts;
  opts["expand"] = true;
  //  opts["max_iter"] = 10;
  //  opts["verbose"] = true;
  //  opts["linear_solver"] = "ma57";
  //  opts["hessian_approximation"] = "limited-memory";
  //  opts["derivative_test"] = "second-order";

  // Allocate NLP solver and buffers
  Function solver = nlpsol("nlpsol", "ipopt", nl, opts);
  std::map<std::string, DM> arg, res;

  // Solve NLP
  arg["lbx"] = nl.x_lb;
  arg["ubx"] = nl.x_ub;
  arg["lbg"] = nl.g_lb;
  arg["ubg"] = nl.g_ub;
  arg["x0"] = nl.x_init;
  res = solver(arg);
  res = solver(arg);
  for (auto &&s : res) {
    std::cout << std::setw(10) << s.first << ": "
              << std::vector<double>(s.second) << std::endl;
  }
  return 0;
}
