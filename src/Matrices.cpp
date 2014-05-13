#include "Matrices.h"

using namespace Rcpp;
using namespace arma;

SEXP is_symmetric_matrix(SEXP x) {
  arma::mat X = as<arma::mat>(x);
  arma::mat Xt = arma::trans(X);
  int same = 0, n = X.n_rows;
  bool symmetric = false;
  for (int i = 0; i < n; i++) {
    same += arma::sum(X.row(i) == Xt.row(i));
  }
  if (same == pow(n,2)) symmetric == true;
  return wrap(symmetric);
}

SEXP tr(SEXP x) {
  arma::mat X = as<arma::mat>(x);
  double tra = arma::trace(X);
  return wrap(tra);
}
