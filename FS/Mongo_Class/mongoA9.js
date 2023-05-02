//get all students with markspercent greater than 75 and less than 80
var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://localhost:27017/";

MongoClient.connect(url, function(err, db) {
  if (err) throw err;
  var dbo = db.db("mongoAssignment");
  dbo.collection("Enrolment").find({"percentMarks": {$gt: 75, $lt: 80}}).toArray(function(err, result) {
    if (err) throw err;
    console.log(result);
    db.close();
  });
});
