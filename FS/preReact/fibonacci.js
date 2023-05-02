const n = 10; // Number of terms

let num1 = 0, num2 = 1, nextTerm;

console.log('Fibonacci Series:');
console.log(num1); // print first term
console.log(num2); // print second term

for (let i = 3; i <= n; i++) {
  nextTerm = num1 + num2;
  console.log(nextTerm);
  num1 = num2;
  num2 = nextTerm;
}
