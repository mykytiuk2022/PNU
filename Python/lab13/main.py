from abc import ABC, abstractmethod


class Employee(ABC):
    def __init__(self, name, employee_id):
        self.name = name
        self.employee_id = employee_id

    @abstractmethod
    def get_salary(self):
        pass

    @abstractmethod
    def get_tax(self):
        pass


class HourlyPayEmployee(Employee):
    def __init__(self, name, employee_id, hours, rate):
        super().__init__(name, employee_id)
        self.hours = hours
        self.rate = rate

    def get_salary(self):
        return self.hours * self.rate

    def get_tax(self):
        salary = self.get_salary()
        pit = 0.18 * salary
        military_tax = 0.015 * salary
        return pit + military_tax


class FixedPayEmployee(Employee):
    def __init__(self, name, employee_id, salary):
        super().__init__(name, employee_id)
        self.salary = salary

    def get_salary(self):
        return self.salary

    def get_tax(self):
        salary = self.get_salary()
        pit = 0.18 * salary
        military_tax = 0.015 * salary
        return pit + military_tax


class HourlyIndividualPayEmployee(HourlyPayEmployee):
    def __init__(self, name, employee_id, hours, rate):
        super().__init__(name, employee_id, hours, rate)

    def get_salary(self):
        salary = self.hours * self.rate
        return salary + 0.1 * salary

    def get_tax(self):
        salary = self.get_salary()
        ep = 0.05 * salary  # Єдиний податок
        esv = 704  # Єдиний соціальний внесок (фіксована сума)
        return ep + esv


class SelfEmployedEmployee(Employee):
    def __init__(self, name, employee_id, code_lines, rate_per_line):
        super().__init__(name, employee_id)
        self.code_lines = code_lines
        self.rate_per_line = rate_per_line

    def get_salary(self):
        return self.code_lines * self.rate_per_line

    def get_tax(self):
        salary = self.get_salary()
        pit = 0.18 * salary
        military_tax = 0.015 * salary
        esv = 704
        return pit + military_tax + esv


employees = [
    HourlyPayEmployee("Brown", 1, 40, 10),
    FixedPayEmployee("Johnson", 2, 5000),
    HourlyIndividualPayEmployee("Miller", 3, 40, 10),
    SelfEmployedEmployee("Wilson", 4, 1000, 5),
]
employees.sort(key=lambda x: (-x.get_salary(), x.name.lower()))

for employee in employees:
    print(f"ID: {employee.employee_id}, Прізвище: {employee.name}, ЗП: {employee.get_salary()}"
          f", Податок: {employee.get_tax()}")
