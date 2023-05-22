const http = require('http');
const host = "localhost";
const port = 3000;

str= `<html><body><h1>MCA 2nd Sem This is HTML output at <b>Node Server</b></h1></body></html>`;
const requestListener = function(req,res){
    res.setHeader("Content-Type", "text/html");
    res.writeHead(200);
    res.end(str) 
};

http.createServer(requestListener).listen(port,host,()=>{console.log(`Server is running 
on http://${host}:${port}`)});

