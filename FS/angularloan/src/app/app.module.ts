import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { FormsModule } from '@angular/forms';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { CarLoanComponent } from './car-loan/car-loan.component';
import { HomeLoanComponent } from './home-loan/home-loan.component';

@NgModule({
  declarations: [
    AppComponent,
    CarLoanComponent,
    HomeLoanComponent
  ],
  imports: [
    BrowserModule,
    FormsModule,
    AppRoutingModule
    
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
