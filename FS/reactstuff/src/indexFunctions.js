export function FunCompEx(props)
 {
    return(
    <div>
    <h1>This is one of the components created by {props.nm} at {props.at}</h1>       
    </div>)
 }


export function Login()
  {
    return(
    <form>
       
    <h1>Abhi.com</h1>
    <input placeholder="Enter Your Name" type="text" name="name" id="name" />
    <input
    placeholder="Enter Your Email"
    type="email"
    name="email"
    id="email"
    />
   
   <input
    placeholder="Enter Your Password"
    type="password"
    name="password"
    id="password"
  />

   <input type="submit" value="Login" />
    
    </form>)
  }
