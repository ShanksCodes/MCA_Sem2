const arr = [2, 3, 5, 7, 10, 12, 13, 14, 15, 17, 19, 20, 23, 29]; // Example array

const evenNumbers = [];
const oddNumbers = [];
const primeNumbers = [];
const nonPrimeNumbers = [];

for (let i = 0; i < arr.length; i++) {
  let isPrime = true;

  // Check if the number is even or odd
  if (arr[i] % 2 === 0) {
    evenNumbers.push(arr[i]);
  } else {
    oddNumbers.push(arr[i]);
  }

  // Check if the number is prime or non-prime
  if (arr[i] === 2) {
    primeNumbers.push(arr[i]);
  } else if (arr[i] > 2) {
    for (let j = 2; j < arr[i]; j++) {
      if (arr[i] % j === 0) {
        isPrime = false;
        break;
      }
    }

    if (isPrime) {
      primeNumbers.push(arr[i]);
    } else {
      nonPrimeNumbers.push(arr[i]);
    }
  }
}

console.log('Even numbers:', evenNumbers);
console.log('Odd numbers:', oddNumbers);
console.log('Prime numbers:', primeNumbers);
console.log('Non-prime numbers:', nonPrimeNumbers);
