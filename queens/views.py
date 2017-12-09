from django.shortcuts import render, redirect, HttpResponse
from django.views.generic.base import RedirectView
from django.http import JsonResponse
from .models import ChessData
import os, subprocess, json
from time import time

def getRedirectUrl(request, matchedString):
    url = '/static/img/chesspieces/wikipedia/' + matchedString + '.png'
    return redirect(url, content_type = 'image/png')

def index(request):
    selected = 'home'
    return render(request, 'index.html', {'selected': selected})

def about(request):
    selected = 'about'
    return render(request, 'about.html', {'selected': selected})

def stats(request):
    selected = 'stats'
    return render(request, 'stats.html', {'selected': selected})

def solve(request, size, method):
    dir_path = os.path.dirname(os.path.realpath(__file__))
    staticPath = dir_path + '/static/'

    start = time()
    p = subprocess.Popen([staticPath + 'c++/solver', method, str(size)], stdout = subprocess.PIPE, stderr = subprocess.PIPE)
    real = time() - start
    #print(real)
    out, error = p.communicate()
    error = error.decode()[:-1]

    if(error != ''):
        print('Error while calling algorithm: ' + error)
        return HttpResponse('Error while calling algorithm', status = '500')

    out = out.decode()[:-1]
    solved = out[0]

    solution = out[1:]
    solution = solution.strip()
    solution = solution.split(' ')
    solution = list(map(int, solution))
    positionObject = {}

    k = 0
    positionLetters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
    for i in range(int(size)):
        for j in range(int(size)):
            if(solution[k] != 0):
                positionObject[positionLetters[j] + str(i + 1)] = 'bQ'
            k += 1
          
    positionObjectJson = json.dumps(positionObject)
    #print(positionObjectJson)

    if(solved != '1'):
        return HttpResponse(status = '400')

    newRow = ChessData()
    newRow.algorithm = method
    newRow.queens = size
    newRow.time = real*1000
    newRow.save()
    return HttpResponse(positionObjectJson, content_type = 'application/json')
