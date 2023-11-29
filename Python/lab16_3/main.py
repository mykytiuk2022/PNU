import requests
import csv
from bs4 import BeautifulSoup


def scrape_schools(url, csv_filename):
    response = requests.get(url)
    html = response.text
    soup = BeautifulSoup(html, 'html.parser')

    with open(csv_filename, 'w', newline='', encoding='utf-8') as csv_file:
        fieldnames = ['Назва', 'Телефон', 'E-mail', 'Прізвище директора', 'Кількість учнів']
        writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
        writer.writeheader()
        table = soup.find('table', {'class': 'zebra-stripe'})
        links = table.find_all('a')
        for link in links:
            school_url = 'https://if.isuo.org/' + link.get('href')
            print(school_url)
            school_response = requests.get(school_url)
            school_html = school_response.text
            school_soup = BeautifulSoup(school_html, 'html.parser')
            table = school_soup.find('table', {'class': 'zebra-stripe'})
            rows = table.find_all('tr')
            school_name = rows[3].find('td').text.strip()
            school_phone = rows[11].find('td').text.strip()
            school_email = rows[12].find('td').text.strip()
            school_director = rows[17].find('td').text.strip()
            school_students = rows[22].find('td').text.strip()
            writer.writerow({
                'Назва': school_name,
                'Телефон': school_phone,
                'E-mail': school_email,
                'Прізвище директора': school_director,
                'Кількість учнів': school_students
            })

scrape_schools("https://if.isuo.org/authorities/schools-list/id/626", "schools_info.csv")