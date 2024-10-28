package.path = package.path .. ";src/plugins/?.lua"

local function loadModulesFromDirectory(directory)
  LuaModules = {}
  for file in io.popen('ls "' .. directory .. '"'):lines() do
    if file:match("%.lua$") then
      local moduleName = file:gsub("%.lua$", "")
      local modulePath = directory .. "/" .. moduleName

      local success, module = pcall(require, modulePath:gsub("/", "."))

      module = require(modulePath:gsub("/", "."))

      if success then
        LuaModules[moduleName] = module
      else
        print("Error to load plugin: ", moduleName, module)
      end
    end
  end
  return LuaModules
end


function LoadPlugins()
  local directory = "src/plugins"
  loadModulesFromDirectory(directory)

  local pluginNames = {}

  for name in pairs(LuaModules) do
    table.insert(pluginNames, name)
  end

  return (pluginNames)
end

function RunPlugin(pluginName, ...)
  local plugin = LuaModules[pluginName]

  print("in memory plugin: ", plugin)
  if plugin then
    print("Running plugin: ", pluginName)
    plugin(...)
  else
    print("Plugin not found: ", pluginName)
  end
end
