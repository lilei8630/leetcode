//用户自定义变量的使用
SELECT 
        @counter:=@counter+1 as counter,
        Scores.*
FROM    
        (SELECT @counter:=0) v,
        Scores;
