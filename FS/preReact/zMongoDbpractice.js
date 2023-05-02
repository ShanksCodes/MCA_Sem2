/*
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

});

console.log("ok");*/

const mongoose = require('mongoose');
mongoose.set('strictQuery', true);  //added to prevent deprecation warning

// Define a schema for your data
const userSchema = new mongoose.Schema({
  name: String,
  email: String,
  password: String,
});

// Create a model for your data
const User = mongoose.model('User', userSchema);

// Connect to the database and insert some data
mongoose
  .connect('mongodb://localhost:27017/testingdb')
  .then(() => {
    const newUser = new User({
      name: 'John Doe',
      email: 'johndoe@example.com',
      password: 'password123',
    });

    return newUser.save();
  })
  .then(() => console.log('Data inserted successfully'))
  .catch((err) => console.log(err));
