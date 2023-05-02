var fs = require('fs');
var data = "";

fs.readFile('newFile.txt',"utf-8", function(err,data){
    if(err) throw err;
});

fs.writeFile('newFile2.txt',data, function(err){
    if(err) throw err;
    console.log("File created successfully");
});