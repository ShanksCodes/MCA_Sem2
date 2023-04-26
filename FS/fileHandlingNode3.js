var fs = require('fs');
var data = "Learn Node FS module. Library used for file operations";

fs.readFile('newFile.txt',"utf-8", function(err,data){
    if(err) throw err;
    console.log(data);
});