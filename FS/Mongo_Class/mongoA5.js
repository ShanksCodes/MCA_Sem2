const MongoClient = require('mongodb').MongoClient;
const url = 'mongodb://localhost:27017/';
const dbName = 'mongoAssignment';

MongoClient.connect(url, function(err, client) {
  if (err) throw err;

  const db = client.db(dbName);
  const studentCollection = db.collection('Student');
  const enrolmentCollection = db.collection('Enrolment');

  // Join the collections on Roll_No field
  studentCollection.aggregate([
    {
      $lookup:
        {
          from: "Enrolment",
          localField: "Roll_No",
          foreignField: "Roll_No",
          as: "enrolmentData"
        }
    }
  ]).toArray(function(err, result) {
    if (err) throw err;

    // Display the results
    result.forEach(function(item) {
      console.log(`Roll No: ${item.Roll_No}`);
      console.log(`Name: ${item.stNm}`);
      console.log(`Course: ${item.enrolmentData[0].Course}`);
      console.log(`Grade: ${item.enrolmentData[0].Grade}`);
      console.log('\n');
    });

    client.close();
  });
});
