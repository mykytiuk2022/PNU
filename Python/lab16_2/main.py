import requests
import csv
from bs4 import BeautifulSoup


def scrape_laptops(url, min_price, max_price, csv_filename):
    # Отримання html-коду сторінки
    response = requests.get(url)
    html = response.text

    soup = BeautifulSoup(html, 'html.parser')

    with open(csv_filename, 'w', newline='', encoding='utf-8') as csv_file:
        # Задаємо поля для CSV-файлу
        fieldnames = ['Назва', 'Ціна', 'Посилання', 'Посилання на фото']
        writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
        writer.writeheader()

        # Знаходимо блоки з інформацією про ноутбуки
        laptops = soup.find_all('div', {'class': 'product-block'})

        # Ітеруємося по блоках та записуємо інформацію у CSV-файл
        for laptop in laptops:
            # Отримуємо ціну ноутбука
            price = laptop.find('span', {'class': 'price'}).text
            price = price.replace('\xa0', ' ')
            integer_price = price.replace(' ', '').replace('грн.', '').replace('від', '')

            # Перевіряємо, чи ціна ноутбука вказана у заданому діапазоні
            if not min_price <= int(integer_price) <= max_price:
                continue

            name = laptop.find('a', {'class': 'model-name'}).text.strip()
            laptop_link = laptop.find('a', {'class': 'model-name'})['href']
            img_link = laptop.find('img')['src']

            writer.writerow({
                'Назва': name,
                'Ціна': price,
                'Посилання': laptop_link,
                'Посилання на фото': img_link
            })


def main():
    url = "http://price.ua/catc839t14.html"
    min_price = 20000  # Мінімальна ціна
    max_price = 40000  # Максимальна ціна
    csv_filename = "laptops_info.csv"

    # Викликаємо функцію для витягування інформації та збереження у CSV-файл
    scrape_laptops(url, min_price, max_price, csv_filename)
    print(f"Дані збережено у файлі: {csv_filename}")


if __name__ == '__main__':
    main()
