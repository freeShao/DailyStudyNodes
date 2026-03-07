# 基于Ubuntu22.04安装Hadoop集群

## 一、准备阶段

### 1. 安装 Java 工具包

Ubuntu默认软件仓库同时包含 `Java 8` 和 `Java 11`。由于 `Hive` 只能 `Java 8` 版本上运行，此处使用 `Java 8` 版本。
执行下述指令：

```cmd
sudo apt update && sudo apt install openjdk-8-jdk
```

![安装jdk8](./image/HadoopSetting/安装jdk8.png)
继续输入`yes`，继续执行安装流程。
![允许继续](./image/HadoopSetting/1772701552015.png)
![安装完成](./image/HadoopSetting/1772701637471.png)

### 2. 验证安装

```cmd
java -version
```

![1772701704885](./image/HadoopSetting/1772701704885.png)

### 3. 安装 SSH（如果已完成可以跳过）

安装 `SSH`（安全外壳协议）对 `Hadoop` 来说至关重要，它能够实现在 `Hadoop` 集群中节点之间的安全通信。确保数据的完整性和机密性，并支持在集群中高效地进行分布式数据处理。

```cmd
sudo apt install ssh
```

### 4. 创建 Hadoop 用户

本组件都将以创建的 `Hadoop` 用户身份运行，该用户将用于登录 `Hadoop` 的 Web 界面。
运行下述命令创建用户并设置密码。

```cmd
sudo adduser hadoop
```

补充注销用户指令。

```cmd
sudo userdel hadoop
```

对于 `Full Name` 等部分，回车保持默认即可。
![1772776985345](./image/HadoopSetting/1772776985345.png)

### 5. 切换用户

执行下述指令，输入之前设置的密码，切换到 `hadoop` 用户。

```cmd
su - hadoop
```

![1772777201231](./image/HadoopSetting/1772777201231.png)
> 登陆成功后的各项信息，此处不对该内容进行解释。

### 6. 配置 SSH

#### (1) 生成 SSH 密钥

为新用户 hadoop 配置免密码 SSH 访问，因此并没有输入输入密钥来保护文件和密码。
执行下述代码生成 SSH 密钥。

```cmd
ssh-keygen -t rsa
```

![1772783300787](./image/HadoopSetting/1772783300787.png)

#### (2) 设置密钥权限

将生成的公钥复制到授权密钥文件中，并设置权限。

```cmd
cat ~/.ssh/id_rsa.pub >> ~/.ssh/authorized_keys   
chmod 640 ~/.ssh/authorized_keys
```

#### (3) 通过 SSH 链接本地主机

```cmd
ssh localhost
```

![1772783572689](./image/HadoopSetting/1772783572689.png)
___

## 二、安装 Hadoop

### 1. 下载 hadoop 安装包

下载 Hadoop 3.3.6 安装包。

```cmd
wget https://dlcdn.apache.org/hadoop/common/hadoop-3.3.6/hadoop-3.3.6.tar.gz
```

![1772777362181](./image/HadoopSetting/1772777362181.png)
> 等待下载安装包。

### 2. 解压 hadoop 安装包

- 查看当前安装包路径情况（可选）

    ```cmd
    ll

    或

    ls
    ```

    ![1772777555555](./image/HadoopSetting/1772777555555.png)

- 解压缩到当前文件夹

    ```cmd
    tar -xvzf hadoop-3.3.6.tar.gz
    ```

    ![1772777913359](./image/HadoopSetting/1772777913359.png)

- 重命名解压后文件（可选）

    ```cmd
    mv hadoop-3.3.6 hadoop
    ```

### 3. 配置环境变量

#### (1) 系统环境变量

接下来，需要在系统上配置 Hadoop 和 Java 环境变量。可以使用熟悉的文本编辑器打开 ~/.bashrc 文件。
本文使用 `vim` 编辑器。

```cmd
vim ~/.bashrc
```

添加下述内容到最后一行中。

```cmd
# java
export JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64
# hadoop
export HADOOP_HOME=/home/hadoop/hadoop-3.3.6
export HADOOP_INSTALL=$HADOOP_HOME
export HADOOP_MAPRED_HOME=$HADOOP_HOME
export HADOOP_COMMON_HOME=$HADOOP_HOME
export HADOOP_HDFS_HOME=$HADOOP_HOME
export HADOOP_YARN_HOME=$HADOOP_HOME
export HADOOP_COMMON_LIB_NATIVE_DIR=$HADOOP_HOME/lib/native
export PATH=$PATH:$HADOOP_HOME/sbin:$HADOOP_HOME/bin
export HADOOP_OPTS="-Djava.library.path=$HADOOP_HOME/lib/native"
```

