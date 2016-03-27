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
HAVING (@counter :=@counter +1) =3
ORDER BY Id;
//计算累加和
SELECT t.Id,
       t.Score,
       @x := @x+t.Score as Total
FROM
       (SELECT @x := 0) a,
       Scores t;
