//To get all students with marks percent less than 50 or greater than 75, you can use the following code:
var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://localhost:27017/";

MongoClient.connect(url, function(err, db) {
  if (err) throw err;
  var dbo = db.db("mongoAssignment");
  dbo.collection("Enrolment").find({$or: [{"percentMarks": {$lt: 50}}, {"percentMarks": {$gt: 75}}]}).toArray(function(err, result) {
    if (err) throw err;
    console.log(result);
    db.close();
  });
});
