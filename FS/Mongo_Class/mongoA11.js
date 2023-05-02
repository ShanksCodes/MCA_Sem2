//change name from Akash to Aakash
var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://localhost:27017/";

MongoClient.connect(url, function(err, db) {
  if (err) throw err;
  var dbo = db.db("mongoAssignment");
  var query = { "stNm": "Akash" };
  var update = { $set: { "stNm": "Aakash" } };
  dbo.collection("Student").updateMany(query, update, function(err, res) {
    if (err) throw err;
    console.log(res.result.nModified + " document(s) updated");
    db.close();
  });
});

