var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://localhost:27017/mongoAssignment";
//'mongodb://0.0.0.0:27017/mongoAssignment';
MongoClient.connect(url, function(err, db) {
  if (err) throw err;
  console.log("Database created!");
  db.close();
});