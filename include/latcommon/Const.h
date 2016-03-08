// This file is part of LatCommon.
//
// LatCommon
// Copyright (C) 2012-2016  Pierre L'Ecuyer and Universite de Montreal
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * \file latcommon/Const.h
 *
 * This module contains global constants used in LatMRG and Lattice Builder.
 * \remark **Richard:** Most of these are used only in LatMRG; thus should
 * separate this in two different files: one common and one in LatMRG.
 *
 */

#ifndef LATCOMMON__CONST_H
#define LATCOMMON__CONST_H
#include <string>


namespace LatCommon {

/**
 * Indicates which norm is used to measure the length of vectors. For \f$X =
 * (x_1,…,x_t)\f$,
 *
 * `SUPNORM` corresponds to
 * \f$\Vert X\Vert= \max(|x_1|,…,|x_t|)\f$.<br> `L1NORM` corresponds to
 * \f$\Vert X\Vert= |x_1|+\cdots+|x_t|\f$.<br> `L2NORM` corresponds to
 * \f$\Vert X\Vert= (x_1^2+\cdots+x_t^2)^{1/2}\f$.<br> `ZAREMBANORM`
 * corresponds to \f$\Vert X\Vert= \max(1, |x_1|)\cdots\max(1, |x_t|)\f$.
 */
enum NormType { SUPNORM, L1NORM, L2NORM, ZAREMBANORM };

/**
 * Used to identify the type of a generator. If a generator is of type `MWC`,
 * it is converted to its corresponding `MRG` by the program.
 *
 * `LCG`: the linear congruential generator.<br>
 * `MRG`: the multiple-recursive generator.<br>
 * `MWC`: the multiply-with-carry generator.<br>
 * `KOROBOV`: the Korobov lattice.<br>
 * `RANK1`: the rank 1 lattice.
 */
enum GenType { LCG, MRG, MWC, KOROBOV, RANK1 };

/**
 * Indicates whether to analyze the lattice generated by all possible states,
 * or a sub-lattice generated by the set of recurrent states or by a
 * sub-cycle of the generator.
 *
 * `FULL`: The complete lattice, generated by all possible initial states,
 * will be analyzed.<br> `RECURRENT`: If the (combined) generator has
 * transient states, then the lattice analyzed will be the sub-lattice
 * generated by the set of recurrent states.<br> `ORBIT`: The grid generated
 * by the (forward) orbit of a state of the (combined) generator is analyzed.
 * This state is specified as follows. On the following \f$J\f$ lines, the
 * initial state for each component must be given. This is an integer vector
 * with a number of components equal to the order of the component.<br>
 * `PRIMEPOWER`: In the case where some component is an MLCG whose modulus is
 * a power of a prime \f$p\f$, then the states visited over a single orbit
 * (sub-cycle) of that component generate a sub-lattice (when \f$a
 * \equiv1 \bmod p\f$) or belong to the union of \f$p-1\f$ sub-lattices
 * (otherwise). If `LatticeType` takes this value, and a component is a MLCG
 * (\f$k=1\f$), and if the modulus of that MLCG is given in the data file in
 * the form (b): \f$(x y z)\f$ with \f$z=0\f$ and \f$x\f$ prime, then what is
 * analyzed is one of those sub-lattices. This is done by dividing the
 * modulus by the appropriate power of \f$p\f$, as described in
 * \cite rLEC94e&thinsp;. For example, if \f$p=2\f$ and \f$a \mod8 = 5\f$,
 * then the modulus is divided by 4 as in \cite rFIS90a,
 * \cite rKNU81a&thinsp;.
 */
enum LatticeType { FULL, RECURRENT, ORBIT, PRIMEPOWER };

/**
 * Indicates whether an integer is prime, probably prime, composite or its
 * status is unknown (or don’t care).
 */
enum PrimeType { UNKNOWN, PRIME, PROB_PRIME, COMPOSITE };

/**
 * Given an integer \f$r\f$, indicates what to do about the decomposition of
 * \f$r\f$ in its prime factors.
 *
 * `DECOMP`: means that the program will factorize \f$r\f$.<br>
 * <tt>DECOMP_WRITE</tt>: means that the program will factorize \f$r\f$ and
 * writes the factors in a file.<br>
 * <tt>DECOMP_READ</tt>: means that \f$r\f$ is already factorized, and the
 * factors will be read from a file.<br>
 * <tt>DECOMP_PRIME</tt>: means that \f$r\f$ is prime. No factorization will
 * be done.
 */
enum DecompType { DECOMP, DECOMP_WRITE, DECOMP_READ, DECOMP_PRIME };

/**
 * Indicates in which form and where the results will be sent.
 * \anchor REF__Const_co_output
 *
 * `TERMINAL`: the results will appear only on the terminal screen.<br>
 * `RES`: the results will be in plain text format and sent to a file with
 * extension "<tt>.res</tt>".<br>
 * `TEX`: the results will be in LaTeX format and sent to a file with extension
 * "<tt>.tex</tt>".<br>
 * `GEN`: the results will be sent to a file with extension "<tt>.gen</tt>".
 */
enum OutputType { TERMINAL, RES, TEX, GEN };

/**
 * Gives the merit criterion for ranking generators or lattices.
 *
 * `BEYER`: the figure of merit is the Beyer quotient \f$Q_T\f$.<br>
 * `SPECTRAL`: the figure of merit \f$S_T\f$ is based on the spectral
 * test.<br>
 * `PALPHA`: the figure of merit is based on \f$P_{\alpha}\f$.<br>
 * <tt>BOUND_JS</tt>: the figure of merit is based on
 * the Joe-Sinescu bound \cite rSIN08a&thinsp;.
 */
enum CriterionType { SPECTRAL, BEYER, PALPHA, BOUND_JS };

/**
 * Indicates which normalization is used to compute \f$S_t\f$ in the spectral
 * test, for each dimension \f$t\f$.
 *
 * `BESTLAT`: the value used for \f$d_t^*\f$ corresponds to the best
 * lattice.<br>
 * `LAMINATED`: the value used for \f$d_t^*\f$ corresponds to the best
 * *laminated* lattice.<br>
 * `ROGERS`: the value for \f$d_t^*\f$ is obtained from *Rogers’* bound on the
 * density of sphere packing.<br>
 * `MINKOWSKI`: the value for \f$d_t^*\f$ is obtained from *Minkowski’*
 * theoretical bounds on the length of the shortest nonzero vector in the
 * lattice using the \f${\mathcal{L}}_2\f$ norm.<br>
 * `MINKL1`: the value for \f$d_t^*\f$ is obtained from the theoretical bounds
 * on the length of the shortest nonzero vector in the lattice using the
 * \f${\mathcal{L}}_1\f$ norm.<br>
 * <tt>PALPHA_N</tt>: the case of the \f$P_{\alpha}\f$ test.<br>
 * <tt>NORMA_GENERIC</tt>: the trivial normalization (= 1) used for the generic
 * case when no useful normalization constant is known.
 */
enum NormaType { BESTLAT, LAMINATED, ROGERS, MINKOWSKI, MINKL1,
                 PALPHA_N, NORMA_GENERIC };

/**
 * Indicates which type of calculation is considered for the
 * \f$P_{\alpha}\f$ test. \anchor REF__Const_CalcType_def
 *
 * `PAL` is for the \f$P_{\alpha}\f$ test. <br>
 * `BAL` is for the bound on the \f$P_{\alpha}\f$ test. <br>
 * `NORMPAL` is for the \f$P_{\alpha}\f$ test `PAL`, with the result normalized
 * over the `BAL` bound. <br>
 * `SEEKPAL` is for the \f$P_{\alpha}\f$ seek, which searches
 * for good values of the multiplier.
 */
enum CalcType { PAL, NORMPAL, BAL, SEEKPAL };

/**
 * Indicates which type of conditions are imposed on the coefficients
 * \f$a_i\f$ of a recurrence.
 *
 * <tt>NO_COND</tt>: no condition is imposed on the coefficients.<br>
 * <tt>APP_FACT</tt>: the coefficients must satisfy the "approximate
 * factoring" condition \f$|a_i| (m\mod|a_i|) < m\f$. Congruential
 * generators are easier to implement under this condition
 * \cite rLEC90a&thinsp;.<br>
 * <tt>POWER_TWO</tt>: the coefficients must be sums or differences of powers
 * of 2.<br>
 * <tt>EQUAL_COEF</tt>: all the coefficients must be equal by groups: a first
 * group all equal to a first number, a second group all equal to a second
 * number, and so on. <br>
 * <tt>ZERO_COEF</tt>: all the coefficients must be equal to 0, except for a
 * select fews.
 */
enum ImplemCond { NO_COND, APP_FACT, POWER_TWO, EQUAL_COEF, ZERO_COEF };

/**
 * Indicates the search method used to find good multipliers \f$a_i\f$.
 *
 * `EXHAUST`: the search will be exhaustive over the chosen regions.<br>
 * `RANDOM`: the search will be random over the chosen regions.
 */
enum SearchMethod { EXHAUST, RANDOM };

/**
 * \name toString functions
 *
 * Useful functions for printing the `enum` constants in this module.
 * 
 * @{
 *
 * Returns the `enum` constants in this module as strings.
 * \remark **Richard:** These are global methods for now, but maybe `Const`
 * should be a class containing these methods.
 */
std::string toStringNorm (NormType);
std::string toStringGen (GenType);
std::string toStringLattice (LatticeType);
std::string toStringPrime (PrimeType);
std::string toStringDecomp (DecompType);
std::string toStringOutput (OutputType);
std::string toStringCriterion (CriterionType);
std::string toStringNorma (NormaType);
std::string toStringCalc (CalcType);
std::string toStringImplemCond (ImplemCond);
std::string toStringSearchMethod (SearchMethod);

/**
 * @}
 */
}
#endif
