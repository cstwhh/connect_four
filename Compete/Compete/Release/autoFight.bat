del result.txt
for /l %%i in (100,-2,1) do Compete.exe C:\Users\Administrator\Desktop\work\人工智能导论\big\AI_project_2014\Connect4\Strategy\Release\Strategy.dll C:\Users\Administrator\Desktop\work\人工智能导论\big\AI_project_2014\TestCases\%%i.dll result.txt 3 %%i
pause