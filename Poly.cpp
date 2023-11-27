#include "Poly.h"
#include <cmath>

Poly::Poly(const Poly& poly) : terms(poly.terms) {}

Poly::Poly(double poly)
{
	terms[0] = poly;
}

double& Poly::operator[](unsigned int index)
{
	return terms[index];
}

Poly& Poly::operator=(const Poly& poly)
{
	if (this != &poly) {
		terms = poly.terms;
	}
	return *this;
}

Poly Poly::operator+(const Poly& poly) const
{
	Poly result;
	for (const auto& term : terms) {
		result.terms[term.first] += term.second;
	}
	return result;
}
Poly operator+(double p1, const Poly& p2)
{
	Poly result = p2;
	result.terms[0] += p1;
	return result;
}

Poly Poly::operator-(const Poly& poly) const
{
	Poly result;
	
	for (const auto& term : terms) {
		result.terms[term.first] += term.second;
	}
	for (const auto& term : poly.terms) {
		result.terms[term.first] -= term.second;
	}
	
	auto currTerms = result.terms.begin();
	
	while(currTerms != result.terms.end()){
		if(currTerms->second == 0){
			currTerms = result.terms.erase(currTerms);
			return 0;
		}
		else{
			currTerms++;
		}
	}
	return result;
}

Poly operator-(double p1, const Poly& p2)
{
	Poly result = -p2;
	result.terms[0] += p1;
	return result;
}
Poly Poly::operator-() const
{
	Poly result = *this;
	for (auto& term : result.terms) {
		term.second = -term.second;
	}
	return result;
}

Poly Poly::operator*(const Poly& poly) const
{
	Poly result;
	for (const auto& term1 : terms) {
		for (const auto& term2 : poly.terms) {
			result.terms[term1.first + term2.first] +=
				term1.second * term2.second;
		}
	}
	return result;
}
Poly operator*(double p1, const Poly& p2)
{
	Poly result = p2;
	for (auto& term : result.terms) {
		term.second *= p1;
	}
	return result;
}

double Poly::operator()(double x) const
{
	double result = 0.0;
	for (const auto& term : terms) {
		result += term.second * pow(x, term.first);
	}
	return result;
}

std::ostream& operator<<(std::ostream& os, const Poly& poly)
{
	auto it = poly.terms.rbegin();
	if (it != poly.terms.rend()) {
		os << it->second;
		if (it->first != 0) {
			os << "x^" << it->first;
		}
		++it;
		for (;it != poly.terms.rend(); ++it) {
			if(it->second > 0){
			os << " + " << it->second;
			if (it->first != 0) {
				os << "x^" << it->first;
			}
		}
		else{
			os << " " << it->second;
			if (it->first != 0) {
				os << "x^" << it->first;
			}
		}
		}
	}
	return os;
}
