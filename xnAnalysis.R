###
###  xnAnalysis.R
###  Calculates the Smaug sequence using C++ output
###

output <- read.csv(".../output.txt") # change your directory responsibly

N = 10000 # match N with the passed parameter from pp.cpp

primeOutput = unique(output$Prime1)

###
###  Obtain List of Primes Under N
###

prime_numbers <- function(n) {
  if (n >= 2) {
    x = seq(2, n)
    prime_nums = c()
    for (i in seq(2, n)) {
      if (any(x == i)) {
        prime_nums = c(prime_nums, i)
        x = c(x[(x %% i) != 0], i)
      }
    }
    return(prime_nums)
  }
  else 
  {
    stop("Input number should be at least 2.")
  }
}

primes = prime_numbers(N)

###
###  Outputs the Primes that Require an Additional Base to Obtain a Prime Mirror to Form a Palindrome
###

current = 0

for(i in primes){
  if(output$Base[which(output$Prime1==i)][1] > current){
    current = output$Base[which(output$Prime1==i)][1]
    cat(i, " ")
  }
}
