//      __________        ___               ______            _
//     / ____/ __ \____  / (_)___  ___     / ____/___  ____ _(_)___  ___
//    / /_  / / / / __ \/ / / __ \/ _ \   / __/ / __ \/ __ `/ / __ \/ _ \
//   / __/ / /_/ / / / / / / / / /  __/  / /___/ / / / /_/ / / / / /  __/
//  /_/    \____/_/ /_/_/_/_/ /_/\___/  /_____/_/ /_/\__, /_/_/ /_/\___/
//                                                  /____/
// FOnline Engine
// https://fonline.ru
// https://github.com/cvet/fonline
//
// MIT License
//
// Copyright (c) 2006 - present, Anton Tsvetinskiy aka cvet <cvet@tut.by>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#ifdef FO_SERVER_SCRIPTING
#include "ServerScripting.h"
#define SCRIPTING_CLASS ServerScriptSystem
#endif
#ifdef FO_CLIENT_SCRIPTING
#include "ClientScripting.h"
#define SCRIPTING_CLASS ClientScriptSystem
#endif
#ifdef FO_MAPPER_SCRIPTING
#include "MapperScripting.h"
#define SCRIPTING_CLASS MapperScriptSystem
#endif

#ifdef FO_MONO_SCRIPTING
#include "Log.h"
#include "Testing.h"

#include <mono/dis/meta.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>
#include <mono/metadata/mono-config.h>
#include <mono/mini/jit.h>

// static void SetMonoInternalCalls();
// static MonoAssembly* LoadNetAssembly(const string& name);
// static MonoAssembly* LoadGameAssembly(const string& name, map<string, MonoImage*>& assembly_images);
// static bool CompileGameAssemblies(const string& target, map<string, MonoImage*>& assembly_images);

struct ScriptSystem::MonoImpl
{
    map<string, MonoImage*> EngineAssemblyImages {};
};

