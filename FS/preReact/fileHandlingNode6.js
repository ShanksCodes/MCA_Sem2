var fs = require('fs');
var data = "Learn Node FS module. Library used for file operations";

fs.readFile('newFile.txt',"utf-8", function(err,data){
    if(err) throw err;
});

fs.writeFile('newFileRenamed.txt',data, function(err){
    if(err) throw err;
    console.log("File renamed successfully");
});

fs.unlink('newFile.txt', function(err){
    if(err) throw err;
});