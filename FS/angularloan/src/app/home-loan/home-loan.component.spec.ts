import { ComponentFixture, TestBed } from '@angular/core/testing';

import { HomeLoanComponent } from './home-loan.component';

describe('HomeLoanComponent', () => {
  let component: HomeLoanComponent;
  let fixture: ComponentFixture<HomeLoanComponent>;

  beforeEach(() => {
    TestBed.configureTestingModule({
      declarations: [HomeLoanComponent]
    });
    fixture = TestBed.createComponent(HomeLoanComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
