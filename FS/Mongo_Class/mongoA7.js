//get all students with Grade A or B

var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://localhost:27017/";

MongoClient.connect(url, function(err, db) {
  if (err) throw err;
  var dbo = db.db("mongoAssignment");
  dbo.collection("Enrolment").find({"Grade": {$in: ["A", "B"]}}).toArray(function(err, result) {
    if (err) throw err;
    console.log(result);
    db.close();
  });
});
