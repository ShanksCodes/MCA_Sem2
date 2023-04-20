/*var MongoClient = require('mongodb').MongoClient;
var url = 'mongodb://0.0.0.0:27017';
MongoClient.connect(url, function(err,dbClient){
    if(err) throw err;
    var dbo = dbClient.db("fs_stud_lab2",function(err,res){      //student id name phone number city
        if(err) throw err;   
        console.log("collection created");
        dbClient.close();
    });
}); console.log("hi");*/


var MongoClient = require('mongodb').MongoClient;
var url = 'mongodb://0.0.0.0:27017';

MongoClient.connect(url, function(err, dbClient) {
  if (err) throw err;
  
  var dbo = dbClient.db("fs_stud_lab2");
  
  var students = [
    { student_id: 1, name: "Rahul", phone_number: "9876543210", city: "Delhi" },
    { student_id: 2, name: "Amit", phone_number: "8765432109", city: "Mumbai" },
    { student_id: 3, name: "Neha", phone_number: "7654321098", city: "Kolkata" },
    { student_id: 4, name: "Riya", phone_number: "6543210987", city: "Delhi" },
    { student_id: 5, name: "Kunal", phone_number: "5432109876", city: "Bangalore" }
  ];
  
  dbo.collection("Indian_Students").insertMany(students, function(err, res) {
    if (err) throw err;
    console.log("Number of documents inserted: " + res.insertedCount);
    dbClient.close();
  });
});

