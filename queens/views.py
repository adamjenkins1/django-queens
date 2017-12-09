from django.shortcuts import render, redirect, HttpResponse
from django.views.generic.base import RedirectView
from django.http import JsonResponse
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
    solutionJson = json.dumps(solution)

    if(solved != '1'):
        return HttpResponse(solvedBoardJson, content_type = 'application/json', status = '400')

    '''
    newRow = SudokuData()
    newRow.algorithm = algorithm
    newRow.size = boardSize
    newRow.time = real*1000
    newRow.difficulty = difficulty
    newRow.save()
    '''
    return HttpResponse(solutionJson, content_type = 'application/json')
