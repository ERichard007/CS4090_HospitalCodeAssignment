#include <iostream>
#include <string>
#include <vector>

using namespace std;

class UserAccount
{

private:
	static int userCount;

	int userID;
	bool loggedIn = 0;

	string email;
	string password;

	void login(string emailc, string passwordc)
	{
		if (email == emailc && password == passwordc)
		{
			loggedIn = 1;
		}
	}

public:
	void passwordReset(string newPassword)
	{
		password = newPassword;
	}

	UserAccount(string emailc, string passwordc)
	{
		userCount++;

		email = emailc;
		userID = userCount;
		password = passwordc;

		login(emailc, passwordc);
	}

	void logout()
	{
		loggedIn = 0;
	}
};

class Staff : public UserAccount
{
private:
	static int staffCount;
	int staffID;

	string departmentType;

public:
	Staff(string departmentTypec, string emailc, string passwordc) : UserAccount(emailc, passwordc)
	{
		staffCount++;
		staffID = staffCount;
		departmentType = departmentTypec;
	}

	Staff(string emailc, int userIDc, string namec, string passwordc, int staffIDc, string departmentTypec) : UserAccount(emailc, passwordc)
	{
		staffCount++;
		staffID = staffIDc;
		departmentType = departmentTypec;
		(void)userIDc;
		(void)namec;
	}
};

class Patient;
class Physician;

class Appointment
{
public:
	string date;
	string time;
	string appointmentDesc;
	string status;

	Patient *patient;
	Physician *provider;

	Appointment(int appointmentIDc, string datec, string timec, string appointmentDescc, Patient *patientc, Physician *providerc)
	{
		appointmentID = appointmentIDc;
		date = datec;
		time = timec;
		appointmentDesc = appointmentDescc;
		patient = patientc;
		provider = providerc;
		status = "Scheduled";
	}

	void schedule()
	{
		status = "Scheduled";
	}

	void reschedule(string newDate, string newTime)
	{
		date = newDate;
		time = newTime;
	}

	void cancel()
	{
		status = "Cancelled";
	}

private:
	int appointmentID;
};

class Patient : public UserAccount
{
private:
	static int patientCount;
	int patientID;

public:
	string dateOfBirth;
	string emergencyContact;
	string insuranceProvider;
	vector<Appointment *> appointments;

	Patient(string emailc, string passwordc, string dateOfBirthc = "", string emergencyContactc = "", string insuranceProviderc = "") : UserAccount(emailc, passwordc)
	{
		patientCount++;
		patientID = patientCount;
		dateOfBirth = dateOfBirthc;
		emergencyContact = emergencyContactc;
		insuranceProvider = insuranceProviderc;
	}

	void viewSchedule()
	{
		for (int i = 0; i < appointments.size(); i++)
		{
			cout << appointments[i]->date << " ";
			cout << appointments[i]->time << " ";
			cout << appointments[i]->status << endl;
		}
	}

	void makeAppointment(Appointment *appointment)
	{
		appointments.push_back(appointment);
		appointment->schedule();
	}

	void edit_profile()
	{
	}

	void search_provider()
	{
	}

	void view_provider_info()
	{
	}

	void edit_appointment(Appointment *appointment, string newDate, string newTime)
	{
		appointment->reschedule(newDate, newTime);
	}
};

class FrontDeskStaff : public Staff
{
private:
	static int frontDeskStaffCount;
	int frontDeskStaffID;

	void checkInPatient()
	{
	}

	void verifyInformation()
	{
	}

	void viewSchedule()
	{
	}

	void updateAppointment()
	{
	}

public:
	FrontDeskStaff(string frontDeskStaffNamec, string emailc, string passwordc) : Staff("Front Desk", emailc, passwordc)
	{
		frontDeskStaffCount++;
		frontDeskStaffID = frontDeskStaffCount;
	}
};

class Nurse : public Staff
{
private:
	static int nurseCount;
	int nurseID;

	void viewSchedule()
	{
	}

public:
	Nurse(string nurseNamec, string emailc, string passwordc) : Staff("Nurse", emailc, passwordc)
	{
		nurseCount++;
		nurseID = nurseCount;
	}
};

class SchedulingStaff : public Staff
{
private:
	static int schedulingStaffCount;
	int schedulingStaffID;

	void createAppointment()
	{
	}

	void deleteAppointment()
	{
	}

	void manage_appointment()
	{
	}

public:
	SchedulingStaff(string schedulingStaffNamec, string emailc, string passwordc) : Staff("Scheduling", emailc, passwordc)
	{
		schedulingStaffCount++;
		schedulingStaffID = schedulingStaffCount;
	}
};

class BillingStaff : public Staff
{
public:
	BillingStaff(string emailc, int userIDc, string namec, string passwordc, int staffIDc, string departmentTypec, int billingIDc) : Staff(emailc, userIDc, namec, passwordc, staffIDc, departmentTypec)
	{
		billingID = billingIDc;
	}

	void send_payment()
	{
	}

	void review_visit_info()
	{
	}

private:
	int billingID;
};

class Physician : public Staff
{
public:
	bool individualOrCompany;
	string providerInfo;

