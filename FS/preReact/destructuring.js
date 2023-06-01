let x, y, a1, b1, d, z, rest, pop, push;
var array = [1,2,3,4,5,6,7,8,9];
var arr = [];
[x,y] = array;
console.log(x);
console.log(y);

[x, , y] = array;
console.log("\n", x);
console.log(y);

[x=123, y] = array;
console.log("\n", x);
console.log(y);


[x=123, y] = arr;
console.log("\n", x);
console.log(y);

[x,y,...rest] = array;
console.log("\n", x);
console.log(y);
console.log(rest);

[x,y,...[z, d]] = array;
console.log("\n", x);
console.log(y);
console.log(d);




