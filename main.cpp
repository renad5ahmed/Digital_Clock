#include <iostream>
using namespace std;
void    DigitalCLock1(int sec, char time[11]) {
time[2] = ':';
time[5] = ':';
int M1 = 0, H1=0, H2=0, S1=0, S2 = 0, M2=0;
	char when = 'a'; //indicates AM
	
	if (sec >= 86400) {// aktr mn 24 hours
		time[0] = 'i';	time[1] = 'n';
		time[2] = 'v';	time[3] = 'a';
		time[4] = 'l'; time[5] = 'i';
		time[6] = 'd'; time[7] = '\0';
        return;}
        
	else if (sec == 0) { // exactly midnight
		time[0] = '1'; time[1] = '2';
		time[3] = '0'; time[4] = '0';
		time[6] = '0'; time[7] = '0';
		time[8] = 'a'; time[9] = 'm';
		time[10] = '\0';// null
        return;}
        
	else {
		while (sec > 0) {

			if (sec >= 43200) { // aktr mn 12 hours (y3ny PM)
				sec -= 43200;
				when = 'p';} //keda when b'indicates PM
				
			if (sec < 3600) { // a2l mn saa3a , y3ny elsa3a 12 
				H1 = 1; H2 = 2;
				while (sec >= 60) { 
					M2++;
					sec -= 60;
					if (M2 ==10) {
						M1++;
						M2 = 0;}}
						
					while(sec>0){ S2++;
					sec--;
					if(S2==10){
						S1++; S2=0;}}}//keda awl while
					
			if (sec >= 3600) { // aktr mn sa3a
			
			while(sec>=3600){
				H2++;
				sec -= 3600;
				if (H2 ==10) {
					H1++; H2 = 0;}}}
					
				while (sec > 0) { // h7sb elly fadl d2ay2 wla sawany
					S2++;
					sec--;
					if (S2 ==10) {
						S1++;
						S2 = 0;}
					if (S1 == 6) {
						M2++;
						S1 = 0;}
					if(M2==10){M1++; M2=0;}}
		

			
					
			}}
					
		
		time[0] = H1 + '0'; time[1] = H2 + '0';
		time[3] = M1 + '0'; time[4] = M2 + '0';
		time[6] = S1 + '0'; time[7] = S2 + '0';
		if (when == 'a') {
			time[8] = 'a' ; time[9] = 'm' ;
			time[10] = '\0';
		}
		else if (when == 'p') {
			time[8] = 'p'; time[9] = 'm';
			time[10] = '\0';}}
			

int DigitalClock2(const char time[11]) {
	int H1, H2, M1, M2, S1, S2, HAll, MAll, SAll, All;

	if ((time[0] == '1') && (time[1] == '2')) {
		HAll = 0;}
		
	else {
		H2 = time[1] - '0';
		H1 = time[0] - '0';
		H1 = H1 * 10;
		HAll = (H1 + H2) * 3600;}
		
	M1 = time[3] - '0';
	M2 = time[4] - '0';
	M1 = M1 * 10;
	
	MAll = (M1 + M2) * 60;
	S1 =( time[6] - '0')*10;
	S2 = time[7] - '0';
	SAll = (S1 + S2);

	All = SAll + MAll + HAll;
	if (time[8] == 'p') All += 43200;
	return All;}
	
int main(){

cout << DigitalClock2("12:01:00am") << endl;
cout << DigitalClock2("01:00:00am") << endl;
cout << DigitalClock2("12:00:59am") << endl;
cout << DigitalClock2("12:01:01am") << endl;
cout << DigitalClock2("12:02:40am") << endl;
cout << DigitalClock2("01:00:00pm") << endl;
cout << DigitalClock2("12:00:01pm") << endl;
cout << DigitalClock2("11:59:59pm") << endl;
cout<<endl;
char time[11];
DigitalCLock1(0,time);
cout << time<<endl;
DigitalCLock1(59,time);
cout << time<<endl;
DigitalCLock1(160,time);
cout << time<<endl;
DigitalCLock1(3600,time);
cout << time<<endl;
DigitalCLock1(86399,time);
cout << time<<endl;
DigitalCLock1(43199,time);
cout << time<<endl;
DigitalCLock1(86401,time);
cout << time<<endl;
return 0;}

