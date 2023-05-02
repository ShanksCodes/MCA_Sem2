const MongoClient = require('mongodb').MongoClient;
const url = "mongodb://localhost:27017/";

MongoClient.connect(url, function(err, db) {
  if (err) throw err;
  const dbo = db.db("mongoAssignment");

// (v) get all students with Grade A or B
dbo.collection("Enrolment").aggregate([
    {
      $match: { "Grade": { $in: ["A", "B"] } }
    },
    {
      $lookup: {
        from: "Student",
        localField: "Roll_No",
        foreignField: "Roll_No",
        as: "student_details"
      }
    },
    {
      $project: {
        _id: 0,
        stNm: { $arrayElemAt: ["$student_details.stNm", 0] },
        Course: 1,
        Grade: 1
      }
    }
  ]).toArray(function(err, result) {
    if (err) throw err;
    console.log("(v) All students with Grade A or B:");
    console.log(result);
  });
  
  // (vi) get all students with marks percent less than 50 or greater than 75
  dbo.collection("Enrolment").aggregate([
    {
      $match: { "percentMarks": { $lt: 50, $gt: 75 } }
    },
    {
      $lookup: {
        from: "Student",
        localField: "Roll_No",
        foreignField: "Roll_No",
        as: "student_details"
      }
    },
    {
      $project: {
        _id: 0,
        stNm: { $arrayElemAt: ["$student_details.stNm", 0] },
        Course: 1,
        Grade: 1,
        percentMarks: 1
      }
    }
  ]).toArray(function(err, result) {
    if (err) throw err;
    console.log("(vi) All students with marks percent less than 50 or greater than 75:");
    console.log(result);
  });
  

 /* // (v) get all students with Grade A or B
  dbo.collection("Enrolment").find({ "Grade": { $in: ["A", "B"] } })
    .populate('Roll_No')
    .toArray(function(err, result) {
      if (err) throw err;
      console.log("(v) All students with Grade A or B:");
      console.log(result);
    });

  // (vi) get all students with marks percent less than 50 or greater than 75
  dbo.collection("Enrolment").find({ "percentMarks": { $lt: 50, $gt: 75 } })
    .populate('Roll_No')
    .toArray(function(err, result) {
      if (err) throw err;
      console.log("(vi) All students with marks percent less than 50 or greater than 75:");
      console.log(result);
    });*/

// (vii) get all students with markspercent greater than 75 and less than 80
dbo.collection("Enrolment").aggregate([
    { $match: { percentMarks: { $gt: 75, $lt: 80 } } },
    {
        $lookup:
        {
            from: "Student",
            localField: "Roll_No",
            foreignField: "Roll_No",
            as: "student_details"
        }
    },
    { $unwind: "$student_details" },
    {
        $project:
        {
            _id: 0,
            Roll_No: 1,
            stNm: "$student_details.stNm",
            Course: 1,
            Grade: 1,
            percentMarks: 1
        }
    }
]).toArray(function(err, result) {
    if (err) throw err;
    console.log("(vii) Students with marks greater than 75 and less than 80:");
    console.log(result);
});

// (viii) add an address and phone number field to every document
dbo.collection("Student").updateMany({}, { $set: { Address: "", Phone: "" } }, function(err, result) {
    if (err) throw err;
    console.log("(viii) Address and Phone fields added to every document");
});

// (ix) change stNm from ‘Aditya’ to ‘Akash’
dbo.collection("Student").updateOne({ stNm: "Aditya" }, { $set: { stNm: "Akash" } }, function(err, result) {
    if (err) throw err;
    console.log("(ix) Student name updated from 'Aditya' to 'Akash'");
});

// (x) List all the Students enrolled for ‘BCA’ and have grade ‘A’
dbo.collection("Enrolment").aggregate([
    { $match: { Course: "BCA", Grade: "A" } },
    {
        $lookup:
        {
            from: "Student",
            localField: "Roll_No",
            foreignField: "Roll_No",
            as: "student_details"
        }
    },
    { $unwind: "$student_details" },
    {
        $project:
        {
            _id: 0,
            Roll_No: 1,
            stNm: "$student_details.stNm",
            Course: 1,
            Grade: 1
        }
    }
]).toArray(function(err, result) {
    if (err) throw err;
    console.log("(x) Students enrolled for 'BCA' and have grade 'A':");
    console.log(result);
});

// (xi) Find the number of students enrolled in each course
dbo.collection("Enrolment").aggregate([
    {
        $group:
        {
            _id: "$Course",
            count: { $sum: 1 }
        }
    },
    {
        $project:
        {
            _id: 0,
            Course: "$_id",
            count: 1
        }
    }
]).toArray(function(err, result) {
    if (err) throw err;
    console.log("(xi) Number of students enrolled in each course:");
    console.log(result);
    db.close();
})
});
