#pragma once

class OccupationStrategy {
	public:								
	virtual double getSalary(double base, double bonus, double level)=0;
	virtual ~OccupationStrategy() = default;
};

class SalesmanStrategy : public OccupationStrategy {
	public:
	double getSalary(double base, double bonus, double level)override
	{
		if(level<60){
			return base;
		}
		else if(level>=60&&level<70){
			return base+bonus*0.6;
		}
		else if (level>=70&&level<80){
			return base+bonus*0.7;
		}
		else if (level>=80&&level<100){
			return base+bonus;
		}
	}
};

class DeveloperStrategy : public OccupationStrategy {
	public:
		double getSalary(double base, double bonus, double level)override
	{

			return base+level*0.01*bonus;

	}	

};