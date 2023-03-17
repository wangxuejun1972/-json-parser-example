function all_tests()
    local res = {}
    for _, x in ipairs(os.files("**.c")) do
        local item = {}
        local s = path.filename(x)
        table.insert(item, s:sub(1, #s - 2)) -- target
        table.insert(item, path.relative(x, ".")) -- source
        table.insert(res, item)
    end
    return res
end

add_deps("json_parser")


for _, test in ipairs(all_tests()) do
    target(test[1])
    set_kind("binary")
    add_files(test[2])
    if get_config("memcheck") == true then
        on_run(function (target)
            local argv = {}
            table.insert(argv, target:targetfile())
            table.insert(argv, "--leak-check=full")
            os.execv("valgrind", argv)
        end)
    end
end