> export HADOOP_HOME=/home/hadoop/hadoop-3.3.6 如果此前更改了文件夹名，此处hadoop-3.3.6需改成重命名后的名字。

加载配置到当前环境。

```cmd
source ~/.bashrc
```

#### (2) hadoop 环境变量

在 hadoop-env.sh 文件中配置 JAVA_HOME。

```cmd
vim $HADOOP_HOME/etc/hadoop/hadoop-env.sh
```

![1772778797969](./image/HadoopSetting/1772778797969.png)
将该内容更改为：
`JAVA_HOME=/usr/lib/jvm/java-8-openjdk-amd64`。
![1772778840873](./image/HadoopSetting/1772778840873.png)

### 4. 配置 Hadoop

#### (1) node

首先，需要在 **Hadoop** 用户主目录下创建 `namenode` 和 `datanode` 目录。
运行以下命令创建这两个目录。

```cmd
cd hadoop/
```

> 由于已经处于主目录下，会出现 `-bash: cd: hadoop/: No such file or directory` 提示

```cmd
mkdir -p ~/hadoopdata/hdfs/{namenode,datanode}
```

创建后内容如下所示。
![1772780113593](./image/HadoopSetting/1772780113593.png)

#### (2) core-site.xml

编辑 `core-site.xml` 文件，将其更新成系统的主机名（可输入指令 `hostname` 进行查看）。

```cmd
vim $HADOOP_HOME/etc/hadoop/core-site.xml
```

将下述中的 `losthost` 更改为 `hostname` 的内容。

```cmd
<configuration>
    <property>
        <name>fs.defaultFS</name>
        <value>hdfs://localhost:9000</value>
    </property>
</configuration>
```

![1772780684349](./image/HadoopSetting/1772780684349.png)

#### (3) hdfs-site.xml

编辑 `hdfs-site.xml` 文件。

```cmd
vim $HADOOP_HOME/etc/hadoop/hdfs-site.xml
```

更改 `NameNode` 和 `DataNode` 目录路径。

```cmd
<configuration>
    <property>
        <name>dfs.replication</name>
        <value>1</value>
    </property>
    <property>
        <name>dfs.namenode.name.dir</name>
        <value>file:///home/hadoop/hadoopdata/hdfs/namenode</value>
    </property>
    <property>
        <name>dfs.datanode.data.dir</name>
        <value>file:///home/hadoop/hadoopdata/hdfs/datanode</value>
    </property>
 </configuration>
```

![1772780949060](./image/HadoopSetting/1772780949060.png)

#### (4) mapred-site.xml

编辑 `mapred-site.xml` 文件。

```cmd
vim $HADOOP_HOME/etc/hadoop/mapred-site.xml
```

此处需注意 `hadoop` 文件夹的名称对应。

```cmd
<configuration>
   <property>
      <name>yarn.app.mapreduce.am.env</name>
      <value>HADOOP_MAPRED_HOME=$HADOOP_HOME/home/hadoop/hadoop-3.3.6/bin/hadoop</value>
   </property>
   <property>
      <name>mapreduce.map.env</name>
      <value>HADOOP_MAPRED_HOME=$HADOOP_HOME/home/hadoop/hadoop-3.3.6/bin/hadoop</value>
   </property>
   <property>
      <name>mapreduce.reduce.env</name>
      <value>HADOOP_MAPRED_HOME=$HADOOP_HOME/home/hadoop/hadoop-3.3.6/bin/hadoop</value>
   </property>
</configuration>
```

![1772781233409](./image/HadoopSetting/1772781233409.png)

#### (5) yarn-site

编辑 `yarn-site.xml` 文件。

```cmd
vim $HADOOP_HOME/etc/hadoop/yarn-site.xml
```

添加下述内容。

```cmd
<configuration>
    <property>
        <name>yarn.nodemanager.aux-services</name>
        <value>mapreduce_shuffle</value>
    </property>
    <property>
        <name>yarn.nodemanager.aux-services.mapreduce_shuffle.port</name>
        <value>13563</value>
    </property>
</configuration>
```

![1772781407321](./image/HadoopSetting/1772781407321.png)

#### (6) 启动 Hadoop 集群

在启动 `Hadoop` 集群之前，需要将 `NameNode` 格式化为 `hadoop` 用户。

执行下述命令格式化 `Hadoop NameNode`。

```cmd
hdfs namenode -format
```

![1772781643526](./image/HadoopSetting/1772781643526.png)

