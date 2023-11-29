class Contact:
    def __init__(self, name, surname, phone_number):
        self.name = name
        self.surname = surname
        self.phone_number = phone_number

    def __str__(self):
        return f"{self.name} {self.surname} {self.phone_number}"


class PhoneBook:
    def __init__(self, file_name):
        self.file_name = file_name
        self.contacts = self.load_from_file()

    def add_contact(self, name, surname, phone_number):
        new_contact = Contact(name, surname, phone_number)
        self.contacts.append(new_contact)

    def remove_contact(self, index):
        if 0 <= index < len(self.contacts):
            del self.contacts[index]

    def display_list(self):
        print("\nТелефонна книга:")
        for index, contact in enumerate(self.contacts):
            print(f"{index + 1}. {contact}")

    def find_by_name(self, name):
        for contact in self.contacts:
            if contact.name == name:
                return contact
        return None

    def find_by_surname(self, surname):
        for contact in self.contacts:
            if contact.surname == surname:
                return contact
        return None

    def find_by_phone(self, phone_number):
        for contact in self.contacts:
            if contact.phone_number == phone_number:
                return contact
        return None

    def save_to_file(self):
        with open(self.file_name, "w") as file:
            for contact in self.contacts:
                file.write(f"{contact}")

    def load_from_file(self):
        try:
            with open(self.file_name, 'r') as file:
                file_data = file.readlines()
            contacts = []
            for line in file_data:
                name, surname, phone_number = line.split()
                contacts.append(Contact(name, surname, phone_number))
            return contacts
        except FileNotFoundError:
            return []


def show_menu():
    print("\nМеню:")
    print("1. Додати контакт")
    print("2. Видалити контакт")
    print("3. Знайти контакт за ім'ям")
    print("4. Знайти контакт за прізвищем")
    print("5. Знайти контакт за номером телефону")
    print("6. Вивести список контактів")
    print("0. Вийти")


phone_book = PhoneBook("phone_book.txt")


def main():
    while True:
        show_menu()
        choice = input("Ваш вибір: ")
        if choice == "1":
            name = input("Ім'я: ")
            surname = input("Прізвище: ")
            phone_number = input("Номер телефону: ")
            phone_book.add_contact(name, surname, phone_number)
        elif choice == "2":
            index = int(input("Номер контакту: ")) - 1
            phone_book.remove_contact(index)
        elif choice == "3":
            name = input("Ім'я: ")
            contact = phone_book.find_by_name(name)
            if contact:
                print(contact)
            else:
                print("Контакт не знайдено")
        elif choice == "4":
            surname = input("Прізвище: ")
            contact = phone_book.find_by_surname(surname)
            if contact:
                print(contact)
            else:
                print("Контакт не знайдено")
        elif choice == "5":
            phone_number = input("Номер телефону: ")
            contact = phone_book.find_by_phone(phone_number)
            if contact:
                print(contact)
            else:
                print("Контакт не знайдено")
        elif choice == "6":
            phone_book.display_list()
        elif choice == "0":
            phone_book.save_to_file()
            break
        else:
            print("Неправильний вибір")


if __name__ == "__main__":
    main()
