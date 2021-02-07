##################################
#   Analysis of Primes Under N   #
#           M. R. Schwob         #
##################################

###
###  Load Output from pp.cpp
###

# load dataset
output <- read.csv("~/Desktop/Palindromes/output.txt")

# set N
N = 100000

# obtain unique values of primes featured in output
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
###  Obtain List of Prime Numbers that Have a Mirror in Some Base (2,...,10)
###

#primeOutput = primeOutput[1:160]

counts = rep(FALSE, length(primes))

for(i in 1:length(primes)){
  for(j in 1:length(primeOutput)){
    if(primes[i] == primeOutput[j]){
      counts[i] = TRUE
    }
  }
}

percentage = sum(counts)/length(counts)
percentage

###
###  Let's Obtain a Nice Graphic
###

percVec = c(rep(0,length(1000:100000)))
counter = 0

sequence = seq(1000,100000,100) # relatively decent resolution

for(maxSize in sequence){
  
  primeList = primes[primes<=maxSize]
  primeOut = primeOutput[primeOutput<=maxSize]
  counts = rep(FALSE, length(primeList))
  
  for(i in 1:length(primeList)){
    
    for(j in 1:length(primeOut)){
      
      if(primeList[i] == primeOut[j]){
        counts[i] = TRUE
      }
    }
  }
  
  counter = counter + 1
  percVec[i] = sum(counts)/length(counts)
  cat("  ", (max(sequence)-maxSize)/100)
  
}
