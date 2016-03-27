//用户自定义变量的使用
SELECT 
        @counter:=@counter+1 as counter,
        Scores.*
FROM    
        (SELECT @counter:=0) v,
        Scores;
//只抽取一个表的第三行
SELECT Scores.*
FROM (SELECT @counter:=0) v,Scores
HAVING (@counter :=@counter +1) %3 =0
ORDER BY Id;
