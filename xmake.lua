set_project("json-parser")
set_languages("c")

if is_mode("debug") then
    set_symbols("debug")
    set_optimize("none")
end

if is_mode("release") then
    set_symbols("hidden")
    set_optimize("fastest")
    set_strip("all")
end

add_cflags("-g -Wall")
add_includedirs("./")

option("memcheck")
    set_default(false)
    set_showmenu(true)

target("json_parser")
    set_kind("static")
    add_files("*.c")

includes('example')