使用 `hdfs` 文件系统成功格式化 `namenode` 目录之后，可以看到提示信息：*"Storage directory /home/hadoop/hadoopdata/hdfs/namenode has been successfully formatted."*
![1772781767995](./image/HadoopSetting/1772781767995.png)

使用下述命令启动 `Hadoop` 集群。

```cmd
start-all.sh
```

![1772792264916](./image/HadoopSetting/1772792264916.png)
> `stop-all.sh` 指令关闭集群。

使用下述命令查看启动状态。

```cmd
jps
```

![jps查询hadoop进程](./image/HadoopSetting/1772792439715.png)
___

**补充：可重看本文第一章第六节部分**
若出现如下图问题，可以尝试输入 `ssh localhost` 测试ssh链接情况。
![启动hadoop问题](./image/HadoopSetting/1772782475097.png)

仍然出现 `Connection refused`，需在拥有 `su` 权限的用户下执行下述命令。

```cmd
sudo apt update
sudo apt install openssh-server -y
sudo systemctl start ssh
sudo systemctl enable ssh
```

![重装SSH1](./image/HadoopSetting/1772782734667.png)
![重装SSH2](./image/HadoopSetting/1772782755222.png)

再次使用 `ssh localhost` 测试ssh链接情况。
![SSH链接](./image/HadoopSetting/1772782797131.png)

#### (7) 访问 NameNode 和 Resource Manager

首先需要查看本机的 `IP` 地址。在 Ubuntu 系统中，需要安装 `net-tools` 来运行 `ipconfig` 命令。

- **务必切换到默认用户执行安装指令**

    `sudo apt install net-tools`

    ![安装net-tools](./image/HadoopSetting/1772793317412.png)

- 然后执行 **`ifconfig`** 命令获取本机 `IP`。
    > 注意此处，是 `ifconfig`，而非 `ipconfig`。

    ![查看WSLip信息](./image/HadoopSetting/1772799604880.png)

    > 此处本机 `IP` 地址是 `26.214.130.121`。

- 要访问 `NameNode`，打开网络浏览器并访问 URL [http://server-ip:9870]

    [http://26.214.130.121:9870]
    ![NameNode界面](./image/HadoopSetting/1772799775967.png)

- 要访问 `Resource Manage`，打开网络浏览器并访问 URL [http://server-ip:8088]

    [http://26.214.130.121:8088]
    ![ResourceManage界面](./image/HadoopSetting/1772799973015.png)

  - 若无法访问，可尝试使用localhost进行替代，亦可通过下述方法解决。
  ![WSL网络配置](./image/HadoopSetting/1772799294602.png)

### 5. 验证 Hadoop 集群

在 `HDFS` 文件系统中创建一些目录来测试 `Hadoop`。

- 输入以下命令，在 `HDFS` 文件系统中创建目录记录：

    ```cmd
    hdfs dfs -mkdir /hadooptest
    hdfs dfs -mkdir /hadooplogs
    ```

- 列出上述所创建的目录：

    ```cmd
    hdfs dfs -ls /
    ```

    输出情况如下：
    ![创建目录](./image/HadoopSetting/1772800530729.png)

    亦可在 `NameNode` 中查看：
    ![NameNode目录](./image/HadoopSetting/1772800927077.png)

## 三、安装 Spark

### 1. 下载spark安装包

下载 Spark 3.5.8 安装包。

```cmd
wget https://dlcdn.apache.org/spark/spark-3.5.8/spark-3.5.8-bin-hadoop3.tgz

tar -xvzf spark-3.3.4-bin-hadoop3.tgz
```

![1772804611090](image/HadoopSetting/1772804611090.png)
> 等待下载安装包。

### 2. 解压 spark 安装包

- 查看当前安装包路径情况（可选）

    ```cmd
    ll

    或

    ls
    ```

    ![1772804854689](image/HadoopSetting/1772804854689.png)

- 解压缩到当前文件夹

    ```cmd
    tar -xvzf spark-3.5.8-bin-hadoop3.tgz
    ```

    ![1772805146661](image/HadoopSetting/1772805146661.png)

- 重命名解压后文件（可选）

    ```cmd
    mv spark-3.5.8-bin-hadoop3 spark-3.5.8
    ```

### 3. 配置spark环境变量

```cmd
vim ~/.bashrc
```

```cmd
export SPARK_HOME=/home/hadoop/spark-3.5.8
export PATH=$SPARK_HOME/bin:$PATH
# 使用类路径
export SPARK_DIST_CLASSPATH=$(hadoop classpath)
```

```cmd
source ~/.bashrc
```
