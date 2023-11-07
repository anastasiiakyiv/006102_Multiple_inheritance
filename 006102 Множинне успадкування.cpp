#include <iostream>
#include <string>
#include <vector>

class PersonalData
{
protected:
	std::string firstName, lastName, dateOfBirth, phoneNumber;
public:
	PersonalData(const std::string firstName, const std::string lastName, 
		const std::string dateOfBirth, const std::string phoneNumber) :
		firstName(firstName), lastName(lastName), dateOfBirth(dateOfBirth), phoneNumber(phoneNumber) {}
};

class ProfessionalActivity
{
protected:
	std::string lastJob, startDate;
	double hourlyRate;
public:
	ProfessionalActivity(const std::string lastJob, const std::string startDate, double hourlyRate) :
		lastJob(lastJob), startDate(startDate), hourlyRate(hourlyRate) {}
};

class SpecificProfession : public PersonalData, public ProfessionalActivity
{
protected:
	std::string professionName;
	std::vector<std::string> skills;
public:
	SpecificProfession(const std::string firstName, const std::string lastName,
		const std::string dateOfBirth, const std::string phoneNumber,
		const std::string lastJob, const std::string startDate, double hourlyRate,
		const std::string professionName, const std::vector<std::string>& skills) :
		PersonalData(firstName, lastName, dateOfBirth, phoneNumber), 
		ProfessionalActivity(lastJob, startDate, hourlyRate),
		professionName(professionName), skills(skills) {}

	void PrintInfo() {
		std::cout << "First and last name: " << firstName << " " << lastName << std::endl;
		std::cout << "Date of birth: " << dateOfBirth << std::endl;
		std::cout << "Phone Number: " << phoneNumber << std::endl;
		std::cout << "Last job: " << lastJob << std::endl;
		std::cout << "Start Date: " << startDate << std::endl;
		std::cout << "Hourly rate: " << hourlyRate << std::endl;
		std::cout << "Profession Name: " << professionName << std::endl;
		std::cout << "Professional skills: " << std::endl;
		for (const std::string& skill : skills) {
			std::cout << skill << std::endl;
		}
		std::cout << std::endl;
	}
};

int main()
{
	SpecificProfession driver("Olena", "Milevska", "08.03.1991", "+380677942264", "Uklon", "07.11.2023", 188.75, "Driver", { "Category B driver" });
	SpecificProfession programmer("Mykola", "Sushko", "12.11.1989", "+380636781345", "SEA", "07.11.2023", 431.25, "Software engineer", { "C++", "C#" });
	SpecificProfession teacher("Serhii", "Mykolaenko", "05.06.1988", "+380963414198", "Englishdom", "07.11.2023", 207.5, "Foreign language teacher", { "English", "German" });

	driver.PrintInfo();
	std::cout << std::endl;
	programmer.PrintInfo();
	std::cout << std::endl;
	teacher.PrintInfo();

	return 0;
}
