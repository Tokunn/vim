#!/usr/bin/env python3
#coding: UTF-8


import cgitb; cgitb.enable()

import cgi
import os, sys
import subprocess


class GetQuery:

    def __init__(self, upload_path):
        self.form = cgi.FieldStorage()
        self.upload_path = upload_path

    def get_iname(self):
        return self.form.getvalue('imagename', '')

    def get_iformat(self):
        return self.form.getvalue('imageformat', '')

    def get_liformat(self):
        liformat = self.form.getvalue('imageformat', '').lower()
        if liformat == "jpeg":
            liformat = "jpg"
        return liformat

    def get_fitem(self):
        return self.form.getvalue('file', '')

    def get_fname(self):
        fitem = self.form['file']
        return fitem.filename

    def get_fpath(self):
        fitem = self.form['file']
        return os.path.join(self.upload_path, fitem.filename)


def upload(fpath, fileitem):
    savef = open(fpath, 'wb')
    savef.write(fileitem)
    savef.close()


def rendring(fpath, iname, iformat):
    trd_com = "blender -b {0} -o //../../{1} -F {2} -f 1".format(fpath, iname, iformat)
    rd_com = trd_com.split()
    p = subprocess.call(rd_com, stdout=subprocess.PIPE)


def html_render(html_path, argument1, argument2):
    html = open(html_path, "r")
    html_body = html.read()
    html.close()
    return html_body.format(argument1, argument2)


query = GetQuery("./cgi-bin/updata/")
result = ''


if query.get_fname().endswith(".blend"):
    upload(query.get_fpath(), query.get_fitem())
    rendring(query.get_fpath(), query.get_iname(), query.get_iformat())
    html_path = "./cgi-bin/views/printimg.html"
    result = html_render(html_path, query.get_iname(), query.get_liformat())

elif query.get_fname() == '':
    html_path = "./cgi-bin/views/printerror_none.html"
    result = html_render(html_path, '', '')

else:
    html_path = "./cgi-bin/views/printerror.html"
    result = html_render(html_path, query.get_fname(), '')


print ("Content-Type: text/html\n")
print (result)
