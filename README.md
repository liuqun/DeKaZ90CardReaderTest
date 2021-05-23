# 转载声明：本文及附件代码转载自博客园用户yisheng163的博客文章，仅供学习参考之用，转载时请保留原作者的信息及免责声明
- 原文标题：德卡Z90读卡器读取社保卡，德卡Z90读卡器CSharp示例程序源码:
- 原文链接：https://www.cnblogs.com/yisheng163/p/9000910.html


# 前言
最近学习调用 医保卡业务,使用德卡读卡器，主要就是调用一个DLL，动态库文件.

借着自学的机会把心得体会都记录下来，方便感兴趣的小伙伴学习与讨论。

内容均系原创，欢迎大家转载分享，但转载的同时别忘了注明作者和原文链接哦。本文内容和图片如果有侵犯您的权利，请联系yisheng163@qq.com。

# 一、准备工作：

先到德卡官网下载相关资料，下载动态库。
[`http://www.decard.com/download/downloadcategoryid=10&isMode=false.html`][1]
下载 SSCardDriver.dll 动态库。
> 2021-5-23备注：德卡官网的dll动态库下载地址已经失效，请下载备用地址中的[exe和dll文件][1]

读卡器准备：找到一台德卡Z9读卡器用来测试，Z9与Z90基本通用，不影响测试。

先拆开底座，把授权蕊片装入卡槽二。

USB插头，插入电脑USB口，任意插USB，不需要记住USB端口号，下一步读卡也不需要设置USB端口号。

 ![image](https://upload-images.jianshu.io/upload_images/1458798-67b53069ec95c993.jpg?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

# 二、C#读卡类
```
/// <summary>
    /// 德卡读卡器专用类
    /// mail:yisheng163@qq.com
    /// </summary>
    public class SSCard
    {
        /// <summary>
        /// 德卡读卡器专用读卡方法，需要将SSCardDriver.dll放在程序同一目录下
        /// </summary>
        /// <param name="iType">卡的类型，定义如下：1-接触式操作卡；2-非接触式操作卡；3-自动寻卡，接触式操作卡优先；4-自动寻卡，非接触式操作卡优先。</param>
        /// <param name="outInfo">该输出参数为读出的社保卡基本信息各数据项，依次为：发卡地区行政区划代码（卡识别码前6位）、社会保障号码、卡号、卡识别码、姓名、卡复位信息（仅取历史字节）、规范版本、发卡日期、卡有效期、终端机编号、终端设备号。各数据项之间以“|”分割，且最后一个数据项以“|”结尾。</param>
        /// <returns></returns>
        [DllImport("SSCardDriver.dll", EntryPoint = "iReadCardBas")]
        public static extern int iReadCardBas(int iType, StringBuilder outInfo);

        /// <summary>
        /// 读取社会保障号和姓名
        /// </summary>
        /// <returns></returns>
        public static string GetIDCode(ref bool CodeState, ref string ErrDesc, ref string IName, ref string ICard)
        {
            string ReStr="";

            StringBuilder myStrB=new StringBuilder(256);
            iReadCardBas(1, myStrB);
            if (myStrB != null && myStrB.ToString() != "" && myStrB.ToString().IndexOf("|") >= 0)
            {
                //读取成功
                string[] myStringList = myStrB.ToString().Split('|');
                if (myStringList != null && myStringList.Length > 0)
                {
                    ICard = myStringList[1];
                    IName = myStringList[4];
                    CodeState = true;
                    ErrDesc = "";
                }
                else
                {
                    CodeState = false;
                    ErrDesc = myStrB.ToString();
                    return "";
                }
            }
            else
            {
                    CodeState = false;
                    ErrDesc = myStrB.ToString();
                    return "";
            }

            return ReStr;
        }

    }
```

# 三、调用测试。
```
StringBuilder myStrB = new StringBuilder(2048);
            PT.BLL.DLL.SSCard.iReadCardBas(1, myStrB);
            if (myStrB != null && myStrB.ToString() != "" && myStrB.ToString().IndexOf("|") >= 0)
            {
                textBox1.Text = "\r\n" + myStrB.ToString();
            }
```

![示意图](https://upload-images.jianshu.io/upload_images/1458798-61bb0c0c40654de5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
读卡成功(示意图)。

# 四、示例源码：

- [德卡Z90读卡器CSharp示例程序exe+dll文件.rar][1]
- [德卡Z90读卡器CSharp示例程序源码.rar][2]

[1]: https://files.cnblogs.com/files/yisheng163/%E5%BE%B7%E5%8D%A1Z90%E8%AF%BB%E5%8D%A1%E5%99%A8CSharp%E7%A4%BA%E4%BE%8B%E7%A8%8B%E5%BA%8F.rar
[2]: https://files.cnblogs.com/files/yisheng163/%E5%BE%B7%E5%8D%A1Z90%E8%AF%BB%E5%8D%A1%E5%99%A8CSharp%E7%A4%BA%E4%BE%8B%E7%A8%8B%E5%BA%8F%E6%BA%90%E7%A0%81.rar
