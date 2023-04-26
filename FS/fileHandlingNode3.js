var fs = require('fs');

fs.readFile('newFile.txt',"utf-8", function(err,data){
    if(err) throw err;
    console.log(data);
});

