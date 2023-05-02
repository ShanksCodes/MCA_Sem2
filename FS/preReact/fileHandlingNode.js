var fs = require('fs');
var data = " Hello! Students This is FS lecture on 25th april where only 9 students were there";

fs.appendFile('newFile.txt',data, function(err){
    if(err) throw err;
    console.log("Data is written to file successfully");
})