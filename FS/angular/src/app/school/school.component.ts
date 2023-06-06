import { Component } from '@angular/core';

@Component({
  selector: 'app-school',
  templateUrl: './school.component.html',
  styleUrls: ['./school.component.css']
})
export class SchoolComponent {
  name: string = "Abhishek";
  marks: number = 100;
  math: number = 90;
  eng: number = 85;
  phy: number = 95;
  chem: number = 88;
  cs: number = 92;

  calculateTotal(): number {
    return this.math + this.eng + this.phy + this.chem + this.cs;
  }
}
