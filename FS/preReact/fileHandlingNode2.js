var fs = require('fs');
var data = "Learn Node FS module. Library used for file operations";

fs.writeFile('newFile.txt',data, function(err){
    if(err) throw err;
    console.log("File created successfully");
});