# 基于Ubuntu22.04安装Git和MiniConda

## 一、安装 Git

### 1. 更换镜像源

```bash
sudo vim /etc/apt/sources.list
```

![更换镜像源](image/GitAndConda/1753757446155.png)

更换为清华大学的镜像源，将前面的内容注释掉后输入：

```bash
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/   jammy main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/   jammy-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/   jammy-backports main restricted universe multiverse
deb http://security.ubuntu.com/ubuntu/   jammy-security main restricted universe multiverse
```

![更新软件包](image/GitAndConda/1753757175233.png)

### 2. 更新软件包

```bash
sudo apt update
```

![安装Git](image/GitAndConda/1753757956820.png)

### 3. 安装 Git

```bash
sudo apt install git -y
```

![配置Git用户名和邮箱](image/GitAndConda/1753758017118.png)

### 4. 配置 Git 用户名和邮箱

```bash
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"
```

![配置SSH密钥](image/GitAndConda/1753758136609.png)

### 5. 配置 SSH 密钥

```bash
ssh-keygen -t rsa -C "your.email@example.com"
```

一路回车默认即可

![查看生成的SSH密钥](image/GitAndConda/1753758978329.png)

查看生成的 SSH 公共密钥并复制：

```bash
cat ~/.ssh/id_rsa.pub
```

![1753759241065](image/GitAndConda/1753759241065.png)

以下为 Github 配置 SSH 密钥的过程：

依次进入：个人主页 → Settings → SSH and GPG keys → New SSH key

![Github配置SSH密钥](image/GitAndConda/1753759365245.png)

![完成添加SSH密钥](image/GitAndConda/1753759455200.png)

![测试SSH连接](image/GitAndConda/1753760002169.png)

![查看当前Python版本](image/GitAndConda/1753772425920.png)

![下载MiniConda安装脚本](image/GitAndConda/1753773101174.png)

![安装MiniConda](image/GitAndConda/1753773733706.png)

![添加环境变量](image/GitAndConda/1753774315324.png)

![验证Conda安装成功](image/GitAndConda/1753774612813.png)