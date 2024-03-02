#!/bin/bash

# 删除当前目录下的所有.o文件，排除.gitignore和LICENSE文件
find . -type f -name "*.o" ! -name ".gitignore" ! -name "LICENSE" -exec rm {} +

# 删除当前目录下的所有没有扩展名的文件，排除.gitignore和LICENSE文件
# 注意：这可能会删除一些你想保留的文件，请根据需要调整或移除这一行
find . -type f -not -name "*.*" ! -name ".gitignore" ! -name "LICENSE" -exec rm {} +
