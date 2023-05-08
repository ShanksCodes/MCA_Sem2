class Student
 {
    constructor(nm,mks)
     {
        this.name=nm;
        this.marks=mks;
     }

    printInfo()
     {
        console.log(`Hello ${this.name}`);
        console.log(`Your score ${this.marks}`);
     } 
 }

 let user = new Student('Abhishek',95);
 user.printInfo();