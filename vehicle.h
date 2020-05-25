#ifndef VEHICLE_H_
#define VEHICLE_H_

class vehicle
{public:
	char type[30];
	int vno;
	float count;
	char dname[30];
	char cctv_location;
	char* entry;
	char* exit;
	
	int input();
	void output();
	void bill();
	void entry_time();
	void exit_time();
};
#endif

#ifndef two_WHEELER_H_
#define two_WHEELER_H_

class two_wheeler:public vehicle
{public:
	float p;
	
	two_wheeler()
	{
		p=20;
      
	}
	void cal_two();

};
#endif

#ifndef four_WHEELER_LIGHT_H_
#define four_WHEELER_LIGHT_H_

class four_wheeler_light:public vehicle
{public:
	float price;
	
	four_wheeler_light()
	{
		price=30;
	
	}
	void cal_fourL();
};
#endif

#ifndef four_WHEELER_HEAVY_H_
#define four_WHEELER_HEAVY_H_

class four_wheeler_heavy:public vehicle
{public:
	float cost;
	
	four_wheeler_heavy()
	{
		cost=35;
	}
	
	void cal_fourH();
};
#endif








