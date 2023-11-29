class TodoItem:
    def __init__(self, description, comment, deadline, priority, is_done=False):
        self.description = description
        self.comment = comment
        self.deadline = deadline
        self.priority = priority
        self.is_done = is_done

    def __str__(self):
        status = "[X]" if self.is_done else "[ ]"
        return f"{status} {self.description}, {self.comment}, {self.deadline}, {self.priority}"

    def mark_as_done(self):
        self.is_done = True

    def edit_item(self, description=None, comment=None, deadline=None, priority=None):
        if description is not None:
            self.description = description
        if comment is not None:
            self.comment = comment
        if deadline is not None:
            self.deadline = deadline
        if priority is not None:
            self.priority = priority


class TodoList:
    def __init__(self):
        self.items = []

    def add_item(self, description, comment, deadline, priority):
        new_item = TodoItem(description, comment, deadline, priority)
        self.items.append(new_item)

    def remove_item(self, index):
        if 0 <= index < len(self.items):
            del self.items[index]

    def mark_item_as_done(self, index):
        if 0 <= index < len(self.items):
            self.items[index].mark_as_done()

    def edit_item(self, index, description=None, comment=None, deadline=None, priority=None):
        if 0 <= index < len(self.items):
            self.items[index].edit_item(description, comment, deadline, priority)

    def display_list(self):
        print("\nСписок справ:")
        for index, item in enumerate(self.items):
            print(f"{index + 1}. {item}")


def show_menu():
    print("\nМеню:")
    print("1. Додати справу")
    print("2. Видалити справу")
    print("3. Відзначити справу як виконану")
    print("4. Редагувати справу")
    print("5. Вивести список справ")
    print("0. Вийти")


todo_list = TodoList()

while True:
    show_menu()
    choice = input("Ваш вибір: ")
    if choice == "1":
        description = input("Назва: ")
        comment = input("Коментар (натисніть Enter, щоб пропустити): ")
        deadline = input("Термін (натисніть Enter, щоб пропустити): ")
        priority = input("Пріоритет (натисніть Enter, щоб пропустити): ")
        todo_list.add_item(description, comment or None, deadline or None, int(priority) if priority else None)
    elif choice == "2":
        index = int(input("Номер справи: ")) - 1
        todo_list.remove_item(index)
    elif choice == "3":
        index = int(input("Номер справи: ")) - 1
        todo_list.mark_item_as_done(index)
    elif choice == "4":
        index = int(input("Номер справи: ")) - 1
        description = input("Назва (натисніть Enter, щоб залишити без змін): ")
        comment = input("Коментар (натисніть Enter, щоб залишити без змін): ")
        deadline = input("Термін (натисніть Enter, щоб залишити без змін): ")
        priority = input("Пріоритет (натисніть Enter, щоб залишити без змін): ")
        todo_list.edit_item(index, description or None, comment or None, deadline or None,
                            int(priority) if priority else None)
    elif choice == "5":
        todo_list.display_list()
    elif choice == "0":
        break
    else:
        print("Неправильний вибір")
