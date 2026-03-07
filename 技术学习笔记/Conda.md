# 基于 Ubuntu22.04 配置 MiniConda

## 一、安装 MiniConda

### 1. 下载 MiniConda 安装脚本

- 切换文件路径到 `tmp` 文件夹下

    ```cmd
    cd ~
    cd /tmp
    ```

- 使用 `wget` 命令从清华源下载 MiniConda 安装脚本。这里以最新版为例：

    ```cmd
    wget https://mirrors.tuna.tsinghua.edu.cn/anaconda/miniconda/Miniconda3-latest-Linux-x86_64.sh
    ```

    ![获取conda安装包](./image/Conda/获取conda安装包.png)

### 2. 执行安装脚本

- 给安装包添加执行权限

```cmd
chmod +x Miniconda3-latest-Linux-x86_64.sh
```

- 执行安装

```cmd
./Miniconda3-latest-Linux-x86_64.sh
```

![执行安装conda1](./image/Conda/执行安装conda1.png)

依次通过 > **回车** > **输入 `yes`** > **设置安装路径** > **输入 `yes`** . 不设置安装路径将会默认安装在 `/home/yourname/miniconda3` 的路径下，并且设置完成环境变量。

![执行安装conda2](./image/Conda/执行安装conda2.png)

### 3. 激活环境

- 添加完环境变量后需要对环境进行更新，使其生效

  ```cmd
  source ~/.bashrc
  ```

  ![更新环境变量](./image/Conda/更新环境变量.png)

  > 可以看到更新后有 `conda` 的 `base`标识。也可以输入 `conda --version` 查看当前 `conda` 版本。

___

## 二、添加Conda镜像源（可选）

> 注意：镜像源不能完全保证所有的库都有，因此官方源相对是最全面的。如果碰到某些库无法安装，请尝试使用默认源进行安装。

**查看已拥有的源：** `conda config --show channels`

**显示库安装自什么源：** `conda config --set show_channel_urls yes`

### 1. 清华源

```cmd
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/pytorch/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/cloud/conda-forge/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/free/
conda config --add channels https://mirrors.tuna.tsinghua.edu.cn/anaconda/pkgs/main/
```

### 2. 中科大源

```cmd
conda config --add channels https://mirrors.ustc.edu.cn/anaconda/pkgs/free/
conda config --add channels https://mirrors.ustc.edu.cn/anaconda/pkgs/main/
```

> pip 镜像源同理：`pip config set global.index-url https://pypi.tuna.tsinghua.edu.cn/simple`

![添加镜像源](./image/Conda/添加镜像源.png)
___

## 三、Conda 常用命令速查表

| 命令                                | 作用               | 示例                            |
| ----------------------------------- | ------------------ | ------------------------------- |
| `conda create -n myenv python=3.10` | 创建新环境         | 创建一个名为 myenv 的Python环境 |
| `conda activate myenv`              | 激活环境           | 使用 myenv 环境                 |
| `conda deactivate`                  | 退出当前环境       | 从任何环境切换回 base           |
| `conda env list`                    | 列出所有环境       | 查看当前系统中的 Conda 环境     |
| `conda install numpy`               | 安装包             | 安装 numpy 包                   |
| `conda remove numpy`                | 卸载包             | 卸载 numpy 包                   |
| `conda list`                        | 查看环境中已安装包 | 列出当前环境中的所有包          |