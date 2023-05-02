var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://localhost:27017/";

MongoClient.connect(url, function(err, db) {
  if (err) throw err;
  var dbo = db.db("mongoAssignment");
  var myobj = [
    { "Roll_No": 1, "stNm": "Alok", "Address": "Karol Bagh, Delhi" },
    { "Roll_No": 2, "stNm": "Bhawna", "Address": "Dwarka, Delhi" },
    { "Roll_No": 3, "stNm": "Chirag", "Address": "Rohini, Delhi" },
    { "Roll_No": 4, "stNm": "Deepak", "Address": "Janakpuri, Delhi" },
    { "Roll_No": 5, "stNm": "Ekta", "Address": "Pitampura, Delhi" }
  ];


  var myobj2 =[
    { "Roll_No": 1, "Course": "BCA", "Grade": "A", "percentMarks": 95 },
    { "Roll_No": 2, "Course": "MCA", "Grade": "B", "percentMarks": 80 },
    { "Roll_No": 3, "Course": "Btech", "Grade": "C", "percentMarks": 70 },
    { "Roll_No": 4, "Course": "BCA", "Grade": "A", "percentMarks": 92 },
    { "Roll_No": 5, "Course": "MCA", "Grade": "B", "percentMarks": 78 }

  ];

  dbo.collection("Student").insertMany(myobj, function(err, res) {
    if (err) throw err;
    console.log("Number of documents inserted in Student collection: " + res.insertedCount);
  //  db.close();
  });

  dbo.collection("Enrolment").insertMany(myobj2, function(err, res) {
    if (err) throw err;
    console.log("Number of documents inserted in Enrolment collection: " + res.insertedCount);
    db.close();
  });

});
