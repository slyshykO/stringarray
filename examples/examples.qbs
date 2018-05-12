import qbs

CppApplication{
    Group {
        fileTagsFilter: product.type
        qbs.install: true
    }
    consoleApplication : true
    cpp.minimumWindowsVersion:"6.1"
    cpp.enableExceptions:true
    cpp.enableRtti:true
    cpp.cxxLanguageVersion:"c++11"
    cpp.useCxxPrecompiledHeader:!(qbs.hostOS.contains("windows") && qbs.targetOS.contains("linux"))
    cpp.windowsApiCharacterSet:project.unicode ? "unicode" : "mbcs"

    cpp.includePaths:["../stringarray"]
    cpp.defines:{
        var defs = base
        if(project.unicode){
            defs.push("UNICODE")
            defs.push("_UNICODE")
        }
        if(qbs.buildVariant == "debug")
            defs.push("DEBUG")
        else
            defs.push("NDEBUG")

        return defs
    }


    files:[
        "src/main.cpp",
    ]
    Group{
        name:"stringarray"
        files:[
            "../stringarray/stringarray.cpp",
            "../stringarray/stringarray.hpp",
        ]
    }
}
