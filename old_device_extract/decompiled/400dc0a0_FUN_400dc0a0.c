// Function : FUN_400dc0a0
// Address  : 0x400dc0a0
// Size     : 92 bytes


void FUN_400dc0a0(int param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((*(byte *)((int)param_2 + 0xf) & 0x80) == 0) {
    param_2 = (int *)*param_2;
  }
  FUN_400f06a4(0x3ffc5490,"or: %s\n",param_2);
  FUN_400f1a40(*(undefined1 *)(param_1 + 0x25),1);
  func_0x4009246c(*(undefined4 *)(param_1 + 0x4c),4,
                  ((uint)*(ushort *)(param_1 + 0x28) * 1000) / 1000,0);
  uVar1 = *(undefined4 *)(param_1 + 0x4c);
  uVar2 = func_0x40090b58();
  func_0x4009246c(uVar1,1,uVar2,0);
  return;
}

