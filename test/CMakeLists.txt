
# 指定生成目标
add_executable(TestSolarCore test.c)

TARGET_LINK_LIBRARIES(TestSolarCore 
    solarcore
    sqlite3
)