	Physician(string emailc, int userIDc, string namec, string passwordc, int staffIDc, string departmentTypec, int physicianIDc, bool individualOrCompanyc, string providerInfoc) : Staff(emailc, userIDc, namec, passwordc, staffIDc, departmentTypec)
	{
		physicianID = physicianIDc;
		individualOrCompany = individualOrCompanyc;
		providerInfo = providerInfoc;
	}

	void view_Schedule()
	{
	}

	void view_Patient_Profile()
	{
	}

	void edit_appointment_info()
	{
	}

	void view_appointment_details()
	{
	}

private:
	int physicianID;
};

class SystemAdministrationStaff : public Staff
{
public:
	string adminPass;

	SystemAdministrationStaff(string emailc, int userIDc, string namec, string passwordc, int staffIDc, string departmentTypec, int administratorIDc, string adminPassc) : Staff(emailc, userIDc, namec, passwordc, staffIDc, departmentTypec)
	{
		administratorID = administratorIDc;
		adminPass = adminPassc;
	}

	void view_Patient_Profile()
	{
	}

	void view_operational_reports()
	{
	}

	void view_provider_info()
	{
	}

	void view_departments()
	{
	}

	void view_appointment()
	{
	}

private:
	int administratorID;
};

class Schedule
{
public:
	int scheduleID;
	string month;
	int day;
	vector<Appointment *> appointments;

	Schedule(int scheduleIDc, string monthc, int dayc)
	{
		scheduleID = scheduleIDc;
		month = monthc;
		day = dayc;
	}

	void addAppointment(Appointment *appointment)
	{
		appointments.push_back(appointment);
	}

	void viewAppointments()
	{
		for (int i = 0; i < appointments.size(); i++)
		{
			cout << appointments[i]->date << " ";
			cout << appointments[i]->time << " ";
			cout << appointments[i]->status << endl;
		}
	}
};

class HospitalSystem
{
public:
	vector<Patient> patients;
	vector<Physician> physicians;
	vector<FrontDeskStaff> frontDeskStaff;
	vector<Nurse> nurses;
	vector<SchedulingStaff> schedulingStaff;
	vector<BillingStaff> billingStaff;
	vector<SystemAdministrationStaff> adminStaff;
	vector<Appointment> appointments;

	void addPatient(const Patient &p) { patients.push_back(p); }
	void addPhysician(const Physician &doc) { physicians.push_back(doc); }
	void addFrontDeskStaff(const FrontDeskStaff &staff) { frontDeskStaff.push_back(staff); }
	void addNurse(const Nurse &staff) { nurses.push_back(staff); }
	void addSchedulingStaff(const SchedulingStaff &staff) { schedulingStaff.push_back(staff); }
	void addBillingStaff(const BillingStaff &staff) { billingStaff.push_back(staff); }
	void addAdminStaff(const SystemAdministrationStaff &staff) { adminStaff.push_back(staff); }

	void scheduleAppointment(int id, string date, string time, string desc, Patient *p, Physician *doc)
	{
		appointments.push_back(Appointment(id, date, time, desc, p, doc));
	}

	void initializeHospital()
	{
		Patient p1("Patient1@email.com", "pass123", "1985-08-12", "555-1111", "BlueCross");
		Patient p2("Patient2@email.com", "pass456", "1985-08-08", "444-2222", "Medicare");

		Physician doc1("Doc1@email.com", 1, "Dr. V", "pass1", 1, "Cardiology", 1, true, "Heart specialist");
		Physician doc2("Doc2@email.com", 2, "Dr. Moschops", "pass2", 2, "Family Medicine", 2, true, "General care");

		FrontDeskStaff desk("Front Desk", "frontdesk@email.com", "pass1");
		Nurse nurse("Nurse", "nurse@email.com", "pass2");
		SchedulingStaff scheduler("Scheduling", "sched@email.com", "pass3");
		BillingStaff billing("billing@email.com", 1, "Dana Reed", "pass4", 1, "Billing", 1);
		SystemAdministrationStaff admin("admin@email.com", 2, "Sam Brooks", "adminpass", 2, "Administration", 1, "admin123");

		patients.push_back(p1);
		patients.push_back(p2);
		physicians.push_back(doc1);
		physicians.push_back(doc2);
		frontDeskStaff.push_back(desk);
		nurses.push_back(nurse);
		schedulingStaff.push_back(scheduler);
		billingStaff.push_back(billing);
		adminStaff.push_back(admin);

		appointments.push_back(Appointment(1, "2026-11-12", "10:00", "Routine checkup", &patients[0], &physicians[0]));
		appointments.push_back(Appointment(2, "2026-11-12", "14:30", "Follow-up", &patients[1], &physicians[1]));
	}
};

int UserAccount::userCount = 0;
int Staff::staffCount = 0;
int Patient::patientCount = 0;
int FrontDeskStaff::frontDeskStaffCount = 0;
int Nurse::nurseCount = 0;
int SchedulingStaff::schedulingStaffCount = 0;

// MAIN.CPP ---------------------------------------------------------------------------------------------

int main()
{
	HospitalSystem hospital;
	hospital.initializeHospital();

	std::cout << "Welcome to the Hospital Management System!" << std::endl;

	std::string email, password;

	std::cout << "Please enter your email: ";
	std::cin >> email;

	std::cout << "Please enter your password: ";
	std::cin >> password;

	UserAccount user(email, password); // login = 1
	//
	return 0;
}