void SCRIPTING_CLASS::InitMonoScripting()
{
    pMonoImpl = std::make_unique<MonoImpl>();

    /*g_set_print_handler([](const gchar* string) { WriteLog("{}", string); });
    g_set_printerr_handler([](const gchar* string) { WriteLog("{}", string); });

    mono_config_parse_memory(R"(
    <configuration>
        <dllmap dll="i:cygwin1.dll" target="libc.so.6" os="!windows" />
        <dllmap dll="libc" target="libc.so.6" os="!windows"/>
        <dllmap dll="intl" target="libc.so.6" os="!windows"/>
        <dllmap dll="intl" name="bind_textdomain_codeset" target="libc.so.6" os="solaris"/>
        <dllmap dll="libintl" name="bind_textdomain_codeset" target="libc.so.6" os="solaris"/>
        <dllmap dll="libintl" target="libc.so.6" os="!windows"/>
        <dllmap dll="i:libxslt.dll" target="libxslt.so" os="!windows"/>
        <dllmap dll="i:odbc32.dll" target="libodbc.so" os="!windows"/>
        <dllmap dll="i:odbc32.dll" target="libiodbc.dylib" os="osx"/>
        <dllmap dll="oci" target="libclntsh.so" os="!windows"/>
        <dllmap dll="db2cli" target="libdb2_36.so" os="!windows"/>
        <dllmap dll="MonoPosixHelper" target="$mono_libdir/libMonoPosixHelper.so" os="!windows" />
        <dllmap dll="System.Native" target="$mono_libdir/libmono-system-native.so" os="!windows" />
        <dllmap dll="libmono-btls-shared" target="$mono_libdir/libmono-btls-shared.so" os="!windows" />
        <dllmap dll="i:msvcrt" target="libc.so.6" os="!windows"/>
        <dllmap dll="i:msvcrt.dll" target="libc.so.6" os="!windows"/>
        <dllmap dll="sqlite" target="libsqlite.so.0" os="!windows"/>
        <dllmap dll="sqlite3" target="libsqlite3.so.0" os="!windows"/>
        <dllmap dll="libX11" target="libX11.so" os="!windows" />
        <dllmap dll="libgdk-x11-2.0" target="libgdk-x11-2.0.so.0" os="!windows"/>
        <dllmap dll="libgdk_pixbuf-2.0" target="libgdk_pixbuf-2.0.so.0" os="!windows"/>
        <dllmap dll="libgtk-x11-2.0" target="libgtk-x11-2.0.so.0" os="!windows"/>
        <dllmap dll="libglib-2.0" target="libglib-2.0.so.0" os="!windows"/>
        <dllmap dll="libgobject-2.0" target="libgobject-2.0.so.0" os="!windows"/>
        <dllmap dll="libgnomeui-2" target="libgnomeui-2.so.0" os="!windows"/>
        <dllmap dll="librsvg-2" target="librsvg-2.so.2" os="!windows"/>
        <dllmap dll="libXinerama" target="libXinerama.so.1" os="!windows" />
        <dllmap dll="libasound" target="libasound.so.2" os="!windows" />
        <dllmap dll="libcairo-2.dll" target="libcairo.so.2" os="!windows"/>
        <dllmap dll="libcairo-2.dll" target="libcairo.2.dylib" os="osx"/>
        <dllmap dll="libcups" target="libcups.so.2" os="!windows"/>
        <dllmap dll="libcups" target="libcups.dylib" os="osx"/>
        <dllmap dll="i:kernel32.dll">
            <dllentry dll="__Internal" name="CopyMemory" target="mono_win32_compat_CopyMemory"/>
            <dllentry dll="__Internal" name="FillMemory" target="mono_win32_compat_FillMemory"/>
            <dllentry dll="__Internal" name="MoveMemory" target="mono_win32_compat_MoveMemory"/>
            <dllentry dll="__Internal" name="ZeroMemory" target="mono_win32_compat_ZeroMemory"/>
        </dllmap>
        <dllmap dll="gdiplus" target="libgdiplus.so" os="!windows"/>
        <dllmap dll="gdiplus.dll" target="libgdiplus.so"  os="!windows"/>
        <dllmap dll="gdi32" target="libgdiplus.so" os="!windows"/>
        <dllmap dll="gdi32.dll" target="libgdiplus.so" os="!windows"/>
    </configuration>)");

    mono_set_dirs("./dummy/lib", "./dummy/etc");
    mono_set_assemblies_path("./dummy/lib/gac");

    RUNTIME_ASSERT(pMonoImpl->EngineAssemblyImages.empty());
    mono_install_assembly_preload_hook(
        [](MonoAssemblyName* aname, char** assemblies_path, void* user_data) -> MonoAssembly* {
            auto assembly_images = (map<string, MonoImage*>*)user_data;
            if (assembly_images->count(aname->name))
                return LoadGameAssembly(aname->name, *assembly_images);
            return LoadNetAssembly(aname->name);
        },
        (void*)&EngineAssemblyImages);

    MonoDomain* domain = mono_jit_init_version("FOnlineDomain", "v4.0.30319");
    RUNTIME_ASSERT(domain);

    SetMonoInternalCalls();

    if (assemblies_data)
    {
        for (auto& kv : *assemblies_data)
        {
            MonoImageOpenStatus status = MONO_IMAGE_OK;
            MonoImage* image = mono_image_open_from_data((char*)&kv.second[0], (uint)kv.second.size(), TRUE, &status);
            RUNTIME_ASSERT((status == MONO_IMAGE_OK && image));

            EngineAssemblyImages[kv.first] = image;
        }
    }
    else
    {
        bool ok = CompileGameAssemblies(target, EngineAssemblyImages);
        RUNTIME_ASSERT(ok);
    }

    for (auto& kv : EngineAssemblyImages)
    {
        bool ok = LoadGameAssembly(kv.first, EngineAssemblyImages);
        RUNTIME_ASSERT(ok);
    }

    MonoClass* global_events_class =
        mono_class_from_name(EngineAssemblyImages["FOnline.Core.dll"], "FOnlineEngine", "GlobalEvents");
    RUNTIME_ASSERT(global_events_class);
    MonoMethodDesc* init_method_desc = mono_method_desc_new(":Initialize()", FALSE);
    RUNTIME_ASSERT(init_method_desc);
    MonoMethod* init_method = mono_method_desc_search_in_class(init_method_desc, global_events_class);
    RUNTIME_ASSERT(init_method);
    mono_method_desc_free(init_method_desc);

    MonoObject* exc;
    MonoObject* init_method_result = mono_runtime_invoke(init_method, NULL, NULL, &exc);
    if (exc)
        mono_print_unhandled_exception(exc);

    RUNTIME_ASSERT(exc || *(bool*)mono_object_unbox(init_method_result) == false)
    return false;*/
}

