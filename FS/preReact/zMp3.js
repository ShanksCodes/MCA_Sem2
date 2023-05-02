const MongoClient = require('mongodb').MongoClient;
const url = "mongodb://localhost:27017/mydb";

MongoClient.connect(url, function(err, db) {
  if (err) throw err;

  const myCollection = db.collection('mycollection');

  const myDocument = { name: 'John Doe', age: 30 };

  myCollection.insertOne(myDocument, function(err, res) {
    if (err) throw err;

    console.log("1 document inserted");

    db.close();
  });
});



console.log("ok");