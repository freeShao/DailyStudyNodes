# 基于Ubuntu22.04安装Git

## 安装 Git

### 1. 更换镜像源

```cmd
sudo vim /etc/apt/sources.list
```

![更换镜像源](./image/GitSetting/更换镜像源1.png)

更换为清华大学的镜像源，按 `i` 切换到 `INSERT` 模式，将前面的内容注释掉后粘贴下述内容：

```cmd
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-updates main restricted universe multiverse
deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ jammy-backports main restricted universe multiverse
deb http://security.ubuntu.com/ubuntu/ jammy-security main restricted universe multiverse
```

![更换镜像源2](./image/GitSetting/更换镜像源2.png)

> 编辑完成后按 `esc` 退 `INSERT` 模式，输入 `:wq` 保存退出 `vim` 编辑器。

### 2. 更新软件包

```cmd
sudo apt update
```

![更新软件包1](./image/GitSetting/更新软件包1.png)
![更新软件包2](./image/GitSetting/更新软件包2.png)

### 3. 安装 Git

```cmd
sudo apt install git -y
```

![安装Git](./image/GitSetting/安装Git.png)

### 4. 配置 Git 用户名和邮箱

```cmd
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"
```

![配置用户名](./image/GitSetting/配置用户名.png)

### 5. 配置 SSH 密钥

```cmd
ssh-keygen -t rsa -C "your.email@example.com"
```

一路回车默认即可

![查看生成的SSH密钥](image/GitSetting/查看生成的SSH密钥.png)

查看生成的 SSH 公共密钥并复制：

```cmd
cat ~/.ssh/id_rsa.pub
```

![查看公钥](image/GitSetting/查看公钥.png)

### 6. Github 配置 SSH 密钥

依次进入：个人主页 → Settings → SSH and GPG keys → New SSH key

![Github配置SSH密钥](image/GitSettingGithub配置SSH密钥1.png)

![完成添加SSH密钥](image/GitSetting/Github配置SSH密钥2.png)

![测试SSH连接](image/GitSetting/Github配置SSH密钥3.png)
