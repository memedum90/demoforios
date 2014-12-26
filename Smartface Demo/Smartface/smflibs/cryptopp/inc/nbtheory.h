// nbtheory.h - written and placed in the public domain by Wei Dai

#ifndef CRYPTOPP_NBTHEORY_H
#define CRYPTOPP_NBTHEORY_H

#include "integer.h"
#include "algparam.h"

NAMESPACE_BEGIN(SmfCryptoPP)

// obtain pointer to small prime table and get its size
CRYPTOPP_DLL const word16 * CRYPTOPP_API GetPrimeTable(unsigned int &size);

// ************ primality testing ****************

// generate a provable prime
CRYPTOPP_DLL Integer CRYPTOPP_API MaurerProvablePrime(RandomNumberGenerator &rng, unsigned int bits);
CRYPTOPP_DLL Integer CRYPTOPP_API MihailescuProvablePrime(RandomNumberGenerator &rng, unsigned int bits);

CRYPTOPP_DLL bool CRYPTOPP_API IsSmallPrime(const Integer &p);

// returns true if p is divisible by some prime less than bound
// bound not be greater than the largest entry in the prime table
CRYPTOPP_DLL bool CRYPTOPP_API TrialDivision(const Integer &p, unsigned bound);

// returns true if p is NOT divisible by small primes
CRYPTOPP_DLL bool CRYPTOPP_API SmallDivisorsTest(const Integer &p);

// These is no reason to use these two, use the ones below instead
CRYPTOPP_DLL bool CRYPTOPP_API IsFermatProbablePrime(const Integer &n, const Integer &b);
CRYPTOPP_DLL bool CRYPTOPP_API IsLucasProbablePrime(const Integer &n);

CRYPTOPP_DLL bool CRYPTOPP_API IsStrongProbablePrime(const Integer &n, const Integer &b);
CRYPTOPP_DLL bool CRYPTOPP_API IsStrongLucasProbablePrime(const Integer &n);

// Rabin-Miller primality test, i.e. repeating the strong probable prime test 
// for several rounds with random bases
CRYPTOPP_DLL bool CRYPTOPP_API RabinMillerTest(RandomNumberGenerator &rng, const Integer &w, unsigned int rounds);

// primality test, used to generate primes
CRYPTOPP_DLL bool CRYPTOPP_API IsPrime(const Integer &p);

// more reliable than IsPrime(), used to verify primes generated by others
CRYPTOPP_DLL bool CRYPTOPP_API VerifyPrime(RandomNumberGenerator &rng, const Integer &p, unsigned int level = 1);

class CRYPTOPP_DLL PrimeSelector
{
public:
	const PrimeSelector *GetSelectorPointer() const {return this;}
	virtual bool IsAcceptable(const Integer &candidate) const =0;
};

// use a fast sieve to find the first probable prime in {x | p<=x<=max and x%mod==equiv}
// returns true iff successful, value of p is undefined if no such prime exists
CRYPTOPP_DLL bool CRYPTOPP_API FirstPrime(Integer &p, const Integer &max, const Integer &equiv, const Integer &mod, const PrimeSelector *pSelector);

CRYPTOPP_DLL unsigned int CRYPTOPP_API PrimeSearchInterval(const Integer &max);

CRYPTOPP_DLL AlgorithmParameters CRYPTOPP_API MakeParametersForTwoPrimesOfEqualSize(unsigned int productBitLength);

// ********** other number theoretic functions ************

inline Integer GCD(const Integer &a, const Integer &b)
	{return Integer::Gcd(a,b);}
inline bool RelativelyPrime(const Integer &a, const Integer &b)
	{return Integer::Gcd(a,b) == Integer::One();}
inline Integer LCM(const Integer &a, const Integer &b)
	{return a/Integer::Gcd(a,b)*b;}
inline Integer EuclideanMultiplicativeInverse(const Integer &a, const Integer &b)
	{return a.InverseMod(b);}

// use Chinese Remainder Theorem to calculate x given x mod p and x mod q, and u = inverse of p mod q
CRYPTOPP_DLL Integer CRYPTOPP_API CRT(const Integer &xp, const Integer &p, const Integer &xq, const Integer &q, const Integer &u);

// if b is prime, then Jacobi(a, b) returns 0 if a%b==0, 1 if a is quadratic residue mod b, -1 otherwise
// check a number theory book for what Jacobi symbol means when b is not prime
CRYPTOPP_DLL int CRYPTOPP_API Jacobi(const Integer &a, const Integer &b);

// calculates the Lucas function V_e(p, 1) mod n
CRYPTOPP_DLL Integer CRYPTOPP_API Lucas(const Integer &e, const Integer &p, const Integer &n);
// calculates x such that m==Lucas(e, x, p*q), p q primes, u=inverse of p mod q
CRYPTOPP_DLL Integer CRYPTOPP_API InverseLucas(const Integer &e, const Integer &m, const Integer &p, const Integer &q, const Integer &u);

inline Integer ModularExponentiation(const Integer &a, const Integer &e, const Integer &m)
	{return a_exp_b_mod_c(a, e, m);}
// returns x such that x*x%p == a, p prime
CRYPTOPP_DLL Integer CRYPTOPP_API ModularSquareRoot(const Integer &a, const Integer &p);
// returns x such that a==ModularExponentiation(x, e, p*q), p q primes,
// and e relatively prime to (p-1)*(q-1)
// dp=d%(p-1), dq=d%(q-1), (d is inverse of e mod (p-1)*(q-1))
// and u=inverse of p mod q
CRYPTOPP_DLL Integer CRYPTOPP_API ModularRoot(const Integer &a, const Integer &dp, const Integer &dq, const Integer &p, const Integer &q, const Integer &u);

// find r1 and r2 such that ax^2 + bx + c == 0 (mod p) for x in {r1, r2}, p prime
// returns true if solutions exist
CRYPTOPP_DLL bool CRYPTOPP_API SolveModularQuadraticEquation(Integer &r1, Integer &r2, const Integer &a, const Integer &b, const Integer &c, const Integer &p);

// returns log base 2 of estimated number of operations to calculate discrete log or factor a number
CRYPTOPP_DLL unsigned int CRYPTOPP_API DiscreteLogWorkFactor(unsigned int bitlength);
CRYPTOPP_DLL unsigned int CRYPTOPP_API FactoringWorkFactor(unsigned int bitlength);

// ********************************************************

//! generator of prime numbers of special forms
class CRYPTOPP_DLL PrimeAndGenerator
{
public:
	PrimeAndGenerator() {}
	// generate a random prime p of the form 2*q+delta, where delta is 1 or -1 and q is also prime
	// Precondition: pbits > 5
	// warning: this is slow, because primes of this form are harder to find
	PrimeAndGenerator(signed int delta, RandomNumberGenerator &rng, unsigned int pbits)
		{Generate(delta, rng, pbits, pbits-1);}
	// generate a random prime p of the form 2*r*q+delta, where q is also prime
	// Precondition: qbits > 4 && pbits > qbits
	PrimeAndGenerator(signed int delta, RandomNumberGenerator &rng, unsigned int pbits, unsigned qbits)
		{Generate(delta, rng, pbits, qbits);}
	
	void Generate(signed int delta, RandomNumberGenerator &rng, unsigned int pbits, unsigned qbits);

	const Integer& Prime() const {return p;}
	const Integer& SubPrime() const {return q;}
	const Integer& Generator() const {return g;}

private:
	Integer p, q, g;
};

NAMESPACE_END

#endif
