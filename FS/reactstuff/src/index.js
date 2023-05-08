import React from 'react';
import ReactDOM from 'react-dom/client';
import App from './App';

function FunCompEx(props)
 {
    return(
    <div>
    <h1>This is one of the components created by {props.nm} at {props.at}</h1>       
    </div>)
 }

function Login()
  {
    return(
    <div>
    
 
    </div>)
  }
 

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
    <App />
    <FunCompEx nm="abhi" at="bciiit"/>
    <Login/>
  </React.StrictMode>
);