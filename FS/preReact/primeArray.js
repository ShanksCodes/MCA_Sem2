function isPrime(num) {
    // Check if a number is prime
    if (num < 2) {
      return false;
    }
    for (let i = 2; i <= Math.sqrt(num); i++) {
      if (num % i === 0) {
        return false;
      }
    }
    return true;
  }
  
  function separatePrimes(inputArray) {
    const primes = [];
    const nonPrimes = [];
  
    // Loop through each element in the input array
    for (let i = 0; i < inputArray.length; i++) {
      const num = inputArray[i];
  
      // Check if the current number is prime
      if (isPrime(num)) {
        primes.push(num);
      } else {
        nonPrimes.push(num);
      }
    }
  
    // Return the result object
    return { primes, nonPrimes };
  }
  
  // Example usage:
  const inputArray = [2, 3, 4, 5, 6, 7];
  const result = separatePrimes(inputArray);
  console.log("Prime numbers:", result.primes);
  console.log("Non-prime numbers:", result.nonPrimes);
  