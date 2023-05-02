//Find the number of students enrolled in each course.
var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://localhost:27017/";

MongoClient.connect(url, function(err, db) {
  if (err) throw err;
  var dbo = db.db("mongoAssignment");
  dbo.collection("Enrolment").aggregate([{$group: {_id: "$Course", count: {$sum: 1}}}]).toArray(function(err, result) {
    if (err) throw err;
    console.log(result);
    db.close();
  });
});
