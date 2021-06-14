#!/usr/bin/python3
"""count"""

import requests
import sys


def count_words(subreddit, word_list, kw_cont={}, next_pg=None, reap_kw={}):
    """count_words

    Args:
        subreddit (string): filter
        word_list (list): list fo the word
        kw_cont (dict, optional): [description]. Defaults to {}.
        next_pg ([type], optional): [description]. Defaults to None.
        reap_kw (dict, optional): [description]. Defaults to {}.
    """
    url = "https://reddit.com/r/"
    headers = {"User-Agent": "nildiert"}
    hotafter = '/hot.json?after='
    hot = '/hot.json'

    try:
        if next_pg:
            subr = requests.get(
                url + subreddit + hotafter + next_pg,
                headers=headers)
        else:
            subr = requests.get(url + subreddit + hot, headers=headers)

        if subr.status_code == 404:
            return

        if kw_cont == {}:
            for word in word_list:
                kw_cont[word.lower()] = 0
                reap_kw[word.lower()] = word_list.count(word)

        subr_dict = subr.json()
        subr_data = subr_dict['data']
        next_pg = subr_data['after']
        subr_posts = subr_data['children']

        for post in subr_posts:
            post_data = post['data']
            post_title = post_data['title']
            title_words = post_title.split()
            for w in title_words:
                for key in kw_cont:
                    if w.lower() == key.lower():
                        kw_cont[key] += 1

        if next_pg:
            count_words(subreddit, word_list, kw_cont, next_pg, reap_kw)

        else:
            for key, val in reap_kw.items():
                if val > 1:
                    kw_cont[key] *= val

            sorted_abc = sorted(kw_cont.items(), key=lambda x: x[0])
            sorted_res = sorted(sorted_abc, key=lambda x: (-x[1], x[0]))
            for res in sorted_res:
                if res[1] > 0:
                    print('{}: {}'.format(res[0], res[1]))

    except ValueError:
        print(ValueError)
