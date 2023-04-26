var fs = require('fs');
var data = "Learn Node FS module. Library used for file operations";

fs.unlink('newFile.txt', function(err){
    if(err) throw err;
    console.log("File deleted successfully");
});