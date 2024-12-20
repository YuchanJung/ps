SELECT ID, FISH_NAME, LENGTH FROM FISH_INFO i
JOIN FISH_NAME_INFO n
on i.FISH_TYPE = n.FISH_TYPE
WHERE (i.FISH_TYPE, i.LENGTH) IN (
    SELECT FISH_TYPE, MAX(LENGTH) FROM FISH_INFO
    GROUP BY FISH_TYPE
)
ORDER BY ID

-- WHERE 구문에서 LEGNTH로만 찾으면 틀림. TYPE, LEGNTH가 동시에 일치하는 것을 찾아야 함