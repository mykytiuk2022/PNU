import requests
import csv
from bs4 import BeautifulSoup


def scrape_ranking(url, csv_filename):
    # Отримання html-коду сторінки
    response = requests.get(url)
    html = response.text

    soup = BeautifulSoup(html, 'html.parser')

    with open(csv_filename, 'w', newline='', encoding='utf-8') as csv_file:
        fieldnames = ['ranking number', 'username', 'rank', 'enlightenment', 'solved']
        writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
        writer.writeheader()
        table = soup.find('table', {'class': 'table table-striped table-bordered full-width ranking-table'})
        rows = table.find_all('tr')
        for row in rows[:50]:
            columns = row.find_all('td')
            ranking_number = columns[0].text.strip()
            username = columns[2].text.strip()
            rank = columns[4].text.strip()
            enlightenment = columns[5].text.strip()
            solved = columns[6].text.strip()
            writer.writerow({
                'ranking number': ranking_number,
                'username': username,
                'rank': rank,
                'enlightenment': enlightenment,
                'solved': solved
            })


def main():
    url = "http://www.codeabbey.com/index/user_ranking"
    csv_filename = "user_rating.csv"
    scrape_ranking(url, csv_filename)
    print(f"Дані збережено у файлі: {csv_filename}")


if __name__ == '__main__':
    main()
