const arr = [2, 3, 50, 4, 11, 13, 17, 20, 23, 29]; // Example array
const primes = [];

for (let i = 0; i < arr.length; i++) {
  let isPrime = true;

  for (let j = 2; j < arr[i]; j++) {
    if (arr[i] % j === 0) {
      isPrime = false;
      break;
    }
  }

  if (isPrime) {
    primes.push(arr[i]);
  }
}

console.log('Prime numbers in the array:', primes);
