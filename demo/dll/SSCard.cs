using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.Runtime.InteropServices;

namespace PT.BLL.DLL
{
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
}
