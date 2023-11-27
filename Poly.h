#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <map>

class Poly {
  private:
	std::map<unsigned int, double> terms;

  public:
	Poly() = default;
	Poly(const Poly& poly);
	Poly(double poly);

	double& operator[](unsigned int index);

	Poly& operator=(const Poly& poly);

	Poly operator+(const Poly& poly) const;
	friend Poly operator+(double p1, const Poly& p2);

	Poly operator-(const Poly& poly) const;
	friend Poly operator-(double p1, const Poly& p2);
	Poly operator-() const;

	Poly operator*(const Poly& poly) const;
	friend Poly operator*(double p1, const Poly& p2);

	double operator()(double x) const;

	friend std::ostream& operator<<(std::ostream& os, const Poly& poly);
};

#endif // POLY_H