/*static MonoAssembly* LoadNetAssembly(const string& name)
{
    string assemblies_path = "Assemblies/" + name + (_str(name).endsWith(".dll") ? "" : ".dll");
#ifdef FONLINE_SERVER
    assemblies_path = "Resources/Mono/" + assemblies_path;
#endif

    File file;
    file.LoadFile(assemblies_path);
    RUNTIME_ASSERT(file.IsLoaded());

    MonoImageOpenStatus status = MONO_IMAGE_OK;
    MonoImage* image = mono_image_open_from_data((char*)file.GetBuf(), file.GetFsize(), TRUE, &status);
    RUNTIME_ASSERT((status == MONO_IMAGE_OK && image));

    MonoAssembly* assembly = mono_assembly_load_from(image, name.c_str(), &status);
    RUNTIME_ASSERT((status == MONO_IMAGE_OK && assembly));

    return assembly;
}

static MonoAssembly* LoadGameAssembly(const string& name, map<string, MonoImage*>& assembly_images)
{
    RUNTIME_ASSERT(assembly_images.count(name));
    MonoImage* image = assembly_images[name];

    MonoImageOpenStatus status = MONO_IMAGE_OK;
    MonoAssembly* assembly = mono_assembly_load_from(image, name.c_str(), &status);
    RUNTIME_ASSERT((status == MONO_IMAGE_OK && assembly));

    return assembly;
}

static bool CompileGameAssemblies(const string& target, map<string, MonoImage*>& assembly_images)
{
    string mono_path = MainConfig->GetStr("", "MonoPath");
    string xbuild_path = _str(mono_path + "/bin/xbuild.bat").resolvePath();

    FileCollection proj_files("csproj");
    while (proj_files.IsNextFile())
    {
        string name, path;
        File& file = proj_files.GetNextFile(&name, &path);
        RUNTIME_ASSERT(file.IsLoaded());

        // Compile
        string command =
            _str("{} /property:Configuration={} /nologo /verbosity:quiet \"{}\"", xbuild_path, target, path);
        string output;
        int call_result = SystemCall(command, output);
        if (call_result)
        {
            StrVec errors = _str(output).split('\n');
            WriteLog("Compilation failed! Error{}:", errors.size() > 1 ? "s" : "");
            for (string& error : errors)
                WriteLog("{}\n", error);
            return false;
        }

        // Get output path
        string file_content = (char*)file.GetBuf();
        size_t pos = file_content.find("'$(Configuration)|$(Platform)' == '" + target + "|");
        RUNTIME_ASSERT(pos != string::npos);
        pos = file_content.find("<OutputPath>", pos);
        RUNTIME_ASSERT(pos != string::npos);
        size_t epos = file_content.find("</OutputPath>", pos);
        RUNTIME_ASSERT(epos != string::npos);
        pos += _str("<OutputPath>").length();

        string assembly_name = name + ".dll";
        string assembly_path =
            _str("{}/{}/{}", _str(path).extractDir(), file_content.substr(pos, epos - pos), assembly_name)
                .resolvePath();

        File assembly_file;
        assembly_file.LoadFile(assembly_path);
        RUNTIME_ASSERT(assembly_file.IsLoaded());

        MonoImageOpenStatus status = MONO_IMAGE_OK;
        MonoImage* image =
            mono_image_open_from_data((char*)assembly_file.GetBuf(), assembly_file.GetFsize(), TRUE, &status);
        RUNTIME_ASSERT((status == MONO_IMAGE_OK && image));

        assembly_images[assembly_name] = image;
    }

    return true;
}*/

#else
struct ScriptSystem::MonoImpl
{
};
void SCRIPTING_CLASS::InitMonoScripting()
{
}
#endif
