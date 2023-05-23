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


  export const FormA =()=>{
    return(

      <form>
      <br/>
      <div>Name: <input type="text" name="myName" /></div>
      <br />
      <div>Email: <input type="email" name="myEmail" /></div>
      <br />
      Address:
      <div>
        <textarea name="myAddress" rows="10" cols="40"></textarea>
      </div>
      <br/>
      <div>
        Post code: <input type="text" name="code"/>
      </div>
      <h3>Product details </h3>
      
<table>
        <tr>
          <th>Product</th>
          <th>Part Number</th>
          <th>Quantity</th>
          <th>Unit Price</th>
          <th>Sub total</th>
        </tr>

        <tr>
          <td>.</td> 
          <td><input type="text"/></td>
          <td><input type="number"/></td>
          <td><input type="number"/></td>
          <td><input type="text"/></td>
        </tr>
        <tr>
            <td>Standard Box</td>
            <td><input type="text" /></td>
            <td><input type="number" /></td>
            <td><input type="number" /></td>
            <td><input type="text" /></td>
          </tr>
          <tr>
            <td>Premium Box</td>
            <td><input type="text" /></td>
            <td><input type="number" /></td>
            <td><input type="number" /></td>
            <td><input type="text" /></td>
          </tr>
          <tr>
            <td>Deluxe Box</td>
            <td><input type="text" /></td>
            <td><input type="number" /></td>
            <td><input type="number" /></td>
            <td><input type="text" /></td>
          </tr>
          <tr>
            <td>Super Deluxe Box</td>
            <td><input type="text" /></td>
            <td><input type="number" /></td>
            <td><input type="number" /></td>
            <td><input type="text" /></td>
          </tr>
          <tr>
            <td align="right" colspan="5">
              Total <input type="text" />
            </td>
          </tr>
      </table>



      
      <h3>Credit Card Details</h3>
      <h4>Card type:</h4>
      <input type="radio" name="Card" value="Master Card" />Master card  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;

      Card Number: <input type="text" name="card NUmber" />   <br/>

      <input type="radio" name="Card" value="Visa" /> Visa   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; &nbsp;&nbsp;&nbsp;&nbsp;

      Expiry Date: &nbsp; <input type="date" name="expiry date" /> <br/>
    
      <input type="radio" name="Card" value="American Express" /> American
      Express<br />
      <input type="radio" name="Card" value="Diners club" /> Diners club<br />
      <br />
      Delivery Address:
      <div>
        <textarea name="newAddress" rows="10" cols="40"></textarea>
      </div>
      <br/>
      <input type="button" value="Send Order" />
      <input type="reset" value="Clear Form" />
    </form>

  
    )
  }