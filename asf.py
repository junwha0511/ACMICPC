import requests
from bs4 import BeautifulSoup
from collections import OrderedDict
from itertools import count
import time
import random
import pandas as pd
import numpy as np
from selenium import webdriver



def free_board_crawl():
   url = 'https://www.gamemeca.com/smart.php'
   post_dict = OrderedDict()


   for page in count(1):
      params = {
         'gcode': 'mobile_free',
         'rts': "board",
         'bt': "title",
         #"bq": keyword,
         "p": page
      }
      print(params)
      sess = requests.session()
      '''
      headers ={
         'user-agent' : 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.106 Safari/537.36'
      }
      이거 활용하기!?
      '''
      sess.headers['user-agent'] = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.106 Safari/537.36'

      res = sess.get(url, params=params,headers=sess.headers)
      #print(res,'gunny')

      if res.status_code != 200:
         break


      html = res.text
      #print(html)

      soup = BeautifulSoup(html, 'html.parser')
      soup

      contents = soup.find('table').find_all('tr')
      #for i in contents:
         #print('-'*20)

      t_list = []
      title_list = soup.select('tr > .row-title')
      post_dict = {}
      if not title_list:
         break
      for tag in title_list:
         if 'https://www.gamemeca.com/smart.php'+tag('a')[0]['href'] in post_dict:
            return post_dict
         #print(tag.text,'https://www.gamemeca.com/smart.php'+tag('a')[0]['href'])
         #post_dict['https://www.gamemeca.com/smart.php'+tag('a')[0]['href']]=tag.text
         #print(tag.text)
         t_list.append(tag.text)
      for i in range(len(t_list)):
         t_list[i]=t_list[i].replace('\n','')
      print(t_list)

      a_list = []
      auth_list = soup.select('tr > .row-auth')
      if not auth_list:
         break
      for tag in auth_list:
         #print(tag.text)
         a_list.append(tag.text)
      print(a_list)

      v_list = []
      view_list = soup.select('tr >.row-hit')
      if not view_list:
         break
      for tag in view_list:
         #print(tag.text)
         v_list.append(tag.text)
      print(v_list)

      d_list=[]
      date_list = soup.select('tr >.row-date')
      if not date_list:
         break
      for tag in date_list:
         #print(tag.text)
         d_list.append(tag.text)
      print(d_list)

      r_list = []
      recommend_list = soup.select('tr >.row-recom')
      if not recommend_list:
         break
      for tag in recommend_list:
         #print(tag.text)
         r_list.append(tag.text)

      c_list = []
      comment_num_list = soup.select('.c-red')
      for tag in comment_num_list:
         if tag is None:
            #print('0')
            c_list.append('0')
         else:
            #print(tag)
            c_list.append(tag.text)
      print(c_list)

      #print(len(t_list),len(a_list),len(v_list),len(d_list),len(r_list),len(c_list),'gunnnnnnnnnnny')

      df_t = pd.DataFrame(t_list)
      df_a = pd.DataFrame(a_list)
      df_v = pd.DataFrame(v_list)
      df_d = pd.DataFrame(d_list)
      df_r = pd.DataFrame(r_list)
      df_c = pd.DataFrame(c_list)
      df = pd.concat([df_t, df_a, df_v, df_d, df_r, df_c], axis=1)
      df.columns = ['title','author','views','date','recommendation','comment number']
      print(df)
   return post_dict

#def entering_link():


if __name__ == "__main__":
   free_board_crawl()





