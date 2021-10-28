# PrimePalindromes

This repository contains several functions that find, use, or manipulate prime palindromes in various bases. As I progressed through this topic, I started with the most basic code (baseConvert.cpp converts a given number into base 2), then worked through more difficult problems. All files, no matter how trivial or nuanced, are shared in this repository.

Algorithms in this repository were used to obtain results in:

Venkat R., Schwob M.R., (2021). "Novel Sequences of Prime Palindromes in Various Bases." _International Journal of Advanced Research in Computer Science_, vol. 12:2.

## Description of Each File

#### baseConvert.cpp 

This file converts the given number into base 2.

#### findPair.cpp

This file finds the palindrome pair for the given number in base 2.

#### primePairs.cpp

This file obtains all prime palindrome pairs up to a given number.

#### pp.cpp

This file obtains a list of prime numbers such that its mirror in any base between 2 and 10 is also a prime number. Its output can be analyzed in xnAnalysis.R.

#### primeAnalysis.R

Using the output from pp.cpp, this file graphs the percentage of prime numbers that have a prime mirror in some base 2-10 against the upperbound of numbers to consider.

#### xn.cpp

This file outputs the primes that require an additional base to obtain a prime mirror in base 10. The generated sequence in base 10 is the Smaug sequence.

#### xnAnalysis.R

Using the output from pp.cpp, this file outputs the primes that require an additional base to obtain a prime mirror in base 10. The generated sequence in base 10 is the Smaug sequence.

## Licensing

This repository is licensed under GNU GPLv3.
