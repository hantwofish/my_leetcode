步骤二：打开命令面板

在VSCode的顶部菜单栏中选择“查看”选项，然后选择“命令面板”，或者直接按下快捷键“Ctrl + Shift + P”，打开命令面板。

步骤三：输入命令

在命令面板中，输入“open user settings”，然后选择“首选项: 打开用户设置”。

    "terminal.integrated.profiles.windows": {
        "PowerShell": {
            "source": "PowerShell",
            "icon": "terminal-powershell"
        },
        "Command Prompt": {
            "path": [
                "${env:windir}\\Sysnative\\cmd.exe",
                "${env:windir}\\System32\\cmd.exe"
            ],
            "args": [],
            "icon": "terminal-cmd"
        },
        "Git Bash": {
            "source": "Git Bash",
            "path": " D:\\soft\\Git\\bin\\bash.exe",
            "args": []
        },
        "git": {  // 添加此项
            "path": "D:\\soft\\Git\\bin\\bash.exe",
            "args": []
        }
    },