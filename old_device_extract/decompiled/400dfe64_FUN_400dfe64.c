// Function : FUN_400dfe64
// Address  : 0x400dfe64
// Size     : 104 bytes


void FUN_400dfe64(int param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  *(undefined1 *)(param_1 + 0x79) = 1;
  uVar1 = FUN_400f1a9c();
  *(undefined4 *)(param_1 + 0x7c) = uVar1;
  *(int *)(param_1 + 0x80) = param_2;
  FUN_400f0d18(param_1 + 0x84,param_3);
  FUN_400dfe3c(param_1,1);
  func_0x4009246c(*(undefined4 *)(param_1 + 0x98),4,(uint)(param_2 * 1000000) / 1000,0);
  uVar1 = *(undefined4 *)(param_1 + 0x98);
  uVar2 = func_0x40090b58();
  func_0x4009246c(uVar1,1,uVar2,0);
  if ((*(byte *)((int)param_3 + 0xf) & 0x80) == 0) {
    param_3 = (int *)*param_3;
  }
  FUN_400f06a4(0x3ffc5490,"in %d)\n",param_2,param_3);
  return;
}

