# 基于Ubuntu22.04安装Hadoop

## 一、准备阶段

### 1. 安装 Java 工具包

Ubuntu默认软件仓库同时包含 Java 8 和 Java 11。由于Hive只能 Java 8 版本上运行，此处使用 Java 8 版本。
执行下述指令：

```cmd
sudo apt update && sudo apt install openjdk-8-jdk
```

