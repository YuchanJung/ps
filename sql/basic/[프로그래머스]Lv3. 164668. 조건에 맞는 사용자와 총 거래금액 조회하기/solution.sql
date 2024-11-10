SELECT USER_ID, NICKNAME, SUM(PRICE) as TOTAL_SALES FROM USED_GOODS_BOARD b
JOIN USED_GOODS_USER u
on b.WRITER_ID = u.USER_ID
where b.STATUS = 'DONE'
GROUP BY USER_ID
HAVING SUM(PRICE) >= 700000
ORDER BY TOTAL_SALES