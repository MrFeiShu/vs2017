using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace XIBDLLTest
{
    class Program
    {
        static void Main(string[] args)
        {
            bool bIs64App = true;
            UInt32 u4Result = 1;

            IntPtr ptrSN = Marshal.AllocHGlobal(32 * 0x10 + 1);
            do
            {

                UInt32 u4SnSize = 32 * 0x10 + 1;
                if (bIs64App)
                {
                    u4Result = EsCtrlDll_X64.GetUsbKeSn(ptrSN, ref u4SnSize);
                }
                else
                {
                    u4Result = EsCtrlDll.GetUsbKeSn(ptrSN, ref u4SnSize);
                }
                if (u4Result == 0)
                {
                    if (u4SnSize > 1)
                    {
                        Console.WriteLine("SN: {0}", Marshal.PtrToStringAnsi(ptrSN));
                    }
                    else
                    {
                        Console.WriteLine("No Key");
                        break;
                    }
                }
                else
                {
                    break;
                }

                UInt32 u4KeyNum = 0;
                if (bIs64App)
                {
                    u4Result = EsCtrlDll_X64.ListUsbkeyNumber(ref u4KeyNum);
                }
                else
                {
                    u4Result = EsCtrlDll.ListUsbkeyNumber(ref u4KeyNum);
                }
                if (u4Result == 0)
                {
                    if (u4KeyNum > 0)
                    {
                        Console.WriteLine("KeyNum = {0}", u4KeyNum);
                    }
                    else
                    {
                        Console.WriteLine("No Key");
                        break;
                    }
                }
                else
                {
                    break;
                }

                string strCN = Console.ReadLine();
                byte[] bCN = System.Text.Encoding.Default.GetBytes(strCN);
                if (bIs64App)
                {
                    u4Result = EsCtrlDll_X64.IsHaveSpecCert(ref bCN[0]);
                }
                else
                {
                    u4Result = EsCtrlDll.IsHaveSpecCert(ref bCN[0]);
                }
                if (0 == u4Result)
                {
                    Console.WriteLine("Specified Cert Existed");
                }
                else if (0xE0620005 == u4Result)
                {
                    Console.WriteLine("Specified Cert Not Existed");
                }
                else
                {
                    Console.WriteLine("operation failed, Error=0x{0:x}", u4Result);
                    break;
                }

                string strSN = "XIB882A100001572";
                byte[] u1SN = System.Text.Encoding.Default.GetBytes(strSN);
                if (bIs64App)
                {
                    u4Result = EsCtrlDll_X64.InitUsbKey(ref u1SN[0]);
                }
                else
                {
                    u4Result = EsCtrlDll.InitUsbKey(ref u1SN[0]);
                }
                if (u4Result == 0)
                {
                    Console.WriteLine("InitUsbKey Success");
                }
                else
                {
                    Console.WriteLine("InitUsbKey Failed, Error=0x{0:x}", u4Result);
                    break;
                }

            } while (false);

            Marshal.FreeHGlobal(ptrSN);
        }
    }

    public class EsCtrlDll
    {
        [DllImport("XIBCtrlCAPIDLL.dll", EntryPoint = "GetUsbKeySn", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
        public static extern UInt32 GetUsbKeSn(IntPtr pstrSn, ref UInt32 u4SnSize);

        [DllImport("XIBCtrlCAPIDLL.dll", EntryPoint = "InitUsbKey", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
        public static extern UInt32 InitUsbKey(ref byte u1SN);

        [DllImport("XIBCtrlCAPIDLL.dll", EntryPoint = "ListUsbkeyNumber", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
        public static extern UInt32 ListUsbkeyNumber(ref UInt32 u4SnSize);

        [DllImport("XIBCtrlCAPIDLL.dll", EntryPoint = "IsHaveSpecCert", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
        public static extern UInt32 IsHaveSpecCert(ref byte u1CN);
    }

    public class EsCtrlDll_X64
    {
        [DllImport("XIBCtrlCAPIDLL_x64.dll", EntryPoint = "GetUsbKeySn", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
        public static extern UInt32 GetUsbKeSn(IntPtr pstrSn, ref UInt32 u4SnSize);

        [DllImport("XIBCtrlCAPIDLL_x64.dll", EntryPoint = "InitUsbKey", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
        public static extern UInt32 InitUsbKey(ref byte u1SN);

        [DllImport("XIBCtrlCAPIDLL_x64.dll", EntryPoint = "ListUsbkeyNumber", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
        public static extern UInt32 ListUsbkeyNumber(ref UInt32 u4SnSize);

        [DllImport("XIBCtrlCAPIDLL_x64.dll", EntryPoint = "IsHaveSpecCert", CharSet = CharSet.Auto, CallingConvention = CallingConvention.StdCall)]
        public static extern UInt32 IsHaveSpecCert(ref byte u1CN);
    }
}
