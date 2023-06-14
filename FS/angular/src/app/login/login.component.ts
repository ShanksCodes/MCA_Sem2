import { Component } from '@angular/core';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent {
  name: string = '';
  email: string = '';
  password: string = '';

  handleSubmit() {
    //event.preventDefault();
    // Handle form submission logic here
  }
}
