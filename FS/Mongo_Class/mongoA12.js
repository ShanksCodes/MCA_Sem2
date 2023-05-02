//List all the Students enrolled for ‘BCA’ and have grade ‘A’
const MongoClient = require('mongodb').MongoClient;

const uri = 'mongodb://localhost:27017/';
const dbName = 'mongoAssignment';

MongoClient.connect(uri, function(err, client) {
  if (err) {
    console.log(err);
    return;
  }

  const db = client.db(dbName);

  const query = {
    "Course": "BCA",
    "Grade": "A"
  };

  db.collection('Enrolment').aggregate([
    { $match: query },
    {
      $lookup: {
        from: 'Student',
        localField: 'Roll_No',
        foreignField: 'Roll_No',
        as: 'student_details'
      }
    },
    {
      $project: {
        _id: 0,
        stNm: { $arrayElemAt: ["$student_details.stNm", 0] },
        Roll_No: 1,
        Course: 1,
        Grade: 1,
        percentMarks: 1
      }
    }
  ]).toArray(function(err, result) {
    if (err) {
      console.log(err);
      return;
    }

    console.log(result);
    client.close();
  });
});
