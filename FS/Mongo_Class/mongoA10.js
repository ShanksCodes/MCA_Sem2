//add an address and phone number field to every document
var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://localhost:27017/";

MongoClient.connect(url, function(err, db) {
  if (err) throw err;
  var dbo = db.db("mongoAssignment");
  dbo.collection("Enrolment").updateMany({}, {$set: {phone: ""}}, function(err, result) {
    if (err) throw err;
    console.log(result.modifiedCount + " documents updated");
    db.close();
  });
});
