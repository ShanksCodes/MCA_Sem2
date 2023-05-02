const http = require('http');
const host = "localhost";
const port = 3000;

str= `id,name,email\nAT,AbhishekTyagi,abhi@gmail.com\nVT,ViratKohli,virat@gmail.com`;
const requestListener = function(req,res){
    res.setHeader("Content-Type", "text/csv");
    res.writeHead(200);
    res.end(str) 
};

http.createServer(requestListener).listen(port,host,()=>{console.log(`Server is running on http://${host}:${port}`)});

